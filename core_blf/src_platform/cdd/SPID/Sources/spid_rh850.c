/******************************************************************************/
/*@F_NAME:             spid_rh850.c                                           */
/*@F_PURPOSE:          Serial Synchronous Peripheral Interface Driver         */
/*@F_CREATED_BY:       shubin liang                                           */
/*@F_CREATION_DATE:    2017 03 18                                             */
/*@F_MPROC_TYPE:       rh850 f1x                                              */
/************************************** (C) Copyright 2017 Magneti Marelli ****/

/*_____ I N C L U D E - F I L E S ____________________________________________*/

#include "syst.h"
#include "spid.h"
#include "spid_config.h"
#include "iodd.h"

#ifdef __RH850__


/*******************************************************************************/
/* RH850 CODE                                                                  */
/******************************************************************************/
#ifdef __RH850_F1x__

/*_____ L O C A L - D E F I N E S ____________________________________________*/

#define SPID_CSIG_CTL0
#define SPID_CSIG_CTL1
#define SPID_CSIG_CTL2
#define SPID_CSIG_CFG0
#define SPID_CSIG_BCTL0

#define SPID_CSIH_CTL0
#define SPID_CSIH_CTL1
#define SPID_CSIH_CTL2
#define SPID_CSIH_BRS0
#define SPID_CSIH_CFG0
#define SPID_CSIH_MCTL0

#define Spid_Msk_Bit0                (ushort)(0x0001)
#define Spid_Msk_Bit1                (ushort)(0x0002)
#define Spid_Msk_Bit2                (ushort)(0x0004)
#define Spid_Msk_Bit3                (ushort)(0x0008)
#define Spid_Msk_Bit4                (ushort)(0x0010)
#define Spid_Msk_Bit5                (ushort)(0x0020)
#define Spid_Msk_Bit6                (ushort)(0x0040)
#define Spid_Msk_Bit7                (ushort)(0x0080)
#define Spid_Msk_Bit8                (ushort)(0x0100)
#define Spid_Msk_Bit9                (ushort)(0x0200)
#define Spid_Msk_Bit10               (ushort)(0x0400)
#define Spid_Msk_Bit11               (ushort)(0x0800)
#define Spid_Msk_Bit12               (ushort)(0x1000)
#define Spid_Msk_Bit13               (ushort)(0x2000)
#define Spid_Msk_Bit14               (ushort)(0x4000)
#define Spid_Msk_Bit15               (ushort)(0x8000)

/* channel status mask */
#define SPID_CSIG0_STATUS_MASK     ((ubyte)0x01)
#define SPID_CSIG1_STATUS_MASK     ((ubyte)0x02)
#define SPID_CSIH0_STATUS_MASK     ((ubyte)0x04)
#define SPID_CSIH1_STATUS_MASK     ((ubyte)0x08)
#define SPID_CSIH2_STATUS_MASK     ((ubyte)0x10)
#define SPID_CSIH3_STATUS_MASK     ((ubyte)0x20)


/*
#define   SPID_ResetCsih(CsihChannel)                   \
                    CSIH0CTL0      = 0x00; \



#define   SPID_InitCsihChannel(CsihChannel)                     \
                        SPID_ResetCsih(CsihChannel)


#define   SPID_InitCsihChannel(CsihChannel)                     \
              CSIH0CTL1  = SPID_RegConfig.TempCtl1;
              CSIH0CTL2  = SPID_RegConfig.TempCtl2;
              CSIH0BRS0  = SPID_RegConfig.TempBrs0;
              CSIH0CFG0  = SPID_RegConfig.Tempcfg0;
              CSIH0MCTL0 = 0x00;
              CSIH0CTL0  = 0xe1;
*/

/*
 *
#define   SPID_EnableCsihTransfer(CsihChannel)  (CSIH0CTL0 = 0xe1)


#define   SPID_ResetCsihChannel0()           SPID_ResetCsih(SPID_CSIH_CHANNEKL_0)

#define   SPID_InitCsihChannle0()            (SPID_InitCsihChannel(SPID_CSIH_CHANNEKL_0))

#define   SPID_EnableCsihTransferChannel0()  SPID_EnableCsihTransfer(SPID_CSIH_CHANNEKL_0)


#define   SPID_ResetCsihChannel1()           SPID_ResetCsih(SPID_CSIH_CHANNEKL_1)

#define   SPID_InitCsihChannle1()            SPID_InitCsihChannel(SPID_CSIH_CHANNEKL_1)

#define   SPID_EnableCsihTransferChannel1()  SPID_EnableCsihTransfer(SPID_CSIH_CHANNEKL_1)

#define   SPID_ResetCsihChannel2()           SPID_ResetCsih(SPID_CSIH_CHANNEKL_2)

#define   SPID_InitCsihChannle2()            SPID_InitCsihChannel(SPID_CSIH_CHANNEKL_2)

#define   SPID_EnableCsihTransferChannel2()  SPID_EnableCsihTransfer(SPID_CSIH_CHANNEKL_2)

#define   SPID_ResetCsihChannel3()           SPID_ResetCsih(SPID_CSIH_CHANNEKL_3)

#define   SPID_InitCsihChannle3()            SPID_InitCsihChannel(SPID_CSIH_CHANNEKL_3)

#define   SPID_EnableCsihTransferChannel3()  SPID_EnableCsihTransfer(SPID_CSIH_CHANNEKL_3)
*/


/*_____ L O C A L - T Y P E __________________________________________________*/

typedef struct
{
  ubyte  TempCtl0;
  ulong  TempCtl1;
  ushort TempCtl2;
  ushort TempBrs0;
  ulong Tempcfg0;
}SPID_Reg_Config_t;

#endif /* __RH850_F1x__ */


/* local data */
static volatile ubyte Spid_TransmitMask;


/*_____ L O C A L - F U N C T I O N S - P R O T O T Y P E S __________________*/

static void Spid_CSIG_initialize( volatile SPID_csig_t * const CSIG_channel, const SPID_Ch_Config_t *  const Channel);

static void Spid_CSIH_initialize( SPID_CSIH_Channel_t CsihChannl,\
                                  const SPID_Ch_Config_t *  const ChannelConfig);
/* _____ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

#ifdef SPID_UserReceiveInterrupt_ch0
extern void SPID_UserReceiveInterrupt_ch0 (void);
#endif
#ifdef SPID_UserReceiveInterrupt_ch1
extern void SPID_UserReceiveInterrupt_ch1 (void);
#endif
#ifdef SPID_UserReceiveInterrupt_ch2
extern void SPID_UserReceiveInterrupt_ch2 (void);
#endif
#ifdef SPID_UserReceiveInterrupt_ch3
extern void SPID_UserReceiveInterrupt_ch3 (void);
#endif


/*_____ G L O B A L - F U N C T I O N S ______________________________________*/

