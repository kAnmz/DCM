/* STARTSINGLE_OF_MULTIPLE */
/*******************************************************************************
| Project Name: Tp_Iso15765
|               OSEK single-/multiconnection transport layer
|    File Name: tpmc.c
|
|  Description: This version supports the specification for
|               the ISO 15765-2 transport protocol
|
|-------------------------------------------------------------------------------
|               C O P Y R I G H T
|-------------------------------------------------------------------------------
| Copyright (c) 2000-2007 Vector Informatik GmbH            All rights reserved.
|
|     This software is copyright protected and proprietary
|     to Vector Informatik GmbH. Vector Informatik GmbH
|     grants to you only those rights as set out in the
|     license conditions. All other rights remain with
|     Vector Informatik GmbH.
|
|     REMOVAL OF THESE COMMENTS IS A VIOLATION OF THE LICENSE AGREEMENT.
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ---------------------------------------
| Gz           Oliver Garnatz            Vector Informatik GmbH
| Js           Bernd Jesse               Vector Informatik GmbH
| Rn           Jochen Rein               Vector Informatik GmbH
| Ap           Andreas Pick              Vector Informatik GmbH
| VC                                     Vector Cantech
| Her          Peter Herrmann            Vector Informatik GmbH
| EJW          Eric J. Winder            Vector CANtech, Inc.
|-------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-------------------------------------------------------------------------------
| Date         Ver   Author  Description
| ---------    ----  ------  ---------------------------------------------------
| 16-Jun-00    2.00    Gz    Creation
| 26-Jul-00    2.01    Gz    Compatibility for DBKOMGen (files needed: tp_mch.h & tpmc.cfg)
| 31-Jul-00    2.02    Gz    Old Switches deleted/renamed
| 09-Aug-00            Gz    Support for multiple ECU numbers
| 31-Aug-00    2.03    Gz    support of normal_addressing including dynamic_ids
| 12-Oct-00    2.05    Gz    support of normal_fixed_addressing (ext.ID) format
|                            added Channel-Lock
|                            added Reception Break while sending Wait-Frame
|                            added BugFix Version
|                            added more Assertions
|                            added indicated CAN-Driver support
|                            added/modified some API-functions
|                            modified Custom TX/RX CopyFunctions
|                            modified concerning DBKOMGen Tool
|                            deleted TransmitSF
|                            deleted compatibility Mode
| 16-Oct-00            Gz    modified TpTxGetConnectionStatus
| 09-Nov-00            Gz    ErrorIndication(s) modified - connection instead channel
| 24-Nov-00    2.06    Gz    no changes
| 05-Mar-01    2.07    Gz    cast the constants to unsigned values for negating
|                      Gz    optimizing NormalFixedAddressing
|                      Gz    added connections for rx-side; adjustable stmin-time
|                      Gz    support for multiple can systems added (non indexed)
|                      Gz    added Review changes
| 14-Mar-01    2.08    Gz    corrections for Busoff handling
| 09-Apr-01    2.09    Gz    added usage of CanCancelTransmit()
|                      Gz    extension of the Gateway-API
|                      Gz    for SingleFrames will be copied the correct length now
| 20-Apr-01    2.10    Gz    no changes
|                      Gz    added support for Multiple ECU's
|                      Gz    added observe of minimum sending distance
| 11-May-01    2.11    Gz    enlarged support for multiple CAN-channel ECUs
| 05-Jun-01    2.12    Gz    support of extended addressing
| 11-Jun-01            Gz    support of single channel TP
| 15-Jun-01    2.13    Gz    correct timer handling
| 19-Jun-01    2.14    Js    ESCAN00000839: pChipDataPtr substituted with CanChipDataPtr
| 27-Jul-01    2.15    Gz    added casts
|                            correct static addressing support for multiple CAN-channel ECUs
| 07-Sep-01    2.16    Gz    ESCAN00000819: better support for singlechannel-TP
|                            ESCAN00001096: Support of Tp-Connections without FC
|                            ESCAN00001097: TP is always in compatibility mode
|                                           while reading Source-/TargetAddress
|                            ESCAN00001101: early termination of the
|                                           queueing mechanism (only if CanChannels > 1)
|                            ESCAN00001149: New TP-class: Dynamic Multiple Addressing
| 07-Sep-01    2.17    Gz    ESCAN00001422: Hold the channel while leaving the
|                                           ApplTxErrorIndication-Fct. unlocks it
| 20-Sep-01    2.18    Gz    ESCAN00001482: 'Connection specific timings' is not
|                                           working correctly
|                            ESCAN00001526: Timings should be normalized by the GenTool
|                            ESCAN00001537: TransmitHandles should be changeable
|                                           while runtime
| 26-Oct-01    2.19    VC    Reserved (only VectorCantech)
| 26-Oct-01    2.20    VC    Reserved (only VectorCantech)
| 26-Oct-01    2.21    VC    Reserved (only VectorCantech)
| 26-Oct-01    2.22    Gz    General improvement
| 06-Nov-01            Rn    ESCAN00001724: delete used in TpTxHoldChannel
| 06-Nov-01            Gz    ESCAN00001744: Combination of 'Use STMin from flow control
|                                           frame' together with a 'connection without FC'
|                                           will not work
| 06-Nov-01            Gz    ESCAN00001746: (only DC) complementary to 'connecntions
|                                           without FC' an additional BIT is set in the
|                                           TPCI-Byte to differ between
| 08-Nov-01    2.23    Gz    ESCAN00001764: In case of single optimized version some
|                                           macros have still parameter channel.
|                      Gz    ESCAN00001796: All pending TpConnections will get cancelled
|                                           after a Confirmation-Timeout occurs
|                                           (with de-activated CAN-Driver TransmitQueue)
| 27-Nov-01    2.24    Gz    ESCAN00001805: After calling TpRxResetChannel() a TxConnection
|                                           is running into ConfTimeout (only with
|                                           de-activated CAN-Driver TransmitQueue)
| 2001-Dec-06  2.25.00 Gz    ESCAN00001891: The limitation having an unique CAN-ID over
|                                           all CAN-Channels is eliminated
|                            ESCAN00001892: ApplTpRxGetBuffer has additional parameter for gateways
| 2001-Dec-12  2.26.00 Gz    ESCAN00001662: It should be possible to have more than one Base-Address
| 2001-Dec-18          Gz    ESCAN00001798: The TPCI-Byte for FlowControl's is not checked
|                                           for valid values
| 2002-Jan-07          Gz    ESCAN00001853: insert keyword for far APIm and far callback-functions
| 2002-Jan-30          Gz    ESCAN00002185: for multiple CAN-systems and dynamicTP:
|                                           TpPrecopy-function is not reentrant
|                            ESCAN00002175: Illegal SingleFrame lengths will be shorten
|                                           to a legal SingleFrame length.
|                            ESCAN00002190: ApplTpRxErrorIndication is called after ApplTpRxIndication
| 2002-Jan-14  2.27.00 Gz    ESCAN00002323: No transmission or reception possible in case of enable debug mode
|                            ESCAN00002324: support indexed CAN-driver for all dynamic TP-classes
| 2002-Feb-28  2.28.00 Gz    ESCAN00002374: Limiting the STmin time from FC to a minimum
| 2002-Mar-11          Gz    ESCAN00002392: Observing CAN frame DLC (Data Length Code)
| 2002-Mar-11          Gz    ESCAN00002379: Illegal reception, if a CAN-message with DLC=0 is received
| 2002-Mar-11          Gz    ESCAN00002380: The TP can't receive a FirstFrame with a dataLength
|                                           smaller six(6)/seven(7) bytes successfully
| 2002-Mar-11          Gz    ESCAN00002459: enhance the fault tolerance
| 2002-Mar-14          Gz    ESCAN00002490: A possibility should be provided to pre-check
|                                           each CAN-message of a TP-frame
| 2002-Mar-20  2.29.00 Gz    ESCAN00002534: Tp is blocked after TpTransmit returns 'kTpFailed'
| 2002-Mar-22          Gz    ESCAN00002554: Tp stays blocked after receiving a TP-frame with
|                                           wrong DLC or incorrect frame-length
|                      Gz    ESCAN00002555: AppltpTxErrorFunction() will be called
|                                           after TpTransmit returns 'kTpFailed'
|                      Gz    ESCAN00002534: TP is locked after wakeup
| 2002-Mar-27  2.30.00 Gz    ESCAN00002565: Possible under-run of the requested STmin time
|                      Gz    ESCAN00002558: Only Cosmic HC12 with option -pck :
|                                           Compiler reports truncating assignment when TpTxQueueCheck() is called
| 2002-Apr-03          Gz    ESCAN00002578: It should be not possible to change communication parameters
|                                           while a communication is running
| 2002-Apr-05          Gz    ESCAN00002632: compatibility mode for old style
|                                           TpTxErrorIndication function is deleted
|                      Gz    ESCAN00002636: the possibility to switch off the feature
|                                           'using connections' are not supported any more
| 2002-Apr-26  2.31.00 Gz    ESCAN00002642: Partially written frames are transmitted by the TP
|                                           (only if 'ApplTpTxCopyToCAN' is used)
| 2002-May-07  2.32.00 Gz    ESCAN00002798: connections will terminate very often and run into a
|                                           confirmation timeout (only with disabled can transmit queue)
| 2002-Jun-05  2.33.00 Gz    ESCAN00003065: It should be possible to deactivate the TP separately on each CAN-channel
|                      Gz    ESCAN00002652: The indication function for first frame reception is called
|                                           befor ApplTpGetRxBuffer() callback.
|                      Gz    ESCAN00003077: assertInternal would not work correct in TpRxInit() function
|                      Gz    ESCAN00003076: Retransmission of FlowControl message would not working correctly
|                                           (only with de-activated CAN-Driver TransmitQueue)
| 2002-Jul-11  2.34.00 Gz    ESCAN00003204: Dynamic data pointer are not longer necessary
| 2002-Jul-22          Gz    ESCAN00003135: Termination of  two TX connections, which have
|                                           assigned the same Source- and TargetAddress
| 2002-Jul-22          Gz    ESCAN00003081: Fully compliance to the ISO-specification
| 2002-Jul-22          Gz    ESCAN00003344: It should be possible to pad out the unsused bytes in a CAN-frame
| 2002-Jul-22          Gz    ESCAN00003345: Call 'CanCancelTransmit()' with wrong handle for 'withoutFC' connections
| 2002-Jul-24          Gz    ESCAN00003342: Change in observing the minimum sending time foy dyn.TP
| 2002-Jul-24          Gz    ESCAN00003374: Calculate STmin and BS only from the first FlowControl
| 2002-Aug-22  2.35.00 Gz    ESCAN00003584: Some compilers generates an error with connection-specific timing enabled
| 2002-Sep-02          Gz    ESCAN00003617: Connection-specific timing generates errors in
|                                           combination with connections-withoutFC's
| 2002-Sep-04          Gz    ESCAN00003586: Possible call ApplTpXxErrorIndication and ApplTpIndication/ApplTpConfirmation functions
| 2002-Sep-04          Gz    ESCAN00003655: The FlowControl Timeout time can be replaced by the Confirmation Timeout value
| 2002-Sep-05          Gz    ESCAN00003375: Separation of TimerTask and TransmissionTask (StateTask)
| 2002-Sep-05          Gz    ESCAN00003376: CF Transmission faster than callycyle of TpTxTimerTask()
| 2002-Okt-07  2.36.00 Ap    ESCAN00003809: While polling the CAN-driver slowly the connection can be lost
| 2002-Okt-09          Gz    ESCAN00003520: Change hook-functions (delete 'ApplTpRxCanMessageReceived' /
|                                           add 'ApplTpTxFC' / add 'TpPreCopyCheckFunction')
| 2002-Okt-09          Gz    ESCAN00003750: no changes
| 2002-Okt-09          Gz    ESCAN00003751: assert called in TpTransmit
| 2002-12-06   2.37.00 Gz    ESCAN00004216: Wrong CANdriver macros are used (CanRxActualIdExtLo)
|                      Gz    ESCAN00004340: TP stays blocked after ConfirmationTimeout occurs
|                                           (only dynamic TP-classes in multiple CAN-channel ECUs)
|                      Gz    ESCAN00004373: ApplTpTxErrorIndication: 'kTpHoldChannel' will free the tpChannel
|                                           (only dynamic TP-classes)
| 2002-12-09   2.38.00 Gz    ESCAN00004399: endless loop in TpInitPowerOn()
| 2003-01-11   2.39.00 Gz    ESCAN00004587: no changes
| 2003-02-03   2.40.00 Gz    ESCAN00004757: Compiler failure for dynamic TP on multichannel systems removed
|                            ESCAN00004802: Fully compliance to the ISO-specification for dynamic TP-classes
| 2003-11-13   2.41.00 Gz    ESCAN00005041: (Minimum) delay time monitoring frees locked tpChannels (only dynamic TP-classes)
|                      Gz    ESCAN00004199: Conditional Pre-Processor directives misses parantheses
|                      Gz    ESCAN00003891: Add a CANchannel-specific re-initialization function.
|                      Gz    ESCAN00005100: Wrong DataBuffers are used (only multi CAN-channel ECU's with dynamic TP-classes)
|                      Gz    ESCAN00005221: Compile errors (only if 'NormalFixed Addressing SingleTP (mulit-based)' is used)
|                      Gz    ESCAN00005257: TpTxGetConnectionStatus() returns wrong values (only dynamic TP-classes)
|                      Gz    ESCAN00005539: TpRxSetBufferOverrun is provided: Do not copy all frames if a buffer overrun occured
|                      Gz    ESCAN00005541: Call ApplXxErrorIndication() if for a running connection TpXxResetChannel() is called.
|                      !!! Warning this version has a change in its behaviour !!!
|                      Gz    ESCAN00006155: Transmit the CF directly after a FC without waiting the STmin time
|                      Gz    ESCAN00006159: Add TpTask() function
|                      Gz    ESCAN00006156: Add new requirements from ISO 15765-2.2
|                      !!! Warning if these changes are active there will be changes in the behaviour !!!
|                      Gz    ESCAN00006158: Add a separat channel for functional reception (N_TAtype = functional)
|                      Gz    ESCAN00006040: An API should be added which results the current CAN-channel
|                                           of the received frame (only multiple CAN-channel systems)
|                      Gz    ESCAN00006014: Unused locals (only for static and single TP classes)
|                      Gz    ESCAN00006341: Extend the DLC check from a variable length to the fix length of 8 bytes
|                      Gz    ESCAN00006354: C-Library functions not longer used
|                      Gz    ESCAN00006465: Multiple ECU support should be added
|                      Gz    ESCAN00006379: Irregular termination of a running connection
|                                           followed by possibly wrong exception handling  (only dynamic TP-classes)
|                      Gz    ESCAN00006850: Transmission will fail, if the application report
|                                           an buffer-underrun in the ApplTpCopyToCAN hook function
|                      Gz    ESCAN00007005: Add TMS320 support (not fully supported)
|                      Gz    ESCAN00007006: Support for GENy
| 2003-11-17  2.42.00  Ap    ESCAN00007029: channel specific minimum sending distance
|                      Gz    ESCAN00007005: Add TMS320 support (not fully supported)
| 2003-12-12  2.43.00  Gz    ESCAN00007108: Compile errors to missing functions/macros (only if RuntimeChecks are activated)
|                      Gz    ESCAN00007107: Compile errors occures to undefined functions/macros (only NormalFixedAddressing SingleTP)
|                      Gz    ESCAN00007005: Add TMS320 support (not fully supported)
| 2004-01-15  2.44.00  Gz    ESCAN00007173: RuntimeCheck in TpTransmit evaluates wrong (only multiple CAN channel systems)
|                      Gz    ESCAN00007005: Add TMS320 support (finished)
|                      Ap    ESCAN00007229: no changes
|                      Gz    ESCAN00007193: define TP_API_CALLBACK_TYPE currently not defined (partly)
|                      Gz    ESCAN00007192: no changes
|                      Gz    ESCAN00007191: TpCannel stays locked if ApplTpRxGetBuffer is returning V_NULL when receiving a FF
|                      Gz    ESCAN00007098: While initialization an assertion gets called
|                      Ap    ESCAN00007257: truncating assignment for calculations without cast
|                      Gz    ESCAN00005679: The memory qualifier V_MEMROM0 has to be implemented in this module
|                      Gz    ESCAN00007273: no changes
| 2004-01-30  2.45.00  Gz    ESCAN00007293: Additional memory qualifier should be added
|                      Ap    ESCAN00007349: Memory qualifier for TpTxPostProcessing and TpRxPostProcessing corrected
|                      Gz    ESCAN00007318: In each transmission wrong data will be sent. (only 8bit controller)
| 2004-01-27  2.50.00  Ap    ESCAN00007341: ApplTpCopyToCAN parameter harmonisation for 8-bit controllers
|                      Ap    ESCAN00007392: Truncating assingment: TP_RX/TX_INIT_HANDLE is casted to a unsigned char value
| 2004-02-06  2.51.00  Ap    ESCAN00007426: no changes
|                      Ap    ESCAN00007441: Functions TpDrvTxConfirmation and TpDrvRxConfirmation undefined for polling mode
|                      Ap    ESCAN00007471: Unsigned signed mismatch warning for sequence number check
| 2004-03-02  2.52.00  Gz    ESCAN00007778: Compile error while using TP handle changeable
| 2004-03-12  2.53.00  Ap    ESCAN00007864: An interrupt lock is never restored from the TP component (only GENY)
| 2004-03-19  2.54.00  Ap    ESCAN00007932: Bracket missing in runtime check
| 2004-03-19  2.55.00  Ap    ESCAN00007519: Support for CAN buffer access in ApplTpRxGetBuffer callback function
| 2004-04-02  2.56.00  Gz    ESCAN00007675: TP class 'NormalFixed Addressing SingleTP' can not used together with dynamic data Pts. for dynamic transmit objects (CANdrv)
|                      Gz    ESCAN00008089: Adapt NormalFixedAddressing TP-class for GENy
| 2004-04-06  2.57.00  Gz    ESCAN00008142: CAN driver assertion is called while receiving a multiple frame request (only dynamic TP-class and multiple CAN systems)
|                      Gz    ESCAN00008143: Confirmation timeout is reported, after the transmission of the FlowControl frame (only dynamic TP-class)
|                      Gz    ESCAN00008091: no changes
| 2004-04-23  2.58.00  Gz    ESCAN00008246: TP is getting blocked after an protocol error (only NormalFixed Addressing SingleTP)
|                      Gz    ESCAN00007675: TP class 'NormalFixed Addressing SingleTP' can not be used together with dynamic data Pts. for dynamic transmit objects (CANdrv)
|                      Ap    ESCAN00008259: Compile error due to a missing AND operator in if statement
| 2004-05-13  2.60.00  Ap    ESCAN00007624: Support for mixed 11/29 addressing
|                      Ap    ESCAN00007831: MISRA: tpmc.h: Macro body not enclosed in ()
|                      Ap    ESCAN00008170: Parameter 'txObject' unused in function 'TpDrvTxConfirmation'
|                      Ap    ESCAN00008037: Variable DLC support
|                      Ap    ESCAN00008390: Each transmission results in a Confirmation timeout (only GENy)
| 2004-05-25  2.61.00  Ap    ESCAN00008474: no changes
| 2004-06-18  2.62.00  Ap    ESCAN00008488: FORMATE_OFFSET undefined when using feature VariableDLC
|                      Gz    ESCAN00008520: Add special routines for testing purpose
|                      Ap    ESCAN00008629: no changes
|                      Ap    ESCAN00008630: Undeclared identifier tpCanGetDynTxObjReturn missing in TpInitPowerOn
| 2004-08-06  2.63.00  Gz    ESCAN00008520: Add special routines for testing purpose (2.nd)
|                      Gz    ESCAN00008778: TpTransmit returns always 'kTpBusy' - no transmission is possible
|                      Gz    ESCAN00008983: TP-class: NormalFixed Addresing SingleTP will not compile
|                      Gz    ESCAN00007440: no changes
|                      Ap    ESCAN00009095: Runtime check for Base Address in case of multiple base addresses with extended addressing failed
| 2004-06-18  2.64.00  Ap    ESCAN00009112: Warning about possibly uninitialized variable 'offset'
|                      Ap    ESCAN00009111: no changes
| 2004-08-23  2.65.00  Gz    ESCAN00009502: no changes
|                      Ap    ESCAN00009153: Warning due to unused parameter in TpDrvConfirmation
|                      Ap    ESCAN00009375: A reception is made to a locked tpRxChannel (only dynamic TP-classes)
|                      Ap    ESCAN00009511: Naming Conventions: New version defines
|                      Ap    ESCAN00004702: BS and STmin shall be ignored
| 2004-10-15  2.66.00  Ap    ESCAN00009865: Unexpected handling of functional requests with wrong PCI byte
| 2004-10-22  2.67.00  Ap    ESCAN00009979: A valid  functional diag request is not accepted by the transport layer
|                      Ap    ESCAN00009797: Old naming of compiler switch "MULTIPLE_RECEIVE_BUFFER"
| 2005-01-11  2.68.00  Ap    ESCAN00010029: An assertion occures when receiving a functional diagnostic request
|                      Ap    ESCAN00010186: No libary functions should be used - VSTDLIB used (mendatory) instead
|                      Ap    ESCAN00010770: Use of official CAN Driver API CanGetTxDataPtr
|                      Ap    ESCAN00010773: Support for multiple ECUs in combination with single optimization and Mixed29/Extended/NormalFixed
|                      Ap    ESCAN00010774: Support for Multiple Addressing with GENy
|                      Ap    ESCAN00010775: MISRA and pclint status and improvement request
|                      Ap    ESCAN00010776: Compile error is reported in TpTransmit if MultipleAddressing is used without ExtendedAddressing
|                      Ap    ESCAN00010777: Support for AddressingType specific PGN and Priority
|                      Ap    ESCAN00010781: Compile error is reported if MultipleAddressing is active but AddressingType NormalAddressing is inactive
| 2005-02-08  2.69.00  Ap    ESCAN00010829: Support for non ISO feature AcknowledgedConnection
|                      Ap    ESCAN00010831: Support for GatewayAPI on diagnostic functional requests
|                      Ap    ESCAN00011025: Availability of API function TpRxGetStatus extended (as documented in TechRef)
|                      Gz    ESCAN00011041: Extra OBD reception path has to be added
|                      Gz    ESCAN00011040: TpTransmit has to be accepted while TP is in minimum sending distance state
| 2005-02-11  2.70.00  Ap    ESCAN00010186: Compliency to CANGen and DBKOMGen
| 2005-02-25  2.71.00  Ap    ESCAN00011124: NULL should not be used in the component
|                      Ap    ESCAN00010186: No changes
|                      Ap    ESCAN00011285: Compiler warning due to missing cast on tpCopyToCanInfoStruct.pDestination in TpTxPreCanTransmit
| 2005-03-17  2.72.00  Ap    ESCAN00011292: Behaviour in case of incorrect consecutive frame reception
|                      Ap    ESCAN00011443: Support for feature required: Functional FC with flow status wait
|                      Ap    ESCAN00011415: No changes
| 2005-08-11  2.73.00  Ap    ESCAN00011729: No changes
|                      Ap    ESCAN00011738: Missing memory qualifier to support memory modes small/medium/lage when accessing CAN driver
|                      Ap    ESCAN00011897: Transmissions of FlowControl.Wait / suspend of reception (interface behaviour change required!)
|                      Ap    ESCAN00011924: Undeclared identifier 'tpCurrentTargetAddress' in TPMC Gateway API configuration
|                      Ap    ESCAN00012015: No changes
|                      Her   ESCAN00012778: added dynamic handling of SN and FC strict checking
|                                           (TP_ENABLE_FC_MSG_FLOW_DYN_CHECK, TP_ENABLE_DYN_AWAIT_CORRECT_SN)
|                      Gz    ESCAN00012915: Change the functionality of the ApplTpCheckTA() callback function
|                                           !!! Warning this version has a change in its behaviour !!!
|                      Ap    ESCAN00011586: Compiler error in Multiple-ECU configuration
|                      Ap    ESCAN00011117: Multiple Base Addresses with Address Offset does not work in Extended Addressing
|                      Her   ESCAN00013192: added dynamic handling of timeout values (N_As,N_Ar,N_Bs,N_Cr)
|                                           (TP_ENABLE_DYN_CHANNEL_TIMING)
| 2005-08-22  2.74.00  Her   ESCAN00013222: MISRA compliancy (cancelled context switch)
| 2005-09-12  2.75.00  Ap    ESCAN00013489: Acceptance of functional FirstFrame
| 2005-09-25           Her   ESCAN00013590: cleanup of pclint warnings
| 2005-10-17  2.76.00  Her   ESCAN00013654: FirstFrame / SingleFrame acceptance to wrong parallel connection in multi addressing TP class
|                            ESCAN00013914: cleanup of compiler warnings
|                            ESCAN00013995: added single channel multi connection multi CAN channels
|                                           (TP_ENABLE_SINGLE_CHAN_MULTICONN)
| 2005-11-10  2.77.00  Gz    ESCAN00014224: FC.overflow is not automatically supprted
|                      Gz    ESCAN00013335: Wrong calculation of data length when receiving a first frame (only PIC18)
|                      Gz    ESCAN00014153: Compiler warning W1353C "assignment incompatible pointer types" occurs
|                      Gz    ESCAN00014000: CAN driver assertion is called in TpInitPowerOn()
|                      Gz    ESCAN00014015: Multiple ECU numbers in functional requests
|                      Gz    ESCAN00013054: memcpy() should used instead of VStdRamMemCpy()
| 2005-11-10  2.78.00  Gz    ESCAN00014444: Compile error: kTpFCSuppressFrame is undefined
| 2005-12-19  2.79.00  Gz    ESCAN00014547: Invalid call of "dynamic tx object set data pointer" macro under certain configuration.
| 2006-01-10  2.80.00  Gz    ESCAN00014790: A ConsecutiveFrame can get lost while a unexpected FlowControl is received
|                      Gz    ESCAN00014838: Add support for functional extended addressing an physical normal addressing with GENy
|                      Gz    ESCAN00014839: STmin calculation not correct for specific values
| 2006-01-18  2.81.00  Her   ESCAN00014937: c++ comment was used
| 2006-01-31  2.82.00  Her   ESCAN00014888: Tx/Rx interrupt priority inversion re-released
| 2006-02-06           Her   ESCAN00015232: no changes
| 2006-02-15  2.83.00  Her   ESCAN00015346: FlowControl contains currupted data (only dynamic TP-classes)
| 2006-02-18  2.84.00  Her   ESCAN00013656: Runtimecheck and assertions hit without reason in mulitple addressing TP classes
|                      Her   ESCAN00013658: no changes
|                      Her   ESCAN00015368: replace string.h
|                      Her   ESCAN00015427: Functional Flow Control with Wait state (multiple addressing)
| 2006-02-27  2.85.00  Her   ESCAN00015472: __ApplTpPrecopy erroneously called with multiple addressing
| 2006-03-06  2.86.00  Her   ESCAN00015521: cleanup of compiler warnings (includes ESCAN13328), additional consistency check
|                      Her   ESCAN00015595: Cast to tvolatileTpTxState  missing
| 2006-04-06  2.87.00  Her   ESCAN00015988: unidirectional connections without FC: Rx != Tx connection count
|                      Her   ESCAN00016008: possible STmin underrun with TP_ENABLE_ISO_15765_2_2 enabled
|                      Her   ESCAN00016050: TP is not configured on all CAN channels (kTpNumberOfCanChannels != kCanNumberOfChannel)
|                      Her   ESCAN00016055: compiler warning "too many arguments" for CanInterruptDisable/Restore
| 2006-04-24  2.88.00  Her   ESCAN00016125: set TP_ENABLE_CHECKTA_COMPATIBILITY as default for old GenTool
|                                           Misra compliancy adaptations
|                      Her   ESCAN00016214: Typo in STmin calculation for reserved values sets STMin to 128 regardless of the Call Cycle
|                      Her   ESCAN00016229: TP should not continue after assertion
| 2006-06-16  2.89.00  Her   ESCAN00016608: Support Tx variable Dlc for GENy configuration
|                      Her   ESCAN00016610: Feature TP_ENABLE_SINGLE_CHAN_MULTICONN does not work with CANgen
|                      Her   ESCAN00016611: Search/Replace typo for multiple addressing configuration in tpTxState structure
|                      Her   ESCAN00016632: Different extern declarations for const memory location.
|                      Her   ESCAN00016639: Using wrong info structure for address information evaluation
|                      Her   ESCAN00016658: NEC 78K0 warning due to missing cast
|                      Her   ESCAN00016678: CanCanInterruptDisable/Restore needs CANdriver reference implementation LI 1.3
|                      Her   ESCAN00016581: Support max. number of wait frames (N_WFTmax)
|                      Her   ESCAN00016821: Missing First Frame data bytes
|                      Her   ESCAN00016920: no changes
| 2006-07-27  2.89.01  Her   ESCAN00017063: functional reception interrupts running physical reception
| 2006-08-10  2.89.02  Her   ESCAN00017206: Missing power on initialization for transmit channel semaphore
|                      Her   ESCAN00017305: Compiler error due to wrong bracing of macro definitions
| 2006-10-12  2.89.03  EJW   ESCAN00018009: no changes
| 2006-11-09  2.89.04  Her   ESCAN00018058: Missing default definition for TP_TX_HANDLE_CHANGEABLE
|                      Her   ESCAN00018299: Compiler warning using break after return statement
|                      Her   ESCAN00018508: Extend ApplTpCopyFromCan API with rxStruct for usage by GW
|                      Her   ESCAN00018791: WFTCounter shall only be used in necessary configuration
| 2007-01-04  2.90.00  Her   ESCAN00018236: separate SF/MF acknowledged connection
|                      Her   ESCAN00019126: ignore frames longer than announced by DL info
|                      Her   ESCAN00019137: assertion called in tpTxInit function
| 2007-02-19  2.91.00  Her   ESCAN00019597: Disable MF reception
| 2007-03-15  2.92.00  Her   ESCAN00019850: Disable MF reception:Compiler warning(unreferenced static function declaration)
|                      Her   ESCAN00019928: Runtime check does not cover mixed-11 addressing type
|                      Her   ESCAN00020136: Add ASR CanIf interface for Static SingleTP use case
|                      Her   ESCAN00020427: TpOBDPrecopy requests are interpreted with Extended instead of Normal Addressing
| 2007-05-10  2.93.00  Her   ESCAN00020926: TpInit must call TpFuncInit to reset the functional state machine
|                      Her   ESCAN00021048: Add ASR CanIf interface for Static SingleTP use case (functional connection group),
|                                           Assertions adapted
|                      Her   ESCAN00021049: wrong typedef used for (v)uint8
| 2007-08-28  2.94.00  Her   ESCAN00021597: Redefinitions in mixed configurations (ASR/nonASR) solved
|                      Her   ESCAN00022111: Support AUTOSAR post built functionality for transmitting PDU-IDs
|                      Her   ESCAN00022166: no changes
|                      Her   ESCAN00022281: Proper support of the "multiple ECU" feature with NormalFixed addressing
|                      Her   ESCAN00022424: Missing opening brace leads to a syntax error
|                      Her   ESCAN00022582: Multiple addressing: connection type A accepts FC of connection type B
| 2007-10-30  3.00.00  Her   ESCAN00023023: Dispatched Multi TP classes
|                      Her   ESCAN00022661: Compiler warning with canbittype cast cleaned
|                      Her   ESCAN00022683: Connection specific setting of the CAN message confirmation timeout
|                      Her   ESCAN00023030: ASR - Single Channel TP used with multiple channels (TP_ENABLE_SINGLE_CHAN_MULTICONN)
| 2007-11-08  3.00.01  Her   ESCAN00023135: Connection specific timings for Dispatched classes
| 2007-11-20  3.01.00  Her   ESCAN00023262: Acknowledged TP: TPMC tries to send further CFs after transmission completion
|                      Her   ESCAN00022704: WFT_OVRN indication at transmission side
|                      Her   ESCAN00023482: Interrupt disable and restore is done for the wrong CAN channel
| 2007-12-07  3.02.00  Her   ESCAN00023568: FC timeout value is erroneously used on the Rx side for Wait Frame transmissions
|                      Her   ESCAN00023572: no changes
| 2008-01-08  3.03.00  Her   ESCAN00023881: allow multiple use cases for one source with multiple addressing
| 2008-01-09  3.04.00  Her   ESCAN00023959: Application buffer resides in paged (far)  memory
|                      Her   ESCAN00023972: no changes
|                      Her   ESCAN00023991: API function TpFuncGetReceiveCanID returns a wrong type.
|                      Her   ESCAN00013328: Cosmic -pck: type conversion with truncation error
|                      Her   ESCAN00024096: Assertion checks fail
|                      Her   ESCAN00024024: TP messages send onto a differrent CAN bus then expected
| 2008-01-25  3.04.01  Her   ESCAN00024227: new API function for functional requested multiframe responses
| 2008-02-08  3.04.02  Her   ESCAN00024290: Check CanTransmit return value for queued elements
|                      Her   ESCAN00024488: Development error detection notifies about unused tx handles (TP_ENABLE_SINGLE_CHAN_MULTICONN and ASR)
|                      Her   ESCAN00024771: Wrong memory qualifier used
| 2008-02-28  3.04.03  Her   ESCAN00024960: Compiler warning (variable "adrFmtOffs" was set but never used)
|                      Her   ESCAN00024963: Compiler error (missing struct element "TargetAddressIsValid")
|                      Her   ESCAN00024845: TP references the field kTpRx_RxHandle_Field which is not generated
|                      Her   ESCAN00025819: Tp does not receive requests on some CAN channels
|                      Her   ESCAN00026052: MCAN undefined function names
| 2008-07-17  3.04.04  Her   ESCAN00028477: Mixed CANbedded - AUTOSAR communication stack compiler and  linker issues
|                      Her   ESCAN00028485: Support mixed CAN-IDs dynamically at runtime
|                      Her   ESCAN00027903: Compiler warning: large type was implicitly cast to small type
|                      Her   ESCAN00028580: Support TMS320 for ASR and GENy
| 2008-08-18  3.04.05  Her   ESCAN00029194: Dispatched Tp issue: TpTransmit<Connection> keeps tpChannels blocked
|                      Her   ESCAN00029252: Mixed CANbedded - AUTOSAR communication stack: check for DLC
|                      Her   ESCAN00029288: Mixed-IDs name mix-up for Rx/Tx side
| 2008-08-28  3.04.06  Gz    ESCAN00029557: Lock of dynamic ISO-TP MC rx connections doesn't work
| 2008-09-15  3.04.07  Her   ESCAN00030490: Compiler warning ("-=" implicit conversion)
|                      Her   ESCAN00030329: Compiler warning in TpInitPowerOn
| 2008-11-12  3.04.08  Her   ESCAN00031187: Message buffer overrun for Flow Control frames
| 2009-01-08  3.04.09  Her   ESCAN00031601: TP transmission stops after FC reception with STmin = 0xFF
|                      Her   ESCAN00031930: avoid warning "Narrowing or signed-to-unsigned type conversion"
|                      Her   ESCAN00032048: Support far data access for paged applications
| 2009-01-28  3.04.10  Her   ESCAN00032602: Extend the maximum number of configurable CAN channels
| 2009-04-01  3.04.11  Her   ESCAN00034323: New preprocessor switch coming up with MCAN support by GENy
|                      Her   ESCAN00034343: Type mismatch between extern declaration and definition
| 2009-05-29  3.04.12  Her   ESCAN00035016: no changes
|                      Her   ESCAN00035351: Wrong parameter value used
| 2009-07-01  3.04.13  Her   ESCAN00036069: Support mixed stack (CANbedded/ASR) CANIF without non postbuild API
| 2009-09-18  3.04.14  Her   ESCAN00037745: Redefinition of TpTxConfirmationTimeout and TpRxConfirmationTimeout
|                      Her   ESCAN00037463: Compiler warning: statement not reached
|                      Her   ESCAN00038018: Undefined macro C_VERSION_REF_IMPLEMENTATION
| 2009-11-26  3.04.15  Her   ESCAN00039239: compiler warnings due to dummy assignments
| 2009-11-27  3.04.16  Her   ESCAN00039440: wrong syntax used for useless assignments void cast
| 2010-03-26  3.04.17  Her   ESCAN00040914: Do not use CanCanInterruptDisable/Restore while the CAN cell is in Sleep Mode
|                      Her   ESCAN00041597: Use v_inc.h instead of vstdlib.h
|                      Her   ESCAN00042152: Support dynamic priority and PGN for NormalFixed Addressing
| 2010-07-14  3.04.18  Her   ESCAN00043607: TP message cannot be sent
|                      Her   ESCAN00044057: Missing variable definition
| 2010-11-14  3.04.19  Her   ESCAN00046715: parameter name "pdata" is interpreted as compiler keyword
| 2011-01-10  3.05.00  Her   ESCAN00047913: Reserve a dynamic Tp channel on reception side
|                      Her   ESCAN00047970: Correct Rx/Tx confusion in assertion
|                      Her   ESCAN00047840: no changes
|                      Her   ESCAN00047981: Support TMS320 with GENy
| 2011-02-14  3.05.01  Her   ESCAN00048680: Correct Rx/Tx confusion in assertion
|                      Her   ESCAN00048682: Mixed up Mixed-11 with Mixed-29 addressing type
| 2011-03-10  3.06.00  Her   ESCAN00048797: TP shall judge the FC to be invalid
| 2011-06-29  3.06.01  Her   ESCAN00049499: NDV V2.3.2 test "FC.WAIT" fails (NISSAN V-CAN/M-CAN GW)
|                      Her   ESCAN00051019: Extended CAN-Id (PGN and Priority bits) is not as configured
******************************************************************************/

#define OSEKTPMC_C_MODULE  /*Get access to locally used generated header informations*/

# include "can_inc.h"
#include "can_def.h"
#include "cy_canfd.h"
#include "tpmc.h"
#include "fblm_diag.h"
#if (defined( TP_ENABLE_MCAN ) || defined ( VGEN_ENABLE_TP_MCAN ))
# include "tp_mcan.h"
#endif
#if defined (TP_ENABLE_SINGLE_MSG_OBJ)
#endif

/*******************************************************************************
* Version check
*******************************************************************************/
#if (TP_ISO15765_VERSION != 0x0306)
# error "TPMC.C and TPMC.H used in different versions, please check!"
#endif
#if (TP_ISO15765_RELEASE_VERSION != 0x01)
# error "TPMC.C and TPMC.H used in different versions, please check!"
#endif
# if (C_VERSION_REF_IMPLEMENTATION < 0x130)
#  error "TPMC needs at least the CANdriver reference implementation LI 1.3"
# endif
/*******************************************************************************
* Transport layer version for diagnostics
*******************************************************************************/
/*TP_ISO15765_VERSION is defined within the tpmc.h file*/
V_MEMROM0 V_MEMROM1 canuint8 V_MEMROM2 kTpMainVersion   = (canuint8)((TP_ISO15765_VERSION >> 8)  & 0xFF);
V_MEMROM0 V_MEMROM1 canuint8 V_MEMROM2 kTpSubVersion    = (canuint8) (TP_ISO15765_VERSION & 0xFF);
V_MEMROM0 V_MEMROM1 canuint8 V_MEMROM2 kTpBugFixVersion =             TP_ISO15765_RELEASE_VERSION;

/*******************************************************************************
* Supported configuration(s)
*******************************************************************************/
#if defined (TPMC_ORGANI_CHECK)
#endif


#if defined (TP_ENABLE_MULTIPLE_ADDRESSING)
# error "The TP-class 'Multiple Addressing MultiTP' is not supported within this version !"
#endif


#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#endif





#if defined (TP_ENABLE_NORMAL_FIXED_ADDRESSING)
# error "Normal Fixed Addressing is not supported within this version !"
#endif

#if defined (TP_ENABLE_MIXED_29_ADDRESSING)
# error "Mixed 29 Addressing is not supported within this version !"
#endif

#if defined (TP_ENABLE_MIXED_11_ADDRESSING)
# error "Mixed 11 Addressing is  not supported within this version !"
#endif

/*******************************************************************************
* External function name adaption
*******************************************************************************/
# if ( defined (C_MULTIPLE_RECEIVE_CHANNEL) ||\
      defined (C_SINGLE_RECEIVE_CHANNEL) )
/*-----------------------------------------------------------------------------
| Indexed CANdrivers
-----------------------------------------------------------------------------*/
#  define FRAME_DATA_PTR                   (rxStruct->pChipData)
#  define RX_HANDLE                        (rxStruct->Handle)
#  define CAN_RX_ACTUAL_ID                 (CanRxActualId(rxStruct))
#  define CAN_RX_ACTUAL_ID_TYPE            (CanRxActualIdType(rxStruct))
#  define CAN_RX_ACTUAL_DLC                (CanRxActualDLC(rxStruct))
#  define CAN_RX_ACTUAL_CAN                ((canbittype)(rxStruct->Channel))
# else
#  if ( kTpNumberOfCanChannels > 1 ) /* more than one can tpChannel ? */
/*-----------------------------------------------------------------------------
| Codedoubled CANdrivers
-----------------------------------------------------------------------------*/
#  define FRAME_DATA_PTR                   (rxStruct->pChipData)
#  define CAN_RX_ACTUAL_ID                 (rxStruct->CanRxActualId)
#  define CAN_RX_ACTUAL_DLC                (rxStruct->CanRxActualDLC)
#  define CAN_RX_ACTUAL_CAN                ((canbittype)(rxStruct->Channel))
#  else
#   if defined ( C_MULTIPLE_RECEIVE_BUFFER )
/*-----------------------------------------------------------------------------
| non-indexed CANdriver (multiplpe buffers/FullCAN)
-----------------------------------------------------------------------------*/
#    if defined  (TP_CAN_CHANNEL )
/*-----------------------------------------------------------------------------
| TP is used on one canChannel with a codedoubled CANdriver
-----------------------------------------------------------------------------*/
#     if  (TP_CAN_CHANNEL == 0 )
#      define FRAME_DATA_PTR               rxDataPtr
#      define RX_HANDLE                    canRxHandle_0
#      define CAN_RX_ACTUAL_ID             CanRxActualId_0
#      define CAN_RX_ACTUAL_DLC            CanRxActualDLC_0
#      define CAN_RX_ACTUAL_CAN            TP_CAN_CHANNEL
#     endif
#     if  (TP_CAN_CHANNEL == 1 )
#      define FRAME_DATA_PTR               rxDataPtr
#      define RX_HANDLE                    canRxHandle_1
#      define CAN_RX_ACTUAL_ID             CanRxActualId_1
#      define CAN_RX_ACTUAL_DLC            CanRxActualDLC_1
#      define CAN_RX_ACTUAL_CAN            TP_CAN_CHANNEL
#     endif
#     if  (TP_CAN_CHANNEL == 2 )
#      define FRAME_DATA_PTR               rxDataPtr
#      define RX_HANDLE                    canRxHandle_2
#      define CAN_RX_ACTUAL_ID             CanRxActualId_2
#      define CAN_RX_ACTUAL_DLC            CanRxActualDLC_2
#      define CAN_RX_ACTUAL_CAN            TP_CAN_CHANNEL
#     endif
#     if  (TP_CAN_CHANNEL == 3 )
#      define FRAME_DATA_PTR               rxDataPtr
#      define RX_HANDLE                    canRxHandle_3
#      define CAN_RX_ACTUAL_ID             CanRxActualId_3
#      define CAN_RX_ACTUAL_DLC            CanRxActualDLC_3
#      define CAN_RX_ACTUAL_CAN            TP_CAN_CHANNEL
#     endif
#     if  (TP_CAN_CHANNEL == 4 )
#      define FRAME_DATA_PTR               rxDataPtr
#      define RX_HANDLE                    canRxHandle_4
#      define CAN_RX_ACTUAL_ID             CanRxActualId_4
#      define CAN_RX_ACTUAL_DLC            CanRxActualDLC_4
#      define CAN_RX_ACTUAL_CAN            TP_CAN_CHANNEL
#     endif
#    else
/*-----------------------------------------------------------------------------
| Standard
-----------------------------------------------------------------------------*/
#     define FRAME_DATA_PTR                rxDataPtr
#     define RX_HANDLE                     canRxHandle
#     define CAN_RX_ACTUAL_ID              CanRxActualId
#     define CAN_RX_ACTUAL_DLC             CanRxActualDLC
#     define CAN_RX_ACTUAL_CAN             0
#    endif
#   endif
#   if defined ( C_SINGLE_RECEIVE_BUFFER )
/*-----------------------------------------------------------------------------
| non-indexed CANdriver (single buffer/BasicCAN)
-----------------------------------------------------------------------------*/
#    if defined  (TP_CAN_CHANNEL )
/*-----------------------------------------------------------------------------
| TP is used on one canChannel with a codedoubled CANdriver
-----------------------------------------------------------------------------*/
#     if  (TP_CAN_CHANNEL == 0 )
#      define FRAME_DATA_PTR               CanRDSPtr_0
#      define RX_HANDLE                    rxObject
#      define CAN_RX_ACTUAL_ID             CanRxActualId_0
#      define CAN_RX_ACTUAL_DLC            CanRxActualDLC_0
#      define CAN_RX_ACTUAL_CAN            TP_CAN_CHANNEL
#     endif
#     if  (TP_CAN_CHANNEL == 1 )
#      define FRAME_DATA_PTR               CanRDSPtr_1
#      define RX_HANDLE                    rxObject
#      define CAN_RX_ACTUAL_ID             CanRxActualId_1
#      define CAN_RX_ACTUAL_DLC            CanRxActualDLC_1
#      define CAN_RX_ACTUAL_CAN            TP_CAN_CHANNEL
#     endif
#     if  (TP_CAN_CHANNEL == 2 )
#      define FRAME_DATA_PTR               CanRDSPtr_2
#      define RX_HANDLE                    rxObject
#      define CAN_RX_ACTUAL_ID             CanRxActualId_2
#      define CAN_RX_ACTUAL_DLC            CanRxActualDLC_2
#      define CAN_RX_ACTUAL_CAN            TP_CAN_CHANNEL
#     endif
#     if  (TP_CAN_CHANNEL == 3 )
#      define FRAME_DATA_PTR               CanRDSPtr_3
#      define RX_HANDLE                    rxObject
#      define CAN_RX_ACTUAL_ID             CanRxActualId_3
#      define CAN_RX_ACTUAL_DLC            CanRxActualDLC_3
#      define CAN_RX_ACTUAL_CAN            TP_CAN_CHANNEL
#     endif
#     if  (TP_CAN_CHANNEL == 4 )
#      define FRAME_DATA_PTR               CanRDSPtr_4
#      define RX_HANDLE                    rxObject
#      define CAN_RX_ACTUAL_ID             CanRxActualId_4
#      define CAN_RX_ACTUAL_DLC            CanRxActualDLC_4
#      define CAN_RX_ACTUAL_CAN            TP_CAN_CHANNEL
#     endif
#    else
/*-----------------------------------------------------------------------------
| Standard
-----------------------------------------------------------------------------*/
#     define FRAME_DATA_PTR                CanRDSPtr
#     define RX_HANDLE                     rxObject
#     define CAN_RX_ACTUAL_ID              CanRxActualId
#     define CAN_RX_ACTUAL_DLC             CanRxActualDLC
#     define CAN_RX_ACTUAL_CAN             0
#    endif
#   endif
#  endif
# endif

/*******************************************************************************
* Can-Driver API adaptions
*******************************************************************************/
# if defined (TP_CAN_CODEDOUBLED)
#  if (kTpNumberOfCanChannels > 1)
/*-----------------------------------------------------------------------------
| TP is used on more than one canChannel with a codedoubled CANdriver
-----------------------------------------------------------------------------*/
#   define TPCANTRANSMIT(canChannel)                   (TpCanTransmitField[canChannel])
#   define TPCANCANCELTRANSMIT(canChannel)             (TpCanCancelTransmitField[canChannel])
#   define TPCANDYNTXOBJSETEXTID(canChannel)           (TpCanDynTxObjSetExtIdField[canChannel])
#   define TPCANDYNTXOBJSETID(canChannel)              (TpCanDynTxObjSetIdField[canChannel])

#   define TPCANGETDYNTXOBJ(canChannel)                (TpCanGetDynTxObjField[canChannel])
#   define TPCANDYNTXOBJSETDLC(canChannel)             (TpCanDynTxObjSetDlcField[canChannel])
#   define TPCANDYNTXOBJSETDATAPTR(canChannel)         (TpCanDynTxObjSetDataPtrField[canChannel])
#   define TPCANDYNTXOBJSETPRETRANSMITFCT(canChannel)  (TpCanDynTxObjSetPreTransmitFctField[canChannel])
#   define TPCANDYNTXOBJSETCONFIRMATIONFCT(canChannel) (TpCanDynTxObjSetConfirmationFctField[canChannel])

#   define TpGlobalInterruptDisable()                  (CanInterruptDisable_0())
#   define TpGlobalInterruptRestore()                  (CanInterruptRestore_0())
#  endif
# else
/*-----------------------------------------------------------------------------
| TP is used on one canChannel with a codedoubled CANdriver
-----------------------------------------------------------------------------*/
#  if defined  (TP_CAN_CHANNEL )
#   if  (TP_CAN_CHANNEL == 0 )
#    define TPCANTRANSMIT(canChannel)                   CanTransmit_0
#    define TPCANCANCELTRANSMIT(canChannel)             CanCancelTransmit_0
#    define TPCANDYNTXOBJSETEXTID(canChannel)           CanDynTxObjSetExtId_0
#    define TPCANDYNTXOBJSETID(canChannel)              CanDynTxObjSetId_0

#    define TPCANGETDYNTXOBJ(canChannel)                CanGetDynTxObj_0
#    define TPCANDYNTXOBJSETDLC(canChannel)             CanDynTxObjSetDlc_0
#    define TPCANDYNTXOBJSETDATAPTR(canChannel)         CanDynTxObjSetDataPtr_0
#    define TPCANDYNTXOBJSETPRETRANSMITFCT(canChannel)  CanDynTxObjSetPreTransmitFct_0
#    define TPCANDYNTXOBJSETCONFIRMATIONFCT(canChannel) CanDynTxObjSetConfirmationFct_0

#    define TpGlobalInterruptDisable()                  (CanInterruptDisable_0())
#    define TpGlobalInterruptRestore()                  (CanInterruptRestore_0())
#   endif
#   if  (TP_CAN_CHANNEL == 1 )
#    define TPCANTRANSMIT(canChannel)                   CanTransmit_1
#    define TPCANCANCELTRANSMIT(canChannel)             CanCancelTransmit_1
#    define TPCANDYNTXOBJSETEXTID(canChannel)           CanDynTxObjSetExtId_1
#    define TPCANDYNTXOBJSETID(canChannel)              CanDynTxObjSetId_1

#    define TPCANGETDYNTXOBJ(canChannel)                CanGetDynTxObj_1
#    define TPCANDYNTXOBJSETDLC(canChannel)             CanDynTxObjSetDlc_1
#    define TPCANDYNTXOBJSETDATAPTR(canChannel)         CanDynTxObjSetDataPtr_1
#    define TPCANDYNTXOBJSETPRETRANSMITFCT(canChannel)  CanDynTxObjSetPreTransmitFct_1
#    define TPCANDYNTXOBJSETCONFIRMATIONFCT(canChannel) CanDynTxObjSetConfirmationFct_1

#    define TpGlobalInterruptDisable()                  (CanInterruptDisable_1())
#    define TpGlobalInterruptRestore()                  (CanInterruptRestore_1())
#   endif
#   if  (TP_CAN_CHANNEL == 2 )
#    define TPCANTRANSMIT(canChannel)                   CanTransmit_2
#    define TPCANCANCELTRANSMIT(canChannel)             CanCancelTransmit_2
#    define TPCANDYNTXOBJSETEXTID(canChannel)           CanDynTxObjSetExtId_2
#    define TPCANDYNTXOBJSETID(canChannel)              CanDynTxObjSetId_2

#    define TPCANGETDYNTXOBJ(canChannel)                CanGetDynTxObj_2
#    define TPCANDYNTXOBJSETDLC(canChannel)             CanDynTxObjSetDlc_2
#    define TPCANDYNTXOBJSETDATAPTR(canChannel)         CanDynTxObjSetDataPtr_2
#    define TPCANDYNTXOBJSETPRETRANSMITFCT(canChannel)  CanDynTxObjSetPreTransmitFct_2
#    define TPCANDYNTXOBJSETCONFIRMATIONFCT(canChannel) CanDynTxObjSetConfirmationFct_2

#    define TpGlobalInterruptDisable()                  (CanInterruptDisable_2())
#    define TpGlobalInterruptRestore()                  (CanInterruptRestore_2())
#   endif
#   if  (TP_CAN_CHANNEL == 3 )
#    define TPCANTRANSMIT(canChannel)                   CanTransmit_3
#    define TPCANCANCELTRANSMIT(canChannel)             CanCancelTransmit_3
#    define TPCANDYNTXOBJSETEXTID(canChannel)           CanDynTxObjSetExtId_3
#    define TPCANDYNTXOBJSETID(canChannel)              CanDynTxObjSetId_3

#    define TPCANGETDYNTXOBJ(canChannel)                CanGetDynTxObj_3
#    define TPCANDYNTXOBJSETDLC(canChannel)             CanDynTxObjSetDlc_3
#    define TPCANDYNTXOBJSETDATAPTR(canChannel)         CanDynTxObjSetDataPtr_3
#    define TPCANDYNTXOBJSETPRETRANSMITFCT(canChannel)  CanDynTxObjSetPreTransmitFct_3
#    define TPCANDYNTXOBJSETCONFIRMATIONFCT(canChannel) CanDynTxObjSetConfirmationFct_3

#    define TpGlobalInterruptDisable()                  (CanInterruptDisable_3())
#    define TpGlobalInterruptRestore()                  (CanInterruptRestore_3())
#   endif
#   if  (TP_CAN_CHANNEL == 4 )
#    define TPCANTRANSMIT(canChannel)                   CanTransmit_4
#    define TPCANCANCELTRANSMIT(canChannel)             CanCancelTransmit_4
#    define TPCANDYNTXOBJSETEXTID(canChannel)           CanDynTxObjSetExtId_4
#    define TPCANDYNTXOBJSETID(canChannel)              CanDynTxObjSetId_4

#    define TPCANGETDYNTXOBJ(canChannel)                CanGetDynTxObj_4
#    define TPCANDYNTXOBJSETDLC(canChannel)             CanDynTxObjSetDlc_4
#    define TPCANDYNTXOBJSETDATAPTR(canChannel)         CanDynTxObjSetDataPtr_4
#    define TPCANDYNTXOBJSETPRETRANSMITFCT(canChannel)  CanDynTxObjSetPreTransmitFct_4
#    define TPCANDYNTXOBJSETCONFIRMATIONFCT(canChannel) CanDynTxObjSetConfirmationFct_4

#    define TpGlobalInterruptDisable()                  (CanInterruptDisable_4())
#    define TpGlobalInterruptRestore()                  (CanInterruptRestore_4())
#   endif
#  else
/*-----------------------------------------------------------------------------
| Standard
-----------------------------------------------------------------------------*/
#   if (defined( TP_ENABLE_MCAN ) || defined ( VGEN_ENABLE_TP_MCAN ))
#    define TPCANTRANSMIT(canChannel)                  TpMcanLnTransmitData
#    define TPCANCANCELTRANSMIT(canChannel)            TpMcanLnCancelTransmit
#   else
#    define TPCANTRANSMIT(canChannel)                  CanTransmit
#    define TPCANCANCELTRANSMIT(canChannel)            CanCancelTransmit
#   endif
#   define TPCANDYNTXOBJSETEXTID(canChannel)           CanDynTxObjSetExtId
#   define TPCANDYNTXOBJSETID(canChannel)              CanDynTxObjSetId

#   define TPCANGETDYNTXOBJ(canChannel)                CanGetDynTxObj
#   define TPCANDYNTXOBJSETDLC(canChannel)             CanDynTxObjSetDlc
#   define TPCANDYNTXOBJSETDATAPTR(canChannel)         CanDynTxObjSetDataPtr
#   define TPCANDYNTXOBJSETPRETRANSMITFCT(canChannel)  CanDynTxObjSetPreTransmitFct
#   define TPCANDYNTXOBJSETCONFIRMATIONFCT(canChannel) CanDynTxObjSetConfirmationFct

#   define TpGlobalInterruptDisable()                  (CanInterruptDisable())
#   define TpGlobalInterruptRestore()                  (CanInterruptRestore())
#  endif
# endif


#  define TP_TX_PRE_CANTRANSMIT(tpChannel)
#  define TP_RX_PRE_CANTRANSMIT(tpChannel)

/*-----------------------------------------------------------------------------
| TransmitHandles
-----------------------------------------------------------------------------*/

/* Single channel TP but multi connection on multiple CAN channels */
#if defined ( TP_ENABLE_SINGLE_CHANNEL_TP )
# if defined ( TP_ENABLE_SINGLE_CHAN_MULTICONN )
#  if defined( TP_ENABLE_NORMAL_ADDRESSING )
#   define kTpRxTxHandleFieldSize kCanNumberOfChannels
#  endif
# endif
#endif

#if defined (TP_ENABLE_SINGLE_MSG_OBJ)

/* ****** Post Build support of PDU-IDs in case of AUTOSAR CANIF is available */
/* ********************* Post Build support CANIF ***************************/

# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
/** SingleTP configuration **************************************************/
#  if defined TP_ENABLE_MULTIPLE_NODES
#   if (defined (TP_ENABLE_NORMAL_ADDRESSING) || defined (TP_ENABLE_EXTENDED_ADDRESSING))
#     define TP_TX_HANDLE(tpChannel)              (kTpTxHandle_Field[comMultipleECUCurrent])
#     define TP_RX_HANDLE(tpChannel)              (kTpTxHandle_Field[comMultipleECUCurrent])
#   else
#     define TP_TX_HANDLE(tpChannel)              kTpTxHandle
#     define TP_RX_HANDLE(tpChannel)              kTpTxHandle
#   endif
#  else
#   if defined ( TP_ENABLE_SINGLE_CHAN_MULTICONN )
#    if (defined (TP_ENABLE_NORMAL_ADDRESSING) )
#      define TP_TX_HANDLE(tpChannel)              (kTpTxHandle_Field[connHandle])
#      define TP_RX_HANDLE(tpChannel)              (kTpTxHandle_Field[connHandle])
#    else
#     error "Single channel multiple connection only defined for normal and mixed-11 addressing !"
#    endif
#   else
#    if (TP_USE_TX_HANDLE_CHANGEABLE == kTpOn)
#     define TP_TX_HANDLE(tpChannel)             tpTxHandle
#     define TP_RX_HANDLE(tpChannel)             tpTxHandle
#    else
#      define TP_TX_HANDLE(tpChannel)             kTpTxHandle
#      define TP_RX_HANDLE(tpChannel)             kTpTxHandle
#      define TP_TX_INIT_HANDLE(canChannel)       kTpTxHandle
#      define TP_RX_INIT_HANDLE(canChannel)       kTpTxHandle
#    endif
#   endif
#  endif
# else
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
/** Dynamic MultiTP configuration ********************************************/
#   if (kTpNumberOfCanChannels > 1)
#     define TP_TX_HANDLE(tpChannel)            (kTpTxHandle_Field[tpTxInfoStruct[tpChannel].CanChannel])
#     define TP_RX_HANDLE(tpChannel)            (kTpTxHandle_Field[tpRxInfoStruct[tpChannel].CanChannel])
#     define TP_TX_INIT_HANDLE(canChannel)      (kTpTxHandle_Field[canChannel])
#     define TP_RX_INIT_HANDLE(canChannel)      (kTpTxHandle_Field[canChannel])
#   else
#     define TP_TX_HANDLE(tpChannel)            kTpTxHandle
#     define TP_RX_HANDLE(tpChannel)            kTpTxHandle
#     define TP_TX_INIT_HANDLE(canChannel)      kTpTxHandle
#     define TP_RX_INIT_HANDLE(canChannel)      kTpTxHandle
#   endif
#  else
/** Static MultiTP configuration ********************************************/
#   if defined (TP_CAN_CODEDOUBLED)
#    error CodeDoubled Can-Driver not supported with static TP-channels
#   else
#    if (TP_USE_TX_HANDLE_CHANGEABLE == kTpOn)
#     define TP_TX_HANDLE(tpChannel)           (tpTxHandle_Field[tpChannel])
#     define TP_RX_HANDLE(tpChannel)           (tpTxHandle_Field[tpChannel])
#    else
#      define TP_TX_HANDLE(tpChannel)           (kTpTxHandle_Field[tpChannel])
#      define TP_RX_HANDLE(tpChannel)           (kTpTxHandle_Field[tpChannel])
#    endif
#   endif
#  endif
# endif
#endif



# if( (defined( TP_RX_ENABLE_DYN_EXT_ID )) || (defined( TP_TX_ENABLE_DYN_EXT_ID )) )
#  error "Dynamic setting of Priority and PGN is only possible with NormalFixed or Mixed29 addressing"
# endif

# if defined (TP_ENABLE_SINGLE_MSG_OBJ)
# endif

# if defined(TP_ENABLE_EXTENDED_ADDRESSING)
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#   if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
#    define TPTXSETID(tpChannel)      (TPCANDYNTXOBJSETID(tpTxInfoStruct[tpChannel].CanChannel)  (TP_TX_HANDLE(tpChannel), (canuint16)(tpTxInfoStruct[tpChannel].BaseAddress + (canuint8)TP_TX_ECU_NR(tpChannel))))
#    define TPRXSETID(tpChannel)      (TPCANDYNTXOBJSETID(tpRxInfoStruct[tpChannel].CanChannel)  (TP_RX_HANDLE(tpChannel), (canuint16)(tpRxInfoStruct[tpChannel].BaseAddress + (canuint8)TP_RX_ECU_NR(tpChannel))))
#   else
#    define TPTXSETID(tpChannel)      (TPCANDYNTXOBJSETID(tpTxInfoStruct[tpChannel].CanChannel)  (TP_TX_HANDLE(tpChannel), (canuint16)(TP_RX_BASE_ADDRESS + (canuint8)TP_TX_ECU_NR(tpChannel))))
#    define TPRXSETID(tpChannel)      (TPCANDYNTXOBJSETID(tpRxInfoStruct[tpChannel].CanChannel)  (TP_RX_HANDLE(tpChannel), (canuint16)(TP_RX_BASE_ADDRESS + (canuint8)TP_RX_ECU_NR(tpChannel))))
#   endif
#  else
#   define TPTXSETID(tpChannel)
#   define TPRXSETID(tpChannel)
#  endif
# elif (defined(TP_ENABLE_NORMAL_ADDRESSING) )
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#   define TPTXSETID(tpChannel)         (TpTxSetID(tpChannel))
static void TpTxSetID(canuintCPUtype tpChannel);
#   define TPRXSETID(tpChannel)         (TpRxSetID(tpChannel))
static void TpRxSetID(canuintCPUtype tpChannel);
#  else
#   define TPTXSETID(tpChannel)
#   define TPRXSETID(tpChannel)
#  endif
# endif

/*******************************************************************************
* ASSERTIONS
*******************************************************************************/
# if defined  (TP_ENABLE_USER_CHECK )
#  define assertUser(ch,p,e)                {if (!(p))    {ApplTpFatalError(e); return;}}
#  define assertReturnUser(ch,p,e,r)        {if (!(p))    {ApplTpFatalError(e); return (r);}}
# else
#  define assertUser(ch,p,e)
#  define assertReturnUser(ch,p,e,r)
# endif
# if defined  (TP_ENABLE_USER_CHECK )
#  define assertGeneral(ch,e)               (ApplTpFatalError(e))
# else
#  define assertGeneral(ch,b)
# endif
# if defined  (TP_ENABLE_INTERNAL_CHECK )
#  define assertInternal(ch,p,e)            if (!(p))    {ApplTpFatalError(e); return;}
#  define assertReturnInternal(ch,p,e,r)    if (!(p))    {ApplTpFatalError(e); return (r);}
# else
#  define assertInternal(ch,p,e)
#  define assertReturnInternal(ch,p,e,r)
# endif
# if defined  (TP_ENABLE_GEN_CHECK )
#  define assertGen(ch,p,e)                 {if (!(p))    ApplTpFatalError(e)}
# else
#  define assertGen(ch,a,b)
# endif
# if defined  (TP_ENABLE_RUNTIME_CHECK )
#  define RuntimeCheck(ch,p,e)              {if (!(p))    {return;}}
#  define RuntimeCheck_Return(ch,p,e,r)     {if (!(p))    {return (r);}}
# else
#  define RuntimeCheck(ch,p,e)
#  define RuntimeCheck_Return(ch,p,e,r)
# endif

/*******************************************************************************
* Default values
*******************************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
# define tpChannel 0
# define rxChannel 0
# define txChannel 0
# define TP_RX_RESET_CHANNEL(tpChannel)   { TpRxResetChannel(); }
#else
# define TP_RX_RESET_CHANNEL(tpChannel)   { TpRxResetChannel((canuint8)tpChannel); }
#endif

#if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
#else
# define canChannel 0
#endif

#if defined(TP_ENABLE_EXTENDED_ADDRESSING)
# if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
#  if !defined (TP_RX_BASE_ADDRESS_OFFSET)
#   define TP_RX_BASE_ADDRESS_OFFSET(tpChannel)   0  /* Compatibility for old tools */
#  endif
# endif
#endif
/*******************************************************************************
* Transport protocol TPCI codes and protocol lengths
*******************************************************************************/
#define kL4_SingleFrame                0x00
#define kL4_FirstFrame                 0x10
#define kL4_ConsecutiveFrame           0x20
#define kL4_FlowControl                0x30
#define kL4_FlowStatus_Wait            0x31
#define kL4_FlowStatus_Overrun         0x32
#define kL4_FirstFrameWithoutFC        0x50
#define kL4_ConsecutiveFrameWithoutFC  0x60

#define kL4_SNMask                     0x0F

#if ((TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn) || (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn))
# define CAN_MAX_ID                     0x1fffffff
#else
# define CAN_MAX_ID                     0x07ff
#endif
 /*CANFD Format */
#define CAN_R_DLC_VALUE_8       8u
#define CAN_R_DLC_VALUE_12      12u
#define CAN_R_DLC_VALUE_16      16u
#define CAN_R_DLC_VALUE_20      20u
#define CAN_R_DLC_VALUE_24      24u
#define CAN_R_DLC_VALUE_32      32u
#define CAN_R_DLC_VALUE_48      48u
#define CAN_R_DLC_VALUE_64      64u

#define CAN_DLC_VALUE_0x8      0x8u
#define CAN_DLC_VALUE_0x9      0x9u
#define CAN_DLC_VALUE_0xA      0xAu
#define CAN_DLC_VALUE_0xB      0xBu
#define CAN_DLC_VALUE_0xC      0xCu
#define CAN_DLC_VALUE_0xD      0xDu
#define CAN_DLC_VALUE_0xE      0xEu
#define CAN_DLC_VALUE_0xF      0xFu

/*******************************************************************************
* TPCI offset in CAN-frame
*******************************************************************************/
# if defined (TP_ENABLE_NORMAL_MIXED11_ADDRESSING)
#  if (kTpTxChannelCount != kTpRxChannelCount)
#    error "WithoutFC for combined mixed 11 bit addressing with normal addressing is (currently) not supported!"
#  endif
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#    error "Combined mixed 11 bit addressing with normal addressing is not compatible with dynamic channel allocation!"
#  endif
#  define FORMAT_OFFSET                TpAddressingFormatOffset[tpChannel]
# else
#  if defined(TP_ENABLE_EXTENDED_ADDRESSING)
#   define FORMAT_OFFSET                1
#  else
#   define FORMAT_OFFSET                0
#  endif
# endif

/*******************************************************************************
* TP ISO offsets in CAN-frame
*******************************************************************************/
#define FRAME_LENGTH                   8 /* CAN-Frame */
#define FRAME_CANFD_LENGTH             15 /* CANFD-Frame Max Length */
#define FRAME_CANFD_MAX_REAL_LENGTH    64 /* CANFD-Frame Max Length */
#define FRAME_CANFD_MAX_FF_DL    	   4095 /* CANFD-Frame FF_DL Max Length */
#define FC_LENGTH                      3
#define TPCI_OFFSET                    0
#if defined(TP_ENABLE_EXTENDED_ADDRESSING) || defined(TP_FUNC_ENABLE_EXTENDED_ADDRESSING)
#define TARGET_OFFSET                  0
#endif
#define DL_OFFSET                      1
#define FF_OFFSET                      2
#define SF_OFFSET                      1
#define CF_OFFSET                      1
#define STMIN_OFFSET                   2
#define BS_OFFSET                      1
#define FF_DL_OFFSET                   1

/*******************************************************************************
* Global transport layer Buffer
*******************************************************************************/
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#   if defined (TPC_ENABLE_DYN_TX_DATAPTR)
MEMORY_NEAR_TP_SAVE static canuint8 tpTxBuffer[kCanNumberOfChannels][8]; /*
* Description : TxData Buffer
*
*******************************************************************************/
#    ifdef TP_ENABLE_SINGLE_MSG_OBJ
#    endif
#   endif
#  endif

#if defined (TP_ENABLE_SINGLE_MSG_OBJ)
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#  if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && defined (TPC_ENABLE_DYN_TX_DATAPTR))
#   define TpCanTxDataPtr(tpChannel)      (tpTxBuffer[0])
#   define TpCanTxFCDataPtr(tpChannel)    (tpTxBuffer[0])
#   define TpCanTxDataPtr_Init()          (tpTxBuffer[0])
#   define TpCanTxFCDataPtr_Init()        (tpTxBuffer[0])
#  else
#    if defined ( TP_ENABLE_SINGLE_CHAN_MULTICONN )
#     define TpCanTxDataPtr(tpChannel)     kTpTxData_Field[connHandle]
#     define TpCanTxFCDataPtr(tpChannel)   kTpTxData_Field[connHandle]
#    else
#     define TpCanTxDataPtr(tpChannel)     kTpTxData
#     define TpCanTxFCDataPtr(tpChannel)   kTpTxData
#    endif
#  endif
# else
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#   if defined (TPC_ENABLE_DYN_TX_DATAPTR)
#    if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
#     define TpCanTxDataPtr(tpChannel)   (tpTxBuffer[tpTxInfoStruct[tpChannel].CanChannel])
#     define TpCanTxFCDataPtr(tpChannel) (tpTxBuffer[tpRxInfoStruct[tpChannel].CanChannel])
#     define TpCanTxDataPtr_Init()       (tpTxBuffer[canChannel])
#     define TpCanTxFCDataPtr_Init()     (tpTxBuffer[canChannel])
#    else
#     define TpCanTxDataPtr(tpChannel)   (tpTxBuffer[0])
#     define TpCanTxFCDataPtr(tpChannel) (tpTxBuffer[0])
#     define TpCanTxDataPtr_Init()       (tpTxBuffer[0])
#     define TpCanTxFCDataPtr_Init()     (tpTxBuffer[0])
#    endif
#   else
#    if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
#     define TpCanTxDataPtr(tpChannel)    (kTpTxData_Field[tpTxInfoStruct[tpChannel].CanChannel])
#     define TpCanTxFCDataPtr(tpChannel)  (kTpTxData_Field[tpRxInfoStruct[tpChannel].CanChannel])
#    else
#     define TpCanTxDataPtr(tpChannel)    kTpTxData
#     define TpCanTxFCDataPtr(tpChannel)  kTpTxData
#    endif
#   endif
/* Description : List of pointers to transmit tpChannel data buffer
*******************************************************************************/
#  else /* defined (TP_ENABLE_DYNAMIC_CHANNELS) */

#   define TpCanTxDataPtr(tpChannel)    (kTpTxData_Field[tpChannel])
#   define TpCanTxFCDataPtr(tpChannel)  (kTpTxData_Field[tpChannel]) /*
* Description : List of pointers to transmit tpChannel data buffer
*
*******************************************************************************/
#  endif
# endif
#endif   /* TP_ENABLE_SINGLE_MSG_OBJ  */

/*******************************************************************************
* Transport protocol states
*******************************************************************************/
typedef enum {
  kRxState_Idle = 0,
  kRxState_ApplInformed,
  kRxState_CanFrameReceived,
  kRxState_WaitCF,
  kRxState_WaitFC,
  kRxState_WaitForFCConfIsr,
#if defined (TP_ENABLE_FC_WAIT)
  kRxState_WaitForFCWait,
#endif
#if defined (TP_ENABLE_ISO_15765_2_2)
  kRxState_WaitForFCOverConfIsr,
#endif
  kRxState_Error
} tTpRxStateEngine;

typedef enum {
  kTxState_Idle = 0,
  kTxState_Reserved,
  kTxState_WaitFC,
  kTxState_WaitForTpTxCF,
  kTxState_WaitForMinTimer,
  kTxState_WaitForSFConfIsr,        /* Single Frame           */
  kTxState_WaitForFFConfIsr,        /* First Frame            */
  kTxState_WaitForCFConfIsr,        /* Consecutive Frame      */
  kTxState_WaitForLastCFConfIsr,    /* Last Consecutive Frame */
  kTxState_Error
} tTpTxStateEngine;

typedef enum {
	TP_CANFD_FORMAT,
	TP_CAN_FORMAT,
} tTpCanFrameFormat;

/*******************************************************************************
* Global transport layer data for transmit channels
*******************************************************************************/

/*lint -save -e46*/
typedef struct TpStateTag
{
  tTpEngineTimer Timer;
  canuint8 BSCounter;
#if (defined( TP_ENABLE_MCAN ) || defined ( VGEN_ENABLE_TP_MCAN ))
  canuint8 WFTCounter;
#endif
  tTpTxStateEngine engine;
  canbittype queued:1;
  canbittype blocked:1;
  canbittype retransmit:1;
#if (TP_USE_ONLY_FIRST_FC == kTpOn)
  canbittype firstFC:1;
#endif
#if defined (TP_TEST_ROUTINE_CONF_TIMEOUT)
  canbittype forceConfTimeout:1;
#endif
} tTpTxState;

typedef volatile tTpTxState* tvolatileTpTxState;
/*lint -restore */

MEMORY_NEAR static  tTpTxState      tpTxState[kTpTxChannelCount];
MEMORY_NEAR_TP_SAVE tTpTxInfoStruct tpTxInfoStruct[kTpTxChannelCount];
uint8 Appl_QueNumber = 0u;
/*******************************************************************************
* Global transport layer data for receive channels
*******************************************************************************/
/*lint -save -e46*/
typedef struct
{
  tTpEngineTimer Timer;
  canuint8 BSCounter;
#if defined (TP_ENABLE_FC_WAIT)
  canuint8 WFTCounter;
#endif
  tTpRxStateEngine engine;
  canbittype queued:1;
  canbittype retransmit:1;
#if (TP_USE_OVERRUN_INDICATION == kTpOn)
  canbittype noCopyData:1;
#endif
#if defined (TP_TEST_ROUTINE_CONF_TIMEOUT)
  canbittype forceConfTimeout:1;
#endif
} tTpRxState;

typedef volatile tTpRxState* tvolatileTpRxState;
/*lint -restore */
uint8 TpLongCanFdTxTransmit = FALSE;  /*Used to Send Frame of more than 8 bytes*/
MEMORY_NEAR static  tTpRxState      tpRxState[kTpRxChannelCount];
MEMORY_NEAR_TP_SAVE tTpRxInfoStruct tpRxInfoStruct[kTpRxChannelCount];
static tTpCanFrameFormat tpRxCanFrameFormat = TP_CANFD_FORMAT;
static uint8 tpRxCheckCanDlcFail = FALSE;
#if (TP_SECURITY_LEVEL > 0)
  MEMORY_NEAR static canuint8 tpStateTaskBusy;
#endif


/*******************************************************************************
* Global transport layer data
*******************************************************************************/
#if FBLM_CANFD_SUPPORT
  tCanFdMsgObject PortingData;
#else
  tMsgObject PortingData;
#endif

#if (TP_USE_TX_HANDLE_CHANGEABLE == kTpOn)
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
MEMORY_NEAR_TP_SAVE CanTransmitHandle tpTxHandle;
#  if defined( TP_ENABLE_SINGLE_MSG_OBJ )
#  endif
# else
MEMORY_NEAR_TP_SAVE CanTransmitHandle tpTxHandle_Field[kTpTxChannelCount];
#  if defined( TP_ENABLE_SINGLE_MSG_OBJ )
#  endif
# endif
/* Description :
*
*
* Val. range / Coding: 0..254
*******************************************************************************/
#endif

#if defined ( TP_ENABLE_SINGLE_CHANNEL_TP )
# if defined ( TP_ENABLE_SINGLE_CHAN_MULTICONN )
#  if defined( TP_ENABLE_NORMAL_ADDRESSING )
MEMORY_NEAR_TP_SAVE CanTransmitHandle connHandle;
#   endif
#  endif
/* Description :
*
*
* Val. range / Coding: 0..254
*******************************************************************************/
#endif

/*******************************************************************************
* Transport protocol confirmation support
*******************************************************************************/
# ifndef kTpTxConfirmationTimeout
#  if (kConfInterruptTimeout == 0)
#   error "kConfInterruptTimeout can not be zero !"
#  endif
#  define kTpTxConfirmationTimeout        (tTpEngineTimer)((kConfInterruptTimeout/TpTxCallCycle)+1)
# endif
# ifndef kTpRxConfirmationTimeout
#  define kTpRxConfirmationTimeout        (tTpEngineTimer)((kConfInterruptTimeout/TpRxCallCycle)+1)
# endif

#if defined(TP_ENABLE_DYN_CHANNEL_TIMING)
extern tTpEngineTimer tpRxConfirmationTimeout [kTpRxChannelCount];
extern tTpEngineTimer tpTxConfirmationTimeout [kTpTxChannelCount];
# define TpRxConfirmationTimeout(tpChannel)    (tTpEngineTimer)(tpRxConfirmationTimeout[tpChannel])
# define TpTxConfirmationTimeout(tpChannel)    (tTpEngineTimer)(tpTxConfirmationTimeout[tpChannel])
#else
# if defined(TP_CHANNEL_SPECIFIC_TIMING)
V_MEMROM0 extern V_MEMROM1 tTpEngineTimer V_MEMROM2 tpTxConfirmationTimeout[kTpTxChannelCount];
V_MEMROM0 extern V_MEMROM1 tTpEngineTimer V_MEMROM2 tpRxConfirmationTimeout[kTpRxChannelCount];
#   define TpRxConfirmationTimeout(tpChannel)   (tTpEngineTimer)(tpRxConfirmationTimeout[tpChannel])
#   define TpTxConfirmationTimeout(tpChannel)   (tTpEngineTimer)(tpTxConfirmationTimeout[tpChannel])
# else
#  define TpRxConfirmationTimeout(tpChannel)    (tTpEngineTimer)(kTpRxConfirmationTimeout)
#  define TpTxConfirmationTimeout(tpChannel)    (tTpEngineTimer)(kTpTxConfirmationTimeout)
# endif
#endif

/*******************************************************************************
* Transport protocol blocksize access
*******************************************************************************/
#if (TP_USE_EXTENDED_API_BS == kTpOn)
# define TpRxSetBlockSize(tpChannel, newBS)      (tpRxInfoStruct[tpChannel].BlockSize=(newBS))
# define TpRxGetBlockSize(tpChannel)             (tpRxInfoStruct[tpChannel].BlockSize)
# define TpRxReloadBSCnt(tpChannel)              (tpRxState[tpChannel].BSCounter = (tpRxInfoStruct[tpChannel].BlockSize) )
# if defined(TP_CHANNEL_SPECIFIC_TIMING)
#   define TpRxGetBlockSizeDefault(tpChannel)    (TpBlockSize[tpChannel])
# else
#  define TpRxGetBlockSizeDefault(tpChannel)     (kBSRequested)
# endif
#else
# if defined(TP_CHANNEL_SPECIFIC_TIMING)
#   define TpRxReloadBSCnt(tpChannel)            (tpRxState[tpChannel].BSCounter = (TpBlockSize[tpChannel]))
#   define TpRxGetBlockSize(tpChannel)           (TpBlockSize[tpChannel])
# else
#  define TpRxReloadBSCnt(tpChannel)             (tpRxState[tpChannel].BSCounter = (kBSRequested))
#  define TpRxGetBlockSize(tpChannel)            (kBSRequested)
# endif
#endif /* (TP_USE_EXTENDED_API_BS == kTpOn) */

#if (TP_USE_EXTENDED_API_STMIN == kTpOn)
# define TpRxGetSTMINtime(tpChannel)             (tpRxInfoStruct[tpChannel].STMin)
# if defined(TP_CHANNEL_SPECIFIC_TIMING)
#   define TpRxGetSTMINtimeDefault(tpChannel)    (TpSTMin[tpChannel])
# else
#  define TpRxGetSTMINtimeDefault(tpChannel)     (TpSTMin)
# endif
#else
# if defined(TP_CHANNEL_SPECIFIC_TIMING)
#   define TpRxGetSTMINtime(tpChannel)           (TpSTMin[tpChannel])
# else
#  define TpRxGetSTMINtime(tpChannel)            (TpSTMin)
# endif
#endif /* (TP_USE_EXTENDED_API_STMIN == kTpOn) */

#if defined(TP_ENABLE_DYN_TX_STMIN_TIMING)
# define TpTxGetSTMINtime(tpChannel)             (tTpEngineTimer)(tpTxCFDelay[tpChannel])
#elif (TP_USE_STMIN_OF_FC == kTpOn)
# define TpTxGetSTMINtime(tpChannel)             (tpTxInfoStruct[tpChannel].STMin)
#else
# if defined(TP_CHANNEL_SPECIFIC_TIMING)
#   define TpTxGetSTMINtime(tpChannel)           (tTpEngineTimer)(TpTxTransmitCF[tpChannel])
# else
#  ifndef TpTxTransmitCF
/* Timer value in counter units */
#   define TpTxGetSTMINtime(tpChannel)           ((tTpEngineTimer)((TpTransmitCF+(TpTxCallCycle-1))/TpTxCallCycle))
#  else
#   define TpTxGetSTMINtime(tpChannel)           ((tTpEngineTimer)TpTxTransmitCF)
#  endif
# endif
#endif /* (TP_USE_STMIN_OF_FC == kTpOn) */

#if (TP_USE_STMIN_OF_FC == kTpOn)
# if defined(TP_CHANNEL_SPECIFIC_TIMING)
#   define TpTxGetSTMINDefaultTime(tpChannel)    (tTpEngineTimer)(TpTxTransmitCF[tpChannel])
# else
#  ifndef TpTxTransmitCF
/* Timer value in counter units */
#   define TpTxGetSTMINDefaultTime(tpChannel)    ((tTpEngineTimer)((TpTransmitCF+(TpTxCallCycle-1))/TpTxCallCycle))
#  else
#   define TpTxGetSTMINDefaultTime(tpChannel)    ((tTpEngineTimer)TpTxTransmitCF)
#   if (TpTxTransmitCF == 0)
#    define TP_EXCLUDE_STMININFRAME_CHECK
#   endif
#  endif
# endif
#else
# ifndef TpTxTransmitCF
#  define TpTxGetSTMINDefaultTime(tpChannel)    ((tTpEngineTimer)((TpTransmitCF+(TpTxCallCycle-1))/TpTxCallCycle))
# else
#  define TpTxGetSTMINDefaultTime(tpChannel)    ((tTpEngineTimer)TpTxTransmitCF)
# endif
#endif
/*******************************************************************************
* Transport protocol locally used times
*******************************************************************************/
#if defined(TP_CHANNEL_SPECIFIC_TIMING)
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 TpTxTransmitCF[kTpTxChannelCount];
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 TpRxTimeoutCF [kTpRxChannelCount];
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 TpTxTimeoutFC [kTpTxChannelCount];
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 TpSTMin       [kTpRxChannelCount];
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 TpBlockSize   [kTpRxChannelCount];
#endif

#if defined(TP_ENABLE_DYN_TX_STMIN_TIMING)
tTpEngineTimer tpTxCFDelay [kTpTxChannelCount];
#endif

#if (defined( TP_ENABLE_MCAN ) || defined ( VGEN_ENABLE_TP_MCAN ))
V_MEMROM0 extern V_MEMROM1 canuint8 V_MEMROM2 tpTxWFTmax[kTpTxChannelCount];
#endif

#if defined(TP_ENABLE_DYN_CHANNEL_TIMING)
extern tTpEngineTimer tpRxTimeoutCF [kTpRxChannelCount];
extern tTpEngineTimer tpTxTimeoutFC [kTpTxChannelCount];
# define kTimeoutCF(tpChannel)     (tTpEngineTimer)(tpRxTimeoutCF[tpChannel])
# define kTimeoutFC(tpChannel)     (tTpEngineTimer)(tpTxTimeoutFC[tpChannel])
#else
# if defined(TP_CHANNEL_SPECIFIC_TIMING)
#   define kTimeoutCF(tpChannel)   (tTpEngineTimer)(TpRxTimeoutCF[tpChannel])
#   define kTimeoutFC(tpChannel)   (tTpEngineTimer)(TpTxTimeoutFC[tpChannel])
# else
#  ifndef TpRxTimeoutCF
#   define kTimeoutCF(tpChannel)   ((tTpEngineTimer)((TpTimeoutCF/TpRxCallCycle) + 1) )/*Timer value in counter units*/
#  else
#   define kTimeoutCF(tpChannel)   ((tTpEngineTimer)TpRxTimeoutCF) /*Timer value in counter units*/
#  endif
#  ifndef TpTxTimeoutFC
#   define kTimeoutFC(tpChannel)   ((tTpEngineTimer)((TpTimeoutFC/TpTxCallCycle) + 1) ) /*Timer value in counter units*/
#  else
#   define kTimeoutFC(tpChannel)   ((tTpEngineTimer)TpTxTimeoutFC) /*Timer value in counter units*/
#  endif
# endif  /* #if defined (TP_channel_SPECIFIC_TIMING)   */
#endif   /* #if defined (TP_ENABLE_DYN_CHANNEL_TIMING) */

/*******************************************************************************
* Functions declarations
*******************************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
# define __TpTxInit(tpChannel, errorCode)     (TpTxInit(errorCode))
# define __TpRxInit(tpChannel, errorCode)     (TpRxInit(errorCode))
# define __TpTxPreCanTransmit(tpChannel)      (TpTxPreCanTransmit())
# define __TpTxInternalPrepareOfCF(tpChannel) (TpTxInternalPrepareOfCF())
# define __TpTxStateTask(tpChannel)           (TpTxStateTask())
# define __TpRxStateTask(tpChannel)           (TpRxStateTask())
# define __TpTxPostProcessing(tpChannel)      (TpTxPostProcessing())
# define __TpRxPostProcessing(tpChannel)      (TpRxPostProcessing())

static void TpTxInit(canuint8 errorCode);
static void TpRxInit(canuint8 errorCode);
static canuintCPUtype TpTxPreCanTransmit(void);
static TP_INTERNAL_INLINE void TpTxInternalPrepareOfCF(void);
static TP_INTERNAL_INLINE void TpTxPostProcessing(void);
# if (defined( TP_ENABLE_MF_RECEPTION ) || defined(TP_ENABLE_SF_ACKNOWLEDGE) )
static TP_INTERNAL_INLINE void TpRxPostProcessing(void);
# endif
#else /* defined (TP_ENABLE_SINGLE_CHANNEL_TP) */

# define __TpTxInit(tpChannel, errorCode)     (TpTxInit((canuint8)(tpChannel), (errorCode)))
# define __TpRxInit(tpChannel, errorCode)     (TpRxInit((canuint8)(tpChannel), (errorCode)))
# define __TpTxPreCanTransmit(tpChannel)      (TpTxPreCanTransmit((canuintCPUtype)(tpChannel)))
# define __TpTxInternalPrepareOfCF(tpChannel) (TpTxInternalPrepareOfCF((canuintCPUtype)(tpChannel)))
# define __TpTxStateTask(tpChannel)           (TpTxStateTask((canuint8)(tpChannel)))
# define __TpRxStateTask(tpChannel)           (TpRxStateTask((canuint8)(tpChannel)))
# define __TpTxPostProcessing(tpChannel)      (TpTxPostProcessing((canuintCPUtype)(tpChannel)))
# define __TpRxPostProcessing(tpChannel)      (TpRxPostProcessing((canuintCPUtype)(tpChannel)))

static void TpTxInit(canuint8 tpChannel, canuint8 errorCode);
static void TpRxInit(canuint8 tpChannel, canuint8 errorCode);
static canuintCPUtype TpTxPreCanTransmit(canuintCPUtype tpChannel);
static TP_INTERNAL_INLINE void TpTxInternalPrepareOfCF(canuintCPUtype tpChannel);
static TP_INTERNAL_INLINE void TpTxPostProcessing(canuintCPUtype tpChannel);
# if (defined( TP_ENABLE_MF_RECEPTION ) || defined(TP_ENABLE_SF_ACKNOWLEDGE) )
static TP_INTERNAL_INLINE void TpRxPostProcessing(canuintCPUtype tpChannel);
# endif
#endif /* defined (TP_ENABLE_SINGLE_CHANNEL_TP) */

#if defined TP_FUNC_ENABLE_RECEPTION
void TpFuncInit ( void );
#endif

/*******************************************************************************
* Temp
*******************************************************************************/
#if (kTpNumberOfCanChannels > 1) &&\
    defined( TP_ENABLE_DYNAMIC_CHANNELS)
# define TpIntTxGetCanChannel(tpChannel) (tpTxInfoStruct[tpChannel].CanChannel)
# define TpIntRxGetCanChannel(tpChannel) (tpRxInfoStruct[tpChannel].CanChannel)
#else
# define TpIntTxGetCanChannel(tpChannel) 0
# define TpIntRxGetCanChannel(tpChannel) 0
#endif

/* use CAN interrupt disable/restore instead of global interrupt settings */
# if defined( C_HL_DISABLE_CAN_IRQ_DISABLE )
  /* exception for tms 470 */
#  define TpCanInterruptDisable(tpChannel)   (TpGlobalInterruptDisable())
#  define TpCanInterruptRestore(tpChannel)   (TpGlobalInterruptRestore())
# else

#  if ( defined(C_SINGLE_RECEIVE_CHANNEL) || defined (C_SINGLE_RECEIVE_BUFFER) || defined (C_MULTIPLE_RECEIVE_BUFFER) )
   /* void function */
#   define TpCanInterruptDisable(tpChannel)   CanCanInterruptDisable()
#   define TpCanInterruptRestore(tpChannel)   CanCanInterruptRestore()
#  else
#   if (kCanNumberOfChannels > 1)
    /* multiple CAN channels */
#    if defined( TP_CAN_CODEDOUBLED )
#     error Not supported yet
#    else
#     if (kTpNumberOfCanChannels == 1)
      /* Single TPs included, because SingleTP can be only on one CAN channel active */
#      define TpCanInterruptDisable(tpChannel)  CanCanInterruptDisable(TP_CAN_CHANNEL_INDEX)
#      define TpCanInterruptRestore(tpChannel)  CanCanInterruptRestore(TP_CAN_CHANNEL_INDEX)
#     else
      /* Multi TPs */
#      if defined (TP_ENABLE_DYNAMIC_CHANNELS)
       /* Multi DYNAMIC */
#       define TpCanInterruptDisable(tpChannel)    CanCanInterruptDisable(tpTxInfoStruct[(tpChannel)].CanChannel)
#       define TpCanInterruptRestore(tpChannel)    CanCanInterruptRestore(tpTxInfoStruct[(tpChannel)].CanChannel)
#       define TpRxCanInterruptDisable(tpChannel)  CanCanInterruptDisable(tpRxInfoStruct[(tpChannel)].CanChannel)
#       define TpRxCanInterruptRestore(tpChannel)  CanCanInterruptRestore(tpRxInfoStruct[(tpChannel)].CanChannel)
#      else
       /* Multi STATIC */
#       if defined( TP_SINGLE_CHAN_MULTICONN ) || (TP_USE_TX_HANDLE_CHANGEABLE == kTpOn)
        /* use GlobalInterruptDisable(), the channel info is in RAM and not all assignments
           that are done at runtime are safe */
#        define TpCanInterruptDisable(tpChannel)  (TpGlobalInterruptDisable())
#        define TpCanInterruptRestore(tpChannel)  (TpGlobalInterruptRestore())
#       else
#        define TpCanInterruptDisable(tpChannel)  CanCanInterruptDisable(CanGetChannelOfTxObj(TP_TX_HANDLE(tpChannel)))
#        define TpCanInterruptRestore(tpChannel)  CanCanInterruptRestore(CanGetChannelOfTxObj(TP_TX_HANDLE(tpChannel)))
#       endif
#      endif
#     endif
#    endif
#   else
    /* one CAN channel (always 0) */
#    define TpCanInterruptDisable(tpChannel)  CanCanInterruptDisable(0)
#    define TpCanInterruptRestore(tpChannel)  CanCanInterruptRestore(0)
#   endif
#  endif
# endif
#ifndef TpRxCanInterruptDisable
# define TpRxCanInterruptDisable(tpChannel)  TpCanInterruptDisable(tpChannel)
# define TpRxCanInterruptRestore(tpChannel)  TpCanInterruptRestore(tpChannel)
#endif

# define TpIntAddressFormatCheckEqualToExtended(tpChannel)       (1)
# define TpIntAddressFormatCheckEqualToNormal(tpChannel)         (1)
# define TpIntAddressFormatCheckNotEqualToNormal(tpChannel)      (1)
# define TpIntAddressFormatCheckEqualToNormalFixed(tpChannel)    (1)
# define TpIntAddressFormatCheckEqualToMixed29(tpChannel)        (1)
# define TpIntAddressFormatCheckEqualToMixed11(tpChannel)        (1)

#if defined (TP_ENABLE_SINGLE_MSG_OBJ)
# if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
MEMORY_NEAR_TP_SAVE static canuint8  tpTransmitChannel[kCanNumberOfChannels]; /*
Description :   Semaphore for transmission path
*******************************************************************************/
#  if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
#   define TpIntTxTransmitChannel(tpChannel)      (tpTransmitChannel[tpTxInfoStruct[tpChannel].CanChannel])
#   define TpIntRxTransmitChannel(tpChannel)      (tpTransmitChannel[tpRxInfoStruct[tpChannel].CanChannel])
#  else
#   define TpIntTxTransmitChannel(tpChannel)      (tpTransmitChannel[0])
#   define TpIntRxTransmitChannel(tpChannel)      (tpTransmitChannel[0])
#  endif
# else
MEMORY_NEAR_TP_SAVE static canuint8  tpTransmitChannel[kTpTxChannelCount]; /*
Description :   Semaphore for transmission path
*******************************************************************************/
#  define TpIntTxTransmitChannel(tpChannel)      (tpTransmitChannel[tpChannel])
#  define TpIntRxTransmitChannel(tpChannel)      (tpTransmitChannel[tpChannel])
# endif
#endif

#if defined (TP_ENABLE_SINGLE_MSG_OBJ)
# define TpIntTxTransmitChannel_IsFree(tpChannel)  if (TpIntTxTransmitChannel(tpChannel)  == kTpNoChannel)
# define TpIntTxTransmitChannel_SetFree(tpChannel) (TpIntTxTransmitChannel(tpChannel)     =  kTpNoChannel)
# define TpIntRxTransmitChannel_IsFree(tpChannel)  if (TpIntRxTransmitChannel(tpChannel)  == kTpNoChannel)
# define TpIntRxTransmitChannel_SetFree(tpChannel) (TpIntRxTransmitChannel(tpChannel)     =  kTpNoChannel)
# if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
#  define TpIntTxTransmitChannel_SetLock(tpChannel) (TpIntTxTransmitChannel(tpChannel)     =  (tpChannel))
#  define TpIntTxTransmitChannel_IsTx(tpChannel)    if ((TpIntTxTransmitChannel(tpChannel) & kTpRxChannelMask) == kTpTxChannel)
#  define TpIntRxTransmitChannel_SetLock(tpChannel) (TpIntRxTransmitChannel(tpChannel)     =  ((vuint8)((tpChannel) | kTpRxChannelMask)))
#  define TpIntRxTransmitChannel_IsRx(tpChannel)    if ((TpIntRxTransmitChannel(tpChannel) != kTpNoChannel) && ((TpIntRxTransmitChannel(tpChannel) & kTpRxChannelMask) == kTpRxChannel))
# else /* static + dyn.single */
#  define TpIntTxTransmitChannel_SetLock(tpChannel) (TpIntTxTransmitChannel(tpChannel)    =  kTpTxChannel)
#  define TpIntTxTransmitChannel_IsTx(tpChannel)    if (TpIntTxTransmitChannel(tpChannel) == kTpTxChannel)
#  define TpIntRxTransmitChannel_SetLock(tpChannel) (TpIntRxTransmitChannel(tpChannel)    =  kTpRxChannel)
#  define TpIntRxTransmitChannel_IsRx(tpChannel)    if (TpIntRxTransmitChannel(tpChannel) == kTpRxChannel)
# endif
#endif

/*******************************************************************************
*  PCLINT settings
*******************************************************************************/
/* Unable to match e525 */
/*lint -save -e525*/

#if defined (C_ENABLE_MEMCOPY_SUPPORT)
#else
# if defined (TP_ENABLE_INTERMEDIATE_CANCHIP_BUFFER)
# else
#  if defined (VGEN_ENABLE_VSTDLIB)
#  else
/*******************************************************************************
* NAME:              TpIntMemCpy
* CALLED BY:         TP
* PRECONDITIONS:     none
* PARAMETER:         Ptr to destination, source and the number of bytes to copy
* RETURN VALUE:      none
* DESCRIPTION:       Helper function: Copies nCnt bytes from pSrc to pDest
*******************************************************************************/
void TP_API_CALL_TYPE TpIntMemCpy(TP_MEMORY_MODEL_DATA void *pDest, TP_MEMORY_MODEL_DATA void* pSrc, canuint16 nCnt)
{
  assertUser(tpChannel, pDest != V_NULL, kTpErrMemCpyInvalidParameter);
  assertUser(tpChannel, pSrc  != V_NULL, kTpErrMemCpyInvalidParameter);
  while(nCnt)
  {
    nCnt--;
    ((TP_MEMORY_MODEL_DATA canuint8*)pDest)[nCnt] = ((TP_MEMORY_MODEL_DATA canuint8*)pSrc)[nCnt];
  }
}
#  endif
# endif
#endif


/*******************************************************************************
*
* NAME:              TpInitPowerOn
*
* CALLED BY:         Application
* PRECONDITIONS:     !! Call only once on startup !!
*                    !! If called a second time, the CAN driver initalization
*                    !! function 'CanInitPowerOn' has to be called before!
*
* PARAMETER:         none
* RETURN VALUE:      none
* DESCRIPTION:       Initialization function  to initialize all channels
*
*******************************************************************************/
void TP_API_CALL_TYPE TpInitPowerOn(void)
{
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
  cansintCPUtype tpChannel;
#endif

#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
  CanTransmitHandle tpCanGetDynTxObjReturn;
# if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
  cansintCPUtype canChannel;
# endif
#endif

#if defined( TP_ENABLE_SINGLE_MSG_OBJ )
#endif

#if defined( TP_ENABLE_SINGLE_MSG_OBJ )
#endif


#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
  for(canChannel=(cansintCPUtype)(kCanNumberOfChannels-1);canChannel>=0;canChannel--)
# endif
  {
# if defined TP_ENABLE_SINGLE_MSG_OBJ
# endif

    /***** TX *********************************************************************/
# if ((kTpNumberOfCanChannels > 1) && (kTpNumberOfCanChannels != kCanNumberOfChannels))
    if (TP_TX_INIT_HANDLE(canChannel) != kCanTxHandleNotUsed)
# endif
    {
# if !defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#  if defined TP_ENABLE_SINGLE_MSG_OBJ
      tpTransmitChannel[canChannel]   = kTpNoChannel; /* Free Transmit queue */
#  endif
# endif
      tpCanGetDynTxObjReturn = (TPCANGETDYNTXOBJ(canChannel)) ((CanTransmitHandle)(TP_TX_INIT_HANDLE(canChannel)));
      if (tpCanGetDynTxObjReturn == kCanNoTxDynObjAvailable)
      {
        /* No DynTxObj available in TpInit */
        assertGeneral(kTpNoChannel, kTpErrNoDynObjAtTpInit );
      }
      else
      {
# if defined (TP_ENABLE_VARIABLE_DLC)
# else
#  if defined (TPC_ENABLE_DYN_TX_DLC)
        TPCANDYNTXOBJSETDLC(canChannel) ((CanTransmitHandle)(TP_TX_INIT_HANDLE(canChannel)), FRAME_LENGTH);
#  endif
# endif

# if defined (TPC_ENABLE_DYN_TX_DATAPTR)
        TPCANDYNTXOBJSETDATAPTR(canChannel)((CanTransmitHandle)(TP_TX_INIT_HANDLE(canChannel)),TpCanTxDataPtr_Init());
# endif
# if defined( TPC_ENABLE_DYN_TX_PRETRANS_FCT )
        TPCANDYNTXOBJSETPRETRANSMITFCT(canChannel) ((CanTransmitHandle)(TP_TX_INIT_HANDLE(canChannel)),V_NULL);
# endif
# if defined( TPC_ENABLE_DYN_TX_CONF_FCT )
#  if defined TP_ENABLE_SINGLE_MSG_OBJ
        TPCANDYNTXOBJSETCONFIRMATIONFCT(canChannel)((CanTransmitHandle)(TP_TX_INIT_HANDLE(canChannel)),TpDrvConfirmation);
#  endif
# endif
      }
    }
# if ((kTpNumberOfCanChannels > 1) && (kTpNumberOfCanChannels != kCanNumberOfChannels))
    else
    {
#  if !defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#   if defined TP_ENABLE_SINGLE_MSG_OBJ
      tpTransmitChannel[canChannel]   = kTpNoChannel; /* Free Transmit queue */
#   endif
#  endif
    }
# endif
  }
#endif /* defined (TP_ENABLE_DYNAMIC_CHANNELS) */

#if (TP_USE_TX_HANDLE_CHANGEABLE == kTpOn)
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
  tpTxHandle = 0;
#  if defined( TP_ENABLE_SINGLE_MSG_OBJ )
#  endif
# else
  {
    cansintCPUtype i;
    for (i = (cansintCPUtype)(kTpTxChannelCount-1); i>=0; i--)
    {
      tpTxHandle_Field[i] = kTpTxHandle_Field[i];
    }
#  if defined( TP_ENABLE_SINGLE_MSG_OBJ )
#  endif
  }
# endif
#endif

#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
  /***** RX *********************************************************************/
  for (tpChannel=(cansintCPUtype)(kTpRxChannelCount-1); tpChannel>=0; tpChannel--)
#endif
  {
#if defined(TP_RX_ENABLE_DYN_EXT_ID)
    tpRxHighByte29Bit[tpChannel] = (vuint8)(kTpPhysPrioInitial<<2);
    tpRxPGN29Bit[tpChannel]      = kTpPhysPGNInitial;
#endif
    tpRxState[tpChannel].engine = kRxState_Idle;
#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if (kTpNumberOfCanChannels > 1)
    tpRxInfoStruct[tpChannel].CanChannel = 0;
# endif
#endif

#if defined (TP_ENABLE_SINGLE_MSG_OBJ)
#endif


#if (kTpRxChannelCount != kTpTxChannelCount)
  }
  /***** TX *********************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
# else
  for (tpChannel=(cansintCPUtype)(kTpTxChannelCount-1); tpChannel>=0; tpChannel--)
# endif
  {
#endif
#if defined(TP_TX_ENABLE_DYN_EXT_ID)
    tpTxHighByte29Bit[tpChannel] = (vuint8)(kTpPhysPrioInitial<<2);
    tpTxPGN29Bit[tpChannel]      = kTpPhysPGNInitial;
#endif
    tpTxState[tpChannel].engine = kTxState_Idle;
#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if (kTpNumberOfCanChannels > 1)
    tpTxInfoStruct[tpChannel].CanChannel = 0;
# endif
#endif

#if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
#else
    TpIntTxTransmitChannel_SetFree(tpChannel);
#endif

  }

  /***** TpInit ******************************************************************/
  TpInit();

}

/*******************************************************************************
*
* NAME:              TpInit
*
* CALLED BY:         Application
* PRECONDITIONS:     Reinitialization of the TransportLayer
*
* PARAMETER:         none
* RETURN VALUE:      none
* DESCRIPTION:       Initialization function to initialize all channels
*
*******************************************************************************/
void TP_API_CALL_TYPE TpInit(void)
{
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
  cansintCPUtype  tpChannel;
#endif


# if (TP_SECURITY_LEVEL > 0)
  tpStateTaskBusy = 0;
# endif

  /***** RX *********************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
  for (tpChannel=(cansintCPUtype)(kTpRxChannelCount-1); tpChannel>=0; tpChannel--)
#endif
  {
    __TpRxInit(tpChannel, kTpRxErrTpInitIsCalled);
#if (kTpRxChannelCount != kTpTxChannelCount)
  }

  /***** TX *********************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
# else
  for (tpChannel=(cansintCPUtype)(kTpTxChannelCount-1); tpChannel>=0; tpChannel--)
# endif
  {
#endif /* #if (kTpRxChannelCount != kTpTxChannelCount) */
    __TpTxInit((canuint8)tpChannel, kTpTxErrTpInitIsCalled);
  }

#if defined( TP_FUNC_ENABLE_RECEPTION )
  TpFuncInit();
#endif

}

#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
# if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
/*******************************************************************************
*
* NAME:              TpCanChannelInit
*
* CALLED BY:         Application
* PRECONDITIONS:     Reinitialization per CAN channel of the TransportLayer
*
* PARAMETER:         canChannel
* RETURN VALUE:      none
* DESCRIPTION:       Initialization function to initialize all channels on a given
*                    CAN channel. Channels in idle state are not reinitialized.
*******************************************************************************/
void TP_API_CALL_TYPE TpCanChannelInit(canuint8 canChannel)
{
  cansintCPUtype  tpChannel;


  /***** RX *********************************************************************/
  for (tpChannel=(cansintCPUtype)(kTpRxChannelCount-1); tpChannel>=0; tpChannel--)
  {
    if ((tpRxInfoStruct[tpChannel].CanChannel == canChannel) && (tpRxState[tpChannel].engine != kRxState_Idle))
    {
      __TpRxInit(tpChannel, kTpRxErrTpInitIsCalled);
    }
#if (kTpRxChannelCount != kTpTxChannelCount)
  }
  /***** TX *********************************************************************/
  for (tpChannel=(cansintCPUtype)(kTpTxChannelCount-1); tpChannel>=0; tpChannel--)
  {
#endif /* (kTpRxChannelCount != kTpTxChannelCount) */
    if ((tpTxInfoStruct[tpChannel].CanChannel == canChannel) && (tpTxState[tpChannel].engine != kTxState_Idle))
    {
      __TpTxInit((canuint8)tpChannel, kTpTxErrTpInitIsCalled);
    }
  }
}
#  endif
# endif
#endif

/*******************************************************************************
*
* NAME:              TpTxInit
*
* CALLED BY:         Transport layer functions
* PRECONDITIONS:     none
*
* PARAMETER:         tpChannel number
* RETURN VALUE:      none
* DESCRIPTION:       Initialize the transmit tpChannel specified by parameter
*                    tpChannel
*******************************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
static void TpTxInit(canuint8 errorCode)
#else
static void TpTxInit(canuint8 tpChannel, canuint8 errorCode)
#endif
{
# if defined (__ApplTpTxErrorIndication)
  canuint8 tpErrorIndResult;
# endif
#if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertInternal(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh)
#endif

  TpGlobalInterruptDisable();

#if defined (__ApplTpTxErrorIndication)
  tpErrorIndResult = kTpFreeChannel;
  if ((tpTxState[tpChannel].engine > kTxState_Reserved) && \
     (tpTxState[tpChannel].engine != kTxState_Error)) /* ! (kTxState_Idle || kTxState_Reserved) */
  {
    tpTxState[tpChannel].engine = kTxState_Error;
    tpErrorIndResult = __ApplTpTxErrorIndication(tpChannel, errorCode);

    if(tpErrorIndResult == kTpHoldChannel)
    { /* HoldChannel is called */
#  if ( (defined(TP_ENABLE_DYNAMIC_CHANNELS)) && (!defined(TP_ENABLE_SINGLE_CHANNEL_TP)) )
    	tpTxState[tpChannel].engine                 = kTxState_Idle;
#  else
      tpTxState[tpChannel].engine                 = kTxState_Idle;
#  endif
      /* tpTxState[tpChannel].blocked             = 0; not allowed for HoldChannel */
    }

  }
#endif
  tpTxState[tpChannel].Timer                  = 0;
  /* tpTxState[tpChannel].BSCounter           = 0; not necessary */
#if( (defined( TP_ENABLE_MCAN )) || (defined ( VGEN_ENABLE_TP_MCAN )) )
  tpTxState[tpChannel].WFTCounter             = tpTxWFTmax[tpChannel];
#endif
  tpTxState[tpChannel].queued                 = 0;
  tpTxState[tpChannel].retransmit             = 0;
#if (TP_USE_ONLY_FIRST_FC == kTpOn)
  /* tpTxState[tpChannel].firstFC                = 0; not necessary */
#endif
#if defined (TP_TEST_ROUTINE_CONF_TIMEOUT)
  tpTxState[tpChannel].forceConfTimeout         = 0;
#endif

# if defined (__ApplTpTxErrorIndication)
  if(tpErrorIndResult != kTpHoldChannel)
  /* tpChannel should be reinitialized completely */
# endif
  {
    tpTxState[tpChannel].engine                 = kTxState_Idle;
    tpTxState[tpChannel].blocked                = 0;
    /* tpTxInfoStruct[tpChannel].DataBufferPtr     = 0; not necessary */
    /* tpTxInfoStruct[tpChannel].DataIndex         = 0; not necessary */
    /* tpTxInfoStruct[tpChannel].DataLength        = 0; not necessary */
#if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
    /* tpTxInfoStruct[tpChannel].BaseAddress       = 0; not necessary (will be set in TpTxGetFreeChannel)*/
#endif
#if (defined(TP_ENABLE_EXTENDED_ADDRESSING) )
# if defined  (TP_ENABLE_RUNTIME_CHECK )
    /* Clear validity for TargetAddress */
    tpTxInfoStruct[tpChannel].TargetAddressIsValid = 0;
# endif
    /* tpTxInfoStruct[tpChannel].TargetAddress     = 0; not necessary (will be set later)*/
#endif
#if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
# if defined  (TP_ENABLE_RUNTIME_CHECK )
    /* CLear validity for EcuNumber */
    tpTxInfoStruct[tpChannel].EcuNumberIsValid = 0;
# endif
    /* tpTxInfoStruct[tpChannel].EcuNumber         = 0; not necessary (will be set later )*/
#endif
/* #if defined(TP_ENABLE_MIXED_29_ADDRESSING) || \                */
/*     defined(TP_ENABLE_MIXED_11_ADDRESSING)                     */
/*  tpTxInfoStruct[tpChannel].AddressExtension = 0; not necessary */
/* #endif                                                         */
#if (TP_USE_ONLY_FIRST_FC == kTpOn)
    tpTxInfoStruct[tpChannel].BlockSize         = 0;
#endif
#if defined( TP_ENABLE_DYN_TX_STMIN_TIMING )
    tpTxCFDelay[tpChannel] = TpTxGetSTMINDefaultTime(tpChannel);
#endif
#if (TP_USE_TX_CHANNEL_WITHOUT_FC == kTpOn)
# if (TP_USE_STMIN_OF_FC == kTpOn)
    tpTxInfoStruct[tpChannel].STMin = (canuint8)(TpTxGetSTMINDefaultTime(tpChannel));
# endif
#endif
/* #if (TP_USE_STMIN_OF_FC == kTpOn)                                */
/* # if (TP_USE_FAST_TX_TRANSMISSION == kTpOn)                      */
/*     tpTxInfoStruct[tpChannel].STminInFrame = 0xff; not necessary */
/* # endif                                                          */
/* #endif                                                           */
#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if ((defined(TP_ENABLE_NORMAL_ADDRESSING)) )
#  if (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn)
    tpTxInfoStruct[tpChannel].TransmitID        = 0xffffffff;
    tpTxInfoStruct[tpChannel].ReceiveID         = 0xffffffff;
    tpTxInfoStruct[tpChannel].TransmitIDType    = kTpCanIdTypeStd;
    tpTxInfoStruct[tpChannel].ReceiveIDType     = kTpCanIdTypeStd;
#  elif (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
    tpTxInfoStruct[tpChannel].TransmitID        = 0xffffffff;
    tpTxInfoStruct[tpChannel].ReceiveID         = 0xffffffff;
#  else
    tpTxInfoStruct[tpChannel].TransmitID        = 0xffff;
    tpTxInfoStruct[tpChannel].ReceiveID         = 0xffff;
#  endif
# endif
#endif
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
    tpTxInfoStruct[tpChannel].Connection        = 0xff;
#endif
    tpTxInfoStruct[tpChannel].sequencenumber    = 0;
#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if (kTpNumberOfCanChannels > 1)
    /* tpTxInfoStruct[tpChannel].CanChannel        = 0; not necessary (will be set in TpTxGetFreeChannel) */
# endif
#endif
#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if (TP_USE_TX_CHANNEL_WITHOUT_FC == kTpOn)
    tpTxInfoStruct[tpChannel].withoutFC         = 0;
# endif
#endif
#if defined(TP_ENABLE_FC_MSG_FLOW_DYN_CHECK)
    tpTxInfoStruct[tpChannel].FCwfs             = kTpTrue;
#endif

#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# else
#  if (TP_USE_TX_CHANNEL_WITHOUT_FC == kTpOn)
    tpTxInfoStruct[tpChannel].withoutFC = (canbittype)(!(TpTxFlowControl[tpChannel]));
#  endif
# endif
#endif
  }

#if defined TP_ENABLE_SINGLE_MSG_OBJ
  TpIntTxTransmitChannel_IsTx(tpChannel)
#endif
  {
#if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
    if(tpChannel == TpIntTxTransmitChannel(tpChannel))
    {
# if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && (kTpNumberOfCanChannels > 1) )
      assertInternal(tpChannel, (TP_TX_HANDLE(tpChannel) != kCanTxHandleNotUsed), kTpErrCanChannelNotSupported);
# endif
      TPCANCANCELTRANSMIT(TpIntTxGetCanChannel(tpChannel)) (TP_TX_HANDLE(tpChannel));
      /* Set TransmitObject free */
      TpIntTxTransmitChannel_SetFree(tpChannel);
      TpTxAllStateTask(); /* avoid a break in queue handling */
    }
#else
# if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && (kTpNumberOfCanChannels > 1) )
    assertInternal(tpChannel, (TP_TX_HANDLE(tpChannel) != kCanTxHandleNotUsed), kTpErrCanChannelNotSupported);
# endif
    TPCANCANCELTRANSMIT(TpIntTxGetCanChannel(tpChannel)) (TP_TX_HANDLE(tpChannel));
    /* Set TransmitObject free */
    TpIntTxTransmitChannel_SetFree(tpChannel);
#endif
  }
#if defined( TP_ENABLE_DYN_CHANNEL_TIMING )
  tpTxConfirmationTimeout[tpChannel] = kTpTxConfirmationTimeout;
  tpTxTimeoutFC[tpChannel]           = TpTxTimeoutFC;
#endif
  TpGlobalInterruptRestore();

}

/*******************************************************************************
*
* NAME:              TpRxInit
*
* CALLED BY:         Transport layer functions
* PRECONDITIONS:     none
*
* PARAMETER:         Channel number
* RETURN VALUE:      none
* DESCRIPTION:       Initialize the receive Channel specified by parameter
*                    Channel
*                    Mixed11/29Addressing: tpRxInfoStruct[tpChannel].AddressExtension is not
*                    necessary to be set here.
*
*******************************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
static void TpRxInit(canuint8 errorCode)
#else
static void TpRxInit(canuint8 tpChannel, canuint8 errorCode)
#endif
{

#if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertInternal(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh)
#endif

  TpGlobalInterruptDisable();


  if ((tpRxState[tpChannel].engine > kRxState_ApplInformed) && \
      (tpRxState[tpChannel].engine != kRxState_Error)) /* ! (kRxState_Idle || kRxState_ApplInformed) */
  {
    tpRxState[tpChannel].engine   = kRxState_Error;
    __ApplTpRxErrorIndication(tpChannel, errorCode);
  }
  tpRxState[tpChannel].Timer                    = 0;
  /* tpRxState[tpChannel].BSCounter;            = 0;          not necessary */
  /* tpRxState[tpChannel].WFTCounter            = kTpWFTmax;  not necessary */
  tpRxState[tpChannel].engine                   = kRxState_Idle;
  tpRxState[tpChannel].queued                   = 0;
  tpRxState[tpChannel].retransmit               = 0;
#if (TP_USE_OVERRUN_INDICATION == kTpOn)
  tpRxState[tpChannel].noCopyData               = 0;
#endif
#if defined (TP_TEST_ROUTINE_CONF_TIMEOUT)
  tpRxState[tpChannel].forceConfTimeout         = 0;
#endif

  /* tpRxInfoStruct[tpChannel].DataBufferPtr      = 0; not necessary */
  /* tpRxInfoStruct[tpChannel].DataIndex;         = 0; not necessary */
  /* tpRxInfoStruct[tpChannel].DataLength;        = 0; not necessary */
#if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
  /* tpRxInfoStruct[tpChannel].BaseAddress = 0; = 0; not necessary */
#endif
#if (defined(TP_ENABLE_EXTENDED_ADDRESSING) )
# if (TP_USE_GATEWAY_API == kTpOn)
  tpRxInfoStruct[tpChannel].TargetAddress = 0xff;
# endif
  tpRxInfoStruct[tpChannel].SourceAddress = 0xff;
# if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
  tpRxInfoStruct[tpChannel].EcuNumber     = 0xff;
# endif
#endif
#if (TP_USE_EXTENDED_API_BS == kTpOn)
  TpRxSetBlockSize(tpChannel, TpRxGetBlockSizeDefault(tpChannel));
  /* Set BlockSize to default */
#endif
#if (TP_USE_EXTENDED_API_STMIN == kTpOn)
  tpRxInfoStruct[tpChannel].STMin = TpRxGetSTMINtimeDefault(tpChannel);
  /* Set STMin time to default */
#endif
#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if ((defined(TP_ENABLE_NORMAL_ADDRESSING)) )
#  if (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn)
  tpRxInfoStruct[tpChannel].TransmitID     = 0xffffffff;
  tpRxInfoStruct[tpChannel].ReceiveID      = 0xffffffff;
  tpRxInfoStruct[tpChannel].ReceiveIDType  = kTpCanIdTypeStd;
#  elif (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
  tpRxInfoStruct[tpChannel].TransmitID     = 0xffffffff;
  tpRxInfoStruct[tpChannel].ReceiveID      = 0xffffffff;
#  else
  tpRxInfoStruct[tpChannel].TransmitID     = 0xffff;
  tpRxInfoStruct[tpChannel].ReceiveID      = 0xffff;
#  endif
# endif
#endif

#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
  tpRxInfoStruct[tpChannel].Connection = 0xff;
#endif
  tpRxInfoStruct[tpChannel].sequencenumber = 0;
#if defined (TP_ENABLE_DYN_AWAIT_CORRECT_SN)
  tpRxInfoStruct[tpChannel].SNwait = kTpFalse;
#endif

#if (kTpNumberOfCanChannels > 1)
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
  /* tpRxInfoStruct[tpChannel].CanChannel = 0; not necessary (will be set in TpPrecopy) */
# endif
#endif

#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
# if defined( TP_ENABLE_MF_RECEPTION )
#  if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
#   if defined (TP_ENABLE_DYNAMIC_CHANNELS)
  tpRxInfoStruct[tpChannel].withoutFC = 0;
#   else
  tpRxInfoStruct[tpChannel].withoutFC = (canbittype)(!(TpRxFlowControl[tpChannel]));
#   endif
#  endif
# endif
#endif


#if (defined(TP_ENABLE_FC_WAIT) || defined(TP_ENABLE_FC_SUPPRESS) || defined(TP_ENABLE_FC_OVERFLOW))
  tpRxInfoStruct[tpChannel].ApplGetBufferStatus = kTpFCClearToSend;
#endif


#if defined( TP_ENABLE_MF_RECEPTION )
# if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
  if (tpRxInfoStruct[tpChannel].withoutFC == 0)
# endif
  {
# if defined TP_ENABLE_SINGLE_MSG_OBJ
    TpIntRxTransmitChannel_IsRx(tpChannel)
# endif
    {

# if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
#  if defined TP_ENABLE_SINGLE_MSG_OBJ
      canuint8 tpChannelMasked;
      tpChannelMasked = (canuint8)(tpChannel | kTpRxChannel);
      if(tpChannelMasked == TpIntRxTransmitChannel(tpChannel)) /* must be evaluated as rxChannel -> | 0x80 */
#  endif
      {
#  if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && (kTpNumberOfCanChannels > 1) )
        assertInternal(tpChannel, (TP_RX_HANDLE(tpChannel) != kCanTxHandleNotUsed), kTpErrCanChannelNotSupported);
#  endif
        TPCANCANCELTRANSMIT(TpIntRxGetCanChannel(tpChannel)) (TP_RX_HANDLE(tpChannel));
        /* Set TransmitObject free */
        TpIntRxTransmitChannel_SetFree(tpChannel);
        TpRxAllStateTask(); /* avoid a break in queue handling */
      }

# else

# if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
      /* Count of items in array */
#  if defined TP_ENABLE_SINGLE_MSG_OBJ
      assertInternal(tpChannel, (tpChannel < sizeof(kTpTxHandle_Field) / sizeof(kTpTxHandle_Field[0])), kTpErrChannelNrTooHigh);
#   endif
#  endif

#  if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && (kTpNumberOfCanChannels > 1) )
      assertInternal(tpChannel, (TP_RX_HANDLE(tpChannel) != kCanTxHandleNotUsed), kTpErrCanChannelNotSupported);
#  endif
      TPCANCANCELTRANSMIT(TpIntRxGetCanChannel(tpChannel)) (TP_RX_HANDLE(tpChannel));
      /* Set TransmitObject free */
      TpIntRxTransmitChannel_SetFree(tpChannel);
# endif
    }
  }
#endif

#if defined( TP_ENABLE_DYN_CHANNEL_TIMING )
  tpRxConfirmationTimeout[tpChannel] = kTpRxConfirmationTimeout;
  tpRxTimeoutCF[tpChannel]           = TpRxTimeoutCF;
#endif
  TpGlobalInterruptRestore();

}

/*******************************************************************************
*
* NAME:              TpPrecopy
*
* CALLED BY:         CAN driver
* PRECONDITIONS:     none
*
* PARAMETER:         CanRxInfoStructPtr:Pointer to CAN receive structure
*                    CanChipDataPtr:Pointer to data area of CAN receive object
*                    CanReceiveHandle:CAN-driver handle of received message
*                    addressingFormat:the used addressingformat for this frame
* RETURN VALUE:      Status value
* DESCRIPTION:       Receive function for CAN driver, used for tp-messages
*                    only
*******************************************************************************/
#   if ( defined (C_MULTIPLE_RECEIVE_CHANNEL) ||\
         defined (C_SINGLE_RECEIVE_CHANNEL) ||\
         defined (TP_CAN_CODEDOUBLED) )
canuint8 TP_INTERNAL_CALL_TYPE TpPrecopy(CanRxInfoStructPtr rxStruct)
#   else
#    if defined ( C_MULTIPLE_RECEIVE_BUFFER )
canuint8 TP_INTERNAL_CALL_TYPE TpPrecopy(CanChipDataPtr rxDataPtr)
#    endif
#    if defined ( C_SINGLE_RECEIVE_BUFFER )
canuint8 TP_INTERNAL_CALL_TYPE TpPrecopy(CanReceiveHandle rxObject)
#    endif
#   endif
{
#if (TP_USE_CUSTOM_RX_MEMCPY == kTpOff)
  cansintCPUtype counter;
#endif
#if (TP_USE_APPL_PRECOPY == kTpOn) && (TP_USE_FAST_PRECOPY == kTpOff) && defined (TP_DISABLE_CHECKTA_COMPATIBILITY)
  t_ta_type tpApplTpPrecopyReturn;
#endif
#if defined TP_ENABLE_DYNAMIC_CHANNELS
# if !defined(TP_ENABLE_SINGLE_CHANNEL_TP)
#  if (TP_USE_ISO_COMPLIANCE == kTpOn)
  canuintCPUtype rightChannel;
  canuint8 freeChannel;
#  endif
# endif
#endif
#if (TP_USE_STMIN_OF_FC == kTpOn)
  canuintCPUtype tpSTminInFrame;
#endif
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
  cansintCPUtype  tpChannel;
#endif

#if (defined(TP_ENABLE_EXTENDED_ADDRESSING))
  canuint16 tpCanRxActualId;    /* check in assert for CanRxActualIdType */
#elif (defined(TP_ENABLE_DYNAMIC_CHANNELS))
# if (defined(TP_ENABLE_NORMAL_ADDRESSING) )
#  if (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn)
  canuint32 tpCanRxActualId;
  canuint8  tpCanRxActualIdType;
#  elif (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
  canuint32 tpCanRxActualId;
#  else
  canuint16 tpCanRxActualId;
#  endif
# endif
#endif

#if ( (TP_USE_FIX_RX_DLC_CHECK == kTpOn) ||\
      (TP_USE_VARIABLE_RX_DLC_CHECK == kTpOn) )
  canuint8 tpCanRxActualDLC;
  canuint8 tpCanRxFrameLength;
#endif
#if defined(TP_ENABLE_EXTENDED_ADDRESSING)
# if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
  cansint16 tpCurrentSourceAddress;
# else
  canuint8  tpCurrentSourceAddress;
# endif
# if (TP_USE_FAST_PRECOPY == kTpOff)
  canuint8  tpCurrentTargetAddress;
# endif
#endif
#if (TP_USE_APPL_PRECOPY == kTpOn) && defined (TP_ENABLE_CHECKTA_COMPATIBILITY)
# if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
  canuint8 tpEcuNr;
# endif
#endif
#if defined(TP_ENABLE_EXTENDED_ADDRESSING)
# if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
  canuint16 tpCurrentBaseAddress;
# endif
#endif
#if (TP_USE_PRE_COPY_CHECK == kTpOn)
  canuint8 tpPreCopyCheckFunctionReturn;
#endif

#if defined ( TP_ENABLE_SINGLE_CHANNEL_TP )
# if defined ( TP_ENABLE_SINGLE_CHAN_MULTICONN )
#  if defined( TP_ENABLE_NORMAL_ADDRESSING )
  CanTransmitHandle handle;
#  endif
# endif
#endif

#if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
#endif

#if defined (TP_ENABLE_SINGLE_MSG_OBJ)
#endif

#if (TP_USE_CUSTOM_RX_MEMCPY == kTpOn)
# if defined (TP_ENABLE_INTERMEDIATE_CANCHIP_BUFFER)
  vuint8 pIntermediateCANChipData[8];
# endif
#endif

#if defined(TP_ENABLE_EXTENDED_ADDRESSING)
  tpCurrentSourceAddress = 0xFF;
# if (TP_USE_FAST_PRECOPY == kTpOff)
  tpCurrentTargetAddress = 0xFF;
# endif
#endif

  /**********************************************************************************/
  /* Multiple Nodes *****************************************************************/
  /**********************************************************************************/
#if defined TP_ENABLE_MULTIPLE_NODES

# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#  if defined(TP_ENABLE_NORMAL_ADDRESSING)
  if (kTpRx_RxHandle_Field[comMultipleECUCurrent] != RX_HANDLE)
  {
    return kCanNoCopyData;
  }
#  endif
# else
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#  else
  /* static Multi TP */
#   if defined( kVNumberOfIdentities )
#    if ( kVNumberOfIdentities > 1 )
  if (TpRxHandleToIdentity[RX_HANDLE] != comMultipleECUCurrent )
  {
    return kCanNoCopyData;
  }
#    endif
#   endif
  if (TpRxHandleToChannel[RX_HANDLE] != comMultipleECUCurrent )
  {
    return kCanNoCopyData;
  }
#  endif
# endif

#else
  /**********************************************************************************/
  /* Single channel multiple connection *********************************************/
  /**********************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#  if defined (TP_ENABLE_SINGLE_CHAN_MULTICONN )
#   if defined(TP_ENABLE_NORMAL_ADDRESSING)
  for (handle = 0; handle < kTpRxTxHandleFieldSize; handle++)
  {
    if ((kTpRxHandle_Field[handle] == RX_HANDLE))
    { /* this handle is used for transmission */
      /* connHandle = handle; this is done after GetBuffer callback */
      break;
    }
  }
  if (handle >= kTpRxTxHandleFieldSize)
  {
    return kCanNoCopyData;
  }
#   endif
#  endif
# endif

#endif
  /**********************************************************************************/
  /* PrecopyCheckFunction ***********************************************************/
  /**********************************************************************************/
#if (TP_USE_PRE_COPY_CHECK == kTpOn)
  /* ! Be aware if using a codedoubled system ! */
  /* PreCopyCheck function has API of index candrivers */
# if ( defined( C_MULTIPLE_RECEIVE_CHANNEL) ||\
   defined( C_SINGLE_RECEIVE_CHANNEL) ||\
   defined (TP_CAN_CODEDOUBLED) )
  tpPreCopyCheckFunctionReturn = __ApplTpPreCopyCheckFunction(rxStruct);
  if(tpPreCopyCheckFunctionReturn == 0) {return kCanNoCopyData;}
# else
#  if defined ( C_MULTIPLE_RECEIVE_BUFFER )
  tpPreCopyCheckFunctionReturn = __ApplTpPreCopyCheckFunction(rxDataPtr);
  if(tpPreCopyCheckFunctionReturn == 0) {return kCanNoCopyData;}
#  endif
#  if defined ( C_SINGLE_RECEIVE_BUFFER )
  tpPreCopyCheckFunctionReturn = __ApplTpPreCopyCheckFunction(rxObject);
  if(tpPreCopyCheckFunctionReturn == 0) {return kCanNoCopyData;}
#  endif
# endif
#endif

  /**********************************************************************************/
  /**** Normal Fixed Addressing *****************************************************/
  /**** Mixed 29bit Addressing ******************************************************/
  /**********************************************************************************/
  /**********************************************************************************/
  /**** Normal Addressing ***********************************************************/
  /**** Extended Addressing *********************************************************/
  /**********************************************************************************/
#if defined( TP_ENABLE_EXTENDED_ADDRESSING ) || \
           ( defined( TP_ENABLE_DYNAMIC_CHANNELS) &&  \
             ( defined( TP_ENABLE_NORMAL_ADDRESSING) )  \
           )
# if (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn)
  tpCanRxActualId     = (canuint32) CAN_RX_ACTUAL_ID;
  tpCanRxActualIdType = (canuint8)  (CAN_RX_ACTUAL_ID_TYPE == 0) ? kTpCanIdTypeStd : kTpCanIdTypeExt;
# elif (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
  tpCanRxActualId     = (canuint32) CAN_RX_ACTUAL_ID;
# else
  tpCanRxActualId     = (canuint16) CAN_RX_ACTUAL_ID;
# endif
#endif
  /************************************************************************************/
  /**** Extended Addressing ***********************************************************/
  /************************************************************************************/
#if defined(TP_ENABLE_EXTENDED_ADDRESSING)
  {
# if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
    tpCurrentBaseAddress = 0xffff;
    /* tpChannel is only used as counter for kTpNumberOfBaseAddresses */
    for (tpChannel=(cansintCPUtype)(kTpNumberOfBaseAddresses-1); tpChannel>=0; tpChannel--)
    {
      tpCurrentSourceAddress = VSINT16_CAST(tpCanRxActualId - kTpRxBaseAddress[tpChannel]);
      if ( (TP_RX_BASE_ADDRESS_OFFSET(tpChannel) <= tpCurrentSourceAddress) &&
      ((tpCurrentSourceAddress - TP_RX_BASE_ADDRESS_OFFSET(tpChannel) ) <= kTpRxMessageCount[tpChannel]) )
      {
        tpCurrentBaseAddress = kTpRxBaseAddress[tpChannel];
        break;
      }
    }
    if (tpChannel<0)
    {
      return kCanNoCopyData;
    }
# else
    tpCurrentSourceAddress = (canuint8)(tpCanRxActualId - TP_RX_BASE_ADDRESS);
# endif
    tpCurrentTargetAddress = *(CanChipDataPtr)(FRAME_DATA_PTR + TARGET_OFFSET);
    /* kTpExtendedAddressing -> TP_USE_FAST_PRECOPY == kTpOff */
  }
#endif
  /************************************************************************************/
  /**** Mixed Addressing        *******************************************************/
  /************************************************************************************/
  /**********************************************************************************/
  /* ApplTpPrecopy ******************************************************************/
  /**** Normal Fixed Addressing *****************************************************/
  /**** Extended Addressing     *****************************************************/
  /**** Mixed Addressing        *****************************************************/
  /**********************************************************************************/
#if (TP_USE_APPL_PRECOPY == kTpOn)
# if (TP_USE_FAST_PRECOPY == kTpOff) && defined (TP_ENABLE_CHECKTA_COMPATIBILITY)
/*lint -save -e644*/
#  if defined(TP_ENABLE_EXTENDED_ADDRESSING)
  {
#    if (TP_USE_MULTIPLE_ECU_NR == kTpOn) /* */
#     if (TP_USE_GATEWAY_API == kTpOn)
    tpEcuNr = __ApplTpPrecopy(tpCurrentTargetAddress, rxStruct);
    if (tpEcuNr == 0xff)
#     else
    tpEcuNr = __ApplTpPrecopy(tpCurrentTargetAddress);
    if (tpEcuNr == 0xff)
#     endif
#    else
     /* (TP_USE_MULTIPLE_ECU_NR == kTpOff) */
    canuint8 tpApplTpPrecopyReturn;
#     if (TP_USE_GATEWAY_API == kTpOn)
       /* (TP_DISABLE_MIXED_29_ADDRESSING) */
    tpApplTpPrecopyReturn = __ApplTpPrecopy(tpCurrentTargetAddress, rxStruct);
    if (tpApplTpPrecopyReturn == 0xff)

#     else
      /* (TP_USE_GATEWAY_API == kTpOff) */
       /* (TP_DISABLE_MIXED_29_ADDRESSING) */
    tpApplTpPrecopyReturn = __ApplTpPrecopy(tpCurrentTargetAddress);
    if (tpApplTpPrecopyReturn == 0xff)
#     endif
#    endif
    {
      return kCanNoCopyData;
    }
  }
#  endif
   /* defined(TP_ENABLE_NORMAL_FIXED_ADDRESSING) || defined(TP_ENABLE_EXTENDED_ADDRESSING) || defined(TP_ENABLE_MIXED_29_ADDRESSING) */

# else /* # (TP_USE_FAST_PRECOPY == kTpOff) && (TP_ENABLE_CHECKTA_COMPATIBILITY) */
  {
#  if defined(TP_ENABLE_EXTENDED_ADDRESSING)

    tpApplTpPrecopyReturn = kTpPhysical;    /* init value used in case of normal addressing  */
    /* (TP_ENABLE_NORMAL_FIXED_ADDRESSING) || (TP_ENABLE_EXTENDED_ADDRESSING) */
    {
#    if (TP_USE_GATEWAY_API == kTpOn)
      tpApplTpPrecopyReturn = __ApplTpPrecopy(tpCurrentTargetAddress, rxStruct);
#    else
      tpApplTpPrecopyReturn = __ApplTpPrecopy(tpCurrentTargetAddress);
#    endif
    }

    if (tpApplTpPrecopyReturn == kTpNone)  /* init value used in case of normal addressing */
    {
      return kCanNoCopyData;
    }

#  endif
   /* (TP_ENABLE_NORMAL_FIXED_ADDRESSING) || (TP_ENABLE_EXTENDED_ADDRESSING) || (TP_ENABLE_MIXED_29_ADDRESSING) */
  }
/*lint -restore */
# endif
#endif

  /**********************************************************************************/
  /**** Normal Fixed Addressing *****************************************************/
  /**** Mixed Addressing ************************************************************/
  /**********************************************************************************/

  /**********************************************************************************/
  /* store CAN-DLC on Stack                                                         */
  /**********************************************************************************/
#if ( (TP_USE_FIX_RX_DLC_CHECK == kTpOn) || (TP_USE_VARIABLE_RX_DLC_CHECK == kTpOn) )
  tpCanRxActualDLC = (canuint8)CAN_RX_ACTUAL_DLC;
#if FBLM_CANFD_SUPPORT
  if(CAN_DLC_VALUE_0x9 == tpCanRxActualDLC)
  {
    tpCanRxFrameLength = CAN_R_DLC_VALUE_12;
  }
  else if(CAN_DLC_VALUE_0xA == tpCanRxActualDLC)
  {
    tpCanRxFrameLength = CAN_R_DLC_VALUE_16;
  }
  else if(CAN_DLC_VALUE_0xB == tpCanRxActualDLC)
  {
    tpCanRxFrameLength = CAN_R_DLC_VALUE_20;
  }
  else if(CAN_DLC_VALUE_0xC == tpCanRxActualDLC)
  {
	 tpCanRxFrameLength = CAN_R_DLC_VALUE_24;
  }
  else if(CAN_DLC_VALUE_0xD == tpCanRxActualDLC)
  {
	 tpCanRxFrameLength = CAN_R_DLC_VALUE_32;
  }
  else if(CAN_DLC_VALUE_0xE == tpCanRxActualDLC)
  {
	 tpCanRxFrameLength = CAN_R_DLC_VALUE_48;
  }
  else if(CAN_DLC_VALUE_0xF == tpCanRxActualDLC)
  {
	 tpCanRxFrameLength = CAN_R_DLC_VALUE_64;
  }
  else
  {
    tpCanRxFrameLength = 0x08u;
  }
#endif

#endif
#if (TP_USE_FIX_RX_DLC_CHECK == kTpOn)
  if (tpCanRxActualDLC != FRAME_LENGTH)
  {
    return kCanNoCopyData;
  }
#endif

  /**********************************************************************************/
  /**** Static Normal Addressing ****************************************************/
  /**********************************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# else
  /* static Multi TP */
  tpChannel = TpRxHandleToChannel[RX_HANDLE];
# endif
#endif

  switch (*(CanChipDataPtr)(TPCI_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR) & 0xF0)
  {
#if defined( TP_ENABLE_MF_RECEPTION )
  /*-----------------------------------------------------------------------------
  | kL4_FirstFrame || kL4_SingleFrame
    -----------------------------------------------------------------------------*/
  case kL4_FirstFrame:
# if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
  case kL4_FirstFrameWithoutFC:
    /* no break - because kL4_FirstFrame || kL4_FirstFrameWithoutFC are the same */
# endif
    /* no break - because kL4_FirstFrame || kL4_SingleFrame are the same */
#endif
  case kL4_SingleFrame:
    {
      /**** Search for a free tpChannel *****************************************/
#if defined TP_ENABLE_DYNAMIC_CHANNELS && \
      (! defined(TP_ENABLE_SINGLE_CHANNEL_TP))
# if  (TP_USE_ISO_COMPLIANCE == kTpOn)
      /**** Search for a currently running tpChannel ****************************/
      rightChannel = kTpNoChannel; /* Used to identify a reception on a already running channel */
      freeChannel = kTpNoChannel;  /* Used to identify a reception on a free channel            */
#  if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
      /* Disable interrupts for reentrance of TpPrecopy() */
      TpGlobalInterruptDisable();
#  endif
      for (tpChannel=(cansintCPUtype)(kTpRxChannelCount-1); tpChannel>=0; tpChannel--)
      {
        if (tpRxState[tpChannel].engine != kRxState_Idle)
        {
#  if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
          if (tpRxInfoStruct[tpChannel].CanChannel == (canbittype)(rxStruct->Channel))
#  endif
          {
            /**** EXTENDED_ADDRESSING  ******************************************/
#   if defined(TP_ENABLE_EXTENDED_ADDRESSING)
            { /*lint -e(644) tpCurrentSourceAddress is initialized */
              if( (tpRxInfoStruct[tpChannel].SourceAddress == (canuint8)tpCurrentSourceAddress)
#   if (TP_USE_FAST_PRECOPY == kTpOff)
                && (TP_RX_ECU_NR(tpChannel) == tpCurrentTargetAddress) /* Compare addresses */
#   endif
#   if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
                && (tpRxInfoStruct[tpChannel].BaseAddress == tpCurrentBaseAddress)
#   endif
                )
              {
                if (tpRxState[tpChannel].engine != kRxState_ApplInformed)
                {
                  rightChannel = (canuintCPUtype)tpChannel;
                }
                else
                { /* channel found but blocked - reject reception */
                  freeChannel = kTpNoChannel; /* reset freeChannel to prevent reception on free channel */
                }
                break; /* break channel search */
              }
            }
#  endif
            /**** NORMAL FIXED ADDRESSING ***************************************/
            /**** MIXED 29bit ADDRESSING *********************************************/
            /**** DYNAMIC NORMAL ADDRESSING *************************************/
#  if defined(TP_ENABLE_NORMAL_ADDRESSING)
            {
#   if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
              if( (tpRxInfoStruct[tpChannel].ReceiveID == tpCanRxActualId) && (tpRxInfoStruct[tpChannel].ReceiveIDType == tpCanRxActualIdType) )
#   else
              if(tpRxInfoStruct[tpChannel].ReceiveID == tpCanRxActualId)
#   endif
              {
                if (tpRxState[tpChannel].engine != kRxState_ApplInformed)
                {
                  rightChannel = (canuintCPUtype)tpChannel;
                }
                else
                { /* channel found but blocked - reject reception */
                  freeChannel = kTpNoChannel; /* reset freeChannel to prevent reception on free channel */
                }
                break; /* break channel search */
              }
            }
#  endif
            /**** DYNAMIC MIXED 11bit ADDRESSING *************************************/
          }
        }
        else
        { /* If tpChannel is free - receive */
          freeChannel = (canuint8)tpChannel;
        }
      }
      if (rightChannel != kTpNoChannel)
      { /* Stop running reception to set up with new SF/FF */
        __TpRxInit(rightChannel, kTpRxErrFF_SFreceivedAgain);
        freeChannel = (canuint8)rightChannel;
      }
      if (freeChannel != kTpNoChannel)
      {
        tpChannel = (cansintCPUtype)freeChannel;
      }
      else
      {
#  if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
        TpGlobalInterruptRestore();
#  endif
        return kCanNoCopyData;
        /* no free channel available */
      }
# else /* (TP_USE_ISO_COMPLIANCE == kTpOn) */
#  if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
      /* Disable interrupts for reentrance of TpPrecopy() */
      TpGlobalInterruptDisable();
#  endif
      for (tpChannel=(cansintCPUtype)(kTpRxChannelCount-1); tpChannel>=0; tpChannel--)
      {
        if (tpRxState[tpChannel].engine == kRxState_Idle)
        {
          break;
        }
      }
      if (tpChannel < 0)
      {
# if ( kTpNumberOfCanChannels > 1 )    /* more than one canChannel ? */
        TpGlobalInterruptRestore();
# endif
        return kCanNoCopyData;         /* no free channel available */
      }
# endif /* (TP_USE_ISO_COMPLIANCE == kTpOn) */

#else   /* (TP_ENABLE_DYNAMIC_CHANNELS && !TP_ENABLE_SINGLE_CHANNEL_TP) */

# if ( kTpNumberOfCanChannels > 1 )    /* more than one canChannel ? */
      TpGlobalInterruptDisable();      /* Disable interrupts for reentrance of TpPrecopy() */
# endif

      /* If tpChannel is free - receive */
      if (tpRxState[tpChannel].engine != kRxState_Idle)
      {
# if (TP_USE_ISO_COMPLIANCE == kTpOn)
#  if (TP_USE_APPL_PRECOPY == kTpOn) && (TP_USE_FAST_PRECOPY == kTpOff)
#   if defined( TP_DISABLE_CHECKTA_COMPATIBILITY )
        /* do not accept a functional SF(FF) during a running physical reception */
        if((tpRxState[tpChannel].engine == kRxState_ApplInformed) || (tpApplTpPrecopyReturn != kTpPhysical))
#   else
#    error "Not supported: Unable to check whether physical or functional request with old style ApplTpPrecopy."
#   endif
#  else
        if (tpRxState[tpChannel].engine == kRxState_ApplInformed)
#  endif
# endif
        {
# if ( kTpNumberOfCanChannels > 1 )
          TpGlobalInterruptRestore();
# endif
          return kCanNoCopyData;
        }
# if (TP_USE_ISO_COMPLIANCE == kTpOn)
        else
        {
          __TpRxInit(tpChannel, kTpRxErrFF_SFreceivedAgain);
        }
# endif
      }
#endif /* (TP_ENABLE_DYNAMIC_CHANNELS && !TP_ENABLE_SINGLE_CHANNEL_TP) */

      /************************************************************************/
      /**** Receive ***********************************************************/
      /************************************************************************/
      tpRxState[tpChannel].engine = kRxState_CanFrameReceived;

#if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
      TpGlobalInterruptRestore();
#endif

      /**** Update actual Rx Configuration ************************************/

#if ( kTpNumberOfCanChannels > 1 ) /* more than one CanChannel ? */
      tpRxInfoStruct[tpChannel].CanChannel = (canuint8)((CAN_RX_ACTUAL_CAN) & kTpMaxCanChannels);
#endif
#if defined( TP_ENABLE_MF_RECEPTION )
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#  if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
      tpRxInfoStruct[tpChannel].withoutFC = 0;
#  endif
# endif
#endif

#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if defined(TP_ENABLE_EXTENDED_ADDRESSING)
#  if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
      {
        tpRxInfoStruct[tpChannel].BaseAddress = tpCurrentBaseAddress;
      }
#  endif
# endif
#endif

#if defined(TP_ENABLE_EXTENDED_ADDRESSING)
      {
# if (TP_USE_GATEWAY_API == kTpOn) && (TP_USE_FAST_PRECOPY == kTpOff)
        tpRxInfoStruct[tpChannel].TargetAddress = tpCurrentTargetAddress;
# endif
# if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
#  if (TP_USE_APPL_PRECOPY == kTpOn) && defined (TP_ENABLE_CHECKTA_COMPATIBILITY)
        tpRxInfoStruct[tpChannel].EcuNumber = tpEcuNr;
#  else
        tpRxInfoStruct[tpChannel].EcuNumber = tpCurrentTargetAddress; /* TP_USE_MULTIPLE_ECU_NR == kTpOn -> TP_USE_FAST_PRECOPY == kTpOff */
#  endif
# endif
        tpRxInfoStruct[tpChannel].SourceAddress = tpCurrentSourceAddress;
      }
#endif

#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if defined(TP_ENABLE_NORMAL_ADDRESSING )
      {
        tpRxInfoStruct[tpChannel].ReceiveID     = tpCanRxActualId;
#  if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
        tpRxInfoStruct[tpChannel].ReceiveIDType = tpCanRxActualIdType;
#  endif
      }
# endif
#endif


#if (TP_USE_OVERRUN_INDICATION == kTpOn)
      tpRxState[tpChannel].noCopyData = 0;
#endif

      /* set DataIndex to zero */
      tpRxInfoStruct[tpChannel].DataIndex = 0;

#if defined( TP_ENABLE_MF_RECEPTION )
      switch(*(CanChipDataPtr)(TPCI_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR) & 0xF0)
      {
      /*-----------------------------------------------------------------------------
      | Receive FirstFrame
        -----------------------------------------------------------------------------*/
# if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
      case kL4_FirstFrameWithoutFC:
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
        tpRxInfoStruct[tpChannel].withoutFC = 1;
#  endif
        /* no break - because kL4_FirstFrame || kL4_FirstFrameWithoutFC are the same */
# endif
      case kL4_FirstFrame:
# if (TP_USE_APPL_PRECOPY == kTpOn) && (TP_USE_FAST_PRECOPY == kTpOff) && defined (TP_DISABLE_CHECKTA_COMPATIBILITY)
#  if defined(TP_ENABLE_EXTENDED_ADDRESSING)
      {
        switch (tpApplTpPrecopyReturn)
        {
        case kTpNone:
        case kTpFunctional:
          tpRxState[tpChannel].engine = kRxState_Idle;
          return kCanNoCopyData;
          /*break;*/
        case kTpPhysical:
          tpRxInfoStruct[tpChannel].ta_type = 0;
          break;
        default:
          /* Call everytime assertion */
          assertGeneral(tpChannel, kTpErrPrecopyCheckInvalidReturn);
          break;
        }
      }
#  endif
# endif
# if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && ((kTpNumberOfCanChannels > 1) && (kTpNumberOfCanChannels != kCanNumberOfChannels)) )
        if (TP_RX_HANDLE(tpChannel) != kCanTxHandleNotUsed)
        /* we can not receive a multiple frame on this CAN channel, because TP is not activated on it */
# endif
        {
# if (TP_USE_VARIABLE_RX_DLC_CHECK == kTpOn)
#if FBLM_CANFD_SUPPORT

          tpRxInfoStruct[tpChannel].DataLength  = (canuint16)(((canuint16)(*(CanChipDataPtr)(TPCI_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR) & 0x0F))<<8);
      	  tpRxInfoStruct[tpChannel].DataLength |= (canuint16)(*(CanChipDataPtr)(DL_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR));
 
          if ((tpCanRxActualDLC <= FRAME_CANFD_LENGTH) && (tpCanRxActualDLC >= CAN_DLC_VALUE_0x8))
        	  if ((tpRxInfoStruct[tpChannel].DataLength > (tpCanRxFrameLength - FF_OFFSET ))|| (0 == tpRxInfoStruct[tpChannel].DataLength))
#else /*CAN USED*/
          /* Checking CAN-DLC */
          if (tpCanRxActualDLC == FRAME_LENGTH)
#endif
# endif
          {
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#  if defined(TP_ENABLE_NORMAL_ADDRESSING)
#   if defined  (TP_ENABLE_USER_CHECK )
#    if( TP_USE_EXT_IDS_FOR_NORMAL == kTpOn )
            tpRxInfoStruct[tpChannel].TransmitID     = 0xffffffff;
#    else
            tpRxInfoStruct[tpChannel].TransmitID     = 0xffff;
#    endif
#   endif
#  endif
# endif
            /* Store length for app usage */
            tpRxInfoStruct[tpChannel].DataLength  = (canuint16)(((canuint16)(*(CanChipDataPtr)(TPCI_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR) & 0x0F))<<8);
            tpRxInfoStruct[tpChannel].DataLength |= (canuint16)(*(CanChipDataPtr)(DL_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR));

            /* Check dataLength: the minimum length of a First Frame: seven (extended/mixed) or eight (normal(fixed)) */
            if ((tpRxInfoStruct[tpChannel].DataLength > ((canuint16)(FRAME_LENGTH - (SF_OFFSET + FORMAT_OFFSET)))) || (0 == tpRxInfoStruct[tpChannel].DataLength))

              /* for TP_ENABLE_ISO_15765_2_2: DataLength is != 0 is implicit tested positive */
            { /* Is requested dataLength remained under the minimum length of a FirstFrame ? */
# if (defined(TP_ENABLE_FC_WAIT) || defined(TP_ENABLE_FC_SUPPRESS) || defined(TP_ENABLE_FC_OVERFLOW))
              /* Preselect ApplGetBufferStatus to the default */
            	if(0 == tpRxInfoStruct[tpChannel].DataLength) /*DataLength  > 4095 */
            	{
            		canuint32 TempDataLength = 0;
            		TempDataLength = (canuint32)(((canuint16)(*(CanChipDataPtr)(DL_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + FF_DL_OFFSET) & 0xFF)) << 24);
            		TempDataLength |= (canuint32)(((canuint16)(*(CanChipDataPtr)(DL_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + FF_DL_OFFSET + FF_DL_OFFSET) & 0xFF)) << 16);
            		TempDataLength |= (canuint32)(((canuint16)(*(CanChipDataPtr)(DL_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR +FF_DL_OFFSET+FF_DL_OFFSET+FF_DL_OFFSET) & 0xFF)) << 8);
            		TempDataLength |= (canuint32)(*(CanChipDataPtr)(DL_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + FF_DL_OFFSET + FF_DL_OFFSET + FF_DL_OFFSET + FF_DL_OFFSET ));
            		if(FRAME_CANFD_MAX_FF_DL < TempDataLength)
            			tpRxInfoStruct[tpChannel].ApplGetBufferStatus = kTpFCStatusOverflow;
            		else
            			tpRxInfoStruct[tpChannel].ApplGetBufferStatus = kTpFCSuppressFrame;
            	}
            	else
            		tpRxInfoStruct[tpChannel].ApplGetBufferStatus = kTpFCClearToSend;
# endif
              /* Set pointer to CAN buffer data to have access in GetBuffer function */
              tpRxInfoStruct[tpChannel].DataBufferPtr.DataCanBufferPtr = (CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR);
# if (TP_USE_GATEWAY_API == kTpOn)
              tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr = __ApplTpRxGetBuffer((canuint8)tpChannel, tpRxInfoStruct[tpChannel].DataLength, rxStruct);
# else
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
              tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr = __ApplTpRxGetBuffer((canuint8)tpChannel, tpRxInfoStruct[tpChannel].DataLength, &Appl_QueNumber);
#else
              tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr = __ApplTpRxGetBuffer((canuint8)tpChannel, tpRxInfoStruct[tpChannel].DataLength);
#endif/*TP_ENABLE_DIAG_SERVICE_QUEUE*/
# endif
# if (defined(TP_ENABLE_FC_WAIT) || defined(TP_ENABLE_FC_SUPPRESS) || defined(TP_ENABLE_FC_OVERFLOW))
              switch(tpRxInfoStruct[tpChannel].ApplGetBufferStatus)
# endif
              {
# if defined (TP_ENABLE_FC_WAIT)
              case  kTpFCStatusWait:
#  if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
                /* check if feature withoutFC is not activated for this channel - both is not possible! */
                assertReturnInternal(tpChannel,tpRxInfoStruct[tpChannel].withoutFC != 0, kTpRxErrFCWaitCombinedWithNoFC,kCanNoCopyData);
#  endif
                { /* Send FC with status Wait */
                  *(tpRxInfoStruct[tpChannel].FFDataBuffer + 0) = *(CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 0);
                  *(tpRxInfoStruct[tpChannel].FFDataBuffer + 1) = *(CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 1);
                  *(tpRxInfoStruct[tpChannel].FFDataBuffer + 2) = *(CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 2);
                  *(tpRxInfoStruct[tpChannel].FFDataBuffer + 3) = *(CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 3);
                  *(tpRxInfoStruct[tpChannel].FFDataBuffer + 4) = *(CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 4);
#  if defined(TP_ENABLE_NORMAL_ADDRESSING)
                  {
                    *(tpRxInfoStruct[tpChannel].FFDataBuffer + 5) = *(CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 5);
                  }
#  endif
                /*Set rx index to next free data element*/
                  tpRxInfoStruct[tpChannel].DataIndex = (canuint16)(FRAME_LENGTH - (FF_OFFSET + FORMAT_OFFSET));

                  tpRxInfoStruct[tpChannel].sequencenumber = 1;        /* Await CF with SN 1 next */
#  if defined (TP_ENABLE_FC_WAIT)
                  tpRxState[tpChannel].WFTCounter = kTpWFTmax;         /* Reset wait frame counter */
#  endif

#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#   if defined(TP_ENABLE_NORMAL_ADDRESSING)
                  {
                    assertReturnUser(tpChannel, tpRxInfoStruct[tpChannel].TransmitID <= CAN_MAX_ID, kTpRxErrFcCanIdIsMissing, kCanNoCopyData);
                  }
#   endif
#  endif

                  tpRxState[tpChannel].Timer  = TpRxConfirmationTimeout(tpChannel);
                  tpRxState[tpChannel].engine = kRxState_WaitForFCConfIsr;
                  /* set transmission request */
                  tpRxState[tpChannel].queued = 1;
#  if(TP_USE_TX_OF_FC_IN_ISR == kTpOn)
                  __TpRxStateTask(tpChannel);
#  endif
                }
                break;
# endif
#  if defined (TP_ENABLE_FC_SUPPRESS)
              case kTpFCSuppressFrame:
                { /* Suppress sending FC and cancel reception */
                  TpInit();
                  tpRxState[tpChannel].engine = kRxState_Idle;
                }
                break;
#  endif
#  if defined (TP_ENABLE_FC_OVERFLOW)
              case kTpFCStatusOverflow:
                { /* Send FC with status overflow */
# if defined (TP_ENABLE_ISO_15765_2_2)
#  if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
                  if (tpRxInfoStruct[tpChannel].withoutFC == 0)
#  endif
                  {
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#   if defined(TP_ENABLE_NORMAL_ADDRESSING)
                    assertReturnUser(tpChannel, tpRxInfoStruct[tpChannel].TransmitID <= CAN_MAX_ID, kTpRxErrFcCanIdIsMissing, kCanNoCopyData);
#   endif
#  endif
                    tpRxState[tpChannel].Timer  = TpRxConfirmationTimeout(tpChannel);
                    tpRxState[tpChannel].engine = kRxState_WaitForFCOverConfIsr;

                    /* set transmission request */
                    tpRxState[tpChannel].queued = 1;
#  if(TP_USE_TX_OF_FC_IN_ISR == kTpOn)
                    __TpRxStateTask(tpChannel);
#  endif
                  }
#  if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
                  else
                  {
                    tpRxState[tpChannel].engine = kRxState_Idle;
                  }
#  endif
# endif /* TP_DISABLE_ISO_15765_2_2 */
                }
                break;
#  endif
#  if (defined(TP_ENABLE_FC_WAIT) || defined(TP_ENABLE_FC_SUPPRESS) || defined(TP_ENABLE_FC_OVERFLOW))
              case kTpFCClearToSend:
                /* same as default - no break here */
              default:
#  endif
                if(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr != V_NULL)
                { /* data buffer is valid */
#  if defined TP_ENABLE_MULTIPLE_NODES
#  else
#   if defined( TP_ENABLE_SINGLE_CHAN_MULTICONN )
                  connHandle = handle;
#    if ( kTpNumberOfCanChannels > 1 )
#    endif
#   endif
#  endif
                  /* Callback - a FirstFrame is received */
                  __ApplTpRxFF((canuint8)tpChannel);

                  /**** COPY DATA ********************************************/
# if (TP_USE_CUSTOM_RX_MEMCPY == kTpOff)

#if FBLM_CANFD_SUPPORT
                  for (counter = (cansintCPUtype)tpCanRxFrameLength; counter>=0; counter--)
                  {
                    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + counter) = *((CanChipDataPtr)(SF_OFFSET + SF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR) + counter);
                  }
#else /*CAN USED */
                  *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + 0) = *(CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 0);
                  *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + 1) = *(CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 1);
                  *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + 2) = *(CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 2);
                  *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + 3) = *(CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 3);
                  *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + 4) = *(CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 4);
#  if defined(TP_ENABLE_NORMAL_ADDRESSING)
                  {
                    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + 5) = *(CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 5);
                  }
#  endif
#endif /*FBLM_CANFD_SUPPORT*/

# else
#  if defined (TP_ENABLE_INTERMEDIATE_CANCHIP_BUFFER)
#   if defined (C_ENABLE_MEMCOPY_SUPPORT)
                  CanCopyFromCan(pIntermediateCANChipData, (CanChipDataPtr)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR), FRAME_LENGTH);
#   else
#    error Configuration is not supported: C_ENABLE_MEMCOPY_SUPPORT is missing
#   endif
#   if defined( TP_ENABLE_EXT_COPYFROMCAN_API )
                  __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)pIntermediateCANChipData, (canuint16)(FRAME_LENGTH - (FF_OFFSET + FORMAT_OFFSET)), rxStruct);
#   else
                  __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)pIntermediateCANChipData, (canuint16)(FRAME_LENGTH - (FF_OFFSET + FORMAT_OFFSET)));
#   endif
#  else
#   if defined( TP_ENABLE_EXT_COPYFROMCAN_API )
                  __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR), (canuint16)(FRAME_LENGTH - (FF_OFFSET + FORMAT_OFFSET)), rxStruct);
#   else
                  __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)(FF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR), (canuint16)(FRAME_LENGTH - (FF_OFFSET + FORMAT_OFFSET)));
#   endif
#  endif
# endif

#if FBLM_CANFD_SUPPORT
                  /*Set rx index to next free data element*/
                  tpRxInfoStruct[tpChannel].DataIndex = (canuint16)(tpCanRxFrameLength - (FF_OFFSET + FORMAT_OFFSET));
#else /*CANFD USED */
                  tpRxInfoStruct[tpChannel].DataIndex = (canuint16)(FRAME_LENGTH - (FF_OFFSET + FORMAT_OFFSET));
#endif /*FBLM_CANFD_SUPPORT*/

                  tpRxInfoStruct[tpChannel].sequencenumber = 1;        /* Await CF with SN 1 next */
# if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
                  if (tpRxInfoStruct[tpChannel].withoutFC == 0)
# endif
                  {
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#  if defined(TP_ENABLE_NORMAL_ADDRESSING)
                    {
                      assertReturnUser(tpChannel, tpRxInfoStruct[tpChannel].TransmitID <= CAN_MAX_ID, kTpRxErrFcCanIdIsMissing, kCanNoCopyData);
                    }
#  endif
# endif
                    tpRxState[tpChannel].Timer  = TpRxConfirmationTimeout(tpChannel);
                    tpRxState[tpChannel].engine = kRxState_WaitForFCConfIsr;

                    tpRxState[tpChannel].queued = 1; /* set transmission request */
# if(TP_USE_TX_OF_FC_IN_ISR == kTpOn)
                    __TpRxStateTask(tpChannel);
# endif
                  }
# if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
                  else
                  {
                    tpRxState[tpChannel].Timer  = kTimeoutCF(tpChannel);
                    /* setting BSCounter to zero to avoid further FlowControls */
                    tpRxState[tpChannel].BSCounter = 0;
                    tpRxState[tpChannel].engine = kRxState_WaitCF;
                  }
# endif
                }
                else
                { /* FS == CTS but invalid data buffer */
                  tpRxState[tpChannel].engine = kRxState_Idle;
                }
              } /* end switch flow status */
            }
            else
            { /* too less data bytes for a FF */
              tpRxState[tpChannel].engine = kRxState_ApplInformed;
              TP_RX_RESET_CHANNEL(tpChannel);
            }
          }
# if (TP_USE_VARIABLE_RX_DLC_CHECK == kTpOn)
          else
          { /* FF with less than 8 bytes is not defined */
            tpRxState[tpChannel].engine = kRxState_ApplInformed;
            TP_RX_RESET_CHANNEL(tpChannel);
          }
# endif
        }
# if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && ((kTpNumberOfCanChannels > 1) && (kTpNumberOfCanChannels != kCanNumberOfChannels)) )
        else
        { /* unused handle */
          tpRxState[tpChannel].engine = kRxState_ApplInformed;
          TP_RX_RESET_CHANNEL(tpChannel);
        }
# endif
        return kCanNoCopyData; /* Do not receive the frame */
        /* break; */
        /*-----------------------------------------------------------------------------
        | Receive SingleFrame
        -----------------------------------------------------------------------------*/
        case kL4_SingleFrame:
#endif  /* defined( TP_ENABLE_MF_RECEPTION ) */

#if (TP_USE_APPL_PRECOPY == kTpOn) && (TP_USE_FAST_PRECOPY == kTpOff) && defined (TP_DISABLE_CHECKTA_COMPATIBILITY)
# if defined(TP_ENABLE_EXTENDED_ADDRESSING)
        {
          switch (tpApplTpPrecopyReturn)
          {
          case kTpNone:
            tpRxState[tpChannel].engine = kRxState_Idle;
            return kCanNoCopyData;
            /*break;*/
          case kTpPhysical:
            tpRxInfoStruct[tpChannel].ta_type = 0;
            break;
          case kTpFunctional:
            tpRxInfoStruct[tpChannel].ta_type = 1;
            break;
          default:
            /* Call everytime assertion */
            assertGeneral(tpChannel, kTpErrPrecopyCheckInvalidReturn);
            break;
          }
        }
# endif
#endif
#if FBLM_CANFD_SUPPORT
//        if(0x00 == (*(CanChipDataPtr)(TPCI_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR) & 0x0F))
        if((CAN_DLC_VALUE_0x9 <=tpCanRxActualDLC) && ((CAN_DLC_VALUE_0xF >=tpCanRxActualDLC)))
        {
          /*When receive the Length > 8 of CANFD Single Frame (byte#1 : 0x00, byte#2 :SF_DL)*/
          tpRxInfoStruct[tpChannel].DataLength = *(CanChipDataPtr)(TPCI_OFFSET + FORMAT_OFFSET + SF_OFFSET + FRAME_DATA_PTR);
          tpRxCanFrameFormat = TP_CANFD_FORMAT;
        }
        else
        {
           /*When receive the Length <= 8 of CANFD/CAN Single Frame (byte#1 Bit7-4:0x0, byte#1 Bit3-0:SF_DL )*/
           tpRxInfoStruct[tpChannel].DataLength = *(CanChipDataPtr)(TPCI_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR);
           tpRxCanFrameFormat = TP_CAN_FORMAT;
        }
#else  /*CAN USED*/
        tpRxInfoStruct[tpChannel].DataLength = *(CanChipDataPtr)(TPCI_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR);
#endif /*FBLM_CANFD_SUPPORT*/
        /*Store length for app usage*/
#if (TP_USE_VARIABLE_RX_DLC_CHECK == kTpOn)
# if defined( TP_ENABLE_STRICT_DL_CHECK )
          if (tpCanRxActualDLC == (tpRxInfoStruct[tpChannel].DataLength + SF_OFFSET + FORMAT_OFFSET))
# else
          if(TP_CANFD_FORMAT == tpRxCanFrameFormat)
          {
           /*Allowed SF_DL values for a given CAN_DL Greater than 8 and addressing cheme*/
            if(tpCanRxFrameLength == CAN_R_DLC_VALUE_12)
            {
              if((8 <= tpRxInfoStruct[tpChannel].DataLength) && (10 >= tpRxInfoStruct[tpChannel].DataLength))
              {
                tpRxCheckCanDlcFail = FALSE;
              }
              else
              {
            	tpRxCheckCanDlcFail = TRUE;
              }
            }
            else if(tpCanRxFrameLength == CAN_R_DLC_VALUE_16)
            {
              if((11 <= tpRxInfoStruct[tpChannel].DataLength) && (14 >= tpRxInfoStruct[tpChannel].DataLength))
              {
                tpRxCheckCanDlcFail = FALSE;
              }
              else
              {
              tpRxCheckCanDlcFail = TRUE;
              }
            }
            else if(tpCanRxFrameLength == CAN_R_DLC_VALUE_20)
            {
              if((15 <= tpRxInfoStruct[tpChannel].DataLength) && (18 >= tpRxInfoStruct[tpChannel].DataLength))
              {
                tpRxCheckCanDlcFail = FALSE;
              }
              else
              {
              tpRxCheckCanDlcFail = TRUE;
              }
            }
            else if(tpCanRxFrameLength == CAN_R_DLC_VALUE_24)
            {
              if((19 <= tpRxInfoStruct[tpChannel].DataLength) && (22 >= tpRxInfoStruct[tpChannel].DataLength))
              {
                tpRxCheckCanDlcFail = FALSE;
              }
              else
              {
                tpRxCheckCanDlcFail = TRUE;
              }
            }
            else if(tpCanRxFrameLength == CAN_R_DLC_VALUE_32)
            {
              if((23 <= tpRxInfoStruct[tpChannel].DataLength) && (30 >= tpRxInfoStruct[tpChannel].DataLength))
              {
                tpRxCheckCanDlcFail = FALSE;
              }
              else
              {
              tpRxCheckCanDlcFail = TRUE;
              }
            }
            else if(tpCanRxFrameLength == CAN_R_DLC_VALUE_48)
            {
              if((31 <= tpRxInfoStruct[tpChannel].DataLength) && (46 >= tpRxInfoStruct[tpChannel].DataLength))
              {
                tpRxCheckCanDlcFail = FALSE;
              }
              else
              {
              tpRxCheckCanDlcFail = TRUE;
              }
            }
            else if(tpCanRxFrameLength == CAN_R_DLC_VALUE_64)
            {
              if((47 <= tpRxInfoStruct[tpChannel].DataLength) && (62 >= tpRxInfoStruct[tpChannel].DataLength))
              {
                tpRxCheckCanDlcFail = FALSE;
              }
              else
              {
              tpRxCheckCanDlcFail = TRUE;
              }
            }
          }
          else if(TP_CAN_FORMAT == tpRxCanFrameFormat)
          {
              if(tpCanRxActualDLC >= (tpRxInfoStruct[tpChannel].DataLength + SF_OFFSET + FORMAT_OFFSET))
              {
                tpRxCheckCanDlcFail = FALSE;
              }
              else
              {
                tpRxCheckCanDlcFail = TRUE;
              }
          }
          /* Checking CAN-DLC */
          if (FALSE == tpRxCheckCanDlcFail)
# endif
#endif
          {
            if ((tpRxInfoStruct[tpChannel].DataLength <= ((canuint16)(tpCanRxFrameLength - (SF_OFFSET + FORMAT_OFFSET))))
#if defined (TP_ENABLE_ISO_15765_2_2)
              && (tpRxInfoStruct[tpChannel].DataLength  != 0)
#endif
              )
            { /* Is maximum length of a SingleFrame exeeded ? */
#if (defined(TP_ENABLE_FC_WAIT) || defined(TP_ENABLE_FC_SUPPRESS) || defined(TP_ENABLE_FC_OVERFLOW))
              /* Preselect ApplGetBufferStatus to the default */
              tpRxInfoStruct[tpChannel].ApplGetBufferStatus = kTpFCClearToSend;
#endif
              tpRxInfoStruct[tpChannel].DataBufferPtr.DataCanBufferPtr = (CanChipDataPtr)(SF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR);
#  if (TP_USE_GATEWAY_API == kTpOn)
              tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr = __ApplTpRxGetBuffer((canuint8)tpChannel, tpRxInfoStruct[tpChannel].DataLength, rxStruct);
#  else
#if defined(TP_ENABLE_DIAG_SERVICE_QUEUE)
              tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr = __ApplTpRxGetBuffer((canuint8)tpChannel, tpRxInfoStruct[tpChannel].DataLength, &Appl_QueNumber);
#else
              tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr = __ApplTpRxGetBuffer((canuint8)tpChannel, tpRxInfoStruct[tpChannel].DataLength);
#endif/*TP_ENABLE_DIAG_SERVICE_QUEUE*/

#endif
#if (defined(TP_ENABLE_FC_WAIT) || defined(TP_ENABLE_FC_SUPPRESS) || defined(TP_ENABLE_FC_OVERFLOW))
              assertReturnUser(tpChannel, (tpRxInfoStruct[tpChannel].ApplGetBufferStatus == kTpFCClearToSend) || (tpRxInfoStruct[tpChannel].ApplGetBufferStatus == kTpFCSuppressFrame), kTpRxErrInconsistentFlowStatus, kCanNoCopyData);
#endif
              if((tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr != V_NULL)
#if (defined(TP_ENABLE_FC_WAIT) || defined(TP_ENABLE_FC_SUPPRESS) || defined(TP_ENABLE_FC_OVERFLOW))
                && (tpRxInfoStruct[tpChannel].ApplGetBufferStatus == kTpFCClearToSend)
#endif
                )
              { /* data buffer is valid */
#if defined TP_ENABLE_MULTIPLE_NODES
#else
# if defined( TP_ENABLE_SINGLE_CHAN_MULTICONN )
                connHandle = handle;
#  if ( kTpNumberOfCanChannels > 1 )
#  endif
# endif
#endif
                /* Callback - a SingleFrame is received */
                __ApplTpRxSF((canuint8)tpChannel);
                /**** COPY DATA ********************************************/
#if (TP_USE_CUSTOM_RX_MEMCPY == kTpOff)
#if FBLM_CANFD_SUPPORT
                if(TP_CANFD_FORMAT == tpRxCanFrameFormat)
                {
                  for (counter = (cansintCPUtype)(tpRxInfoStruct[tpChannel].DataLength-1); counter>=0; counter--)
                  {
                    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + counter) = *((CanChipDataPtr)(SF_OFFSET + SF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR) + counter);
                  }
                }
                else if(TP_CAN_FORMAT == tpRxCanFrameFormat)
                {
                  for (counter = (cansintCPUtype)(tpRxInfoStruct[tpChannel].DataLength-1); counter>=0; counter--)
                  {
                    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + counter) = *((CanChipDataPtr)(SF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR) + counter);
                  }
                }
                else
                {
                  /*nothing,error.*/
                }
#else /*CAN USED*/
                *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + counter) = *((CanChipDataPtr)(SF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR) + counter);
#endif /*FBLM_CANFD_SUPPORT*/

#else
# if defined (TP_ENABLE_INTERMEDIATE_CANCHIP_BUFFER)
#  if defined (C_ENABLE_MEMCOPY_SUPPORT)
                CanCopyFromCan(pIntermediateCANChipData, (CanChipDataPtr)(SF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR), FRAME_LENGTH);
#  else
#   error Configuration is not supported: C_ENABLE_MEMCOPY_SUPPORT is missing
#  endif
#  if defined( TP_ENABLE_EXT_COPYFROMCAN_API )
                __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)pIntermediateCANChipData, tpRxInfoStruct[tpChannel].DataLength, rxStruct);
#  else
                __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)pIntermediateCANChipData, tpRxInfoStruct[tpChannel].DataLength);
#  endif
# else
#  if defined( TP_ENABLE_EXT_COPYFROMCAN_API )
                __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)(SF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR), tpRxInfoStruct[tpChannel].DataLength, rxStruct);
#  else
                __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)(SF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR), tpRxInfoStruct[tpChannel].DataLength);
#  endif
# endif
#endif

                {
                  tpRxState[tpChannel].engine = kRxState_ApplInformed;
                  /* Callback - ApplIndication: a SF is completely received */
                  __ApplTpRxIndication((canuint8)tpChannel, tpRxInfoStruct[tpChannel].DataLength);
                }
              }
              else
              { /* invalid data buffer */
                tpRxState[tpChannel].engine = kRxState_ApplInformed;
                TP_RX_RESET_CHANNEL(tpChannel);
              }
            }
            else
            { /* SF data length incorrect */
              tpRxState[tpChannel].engine = kRxState_ApplInformed;
              TP_RX_RESET_CHANNEL(tpChannel);
            }
          }
#if (TP_USE_VARIABLE_RX_DLC_CHECK == kTpOn)
          else
          { /* DLC check failed */
            tpRxState[tpChannel].engine = kRxState_ApplInformed;
            TP_RX_RESET_CHANNEL(tpChannel);
          }
#endif
          return kCanNoCopyData;
          /* break; */

#if defined( TP_ENABLE_MF_RECEPTION )
        default:
          /* unknown frame */
          tpRxState[tpChannel].engine = kRxState_ApplInformed;
          TP_RX_RESET_CHANNEL(tpChannel);
          break;
      }
#endif
    }
    break;

#if defined( TP_ENABLE_MF_RECEPTION )
    /*-----------------------------------------------------------------------------
    | TP Consecutive Frame in CAN-Cell -> map it to appropriate TP-channel
    -----------------------------------------------------------------------------*/
  case kL4_ConsecutiveFrame:
# if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
  case kL4_ConsecutiveFrameWithoutFC:
    /* no break - because kL4_ConsecutiveFrame || kL4_ConsecutiveFrameWithoutFC are the same */
# endif
    /**** Search for a free tpChannel *****************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
# else
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
    for (tpChannel=(cansintCPUtype)(kTpRxChannelCount-1); tpChannel>=0; tpChannel--)
#  endif
# endif
    {
      /* check if tpChannel is in use */
      if((tpRxState[tpChannel].engine == kRxState_WaitCF)
# if (TP_HIGH_RX_LOW_TX_PRIORITY == kTpOn)
        || (tpRxState[tpChannel].engine == kRxState_WaitForFCConfIsr)
# endif
        )
      { /* A connection is established on this channel and a CF is allowed */

        /**** Receive ***********************************************************/
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#  if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
        if (tpRxInfoStruct[tpChannel].CanChannel == (canbittype)(rxStruct->Channel))
#  endif
# endif
        {
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
          /**** EXTENDED_ADDRESSING  ******************************************/
#  if defined(TP_ENABLE_EXTENDED_ADDRESSING)
            /*lint -e(644) tpCurrentSourceAddress is initialized */
            if( (tpRxInfoStruct[tpChannel].SourceAddress == (canuint8)tpCurrentSourceAddress)
#   if (TP_USE_FAST_PRECOPY == kTpOff)
              && (TP_RX_ECU_NR(tpChannel) == tpCurrentTargetAddress) /* Compare addresses */
#   endif
#   if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
              && (tpRxInfoStruct[tpChannel].BaseAddress == tpCurrentBaseAddress)
#   endif
              )
#  endif
          /**** NORMAL FIXED ADDRESSING ***************************************/
          /**** MIXED 29bit ADDRESSING ****************************************/
          /**** DYNAMIC NORMAL ADDRESSING *************************************/
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#   if defined(TP_ENABLE_NORMAL_ADDRESSING)
#    if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
            if( (tpRxInfoStruct[tpChannel].ReceiveID == tpCanRxActualId) && (tpRxInfoStruct[tpChannel].ReceiveIDType == tpCanRxActualIdType) )
#    else
            if(tpRxInfoStruct[tpChannel].ReceiveID == tpCanRxActualId)
#    endif
#   endif
#  endif
          /**** DYNAMIC MIXED 11bit ADDRESSING ********************************/
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#  endif
          /**** STATIC NORMAL ADDRESSING **************************************/
# endif
/* defined (TP_ENABLE_DYNAMIC_CHANNELS) */
          {
          /*-----------------------------------------------------------------------------
          | ConsecutiveFrame is now assigned to TP - channel -> work now on received data
            -----------------------------------------------------------------------------*/
# if (TP_HIGH_RX_LOW_TX_PRIORITY == kTpOn)
            if(tpRxState[tpChannel].engine == kRxState_WaitForFCConfIsr)
            {
              if(tpRxState[tpChannel].queued == 0)
              {
#  if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && (kTpNumberOfCanChannels > 1) )
                assertReturnInternal(tpChannel, (TP_RX_HANDLE(tpChannel) != kCanTxHandleNotUsed), kTpErrCanChannelNotSupported, kCanNoCopyData);
#  endif
                /* Emulate Isr-Confirm on state kRxState_WaitForFCConfIsr because this event might have happened but is only scheduled later in processor */
                TPCANCANCELTRANSMIT(TpIntRxGetCanChannel(tpChannel)) (TP_RX_HANDLE(tpChannel)); /* suppress real confirmation */
#  if defined (TP_CAN_CODEDOUBLED)
                TpDrvRxConfirmation(rxStruct->Channel); /* Call confirmation function to simulate expected WaitForFCConfIsr event */
#  else
#   if defined (TP_ENABLE_SINGLE_MSG_OBJ )
                TpDrvConfirmation(TP_RX_HANDLE(tpChannel)); /* Call confirmation function to simulate expected WaitForFCConfIsr event */
#   endif
#  endif
                /* state engine should now be in state kRxState_WaitCF */
                /* assertion on current state */
                assertReturnInternal(tpChannel,tpRxState[tpChannel].engine == kRxState_WaitCF, kTpRxErrNotInWaitCFState,kCanNoCopyData);
              }
              else
              {
                return kCanNoCopyData; /* Ignore frame and wait for correct frame */
              }
            }
# endif
#if FBLM_CANFD_SUPPORT
            /* A connection is established, CF is allowed */
            if( (tpRxInfoStruct[tpChannel].DataIndex + ((canuint16)(tpCanRxFrameLength - (CF_OFFSET + FORMAT_OFFSET))) ) >= tpRxInfoStruct[tpChannel].DataLength )
#else /*CAN USED*/
            /* A connection is established, CF is allowed */
            if( (tpRxInfoStruct[tpChannel].DataIndex + ((canuint16)(FRAME_LENGTH - (CF_OFFSET + FORMAT_OFFSET))) ) >= tpRxInfoStruct[tpChannel].DataLength )
#endif /*FBLM_CANFD_SUPPORT*/
            { /* Last CF! */
# if (TP_USE_VARIABLE_RX_DLC_CHECK == kTpOn)
#  if defined( TP_ENABLE_STRICT_DL_CHECK )
              if (tpCanRxActualDLC == (tpRxInfoStruct[tpChannel].DataLength - tpRxInfoStruct[tpChannel].DataIndex + FORMAT_OFFSET + CF_OFFSET))
#  else
#if FBLM_CANFD_SUPPORT
              /* Checking CAN-DLC */
              if (tpCanRxFrameLength >= (tpRxInfoStruct[tpChannel].DataLength - tpRxInfoStruct[tpChannel].DataIndex + FORMAT_OFFSET + CF_OFFSET))
#else  /*CAN USED */
              if (tpCanRxActualDLC >= (tpRxInfoStruct[tpChannel].DataLength - tpRxInfoStruct[tpChannel].DataIndex + FORMAT_OFFSET + CF_OFFSET))
#endif /*FBLM_CANFD_SUPPORT*/
#  endif
# endif
              {
                /*Wrong SN received?*/
                if( ((*(CanChipDataPtr)(TPCI_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR)) & kL4_SNMask) != (canuint8)(tpRxInfoStruct[tpChannel].sequencenumber) )
                { /* Stop receiving immediately! */
# if defined (TP_ENABLE_DYN_AWAIT_CORRECT_SN) || defined (TP_ENABLE_WAIT_FOR_CORRECT_SN)
#  if defined(TP_ENABLE_DYN_AWAIT_CORRECT_SN)
                  if(tpRxInfoStruct[tpChannel].SNwait == kTpTrue)
#  endif
                  {
                    return kCanNoCopyData; /* Ignore frame and wait for correct frame */
                  }
# endif
# if defined (TP_ENABLE_DYN_AWAIT_CORRECT_SN)
                  else
# endif
# if defined (TP_ENABLE_DYN_AWAIT_CORRECT_SN) || defined (TP_DISABLE_WAIT_FOR_CORRECT_SN)
                  {
                    __TpRxInit(tpChannel, kTpRxErrWrongSNreceived);
                    /*Possible tx of error frame here?*/
                  }
# endif
                }
                else
                {
                  /* Callback - a ConsecutiveFrame is received */
                  __ApplTpRxCF((canuint8)tpChannel);
                  /**** COPY DATA ********************************************/
# if (TP_USE_OVERRUN_INDICATION == kTpOn)
                  if (tpRxState[tpChannel].noCopyData == 0)
# endif
                  {
# if (TP_USE_CUSTOM_RX_MEMCPY == kTpOff)
                    for (counter = (cansintCPUtype)(tpRxInfoStruct[tpChannel].DataLength - (tpRxInfoStruct[tpChannel].DataIndex + 1)); counter>=0; counter--)
                    {
                      *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + tpRxInfoStruct[tpChannel].DataIndex + counter) = *((CanChipDataPtr)(CF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR) + counter);
                    }
# else
#  if defined (TP_ENABLE_INTERMEDIATE_CANCHIP_BUFFER)
#   if defined (C_ENABLE_MEMCOPY_SUPPORT)
                    CanCopyFromCan(pIntermediateCANChipData, (CanChipDataPtr)(FRAME_DATA_PTR + FORMAT_OFFSET + CF_OFFSET), FRAME_LENGTH);
#   else
#    error Configuration is not supported: C_ENABLE_MEMCOPY_SUPPORT is missing
#   endif
#   if defined( TP_ENABLE_EXT_COPYFROMCAN_API )
                    __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)pIntermediateCANChipData, (canuint8)(tpRxInfoStruct[tpChannel].DataLength - tpRxInfoStruct[tpChannel].DataIndex), rxStruct);
#   else
                    __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)pIntermediateCANChipData, (canuint8)(tpRxInfoStruct[tpChannel].DataLength - tpRxInfoStruct[tpChannel].DataIndex));
#   endif
#  else
#   if defined( TP_ENABLE_EXT_COPYFROMCAN_API )
                    __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)(FRAME_DATA_PTR + FORMAT_OFFSET + CF_OFFSET), (canuint8)(tpRxInfoStruct[tpChannel].DataLength - tpRxInfoStruct[tpChannel].DataIndex), rxStruct );
#   else
                    __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)(FRAME_DATA_PTR + FORMAT_OFFSET + CF_OFFSET), (canuint8)(tpRxInfoStruct[tpChannel].DataLength - tpRxInfoStruct[tpChannel].DataIndex) );
#   endif
#  endif
# endif
                  }
                  {
                    tpRxState[tpChannel].engine = kRxState_ApplInformed; /* Stop waiting for CF/FC */
                    tpRxState[tpChannel].Timer  = 0; /* Stop Timeout Counter */
                    /* Callback - ApplIndication a MultipleFrame is completely received */
                    __ApplTpRxIndication((canuint8)tpChannel, tpRxInfoStruct[tpChannel].DataLength);
                  }
                }
              }
            }
            else
            { /*Wait for next CF*/
# if (TP_USE_VARIABLE_RX_DLC_CHECK == kTpOn)
#if FBLM_CANFD_SUPPORT
               /* Checking CAN-DLC */
          //     if (tpCanRxActualDLC <= FRAME_CANFD_LENGTH)
               if (tpCanRxActualDLC == FRAME_CANFD_LENGTH)
#else
               /* Checking CAN-DLC */
               if (tpCanRxActualDLC == FRAME_LENGTH)
#endif /*FBLM_CANFD_SUPPORT*/
# endif
              {
                /*Wrong SN received?*/
                if( ((*(CanChipDataPtr)(TPCI_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR)) & kL4_SNMask) != (canuint8)(tpRxInfoStruct[tpChannel].sequencenumber) )
                { /* Stop receiving immediately! */
                  __TpRxInit(tpChannel, kTpRxErrWrongSNreceived);
                  /*Possible tx of error frame here?*/
                }
                else
                {
                  /* Callback - a ConsecutiveFrame is received */
                  __ApplTpRxCF((canuint8)tpChannel);
                  /**** COPY DATA ********************************************/
# if (TP_USE_OVERRUN_INDICATION == kTpOn)
                  if (tpRxState[tpChannel].noCopyData == 0)
# endif
                  {

# if (TP_USE_CUSTOM_RX_MEMCPY == kTpOff)
#if FBLM_CANFD_SUPPORT
                    for (counter = (cansintCPUtype)(tpCanRxFrameLength - CF_OFFSET - CF_OFFSET); counter>=0; counter--)  /*Receive 63 data byte, array is [0 - 62]*/
                    {
                      *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + tpRxInfoStruct[tpChannel].DataIndex + counter) = *(CanChipDataPtr)(CF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + counter);
                    }
#else /*CAN USED*/
                    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + tpRxInfoStruct[tpChannel].DataIndex + 0) = *(CanChipDataPtr)(CF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 0);
                    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + tpRxInfoStruct[tpChannel].DataIndex + 1) = *(CanChipDataPtr)(CF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 1);
                    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + tpRxInfoStruct[tpChannel].DataIndex + 2) = *(CanChipDataPtr)(CF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 2);
                    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + tpRxInfoStruct[tpChannel].DataIndex + 3) = *(CanChipDataPtr)(CF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 3);
                    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + tpRxInfoStruct[tpChannel].DataIndex + 4) = *(CanChipDataPtr)(CF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 4);
                    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + tpRxInfoStruct[tpChannel].DataIndex + 5) = *(CanChipDataPtr)(CF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 5);

#endif /*FBLM_CANFD_SUPPORT*/
#  if defined(TP_ENABLE_NORMAL_ADDRESSING)
#if FBLM_CANFD_SUPPORT

#else /*CAN USED*/
                    {
                      *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + tpRxInfoStruct[tpChannel].DataIndex + 6) = *(CanChipDataPtr)(CF_OFFSET + FORMAT_OFFSET + FRAME_DATA_PTR + 6);
                    }
#endif /*FBLM_CANFD_SUPPORT*/
#  endif

# else
#  if defined (TP_ENABLE_INTERMEDIATE_CANCHIP_BUFFER)
#   if defined (C_ENABLE_MEMCOPY_SUPPORT)
                    CanCopyFromCan(pIntermediateCANChipData, (CanChipDataPtr)(FRAME_DATA_PTR + FORMAT_OFFSET + CF_OFFSET), FRAME_LENGTH);
#   else
#    error Configuration is not supported: C_ENABLE_MEMCOPY_SUPPORT is missing
#   endif
#   if defined( TP_ENABLE_EXT_COPYFROMCAN_API )
                    __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)pIntermediateCANChipData, (canuint16)(FRAME_LENGTH - (CF_OFFSET + FORMAT_OFFSET)), rxStruct);
#   else
                    __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)pIntermediateCANChipData, (canuint16)(FRAME_LENGTH - (CF_OFFSET + FORMAT_OFFSET)));
#   endif
#  else
#   if defined( TP_ENABLE_EXT_COPYFROMCAN_API )
                    __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)(FRAME_DATA_PTR + FORMAT_OFFSET + CF_OFFSET), (canuint16)(FRAME_LENGTH - (CF_OFFSET + FORMAT_OFFSET)), rxStruct);
#   else
                    __ApplTpRxCopyFromCAN((canuint8)tpChannel, (canuint8*)(FRAME_DATA_PTR + FORMAT_OFFSET + CF_OFFSET), (canuint16)(FRAME_LENGTH - (CF_OFFSET + FORMAT_OFFSET)));
#   endif
#  endif
# endif
                  }
#if FBLM_CANFD_SUPPORT
                  tpRxInfoStruct[tpChannel].DataIndex = tpRxInfoStruct[tpChannel].DataIndex + (canuint16)(tpCanRxFrameLength - (CF_OFFSET + FORMAT_OFFSET));   /*Set rx index to next free data element*/
#else
                  tpRxInfoStruct[tpChannel].DataIndex = tpRxInfoStruct[tpChannel].DataIndex + (canuint16)(FRAME_LENGTH - (CF_OFFSET + FORMAT_OFFSET));   /*Set rx index to next free data element*/
#endif /*FBLM_CANFD_SUPPORT*/
                  /*Calculate next expected SN now (not neccessary if last CF was received)*/
                  /*SN is calculated modulo 15*/
                  tpRxInfoStruct[tpChannel].sequencenumber = CANBITTYPE_CAST(tpRxInfoStruct[tpChannel].sequencenumber + 1); /*SN increment*/

                  /* No special check for channels without FlowControl */
                  /* If BS == 0 - no FlowControl frames shall be sent */
                  if(tpRxState[tpChannel].BSCounter != 0)
                  {
                    tpRxState[tpChannel].BSCounter--;
                    /* Check if a FC is requested (BS==0?) */
                    if(tpRxState[tpChannel].BSCounter == 0)
                    { /*Yes, FC is requested!*/
                      tpRxState[tpChannel].engine = kRxState_WaitForFCConfIsr;
                      tpRxState[tpChannel].Timer = TpRxConfirmationTimeout(tpChannel);
                      /* set transmission request */
                      tpRxState[tpChannel].queued = 1;
# if(TP_USE_TX_OF_FC_IN_ISR == kTpOn)
                      __TpRxStateTask(tpChannel);
# endif
                      return kCanNoCopyData;
                    }
                  }
                  tpRxState[tpChannel].Timer = kTimeoutCF(tpChannel);
                  tpRxState[tpChannel].engine = kRxState_WaitCF;
                }
              }
            }
            return kCanNoCopyData;
          }
        }
        /**** if CAN channel detected ********************************************/
      }
      /**** Search for a free tpChannel - finish *********************************/
    }
    break;
#endif  /* defined( TP_ENABLE_MF_RECEPTION ) */

    /*-----------------------------------------------------------------------------
    | Flow Control in CAN-cell -> map it to appropriate TP-channel
    -----------------------------------------------------------------------------*/
  case kL4_FlowControl:
    /**** Search for a free tpChannel *****************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
    for (tpChannel=(cansintCPUtype)(kTpTxChannelCount-1); tpChannel>=0; tpChannel--)
# endif
#endif
    { /* Is waiting for FC ? */
#if (TP_HIGH_RX_LOW_TX_PRIORITY == kTpOn)
      if((  tpTxState[tpChannel].engine == kTxState_WaitFC)
        || (tpTxState[tpChannel].engine == kTxState_WaitForFFConfIsr)
        || (tpTxState[tpChannel].engine == kTxState_WaitForCFConfIsr))
#else
      if(tpTxState[tpChannel].engine    == kTxState_WaitFC)
#endif
      {
        /**** Receive ***********************************************************/
#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
        if (tpTxInfoStruct[tpChannel].CanChannel == (canbittype)(rxStruct->Channel))
# endif
#endif
        {
          /**** EXTENDED_ADDRESSING  ******************************************/
#if defined(TP_ENABLE_EXTENDED_ADDRESSING)
            /*lint -e(644) tpCurrentSourceAddress is initialized */
            if( (tpTxInfoStruct[tpChannel].TargetAddress == (canuint8)tpCurrentSourceAddress)
# if (TP_USE_FAST_PRECOPY == kTpOff)
              && (TP_TX_ECU_NR(tpChannel) == tpCurrentTargetAddress) /* Compare addresses */
# endif
# if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
              && (tpTxInfoStruct[tpChannel].BaseAddress == tpCurrentBaseAddress)
# endif
              )
#endif
          /**** NORMAL FIXED ADDRESSING ***************************************/
          /**** MIXED 29bit  ADDRESSING ***********************************************/
          /**** DYNAMIC NORMAL ADDRESSING *************************************/
#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if defined(TP_ENABLE_NORMAL_ADDRESSING)
#    if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
            if( (tpTxInfoStruct[tpChannel].ReceiveID == tpCanRxActualId) && (tpTxInfoStruct[tpChannel].ReceiveIDType == tpCanRxActualIdType) )
#    else
            if(tpTxInfoStruct[tpChannel].ReceiveID == tpCanRxActualId)
#    endif
# endif
#endif
          /**** DYNAMIC MIXED 11bit ADDRESSING *************************************/
#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#endif
          /****
          STATIC NORMAL ADDRESSING **************************************/
          {
            /*-----------------------------------------------------------------------------
            | FlowControl is now assigned to TP - channel -> work now on received data
            -----------------------------------------------------------------------------*/
            /*Attention: No FC after last data message allowed (except feature AcknowledgeConnection) */
#if (TP_HIGH_RX_LOW_TX_PRIORITY == kTpOn)
            if(tpTxState[tpChannel].queued == 0)
            {
              if((tpTxState[tpChannel].engine == kTxState_WaitForFFConfIsr)     ||
                ((tpTxState[tpChannel].engine == kTxState_WaitForCFConfIsr) &&
                 (tpTxState[tpChannel].BSCounter == 1)) )
              {
# if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && (kTpNumberOfCanChannels > 1) )
                assertReturnInternal(tpChannel, (TP_TX_HANDLE(tpChannel) != kCanTxHandleNotUsed), kTpErrCanChannelNotSupported, kCanNoCopyData);
# endif
                /* Emulate Isr-Confirm on state kRxState_WaitForFCConfIsr because this event might have happened but is only scheduled later in processor */
                TPCANCANCELTRANSMIT(TpIntTxGetCanChannel(tpChannel)) (TP_TX_HANDLE(tpChannel)); /* suppress scheduled event */
# if defined (TP_CAN_CODEDOUBLED)
                TpDrvTxConfirmation(rxStruct->Channel);       /* call driver routine now */
# else
#  if defined (TP_ENABLE_SINGLE_MSG_OBJ )
                TpDrvConfirmation(TP_TX_HANDLE(tpChannel)); /* call driver routine now */
#  endif
# endif
                /* state engine should be now in kTxState_WaitFC state */
                assertReturnInternal(tpChannel, (tpTxState[tpChannel].engine == kTxState_WaitFC),     kTpTxErrNotInWaitFCState,kCanNoCopyData);
              }
            }
            else
            {
                /* ignore FC while confirmation is queued */
                return kCanNoCopyData;
            }
#endif

            if(  (tpTxState[tpChannel].engine == kTxState_WaitFC)
              )
            {
#if (TP_USE_VARIABLE_RX_DLC_CHECK == kTpOn)
              /* Checking CAN-DLC */
# if defined( TP_ENABLE_STRICT_DL_CHECK )
              if (tpCanRxActualDLC == (FC_LENGTH + FORMAT_OFFSET))
# else
              if (tpCanRxActualDLC >= (FC_LENGTH + FORMAT_OFFSET))
# endif
#endif
              {
                /**** FlowStatus *******************************************************/
                switch(*(CanChipDataPtr)(FRAME_DATA_PTR + FORMAT_OFFSET + TPCI_OFFSET))
                {
                case kL4_FlowControl:
                  {
                    {
# if (TP_USE_ONLY_FIRST_FC == kTpOn)
                      if (tpTxState[tpChannel].firstFC == 0)
# endif
                      {
# if (TP_USE_ONLY_FIRST_FC == kTpOn)
                        tpTxState[tpChannel].firstFC = 1; /* Set flag with the first received FC */
                        tpTxInfoStruct[tpChannel].BlockSize = (*(CanChipDataPtr)(FRAME_DATA_PTR + FORMAT_OFFSET + BS_OFFSET));
# else
                        tpTxState[tpChannel].BSCounter = (*(CanChipDataPtr)(FRAME_DATA_PTR + FORMAT_OFFSET + BS_OFFSET));
# endif

# if (TP_USE_STMIN_OF_FC == kTpOn)
                        tpSTminInFrame = (*(CanChipDataPtr)(FRAME_DATA_PTR + FORMAT_OFFSET + STMIN_OFFSET));
#  if defined( TP_ENABLE_IGNORE_FC_RES_STMIN )
                        if ( ((tpSTminInFrame & 0x80) != 0) && ((tpSTminInFrame < 0xF1) || (tpSTminInFrame > 0xF9)) )
                        {
                          break; /* When Reserved value is received, FC is rejected (wprocan-a00-00-a) */
                        }
#  endif
#  if (TP_USE_FAST_TX_TRANSMISSION == kTpOn)
                        tpTxInfoStruct[tpChannel].STminInFrame = (canuint8)tpSTminInFrame;
#  endif
#  if defined (TP_EXCLUDE_STMININFRAME_CHECK)
#  else
                        if (tpSTminInFrame < (canuintCPUtype)(TpTxGetSTMINDefaultTime(tpChannel)*TpTxCallCycle))
                        { /* Requested STmin to low for internal possible values, use minimum value */
                          tpTxInfoStruct[tpChannel].STMin = (canuint8)TpTxGetSTMINDefaultTime(tpChannel);
                        }
                        else
#  endif
                        { /* Selected call cycle is rounded up to next possible call value */
#  if defined (TP_ENABLE_ISO_15765_2_2)
                          if ((tpSTminInFrame & 0x80) != 0)
                          {
                            if ((tpSTminInFrame > 0xF0) && (tpSTminInFrame <= 0xF9))
                            {
                              tpTxInfoStruct[tpChannel].STMin = (canuint8)TpTxGetSTMINDefaultTime(tpChannel);
                            }
                            else
                            {
                              tpTxInfoStruct[tpChannel].STMin = (canuint8)( ((127/*maxSTminTime*/ + (TpTxCallCycle-1)) / TpTxCallCycle) + 1);
                            }
                          }
                          else
#  endif
                          {
#  if (TP_USE_OLD_STMIN_CALCULATION == kTpOn)
#   if !defined (TP_ENABLE_ISO_15765_2_2)
#   else
                            tpTxInfoStruct[tpChannel].STMin = (canuint8) ((tpSTminInFrame + (TpTxCallCycle-1)) / TpTxCallCycle);
#   endif
#  else
#   if !defined (TP_ENABLE_ISO_15765_2_2)
#   else
                            tpTxInfoStruct[tpChannel].STMin = (canuint8)(((tpSTminInFrame + (TpTxCallCycle-1)) / TpTxCallCycle) + 1);
#   endif
#  endif
                          }
                        }
# endif  /* (TP_USE_STMIN_OF_FC == kTpOn) */
                      }
# if (TP_USE_ONLY_FIRST_FC == kTpOn)
                      tpTxState[tpChannel].BSCounter = (tpTxInfoStruct[tpChannel].BlockSize); /* load BlockSize into Counter */
# endif
#if (TP_USE_NO_STMIN_AFTER_FC == kTpOn)
                      tpTxState[tpChannel].Timer = 1;
#else
                      tpTxState[tpChannel].Timer = TpTxGetSTMINtime(tpChannel);
#endif
                      tpTxState[tpChannel].engine = kTxState_WaitForTpTxCF;

                      /* Callback - a FlowControl-Frame is received */
                      /* Note: This place of the hook function makes it possible to speed up */
                      /* the transmission of the next CF (instead of waiting the STmin time) */
                      /* by calling TpTxPrepareSendImmediate() in it. */
                      __ApplTpTxFC((canuint8)tpChannel);
                    }
                  }
                  break;


                case kL4_FlowStatus_Wait:
#if (defined( TP_ENABLE_MCAN ) || defined ( VGEN_ENABLE_TP_MCAN ))
                  if(tpTxState[tpChannel].WFTCounter == 0)
                  { /* N_WFTmax = 0: if ECU receives a FC.WAIT, then it detects 'N_WFT_OVRN' and notifies it to the Transport layer ( MCAN 25915NDS01) */
                    __TpTxInit(tpChannel, kTpTxErrWFTmaxOverrun);
                  }
                  else
                  {
                    tpTxState[tpChannel].WFTCounter--;                       /* decr. WaitFrame counter */
                    tpTxState[tpChannel].Timer = kTimeoutFC(tpChannel);      /* WaitFrame received, set timer again */
                  }
#else
                  tpTxState[tpChannel].Timer = kTimeoutFC(tpChannel);        /* WaitFrame received, set timer again */
#endif
                  break;


#if defined (TP_ENABLE_ISO_15765_2_2)
                case kL4_FlowStatus_Overrun:
                  /* Receiver reported an Overrun - terminate channel */
# if defined( TP_ENABLE_IGNORE_FC_OVFL )
# else
                  __TpTxInit(tpChannel, kTpTxErrFCOverrun);
# endif
                  break;
#endif
                default:
#if defined (TP_ENABLE_FC_MSG_FLOW_DYN_CHECK) || \
            (TP_USE_STRICT_MSG_FLOW_CHECKING == kTpOn)
# if defined (TP_ENABLE_FC_MSG_FLOW_DYN_CHECK)
                  if(tpTxInfoStruct[tpChannel].FCwfs == kTpTrue)
# endif
                  {
                    __TpTxInit(tpChannel, kTpTxErrFCWrongFlowStatus);
                  }
#endif
                  break;
                }
              }
            }
            return kCanNoCopyData;
          }
        }
      }
      /**** Search for a free tpChannel - finish *********************************/
    }
    break;
    /*-----------------------------------------------------------------------------
    | Default
    -----------------------------------------------------------------------------*/
  default:
    break;
  }
  return kCanNoCopyData;
} /* TpPrecopy */

#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
/*******************************************************************************
*
* NAME:              TpTxGetFreeChannel
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         connection
* RETURN VALUE:      tpChannel number
* DESCRIPTION:       Find a free tpChannel
*
*******************************************************************************/
canuint8 TP_API_CALL_TYPE TpTxGetFreeChannel(canuint8 connection)
{
  cansintCPUtype  tpChannel;
  tvolatileTpTxState pTpTxState;

  /* Search for a free TX-Channel */
  for (tpChannel=(cansintCPUtype)(kTpTxChannelCount-1); tpChannel>=0; tpChannel--)
  {
    if(tpTxState[tpChannel].engine == kTxState_Idle)   /* Channel is in use */
    {
      TpGlobalInterruptDisable();

      pTpTxState = (tvolatileTpTxState) &tpTxState[tpChannel];
      if(pTpTxState->engine == kTxState_Idle)   /* Channel is in use */
      {
        tpTxState[tpChannel].engine = kTxState_Reserved;
        TpGlobalInterruptRestore();

        tpTxInfoStruct[tpChannel].Connection = connection; /* Store the ConnectionNr. */
#  if (kTpNumberOfCanChannels > 1)
        tpTxInfoStruct[tpChannel].CanChannel = kTpMaxCanChannels; /* Preset for checking */
#  endif
#  if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
#   if defined  (TP_ENABLE_RUNTIME_CHECK )
        /* Clear validity for EcuNumber */
        tpTxInfoStruct[tpChannel].EcuNumberIsValid = 0;
#   endif
#  endif
#  if (defined(TP_ENABLE_EXTENDED_ADDRESSING) )
#   if defined  (TP_ENABLE_RUNTIME_CHECK )
        /* Clear validity for TargetAddress */
        tpTxInfoStruct[tpChannel].TargetAddressIsValid = 0;
#   endif
#  endif
#  if defined(TP_ENABLE_EXTENDED_ADDRESSING)
#   if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
        tpTxInfoStruct[tpChannel].BaseAddress = 0xffff;
#   endif
#  endif
#  if (TP_USE_TX_CHANNEL_WITHOUT_FC == kTpOn)
        tpTxInfoStruct[tpChannel].withoutFC = 0;
#  endif
        return (canuint8)tpChannel; /* Return the free ChannelNr */
      }
      TpGlobalInterruptRestore();
    }
  }
  return kTpNoChannel;
}
# endif /* # if defined (TP_ENABLE_DYNAMIC_CHANNELS) */
#endif

/*******************************************************************************
*
* NAME:              TpTransmit
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         Channel handle, pointer to transmit data, number of data bytes
* RETURN VALUE:      Status value
* DESCRIPTION:       Transmit data in buffer
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_API_CALL_TYPE TpTransmit(TP_MEMORY_MODEL_DATA canuint8 *ptrData, canuint16 count)
# else
canuint8 TP_API_CALL_TYPE TpTransmit(canuint8 tpChannel, TP_MEMORY_MODEL_DATA canuint8 *ptrData, canuint16 count)
# endif
{

  /*******************************************************************************
  * Runtime Checks
  *******************************************************************************/
  /*lint -e(506) kTpFailed is constant */
  RuntimeCheck_Return(tpChannel, (count <= 0xfff), kTpTxErrDatalengthTooHigh, kTpFailed);

# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
# else
#  if (kTpNumberOfCanChannels > 1)
#   if defined (TP_ENABLE_DYNAMIC_CHANNELS)
  assertReturnUser(    tpChannel, tpTxInfoStruct[tpChannel].CanChannel < kCanNumberOfChannels, kTpErrChannelNrTooHigh, kTpFailed);
  /*lint -e(506) kTpFailed is constant */
  RuntimeCheck_Return(tpChannel, (tpTxInfoStruct[tpChannel].CanChannel < kCanNumberOfChannels),0, kTpFailed);
#   endif
#  endif

#  if defined  (TP_ENABLE_RUNTIME_CHECK )

#   if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
  /*lint -e(506) kTpFailed is constant */
  RuntimeCheck_Return(tpChannel, ((tpTxInfoStruct[tpChannel].EcuNumberIsValid != 0x00) || (TpIntAddressFormatCheckEqualToNormal(tpChannel)) ),0, kTpFailed);
#   endif

#   if (defined(TP_ENABLE_EXTENDED_ADDRESSING) )
  /*lint -e(506) kTpFailed is constant */
  RuntimeCheck_Return(tpChannel, ((tpTxInfoStruct[tpChannel].TargetAddressIsValid != 0x00)),0, kTpFailed);
#   endif

#   if defined(TP_ENABLE_EXTENDED_ADDRESSING)
#    if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
    /*lint -e(506) kTpFailed is constant */
  RuntimeCheck_Return(tpChannel, ((tpTxInfoStruct[tpChannel].BaseAddress < 0x7ff) && TpIntAddressFormatCheckEqualToExtended(tpChannel)),0, kTpFailed);
#    endif
#   endif

#  endif
  /* TP_ENABLE_RUNTIME_CHECK */
# endif

  /*******************************************************************************
  * Protocol checks
  *******************************************************************************/
# if defined (TP_ENABLE_ISO_15765_2_2)
  if (count == 0)
  {
    return kTpFailed;
  }
# endif
# if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && ((kTpNumberOfCanChannels > 1) && (kTpNumberOfCanChannels != kCanNumberOfChannels)) )
  if (TP_TX_HANDLE(tpChannel) == kCanTxHandleNotUsed)
  {
    return kTpFailed;
  }
# endif
  /*******************************************************************************
  * Check if the same connection (not tpChannel) is currently running
  *******************************************************************************/
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#  if !defined (TP_ENABLE_SINGLE_CHANNEL_TP)
  {
    cansintCPUtype lTpChannel;
    for (lTpChannel=(cansintCPUtype)(kTpTxChannelCount-1); lTpChannel>=0; lTpChannel--)
    {
      if(  (tpTxState[lTpChannel].engine != kTxState_Idle)
        && (tpTxState[lTpChannel].engine != kTxState_Reserved)
        && (          lTpChannel         != tpChannel) )
      {
        /**** Receive ***********************************************************/

#   if ( kTpNumberOfCanChannels > 1 ) /* more than one canChannel ? */
        if (tpTxInfoStruct[tpChannel].CanChannel == tpTxInfoStruct[lTpChannel].CanChannel )
#   endif
        {
            /**** EXTENDED_ADDRESSING  ******************************************/
#   if defined(TP_ENABLE_EXTENDED_ADDRESSING)
              if( (tpTxInfoStruct[tpChannel].TargetAddress == tpTxInfoStruct[lTpChannel].TargetAddress)
#    if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
                && (tpTxInfoStruct[tpChannel].EcuNumber == tpTxInfoStruct[lTpChannel].EcuNumber)
#    endif
#    if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
                && (tpTxInfoStruct[tpChannel].BaseAddress == tpTxInfoStruct[lTpChannel].BaseAddress)
#    endif
                )
#   endif
            /**** NORMAL FIXED ADDRESSING ***************************************/
            /**** MIXED ADDRESSING ***************************************/
            /**** MIXED 11bit ADDRESSING *************************************/
            /**** DYNAMIC NORMAL ADDRESSING *************************************/
#   if defined(TP_ENABLE_NORMAL_ADDRESSING)
#    if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
              if( (tpTxInfoStruct[tpChannel].ReceiveID  == tpTxInfoStruct[lTpChannel].ReceiveID) && (tpTxInfoStruct[tpChannel].ReceiveIDType  == tpTxInfoStruct[lTpChannel].ReceiveIDType)  &&
                  (tpTxInfoStruct[tpChannel].TransmitID == tpTxInfoStruct[lTpChannel].TransmitID)&& (tpTxInfoStruct[tpChannel].TransmitIDType == tpTxInfoStruct[lTpChannel].TransmitIDType) )
#    else
              if( (tpTxInfoStruct[tpChannel].ReceiveID == tpTxInfoStruct[lTpChannel].ReceiveID)  &&
                  (tpTxInfoStruct[tpChannel].TransmitID == tpTxInfoStruct[lTpChannel].TransmitID) )
#    endif
#   endif
            {
              return kTpBusy;
            }
        }
      }
    }
  }
#  endif
# endif

  /*******************************************************************************
  * check and modify state and timer
  *******************************************************************************/
  TpGlobalInterruptDisable();
# if defined  (TP_ENABLE_REQUEST_QUEUE)
  /* Check if the engine is in minimum sending distance */
  if(tpTxState[tpChannel].engine == kTxState_WaitForMinTimer)
  {
    /* trigger automatic retransmission queue */
#  if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
    assertReturnInternal(tpChannel,tpTxState[tpChannel].blocked == 1, kTpTxErrMinTimerIsInconsistent, kTpFailed);
#  endif
    if (tpTxInfoStruct[tpChannel].DataLength != 0xffff)
    { /* Tansmission request already set - ignore this now */
        TpGlobalInterruptRestore();
        return kTpBusy;
    }
  }
  else
# endif
  {
# if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )

    if(tpTxState[tpChannel].engine == kTxState_Idle)
    { /* Channel is not allocated by TpTxGetFreeChannel - return failed */
      TpGlobalInterruptRestore();
      return kTpFailed;
    }
    else
    { /* Channel is allocated */
      if(tpTxState[tpChannel].engine != kTxState_Reserved)
      { /* Transmission in progress - return busy */
        TpGlobalInterruptRestore();
        return kTpBusy;
      }
      else
      { /* No transmission in progress - ready to send */
      }
    }
# else
    if(tpTxState[tpChannel].engine != kTxState_Idle)
    { /* Transmission in progress - return busy  */
      TpGlobalInterruptRestore();
      return kTpBusy;
    }
    else
    { /* No transmission in progress - ready to send */
    }
# endif

#if FBLM_CANFD_SUPPORT
    if((count) <= ((canuint16)(FRAME_CANFD_MAX_REAL_LENGTH - (SF_OFFSET + SF_OFFSET + FORMAT_OFFSET)))) /*Max byte 64 - 2 = 62 byte*/
    { /*(0)1 to 6/7 bytes will be a SingleFrame*/
      tpTxState[tpChannel].engine = kTxState_WaitForSFConfIsr;
    }
    else
    {
      tpTxState[tpChannel].engine = kTxState_WaitForFFConfIsr;
    }

#else /*CAN USED*/
    if((count) <= ((canuint16)(FRAME_LENGTH - (SF_OFFSET + FORMAT_OFFSET))))
    { /*(0)1 to 6/7 bytes will be a SingleFrame*/
      tpTxState[tpChannel].engine = kTxState_WaitForSFConfIsr;
    }
    else
    {
      tpTxState[tpChannel].engine = kTxState_WaitForFFConfIsr;
    }

#endif /*FBLM_CANFD_SUPPORT*/


    tpTxState[tpChannel].Timer = TpTxConfirmationTimeout(tpChannel);
  }

  /*******************************************************************************
  * store parameters
  *******************************************************************************/
  tpTxInfoStruct[tpChannel].DataBufferPtr = ptrData;
  tpTxInfoStruct[tpChannel].DataIndex     = 0;
  tpTxInfoStruct[tpChannel].DataLength    = count;

  /*******************************************************************************
  * start transmission
  *******************************************************************************/
# if defined  (TP_ENABLE_REQUEST_QUEUE)
  /* Check if the engine is in minimum sending distance */
  /* the transmission flag will be set later than */
  if(tpTxState[tpChannel].engine != kTxState_WaitForMinTimer)
# endif
  { /* No ISRlock needed - other parts cannot access other members meanwhile   */
    tpTxState[tpChannel].queued = 1;               /* set transmission request */
  }

# if (defined( TP_ENABLE_MCAN ) || defined ( VGEN_ENABLE_TP_MCAN ))
  tpTxState[tpChannel].WFTCounter = tpTxWFTmax[tpChannel]; /* reset wait frame counter */
# endif

  TpGlobalInterruptRestore();
  return kTpSuccess;
}

/*******************************************************************************
*
* NAME:              TpTask
*
* CALLED BY:         application
* PRECONDITIONS:     Initialized TPMC. This function must not be called outside
*                    of cyclic task context (e.g.: CAN Rx/Tx-Interrupt).
* PARAMETER:         none
* RETURN VALUE:      none
* DESCRIPTION:       Function calls both TpRxTask and TpTxTask in correct order.
*
*******************************************************************************/
void TP_API_CALL_TYPE TpTask(void)
{
  TpRxTask();
  TpTxTask();
}

#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
/*******************************************************************************
*
* NAME:              TpTxAllStateTask
*
* CALLED BY:         application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:      none
* DESCRIPTION:       Handles transmission request
*
*******************************************************************************/
void TP_API_CALL_TYPE TpTxAllStateTask(void)
{
  cansintCPUtype  tpChannel;

  for (tpChannel=(cansintCPUtype)(kTpTxChannelCount-1); tpChannel>=0; tpChannel--)
  {
    __TpTxStateTask(tpChannel);
  }
}
#endif

/*******************************************************************************
*
* NAME:              TpTxStateTask
*
* CALLED BY:
* PRECONDITIONS:
*
* PARAMETER:         Number of current receive tpChannel
* RETURN VALUE:      none
* DESCRIPTION:       Transmit a CAN frame
*
*******************************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpTxStateTask(void)
#else
void TP_API_CALL_TYPE TpTxStateTask(canuint8 tpChannel)
#endif
{
#if (TP_SECURITY_LEVEL > 0)
  tvolatileTpTxState pTpTxState;
#endif
  canuintCPUtype preTransmitResult;
  canuint8 tpCanTxReturn;

#if (TP_SECURITY_LEVEL > 0)
  if(tpStateTaskBusy == 0)
  {
    tpStateTaskBusy = 1;
#endif

    if(tpTxState[tpChannel].retransmit != 0)
    {
#if (TP_SECURITY_LEVEL > 0)
      TpGlobalInterruptDisable();
      pTpTxState = (tvolatileTpTxState) &tpTxState[tpChannel];
      if(pTpTxState->retransmit != 0)
#endif
      {
        tpTxState[tpChannel].retransmit = 0;
#if (TP_SECURITY_LEVEL > 0)
        TpGlobalInterruptRestore();
#endif
#if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && (kTpNumberOfCanChannels > 1) )
        assertInternal(tpChannel, (TP_TX_HANDLE(tpChannel) != kCanTxHandleNotUsed), kTpErrCanChannelNotSupported);
#endif
        tpCanTxReturn = TPCANTRANSMIT(TpIntTxGetCanChannel(tpChannel)) (TP_TX_HANDLE(tpChannel), &PortingData);
        if(tpCanTxReturn == kCanTxOk)
        {
          tpCanTxReturn = FblCanTransmit(&PortingData);
        }
        if (tpCanTxReturn != kCanTxOk)
        {
          /* TpGlobalInterruptDisable(); No ISRlock needed - no other part can access other members while this time */
          tpTxState[tpChannel].retransmit = 1;
          /* TpGlobalInterruptRestore(); */
        }
        else /*When transmit oK, it clear flag*/
        {
          TpLongCanFdTxTransmit = FALSE;
        }
      }
#if (TP_SECURITY_LEVEL > 0)
      else
      {
        TpGlobalInterruptRestore();
      }
#endif
    }
    else
    {
      if (tpTxState[tpChannel].queued != 0)
      {
#if (TP_SECURITY_LEVEL > 0)
        TpGlobalInterruptDisable();
        /* Verify previous check, if meanwhile (after ISR lock) the queue flag is removed */
        pTpTxState = (tvolatileTpTxState) &tpTxState[tpChannel];
        if(pTpTxState->queued != 0)
#endif
        { /* Is transmission semaphore free ? */
          TpIntTxTransmitChannel_IsFree(tpChannel) /* if statement */
          { /* It is ! */
            TpIntTxTransmitChannel_SetLock(tpChannel);

            tpTxState[tpChannel].queued = 0;
            /* Copy Data to Buffer */
            preTransmitResult = __TpTxPreCanTransmit(tpChannel);
            if (preTransmitResult == kTpSuccess)
            {
#if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && (kTpNumberOfCanChannels > 1) )
              assertInternal(tpChannel, (TP_TX_HANDLE(tpChannel) != kCanTxHandleNotUsed), kTpErrCanChannelNotSupported);
#endif

              TPTXSETID(tpChannel);
              TP_TX_PRE_CANTRANSMIT(tpChannel);
              tpCanTxReturn = TPCANTRANSMIT(TpIntTxGetCanChannel(tpChannel)) (TP_TX_HANDLE(tpChannel), &PortingData);
              if(tpCanTxReturn == kCanTxOk)
              {
                tpCanTxReturn = FblCanTransmit(&PortingData);
              }
#if (TP_SECURITY_LEVEL > 0)
              TpGlobalInterruptRestore();
#endif
              if (tpCanTxReturn != kCanTxOk)
              {
                /* TpGlobalInterruptDisable(); No ISRlock needed - no other part can access other members while this time */
                tpTxState[tpChannel].retransmit = 1;
              }
              else  /*when cantransmit ok, it clear flag*/
              {
                TpLongCanFdTxTransmit = FALSE;
              }
            }
            else
            {
#if (TP_USE_CUSTOM_TX_MEMCPY == kTpOn)
              /* A buffer underrun has happened - restore index for First/Consecutive Frames
                 Only if ApplTpTxCopyToCan function is used,
                 otherwise a linear copy mechanism is used (no buffer-underrun can happen)   */
              if ((tpTxState[tpChannel].engine == kTxState_WaitForCFConfIsr)     ||
                  (tpTxState[tpChannel].engine == kTxState_WaitForLastCFConfIsr) ||
                  (tpTxState[tpChannel].engine == kTxState_WaitForFFConfIsr)
                 )
              {
                if(tpTxState[tpChannel].engine == kTxState_WaitForFFConfIsr)
                {
                  tpTxInfoStruct[tpChannel].DataIndex = 0;
                }
                else
                {
                  tpTxInfoStruct[tpChannel].DataIndex = (tpTxInfoStruct[tpChannel].DataIndex) - (canuint16)(FRAME_LENGTH - (CF_OFFSET + FORMAT_OFFSET));
                }
              }
#endif
              /* A buffer underrun has happened - restore transmit path and set queue flag again */
              TpIntTxTransmitChannel_SetFree(tpChannel);
              tpTxState[tpChannel].queued = 1;
#if (TP_SECURITY_LEVEL > 0)
              TpGlobalInterruptRestore();
#endif
            }
          }
#if (defined (TP_ENABLE_SINGLE_MSG_OBJ) || (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) ))
          else
          {
# if (TP_SECURITY_LEVEL > 0)
            TpGlobalInterruptRestore();
# endif
          }
#endif
        }
#if (TP_SECURITY_LEVEL > 0)
        else
        {
          TpGlobalInterruptRestore();
        }
#endif
      }
    }
# if (TP_SECURITY_LEVEL > 0)
    tpStateTaskBusy = 0;
  }
# endif
}

#if (defined( TP_ENABLE_MF_RECEPTION ) || defined (TP_ENABLE_SF_ACKNOWLEDGE))
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
# else
/*******************************************************************************
*
* NAME:              TpRxAllStateTask
*
* CALLED BY:         application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:      none
* DESCRIPTION:       Handles transmission request
*
*******************************************************************************/
void TP_API_CALL_TYPE TpRxAllStateTask(void)
{
  cansintCPUtype  tpChannel;

  for (tpChannel=(cansintCPUtype)(kTpRxChannelCount-1); tpChannel>=0; tpChannel--)
  {
    __TpRxStateTask(tpChannel);
  }
}
# endif

/*******************************************************************************
*
* NAME:              TpRxStateTask
*
* CALLED BY:         Transport Layer (TpReceive)
* PRECONDITIONS:
*
* PARAMETER:         Number of current receive tpChannel
* RETURN VALUE:      none
* DESCRIPTION:       Transmit a CAN frame
*
*******************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpRxStateTask(void)
# else
void TP_API_CALL_TYPE TpRxStateTask(canuint8 tpChannel)
# endif
{
  tvolatileTpRxState pTpRxState;

  canuint8 tpCanTxReturn;
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertInternal(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
# endif

# if (TP_SECURITY_LEVEL > 0)
  if(tpStateTaskBusy == 0)
  {
    tpStateTaskBusy = 1;
# endif

    if(tpRxState[tpChannel].retransmit != 0)
    {
# if (TP_SECURITY_LEVEL > 0)
      TpGlobalInterruptDisable();
      pTpRxState = (tvolatileTpRxState) &tpRxState[tpChannel];
      if(pTpRxState->retransmit != 0)
# endif
      {
        tpRxState[tpChannel].retransmit = 0;
        TpGlobalInterruptRestore();
# if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && (kTpNumberOfCanChannels > 1) )
        assertInternal(tpChannel, (TP_RX_HANDLE(tpChannel) != kCanTxHandleNotUsed), kTpErrCanChannelNotSupported);
# endif
        tpCanTxReturn = TPCANTRANSMIT(TpIntRxGetCanChannel(tpChannel)) (TP_RX_HANDLE(tpChannel), &PortingData);
        if(tpCanTxReturn == kCanTxOk)
        {
          tpCanTxReturn = FblCanTransmit(&PortingData);
        }
        if ( tpCanTxReturn != kCanTxOk )
        {
          /* TpGlobalInterruptDisable(); No ISRlock needed - no other part can access other members while this time */
          tpRxState[tpChannel].retransmit = 1;
          /* TpGlobalInterruptRestore(); */
        }
      }
# if (TP_SECURITY_LEVEL > 0)
      else
      {
        TpGlobalInterruptRestore();
      }
# endif
    }
    else
    {
      if (tpRxState[tpChannel].queued != 0)
      {
# if (TP_SECURITY_LEVEL > 0)
        TpGlobalInterruptDisable();
        pTpRxState = (tvolatileTpRxState)&tpRxState[tpChannel];
        if(pTpRxState->queued != 0)
# endif
        {
#  if defined (TP_ENABLE_ISO_15765_2_2)
          assertInternal(tpChannel, ((tpRxState[tpChannel].engine == kRxState_WaitForFCConfIsr) \
                                    ||(tpRxState[tpChannel].engine == kRxState_WaitForFCOverConfIsr) \
                                    ), kTpErrChannelNotInUse);
#  endif

# if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
          assertInternal(tpChannel, (tpRxInfoStruct[tpChannel].withoutFC == 0), kTpErrChannelNotInUse);
# endif
          TpIntRxTransmitChannel_IsFree(tpChannel)
          {
            TpIntRxTransmitChannel_SetLock(tpChannel);
            tpRxState[tpChannel].queued = 0;

            /* Copy Data to Buffer */

            /*-----------------------------------------------------------------------------
            | NAME:              AssembleFC
            | DESCRIPTION:       Assemble a FlowControl Frame
            -----------------------------------------------------------------------------*/
# if defined (TP_ENABLE_EXTENDED_ADDRESSING)
            {
              TpCanTxFCDataPtr(tpChannel)[TARGET_OFFSET] = (canuint8)tpRxInfoStruct[tpChannel].SourceAddress;
            }
# endif
# if defined(TP_ENABLE_NORMAL_MIXED11_ADDRESSING)
#   if defined (TP_ENABLE_NORMAL_MIXED11_ADDRESSING)
            if(TpAddressingFormatOffset[tpChannel] == 1)
#   endif
            {
              TpCanTxFCDataPtr(tpChannel)[ADDRESS_EXTENSION_OFFSET] = (canuint8)tpRxInfoStruct[tpChannel].AddressExtension;
            }
# endif

# if  (TP_USE_PADDING == kTpOn )
#   if defined (TP_ENABLE_NORMAL_MIXED11_ADDRESSING)
            if(TpAddressingFormatOffset[tpChannel] == 0)
#   endif
            {
              /* Just for a fine look of the flow control message... */
              TpCanTxFCDataPtr(tpChannel)[3] = TP_PADDING_PATTERN;
            }
            /* Just for a fine look of the flow control message... */
            TpCanTxFCDataPtr(tpChannel)[4] = TP_PADDING_PATTERN;
            TpCanTxFCDataPtr(tpChannel)[5] = TP_PADDING_PATTERN;
            TpCanTxFCDataPtr(tpChannel)[6] = TP_PADDING_PATTERN;
            TpCanTxFCDataPtr(tpChannel)[7] = TP_PADDING_PATTERN;
# endif

# if defined (TP_ENABLE_VARIABLE_DLC)
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
            TPCANDYNTXOBJSETDLC(TpIntRxGetCanChannel(tpChannel)) ((CanTransmitHandle)(TP_RX_INIT_HANDLE(TpIntRxGetCanChannel(tpChannel))), (FC_LENGTH + FORMAT_OFFSET));
#  endif
# endif

# if defined (TP_ENABLE_ISO_15765_2_2)
            if (tpRxState[tpChannel].engine == kRxState_WaitForFCOverConfIsr)
            {
              TpCanTxFCDataPtr(tpChannel)[ (TPCI_OFFSET + FORMAT_OFFSET) ]  = kL4_FlowStatus_Overrun;
            }
            else
# endif
            {
              {

# if defined (TP_ENABLE_FC_WAIT)
                if (tpRxInfoStruct[tpChannel].ApplGetBufferStatus == kTpFCStatusWait)
                { /* currently in status wait */
                  TpCanTxFCDataPtr(tpChannel)[ (TPCI_OFFSET + FORMAT_OFFSET) ]  = kL4_FlowStatus_Wait;
                }
                else
                { /* normal clear to send state */
                  TpCanTxFCDataPtr(tpChannel)[ (TPCI_OFFSET + FORMAT_OFFSET) ]  = kL4_FlowControl;
                }
# else
                TpCanTxFCDataPtr(tpChannel)[ (TPCI_OFFSET + FORMAT_OFFSET) ]    = kL4_FlowControl;
# endif

              }
            }
            {
              TpCanTxFCDataPtr(tpChannel)[(BS_OFFSET + FORMAT_OFFSET)]    = TpRxGetBlockSize(tpChannel);
              TpCanTxFCDataPtr(tpChannel)[(STMIN_OFFSET + FORMAT_OFFSET)] = TpRxGetSTMINtime(tpChannel);

              TpRxReloadBSCnt(tpChannel);
            }
# if (defined( TP_ENABLE_DYNAMIC_CHANNELS) && (kTpNumberOfCanChannels > 1) )
            assertInternal(tpChannel, (TP_RX_HANDLE(tpChannel) != kCanTxHandleNotUsed), kTpErrCanChannelNotSupported);
# endif
            TPRXSETID(tpChannel);
            TP_RX_PRE_CANTRANSMIT(tpChannel);
            tpCanTxReturn = ((TPCANTRANSMIT(TpIntRxGetCanChannel(tpChannel))) (TP_RX_HANDLE(tpChannel), &PortingData));
            if(tpCanTxReturn == kCanTxOk)
            {
              tpCanTxReturn = FblCanTransmit(&PortingData);
            }

            if ( tpCanTxReturn != kCanTxOk )
            {
              /* TpGlobalInterruptDisable(); No ISRlock needed - no other part can access other members while this time */
              tpRxState[tpChannel].retransmit = 1;
            }
# if (TP_SECURITY_LEVEL > 0)
            TpGlobalInterruptRestore();
# endif
          }
# if (defined (TP_ENABLE_SINGLE_MSG_OBJ) || (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) ))
          else
          {
#  if (TP_SECURITY_LEVEL > 0)
            TpGlobalInterruptRestore();
#  endif
          }
# endif
        }
# if (TP_SECURITY_LEVEL > 0)
        else
        {
          TpGlobalInterruptRestore();
        }
# endif
      }
    }
# if (TP_SECURITY_LEVEL > 0)
    tpStateTaskBusy = 0;
  }
# endif
} /* TpRxStateTask */
#endif  /* defined( TP_ENABLE_MF_RECEPTION ) || defined (TP_ENABLE_SF_ACKNOWLEDGE) */

/*******************************************************************************
*
* NAME:              TpTxPreCanTransmit
*
* CALLED BY:         TpTxStateTask
* PRECONDITIONS:     PreTransmit functions are configured
*
* PARAMETER:         Pointer to CAN Buffer
* RETURN VALUE:      canuintCPUtype rc
* DESCRIPTION:       Copy Data to CAN
*
*******************************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
static canuintCPUtype TpTxPreCanTransmit(void)
#else
static canuintCPUtype TpTxPreCanTransmit(canuintCPUtype tpChannel)
#endif
{
  tTpCopyToCanInfoStruct  tpCopyToCanInfoStruct;

#if (TP_USE_PADDING == kTpOff) && (TP_USE_CUSTOM_TX_MEMCPY == kTpOn)
#else
  canuintCPUtype i;
#endif
#if (TP_USE_CUSTOM_TX_MEMCPY == kTpOn)
  canuintCPUtype rc;
#endif
#if  (TP_USE_PADDING == kTpOn )
  canuintCPUtype offset;
  offset = 0;
#endif


#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
  tpCopyToCanInfoStruct.Channel = (canuint8)tpChannel;
#endif
  tpCopyToCanInfoStruct.pSource = &tpTxInfoStruct[tpChannel].DataBufferPtr[tpTxInfoStruct[tpChannel].DataIndex];

  switch(tpTxState[tpChannel].engine)
  {
  case kTxState_WaitForSFConfIsr:
    /*-----------------------------------------------------------------------------*/
    /* NAME:              TpAssembleSF / SingleFrame                               */
    /* DESCRIPTION:       Assemble a Transmit SingleFrame                          */
    /*-----------------------------------------------------------------------------*/
#if FBLM_CANFD_SUPPORT
	if(((canuint8)(tpTxInfoStruct[tpChannel].DataLength)) <= FRAME_LENGTH)
	{
	    TpCanTxDataPtr(tpChannel)[(TPCI_OFFSET + FORMAT_OFFSET)] = (canuint8)(tpTxInfoStruct[tpChannel].DataLength); /*kL4_SingleFrame TPCI is 0x00*/
	#if  (TP_USE_PADDING == kTpOn )
	    offset = SF_OFFSET;
	#endif
	}
	else  /*When Dlc of CANFD is more than 8 byte*/
	{
	    TpCanTxDataPtr(tpChannel)[(TPCI_OFFSET + FORMAT_OFFSET)] = (canuint8)0; /*kL4_SingleFrame  TPCI Fix is 0x00*/
	    TpCanTxDataPtr(tpChannel)[(SF_OFFSET + TPCI_OFFSET + FORMAT_OFFSET)] = (canuint8)(tpTxInfoStruct[tpChannel].DataLength); /*kL4_SingleFrame TPCI is 0x00*/
	#if  (TP_USE_PADDING == kTpOn )
	    offset = SF_OFFSET + SF_OFFSET;
	#endif
      tpTxInfoStruct[tpChannel].DataLength += 2;
	    TpLongCanFdTxTransmit = TRUE;
	}

#else  /*CAN USED */
    TpCanTxDataPtr(tpChannel)[(TPCI_OFFSET + FORMAT_OFFSET)] = (canuint8)(tpTxInfoStruct[tpChannel].DataLength); /*kL4_SingleFrame TPCI is 0x00*/
#if  (TP_USE_PADDING == kTpOn )
    offset = SF_OFFSET;
#endif 

#endif /*FBLM_CANFD_SUPPORT*/

    tpCopyToCanInfoStruct.pDestination  = (TxDataPtr)(&(TpCanTxDataPtr(tpChannel)[(offset + FORMAT_OFFSET)]));
    tpCopyToCanInfoStruct.Length        = tpTxInfoStruct[tpChannel].DataLength;
#if defined (TP_ENABLE_VARIABLE_DLC)
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
    TPCANDYNTXOBJSETDLC(TpIntTxGetCanChannel(tpChannel)) ((CanTransmitHandle)(TP_TX_INIT_HANDLE(TpIntTxGetCanChannel(tpChannel))), (SF_OFFSET + FORMAT_OFFSET + tpTxInfoStruct[tpChannel].DataLength));
# else
    tpTxInfoStruct[tpChannel].CurrentTpCanDLC = CANBITTYPE_CAST(SF_OFFSET + FORMAT_OFFSET + tpTxInfoStruct[tpChannel].DataLength);
# endif
#endif

    break;
  case kTxState_WaitForFFConfIsr:
  /*-----------------------------------------------------------------------------
  | NAME:              TpAssembleFF
  | DESCRIPTION:       Assemble a Transmit Frame
    -----------------------------------------------------------------------------*/
#if (TP_USE_TX_CHANNEL_WITHOUT_FC == kTpOn)
# if (TP_USE_WITHOUT_FC_TPCI_ADDON == kTpOn)
    if(tpTxInfoStruct[tpChannel].withoutFC == 1)
    {
      TpCanTxDataPtr(tpChannel)[(TPCI_OFFSET + FORMAT_OFFSET)]  = (canuint8)kL4_FirstFrameWithoutFC;
    }
    else
# endif
#endif
    {
      TpCanTxDataPtr(tpChannel)[(TPCI_OFFSET + FORMAT_OFFSET)] = (canuint8)kL4_FirstFrame;
    }
    TpCanTxDataPtr(tpChannel)[(TPCI_OFFSET + FORMAT_OFFSET)] |= (canuint8)((tpTxInfoStruct[tpChannel].DataLength & 0x0F00)>>8);
    TpCanTxDataPtr(tpChannel)[(DL_OFFSET   + FORMAT_OFFSET)]  = (canuint8)( tpTxInfoStruct[tpChannel].DataLength & 0x00FF);

#if  (TP_USE_PADDING == kTpOn )
    offset = FF_OFFSET;
#endif

    tpCopyToCanInfoStruct.pDestination = (TxDataPtr)(&(TpCanTxDataPtr(tpChannel)[(FF_OFFSET + FORMAT_OFFSET)]));
#if FBLM_CANFD_SUPPORT
    tpCopyToCanInfoStruct.Length       = (canuint16)(FRAME_CANFD_MAX_REAL_LENGTH - (FF_OFFSET + FORMAT_OFFSET));
    tpTxInfoStruct[tpChannel].DataIndex = (canuint16)(FRAME_CANFD_MAX_REAL_LENGTH - (FF_OFFSET + FORMAT_OFFSET));    /*Set tx index to next free data element*/
    TpLongCanFdTxTransmit = TRUE; /*Due to that it must be more than 64 byte*/
#else
    tpCopyToCanInfoStruct.Length       = (canuint16)(FRAME_LENGTH - (FF_OFFSET + FORMAT_OFFSET));
    tpTxInfoStruct[tpChannel].DataIndex = (canuint16)(FRAME_LENGTH - (FF_OFFSET + FORMAT_OFFSET));    /*Set tx index to next free data element*/

#endif


    #if defined (TP_ENABLE_VARIABLE_DLC)
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
    TPCANDYNTXOBJSETDLC(TpIntTxGetCanChannel(tpChannel)) ((CanTransmitHandle)(TP_TX_INIT_HANDLE(TpIntTxGetCanChannel(tpChannel))), (FRAME_LENGTH));
# else
    tpTxInfoStruct[tpChannel].CurrentTpCanDLC = CANBITTYPE_CAST(FRAME_LENGTH);
# endif
#endif
    tpTxInfoStruct[tpChannel].sequencenumber = 0;   /*SN set to zero*/
    tpTxState[tpChannel].BSCounter = 0;   /*Neccessary for correct setting of next state kTxState_WaitFC*/
    break;
  /*-----------------------------------------------------------------------------
  | NAME:              TpAssembleCF
  | DESCRIPTION:       Assemble a Transmit Frame
    -----------------------------------------------------------------------------*/
  case kTxState_WaitForLastCFConfIsr:
    /* no break */
  case kTxState_WaitForCFConfIsr:
#if (TP_USE_TX_CHANNEL_WITHOUT_FC == kTpOn)
# if (TP_USE_WITHOUT_FC_TPCI_ADDON == kTpOn)
    if(tpTxInfoStruct[tpChannel].withoutFC == 1)
    {
      TpCanTxDataPtr(tpChannel)[(TPCI_OFFSET + FORMAT_OFFSET)]  = (canuint8)kL4_ConsecutiveFrameWithoutFC;
    }
    else
# endif
#endif
    {
      TpCanTxDataPtr(tpChannel)[(TPCI_OFFSET + FORMAT_OFFSET)] = (canuint8)kL4_ConsecutiveFrame;
    }
    TpCanTxDataPtr(tpChannel)[(TPCI_OFFSET + FORMAT_OFFSET)] |= (canuint8)tpTxInfoStruct[tpChannel].sequencenumber;
#if  (TP_USE_PADDING == kTpOn )
    offset = CF_OFFSET;
#endif
    tpCopyToCanInfoStruct.pDestination = (TxDataPtr)(&(TpCanTxDataPtr(tpChannel)[(CF_OFFSET + FORMAT_OFFSET)]));
    TpLongCanFdTxTransmit = TRUE; /*Even case, it reponse the longest lenght*/
    if (tpTxState[tpChannel].engine == kTxState_WaitForLastCFConfIsr)
    {
      tpCopyToCanInfoStruct.Length = (canuint16)(tpTxInfoStruct[tpChannel].DataLength-tpTxInfoStruct[tpChannel].DataIndex);
#if defined (TP_ENABLE_VARIABLE_DLC)
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
      TPCANDYNTXOBJSETDLC(TpIntTxGetCanChannel(tpChannel)) ((CanTransmitHandle)(TP_TX_INIT_HANDLE(TpIntTxGetCanChannel(tpChannel))), (CF_OFFSET + FORMAT_OFFSET + tpCopyToCanInfoStruct.Length));
# else
      tpTxInfoStruct[tpChannel].CurrentTpCanDLC = CANBITTYPE_CAST(CF_OFFSET + FORMAT_OFFSET + tpCopyToCanInfoStruct.Length);
# endif
#endif
    }
    else
    {
#if FBLM_CANFD_SUPPORT
      tpCopyToCanInfoStruct.Length = (canuint16)(FRAME_CANFD_MAX_REAL_LENGTH - (CF_OFFSET + FORMAT_OFFSET));
#else /*CAN USED*/
      tpCopyToCanInfoStruct.Length = (canuint16)(FRAME_LENGTH - (CF_OFFSET + FORMAT_OFFSET));
#endif /*FBLM_CANFD_SUPPORT*/

#if defined (TP_ENABLE_VARIABLE_DLC)
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
      TPCANDYNTXOBJSETDLC(TpIntTxGetCanChannel(tpChannel)) ((CanTransmitHandle)(TP_TX_INIT_HANDLE(TpIntTxGetCanChannel(tpChannel))), (FRAME_LENGTH));
# else
      tpTxInfoStruct[tpChannel].CurrentTpCanDLC = CANBITTYPE_CAST(FRAME_LENGTH);
# endif
#endif
    }
#if FBLM_CANFD_SUPPORT
    tpTxInfoStruct[tpChannel].DataIndex = tpTxInfoStruct[tpChannel].DataIndex + (canuint16)(FRAME_CANFD_MAX_REAL_LENGTH - (CF_OFFSET + FORMAT_OFFSET));   /*Set tx index to next free data element*/
#else /*CAN USED*/
    tpTxInfoStruct[tpChannel].DataIndex = tpTxInfoStruct[tpChannel].DataIndex + (canuint16)(FRAME_LENGTH - (CF_OFFSET + FORMAT_OFFSET));   /*Set tx index to next free data element*/
#endif /*FBLM_CANFD_SUPPORT*/

    break;
  default: /* Nothing to do */
    /* Call everytime assertion */
    assertGeneral(tpChannel, kTpTxErrWrongFrameAtPretransmitSpecified);
    return kTpFailed; /* do not proceed with wrong state */
    /* break; */
  }  /* end of switch state */

#if defined(TP_ENABLE_EXTENDED_ADDRESSING)
  {
    TpCanTxDataPtr(tpChannel)[TARGET_OFFSET] = tpTxInfoStruct[tpChannel].TargetAddress;
  }
#endif

#if (TP_USE_CUSTOM_TX_MEMCPY == kTpOff)
# if  (TP_USE_PADDING == kTpOn )

#if FBLM_CANFD_SUPPORT
  if(TRUE == TpLongCanFdTxTransmit)
  {
	for (i=0; i<(FRAME_CANFD_MAX_REAL_LENGTH-(offset + FORMAT_OFFSET)); i++)
	{
	  if(tpCopyToCanInfoStruct.Length == 0)
	  {
	    *(tpCopyToCanInfoStruct.pDestination + i) = TP_PADDING_PATTERN;
	  }
	  else
	  {
	    tpCopyToCanInfoStruct.Length--;
	    *(tpCopyToCanInfoStruct.pDestination + i) = *(tpCopyToCanInfoStruct.pSource + i);
	  }
	}
  }
  else
  {
	for (i=0; i<(FRAME_LENGTH-(offset + FORMAT_OFFSET)); i++)
	{
	  if(tpCopyToCanInfoStruct.Length == 0)
	  {
	    *(tpCopyToCanInfoStruct.pDestination + i) = TP_PADDING_PATTERN;
	  }
	  else
	  {
	    tpCopyToCanInfoStruct.Length--;
	    *(tpCopyToCanInfoStruct.pDestination + i) = *(tpCopyToCanInfoStruct.pSource + i);
	  }
	}
  }
#else /*CAN USED*/
  for (i=0; i<(FRAME_LENGTH-(offset + FORMAT_OFFSET)); i++)
  {
    if(tpCopyToCanInfoStruct.Length == 0)
    {
      *(tpCopyToCanInfoStruct.pDestination + i) = TP_PADDING_PATTERN;
    }
    else
    {
      tpCopyToCanInfoStruct.Length--;
      *(tpCopyToCanInfoStruct.pDestination + i) = *(tpCopyToCanInfoStruct.pSource + i);
    }
  }

#endif /*FBLM_CANFD_SUPPORT*/


# else
  for (i=0; i<(tpCopyToCanInfoStruct.Length); i++)
  {
    *(tpCopyToCanInfoStruct.pDestination + i) = *(tpCopyToCanInfoStruct.pSource + i);
  }
# endif
  return kTpSuccess;
#else
  rc = __ApplTpTxCopyToCAN(&tpCopyToCanInfoStruct);
# if  (TP_USE_PADDING == kTpOn )
  i = CANUINTCPUTYPE_CAST(tpCopyToCanInfoStruct.Length  + offset + FORMAT_OFFSET);
  while (FRAME_LENGTH > i)
  {
    TpCanTxDataPtr(tpChannel)[i] = TP_PADDING_PATTERN;
    i++;
  }
# endif
  return rc;
#endif

} /* TpTxPreCanTransmit */

/*******************************************************************************
*
* NAME:              TpDrvTxPreTransmit
*
* CALLED BY:         CanDriver
* PRECONDITIONS:     PreTransmit functions are configured
*
* PARAMETER:         Connection, Pointer to CAN Buffer
* RETURN VALUE:      none
* DESCRIPTION:       Copy DLC to CAN
*
*******************************************************************************/
#if defined (TP_ENABLE_VARIABLE_DLC)
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# else
#  if defined (TP_ENABLE_SINGLE_MSG_OBJ) /* Geny */
#   if defined(C_MULTIPLE_RECEIVE_CHANNEL) || defined(C_SINGLE_RECEIVE_CHANNEL)
#    if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_INTERNAL_CALL_TYPE TpTxPreTransmit(CanTxInfoStruct txStruct)
#    else
canuint8 TP_INTERNAL_CALL_TYPE TpDrvTxPreTransmit(vuintx tpChannel, CanTxInfoStruct txStruct)
#    endif
{ /* TP tx or rx message? */
  TpIntTxTransmitChannel_IsTx(tpChannel)
  { /* tx: SF,FF,CF */
    CanTxWriteActDLC(txStruct,tpTxInfoStruct[tpChannel].CurrentTpCanDLC);
  }
  else
  { /* rx: FC */
    CanTxWriteActDLC(txStruct,(FC_LENGTH + FORMAT_OFFSET)); /* FORMAT_OFFSET conflicts multiple addressing */
  }
  return kCanCopyData;
}
#   else
#    if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_INTERNAL_CALL_TYPE TpTxPreTransmit(CanChipDataPtr txDataPtr)
#    else
canuint8 TP_INTERNAL_CALL_TYPE TpDrvTxPreTransmit(vuintx tpChannel, CanChipDataPtr txDataPtr)
#    endif
{
  TpIntTxTransmitChannel_IsTx(tpChannel)
  { /* tx: SF,FF,CF */
    CanTxWriteActDLC(txDataPtr,tpTxInfoStruct[tpChannel].CurrentTpCanDLC);
  }
  else
  { /* rx: FC */
    CanTxWriteActDLC(txDataPtr,(FC_LENGTH + FORMAT_OFFSET));
  }
  return kCanCopyData;
}
#   endif
#  endif
# endif
#endif


#if defined (TP_ENABLE_SINGLE_MSG_OBJ)
/*******************************************************************************
*
* NAME:              TpDrvConfirmation
*
* CALLED BY:         Confirmation Interrupt
* PRECONDITIONS:     Confirmation interrupts are configured
*
* PARAMETER:         Handle of message to be confirmed
* RETURN VALUE:      none
* DESCRIPTION:       Inform application and start timeout counter
*
*******************************************************************************/
void TP_INTERNAL_CALL_TYPE TpDrvConfirmation(CanTransmitHandle txObject)
{
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
# if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)txObject;
# endif
#else
  /*** Multi TP ***/
  canuintCPUtype tpChannel;

# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL)
#   if (kTpNumberOfCanChannels > 1)
  cansintCPUtype  canChannel;

  for (canChannel=(cansintCPUtype)(kCanNumberOfChannels-1); canChannel>=0; canChannel--)
  {
    if (txObject == kTpTxHandle_Field[canChannel])
    {
      break;
    }
  }
  assertInternal(kTpNoChannel, canChannel>=0, kTpErrNoCanChannelFound);
#   endif
#  endif
#  if defined (TP_CAN_CODEDOUBLED)
#  else
#   if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)txObject;
#   endif
#  endif
# endif


# if defined(TP_ENABLE_DYNAMIC_CHANNELS)
  tpChannel = CANUINTCPUTYPE_CAST(tpTransmitChannel[canChannel] & kTpChannelMask); /* ~0x80 to mask out the Tx/Rx Flag -> result is the pure tpChannel */
# else
  /* Only static normal addressing Multi TP */
  tpChannel = TpTxHandleToChannel[txObject];
# endif

#endif


#if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
  if ((tpTransmitChannel[canChannel] & kTpRxChannelMask) == kTpTxChannel)
#else
  TpIntTxTransmitChannel_IsTx(tpChannel)
#endif
  {
    __TpTxPostProcessing(tpChannel);
  }
  else
  {
#if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
    assertInternal(tpChannel, ((TpIntRxTransmitChannel(tpChannel) != kTpNoChannel) && ((TpIntRxTransmitChannel(tpChannel) & kTpRxChannelMask) == kTpRxChannel)), kTpRxErrInconsistentSemaphore)
#else
    assertInternal(tpChannel, (TpIntRxTransmitChannel(tpChannel) == kTpRxChannel), kTpRxErrInconsistentSemaphore)
#endif
#if (defined( TP_ENABLE_MF_RECEPTION ) || defined(TP_ENABLE_SF_ACKNOWLEDGE) )
# if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
    assertInternal(tpChannel, (tpRxInfoStruct[tpChannel].withoutFC == 0), kTpErrChannelNotInUse);
# endif
    __TpRxPostProcessing(tpChannel);
#endif
  }
#if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
# if(TP_USE_QUEUE_IN_ISR == kTpOn)
  /* Is transmit object in Queue ? */
# if (defined( TP_ENABLE_MF_RECEPTION ) || defined(TP_ENABLE_SF_ACKNOWLEDGE) )
  TpRxAllStateTask();
# endif
  TpTxAllStateTask();
# endif
#endif
}
#endif

#if defined (TP_ENABLE_SINGLE_MSG_OBJ)
#endif

#if defined (TP_ENABLE_SINGLE_MSG_OBJ)
#endif

/*******************************************************************************
*
* NAME:              TpTxPostProcessing
*
* CALLED BY:         Confirmation Interrupt
* PRECONDITIONS:     Confirmation interrupts are configured
*
* PARAMETER:         -
* RETURN VALUE:      none
* DESCRIPTION:       Inform application and start timeout counter
*
*******************************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
static void TP_INTERNAL_INLINE TpTxPostProcessing(void)
#else
static void TP_INTERNAL_INLINE TpTxPostProcessing(canuintCPUtype tpChannel)
#endif
{
#if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertInternal(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
#endif
#if defined (TP_TEST_ROUTINE_CONF_TIMEOUT)
  if (TpTestTxCheckForcingConfTimeout())
#endif
  {

    /* Do Tx confirmation stuff */
    switch(tpTxState[tpChannel].engine)
    {
      /*-----------------------------------------------------------------------------
      | SingleFrame
      -----------------------------------------------------------------------------*/
    case kTxState_WaitForSFConfIsr:
      /* Same as "kTxState_WaitForLastCFConfIsr" */
      /*-----------------------------------------------------------------------------
      | LastConsecutiveFrame
      -----------------------------------------------------------------------------*/
    case kTxState_WaitForLastCFConfIsr:
      assertInternal(tpChannel, tpTxState[tpChannel].queued == 0, kTpTxErrTxFlagsInconsitent);
      assertInternal(tpChannel, tpTxState[tpChannel].retransmit == 0, kTpTxErrTxFlagsInconsitent);
      {
        /* Callback - */
        __ApplTpTxConfirmation((canuint8)tpChannel, kTpSuccess);
        /* Reset tpChannel after callback to get access to the connection */

#if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
        if (tpTxState[tpChannel].blocked == 0)
#endif
        {
#if ((defined(TP_ENABLE_MIN_TIMER) ) && (!defined( TP_ENABLE_DYNAMIC_CHANNELS)))
          /* static tpChannels and MinTimer feature is activated */
# if defined( kTpTxMinTimer ) /* global reload value */
          tpTxState[tpChannel].Timer  = kTpTxMinTimer;
# else /* channel specific reload value defined */
          tpTxState[tpChannel].Timer  = TpTxMinTimer[tpChannel];
# endif
          tpTxState[tpChannel].engine = kTxState_WaitForMinTimer;
#else
          /* static tpChannels and MinTimer feature is in-active */
          /* or dynamic and not locked tpChannel */
          tpTxState[tpChannel].Timer      = 0;
          tpTxState[tpChannel].engine     = kTxState_Idle;
#endif
        }
#if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
        else
        { /* dynamic and locked tpChannel */
# if (defined(TP_ENABLE_MIN_TIMER) )
#  if defined( kTpTxMinTimer ) /* global reload value */
          tpTxState[tpChannel].Timer  = kTpTxMinTimer;
#  else /* channel specific reload value defined */
          tpTxState[tpChannel].Timer  = TpTxMinTimer[tpChannnel];
#  endif
          tpTxState[tpChannel].engine = kTxState_WaitForMinTimer;
# else /* case for kTpTxMinTimer != 0 */
          tpTxState[tpChannel].Timer  = 0;
          tpTxState[tpChannel].engine = kTxState_Reserved;
# endif
        }
#endif
#if defined  (TP_ENABLE_REQUEST_QUEUE)
        tpTxInfoStruct[tpChannel].DataLength = 0xffff;
#endif
      }
      break;
      /*-----------------------------------------------------------------------------
      | FirstFrame
      -----------------------------------------------------------------------------*/
    case kTxState_WaitForFFConfIsr:
#if (TP_USE_TX_CHANNEL_WITHOUT_FC == kTpOn)
      if(tpTxInfoStruct[tpChannel].withoutFC == 0)
#endif
      {
        tpTxState[tpChannel].Timer = kTimeoutFC(tpChannel);
        tpTxState[tpChannel].engine = kTxState_WaitFC;

#if (TP_USE_ONLY_FIRST_FC == kTpOn)
        tpTxState[tpChannel].firstFC = 0; /* Calculate BS/STmin only out of the first received FC */
#endif
      }
#if (TP_USE_TX_CHANNEL_WITHOUT_FC == kTpOn)
      else
      {
        /* setting BSCounter to zero to avoid further FlowControls */
        tpTxState[tpChannel].BSCounter = 0;
        tpTxState[tpChannel].Timer = TpTxGetSTMINtime(tpChannel);
        tpTxState[tpChannel].engine = kTxState_WaitForTpTxCF;
      }
#endif
      /* Callback - */
      __ApplTpTxNotification((canuint8)tpChannel, (canuint8)(FRAME_LENGTH - (FF_OFFSET + FORMAT_OFFSET)));
      break;
      /*-----------------------------------------------------------------------------
      | ConsecutiveFrame
      -----------------------------------------------------------------------------*/
    case kTxState_WaitForCFConfIsr:
      /* Callback - */
      __ApplTpTxNotification((canuint8)tpChannel, (canuint8)(FRAME_LENGTH - (CF_OFFSET + FORMAT_OFFSET)));

      /* No special check for channels without FlowControl */
      /* If BS == 0 - no FlowControl frames shall be await */
      if(tpTxState[tpChannel].BSCounter != 0)
      {
        tpTxState[tpChannel].BSCounter--;
        if(tpTxState[tpChannel].BSCounter == 0)
        { /*Check for FC of counterpart now */
          tpTxState[tpChannel].Timer = kTimeoutFC(tpChannel);
          tpTxState[tpChannel].engine = kTxState_WaitFC;
          break;
        }
      }
      {
        tpTxState[tpChannel].Timer = TpTxGetSTMINtime(tpChannel);
        tpTxState[tpChannel].engine = kTxState_WaitForTpTxCF;
      }
      break;
    default:
      /* default case - leave function without any changes to internal states */
      return;
    }  /* end of switch state */

    /* Set TransmitObject free */
    TpIntTxTransmitChannel_SetFree(tpChannel);

    /* Callback - TX TpMessage is transmitted */
    __ApplTpTxCanMessageTransmitted((canuint8)tpChannel);
  }
#if defined (TP_TEST_ROUTINE_CONF_TIMEOUT)
  else
  {
    tpTxState[tpChannel].forceConfTimeout = 0;
  }
#endif
}


#if (defined( TP_ENABLE_MF_RECEPTION ) || defined(TP_ENABLE_SF_ACKNOWLEDGE) )
/*******************************************************************************
*
* NAME:              TpRxPostProcessing
*
* CALLED BY:         Confirmation Interrupt
* PRECONDITIONS:     Confirmation interrupts are configured
*
* PARAMETER:         -
* RETURN VALUE:      none
* DESCRIPTION:       Inform application and start timeout counter
*
*******************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
static void TP_INTERNAL_INLINE TpRxPostProcessing(void)
# else
static void TP_INTERNAL_INLINE TpRxPostProcessing(canuintCPUtype tpChannel)
# endif
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertInternal(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
# endif
# if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
    assertInternal(tpChannel, (tpRxInfoStruct[tpChannel].withoutFC == 0), kTpErrChannelNotInUse);
# endif
# if defined (TP_TEST_ROUTINE_CONF_TIMEOUT)
  if (TpTestRxCheckForcingConfTimeout())
# endif
  {
    switch(tpRxState[tpChannel].engine)
    {
    case kRxState_WaitForFCConfIsr:
# if defined (TP_ENABLE_FC_WAIT)
      if (tpRxInfoStruct[tpChannel].ApplGetBufferStatus == kTpFCStatusWait)
      {
        tpRxState[tpChannel].WFTCounter--;                /* decr. wait frame counter */
        /* Wait for next FC wait transmission */
        tpRxState[tpChannel].Timer  = (tTpEngineTimer) ((((((kTimeoutFC(tpChannel)-1)*TpTxCallCycle)/TpRxCallCycle)+1)<<2)/5);
        tpRxState[tpChannel].engine = kRxState_WaitForFCWait;
      }
      else
# endif
      { /* Wait for next CF */
        tpRxState[tpChannel].Timer  = kTimeoutCF(tpChannel);
        tpRxState[tpChannel].engine = kRxState_WaitCF;
# if defined (TP_ENABLE_FC_WAIT)
        tpRxState[tpChannel].WFTCounter = kTpWFTmax;    /* re-init wait frame counter */
# endif
      }
      break;

# if defined (TP_ENABLE_ISO_15765_2_2)
    case kRxState_WaitForFCOverConfIsr:
      /* Stop receiving frames on this tpChannel */
      tpRxState[tpChannel].Timer  = 0;
      tpRxState[tpChannel].engine = kRxState_Idle;
      break;
# endif


    default:
      return;
    }
    /* Set TransmitObject free */
    TpIntRxTransmitChannel_SetFree(tpChannel);
    /* Callback - Rx TpMessage is transmitted */
    __ApplTpRxCanMessageTransmitted((canuint8)tpChannel);
  }
# if defined (TP_TEST_ROUTINE_CONF_TIMEOUT)
  else
  {
    tpRxState[tpChannel].forceConfTimeout = 0;
  }
# endif
}
#endif  /* (defined( TP_ENABLE_MF_RECEPTION ) || defined(TP_ENABLE_SF_ACKNOWLEDGE) ) */

#if (TP_USE_FAST_TX_TRANSMISSION == kTpOn)
/*******************************************************************************
*
* NAME:              TpTxPrepareSendImmediate
*
* CALLED BY:         Application
* PRECONDITIONS:     -
*
* PARAMETER:         tpChannel
* RETURN VALUE:      kTpSuccess, kTpFailed
* DESCRIPTION:
*
*******************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
TP_EXTERNAL_INLINE canuint8 TP_API_CALL_TYPE TpTxPrepareSendImmediate(void)
# else
TP_EXTERNAL_INLINE canuint8 TP_API_CALL_TYPE TpTxPrepareSendImmediate(canuint8 tpChannel)
# endif
{
  if (tpTxState[tpChannel].engine == kTxState_WaitForTpTxCF)
  {
    tpTxState[tpChannel].Timer = 0;
    return kTpSuccess;
  }
  else
  {
    return kTpFailed;
  }
}
#endif

#if (TP_USE_FAST_TX_TRANSMISSION == kTpOn)
/*******************************************************************************
*
* NAME:              TpTxSendImmediate
*
* CALLED BY:         Application
* PRECONDITIONS:     -
*
* PARAMETER:         tpChannel
* RETURN VALUE:      kTpSuccess, kTpFailed
* DESCRIPTION:
*
*******************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
TP_EXTERNAL_INLINE void TP_API_CALL_TYPE TpTxSendImmediate(void)
# else
TP_EXTERNAL_INLINE void TP_API_CALL_TYPE TpTxSendImmediate(canuint8 tpChannel)
# endif
{
  __TpTxInternalPrepareOfCF(tpChannel);
  /* Try first transmission now */
  __TpTxStateTask((canuint8)tpChannel);
}
#endif

/*******************************************************************************
*
* NAME:              TpTxPrepareCfFrame
*
* CALLED BY:         Application
* PRECONDITIONS:
*
* PARAMETER:         none
* RETURN VALUE:      none
* DESCRIPTION:
*
*******************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
static TP_INTERNAL_INLINE void TpTxInternalPrepareOfCF(void)
# else
static TP_INTERNAL_INLINE void TpTxInternalPrepareOfCF(canuintCPUtype tpChannel)
# endif
{
  /* Assemble CF now*/
  /* Calculate next SN - SN is calculated modulo 15*/
  tpTxInfoStruct[tpChannel].sequencenumber = CANBITTYPE_CAST(tpTxInfoStruct[tpChannel].sequencenumber + 1); /*SN increment*/

#if FBLM_CANFD_SUPPORT
  /* Last message? */
  if((tpTxInfoStruct[tpChannel].DataIndex + ((canuint16)(FRAME_CANFD_MAX_REAL_LENGTH - (CF_OFFSET + FORMAT_OFFSET))) ) >= tpTxInfoStruct[tpChannel].DataLength)
#else /*CAN USED*/
  /* Last message? */
  if((tpTxInfoStruct[tpChannel].DataIndex + ((canuint16)(FRAME_LENGTH - (CF_OFFSET + FORMAT_OFFSET))) ) >= tpTxInfoStruct[tpChannel].DataLength)

#endif /*FBLM_CANFD_SUPPORT*/
  {
    tpTxState[tpChannel].engine = kTxState_WaitForLastCFConfIsr;
  }
  else /*No, wait for next CF*/
  {
    tpTxState[tpChannel].engine = kTxState_WaitForCFConfIsr;
  }
  tpTxState[tpChannel].Timer = TpTxConfirmationTimeout(tpChannel);

  /* Transmit the CANframe */
  tpTxState[tpChannel].queued = 1;
}

/*******************************************************************************
*
* NAME:              TpTxTask (Timer)
*
* CALLED BY:         OS, Application
* PRECONDITIONS:     Cyclical called function (e.g. every 10ms)
*
* PARAMETER:         none
* RETURN VALUE:      none
* DESCRIPTION:       Survey timing conditions, Transmit consecutive frames
*
*******************************************************************************/
void TP_API_CALL_TYPE TpTxTask(void)
{
  tvolatileTpTxState pTpTxState;
#if defined(TP_ENABLE_MIN_TIMER)
# if defined  (TP_ENABLE_REQUEST_QUEUE)
# endif
#endif
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
  cansintCPUtype tpChannel;

  for (tpChannel=(cansintCPUtype)(kTpTxChannelCount-1); tpChannel>=0; tpChannel--)
#endif
  {
    if (tpTxState[tpChannel].Timer != 0)
    { /* Channel is used */
      TpGlobalInterruptDisable();
      pTpTxState = (tvolatileTpTxState)&tpTxState[tpChannel];
      if(pTpTxState->Timer != 0)
      {
        tpTxState[tpChannel].Timer--;

        if(tpTxState[tpChannel].Timer == 0)
        { /*StopTxTimer();*/  /*Value of timer must be zero to reach this point*/
          switch(tpTxState[tpChannel].engine)
          {
          case kTxState_WaitFC:     /*FC Timeout occured!*/
            __TpTxInit(tpChannel, kTpTxErrFCTimeout);
            TPCANCANCELTRANSMIT(TpIntTxGetCanChannel(tpChannel)) (TP_TX_HANDLE(tpChannel));
            TpGlobalInterruptRestore();
            break;
          case kTxState_WaitForTpTxCF:
            __TpTxInternalPrepareOfCF(tpChannel);
            TpGlobalInterruptRestore();
            /* Try first transmission now */
            __TpTxStateTask((canuint8)tpChannel);
            break;

          case kTxState_WaitForSFConfIsr:
          case kTxState_WaitForFFConfIsr:
          case kTxState_WaitForCFConfIsr:
          case kTxState_WaitForLastCFConfIsr:
            /* Timeout, apparently no access to bus*/
            __TpTxInit(tpChannel, kTpTxErrConfIntTimeout);
            TPCANCANCELTRANSMIT(TpIntTxGetCanChannel(tpChannel)) (TP_TX_HANDLE(tpChannel));
            TpGlobalInterruptRestore();
            break;

#if defined(TP_ENABLE_MIN_TIMER)
          case kTxState_WaitForMinTimer:
# if defined  (TP_ENABLE_REQUEST_QUEUE)
            if(tpTxInfoStruct[tpChannel].DataLength != 0xffff)
            { /* TpTransmit was called, while minimum sending distance was active -> re-transmission */
              if((tpTxInfoStruct[tpChannel].DataLength) <= (FRAME_LENGTH - (SF_OFFSET + FORMAT_OFFSET)))
              { /*(0)1 to 6/7 bytes will be a SingleFrame*/
                tpTxState[tpChannel].engine = kTxState_WaitForSFConfIsr;
              }
              else
              {
                tpTxState[tpChannel].engine = kTxState_WaitForFFConfIsr;
              }
              tpTxState[tpChannel].Timer = TpTxConfirmationTimeout(tpChannel);
              /* set transmission flag */
              tpTxState[tpChannel].queued = 1;
            }
            else
# endif
            {
# if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
              if (tpTxState[tpChannel].blocked == 0)
# endif
              {
                /* Clear inUse state to free tpChannel */
                /* Only engine is cleared, Timer is alreaady zero */
                tpTxState[tpChannel].engine = kTxState_Idle;
              }
# if (defined (TP_ENABLE_DYNAMIC_CHANNELS) && !defined (TP_ENABLE_SINGLE_CHANNEL_TP) )
              else
              {
                tpTxState[tpChannel].engine = kTxState_Reserved;
              }
# endif
            }
            TpGlobalInterruptRestore();

# if defined (TP_ENABLE_SINGLE_MSG_OBJ)
            __ApplTpTxDelayFinished(tpChannel, kTpSuccess);
# endif
            break;
#endif
          default:
            TpGlobalInterruptRestore();
            assertGeneral(tpChannel, kTpTxErrNoStateSpecified);
            break;
          } /*End of "switch(txGetState())"*/
        } /*End of "if( TxTimerValue() )"*/
        else
        {
          TpGlobalInterruptRestore();
          /* Try to transmit if timer is not zero */
          __TpTxStateTask((canuint8)tpChannel);
        }
      } /*End of "if( TxTimerValue() )"*/
      else
      {
        TpGlobalInterruptRestore();
      }
    } /* Channel in use ? */
    else
    {
      /* must be empty - could called wrongly on 8bit controllers */
      /* .timer is a 16bit value and is written in ISR and API */
      /* and could be wrongly interpreted as zero while it is written in ISR */
    }
  }/* End of for */
} /* TpTxTask */

/*******************************************************************************
*
* NAME:              TpRxTask (Timer)
*
* CALLED BY:         OS, Application
* PRECONDITIONS:     Cyclical called function (e.g. every 20ms)
*
* PARAMETER:         none
* RETURN VALUE:      none
* DESCRIPTION:       Survey receive timing conditions
*
*******************************************************************************/
void TP_API_CALL_TYPE TpRxTask(void)
{
  tvolatileTpRxState pTpRxState;
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
  cansintCPUtype tpChannel;

  for (tpChannel=(cansintCPUtype)(kTpRxChannelCount-1); tpChannel>=0; tpChannel--)
#endif
  { /* Is the engine IDLE or is the Application already called ? Otherwise a communication is running and the timer should be decremted */
    if (tpRxState[tpChannel].Timer != 0)
    { /* Channel is used ! */
      TpGlobalInterruptDisable();
      pTpRxState = (tvolatileTpRxState) &tpRxState[tpChannel];
      if(pTpRxState->Timer != 0)
      {
        tpRxState[tpChannel].Timer--;

        if(tpRxState[tpChannel].Timer == 0)
        { /*Value of timer must be zero to reach this point*/
          switch(tpRxState[tpChannel].engine)
          {
#if defined( TP_ENABLE_MF_RECEPTION )
          case kRxState_WaitCF:
            __TpRxInit(tpChannel, kTpRxErrCFTimeout);     /* and go to idle state       */
            TPCANCANCELTRANSMIT(TpIntTxGetCanChannel(tpChannel)) (TP_TX_HANDLE(tpChannel));
            Fblm_DiagInitQueue(Appl_QueNumber);/*Reinit this Diagnosic queue*/
            TpGlobalInterruptRestore();
            break;

          case kRxState_WaitForFCConfIsr:
# if defined (TP_ENABLE_ISO_15765_2_2)
          case kRxState_WaitForFCOverConfIsr:
# endif
#endif

#if (defined( TP_ENABLE_MF_RECEPTION ) || defined(TP_ENABLE_SF_ACKNOWLEDGE) )
            /* Timeout, apparently no access to bus*/
            __TpRxInit(tpChannel, kTpRxErrConfIntTimeout); /* and go to idle state       */
            TPCANCANCELTRANSMIT(TpIntTxGetCanChannel(tpChannel)) (TP_TX_HANDLE(tpChannel));
            Fblm_DiagInitQueue(Appl_QueNumber);  /*Reinit this Diagnosic queue*/
            TpGlobalInterruptRestore();
            break;
#endif

#if defined( TP_ENABLE_MF_RECEPTION )
# if defined (TP_ENABLE_FC_WAIT)
          case kRxState_WaitForFCWait:
            if(tpRxState[tpChannel].WFTCounter == 0)
            { /* WFTmax wait frames are transmitted now */
              __TpRxInit(tpChannel, kTpRxErrWFTmaxOverrun);   /* and go to idle state       */
              TpGlobalInterruptRestore();
            }
            else
            { /* Force sending next FC with status wait */
              tpRxState[tpChannel].Timer  = TpRxConfirmationTimeout(tpChannel);
              tpRxState[tpChannel].engine = kRxState_WaitForFCConfIsr;
              tpRxState[tpChannel].queued = 1; /* set transmission request */
              TpGlobalInterruptRestore();
#  if(TP_USE_TX_OF_FC_IN_ISR == kTpOn)
            __TpRxStateTask(tpChannel);
#  endif
            }
            break;
# endif
#endif

          default:
            TpGlobalInterruptRestore();
            assertGeneral(tpChannel, kTpRxErrNoStateSpecified);
            break;
          }
        }
        else
        {
          TpGlobalInterruptRestore();
#if (defined( TP_ENABLE_MF_RECEPTION ) || defined(TP_ENABLE_SF_ACKNOWLEDGE) )
          /* Do only while timer is active */
          __TpRxStateTask((canuint8)tpChannel);
#endif
        }
      } /* RxTimer */
      else
      {
        TpGlobalInterruptRestore();
      }
    } /* Timer in use ? */
  } /* for-loop */
} /* TpRxTask */


/*******************************************************************************
* Set- and Get-Functions for Reception
*******************************************************************************/

#if defined( TP_ENABLE_MF_RECEPTION )
# if (TP_USE_EXTENDED_API_BS == kTpOn)
/*******************************************************************************
*
* NAME:              TpRxSetBS
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle, new blocksize value
* RETURN VALUE:      none
* DESCRIPTION:       Set new blocksize value
*
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpRxSetBS(canuint8 newBS)
#  else
void TP_API_CALL_TYPE TpRxSetBS(canuint8 tpChannel, canuint8 newBS)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
#  endif
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
  assertUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse);
#  endif

  TpRxSetBlockSize(tpChannel, newBS);
}
# endif

# if (TP_USE_EXTENDED_API_BS == kTpOn)
/*******************************************************************************
*
* NAME:              TpRxGetBS
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:      Current BS value
* DESCRIPTION:       Return BS used within FC
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_API_CALL_TYPE TpRxGetBS(void)
#  else
canuint8 TP_API_CALL_TYPE TpRxGetBS(canuint8 tpChannel)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, 0xff);
#  endif
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, 0xff);
#  endif

  return TpRxGetBlockSize(tpChannel);
}
# endif

# if (TP_USE_EXTENDED_API_STMIN == kTpOn)
/*******************************************************************************
*
* NAME:              TpRxSetSTMIN
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle, new stmin value
* RETURN VALUE:      none
* DESCRIPTION:       Set new stmin time
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpRxSetSTMIN(canuint8 newSTMIN)
#  else
void TP_API_CALL_TYPE TpRxSetSTMIN(canuint8 tpChannel, canuint8 newSTMIN)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
#  endif
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
  assertUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse);
#  endif

  tpRxInfoStruct[tpChannel].STMin = newSTMIN;
}
# endif

# if (TP_USE_EXTENDED_API_STMIN == kTpOn)
/*******************************************************************************
*
* NAME:              TpRxGetSTMIN
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:      Current STMIN value
* DESCRIPTION:       Return STMIN used within FC
*
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_API_CALL_TYPE TpRxGetSTMIN(void)
#  else
canuint8 TP_API_CALL_TYPE TpRxGetSTMIN(canuint8 tpChannel)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, 0xff);
#  endif
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, 0xff);
#  endif

  return TpRxGetSTMINtime(tpChannel);
}
# endif
#endif  /* defined( TP_ENABLE_MF_RECEPTION ) */

#if (TP_USE_APPL_PRECOPY == kTpOn) && (TP_USE_FAST_PRECOPY == kTpOff) && defined (TP_DISABLE_CHECKTA_COMPATIBILITY)
/*******************************************************************************
*
* NAME:              TpRxGetTaType
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:
* DESCRIPTION:
*******************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
t_ta_type TP_API_CALL_TYPE TpRxGetTaType(void)
# else
t_ta_type TP_API_CALL_TYPE TpRxGetTaType(canuint8 tpChannel)
# endif
{
  t_ta_type returnValue;
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, kTpNone);
# endif
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, kTpNone);
# endif

  if (tpRxInfoStruct[tpChannel].ta_type == 0)
  {
    returnValue = kTpPhysical;
  }
  else
  {
    assertReturnUser(tpChannel, (tpRxInfoStruct[tpChannel].ta_type == 1), kTpRxErrChannelNotInState, kTpNone);
    returnValue = kTpFunctional;
  }
  return returnValue;
}
#endif

#if defined(TP_ENABLE_EXTENDED_ADDRESSING)
/*******************************************************************************
* NAME:              TpRxGetSourceAddress
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle
* RETURN VALUE:      source address of last CAN message (== ID - base address)
* DESCRIPTION:       Get source address using extended addressing
*******************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_API_CALL_TYPE TpRxGetSourceAddress(void)
# else
canuint8 TP_API_CALL_TYPE TpRxGetSourceAddress(canuint8 tpChannel)
# endif
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, 0xff);
# endif
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, 0xff);

  return((canuint8)tpRxInfoStruct[tpChannel].SourceAddress);
}
#endif

#if (defined(TP_ENABLE_EXTENDED_ADDRESSING) )
# if (TP_USE_GATEWAY_API == kTpOn)
/*******************************************************************************
* NAME:              TpRxGetReceivedTargetAddress
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle
* RETURN VALUE:      Target address received in the last CAN messages
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_API_CALL_TYPE TpRxGetReceivedTargetAddress(void)
#  else
canuint8 TP_API_CALL_TYPE TpRxGetReceivedTargetAddress(canuint8 tpChannel)
#  endif
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, 0xff);
# endif
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, 0xff);

  return tpRxInfoStruct[tpChannel].TargetAddress;
}
# endif
#endif

# if (kTpNumberOfCanChannels > 1)
/*******************************************************************************
* NAME:              TpRxGetCanChannel
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle
* RETURN VALUE:      CAN Channel of MultiCan System
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_API_CALL_TYPE TpRxGetCanChannel(void)
#  else
canuint8 TP_API_CALL_TYPE TpRxGetCanChannel(canuint8 tpChannel)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, kTpNoChannel);
#  endif
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, kTpNoChannel);

  return tpRxInfoStruct[tpChannel].CanChannel;
}
# endif

#if ((defined(TP_ENABLE_NORMAL_ADDRESSING)) )
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
/*******************************************************************************
* NAME:              TpRxGetChannelExtID, TpRxGetChannelID
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         tpChannel
* RETURN VALUE:
*******************************************************************************/
#  if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
canuint32 TP_API_CALL_TYPE TpRxGetChannelExtID(canuint8 tpChannel)
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, 0xffff);
# endif
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, 0xffff);

  return tpRxInfoStruct[tpChannel].ReceiveID;
}
canuint16 TP_API_CALL_TYPE TpRxGetChannelID(canuint8 tpChannel)
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, 0xffff);
# endif
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, 0xffff);

  return((canuint16)tpRxInfoStruct[tpChannel].ReceiveID);
}
#  elif( TP_USE_EXT_IDS_FOR_NORMAL == kTpOn )
canuint32 TP_API_CALL_TYPE TpRxGetChannelExtID(canuint8 tpChannel)
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, 0xffff);
# endif
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, 0xffff);

  return tpRxInfoStruct[tpChannel].ReceiveID;
}
#  else
canuint16 TP_API_CALL_TYPE TpRxGetChannelID(canuint8 tpChannel)
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, 0xffff);
# endif
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, 0xffff);

  return((canuint16)tpRxInfoStruct[tpChannel].ReceiveID);
}
#  endif
#  if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
/*******************************************************************************
* NAME:              TpRxGetChannelIDType
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         tpChannel
* RETURN VALUE:      kTpCanIdTypeStd, kTpCanIdTypeExt
*******************************************************************************/
canuint8 TP_API_CALL_TYPE TpRxGetChannelIDType(canuint8 tpChannel)
{
#   if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, 0xff);
#   endif
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, 0xff);

  return tpRxInfoStruct[tpChannel].ReceiveIDType;
}
#  endif
# endif
#endif

#if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
/*******************************************************************************
* NAME:              TpRxGetEcuNumber
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle
* RETURN VALUE:      Ecu Number
* DESCRIPTION:       Get Ecu Number of the last received TP-Msg.
*******************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_API_CALL_TYPE TpRxGetEcuNumber(void)
# else
canuint8 TP_API_CALL_TYPE TpRxGetEcuNumber(canuint8 tpChannel)
# endif
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, kTpNoChannel);
# endif
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, kTpNoChannel);

  return tpRxInfoStruct[tpChannel].EcuNumber;
}
#endif

/*******************************************************************************
* NAME:              TpRxGetStatus
*
* CALLED BY:         CAN-Driver
* PRECONDITIONS:     TpInit
*
* PARAMETER:         tpChannel
* RETURN VALUE:      Status of channel
*******************************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_API_CALL_TYPE TpRxGetStatus(void)
#else
canuint8 TP_API_CALL_TYPE TpRxGetStatus(canuint8 tpChannel)
#endif
{
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#else
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, kTpChannelNotInUse);
#endif
  if (tpRxState[tpChannel].engine != kRxState_Idle)
  {
    return kTpChannelInUse;
  }
  else
  {
    return kTpChannelNotInUse;
  }
}

/*******************************************************************************
* NAME:              TpRxResetChannel
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         tpChannel
* RETURN VALUE:      none
*******************************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpRxResetChannel(void)
#else
void TP_API_CALL_TYPE TpRxResetChannel(canuint8 tpChannel)
#endif
{
#if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
#endif
  __TpRxInit(tpChannel, kTpRxErrRxResetChannelIsCalled);

}

#if defined( TP_ENABLE_MF_RECEPTION )
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#  if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
/*******************************************************************************
*
* NAME:              TpRxWithoutFC
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         tpChannel handle
* RETURN VALUE:      none
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpRxWithoutFC(canuint8 tpChannel)
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
#  endif
  assertUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse);

  tpRxInfoStruct[tpChannel].withoutFC = 1;
}
#  endif
# endif

# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
#  if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
/*******************************************************************************
*
* NAME:              TpRxWithFC
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         tpChannel handle
* RETURN VALUE:      none
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpRxWithFC(canuint8 tpChannel)
{
#   if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
#   endif
  assertUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse);

  tpRxInfoStruct[tpChannel].withoutFC = 0;
}
#  endif
# endif
#endif

#if defined (TP_ENABLE_DYN_AWAIT_CORRECT_SN)
/*******************************************************************************
*
* NAME:              TpRxSetWaitCorrectSN
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         tpChannel handle, tpBool wait (kTpTrue = strict SN check,
*                                                   kTpFalse = wait for correct SN)
* RETURN VALUE:      none
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpRxSetWaitCorrectSN(canuint8 tpChannel, tpBool wait)
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
# endif
  assertUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse);

  tpRxInfoStruct[tpChannel].SNwait = wait;
}
#endif
/* defined (TP_ENABLE_DYN_AWAIT_CORRECT_SN) */

#if defined (TP_ENABLE_DYN_TX_STMIN_TIMING)
/*******************************************************************************
*
* NAME:              TpTxSetCFDelay
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         tpChannel handle, tTpEngineTimer time
* RETURN VALUE:      none
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpTxSetCFDelay(canuint8 tpChannel, tTpEngineTimer time)
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
# endif
  assertUser(tpChannel, tpTxState[tpChannel].engine != kTxState_Idle, kTpErrChannelNotInUse);

  tpTxCFDelay[tpChannel] = time;
}
#endif

#if defined (TP_ENABLE_DYN_CHANNEL_TIMING)
/*******************************************************************************
*
* NAME:              TpRxSetTimeoutCF
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         tpChannel handle, tTpEngineTimer time
* RETURN VALUE:      none
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpRxSetTimeoutCF(canuint8 tpChannel, tTpEngineTimer time)
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
# endif
  assertUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse);

  tpRxTimeoutCF[tpChannel] = time;
}

/*******************************************************************************
*
* NAME:              TpRxSetTimeoutConfirmation
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         tpChannel handle, tTpEngineTimer time
* RETURN VALUE:      none
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpRxSetTimeoutConfirmation(canuint8 tpChannel, tTpEngineTimer time)
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
# endif
  assertUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse);

  tpRxConfirmationTimeout[tpChannel] = time;
}
#endif
/* defined (TP_ENABLE_DYN_CHANNEL_TIMING) */



#if defined(TP_ENABLE_EXTENDED_ADDRESSING)
# if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
/*******************************************************************************
*
* NAME:              TpRxGetBaseAddress
*
* CALLED BY:         application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         tpChannel handle, BaseAddress
* RETURN VALUE:      none
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
canuint16 TP_API_CALL_TYPE TpRxGetBaseAddress(canuint8 tpChannel)
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh, 0xffff);
#  endif
  assertReturnUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse, 0xffff);

  return tpRxInfoStruct[tpChannel].BaseAddress;
}
# endif
#endif


#if (TP_USE_OVERRUN_INDICATION == kTpOn)
/*******************************************************************************
*
* NAME:              TpRxSetBufferOverrun
*
* CALLED BY:         application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         tpChannel handle
* RETURN VALUE:      none
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpRxSetBufferOverrun(void)
#else
void TP_API_CALL_TYPE TpRxSetBufferOverrun(canuint8 tpChannel)
#endif
{
#if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
#endif
  assertUser(tpChannel, tpRxState[tpChannel].engine == kRxState_CanFrameReceived, kTpRxErrChannelNotInState);

  tpRxState[tpChannel].noCopyData = 1;
}
#endif



/*******************************************************************************
* NAME:              TpRxGetCanBuffer
*
* CALLED BY:         Application
* PRECONDITIONS:     Only valid in __ApplTpRxGetBuffer function
*
* PARAMETER:         tpChannel in case of non singe channel tp
* RETURN VALUE:      Pointer to data buffer in CAN registers
*******************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
CanChipDataPtr TP_API_CALL_TYPE TpRxGetCanBuffer(void)
# else
CanChipDataPtr TP_API_CALL_TYPE TpRxGetCanBuffer(canuint8 tpChannel)
# endif
{
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
  return tpRxInfoStruct[0].DataBufferPtr.DataCanBufferPtr;
# else
  return tpRxInfoStruct[tpChannel].DataBufferPtr.DataCanBufferPtr;
# endif
}

/*******************************************************************************
* NAME:              TpRxSetFCStatus
*
* CALLED BY:         Application
* PRECONDITIONS:     Only valid in __ApplTpRxGetBuffer function
*
* PARAMETER:         tpChannel in case of non singe channel tp
* RETURN VALUE:      none
*******************************************************************************/
#if (defined(TP_ENABLE_FC_WAIT) || defined(TP_ENABLE_FC_SUPPRESS) || defined(TP_ENABLE_FC_OVERFLOW))
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpRxSetFCStatus(canuint8 FCStatus)
# else
void TP_API_CALL_TYPE TpRxSetFCStatus(canuint8 tpChannel, canuint8 FCStatus)
# endif
{
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
  tpRxInfoStruct[0].ApplGetBufferStatus = (canbittype)FCStatus;
# else
  tpRxInfoStruct[tpChannel].ApplGetBufferStatus = (canbittype)FCStatus;
# endif
}
#endif


/*******************************************************************************
* NAME:              TpRxGetFCStatus
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         tpChannel in case of non singe channel tp
* RETURN VALUE:      FC status of channel
*******************************************************************************/
#if (defined(TP_ENABLE_FC_WAIT) || defined(TP_ENABLE_FC_SUPPRESS) || defined(TP_ENABLE_FC_OVERFLOW))
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_API_CALL_TYPE TpRxGetFCStatus(void)
# else
canuint8 TP_API_CALL_TYPE TpRxGetFCStatus(canuint8 tpChannel)
# endif
{
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
  return((canuint8)tpRxInfoStruct[0].ApplGetBufferStatus);
# else
  return((canuint8)tpRxInfoStruct[tpChannel].ApplGetBufferStatus);
# endif
}
#endif

#if defined( TP_ENABLE_MF_RECEPTION )
/*******************************************************************************
* NAME:              TpRxSetClearToSend
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         tpChannel in case of non singe channel tp
* RETURN VALUE:      FC status of channel
*******************************************************************************/
# if defined (TP_ENABLE_FC_WAIT)
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpRxSetClearToSend(TP_MEMORY_MODEL_DATA canuint8 * pBuffer)
#  else
void TP_API_CALL_TYPE TpRxSetClearToSend(canuint8 tpChannel,TP_MEMORY_MODEL_DATA canuint8 * pBuffer)
#  endif
{
  if (tpRxInfoStruct[tpChannel].ApplGetBufferStatus == kTpFCStatusWait)
  {
    tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr = pBuffer;
    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + 0) = *(CanChipDataPtr)(tpRxInfoStruct[tpChannel].FFDataBuffer + 0);
    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + 1) = *(CanChipDataPtr)(tpRxInfoStruct[tpChannel].FFDataBuffer + 1);
    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + 2) = *(CanChipDataPtr)(tpRxInfoStruct[tpChannel].FFDataBuffer + 2);
    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + 3) = *(CanChipDataPtr)(tpRxInfoStruct[tpChannel].FFDataBuffer + 3);
    *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + 4) = *(CanChipDataPtr)(tpRxInfoStruct[tpChannel].FFDataBuffer + 4);
#  if defined(TP_ENABLE_NORMAL_ADDRESSING)
    {
      *(tpRxInfoStruct[tpChannel].DataBufferPtr.DataApplBufferPtr + 5) = *(CanChipDataPtr)(tpRxInfoStruct[tpChannel].FFDataBuffer + 5);
    }
#  endif
    tpRxInfoStruct[tpChannel].ApplGetBufferStatus = (canbittype)kTpFCClearToSend;
    tpRxState[tpChannel].Timer  = TpRxConfirmationTimeout(tpChannel);
    tpRxState[tpChannel].engine = kRxState_WaitForFCConfIsr;
    /* set transmission request */
    tpRxState[tpChannel].queued = 1;
    __TpRxStateTask(tpChannel);
  }
}
# endif
#endif

#if defined (TP_TEST_ROUTINE_CONF_TIMEOUT)
/*******************************************************************************
* NAME:              TpRxTestForceConfirmationTimeout
*
* CALLED BY:         application
* PRECONDITIONS:
*
* PARAMETER:
* RETURN VALUE:
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpRxTestForceConfirmationTimeout(void)
#  else
void TP_API_CALL_TYPE TpRxTestForceConfirmationTimeout(canuint8 tpChannel)
#  endif
{
  tpRxState[tpChannel].forceConfTimeout = 1;
}
#endif


/*******************************************************************************
* Set- and Get-Functions for Transmission
*******************************************************************************/

# if defined (TP_TX_ENABLE_DYN_EXT_ID)
/*******************************************************************************
*
* NAME:              TpTxSetPriority
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle, new priority value
* RETURN VALUE:      none
* DESCRIPTION:       Set priority bits within a 29-bit extended identifier.
*                    Additionally the 'Reserved' and 'Data Page' bits can be set too.
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpTxSetPriorityBits(vuint8 prio, vuint8 res, vuint8 dataPage)
#  else
void TP_API_CALL_TYPE TpTxSetPriorityBits(canuint8 tpChannel, canuint8 prio, canuint8 res, canuint8 dataPage)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
#  endif
  assertUser(tpChannel, prio     <= 7, kTpErrInvalidParameterValue);
  assertUser(tpChannel, res      <= 1, kTpErrInvalidParameterValue);
  assertUser(tpChannel, dataPage <= 1, kTpErrInvalidParameterValue);

  tpTxHighByte29Bit[tpChannel]  = (vuint8)(prio << 2);
  tpTxHighByte29Bit[tpChannel] |= (vuint8)(res << 1);
  tpTxHighByte29Bit[tpChannel] |= dataPage;
}

/*******************************************************************************
*
* NAME:              TpTxSetPGN
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle, new PGN value
* RETURN VALUE:      none
* DESCRIPTION:       Set PGN (PF byte) within a 29-bit extended identifier
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpTxSetPGN(canuint8 pgn)
#  else
void TP_API_CALL_TYPE TpTxSetPGN(canuint8 tpChannel, canuint8 pgn)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
#  endif
  tpTxPGN29Bit[tpChannel] = pgn;
}
# endif /* TP_TX_ENABLE_DYN_EXT_ID */

# if defined (TP_RX_ENABLE_DYN_EXT_ID)
/*******************************************************************************
*
* NAME:              TpRxSetPriority
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle, new priority value
* RETURN VALUE:      none
* DESCRIPTION:       Set priority bits within a 29-bit extended identifier.
*                    Additionally the 'Reserved' and 'Data Page' bits can be set too.
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpRxSetPriorityBits(vuint8 prio, vuint8 res, vuint8 dataPage)
#  else
void TP_API_CALL_TYPE TpRxSetPriorityBits(canuint8 tpChannel, canuint8 prio, canuint8 res, canuint8 dataPage)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
#  endif
  assertUser(tpChannel, prio     <= 7, kTpErrInvalidParameterValue);
  assertUser(tpChannel, res      <= 1, kTpErrInvalidParameterValue);
  assertUser(tpChannel, dataPage <= 1, kTpErrInvalidParameterValue);

  tpRxHighByte29Bit[tpChannel]  = (vuint8)(prio << 2);
  tpRxHighByte29Bit[tpChannel] |= (vuint8)(res << 1);
  tpRxHighByte29Bit[tpChannel] |= dataPage;
}

/*******************************************************************************
*
* NAME:              TpRxSetPGN
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle, new PGN value
* RETURN VALUE:      none
* DESCRIPTION:       Set PGN (PF byte) within a 29-bit extended identifier
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpRxSetPGN(canuint8 pgn)
#  else
void TP_API_CALL_TYPE TpRxSetPGN(canuint8 tpChannel, canuint8 pgn)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
#  endif
  tpRxPGN29Bit[tpChannel] = pgn;
}
# endif /* TP_RX_ENABLE_DYN_EXT_ID */

# if defined(TP_ENABLE_EXTENDED_ADDRESSING)
/*******************************************************************************
*
* NAME:              TpTxSetTargetAddress
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle, new target address value
* RETURN VALUE:      none
* DESCRIPTION:       Set target address using extended addressing
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpTxSetTargetAddress(canuint8 address)
#  else
void TP_API_CALL_TYPE TpTxSetTargetAddress(canuint8 tpChannel, canuint8 address)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, tpTxState[tpChannel].engine == kTxState_Reserved, kTpErrChannelNotInPreTransmitState);
#  endif

#  if defined  (TP_ENABLE_RUNTIME_CHECK )
  /* Set validity for TargetAddress */
  tpTxInfoStruct[tpChannel].TargetAddressIsValid = 1;
#  endif
  tpTxInfoStruct[tpChannel].TargetAddress = address;
}
# endif


#if (kTpNumberOfCanChannels > 1)
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
/*******************************************************************************
* NAME:              TpTxGetCanChannel
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle
* RETURN VALUE:      CAN Channel of MultiCan System
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_API_CALL_TYPE TpTxGetCanChannel(void)
#  else
canuint8 TP_API_CALL_TYPE TpTxGetCanChannel(canuint8 tpChannel)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh, kTpNoChannel);
#  endif
  assertReturnUser(tpChannel, tpTxState[tpChannel].engine != kTxState_Idle, kTpErrChannelNotInUse, kTpNoChannel);

  return tpTxInfoStruct[tpChannel].CanChannel;
}
# endif
#endif


# if (kTpNumberOfCanChannels > 1)
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
/*******************************************************************************
* NAME:              TpTxSetCanChannel
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle
* RETURN VALUE:      CAN Channel of MultiCan System
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#   if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpTxSetCanChannel(canuint8 canChannel)
#   else
void TP_API_CALL_TYPE TpTxSetCanChannel(canuint8 tpChannel, canuint8 canChannel)
#   endif
{
#   if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, (tpTxState[tpChannel].engine == kTxState_Reserved) || (tpTxState[tpChannel].engine == kTxState_WaitForMinTimer), kTpErrChannelNotInPreTransmitState);
#   endif
  tpTxInfoStruct[tpChannel].CanChannel = (canbittype)(canChannel & kTpMaxCanChannels);
}
#  endif
# endif

# if ( (defined(TP_ENABLE_NORMAL_ADDRESSING)) )
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
/*******************************************************************************
* NAME:              TpTxSetChannelID, TpTxSetChannelExtID
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:
* RETURN VALUE:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#   if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpTxSetChannelID(canuint16 transmitID, canuint16 receiveID)
#   else
void TP_API_CALL_TYPE TpTxSetChannelID(canuint8 tpChannel, canuint16 transmitID, canuint16 receiveID)
#   endif
{
#   if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, tpTxState[tpChannel].engine == kTxState_Reserved, kTpErrChannelNotInPreTransmitState);
#   endif
  tpTxInfoStruct[tpChannel].TransmitID     = transmitID;
  tpTxInfoStruct[tpChannel].ReceiveID      = receiveID;
#   if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
  tpTxInfoStruct[tpChannel].TransmitIDType = kTpCanIdTypeStd;
  tpTxInfoStruct[tpChannel].ReceiveIDType  = kTpCanIdTypeStd;
#   endif
}

#   if( (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn) || (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn) )
void TP_API_CALL_TYPE TpTxSetChannelExtID(canuint8 tpChannel, canuint32 transmitID, canuint32 receiveID)
{
#    if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, tpTxState[tpChannel].engine == kTxState_Reserved, kTpErrChannelNotInPreTransmitState);
#    endif
  tpTxInfoStruct[tpChannel].TransmitID     = transmitID;
  tpTxInfoStruct[tpChannel].ReceiveID      = receiveID;
#    if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
  tpTxInfoStruct[tpChannel].TransmitIDType = kTpCanIdTypeExt;
  tpTxInfoStruct[tpChannel].ReceiveIDType  = kTpCanIdTypeExt;
#    endif
}
#   endif

/*******************************************************************************
* NAME:              TpRxSetTransmitID, TpRxSetTransmitExtID
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:
* RETURN VALUE:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#   if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
void TP_API_CALL_TYPE TpRxSetTransmitExtID(canuint8 tpChannel, canuint32 transmitID)
{
#    if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
#    endif
  tpRxInfoStruct[tpChannel].TransmitID     = transmitID;
  tpRxInfoStruct[tpChannel].ReceiveIDType  = kTpCanIdTypeExt;
}
void TP_API_CALL_TYPE TpRxSetTransmitID(canuint8 tpChannel, canuint16 transmitID)
{
#    if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
#    endif
  tpRxInfoStruct[tpChannel].TransmitID     = (canuint32)transmitID;
  tpRxInfoStruct[tpChannel].ReceiveIDType  = kTpCanIdTypeStd;
}

#   elif( TP_USE_EXT_IDS_FOR_NORMAL == kTpOn )
void TP_API_CALL_TYPE TpRxSetTransmitExtID(canuint8 tpChannel, canuint32 transmitID)
{
#    if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
#    endif
  tpRxInfoStruct[tpChannel].TransmitID     = transmitID;
}
#   else

void TP_API_CALL_TYPE TpRxSetTransmitID(canuint8 tpChannel, canuint16 transmitID)
{
#    if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
#    endif
  tpRxInfoStruct[tpChannel].TransmitID     = transmitID;
}
#   endif








#  endif
# endif

# if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
/*******************************************************************************
*
* NAME:              TpTxSetEcuNumber
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         Channel handle, new Ecu Number
* RETURN VALUE:      none
* DESCRIPTION:       Set new ECU Number
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpTxSetEcuNumber(canuint8 ecuNr)
#  else
void TP_API_CALL_TYPE TpTxSetEcuNumber(canuint8 tpChannel, canuint8 ecuNr)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, tpTxState[tpChannel].engine == kTxState_Reserved, kTpErrChannelNotInPreTransmitState);
#  endif
#  if defined  (TP_ENABLE_RUNTIME_CHECK )
  /* Set validity for EcuNumber */
  tpTxInfoStruct[tpChannel].EcuNumberIsValid = 1;
#  endif
  tpTxInfoStruct[tpChannel].EcuNumber = ecuNr;
}
# endif

# if defined(TP_ENABLE_DYNAMIC_CHANNELS)    || \
    defined(TP_DISABLE_NORMAL_ADDRESSING)
/*******************************************************************************
* NAME:              TpTxSetResponse
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         RxChannel handle, TxChannel handle
* RETURN VALUE:
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpTxSetResponse(void)
# else
void TP_API_CALL_TYPE TpTxSetResponse(canuint8 rxChannel, canuint8 txChannel)
# endif
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, rxChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, txChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
# endif
# if (TP_USE_RX_CHANNEL_WITHOUT_FC == kTpOn)
  assertUser(tpChannel, tpRxInfoStruct[rxChannel].withoutFC == 0, kTpRxErrSetResponseWithoutFc);
# endif
# if (TP_USE_TX_CHANNEL_WITHOUT_FC == kTpOn)
  assertUser(tpChannel, tpTxInfoStruct[txChannel].withoutFC == 0, kTpTxErrSetResponseWithoutFc);
# endif
/* Complete InfoStruct object is copied */
# if defined(TP_ENABLE_EXTENDED_ADDRESSING)
#   if defined  (TP_ENABLE_RUNTIME_CHECK )
  /* Set validity for TargetAddress */
  tpTxInfoStruct[txChannel].TargetAddressIsValid = 1;
#   endif
  tpTxInfoStruct[txChannel].TargetAddress = tpRxInfoStruct[rxChannel].SourceAddress;
# endif


# if defined(TP_ENABLE_EXTENDED_ADDRESSING)
#  if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
  tpTxInfoStruct[txChannel].BaseAddress = tpRxInfoStruct[rxChannel].BaseAddress;
#  endif
# endif

# if defined(TP_ENABLE_NORMAL_ADDRESSING)
  tpTxInfoStruct[txChannel].TransmitID = tpRxInfoStruct[rxChannel].TransmitID;
  tpTxInfoStruct[txChannel].ReceiveID  = tpRxInfoStruct[rxChannel].ReceiveID;
#  if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
  tpTxInfoStruct[txChannel].TransmitIDType = tpRxInfoStruct[rxChannel].ReceiveIDType;
  tpTxInfoStruct[txChannel].ReceiveIDType  = tpRxInfoStruct[rxChannel].ReceiveIDType;
#  endif
# endif

# if (kTpNumberOfCanChannels > 1)
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
  tpTxInfoStruct[txChannel].CanChannel = tpRxInfoStruct[rxChannel].CanChannel;
#  endif
# endif

# if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
#  if defined  (TP_ENABLE_RUNTIME_CHECK )
  /* Set validity for EcuNumber */
  tpTxInfoStruct[txChannel].EcuNumberIsValid = 1;
#  endif
  tpTxInfoStruct[txChannel].EcuNumber = tpRxInfoStruct[rxChannel].EcuNumber;
# endif

}
# endif

/*******************************************************************************
* NAME:              TpTxResetChannel
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         tpChannel
* RETURN VALUE:      none
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpTxResetChannel(void)
#else
void TP_API_CALL_TYPE TpTxResetChannel(canuint8 tpChannel)
#endif
{
#if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
#endif
  __TpTxInit(tpChannel, kTpTxErrTxResetChannelIsCalled);

}

# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
# else
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
/*******************************************************************************
* NAME:              TpTxGetConnectionStatus
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         connection number
* RETURN VALUE:      assigned tpChannel to connection -
*                    kTpNoChannel if no tpChannel is assigned to
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
canuint8 TP_API_CALL_TYPE TpTxGetConnectionStatus(canuint8 connection)
{
  cansintCPUtype tpChannel;

  for (tpChannel=(cansintCPUtype)(kTpTxChannelCount-1); tpChannel>=0; tpChannel--)
  {
    if ( (tpTxInfoStruct[tpChannel].Connection == connection) && \
         (tpTxState[tpChannel].engine != kTxState_Idle) )
    {
      return (canuint8)tpChannel;
    }
  }
  return kTpNoChannel;
}
#  endif
# endif


# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
# else
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
/*******************************************************************************
*
* NAME:              TpTxLockChannel
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         Channel handle
* RETURN VALUE:
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpTxLockChannel(canuint8 tpChannel)
{
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, tpTxState[tpChannel].engine == kTxState_Reserved, kTpErrChannelNotInPreTransmitState);

  TpGlobalInterruptDisable();
  tpTxState[tpChannel].blocked = 1;
  TpGlobalInterruptRestore();
}
#  endif
# endif

# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
# else
#  if defined (TP_ENABLE_DYNAMIC_CHANNELS)
/*******************************************************************************
*
* NAME:              TpTxUnlockChannel
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         Channel handle
* RETURN VALUE:
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpTxUnlockChannel(canuint8 tpChannel)
{
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, tpTxState[tpChannel].engine == kTxState_Reserved, kTpErrChannelNotInPreTransmitState);

  TpGlobalInterruptDisable();
  tpTxState[tpChannel].blocked = 0;
  TpGlobalInterruptRestore();
}
#  endif
# endif

#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if (TP_USE_TX_CHANNEL_WITHOUT_FC == kTpOn)
/*******************************************************************************
*
* NAME:              TpTxWithoutFC
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         Channel handle
* RETURN VALUE:
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpTxWithoutFC(canuint8 tpChannel)
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, tpTxState[tpChannel].engine == kTxState_Reserved, kTpErrChannelNotInPreTransmitState);
# endif

  tpTxInfoStruct[tpChannel].withoutFC = 1;
}
# endif
#endif

#if defined (TP_ENABLE_DYNAMIC_CHANNELS)
# if (TP_USE_TX_CHANNEL_WITHOUT_FC == kTpOn)
/*******************************************************************************
*
* NAME:              TpTxWithFC
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         Channel handle
* RETURN VALUE:
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpTxWithFC(canuint8 tpChannel)
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, tpTxState[tpChannel].engine == kTxState_Reserved, kTpErrChannelNotInPreTransmitState);
#  endif

  tpTxInfoStruct[tpChannel].withoutFC = 0;
}
# endif
#endif

#if defined (TP_ENABLE_FC_MSG_FLOW_DYN_CHECK)
/*******************************************************************************
*
* NAME:              TpTxWithStrictFlowControlCheck
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         tpChannel handle, tpBool strict ( kTpTrue  = strict FC check,
*                                                      kTpFalse = no strict FC check)
* RETURN VALUE:      none
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpTxSetStrictFlowControlCheck(canuint8 tpChannel, tpBool strict)
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, tpTxState[tpChannel].engine == kTxState_Reserved, kTpErrChannelNotInPreTransmitState);
# endif

  tpTxInfoStruct[tpChannel].FCwfs = strict;
}
#endif
/* defined (TP_ENABLE_FC_MSG_FLOW_DYN_CHECK) */

#if defined (TP_ENABLE_DYN_CHANNEL_TIMING)
/*******************************************************************************
*
* NAME:              TpTxSetTimeoutFC
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         tpChannel handle, tTpEngineTimer time
* RETURN VALUE:      none
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpTxSetTimeoutFC(canuint8 tpChannel, tTpEngineTimer time)
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
# endif
  assertUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse);

  tpTxTimeoutFC[tpChannel] = time;
}

/*******************************************************************************
*
* NAME:              TpTxSetTimeoutConfirmation
*
* CALLED BY:         Application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         tpChannel handle, tTpEngineTimer time
* RETURN VALUE:      none
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpTxSetTimeoutConfirmation(canuint8 tpChannel, tTpEngineTimer time)
{
# if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpRxChannelCount, kTpErrChannelNrTooHigh);
# endif
  assertUser(tpChannel, tpRxState[tpChannel].engine != kRxState_Idle, kTpErrChannelNotInUse);

  tpTxConfirmationTimeout[tpChannel] = time;
}

#endif
/* defined (TP_ENABLE_DYN_CHANNEL_TIMING) */


#if ( (defined(TP_ENABLE_NORMAL_ADDRESSING)) )
# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
/*******************************************************************************
*
* NAME:              TpTxSetID, TpRxSetId
*
* CALLED BY:         Transport Layer
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         Channel handle
* RETURN VALUE:
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
static void TpTxSetID(canuintCPUtype tpChannel)
{
#  if (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn)
  if(tpTxInfoStruct[tpChannel].TransmitIDType == kTpCanIdTypeStd)
  {
    TPCANDYNTXOBJSETID(   tpTxInfoStruct[tpChannel].CanChannel)  (TP_TX_HANDLE(tpChannel), (canuint16)tpTxInfoStruct[tpChannel].TransmitID);
  }
  else
  {
    TPCANDYNTXOBJSETEXTID(tpTxInfoStruct[tpChannel].CanChannel)  (TP_TX_HANDLE(tpChannel), ((canuint16)(((canuint16)(tpTxInfoStruct[tpChannel].TransmitID>>16)))), (canuint16)((((canuint16) tpTxInfoStruct[tpChannel].TransmitID))) );
  }
#  elif (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
    TPCANDYNTXOBJSETEXTID(tpTxInfoStruct[tpChannel].CanChannel)  (TP_TX_HANDLE(tpChannel), ((canuint16)(((canuint16)(tpTxInfoStruct[tpChannel].TransmitID>>16)))), (canuint16)((((canuint16) tpTxInfoStruct[tpChannel].TransmitID))) );
#  else
    TPCANDYNTXOBJSETID(   tpTxInfoStruct[tpChannel].CanChannel)  (TP_TX_HANDLE(tpChannel), tpTxInfoStruct[tpChannel].TransmitID);
#  endif
}

static void TpRxSetID(canuintCPUtype tpChannel)
{
#  if (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn)
  if(tpRxInfoStruct[tpChannel].ReceiveIDType == kTpCanIdTypeStd)
  {
    TPCANDYNTXOBJSETID(   tpRxInfoStruct[tpChannel].CanChannel)  (TP_RX_HANDLE(tpChannel), (canuint16)tpRxInfoStruct[tpChannel].TransmitID);
  }
  else
  {
    TPCANDYNTXOBJSETEXTID(tpRxInfoStruct[tpChannel].CanChannel)  (TP_RX_HANDLE(tpChannel), ((canuint16)(((canuint16)(tpRxInfoStruct[tpChannel].TransmitID>>16)))), (canuint16)((((canuint16) tpRxInfoStruct[tpChannel].TransmitID))) );
  }
#  elif (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
    TPCANDYNTXOBJSETEXTID(tpRxInfoStruct[tpChannel].CanChannel)  (TP_RX_HANDLE(tpChannel), ((canuint16)(((canuint16)(tpRxInfoStruct[tpChannel].TransmitID>>16)))), (canuint16)((((canuint16) tpRxInfoStruct[tpChannel].TransmitID))) );
#  else
    TPCANDYNTXOBJSETID(   tpRxInfoStruct[tpChannel].CanChannel)  (TP_RX_HANDLE(tpChannel), tpRxInfoStruct[tpChannel].TransmitID);
#  endif
}
# endif
#endif



# if defined(TP_ENABLE_EXTENDED_ADDRESSING)
#  if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
/*******************************************************************************
*
* NAME:              TpTxSetBaseAddress
*
* CALLED BY:         application
* PRECONDITIONS:     TL has to be initialized before
*
* PARAMETER:         tpChannel handle, BaseAddress
* RETURN VALUE:      none
* DESCRIPTION:
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
void TP_API_CALL_TYPE TpTxSetBaseAddress(canuint8 tpChannel, canuint16 baseAddress)
{
#   if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, tpTxState[tpChannel].engine == kTxState_Reserved, kTpErrChannelNotInPreTransmitState);
#   endif

  tpTxInfoStruct[tpChannel].BaseAddress = baseAddress;
}
#  endif
# endif

#if (TP_USE_FAST_TX_TRANSMISSION == kTpOn)
# if (TP_USE_STMIN_OF_FC == kTpOn)
/*******************************************************************************
* NAME:              TpTxGetSTminInFrame
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         tpChannel
* RETURN VALUE:      none
*
* REENTRANCE:        Possible for different channels
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
canuint8 TP_API_CALL_TYPE TpTxGetSTminInFrame(void)
#  else
canuint8 TP_API_CALL_TYPE TpTxGetSTminInFrame(canuint8 tpChannel)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertReturnUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh,0xff);
#  endif
  /* assertUser(tpChannel, tpTxState[tpChannel].engine == kTxState_WaitFC, );*/

  return tpTxInfoStruct[tpChannel].STminInFrame;
}
# endif
#endif


#if defined (TP_TEST_ROUTINE_CONF_TIMEOUT)
/*******************************************************************************
* NAME:              TpTxTestForceConfirmationTimeout
*
* CALLED BY:         application
* PRECONDITIONS:
*
* PARAMETER:
* RETURN VALUE:
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpTxTestForceConfirmationTimeout(void)
#  else
void TP_API_CALL_TYPE TpTxTestForceConfirmationTimeout(canuint8 tpChannel)
#  endif
{
  tpTxState[tpChannel].forceConfTimeout = 1;
}
#endif

#if defined (TP_CAN_CODEDOUBLED)
# if (kTpNumberOfCanChannels > 1)
/*******************************************************************************
* NAME:              MultiChannel Systems
*
* CALLED BY:         CAN-Driver
* PRECONDITIONS:
*
* PARAMETER:
* RETURN VALUE:
*******************************************************************************/
static void TpDrvTxConfirmation(canuintCPUtype canChannel);
static void TpDrvRxConfirmation(canuintCPUtype canChannel);

void TpDrvTxConfirmation_0(CanTransmitHandle txObject)
{
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)txObject;
#  endif
  TpDrvTxConfirmation(0);
}
void TpDrvRxConfirmation_0(CanTransmitHandle txObject)
{
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)txObject;
#  endif
  TpDrvRxConfirmation(0);
}
void TpDrvTxConfirmation_1(CanTransmitHandle txObject)
{
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)txObject;
#  endif
  TpDrvTxConfirmation(1);
}
void TpDrvRxConfirmation_1(CanTransmitHandle txObject)
{
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)txObject;
#  endif
  TpDrvRxConfirmation(1);
}
void TpDrvTxConfirmation_2(CanTransmitHandle txObject)
{
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)txObject;
#  endif
  TpDrvTxConfirmation(2);
}
void TpDrvRxConfirmation_2(CanTransmitHandle txObject)
{
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)txObject;
#  endif
  TpDrvRxConfirmation(2);
}
void TpDrvTxConfirmation_3(CanTransmitHandle txObject)
{
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)txObject;
#  endif
  TpDrvTxConfirmation(3);
}
void TpDrvRxConfirmation_3(CanTransmitHandle txObject)
{
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)txObject;
#  endif
  TpDrvRxConfirmation(3);
}
void TpDrvTxConfirmation_4(CanTransmitHandle txObject)
{
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)txObject;
#  endif
  TpDrvTxConfirmation(4);
}
void TpDrvRxConfirmation_4(CanTransmitHandle txObject)
{
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)txObject;
#  endif
  TpDrvRxConfirmation(4);
}

#  if (TP_USE_GATEWAY_API == kTpOn)
#   if defined ( C_SINGLE_RECEIVE_BUFFER )
#    error This CAN driver do not supported the Gateway API
#   endif
#  endif
# endif
#endif

#  if defined (TP_CAN_CODEDOUBLED)
/*******************************************************************************
* NAME:              MultiChannel Systems
*
* CALLED BY:         CAN-Driver
* PRECONDITIONS:
*
* PARAMETER:
* RETURN VALUE:
*******************************************************************************/
extern canuint8 TpPrecopy(CanRxInfoStructPtr rxStruct);

#   if ( kCanNumberOfChannels > 0 ) /* more than 0 canChannel ? */
#    if defined ( C_MULTIPLE_RECEIVE_BUFFER )
canuint8 TpPrecopy_0(CanChipDataPtr rxDataPtr)
#    endif
#    if defined ( C_SINGLE_RECEIVE_BUFFER )
canuint8 TpPrecopy_0(CanReceiveHandle rxObject)
#    endif
{
  tCanRxInfoStruct rxStruct;

  rxStruct.Channel = 0;
#    if defined ( C_MULTIPLE_RECEIVE_BUFFER )
  rxStruct.pChipData = rxDataPtr;
#    endif
#    if defined ( C_SINGLE_RECEIVE_BUFFER )
#     if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)rxObject;
#     endif
  rxStruct.pChipData = (canuint8*)CanRDSPtr_0;
#    endif
#    if (TP_USE_GATEWAY_API == kTpOn)
  rxStruct.pChipMsgObj = pCanChipMsgObject_0;
#    endif
  rxStruct.CanRxActualId = CanRxActualId_0;
  rxStruct.CanRxActualDLC = CanRxActualDLC_0;
  return TpPrecopy(&rxStruct);
}
#   endif
#   if ( kCanNumberOfChannels > 1 ) /* more than 1 canChannel ? */
#    if defined ( C_MULTIPLE_RECEIVE_BUFFER )
canuint8 TpPrecopy_1(CanChipDataPtr rxDataPtr)
#    endif
#    if defined ( C_SINGLE_RECEIVE_BUFFER )
canuint8 TpPrecopy_1(CanReceiveHandle rxObject)
#    endif
{
  tCanRxInfoStruct rxStruct;

  rxStruct.Channel = 1;
#    if defined ( C_MULTIPLE_RECEIVE_BUFFER )
  rxStruct.pChipData = rxDataPtr;
#    endif
#    if defined ( C_SINGLE_RECEIVE_BUFFER )
#     if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)rxObject;
#     endif
  rxStruct.pChipData = (canuint8*)CanRDSPtr_1;
#    endif
#    if (TP_USE_GATEWAY_API == kTpOn)
  rxStruct.pChipMsgObj = pCanChipMsgObject_1;
#    endif
  rxStruct.CanRxActualId = CanRxActualId_1;
  rxStruct.CanRxActualDLC = CanRxActualDLC_1;
  return TpPrecopy(&rxStruct);
}
#   endif
#   if ( kCanNumberOfChannels > 2 ) /* more than 2 canChannel ? */
#    if defined ( C_MULTIPLE_RECEIVE_BUFFER )
canuint8 TpPrecopy_2(CanChipDataPtr rxDataPtr)
#    endif
#    if defined ( C_SINGLE_RECEIVE_BUFFER )
canuint8 TpPrecopy_2(CanReceiveHandle rxObject)
#    endif
{
  tCanRxInfoStruct rxStruct;

  rxStruct.Channel = 2;
#    if defined ( C_MULTIPLE_RECEIVE_BUFFER )
  rxStruct.pChipData = rxDataPtr;
#    endif
#    if defined ( C_SINGLE_RECEIVE_BUFFER )
#     if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)rxObject;
#     endif
  rxStruct.pChipData = (canuint8*)CanRDSPtr_2;
#    endif
#    if (TP_USE_GATEWAY_API == kTpOn)
  rxStruct.pChipMsgObj = pCanChipMsgObject_2;
#    endif
  rxStruct.CanRxActualId = CanRxActualId_2;
  rxStruct.CanRxActualDLC = CanRxActualDLC_2;
  return TpPrecopy(&rxStruct);
}
#   endif
#   if ( kCanNumberOfChannels > 3 ) /* more than 3 canChannel ? */
#    if defined ( C_MULTIPLE_RECEIVE_BUFFER )
canuint8 TpPrecopy_3(CanChipDataPtr rxDataPtr)
#    endif
#    if defined ( C_SINGLE_RECEIVE_BUFFER )
canuint8 TpPrecopy_3(CanReceiveHandle rxObject)
#    endif
{
  tCanRxInfoStruct rxStruct;

  rxStruct.Channel = 3;
#    if defined ( C_MULTIPLE_RECEIVE_BUFFER )
  rxStruct.pChipData = rxDataPtr;
#    endif
#    if defined ( C_SINGLE_RECEIVE_BUFFER )
#     if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)rxObject;
#     endif
  rxStruct.pChipData = (canuint8*)CanRDSPtr_3;
#    endif
#    if (TP_USE_GATEWAY_API == kTpOn)
  rxStruct.pChipMsgObj = pCanChipMsgObject_3;
#    endif
  rxStruct.CanRxActualId = CanRxActualId_3;
  rxStruct.CanRxActualDLC = CanRxActualDLC_3;
  return TpPrecopy(&rxStruct);
}
#   endif
#   if ( kCanNumberOfChannels > 4 ) /* more than 4 canChannel ? */
#    if defined ( C_MULTIPLE_RECEIVE_BUFFER )
canuint8 TpPrecopy_4(CanChipDataPtr rxDataPtr)
#    endif
#    if defined ( C_SINGLE_RECEIVE_BUFFER )
canuint8 TpPrecopy_4(CanReceiveHandle rxObject)
#    endif
{
  tCanRxInfoStruct rxStruct;

  rxStruct.Channel = 4;
#    if defined ( C_MULTIPLE_RECEIVE_BUFFER )
  rxStruct.pChipData = rxDataPtr;
#    endif
#    if defined ( C_SINGLE_RECEIVE_BUFFER )
#     if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  (void)rxObject;
#     endif
  rxStruct.pChipData = (canuint8*)CanRDSPtr_4;
#    endif
#    if (TP_USE_GATEWAY_API == kTpOn)
  rxStruct.pChipMsgObj = pCanChipMsgObject_4;
#    endif
  rxStruct.CanRxActualId = CanRxActualId_4;
  rxStruct.CanRxActualDLC = CanRxActualDLC_4;
  return TpPrecopy(&rxStruct);
}
#   endif
#  endif

#if defined TP_FUNC_ENABLE_RECEPTION

typedef struct
{
  tTpBufferPtr DataBufferPtr;
/* Description : List of pointer to receive buffers from the application      */
/******************************************************************************/
  canuint16 DataLength;
/* Description : Length of data to be transmitted. The size of this variable  */
/*               limits the maximum size of messages.                         */
/* Val. range / Coding: 0..4095                                               */
/******************************************************************************/
# if ( defined(TP_FUNC_ENABLE_EXTENDED_ADDRESSING)     || \
       defined(TP_FUNC_ENABLE_NORMAL_FIXED_ADDRESSING) || \
       defined(TP_FUNC_ENABLE_MIXED_29_ADDRESSING) )
  canuint8 TargetAddress;
/* Description :                                                              */
/* Val. range / Coding: 0..0xff                                               */
/******************************************************************************/
# endif
# if ( (defined(TP_FUNC_ENABLE_EXTENDED_ADDRESSING) && defined (TP_RX_BASE_ADDRESS) ) || \
       defined(TP_FUNC_ENABLE_NORMAL_FIXED_ADDRESSING) || \
       defined(TP_FUNC_ENABLE_MIXED_29_ADDRESSING) )
  canuint8 SourceAddress;
/* Description :                                                              */
/* Val. range / Coding: 0..0xff                                               */
/******************************************************************************/
# endif
# if defined(TP_FUNC_ENABLE_MIXED_29_ADDRESSING) || \
     defined(TP_FUNC_ENABLE_MIXED_11_ADDRESSING)

  canuint8 AddressExtension;
/* Description :                                                              */
/* Val. range / Coding: 0..0xff                                               */
/******************************************************************************/
# endif
# if defined(TP_ENABLE_DYNAMIC_CHANNELS)
#  if defined(TP_FUNC_ENABLE_NORMAL_ADDRESSING) || \
      defined(TP_FUNC_ENABLE_MIXED_11_ADDRESSING)
#   if (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
  canuint32 TransmitID;
/* Description : For dynamic normal addressing, the Transmit ID               */
/*               will be stored in RAM                                        */
/* Val. range / Coding: 0..0x1fffffff                                         */
/******************************************************************************/
#    if (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn)
  canuint8  TransmitIDType;
/* Description : For dynamic normal addressing, the Transmit ID Type          */
/*               will be stored in RAM                                        */
/* Val. range / Coding: kTpCanIdTypeStd, kTpCanIdTypeExt                      */
/******************************************************************************/
#    endif
  canuint32 ReceiveID;
/* Description : For dynamic normal addressing, the Receive ID                */
/*               will be stored in RAM                                        */
/* Val. range / Coding: 0..0x1fffffff                                         */
/******************************************************************************/
#    if (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn)
  canuint8  ReceiveIDType;
/* Description : For dynamic normal addressing, the Receive ID type           */
/*               will be stored in RAM                                        */
/* Val. range / Coding: kTpCanIdTypeStd, kTpCanIdTypeExt                      */
/******************************************************************************/
#    endif
  canuint32 FcReceiveID;
/* Description : For dynamic normal addressing, the Receive ID for physical   */
/*               reception of FCs in case of segmented transmissions due to   */
/*               functional requests                                          */
/*               will be stored in RAM                                        */
/* Val. range / Coding: 0..0x1fffffff                                         */
/******************************************************************************/
#    if (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
  canuint8  FcReceiveIDType;
/* Description : For dynamic normal addressing, the FcReceiveID Type          */
/*               will be stored in RAM                                        */
/* Val. range / Coding: kTpCanIdTypeStd, kTpCanIdTypeExt                      */
/******************************************************************************/
#    endif
#   else
  canuint16 TransmitID;
/* Description : For dynamic normal addressing, the Tranmit ID                */
/*               will be stored in RAM                                        */
/* Val. range / Coding: 0..0x7ff                                              */
/******************************************************************************/
  canuint16 ReceiveID;
/* Description : For dynamic normal addressing, the Receive ID                */
/*               will be stored in RAM                                        */
/* Val. range / Coding: 0..0x7ff                                              */
/******************************************************************************/
  canuint16 FcReceiveID;
/* Description : For dynamic normal addressing, the Receive ID for physical   */
/*               reception of FCs in case of segmented transmissions due to   */
/*               functional requests                                          */
/*               will be stored in RAM                                        */
/* Val. range / Coding: 0..0x7ff                                              */
/******************************************************************************/
#   endif
#  endif
# endif
#  if (kTpNumberOfCanChannels > 1)
  canuint8 CanChannel;
/* Description : For a MultiCAN System, the physical CanChannel               */
/*               have to be stored in RAM for being changed by the            */
/*               application. To support this, the additional functions       */
/*               TpTxSetCanChannel and TpRxGetCanChannel are provided.        */
/* Val. range / Coding: 0..7                                                  */
/******************************************************************************/
#  endif
} tTpFuncInfoStruct;

# if defined TP_FUNC_ENABLE_EXTENDED_ADDRESSING
#  define FORMAT_FUNC_OFFSET   1
# else
#  define FORMAT_FUNC_OFFSET   0
# endif

MEMORY_NEAR static tTpRxStateEngine tpFuncState_engine;

MEMORY_NEAR_TP_SAVE static tTpFuncInfoStruct tpFuncInfoStruct;


void TpFuncInit ( void )
{
  tpFuncState_engine = kRxState_Idle;

}

#   if ( defined (C_MULTIPLE_RECEIVE_CHANNEL) ||\
         defined (C_SINGLE_RECEIVE_CHANNEL) ||\
         defined (TP_CAN_CODEDOUBLED) )
canuint8 TP_INTERNAL_CALL_TYPE TpFuncPrecopy(CanRxInfoStructPtr rxStruct)
#   else
#    if defined ( C_MULTIPLE_RECEIVE_BUFFER )
canuint8 TP_INTERNAL_CALL_TYPE TpFuncPrecopy(CanChipDataPtr rxDataPtr)
#    endif
#    if defined ( C_SINGLE_RECEIVE_BUFFER )
canuint8 TP_INTERNAL_CALL_TYPE TpFuncPrecopy(CanReceiveHandle rxObject)
#    endif
#   endif
{
#  if defined (TP_FUNC_ENABLE_APPL_PRECOPY)
#   if ( defined(TP_FUNC_ENABLE_EXTENDED_ADDRESSING) || \
         defined(TP_FUNC_ENABLE_NORMAL_FIXED_ADDRESSING) )
#    if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
  canuint8 tpEcuNr;
#    else
  canuint8 FuncTpPrecopyReturn;
#    endif
#   endif
#  endif

#if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
# if defined (TP_ENABLE_SINGLE_CHAN_MULTICONN )
#  if defined(TP_ENABLE_NORMAL_ADDRESSING)
  CanTransmitHandle handle;
#  endif
# endif
#endif

#if defined (TP_FUNC_ENABLE_CUSTOM_RX_MEMCPY)
# if defined (TP_ENABLE_INTERMEDIATE_CANCHIP_BUFFER)
  vuint8 pFuncIntermediateCANChipData[8];
# endif
#endif

#if defined (TP_ENABLE_SINGLE_MSG_OBJ)
#endif

#if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
#endif

  /**********************************************************************************/
  /* Multiple Nodes, multiple CAN channels ******************************************/
  /**********************************************************************************/
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#  if defined ( TP_ENABLE_SINGLE_CHAN_MULTICONN )
#   if defined(TP_ENABLE_NORMAL_ADDRESSING)
  for (handle = 0; handle < kTpRxTxHandleFieldSize; handle++)
  {
    if ((kTpRxFuncHandle_Field[handle] == RX_HANDLE))
    { /* this handle is used for transmission */
      /* connHandle = handle; this is done after GetBuffer callback */
      break;
    }
  }
  if (handle >= kTpRxTxHandleFieldSize)
  {
    return kCanNoCopyData;
  }
#   endif
#  endif
# endif

  if (tpFuncState_engine == kRxState_Idle)
  {
    /**********************************************************************************/
    /**** Normal Addressing ***********************************************************/
    /**********************************************************************************/
# if defined(TP_ENABLE_DYNAMIC_CHANNELS)
#  if defined(TP_FUNC_ENABLE_NORMAL_ADDRESSING) || \
      defined(TP_FUNC_ENABLE_MIXED_11_ADDRESSING)
    tpFuncInfoStruct.ReceiveID     = CAN_RX_ACTUAL_ID;
#  if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
    tpFuncInfoStruct.ReceiveIDType = (canuint8)((CAN_RX_ACTUAL_ID_TYPE == 0) ? kTpCanIdTypeStd : kTpCanIdTypeExt);
#  endif
    /* If no segmented transmission appears the ReceiveID does not matter the further */
    /* processing. Otherwise the following FCs must be received on the pysical ID.    */
    /* tpFuncInfoStruct.FcReceiveID = tpFuncInfoStruct.ReceiveID;                     */
#  endif
# endif
    /**********************************************************************************/
    /**** Normal Fixed Addressing *****************************************************/
    /**** Mixed Addressing ************************************************************/
    /**********************************************************************************/
# if defined (TP_FUNC_ENABLE_NORMAL_FIXED_ADDRESSING) || \
       defined(TP_FUNC_ENABLE_MIXED_29_ADDRESSING)
    tpFuncInfoStruct.SourceAddress = (canuint8)CAN_RX_ACTUAL_ID_EXT_LO; /* ( CAN_RX_ACTUAL_ID & 0x000000ff); */
    tpFuncInfoStruct.TargetAddress = (canuint8)CAN_RX_ACTUAL_ID_EXT_MID_LO; /* ((CAN_RX_ACTUAL_ID & 0x0000ff00) >> 8); */
# endif
    /************************************************************************************/
    /**** Extended Addressing ***********************************************************/
    /************************************************************************************/
# if defined (TP_FUNC_ENABLE_EXTENDED_ADDRESSING)
#  if defined (TP_RX_BASE_ADDRESS)
    tpFuncInfoStruct.SourceAddress = (canuint8)(CAN_RX_ACTUAL_ID - TP_RX_BASE_ADDRESS);
#  endif
    tpFuncInfoStruct.TargetAddress = *(CanChipDataPtr)(FRAME_DATA_PTR + TARGET_OFFSET);
# endif
    /************************************************************************************/
    /**** Mixed Addressing        *******************************************************/
    /************************************************************************************/
# if defined(TP_FUNC_ENABLE_MIXED_29_ADDRESSING) || \
    defined(TP_FUNC_ENABLE_MIXED_11_ADDRESSING)
    tpFuncInfoStruct.AddressExtension = *(CanChipDataPtr)(FRAME_DATA_PTR + ADDRESS_EXTENSION_OFFSET);
# endif

    /************************************************************************************/
    /**** Multiple CAN channel system ***************************************************/
    /************************************************************************************/
# if (kTpNumberOfCanChannels > 1)
    tpFuncInfoStruct.CanChannel = (canbittype)((rxStruct->Channel) & kTpMaxCanChannels);
# endif
    /**********************************************************************************/
    /* ApplTpPrecopy ******************************************************************/
    /**** Normal Fixed Addressing ***********************************************************/
    /**** Extended Addressing *********************************************************/
    /**** Mixed Addressing ************************************************************/
    /**********************************************************************************/
# if defined (TP_FUNC_ENABLE_APPL_PRECOPY)
#  if ( defined(TP_FUNC_ENABLE_EXTENDED_ADDRESSING) || \
        defined(TP_FUNC_ENABLE_NORMAL_FIXED_ADDRESSING) )
#   if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
#    if defined(TP_FUNC_ENABLE_MIXED_29_ADDRESSING)
#     if (TP_USE_GATEWAY_API == kTpOn)
    tpEcuNr = (canuint8)(__ApplFuncTpPrecopy(tpFuncInfoStruct.TargetAddress,tpFuncInfoStruct.AddressExtension, rxStruct));
#     else
    tpEcuNr = (canuint8)(__ApplFuncTpPrecopy(tpFuncInfoStruct.TargetAddress,tpFuncInfoStruct.AddressExtension));
#     endif
    if (tpEcuNr != 0xff)
#    else
#     if (TP_USE_GATEWAY_API == kTpOn)
    tpEcuNr = (canuint8)(__ApplFuncTpPrecopy(tpFuncInfoStruct.TargetAddress, rxStruct));
#     else
    tpEcuNr = (canuint8)(__ApplFuncTpPrecopy(tpFuncInfoStruct.TargetAddress));
#     endif
    if (tpEcuNr != 0xff)
#    endif
#   else
#    if defined(TP_FUNC_ENABLE_MIXED_29_ADDRESSING)
#     if (TP_USE_GATEWAY_API == kTpOn)
    FuncTpPrecopyReturn = (canuint8)(__ApplFuncTpPrecopy(tpFuncInfoStruct.TargetAddress,tpFuncInfoStruct.AddressExtension, rxStruct));
#     else
    FuncTpPrecopyReturn = (canuint8)(__ApplFuncTpPrecopy(tpFuncInfoStruct.TargetAddress,tpFuncInfoStruct.AddressExtension));
#     endif
    if (FuncTpPrecopyReturn != 0xff)
#    else
#     if (TP_USE_GATEWAY_API == kTpOn)
    FuncTpPrecopyReturn = (canuint8)(__ApplFuncTpPrecopy(tpFuncInfoStruct.TargetAddress, rxStruct));
#     else
    FuncTpPrecopyReturn = (canuint8)(__ApplFuncTpPrecopy(tpFuncInfoStruct.TargetAddress));
#     endif
    if (FuncTpPrecopyReturn != 0xff)
#    endif
#   endif
#  endif
# endif
    {
      if ((*(CanChipDataPtr)(TPCI_OFFSET + FORMAT_FUNC_OFFSET + FRAME_DATA_PTR) & 0xF0) == 0x00 )
      { /* Request is SF */
        tpFuncInfoStruct.DataLength = *(CanChipDataPtr)(TPCI_OFFSET + FORMAT_FUNC_OFFSET + FRAME_DATA_PTR);
# if defined (TP_ENABLE_ISO_15765_2_2)
        if (tpFuncInfoStruct.DataLength  != 0)
# endif
        {
          /*Store length for app usage*/
# if   defined (TP_FUNC_ENABLE_FIX_DLC_CHECK)
          if (CAN_RX_ACTUAL_DLC == FRAME_LENGTH)
# elif defined (TP_FUNC_ENABLE_VARIABLE_DLC_CHECK)
            /* Checking CAN-DLC */
          if (CAN_RX_ACTUAL_DLC >= (tpFuncInfoStruct.DataLength + SF_OFFSET + FORMAT_FUNC_OFFSET))
# else
# endif
          {
            if (tpFuncInfoStruct.DataLength <= (FRAME_LENGTH - (SF_OFFSET + FORMAT_FUNC_OFFSET)))
            { /* Is maximum length of a SingleFrame exeeded ? */
# if defined(TP_ENABLE_DYNAMIC_CHANNELS)
#  if defined(TP_FUNC_ENABLE_NORMAL_ADDRESSING) || \
      defined(TP_FUNC_ENABLE_MIXED_11_ADDRESSING)
#   if defined  (TP_ENABLE_RUNTIME_CHECK )
#    if (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
              tpFuncInfoStruct.TransmitID = 0xffffffff;
#    else
              tpFuncInfoStruct.TransmitID = 0xffff;
#    endif
#   endif
#  endif
# endif
# if defined (TP_FUNC_ENABLE_APPL_PRECOPY)
#  if ( defined(TP_FUNC_ENABLE_EXTENDED_ADDRESSING) || \
        defined(TP_FUNC_ENABLE_NORMAL_FIXED_ADDRESSING) )
#   if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
              tpFuncInfoStruct.TargetAddress = tpEcuNr;
#   endif
#  endif
# endif
              tpFuncInfoStruct.DataBufferPtr.DataCanBufferPtr = (CanChipDataPtr)(SF_OFFSET + FORMAT_FUNC_OFFSET + FRAME_DATA_PTR);
              tpFuncInfoStruct.DataBufferPtr.DataApplBufferPtr = __ApplTpFuncGetBuffer(tpFuncInfoStruct.DataLength);

              if(tpFuncInfoStruct.DataBufferPtr.DataApplBufferPtr != V_NULL)
              { /* data buffer is valid */
# if defined(TP_ENABLE_DYNAMIC_CHANNELS)
#  if defined(TP_FUNC_ENABLE_NORMAL_ADDRESSING) || \
      defined(TP_FUNC_ENABLE_MIXED_11_ADDRESSING)
#   if defined  (TP_ENABLE_RUNTIME_CHECK )
                if (tpFuncInfoStruct.TransmitID <= CAN_MAX_ID)
#   endif
#  endif
# endif
                  /**** COPY DATA ********************************************/
                {
# if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
#  if defined ( TP_ENABLE_SINGLE_CHAN_MULTICONN )
#   if defined(TP_ENABLE_NORMAL_ADDRESSING)
                  connHandle = handle;
#   endif
#  endif
# endif
# if (kTpNumberOfCanChannels > 1)
# endif

# if defined (TP_FUNC_ENABLE_CUSTOM_RX_MEMCPY)
#  if defined (TP_ENABLE_INTERMEDIATE_CANCHIP_BUFFER)
                  CanCopyFromCan(pFuncIntermediateCANChipData, (CanChipDataPtr)(SF_OFFSET + FORMAT_FUNC_OFFSET + FRAME_DATA_PTR), tpFuncInfoStruct.DataLength);
                  __ApplTpFuncCopyFromCAN((canuint8*)(pFuncIntermediateCANChipData), tpFuncInfoStruct.DataLength);
#  else
                  __ApplTpFuncCopyFromCAN((canuint8*)(SF_OFFSET + FORMAT_FUNC_OFFSET + FRAME_DATA_PTR), tpFuncInfoStruct.DataLength);
#  endif
# else
                  {
                    cansintCPUtype i;
                    for (i = (cansintCPUtype)(tpFuncInfoStruct.DataLength-1); i>=0; i--)
                    {
                      *(tpFuncInfoStruct.DataBufferPtr.DataApplBufferPtr + i) = *((CanChipDataPtr)(SF_OFFSET + FORMAT_FUNC_OFFSET + FRAME_DATA_PTR) + i);
                    }
                  }
# endif
                  tpFuncState_engine = kRxState_ApplInformed;
                  /* Callback - ApplIndication a SingleFrame is completely received */
                  __ApplTpFuncIndication(tpFuncInfoStruct.DataLength);
                }
              }
            }
          }
        } /* else { do nothing: tpFuncState_engine still in idle state } */
      }
    }
  }
  return kCanNoCopyData;
}

#if defined (TP_ENABLE_OBD_PRECOPY)
#  if ( defined (C_MULTIPLE_RECEIVE_CHANNEL) ||\
        defined (C_SINGLE_RECEIVE_CHANNEL) ||\
        defined (TP_CAN_CODEDOUBLED) )
canuint8 TP_INTERNAL_CALL_TYPE TpOBDPrecopy(CanRxInfoStructPtr rxStruct)
#  else
#   if defined ( C_MULTIPLE_RECEIVE_BUFFER )
canuint8 TP_INTERNAL_CALL_TYPE TpOBDPrecopy(CanChipDataPtr rxDataPtr)
#   endif
#   if defined ( C_SINGLE_RECEIVE_BUFFER )
canuint8 TP_INTERNAL_CALL_TYPE TpOBDPrecopy(CanReceiveHandle rxObject)
#   endif
#  endif
{
#if defined (TP_FUNC_ENABLE_CUSTOM_RX_MEMCPY)
# if defined (TP_ENABLE_INTERMEDIATE_CANCHIP_BUFFER)
  vuint8 pFuncIntermediateCANChipData[8];
# endif
#endif

#if defined (TP_ENABLE_SINGLE_MSG_OBJ)
#endif

  if (tpFuncState_engine == kRxState_Idle)
  {
    /**********************************************************************************/
    /**** Normal Addressing ***********************************************************/
    /**********************************************************************************/
# if defined(TP_ENABLE_DYNAMIC_CHANNELS)
    tpFuncInfoStruct.ReceiveID = CAN_RX_ACTUAL_ID;
# endif
    /************************************************************************************/
    /**** Multiple CAN channel system ***************************************************/
    /************************************************************************************/
# if (kTpNumberOfCanChannels > 1)
    tpFuncInfoStruct.CanChannel = (canbittype)(rxStruct->Channel);
# endif

    if ((*(CanChipDataPtr)(TPCI_OFFSET + FRAME_DATA_PTR) & 0xF0) == 0x00 )
    { /* Request is SF */
      tpFuncInfoStruct.DataLength = *(CanChipDataPtr)(TPCI_OFFSET + FRAME_DATA_PTR);
# if defined (TP_ENABLE_ISO_15765_2_2)
      if (tpFuncInfoStruct.DataLength  != 0)
# endif
      {
        /*Store length for app usage*/
        if (CAN_RX_ACTUAL_DLC == FRAME_LENGTH)
        {
          if (tpFuncInfoStruct.DataLength <= (FRAME_LENGTH - (SF_OFFSET)))
          { /* Is maximum length of a SingleFrame exeeded ? */
# if defined(TP_ENABLE_DYNAMIC_CHANNELS)
#  if defined  (TP_ENABLE_RUNTIME_CHECK )
#   if (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
            tpFuncInfoStruct.TransmitID = 0xffffffff;
#   else
            tpFuncInfoStruct.TransmitID = 0xffff;
#   endif
#  endif
# endif
            tpFuncInfoStruct.DataBufferPtr.DataCanBufferPtr = (CanChipDataPtr)(SF_OFFSET + FRAME_DATA_PTR);
            tpFuncInfoStruct.DataBufferPtr.DataApplBufferPtr = __ApplTpFuncGetBuffer(tpFuncInfoStruct.DataLength);

            if(tpFuncInfoStruct.DataBufferPtr.DataApplBufferPtr != V_NULL)
            { /* data buffer is valid */
# if defined(TP_ENABLE_DYNAMIC_CHANNELS)
#   if defined  (TP_ENABLE_RUNTIME_CHECK )
              if (tpFuncInfoStruct.TransmitID <= CAN_MAX_ID)
#   endif
# endif
                /**** COPY DATA ********************************************/
              {
# if defined (TP_FUNC_ENABLE_CUSTOM_RX_MEMCPY)
#  if defined (TP_ENABLE_INTERMEDIATE_CANCHIP_BUFFER)
                CanCopyFromCan(pFuncIntermediateCANChipData, (CanChipDataPtr)(SF_OFFSET + FRAME_DATA_PTR), tpFuncInfoStruct.DataLength);
                __ApplTpFuncCopyFromCAN((canuint8*)(pFuncIntermediateCANChipData), tpFuncInfoStruct.DataLength);
#  else
                __ApplTpFuncCopyFromCAN((canuint8*)(SF_OFFSET + FRAME_DATA_PTR), tpFuncInfoStruct.DataLength);
#  endif
# else
                {
                  cansintCPUtype i;
                  for (i = (cansintCPUtype)(tpFuncInfoStruct.DataLength-1); i>=0; i--)
                  {
                    *(tpFuncInfoStruct.DataBufferPtr.DataApplBufferPtr + i) = *((CanChipDataPtr)(SF_OFFSET + FRAME_DATA_PTR) + i);
                  }
                }
# endif
                tpFuncState_engine = kRxState_ApplInformed;
                /* Callback - ApplIndication a SingleFrame is completely received */
                __ApplTpFuncIndication(tpFuncInfoStruct.DataLength);
              }
            }
          }
        }
      } /* else { do nothing: tpFuncState_engine still in idle state } */
    }
  }
  return kCanNoCopyData;
}
#endif

/*******************************************************************************
* NAME:              TpFuncResetChannel
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:      none
*******************************************************************************/
void TP_API_CALL_TYPE TpFuncResetChannel(void)
{
  tpFuncState_engine = kRxState_Idle;
}

# if defined (TP_ENABLE_DYNAMIC_CHANNELS)
/*******************************************************************************
* NAME:              TpFuncSetResponse
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:      none
*******************************************************************************/
#  if defined (TP_ENABLE_SINGLE_CHANNEL_TP)
void TP_API_CALL_TYPE TpFuncSetResponse(void)
#  else
void TP_API_CALL_TYPE TpFuncSetResponse(canuint8 tpChannel)
#  endif
{
#  if defined (TP_ENABLE_MULTI_CHANNEL_TP)
  assertUser(tpChannel, tpChannel < kTpTxChannelCount, kTpErrChannelNrTooHigh);
  assertUser(tpChannel, (tpTxState[tpChannel].engine == kTxState_Reserved) || (tpTxState[tpChannel].engine == kTxState_WaitForMinTimer), kTpErrChannelNotInPreTransmitState);
#  endif
#  if (TP_USE_TX_CHANNEL_WITHOUT_FC == kTpOn)
  assertUser(tpChannel, tpTxInfoStruct[tpChannel].withoutFC == 0, kTpTxErrSetResponseWithoutFc);
#  endif

#  if (defined(TP_FUNC_ENABLE_EXTENDED_ADDRESSING) && defined (TP_RX_BASE_ADDRESS) )
#   if defined(TP_FUNC_ENABLE_EXTENDED_ADDRESSING)      || \
       defined(TP_FUNC_ENABLE_NORMAL_FIXED_ADDRESSING)  || \
       defined(TP_FUNC_ENABLE_MIXED_29_ADDRESSING)
#    if defined  (TP_ENABLE_RUNTIME_CHECK )
  /* Set validity for TargetAddress */
  tpTxInfoStruct[tpChannel].TargetAddressIsValid = 1;
#    endif
  tpTxInfoStruct[tpChannel].TargetAddress = tpFuncInfoStruct.SourceAddress;
#   endif
#  endif
#  if defined(TP_ENABLE_EXTENDED_ADDRESSING)
#   if (TP_USE_MULTIPLE_BASEADDRESS == kTpOn)
#  error Not supported, yet!
  tpTxInfoStruct[tpChannel].BaseAddress = ApplTpFuncGet...;
#   endif
#  endif

#  if defined(TP_FUNC_ENABLE_NORMAL_ADDRESSING) || \
      defined(TP_FUNC_ENABLE_MIXED_11_ADDRESSING)
#   if defined(TP_ENABLE_NORMAL_ADDRESSING)
  tpTxInfoStruct[tpChannel].TransmitID = tpFuncInfoStruct.TransmitID;
  /* If no segmented transmission appears the ReceiveID does not matter the further */
  /* processing. Otherwise the following FCs must be received on the pysical ID.    */
  tpTxInfoStruct[tpChannel].ReceiveID  = tpFuncInfoStruct.FcReceiveID;
#    if (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn)
  tpTxInfoStruct[tpChannel].TransmitIDType = tpFuncInfoStruct.TransmitIDType;
  tpTxInfoStruct[tpChannel].ReceiveIDType  = tpFuncInfoStruct.FcReceiveIDType;
#    endif
#   endif
#  endif

#  if (kTpNumberOfCanChannels > 1)
  tpTxInfoStruct[tpChannel].CanChannel = tpFuncInfoStruct.CanChannel;
#  endif
#  if (TP_USE_MULTIPLE_ECU_NR == kTpOn)
#   if defined  (TP_ENABLE_RUNTIME_CHECK )
  /* Set validity for EcuNumber */
  tpTxInfoStruct[tpChannel].EcuNumberIsValid = 1;
#   endif
  tpTxInfoStruct[tpChannel].EcuNumber = tpFuncInfoStruct.TargetAddress;
#  endif
}
# endif

# if ( (defined(TP_FUNC_ENABLE_EXTENDED_ADDRESSING) && defined (TP_RX_BASE_ADDRESS) ) || \
       defined(TP_FUNC_ENABLE_NORMAL_FIXED_ADDRESSING) || \
       defined(TP_FUNC_ENABLE_MIXED_29_ADDRESSING) )
/*******************************************************************************
* NAME:              TpFuncGetSourceAddress
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:      none
*******************************************************************************/
canuint8 TP_API_CALL_TYPE TpFuncGetSourceAddress(void)
{
  return tpFuncInfoStruct.SourceAddress;
}
# endif

# if ( defined(TP_FUNC_ENABLE_EXTENDED_ADDRESSING) || \
       defined(TP_FUNC_ENABLE_NORMAL_FIXED_ADDRESSING) || \
       defined(TP_FUNC_ENABLE_MIXED_29_ADDRESSING) )
/*******************************************************************************
* NAME:              TpFuncGetTargetAddress
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:      none
*******************************************************************************/
canuint8 TP_API_CALL_TYPE TpFuncGetTargetAddress(void)
{
  return tpFuncInfoStruct.TargetAddress;
}
# endif

#  if (kTpNumberOfCanChannels > 1)
/*******************************************************************************
* NAME:              TpFuncGetCanChannel
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:      none
*******************************************************************************/
canuint8 TP_API_CALL_TYPE TpFuncGetCanChannel(void)
{
  return tpFuncInfoStruct.CanChannel;
}
#  endif

# if defined(TP_ENABLE_DYNAMIC_CHANNELS)
#  if defined(TP_FUNC_ENABLE_NORMAL_ADDRESSING) || \
      defined(TP_FUNC_ENABLE_MIXED_11_ADDRESSING)
/*******************************************************************************
* NAME:              TpFuncGetReceiveExtCanID, TpFuncGetReceiveCanID
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:      none
*******************************************************************************/
#   if (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn)
canuint32 TP_API_CALL_TYPE TpFuncGetReceiveExtCanID(void)
{
  return tpFuncInfoStruct.ReceiveID;
}
canuint16 TP_API_CALL_TYPE TpFuncGetReceiveCanID(void)
{
  return tpFuncInfoStruct.ReceiveID;
}
#   elif (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
canuint32 TP_API_CALL_TYPE TpFuncGetReceiveExtCanID(void)
{
  return tpFuncInfoStruct.ReceiveID;
}
#   else
canuint16 TP_API_CALL_TYPE TpFuncGetReceiveCanID(void)
{
  return tpFuncInfoStruct.ReceiveID;
}
#   endif

#   if( TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn )
/*******************************************************************************
* NAME:              TpFuncGetChannelIDType
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         tpChannel
* RETURN VALUE:      kTpCanIdTypeStd, kTpCanIdTypeExt
*******************************************************************************/
canuint8 TP_API_CALL_TYPE TpFuncGetChannelIDType(void)
{
  return tpFuncInfoStruct.ReceiveIDType;
}
#   endif
#  endif
# endif

# if ( defined(TP_FUNC_ENABLE_MIXED_29_ADDRESSING) || \
       defined(TP_FUNC_ENABLE_MIXED_11_ADDRESSING) )
/*******************************************************************************
* NAME:              TpFuncGetAddressExtension
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:      none
*******************************************************************************/
canuint8 TP_API_CALL_TYPE TpFuncGetAddressExtension(void)
{
  return tpFuncInfoStruct.AddressExtension;
}
# endif


# if defined(TP_ENABLE_DYNAMIC_CHANNELS)
#  if defined(TP_FUNC_ENABLE_NORMAL_ADDRESSING) || \
      defined(TP_FUNC_ENABLE_MIXED_11_ADDRESSING)
/*******************************************************************************
* NAME:              TpFuncSetTransmit(Ext)CanID
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         none
* RETURN VALUE:      none
*******************************************************************************/
#   if (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn)
void TP_API_CALL_TYPE TpFuncSetTransmitExtCanID(canuint32 TransmitCanID)
{
  tpFuncInfoStruct.TransmitID = TransmitCanID;
  tpFuncInfoStruct.TransmitIDType = kTpCanIdTypeExt;
}
void TP_API_CALL_TYPE TpFuncSetTransmitCanID(canuint16 TransmitCanID)
{
  tpFuncInfoStruct.TransmitID = (canuint32)TransmitCanID;
  tpFuncInfoStruct.TransmitIDType = kTpCanIdTypeStd;
}
#   elif (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
void TP_API_CALL_TYPE TpFuncSetTransmitExtCanID(canuint32 TransmitCanID)
{
  tpFuncInfoStruct.TransmitID = TransmitCanID;
}
#   else
void TP_API_CALL_TYPE TpFuncSetTransmitCanID(canuint16 TransmitCanID)
{
  tpFuncInfoStruct.TransmitID = TransmitCanID;
}
#   endif

/*******************************************************************************
* NAME:              TpFuncSetReceive(Ext)CanID
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         ReceiveCanID
* RETURN VALUE:      none
*******************************************************************************/
#   if (TP_USE_MIXED_IDS_FOR_NORMAL == kTpOn)
void TP_API_CALL_TYPE TpFuncSetReceiveExtCanID(canuint32 FcReceiveID)
{
  tpFuncInfoStruct.FcReceiveID = FcReceiveID;
  tpFuncInfoStruct.FcReceiveIDType = kTpCanIdTypeExt;
}
void TP_API_CALL_TYPE TpFuncSetReceiveCanID(canuint16 FcReceiveID)
{
  tpFuncInfoStruct.FcReceiveID = (canuint32)FcReceiveID;
  tpFuncInfoStruct.FcReceiveIDType = kTpCanIdTypeStd;
}
#   elif (TP_USE_EXT_IDS_FOR_NORMAL == kTpOn)
void TP_API_CALL_TYPE TpFuncSetReceiveExtCanID(canuint32 FcReceiveID)
{
  tpFuncInfoStruct.FcReceiveID = FcReceiveID;
}
#   else
void TP_API_CALL_TYPE TpFuncSetReceiveCanID(canuint16 FcReceiveID)
{
  tpFuncInfoStruct.FcReceiveID = FcReceiveID;
}
#   endif

#  endif
# endif

/*******************************************************************************
* NAME:              TpFuncGetCanBuffer
*
* CALLED BY:         Application
* PRECONDITIONS:     Only valid in __ApplTpFuncGetBuffer function
*
* PARAMETER:         tpChannel
* RETURN VALUE:      Pointer to data buffer in CAN registers
*******************************************************************************/
CanChipDataPtr TP_API_CALL_TYPE TpFuncGetCanBuffer(void)
{
  return tpFuncInfoStruct.DataBufferPtr.DataCanBufferPtr;
}

#endif
/* defined TP_FUNC_ENABLE_RECEPTION */


#if defined (TP_ENABLE_SINGLE_MSG_OBJ)
#endif /* TP_ENABLE_SINGLE_MSG_OBJ */




#if defined TP_ENABLE_DYNAMIC_CHANNELS && (! defined(TP_ENABLE_SINGLE_CHANNEL_TP))
/*******************************************************************************
*
* NAME:              TpRxGetFreeChannel
*
* CALLED BY:         Application
* PRECONDITIONS:     none
*
* PARAMETER:         connection
* RETURN VALUE:      tpChannel number
* DESCRIPTION:       Find a free tpChannel
*                    Please note that this is a (DOBT) project specific API which
*                    is not intended for general use.
*******************************************************************************/
canuint8 TP_API_CALL_TYPE TpRxGetFreeChannel(canuint8 connection)
{
  cansintCPUtype tpChannel;
  canuint8 retc;

  /**** Search for a free tpChannel *****************************************/
  TpGlobalInterruptDisable();

  retc = kTpNoChannel;
  for (tpChannel=(cansintCPUtype)(kTpRxChannelCount-1); tpChannel>=0; tpChannel--)
  {
    if (tpRxState[tpChannel].engine == kRxState_Idle)
    {
      tpRxState[tpChannel].engine = kRxState_ApplInformed;
      tpRxInfoStruct[tpChannel].Connection = connection;
      retc = (canuint8)tpChannel;
      break;
    }
  }

  TpGlobalInterruptRestore();
  return(retc);
}

#endif
/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