/******************************************************************************/
/* Name: SPID_InitChannel                                                     */
/* Role: Initialise the module                                                */
/* Interface: none                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour:                                                                 */
/* DO                                                                         */
/*   [ Initialize hardware according to configuration ]                       */
/* OD                                                                         */
/******************************************************************************/
void SPID_InitChannel(ubyte SpidChannel )
{
  SPID_Ch_Config_t ChConfig;
  /*
   * clear all mask
   * */
  Spid_TransmitMask = 0x00u;
  /*----For RH850 F1L*/
  switch(SpidChannel)
  {
    #ifdef SPID_CHANNEL_CSIG0_ACTIVE
    case SPID_CHANNEKL_00 :
      if(SpidChannel == SPID_CHANNEKL_00 )
      {
        /* Set the SCK, SO and SI pins as alternate port mode */
        #ifdef __RH850_F1x__
        /* Set the SCK, SO and SI pins as alternate port mode */
        #if defined(Spid_Channel_CSIG0_Use_PortGroup_0)
        /*P0_13 as CSIG0SO*/
        IODD_ALTER_OUT(0,13);
        IODD_ALTER4_FUNC(0,13);

        /*P0_14 as CSIG0SC*/
        IODD_ALTER_OUT(0,14);
        IODD_ALTER4_FUNC(0,14);

        /*P0_12 as CSIG0SI*/
        IODD_ALTER_IN(0,12);
        IODD_ALTER4_FUNC(0,12);
        #endif /* defined(Spid_Channel_CSIG0_Use_PortGroup_0) */

        #if defined(Spid_Channel_CSIG0_Use_PortGroup_10)
        /*P10_6 as CSIG0SO*/
        IODD_ALTER_OUT(10,6);
        IODD_ALTER2_FUNC(10,6);

        /*P10_7 as CSIG0SC*/
        IODD_ALTER_OUT(10,7);
        IODD_ALTER2_FUNC(10,7);

        /*P10_8 as CSIG0SI*/
        IODD_ALTER_IN(10,8);
        IODD_ALTER2_FUNC(10,8);
        #endif /* defined(Spid_Channel0_Use_PortGroup_10) */

        #endif  /*__RH850_F1x__*/

        ChConfig.CLK        = SPID_CHANNEL_CSIG0_CLOCK_FREQUENCY;
        ChConfig.BaudRate   = SPID_CHANNEL_CSIG0_BAUD_SELECTION;
        ChConfig.DataLenght = SPID_CHANNEL_CSIG0_BITS_DATA_LENGHT;
        ChConfig.DataDiret  = SPID_CHANNEL_CSIG0_DIRECTION_MODE;
        ChConfig.Mode       = SPID_CSIG0_COMMUNICATION_TYPE;
        /* Start channel                                              */
        Spid_CSIG_initialize(&CSIG0,&ChConfig);

        /* enable TX interrupt */

        #if defined(__RH850_F1L__)
        #if defined(Spid_Channel_CSIG0_Use_ISR)
          MKCSIG0IC = 0u;
        #endif
        #elif defined(__RH850_F1K__)
        #if defined(Spid_Channel_CSIG0_Use_ISR)
          INTC1MKCSIG0IC  = 0x00u;
        #endif
        #else
        #error "have to set CTL register to MCU"
        #endif
      }
      /*TBCSIG0IC = 1;*/
    break;
    #endif /* SPID_CHANNEL_CSIG0_ACTIVE */

    #ifdef SPID_CHANNEL_CSIG1_ACTIVE
    case SPID_CHANNEKL_01 :
      if(SpidChannel ==  SPID_CHANNEKL_01 )
      {
        /* Set the SCK, SO and SI pins as alternate port mode */
        #ifdef __RH850_F1x__
        /* Set the SSI SCK, SO and SI pins as alternate port mode */
        #if defined(Spid_Channel_CSIG1_Use_PortGroup_11)

        /*P11_9 as CSIG1SO*/
        IODD_ALTER_OUT(11,9);
        IODD_ALTER1_FUNC(11,9);

        /*P11_10 as CSIG1SC*/
        IODD_ALTER_OUT(11,10);
        IODD_ALTER1_FUNC(11,10);

        /*P11_11 as CSIG1SI*/
        IODD_ALTER_IN(11,11);
        IODD_ALTER1_FUNC(11,11);

        #endif /* defined(Spid_Channel_CSIG1_Use_PortGroup_11) */
        #endif /* __RH850_F1x__ */

        ChConfig.CLK        = SPID_CHANNEL_CSIG1_CLOCK_FREQUENCY;
        ChConfig.BaudRate   = SPID_CHANNEL_CSIG1_BAUD_SELECTION;
        ChConfig.DataLenght = SPID_CHANNEL_CSIG1_BITS_DATA_LENGHT;
        ChConfig.DataDiret  = SPID_CHANNEL_CSIG1_DIRECTION_MODE;
        ChConfig.Mode       = SPID_CSIG1_COMMUNICATION_TYPE;
        /* Start channel                                              */
        Spid_CSIG_initialize(&CSIG1,&ChConfig);

        /* enable TX interrupt */
        #if defined(__RH850_F1L__)
          #if defined(Spid_Channel_CSIG0_Use_ISR)
            MKCSIG1IC = 0u;
          #endif
        #elif defined(__RH850_F1K__)
          #if defined(Spid_Channel_CSIG1_Use_ISR)
            INTC1MKCSIG1IC  = 0x00u;
          #endif
        #else
        #error "have to set CTL register to MCU"
        #endif
      }
    break;
    #endif /* SPID_CHANNEL_CSIG1_ACTIVE */

    #ifdef SPID_CHANNEL_CSIH0_ACTIVE
    case SPID_CHANNEKL_02 :
      if(SpidChannel ==  SPID_CHANNEKL_02 )
      {
        /* Set the SCK, SO and SI pins as alternate port mode */
        #ifdef __RH850_F1x__
        /* Set the SSI SCK, SO and SI pins as alternate port mode */
        #if defined(Spid_Channel_CSIH0_Use_PortGroup_0)
        /*P0_3 as CSIH0SO*/
         IODD_ALTER_OUT(0,3);
         IODD_ALTER4_FUNC(0,3);

         /*P0_2 as CSIH0SC*/
         IODD_ALTER_OUT(0,2);
         IODD_ALTER4_FUNC(0,2);

         /*P01 as CSIH0SI*/
         IODD_ALTER_IN(0,1);
         IODD_ALTER4_FUNC(0,1);
        #endif /* defined(Spid_Channel_CSIH0_Use_PortGroup_0) */
        #endif /* __RH850_F1x__ */

         ChConfig.CLK        = SPID_CHANNEL_CSIH0_CLOCK_FREQUENCY;
         ChConfig.BaudRate   = SPID_CHANNEL_CSIH0_BAUD_SELECTION;
         ChConfig.DataLenght = SPID_CHANNEL_CSIH0_BITS_DATA_LENGHT;
         ChConfig.DataDiret  = SPID_CHANNEL_CSIH0_DIRECTION_MODE;
         ChConfig.Mode       = SPID_CSIH0_COMMUNICATION_TYPE;
         /* Start channel                                              */
         Spid_CSIH_initialize(SPID_CSIH_CHANNEKL_0,&ChConfig);
         /* enable TX interrupt */
        #if defined(__RH850_F1L__)
          #if defined(Spid_Channel_CSIH0_Use_ISR)
           MKCSIH0IC = 0u;
          #endif
        #elif defined(__RH850_F1K__)
          #if defined(Spid_Channel_CSIH0_Use_ISR)
           INTC1MKCSIH0IC  = 0x00u;
          #endif
        #else
        #error "have to set CTL register to MCU"
        #endif
      }
    break;
    #endif /* SPID_CHANNEL_CSIH0_ACTIVE */

    #ifdef SPID_CHANNEL_CSIH1_ACTIVE
    case SPID_CHANNEKL_03 :
      if(SpidChannel ==  SPID_CHANNEKL_03 )
      {
        /* Set the SCK, SO and SI pins as alternate port mode */
        #ifdef __RH850_F1x__
        #if defined(Spid_Channel_CSIH1_Use_PortGroup_0)
        /*P0_5 as CSIH1SO*/
        IODD_ALTER_OUT(0,5);
        IODD_ALTER3_FUNC(0,5);

        /*P0_6 as CSIH1SC*/
        IODD_ALTER_OUT(0,6);
        IODD_ALTER3_FUNC(0,6);

        /*P04 as CSIH1SI*/
        IODD_ALTER_IN(0,6);
        IODD_ALTER3_FUNC(0,4);
        #endif /* defined(Spid_Channel_CSIH1_Use_PortGroup_0) */

        #if defined(Spid_Channel_CSIH1_Use_PortGroup_10)
        /*P10_2 as CSIH1SO*/
        IODD_ALTER_OUT(10,2);
        IODD_ALTER5_FUNC(10,2);

        /*P0_1 as CSIH1SC*/
        IODD_ALTER_OUT(10,1);
        IODD_ALTER5_FUNC(10,1);

        /*P00 as CSIH1SI*/
        IODD_ALTER_IN(10,0);
        IODD_ALTER5_FUNC(10,0);
        #endif /* defined(Spid_Channel_CSIH1_Use_PortGroup_10) */
        #endif /* __RH850_F1x__ */

        ChConfig.CLK        = SPID_CHANNEL_CSIH1_CLOCK_FREQUENCY;
        ChConfig.BaudRate   = SPID_CHANNEL_CSIH1_BAUD_SELECTION;
        ChConfig.DataLenght = SPID_CHANNEL_CSIH1_BITS_DATA_LENGHT;
        ChConfig.DataDiret  = SPID_CHANNEL_CSIH1_DIRECTION_MODE;
        ChConfig.Mode       = SPID_CSIH1_COMMUNICATION_TYPE;
        /* Start channel                                              */
        Spid_CSIH_initialize(SPID_CSIH_CHANNEKL_1,&ChConfig);
        /* enable TX interrupt */
        #if defined(__RH850_F1L__)
          #if defined(Spid_Channel_CSIH1_Use_ISR)
          MKCSIH1IC = 0u;
          #endif
          #elif defined(__RH850_F1K__)
          #if defined(Spid_Channel_CSIH1_Use_ISR)
          INTC2MKCSIH1IC  = 0x00u;
          #endif
        #else
          #error "have to set CTL register to MCU"
        #endif
      }
    break;
    #endif /* SPID_CHANNEL_CSIH1_ACTIVE */

    #ifdef SPID_CHANNEL_CSIH2_ACTIVE
    case SPID_CHANNEKL_04 :
      if(SpidChannel ==  SPID_CHANNEKL_04 )
      {
        /* Set the SCK, SO and SI pins as alternate port mode */
        #ifdef __RH850_F1x__
        /* Set the SSI SCK, SO and SI pins as alternate port mode */
        #if defined(Spid_Channel_CSIH2_Use_PortGroup_11)
        /*P11_2 as CSIH2SO*/
        IODD_ALTER_OUT(11,2);
        IODD_ALTER1_FUNC(11,2);

        /*P11_3 as CSIH2SC*/
        IODD_ALTER_OUT(11,3);
        IODD_ALTER1_FUNC(11,3);

        /*P11_4 as CSIH2SI*/
        IODD_ALTER_IN(11,4);
        IODD_ALTER1_FUNC(11,4);
        #endif /* defined(Spid_Channel_CSIH1_Use_PortGroup_11) */
        #endif /* __RH850_F1x__ */

        ChConfig.CLK        = SPID_CHANNEL_CSIH2_CLOCK_FREQUENCY;
        ChConfig.BaudRate   = SPID_CHANNEL_CSIH2_BAUD_SELECTION;
        ChConfig.DataLenght = SPID_CHANNEL_CSIH2_BITS_DATA_LENGHT;
        ChConfig.DataDiret  = SPID_CHANNEL_CSIH2_DIRECTION_MODE;
        ChConfig.Mode       = SPID_CSIH2_COMMUNICATION_TYPE;
        /* Start channel                                              */
        Spid_CSIH_initialize(SPID_CSIH_CHANNEKL_2,&ChConfig);
        /* enable TX interrupt */
        #if defined(__RH850_F1L__)
          #if defined(Spid_Channel_CSIH2_Use_ISR)
          MKCSIH2IC = 0u;
          #endif
        #elif defined(__RH850_F1K__)
          #if defined(Spid_Channel_CSIH2_Use_ISR)
          INTC2MKCSIH2IC  = 0x00u;
          #endif
        #else
        #error "have to set CTL register to MCU"
        #endif
      }
    break;
    #endif /* SPID_CHANNEL_CSIG2_ACTIVE */

    #ifdef SPID_CHANNEL_CSIH3_ACTIVE
    case SPID_CHANNEKL_05 :
      if(SpidChannel ==  SPID_CHANNEKL_05 )
      {
        /* Set the SCK, SO and SI pins as alternate port mode */
        #ifdef __RH850_F1x__
        /* Set the SSI SCK, SO and SI pins as alternate port mode */
        #if defined(Spid_Channel_CSIH3_Use_PortGroup_11)
        /*P11_6 as CSIH3SO*/
        IODD_ALTER_OUT(11,6);
        IODD_ALTER3_FUNC(11,6);

        /*P11_7 as CSIH3SC*/
        IODD_ALTER_OUT(11,7);
        IODD_ALTER3_FUNC(11,7);

        /*P11_5 as CSIH2SI*/
        IODD_ALTER_IN(11,5);
        IODD_ALTER3_FUNC(11,5);
        #endif /* defined(Spid_Channel_CSIG1_Use_PortGroup_11) */
        #endif /* __RH850_F1x__ */

        ChConfig.CLK        = SPID_CHANNEL_CSIH3_CLOCK_FREQUENCY;
        ChConfig.BaudRate   = SPID_CHANNEL_CSIH3_BAUD_SELECTION;
        ChConfig.DataLenght = SPID_CHANNEL_CSIH3_BITS_DATA_LENGHT;
        ChConfig.DataDiret  = SPID_CHANNEL_CSIH3_DIRECTION_MODE;
        ChConfig.Mode       = SPID_CSIH3_COMMUNICATION_TYPE;
        /* Start channel                                              */
        Spid_CSIH_initialize(SPID_CSIH_CHANNEKL_3,&ChConfig);
        /* enable TX interrupt */
        #if defined(__RH850_F1L__)
          #if defined(Spid_Channel_CSIH3_Use_ISR)
          MKCSIH3IC = 0u;
          #endif
        #elif defined(__RH850_F1K__)
          #if defined(Spid_Channel_CSIH3_Use_ISR)
          INTC2MKCSIH3IC  = 0x00u;
          #endif
        #else
        #error "have to set CTL register to MCU"
        #endif
      }
    break;
    #endif /* SPID_CHANNEL_CSIH3_ACTIVE */

    default:
      break;
  }
}

/******************************************************************************/
/* Name: SPID_Init                                                            */
/* Role: Initialise the module                                                */
/* Interface: none                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour:                                                                 */
/* DO                                                                         */
/*   [ Initialize hardware according to configuration ]                       */
/* OD                                                                         */
/******************************************************************************/
void SPID_Init (void)
{
  SPID_Ch_Config_t ChConfig;
  /*
   * clear all mask
   * */
  Spid_TransmitMask = 0x00u;

/*----For RH850 F1L*/
  #ifdef SPID_CHANNEL_CSIG0_ACTIVE

  /* Set the SCK, SO and SI pins as alternate port mode */
  #ifdef __RH850_F1x__
  /* Set the SCK, SO and SI pins as alternate port mode */
  #if defined(Spid_Channel_CSIG0_Use_PortGroup_0)
  /*P0_13 as CSIG0SO*/
  IODD_ALTER_OUT(0,13);
  IODD_ALTER4_FUNC(0,13);

  /*P0_14 as CSIG0SC*/
  IODD_ALTER_OUT(0,14);
  IODD_ALTER4_FUNC(0,14);

  /*P0_12 as CSIG0SI*/
  IODD_ALTER_IN(0,12);
  IODD_ALTER4_FUNC(0,12);
  #endif /* defined(Spid_Channel_CSIG0_Use_PortGroup_0) */

  #if defined(Spid_Channel_CSIG0_Use_PortGroup_10)
  /*P10_6 as CSIG0SO*/
  IODD_ALTER_OUT(10,6);
  IODD_ALTER2_FUNC(10,6);

  /*P10_7 as CSIG0SC*/
  IODD_ALTER_OUT(10,7);
  IODD_ALTER2_FUNC(10,7);

  /*P10_8 as CSIG0SI*/
  IODD_ALTER_IN(10,8);
  IODD_ALTER2_FUNC(10,8);
  #endif /* defined(Spid_Channel0_Use_PortGroup_10) */
  
  #endif	/*__RH850_F1x__*/

  ChConfig.CLK        = SPID_CHANNEL_CSIG0_CLOCK_FREQUENCY;
  ChConfig.BaudRate   = SPID_CHANNEL_CSIG0_BAUD_SELECTION;
  ChConfig.DataLenght = SPID_CHANNEL_CSIG0_BITS_DATA_LENGHT;
  ChConfig.DataDiret  = SPID_CHANNEL_CSIG0_DIRECTION_MODE;
  ChConfig.Mode       = SPID_CSIG0_COMMUNICATION_TYPE;
  /* Start channel                                              */
  Spid_CSIG_initialize(&CSIG0,&ChConfig);

  /* enable TX interrupt */

#if defined(__RH850_F1L__)
  #if defined(Spid_Channel_CSIG0_Use_ISR)
   MKCSIG0IC = 0u;
  #endif
#elif defined(__RH850_F1K__)
  #if defined(Spid_Channel_CSIG0_Use_ISR)
   INTC1MKCSIG0IC  = 0x00u;
  #endif
#else
#error "have to set CTL register to MCU"
#endif
  /*TBCSIG0IC = 1;*/
  #endif /* SPID_CHANNEL_CSIG0_ACTIVE */

  #ifdef SPID_CHANNEL_CSIG1_ACTIVE
  /* Set the SCK, SO and SI pins as alternate port mode */
  #ifdef __RH850_F1x__
  /* Set the SSI SCK, SO and SI pins as alternate port mode */
  #if defined(Spid_Channel_CSIG1_Use_PortGroup_11)

  /*P11_9 as CSIG1SO*/
  IODD_ALTER_OUT(11,9);
  IODD_ALTER1_FUNC(11,9);

  /*P11_10 as CSIG1SC*/
  IODD_ALTER_OUT(11,10);
  IODD_ALTER1_FUNC(11,10);

  /*P11_11 as CSIG1SI*/
  IODD_ALTER_IN(11,11);
  IODD_ALTER1_FUNC(11,11);

  #endif /* defined(Spid_Channel_CSIG1_Use_PortGroup_11) */
  #endif /* __RH850_F1x__ */

  ChConfig.CLK        = SPID_CHANNEL_CSIG1_CLOCK_FREQUENCY;
  ChConfig.BaudRate   = SPID_CHANNEL_CSIG1_BAUD_SELECTION;
  ChConfig.DataLenght = SPID_CHANNEL_CSIG1_BITS_DATA_LENGHT;
  ChConfig.DataDiret  = SPID_CHANNEL_CSIG1_DIRECTION_MODE;
  ChConfig.Mode       = SPID_CSIG1_COMMUNICATION_TYPE;
  /* Start channel                                              */
  Spid_CSIG_initialize(&CSIG1,&ChConfig);

  /* enable TX interrupt */
#if defined(__RH850_F1L__)
  #if defined(Spid_Channel_CSIG0_Use_ISR)
    MKCSIG1IC = 0u;
  #endif
#elif defined(__RH850_F1K__)
  #if defined(Spid_Channel_CSIG1_Use_ISR)
   INTC1MKCSIG1IC  = 0x00u;
  #endif
#else
#error "have to set CTL register to MCU"
#endif
  #endif /* SPID_CHANNEL_CSIG1_ACTIVE */

  #ifdef SPID_CHANNEL_CSIH0_ACTIVE
  /* Set the SCK, SO and SI pins as alternate port mode */
  #ifdef __RH850_F1x__
  /* Set the SSI SCK, SO and SI pins as alternate port mode */
  #if defined(Spid_Channel_CSIH0_Use_PortGroup_0)
  /*P0_3 as CSIH0SO*/
   IODD_ALTER_OUT(0,3);
   IODD_ALTER4_FUNC(0,3);

   /*P0_2 as CSIH0SC*/
   IODD_ALTER_OUT(0,2);
   IODD_ALTER4_FUNC(0,2);

   /*P01 as CSIH0SI*/
   IODD_ALTER_IN(0,1);
   IODD_ALTER4_FUNC(0,1);
  #endif /* defined(Spid_Channel_CSIH0_Use_PortGroup_0) */
  #endif /* __RH850_F1x__ */

   ChConfig.CLK        = SPID_CHANNEL_CSIH0_CLOCK_FREQUENCY;
   ChConfig.BaudRate   = SPID_CHANNEL_CSIH0_BAUD_SELECTION;
   ChConfig.DataLenght = SPID_CHANNEL_CSIH0_BITS_DATA_LENGHT;
   ChConfig.DataDiret  = SPID_CHANNEL_CSIH0_DIRECTION_MODE;
   ChConfig.Mode       = SPID_CSIH0_COMMUNICATION_TYPE;
   /* Start channel                                              */
   Spid_CSIH_initialize(SPID_CSIH_CHANNEKL_0,&ChConfig);
   /* enable TX interrupt */
#if defined(__RH850_F1L__)
  #if defined(Spid_Channel_CSIH0_Use_ISR)
   MKCSIH0IC = 0u;
  #endif
#elif defined(__RH850_F1K__)
  #if defined(Spid_Channel_CSIH0_Use_ISR)
   INTC1MKCSIH0IC  = 0x00u;
  #endif
#else
#error "have to set CTL register to MCU"
#endif
  #endif /* SPID_CHANNEL_CSIH0_ACTIVE */
  
  #ifdef SPID_CHANNEL_CSIH1_ACTIVE
  /* Set the SCK, SO and SI pins as alternate port mode */
  #ifdef __RH850_F1x__
  #if defined(Spid_Channel_CSIH1_Use_PortGroup_0)
  /*P0_5 as CSIH1SO*/
  IODD_ALTER_OUT(0,5);
  IODD_ALTER3_FUNC(0,5);

  /*P0_6 as CSIH1SC*/
  IODD_ALTER_OUT(0,6);
  IODD_ALTER3_FUNC(0,6);

  /*P04 as CSIH1SI*/
  IODD_ALTER_IN(0,6);
  IODD_ALTER3_FUNC(0,4);
  #endif /* defined(Spid_Channel_CSIH1_Use_PortGroup_0) */

  #if defined(Spid_Channel_CSIH1_Use_PortGroup_10)
  /*P10_2 as CSIH1SO*/
  IODD_ALTER_OUT(10,2);
  IODD_ALTER5_FUNC(10,2);

  /*P0_1 as CSIH1SC*/
  IODD_ALTER_OUT(10,1);
  IODD_ALTER5_FUNC(10,1);

  /*P00 as CSIH1SI*/
  IODD_ALTER_IN(10,0);
  IODD_ALTER5_FUNC(10,0);
  #endif /* defined(Spid_Channel_CSIH1_Use_PortGroup_10) */
  #endif /* __RH850_F1x__ */

  ChConfig.CLK        = SPID_CHANNEL_CSIH1_CLOCK_FREQUENCY;
  ChConfig.BaudRate   = SPID_CHANNEL_CSIH1_BAUD_SELECTION;
  ChConfig.DataLenght = SPID_CHANNEL_CSIH1_BITS_DATA_LENGHT;
  ChConfig.DataDiret  = SPID_CHANNEL_CSIH1_DIRECTION_MODE;
  ChConfig.Mode       = SPID_CSIH1_COMMUNICATION_TYPE;
  /* Start channel                                              */
  Spid_CSIH_initialize(SPID_CSIH_CHANNEKL_1,&ChConfig);
  /* enable TX interrupt */
  #if defined(__RH850_F1L__)
    #if defined(Spid_Channel_CSIH1_Use_ISR)
    MKCSIH1IC = 0u;
    #endif
    #elif defined(__RH850_F1K__)
    #if defined(Spid_Channel_CSIH1_Use_ISR)
    INTC2MKCSIH1IC  = 0x00u;
    #endif
  #else
    #error "have to set CTL register to MCU"
  #endif

  #endif /* SPID_CHANNEL_CSIH1_ACTIVE */

  #ifdef SPID_CHANNEL_CSIH2_ACTIVE
  /* Set the SCK, SO and SI pins as alternate port mode */
  #ifdef __RH850_F1x__
  /* Set the SSI SCK, SO and SI pins as alternate port mode */
  #if defined(Spid_Channel_CSIH2_Use_PortGroup_11)
  /*P11_2 as CSIH2SO*/
  IODD_ALTER_OUT(11,2);
  IODD_ALTER1_FUNC(11,2);

  /*P11_3 as CSIH2SC*/
  IODD_ALTER_OUT(11,3);
  IODD_ALTER1_FUNC(11,3);

  /*P11_4 as CSIH2SI*/
  IODD_ALTER_IN(11,4);
  IODD_ALTER1_FUNC(11,4);
  #endif /* defined(Spid_Channel_CSIH1_Use_PortGroup_11) */
  #endif /* __RH850_F1x__ */

  ChConfig.CLK        = SPID_CHANNEL_CSIH2_CLOCK_FREQUENCY;
  ChConfig.BaudRate   = SPID_CHANNEL_CSIH2_BAUD_SELECTION;
  ChConfig.DataLenght = SPID_CHANNEL_CSIH2_BITS_DATA_LENGHT;
  ChConfig.DataDiret  = SPID_CHANNEL_CSIH2_DIRECTION_MODE;
  ChConfig.Mode       = SPID_CSIH2_COMMUNICATION_TYPE;
  /* Start channel                                              */
  Spid_CSIH_initialize(SPID_CSIH_CHANNEKL_2,&ChConfig);
/* enable TX interrupt */
#if defined(__RH850_F1L__)
  #if defined(Spid_Channel_CSIH2_Use_ISR)
  MKCSIH2IC = 0u;
  #endif
#elif defined(__RH850_F1K__)
  #if defined(Spid_Channel_CSIH2_Use_ISR)
  INTC2MKCSIH2IC  = 0x00u;
  #endif
#else
#error "have to set CTL register to MCU"
#endif


  #endif /* SPID_CHANNEL_CSIG2_ACTIVE */

  #ifdef SPID_CHANNEL_CSIH3_ACTIVE
  /* Set the SCK, SO and SI pins as alternate port mode */
  #ifdef __RH850_F1x__
  /* Set the SSI SCK, SO and SI pins as alternate port mode */
  #if defined(Spid_Channel_CSIH3_Use_PortGroup_11)
  /*P11_6 as CSIH3SO*/
  IODD_ALTER_OUT(11,6);
  IODD_ALTER3_FUNC(11,6);

  /*P11_7 as CSIH3SC*/
  IODD_ALTER_OUT(11,7);
  IODD_ALTER3_FUNC(11,7);

  /*P11_5 as CSIH2SI*/
  IODD_ALTER_IN(11,5);
  IODD_ALTER3_FUNC(11,5);
  #endif /* defined(Spid_Channel_CSIG1_Use_PortGroup_11) */
  #endif /* __RH850_F1x__ */

  ChConfig.CLK        = SPID_CHANNEL_CSIH3_CLOCK_FREQUENCY;
  ChConfig.BaudRate   = SPID_CHANNEL_CSIH3_BAUD_SELECTION;
  ChConfig.DataLenght = SPID_CHANNEL_CSIH3_BITS_DATA_LENGHT;
  ChConfig.DataDiret  = SPID_CHANNEL_CSIH3_DIRECTION_MODE;
  ChConfig.Mode       = SPID_CSIH3_COMMUNICATION_TYPE;
  /* Start channel                                              */
  Spid_CSIH_initialize(SPID_CSIH_CHANNEKL_3,&ChConfig);
  /* enable TX interrupt */
  #if defined(__RH850_F1L__)
    #if defined(Spid_Channel_CSIH3_Use_ISR)
    MKCSIH3IC = 0u;
    #endif
  #elif defined(__RH850_F1K__)
    #if defined(Spid_Channel_CSIH3_Use_ISR)
    INTC2MKCSIH3IC  = 0x00u;
    #endif
  #else
  #error "have to set CTL register to MCU"
  #endif

  #endif /* SPID_CHANNEL_CSIH3_ACTIVE */
}

/******************************************************************************/
/* Name: SPID_Refresh                                                         */
/* Role: this seems to be a mcu bug: we must refresh ctl0 register befer use  */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour: none                                                            */
/* DO                                                                         */
/*   [ Put to sleep the channel according to the configuration ]              */
/* OD                                                                         */
/******************************************************************************/
void SPID_Refresh (void)
{
  ubyte TempCTL0 = 0u;

  TempCTL0 |= CSI_MSK_CSIGnBIT0 +
              CSI_MSK_CSIGnRXE +
              CSI_MSK_CSIGnTXE +
              CSI_MSK_CSIGnPWR;
  if(CSIG1.CTL0 == TempCTL0){
    CSIG1.CTL0 = 0;
    CSIG1.CTL0 = TempCTL0;
  }
}

/******************************************************************************/
/* Name: SPID_Sleep                                                           */
/* Role: Provide the mean to put to sleep the hardware of activated channels  */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour: none                                                            */
/* DO                                                                         */
/*   [ Put to sleep the channel according to the configuration ]              */
/* OD                                                                         */
/******************************************************************************/
void SPID_Sleep (void)
{
  #ifdef __RH850_F1x__
  /* Stop active channels by clearing POWER bit */
  #ifdef SPID_CHANNEL_CSIG0_ACTIVE
  TARG_WriteBit(CSIG0CTL0, CSI_BIT_CSIGnPWR, 0);
  #endif /* SPID_CHANNEL_CSIG0_ACTIVE */

  #ifdef SPID_CHANNEL_CSIG1_ACTIVE
  TARG_WriteBit(CSIG1CTL0, CSI_BIT_CSIGnPWR, 0);
  #endif /* SPID_CHANNEL_CSIG1_ACTIVE */

  #ifdef SPID_CHANNEL_CSIH0_ACTIVE
  TARG_WriteBit(CSIH0CTL0, CSI_BIT_CSIHnPWR, 0);
  #endif /* SPID_CHANNEL_CSIH0_ACTIVE */

  #ifdef SPID_CHANNEL_CSIH1_ACTIVE
  TARG_WriteBit(CSIH1CTL0, CSI_BIT_CSIHnPWR, 0);
  #endif /* SPID_CHANNEL_CSIH1_ACTIVE */
  
  #ifdef SPID_CHANNEL_CSIH2_ACTIVE
  TARG_WriteBit(CSIH2CTL0, CSI_BIT_CSIHnPWR, 0);
  #endif /* SPID_CHANNEL_CSIH2_ACTIVE */
  
  #ifdef SPID_CHANNEL_CSIH3_ACTIVE
  TARG_WriteBit(CSIH3CTL0, CSI_BIT_CSIHnPWR, 0);
  #endif /* SPID_CHANNEL_CSIH3_ACTIVE */

/********************************************/
  #endif /* __RH850_F1x__ */
}

/******************************************************************************/
/* Name: SPID_WakeUp                                                          */
/* Role: Provide the mean to wake up the hardware of activated channels       */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour: none                                                            */
/* DO                                                                         */
/*   [ Wake up the channel according to the configuration ]                   */
/* OD                                                                         */
/******************************************************************************/
void SPID_WakeUp (void)
{
  /* Re-start channels */
  /* call SPID_INIT() by Star_config.c
   * */
  /*SPID_Init();*/
}

/******************************************************************************/
/* Name: SPID_TransmitByte                                                    */
/* Role: Provide the mean to start transmit of a byte on selected channel     */
/* Interface: Channel          IN  Communication channel number               */
/*             ByteToTransmit  IN  Byte to transmit on serial communication   */
/* Pre-condition: The transmit data register for the channel must be empty    */
/* Constraints: none                                                          */
/******************************************************************************/
void SPID_TransmitByte(ubyte Channel, ubyte DataByte)
{
    /*
     * channel0 -> CSIG0
     * channel1 -> CSIG1
     * channel2 -> CSIH0
     * channel3 -> CSIH1
     * channel4 -> CSIH2
     * channel5 -> CSIH3
     * */
    switch(Channel)
    {

#ifdef SPID_CHANNEL_CSIG0_ACTIVE
    case 0:
        CSIG0.TX0H = DataByte;
        break;
#endif

#ifdef SPID_CHANNEL_CSIG1_ACTIVE
    case 1:
        CSIG1.TX0H = DataByte;
        break;
#endif

#ifdef SPID_CHANNEL_CSIH0_ACTIVE
    case 2:
        CSIH0.TX0H = DataByte;
        break;
#endif

#ifdef SPID_CHANNEL_CSIH1_ACTIVE
    case 3:
        CSIH1.TX0H = DataByte;
        break;
#endif

#ifdef SPID_CHANNEL_CSIH2_ACTIVE
    case 4:
        CSIH2.TX0H = DataByte;
        break;
#endif

#ifdef SPID_CHANNEL_CSIH3_ACTIVE
    case 5:
        CSIH3.TX0H = DataByte;
        break;
#endif

    default:
        break;
    }
}

/******************************************************************************/
/* Name: SPID_TransmitShort                                                   */
/* Role: Provide the mean to start transmit of a byte on selected channel     */
/* Interface: Channel          IN  Communication channel number               */
/*             ByteToTransmit  IN  Byte to transmit on serial communication   */
/* Pre-condition: The transmit data register for the channel must be empty    */
/* Constraints: none                                                          */
/******************************************************************************/
void SPID_TransmitShort(ubyte Channel, ushort DataShort)
{
    /*
     * channel0 -> CSIG0
     * channel1 -> CSIG1
     * channel2 -> CSIH0
     * channel3 -> CSIH1
     * channel4 -> CSIH2
     * channel5 -> CSIH3
     * */
    switch(Channel)
    {

#ifdef SPID_CHANNEL_CSIG0_ACTIVE
    case 0:
        CSIG0.TX0H = DataShort;
        break;
#endif

#ifdef SPID_CHANNEL_CSIG1_ACTIVE
    case 1:
        CSIG1.TX0H = DataShort;
        break;
#endif

#ifdef SPID_CHANNEL_CSIH0_ACTIVE
    case 2:
        CSIH0.TX0H = DataShort;
        break;
#endif

#ifdef SPID_CHANNEL_CSIH1_ACTIVE
    case 3:
        CSIH1.TX0H = DataShort;
        break;
#endif

#ifdef SPID_CHANNEL_CSIH2_ACTIVE
    case 4:
        CSIH2.TX0H = DataShort;
        break;
#endif

#ifdef SPID_CHANNEL_CSIH3_ACTIVE
    case 5:
        CSIH3.TX0H = DataShort;
        break;
#endif

    default:
        break;
    }
}

/******************************************************************************/
/* Name: SPID_OperationDone                                                   */
/* Role: Provide the mean to get the status of operation on selected channel  */
/* Interface: Channel  IN   Communication channel number                      */
/*            Status   OUT  Status according to previous request:             */
/*                          != 0  -> Operation terminated                     */
/*                          = 0   -> Operation in progress                    */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/******************************************************************************/
ubyte SPID_OperationDone(ubyte Channel)
{
    ubyte Ret;

    /*
     * channel0 -> CSIG0
     * channel1 -> CSIG1
     * channel2 -> CSIH0
     * channel3 -> CSIH1
     * channel4 -> CSIH2
     * channel5 -> CSIH3
     * */

    Ret = 0x0;

    DisableAllInterrupts();

    switch(Channel)
    {
#ifdef SPID_CHANNEL_CSIG0_ACTIVE
    case 0:
#if defined(Spid_Channel_CSIG0_Use_ISR)
        if(Spid_TransmitMask & SPID_CSIG0_STATUS_MASK)
        {
            Ret = 1;
            Spid_TransmitMask &= ~SPID_CSIG0_STATUS_MASK;
        }
#else
        while(CSIG0STR0 & 0x0080);
        Ret = 1;
#endif
        break;
#endif

#ifdef SPID_CHANNEL_CSIG1_ACTIVE
    case 1:
#if defined(Spid_Channel_CSIG1_Use_ISR)
        if(Spid_TransmitMask & SPID_CSIG1_STATUS_MASK)
        {
            Ret = 1;
            Spid_TransmitMask &= ~SPID_CSIG1_STATUS_MASK;
        }
#else
        while(CSIG1STR0 & 0x0080u)
        {
          /*loop waiting */;
        }
        Ret = 1;
#endif
        break;
#endif

#ifdef SPID_CHANNEL_CSIH0_ACTIVE
    case 2:
#if defined (Spid_Channel_CSIH0_Use_ISR)
        if(Spid_TransmitMask & SPID_CSIH0_STATUS_MASK)
        {
            Ret = 1;
            Spid_TransmitMask &= ~SPID_CSIH0_STATUS_MASK;
        }
#else
        while(CSIH0STR0 & 0x0080);
        Ret = 1;
#endif
        break;
#endif

#ifdef SPID_CHANNEL_CSIH1_ACTIVE
    case 3:
#if defined (Spid_Channel_CSIH1_Use_ISR)
        if(Spid_TransmitMask & SPID_CSIH1_STATUS_MASK)
        {
            Ret = 1;
            Spid_TransmitMask &= ~SPID_CSIH1_STATUS_MASK;
        }
#else
        while(CSIH1STR0 & 0x0080);
        Ret = 1;
#endif
        break;
#endif

#ifdef SPID_CHANNEL_CSIH2_ACTIVE
    case 4:
#if defined (Spid_Channel_CSIH2_Use_ISR)
        if(Spid_TransmitMask & SPID_CSIH2_STATUS_MASK)
        {
            Ret = 1;
            Spid_TransmitMask &= ~SPID_CSIH2_STATUS_MASK;
        }
#else
        while(CSIH2STR0 & 0x0080u)
        {
          /*loop waiting */;
        }
        Ret = 1;
#endif
        break;
#endif

#ifdef SPID_CHANNEL_CSIH3_ACTIVE
    case 5:
#if defined (Spid_Channel_CSIH3_Use_ISR)
        if(Spid_TransmitMask & SPID_CSIH3_STATUS_MASK)
        {
            Ret = 1;
            Spid_TransmitMask &= ~SPID_CSIH3_STATUS_MASK;
        }
#else
        while(CSIH3STR0 & 0x0080u)
        {
          /*loop waiting */;
        }
        Ret = 1;
#endif
        break;
#endif

    default:
        break;
    }

    EnableAllInterrupts();

    return Ret;
}

/******************************************************************************/
/* Name: SPID_ReceiveByte                                                     */
/* Role: Provide the mean to read received byte on selected channel           */
/* Interface: Channel       IN   Communication channel number                 */
/*            ReceivedByte  OUT  Byte received from serial communication      */
/* Pre-condition: The receive data register for the channel must be full      */
/* Constraints: none                                                          */
/******************************************************************************/
ubyte SPID_ReceiveByte(ubyte Channel)
{
    ubyte Ret;

    /*
     * channel0 -> CSIG0
     * channel1 -> CSIG1
     * channel2 -> CSIH0
     * channel3 -> CSIH1
     * channel4 -> CSIH2
     * channel5 -> CSIH3
     * */

    Ret = 0x0;

    switch(Channel)
    {

#ifdef SPID_CHANNEL_CSIG0_ACTIVE
    case 0:
        Ret =(ubyte) (0xFFu &  CSIG0.RX0);
        break;
#endif

#ifdef SPID_CHANNEL_CSIG1_ACTIVE
    case 1:
        Ret =(ubyte) (0xFFu &  CSIG1.RX0);
        break;
#endif

#ifdef SPID_CHANNEL_CSIH0_ACTIVE
    case 2:
        Ret =(ubyte) (0xFFu &  CSIH0.RX0);
        break;
#endif

#ifdef SPID_CHANNEL_CSIH1_ACTIVE
    case 3:
        Ret =(ubyte) (0xFFu &  CSIH1.RX0H);
        break;
#endif

#ifdef SPID_CHANNEL_CSIH2_ACTIVE
    case 4:
        Ret =(ubyte) (0xFFu & CSIH2.RX0H);
        break;
#endif

#ifdef SPID_CHANNEL_CSIH3_ACTIVE
    case 5:
        Ret =(ubyte) (0xFFu &  CSIH3.RX0H);
        break;
#endif

    default:
        break;
    }
    return Ret;
}

/******************************************************************************/
/* Name: SPID_TrasmitInterrupt_it                                             */
/* Role: Service routine of interrupt generated by SPI channels               */
/* Interface: void                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour:                                                                 */
/* DO                                                                         */
/*  [ Call user interrupt routine ]                                           */
/* OD                                                                         */
/******************************************************************************/
#ifdef SPID_CHANNEL_CSIG0_ACTIVE
__INTERRUPT__ void SPID_TrasmitInt_CSIG0_it(void)
{
    Spid_TransmitMask |= SPID_CSIG0_STATUS_MASK;
}
#endif

#ifdef SPID_CHANNEL_CSIG1_ACTIVE
#if defined(__OSEK__)
__INTERRUPT__ ISR(SPID_TrasmitInt_CSIG1_it)
#else
ISR(SPID_TrasmitInt_CSIG1_it)
#endif/* defined(__OSEK__) */
{
    Spid_TransmitMask |= SPID_CSIG1_STATUS_MASK;
}
#endif

#ifdef SPID_CHANNEL_CSIH0_ACTIVE
#if defined(__OSEK__)
__INTERRUPT__ ISR(SPID_TrasmitInt_CSIH0_it)
#else
ISR(SPID_TrasmitInt_CSIH0_it)
#endif/* defined(__OSEK__) */
{
    Spid_TransmitMask |= SPID_CSIH0_STATUS_MASK;
}
#endif

#ifdef SPID_CHANNEL_CSIH1_ACTIVE
#if defined(__OSEK__)
__INTERRUPT__ ISR(SPID_TrasmitInt_CSIH1_it)
#else
ISR(SPID_TrasmitInt_CSIH1_it)
#endif/* defined(__OSEK__) */
{
    Spid_TransmitMask |= SPID_CSIH1_STATUS_MASK;
}
#endif

#ifdef SPID_CHANNEL_CSIH2_ACTIVE
#if defined(__OSEK__)
__INTERRUPT__ ISR(SPID_TrasmitInt_CSIH2_it)
#else  /* defined(__OSEK__) */
ISR(SPID_TrasmitInt_CSIH2_it)
#endif /* defined(__OSEK__)  */
{
    Spid_TransmitMask |= SPID_CSIH2_STATUS_MASK;
}
#endif

#ifdef SPID_CHANNEL_CSIH3_ACTIVE
#if defined(__OSEK__)
__INTERRUPT__ ISR(SPID_TrasmitInt_CSIH3_it)
#else  /* defined(__OSEK__) */
ISR(SPID_TrasmitInt_CSIH3_it)
#endif /* defined(__OSEK__)  */
{
    Spid_TransmitMask |= SPID_CSIH3_STATUS_MASK;
}
#endif

/******************************************************************************/
/* Name: SPID_ReceiveInterrupt_it                                             */
/* Role: Service routine of interrupt generated by SPI channels               */
/* Interface: void                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour:                                                                 */
/* DO                                                                         */
/*  [ Call user interrupt routine ]                                           */
/* OD                                                                         */
/******************************************************************************/
#ifdef SPID_UserReceiveInterrupt_ch0
ISR(SPID_ReceiveInterrupt_ch0_it)
{
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_SPID0);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  SPID_UserReceiveInterrupt_ch0();

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_SPID0);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
}
#endif /* SPID_UserReceiveInterrupt_ch0 */

#ifdef SPID_UserReceiveInterrupt_ch1
ISR(SPID_ReceiveInterrupt_ch1_it)
{
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_SPID1);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  SPID_UserReceiveInterrupt_ch1();

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_SPID1);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
}
#endif /* SPID_UserReceiveInterrupt_ch1 */

#ifdef SPID_UserReceiveInterrupt_ch2
ISR(SPID_ReceiveInterrupt_ch2_it)
{
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_SPID2);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  SPID_UserReceiveInterrupt_ch2();

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_SPID2);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
}
#endif /* SPID_UserReceiveInterrupt_ch2 */

#ifdef SPID_UserReceiveInterrupt_ch3
ISR(SPID_ReceiveInterrupt_ch3_it)
{
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_SPID3);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  SPID_UserReceiveInterrupt_ch3();

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_SPID3);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
}
#endif /* SPID_UserReceiveInterrupt_ch3 */

/******************************************************************************/
/* Name: SPID_EnableSerialInput                                               */
/* Role: Provide the mean to enable serial input of selected channel          */
/*       -> The pin port is associated to SPI                                 */
/* Interface: Channel        IN   Communication channel number                */
/* Pre-condition: none                                                        */
/* Constraints: Only for V850 Dx3                                             */
/* Behaviour:                                                                 */
/* DO                                                                         */
/*   [ Set pin port configuration to associate pin to SPI ]                   */
/* OD                                                                         */
/******************************************************************************/
 #ifdef __RH850_F1x__

#ifdef SPID_CHANNEL_CSIG0_ACTIVE
#ifdef SPID_CHANNEL_CSIG0_SI_EXT_DRIVE
void Spid_EnableSerialInputCSIG0(void)
{
  #if defined(Spid_Channel_CSIG0_Use_PortGroup_0)
  TARG_SetBitsInShort(PMC0, Spid_Msk_Bit12); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM0,  Spid_Msk_Bit12); /* SI: Input mode */
  #else
  TARG_SetBitsInShort(PMC10, Spid_Msk_Bit8); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM10,  Spid_Msk_Bit8); /* SI: Input mode */
  #endif /* defined(Spid_Channel0_Use_PortGroup_0) */
}
#endif /* SPID_CHANNEL_CSIG0_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_CSIG0_ACTIVE */

#ifdef SPID_CHANNEL_CSIG1_ACTIVE
#ifdef SPID_CHANNEL_CSIG1_SI_EXT_DRIVE
void Spid_EnableSerialInputCSIG1(void)
{
  #if defined(Spid_Channel_CSIG1_Use_PortGroup_11)
  TARG_SetBitsInShort(PMC11, Spid_Msk_Bit11); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM11,  Spid_Msk_Bit11); /* SI: Input mode */
  #endif /* defined(Spid_Channel_CSIG1_Use_PortGroup_11) */
}
#endif /* SPID_CHANNEL_CSIG1_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_CSIG1_ACTIVE */

#ifdef SPID_CHANNEL_CSIH0_ACTIVE
#ifdef SPID_CHANNEL_CSIH0_SI_EXT_DRIVE
void Spid_EnableSerialInputCSIH0(void)
{
  #if defined(Spid_Channel_CSIH0_Use_PortGroup_11)
  TARG_SetBitsInShort(PMC0, Spid_Msk_Bit1); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM0,  Spid_Msk_Bit1); /* SI: Input mode */
  #endif /* defined(Spid_Channel_CSIH0_Use_PortGroup_0) */
}
#endif /* SPID_CHANNEL_CSIH0_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_CSIH0_ACTIVE */

#ifdef SPID_CHANNEL_CSIH1_ACTIVE
#ifdef SPID_CHANNEL_CSIH1_SI_EXT_DRIVE
void Spid_EnableSerialInputCSIH1(void)
{
  #if defined(Spid_Channel_CSIH1_Use_PortGroup_0)
  TARG_SetBitsInShort(PMC0, Spid_Msk_Bit4); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM0,  Spid_Msk_Bit4); /* SI: Input mode */
  #endif /* defined(Spid_Channel_CSIH1_Use_PortGroup_0) */

    #if defined(Spid_Channel_CSIH1_Use_PortGroup_10)
  TARG_SetBitsInShort(PMC10, Spid_Msk_Bit0); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM10,  Spid_Msk_Bit0); /* SI: Input mode */
  #endif /* defined(Spid_Channel_CSIH1_Use_PortGroup_10) */

}
#endif /* SPID_CHANNEL_CSIH1_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_CSIH1_ACTIVE */

#ifdef SPID_CHANNEL_CSIH2_ACTIVE
#ifdef SPID_CHANNEL_CSIH2_SI_EXT_DRIVE
void Spid_EnableSerialInputCSIG2(void)
{
  #if defined(Spid_Channel_CSIH2_Use_PortGroup_11)
  TARG_SetBitsInShort(PMC11, Spid_Msk_Bit4); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM11,  Spid_Msk_Bit4); /* SI: Input mode */
  #endif /* defined(Spid_Channel_CSIH2_Use_PortGroup_11) */
}
#endif /* SPID_CHANNEL_CSIH2_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_CSIH2_ACTIVE */

#ifdef SPID_CHANNEL_CSIH3_ACTIVE
#ifdef SPID_CHANNEL_CSIH3_SI_EXT_DRIVE
void Spid_EnableSerialInputCSIG3(void)
{
  #if defined(Spid_Channel_CSIH3_Use_PortGroup_11)
  TARG_SetBitsInShort(PMC11, Spid_Msk_Bit5); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM11,  Spid_Msk_Bit5); /* SI: Input mode */
  #endif /* defined(Spid_Channel_CSIH3_Use_PortGroup_11) */
}
#endif /* SPID_CHANNEL_CSIH3_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_CSIH3_ACTIVE */

/*********************************************/


/******************************************************************************/
/* Name: SPID_DisableSerialInput                                              */
/* Role: Provide the mean to disable serial input of selected channel         */
/*       -> The pin port is used as I/O                                       */
/* Interface: Channel        IN   Communication channel number                */
/* Pre-condition: none                                                        */
/* Constraints: Only for V850 Dx3                                             */
/* Behaviour:                                                                 */
/* DO                                                                         */
/*   [ Set pin port configuration to associate pin to I/O ]                   */
/* OD                                                                         */
/******************************************************************************/
#ifdef SPID_CHANNEL_CSIG0_ACTIVE
#ifdef SPID_CHANNEL_CSIG0_SI_EXT_DRIVE
void Spid_DisableSerialInputCSIG0(void)
{
  #if defined(Spid_Channel_CSIG0_Use_PortGroup_0)
  TARG_ClearBitsInShort(PMC0, Spid_Msk_Bit12); /* SI: Port mode */
  #else
  TARG_ClearBitsInShort(PMC10, Spid_Msk_Bit8); /* SI: Port mode */
  #endif /* defined(Spid_Channel_CSIG0_Use_PortGroup_0) */
}
#endif /* SPID_CHANNEL_CSIG0_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_CSIG0_ACTIVE */

#ifdef SPID_CHANNEL_CSIG1_ACTIVE
#ifdef SPID_CHANNEL_CSIG1_SI_EXT_DRIVE
void Spid_DisableSerialInputCSIG1(void)
{
  #if defined(Spid_Channel_CSIG1_Use_PortGroup_11)
  TARG_ClearBitsInShort(PMC11, Spid_Msk_Bit11); /* SI: Port mode */
  #endif /* defined(Spid_Channel_CSIG1_Use_PortGroup_11) */
}
#endif /* SPID_CHANNEL_CSIG1_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_CSIG1_ACTIVE */


#ifdef SPID_CHANNEL_CSIH0_ACTIVE
#ifdef SPID_CHANNEL_CSIH0_SI_EXT_DRIVE
void Spid_DisableSerialInputCSIH0(void)
{
  #if defined(Spid_Channel_CSIH0_Use_PortGroup_0)
  TARG_ClearBitsInShort(PMC0, Spid_Msk_Bit1); /* SI: Port mode */
  #endif /* defined(Spid_Channel_CSIG1_Use_PortGroup_11) */
}
#endif /* SPID_CHANNEL_CSIH0_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_CSIH0_ACTIVE */

#ifdef SPID_CHANNEL_CSIH1_ACTIVE
#ifdef SPID_CHANNEL_CSIH1_SI_EXT_DRIVE
void Spid_DisableSerialInputCSIH1(void)
{
  #if defined(Spid_Channel_CSIH1_Use_PortGroup_0)
  TARG_ClearBitsInShort(PMC0, Spid_Msk_Bit4); /* SI: Port mode */
  #endif /* defined(Spid_Channel_CSIG1_Use_PortGroup_11) */

  #if defined(Spid_Channel_CSIH1_Use_PortGroup_10)
  TARG_ClearBitsInShort(PMC10, Spid_Msk_Bit0); /* SI: Port mode */
  #endif /* defined(Spid_Channel_CSIG1_Use_PortGroup_11) */
}
#endif /* SPID_CHANNEL_CSIH1_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_CSIH1_ACTIVE */

#ifdef SPID_CHANNEL_CSIH2_ACTIVE
#ifdef SPID_CHANNEL_CSIH2_SI_EXT_DRIVE
void Spid_DisableSerialInputCSIH2(void)
{
  #if defined(Spid_Channel_CSIH2_Use_PortGroup_11)
  TARG_ClearBitsInShort(PMC11, Spid_Msk_Bit4); /* SI: Port mode */
  #endif /* defined(Spid_Channel_CSIH2_Use_PortGroup_11) */
}
#endif /* SPID_CHANNEL_CSIH2_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_CSIH2_ACTIVE */

#ifdef SPID_CHANNEL_CSIH3_ACTIVE
#ifdef SPID_CHANNEL_CSIH3_SI_EXT_DRIVE
void Spid_DisableSerialInputCSIH3(void)
{
  #if defined(Spid_Channel_CSIG1_Use_PortGroup_11)
  TARG_ClearBitsInShort(PMC11, Spid_Msk_Bit5); /* SI: Port mode */
  #endif /* defined(Spid_Channel_CSIH3_Use_PortGroup_11) */
}
#endif /* SPID_CHANNEL_CSIH3_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_CSIH3_ACTIVE */




#ifdef SPID_CHANNEL_CSIG0_ACTIVE
ubyte Spid_ReceiveByteCSIG0(void)
{
  return(SPID_CSIG0_RX0);
}
#endif /* SPID_CHANNEL_CSIG0_ACTIVE */

#ifdef SPID_CHANNEL_CSIG1_ACTIVE
ubyte Spid_ReceiveByteCSIG1(void)
{
  return(SPID_CSIG1_RX0);
}
#endif /* SPID_CHANNEL_CSIG1_ACTIVE */

#ifdef SPID_CHANNEL_CSIH0_ACTIVE
ubyte Spid_ReceiveByteCSIH0(void)
{
  return(SPID_CSIH0_RX0);
}
#endif /* SPID_CHANNEL_CSIH0_ACTIVE */

#ifdef SPID_CHANNEL_CSIH1_ACTIVE
ubyte Spid_ReceiveByteCSIH1(void)
{
  return(SPID_CSIH1_RX0);
}
#endif /* SPID_CHANNEL_CSIH1_ACTIVE */

#ifdef SPID_CHANNEL_CSIH2_ACTIVE
ubyte Spid_ReceiveByteCSIH2(void)
{
  return(SPID_CSIH2_RX0);
}
#endif /* SPID_CHANNEL_CSIH2_ACTIVE */

#ifdef SPID_CHANNEL_CSIH3_ACTIVE
ubyte Spid_ReceiveByteCSIH3(void)
{
  return(SPID_CSIH3_RX0);
}
#endif /* SPID_CHANNEL_CSIH3_ACTIVE */

/*local function*/
static void Spid_CSIG_initialize( volatile SPID_csig_t * const CSIG_channel,
                                  const SPID_Ch_Config_t *  const Channel)
{

#if 0/*defined(__RH850_F1L__)*/
    SPID_csig_t Csig_tmp;
#endif

    ulong Channel_Clock = 0u;
    ubyte TempCTL0 = 0u;
    ulong TempCTL1 = 0u;
    ulong TempCTL2 = 0u;
    ulong TempCFG0 = 0u;
    ushort CSIGnBRS_tmp = 0u;
    ubyte TempBCTL0 = 0u;


    /* CSI setting */
    /*
     * disable power, tx, rx
     * */
#if defined(__RH850_F1L__)
    CSIG_channel->CTL0.UINT8  = 0x00u;
#elif defined(__RH850_F1K__)
    CSIG_channel->CTL0  = 0x00u;
#else
#error "have to set CTL register to MCU"
#endif

    /*CTL1 setting*/
    TempCTL1 = 0x00u;

#ifdef SPID_CSIG_CTL1
    if((Channel->Mode == SPID_COMMUNICATION_TYPE_3) ||
       (Channel->Mode == SPID_COMMUNICATION_TYPE_4))
    {
        /*
         * mode3 or mod4
         * default level is low
         * */
        TempCTL1 |= CSI_MSK_CSIGnCKR;
    }
    /* Interrupt generation when CSIGnTX0W/H is empty */

    /*disable extended data length*/
    /*disable data consistency check*/
    /*disable loop back */
    /*interrupt no delay*/
    /*disable handshake function*/
    /*disable slave select function*/
    CSIG_channel->CTL1 = TempCTL1;
#endif /*SPID_CSIG_CTL1*/


    /*CTL2 setting*/
    TempCTL2 = 0x00u;

#ifdef SPID_CSIG_CTL2
#if SPID_CKSCLK_ICSI == CKSCLK_ICSI_80MHz
    switch(Channel->CLK)
    {
        case CSIG_CLK_80MHz:
            Channel_Clock = (ulong)80000;
            break;
        case CSIG_CLK_40MHz:
            Channel_Clock = (ulong)40000;
            break;
        case CSIG_CLK_20MHz:
            Channel_Clock = (ulong)20000;
            break;
        case CSIG_CLK_10MHz:
            Channel_Clock = (ulong)10000;
            break;
        case CSIG_CLK_2500KHz:
            Channel_Clock = (ulong)2500;
            break;
        case CSIG_CLK_1250KHz:
            Channel_Clock = (ulong)1250;
            break;
        default:
       	 break;
    }
#endif

    TempCTL2 = ((ulong)(Channel->CLK & 0x07U)) << 13U;
    TempCTL2 |= (Channel_Clock/0x02/Channel->BaudRate)& 0xffful;
    CSIG_channel->CTL2        = TempCTL2;
#endif /*SPID_CSIG_CTL2*/

    /*CFG0 setting*/
    TempCFG0 = 0x00u;

#ifdef SPID_CSIG_CFG0
    /*no parity bit*/
    /*data length*/
    TempCFG0 |= ((ulong)((Channel->DataLenght) & 0x0fu)) << 24;

    /*data direction*/
    if(Channel->DataDiret == SPID_LSB_FIRST)
    {
        TempCFG0 |= CSI_MSK_CSIGnDIR;
    }
    /* Data Phase Selection */
    if((Channel->Mode == SPID_COMMUNICATION_TYPE_2) ||
       (Channel->Mode == SPID_COMMUNICATION_TYPE_4))
    {
        /*
         * mode2 or mod4
         * falling edge
         * */
        TempCFG0 |= CSI_MSK_CSIGnDAP;
    }

    CSIG_channel->CFG0 = TempCFG0;
#endif /*SPID_CSIG_CFG0*/

    /* BCTL0 setting */
    TempBCTL0 = 0x00u;
#ifdef SPID_CSIG_BCTL0
    CSIG_channel->BCTL0.UINT8 = TempBCTL0;
#endif /*SPID_CSIG_BCTL0*/

    /* CTL0 setting */
#if defined(__RH850_F1L__)
    TempCTL0 = 0x00u;
#elif defined(__RH850_F1K__)
    TempCTL0 = 0x00u;
#else
#error "have to set CTL register to MCU"
#endif

#ifdef SPID_CSIG_CTL0
    /*
     * enable TX, RX, PWR
     * */
#if defined(__RH850_F1L__)
    TempCTL0 += CSI_MSK_CSIGnBIT0 +
                           CSI_MSK_CSIGnRXE +
                           CSI_MSK_CSIGnTXE +
                           CSI_MSK_CSIGnPWR;
#elif defined(__RH850_F1K__)
    TempCTL0 |= CSI_MSK_CSIGnBIT0 +
                CSI_MSK_CSIGnRXE +
                CSI_MSK_CSIGnTXE +
                CSI_MSK_CSIGnPWR;
#else
#error "have to set CTL register to MCU"
#endif

#endif /*SPID_CSIG_CTL0*/

#if defined(__RH850_F1L__)
    CSIG_channel->CTL0.UINT8 = TempCTL0;
#elif defined(__RH850_F1K__)
    CSIG_channel->CTL0 = TempCTL0;
#else
#error "have to set CTL register to MCU"
#endif

}

/************************************************************************************************/

 /*local function*/
void SPID_CsigInitialize( volatile SPID_CSIG_Channel_t CsigChannel,
                                   const SPID_Ch_Config_t *  const Channel)
 {

     ulong Channel_Clock = 0u;
     ubyte TempCTL0 = 0u;
     ulong TempCTL1 = 0u;
     ulong TempCTL2 = 0u;
     ulong TempCFG0 = 0u;
     ubyte TempBCTL0 = 0u;

     /*CTL1 setting*/
     TempCTL1 = 0x00u;
     if((Channel->Mode == SPID_COMMUNICATION_TYPE_3) ||
        (Channel->Mode == SPID_COMMUNICATION_TYPE_4))
     {
         /*
          * mode3 or mod4
          * default level is low
          * */
         TempCTL1 |= CSI_MSK_CSIGnCKR;
     }

     if(SPID_DEALY_HALF_CLOCK_INTERRUPT == Channel->InteruptType)
     {
       TempCTL1  |= CSI_MSK_CSIGnSIT/*half clock dealy for all interrupt*/;
     }
     /* Interrupt generation when CSIGnTX0W/H is empty */

     /*disable extended data length*/
     /*disable data consistency check*/
     /*disable loop back */
     /*interrupt no delay*/
     /*disable handshake function*/
     /*disable slave select function*/


     /*CTL2 setting*/
     TempCTL2 = 0x00u;
 #if SPID_CKSCLK_ICSI == CKSCLK_ICSI_80MHz
     switch(Channel->CLK)
     {
         case CSIG_CLK_80MHz:
             Channel_Clock = (ulong)80000;
             break;
         case CSIG_CLK_40MHz:
             Channel_Clock = (ulong)40000;
             break;
         case CSIG_CLK_20MHz:
             Channel_Clock = (ulong)20000;
             break;
         case CSIG_CLK_10MHz:
             Channel_Clock = (ulong)10000;
             break;
         case CSIG_CLK_2500KHz:
             Channel_Clock = (ulong)2500;
             break;
         case CSIG_CLK_1250KHz:
             Channel_Clock = (ulong)1250;
             break;
         default:
             break;
     }
 #endif
     TempCTL2 = ((ulong)(Channel->CLK & 0x07U)) << 13U;
     TempCTL2 |= (Channel_Clock/0x02/Channel->BaudRate)& 0xffful;


     /*CFG0 setting*/
     TempCFG0 = 0x00u;
     /*no parity bit*/
     /*data length*/
     TempCFG0 |= ((ulong)((Channel->DataLenght) & 0x0fu)) << 24;

     /*data direction*/
     if(Channel->DataDiret == SPID_LSB_FIRST)
     {
         TempCFG0 |= CSI_MSK_CSIGnDIR;
     }
     /* Data Phase Selection */
     if((Channel->Mode == SPID_COMMUNICATION_TYPE_2) ||
        (Channel->Mode == SPID_COMMUNICATION_TYPE_4))
     {
         /*  * mode2 or mod4
          * falling edge* */
         TempCFG0 |= CSI_MSK_CSIGnDAP;
     }

     /* BCTL0 setting */
     TempBCTL0 = 0x00u;

     TempCTL0 |= CSI_MSK_CSIGnBIT0 +
                 CSI_MSK_CSIGnRXE +
                 CSI_MSK_CSIGnTXE +
                 CSI_MSK_CSIGnPWR;


     switch(CsigChannel)
     {
       case SPID_CSIG_CHANNEKL_0:
       CSIG0CTL0 = 0x00;
       CSIG0CTL1  = TempCTL1;
       CSIG0CTL2  = TempCTL2;
       CSIG0CFG0  = TempCFG0;
       CSIG0BCTL0 = TempBCTL0;
       CSIG0CTL0 = 0xe1u;
       break;

       case SPID_CSIG_CHANNEKL_1:
         CSIG1CTL0 = 0x00;
        CSIG1CTL1  = TempCTL1;
        CSIG1CTL2  = TempCTL2;
        CSIG1CFG0  = TempCFG0;
        CSIG1BCTL0 = TempBCTL0;
        CSIG1CTL0 = 0xe1u;
       break;
       default:
      	 break;
     }
 }

#if 0
static void Spid_CSIH_initialize( volatile SPID_csih_t * const CSIH,
                                  const SPID_Ch_Config_t *  const Channel)
{

    SPID_csih_t Csih_tmp;
    ulong Channel_Clock;
    ushort CSIGnBRS_tmp;

    /* CSI setting */
    /*
     * disable power, tx, rx
     * */
#if defined(__RH850_F1L__)
    CSIH->CTL0.UINT8  = 0x00;
#elif defined(__RH850_F1K__)
    CSIH->CTL0 = 0x00;
#else
#error "have to set CTL0 register to MCU"
#endif

    /*CTL1 setting*/
    Csih_tmp.CTL1 = (ulong)0x00;
#ifdef SPID_CSIH_CTL1
    /* CSIHnSLRS = 0,
     * rising edge
     * */

    /* CSIHnPHE = 0,
     * The CPU-controlled high-priority communication function is disabled
     * */

    /*CSIHnCKR*/
    if(Channel->Mode == SPID_COMMUNICATION_TYPE_3 ||
       Channel->Mode == SPID_COMMUNICATION_TYPE_4)
    {
        /*
         * mode3 or mod4
         * default level is low
         * */
        Csih_tmp.CTL1 += CSI_MSK_CSIGnCKR;
    }

    /* CSIHnSLIT = 1,
     * Interrupt generation when CSIGnTX0W/H is empty
     * */
    Csih_tmp.CTL1 += CSI_MSK_CSIGnSLIT;

    /*CSIHnCSLx = 0: Chip select is active low.
     * */

    /*CSIHnEDLE = 0: Disables extended data length mode.
     * */

    /*CSIHnJE = 0: Disables job mode
     * */

    /*CSIHnDCS = 0: Disables data consistency check.
     * */

    /*CSIHnCSRI = 0: Chip select signal retains the active level.
     * */

    /*CSIHnLBM = 0: Deactivates loop-back mode.
     * */

    /*CSIHnSIT = 0: Disables the handshake function.
     * */

    /*CSIHnSSE = 0: Input signal CSIHTSSI is disabled.
     * */

    CSIH->CTL1 = Csih_tmp.CTL1;
#endif /*SPID_CSIH_CTL1*/

    /*CTL2 setting*/
    Csih_tmp.CTL2 = 0x00;

#ifdef SPID_CSIH_CTL2
#if SPID_CKSCLK_ICSI == CKSCLK_ICSI_80MHz
    switch(Channel->CLK)
    {
        case CSIG_CLK_80MHz:
            Channel_Clock = (ulong)80000;
            break;
        case CSIG_CLK_40MHz:
            Channel_Clock = (ulong)40000;
            break;
        case CSIG_CLK_20MHz:
            Channel_Clock = (ulong)20000;
            break;
        case CSIG_CLK_10MHz:
            Channel_Clock = (ulong)10000;
            break;
        case CSIG_CLK_2500KHz:
            Channel_Clock = (ulong)2500;
            break;
        case CSIG_CLK_1250KHz:
            Channel_Clock = (ulong)1250;
            break;
    }
#endif

    Csih_tmp.CTL2  = (Channel->CLK & 0x07U) << 13U;
    CSIH->CTL2        = Csih_tmp.CTL2;
#endif /*SPID_CSIH_CTL2*/

    /*BRS0 setting*/
    Csih_tmp.BRS0 = 0x00u;

#ifdef SPID_CSIH_BRS0
    Csih_tmp.BRS0 += ((Channel_Clock)/((ulong)0x02)/(Channel->BaudRate)) & 0xffful;
    CSIH->BRS0 = Csih_tmp.BRS0;
#endif /*SPID_CSIH_BRS0*/

    /*CFG0 setting*/
    Csih_tmp.CFG0 = 0x00u;

#ifdef SPID_CSIH_CFG0
    /*
     * CSIHnBRSSx[1:0]
     * 0 0 The transfer clock frequency is set according to the CSIHnBRS0 setting.
     * */

    /* CSIHnPSx[1:0]
     * 0 0 Does not transmit any parity bit.
     * */

    /*CSIHnDLSx[3:0]
     * */
    Csih_tmp.CFG0 += ((ulong)((Channel->DataLenght) & 0x0f)) << 24;

    /*CSIHnRCBx = 0: Dominant (higher priority)
     **/

    /*CSIHnDIRx
     * */
    if(Channel->DataDiret == SPID_LSB_FIRST)
    {
        Csih_tmp.CFG0 += CSI_MSK_CSIGnDIR;
    }

    /*CSIHnCKPx = 0
     * */

    /*CSIHnDAPx: Data phase selection bit
     * */
    if(Channel->Mode == SPID_COMMUNICATION_TYPE_2 ||
       Channel->Mode == SPID_COMMUNICATION_TYPE_4)
    {
        /*
         * mode2 or mod4
         * falling edge
         * */
        Csih_tmp.CFG0 += CSI_MSK_CSIGnDAP;
    }

    /*CSIHnIDLx 0 : If the CSIHnTX0W.CSIHnCSx settings of two consecutive transfers are
     *              different, an idle state is inserted between two transfers. If the
     *              CSIHnTX0W.CSIHnCSx settings of two consecutive transfers are the same,
     *              an idle state is not inserted between two transfers.
     * */

    /* CSIHnIDx[2:0] : 000B 0.5 transmission clock cycle
     * */

    /* CSIHnHDx[3:0] : 0000B 0.5 transmission clock cycle 1.0 transmission clock cycle
     * */

    /* CSIHnINx[3:0] : 0000B 0.0 transmission clock cycle 0.5 transmission clock cycle
     * */

    /* CSIHnSPx[3:0] : 0000B 0.5 transmission clock cycle
     * */
    CSIH->CFG0 = Csih_tmp.CFG0;
#endif /*SPID_CSIH_CFG0*/

    /* BCTL0 setting */
    Csih_tmp.MCTL0 = 0x00;
#ifdef SPID_CSIH_MCTL0
    /*CSIHnMMS [1:0] 0 0 FIFO mode
     * */
    /*CSIHnTO[4:0] 00000B No time-out is detected
     * */
    CSIH->MCTL0 = Csih_tmp.MCTL0;
#endif /*SPID_CSIH_MCTL0*/

    /* CTL0 setting */
#if defined(__RH850_F1L__)
    Csih_tmp.CTL0.UINT8 = 0x00;
#elif defined(__RH850_F1K__)
    Csih_tmp.CTL0 = 0x00;
#else
#error "have to set CTL0 register to MCU"
#endif

#ifdef SPID_CSIH_CTL0
    /*
     * enable TX, RX, PWR
     * */
#if defined(__RH850_F1L__)
    Csih_tmp.CTL0.UINT8 += CSI_MSK_CSIGnBIT0 +
                           CSI_MSK_CSIGnRXE +
                           CSI_MSK_CSIGnTXE +
                           CSI_MSK_CSIGnPWR;

    CSIH->CTL0.UINT8  = Csih_tmp.CTL0.UINT8;
#elif defined(__RH850_F1K__)
    Csih_tmp.CTL0 += CSI_MSK_CSIGnBIT0 +
                     CSI_MSK_CSIGnRXE +
                     CSI_MSK_CSIGnTXE +
                     CSI_MSK_CSIGnPWR;

    CSIH->CTL0 = Csih_tmp.CTL0;
#else
#error "have to set CTL0 register to MCU"
#endif

#endif /*SPID_CSIH_CTL0*/

}
#endif /* #if 0*/

static void Spid_CSIH_initialize( SPID_CSIH_Channel_t CsihChannl,
                                  const SPID_Ch_Config_t *  const ChannelConfig)
{
    ulong Channel_Clock = (ulong)0;
    SPID_Reg_Config_t SPID_RegConfig = {0};
    /*ushort CSIGnBRS_tmp;*/
    /*CTL1 setting*/
    SPID_RegConfig.TempCtl1 = (ulong)0x00;
    /* CSIHnSLRS = 0,     rising edge  */
    /* CSIHnPHE = 0,   The CPU-controlled high-priority communication function is disable*/
    /*CSIHnCKR*/
    if((ChannelConfig->Mode == SPID_COMMUNICATION_TYPE_3) ||
       (ChannelConfig->Mode == SPID_COMMUNICATION_TYPE_4))
    {
        /* mode3 or mod4 default level is low*/
        SPID_RegConfig.TempCtl1 += CSI_MSK_CSIGnCKR;
    }
    /* CSIHnSLIT = 1,* Interrupt generation when CSIGnTX0W/H is empty  */

    SPID_RegConfig.TempCtl1 += CSI_MSK_CSIGnSLIT;

    /*CSIHnCSLx = 0: Chip select is active low. * */

    /*CSIHnEDLE = 0: Disables extended data length mode.* */

    /*CSIHnJE = 0: Disables job mode* */

    /*CSIHnDCS = 0: Disables data consistency check. * */

    /*CSIHnCSRI = 0: Chip select signal retains the active level. * */

    /*CSIHnLBM = 0: Deactivates loop-back mode.* */

    /*CSIHnSIT = 0: Disables the handshake function. * */

    /*CSIHnSSE = 0: Input signal CSIHTSSI is disabled. * */

    /*CTL2 setting*/
    switch(ChannelConfig->CLK)
    {
        case CSIG_CLK_80MHz:
            Channel_Clock = (ulong)80000;
            break;
        case CSIG_CLK_40MHz:
            Channel_Clock = (ulong)40000;
            break;
        case CSIG_CLK_20MHz:
            Channel_Clock = (ulong)20000;
            break;
        case CSIG_CLK_10MHz:
            Channel_Clock = (ulong)10000;
            break;
        case CSIG_CLK_2500KHz:
            Channel_Clock = (ulong)2500;
            break;
        case CSIG_CLK_1250KHz:
            Channel_Clock = (ulong)1250;
            break;
        default:
            Channel_Clock = (ulong)1250;
            break;
    }
    SPID_RegConfig.TempCtl2  = ((ulong)(ChannelConfig->CLK & 0x07U)) << 13U;

    /*BRS0 setting*/
    SPID_RegConfig.TempBrs0 += ((Channel_Clock)/((ulong)0x02)/(ChannelConfig->BaudRate)) & 0xffful;
    /*CSIH->BRS0 = TempBrs0;*/

    /*CFG0 setting*/
    /* * 0 0 The transfer clock frequency is set according to the CSIHnBRS0 setting. * */

    /* CSIHnPSx[1:0]* 0 0 Does not transmit any parity bit.* */

    /*CSIHnDLSx[3:0]* */

    SPID_RegConfig.Tempcfg0 += ((ulong)((ChannelConfig->DataLenght) & 0x0fu)) << 24;

    /*CSIHnRCBx = 0: Dominant (higher priority) **/

    /*CSIHnDIRx* */

    if(ChannelConfig->DataDiret == SPID_LSB_FIRST)
    {
        SPID_RegConfig.Tempcfg0 += CSI_MSK_CSIGnDIR;
    }
    /*CSIHnCKPx = 0* */

    /*CSIHnDAPx: Data phase selection bit* */

    if((ChannelConfig->Mode == SPID_COMMUNICATION_TYPE_2) ||
       (ChannelConfig->Mode == SPID_COMMUNICATION_TYPE_4))
    {
        /* mode2 or mod4 falling edge */
        SPID_RegConfig.Tempcfg0 += CSI_MSK_CSIGnDAP;
    }

    /*CSIHnIDLx 0 : If the CSIHnTX0W.CSIHnCSx settings of two consecutive transfers are
     *              different, an idle state is inserted between two transfers. If the
     *              CSIHnTX0W.CSIHnCSx settings of two consecutive transfers are the same,
     *              an idle state is not inserted between two transfers.* */

    /* CSIHnIDx[2:0] : 000B 0.5 transmission clock cycle* */

    /* CSIHnHDx[3:0] : 0000B 0.5 transmission clock cycle 1.0 transmission clock cycle* */

    /* CSIHnINx[3:0] : 0000B 0.0 transmission clock cycle 0.5 transmission clock cycle* */

    /* CSIHnSPx[3:0] : 0000B 0.5 transmission clock cycle * */

    /* BCTL0 setting */
   /* Csih_tmp.MCTL0 = 0x00;*/

    /*CSIHnMMS [1:0] 0 0 FIFO mode* */

    /*CSIHnTO[4:0] 00000B No time-out is detected* */

    /*CSIH->MCTL0 = Csih_tmp.MCTL0;*/

    /*SPID_RegConfig.TempCtl0 = 0x00;
    SPID_RegConfig.TempCtl0 += CSI_MSK_CSIGnBIT0 +
                     CSI_MSK_CSIGnRXE +
                     CSI_MSK_CSIGnTXE +
                     CSI_MSK_CSIGnPWR;  */
  switch(CsihChannl)
  {
    case SPID_CSIH_CHANNEKL_0:
    CSIH0CTL1  = SPID_RegConfig.TempCtl1;
    CSIH0CTL2  = SPID_RegConfig.TempCtl2;
    CSIH0BRS0  = SPID_RegConfig.TempBrs0;
    CSIH0CFG0  = SPID_RegConfig.Tempcfg0;
    CSIH0MCTL0 = 0x00u;
    CSIH0CTL0  = 0xe1u;
    break;

    case SPID_CSIH_CHANNEKL_1:
    CSIH1CTL1  = SPID_RegConfig.TempCtl1;
    CSIH1CTL2  = SPID_RegConfig.TempCtl2;
    CSIH1BRS0  = SPID_RegConfig.TempBrs0;
    CSIH1CFG0  = SPID_RegConfig.Tempcfg0;
    CSIH1MCTL0 = 0x00u;
    CSIH1CTL0  = 0xe1u;
    break;

    case SPID_CSIH_CHANNEKL_2:
    CSIH2CTL1  = SPID_RegConfig.TempCtl1;
    CSIH2CTL2  = SPID_RegConfig.TempCtl2;
    CSIH2BRS0  = SPID_RegConfig.TempBrs0;
    CSIH2CFG0  = SPID_RegConfig.Tempcfg0;
    CSIH2MCTL0 = 0x00u;
    CSIH2CTL0  = 0xe1u;
    break;

    case SPID_CSIH_CHANNEKL_3:
    CSIH3CTL1  = SPID_RegConfig.TempCtl1;
    CSIH3CTL2  = SPID_RegConfig.TempCtl2;
    CSIH3BRS0  = SPID_RegConfig.TempBrs0;
    CSIH3CFG0  = SPID_RegConfig.Tempcfg0;
    CSIH3MCTL0 = 0x00u;
    CSIH3CTL0  = 0xe1u;/*Enable TX ,RX*/
    break;
    default:
   	 break;
  }
}


#endif /* __RH850_F1x__ */

/******************************************************************************/
/* RH850 CODE                                                              */
/******************************************************************************/
#endif /* __RH850__ */

/*_____ E N D _____ (spid.c) _________________________________________________*/
