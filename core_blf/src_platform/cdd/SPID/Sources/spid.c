/******************************************************************************/
/*@F_NAME:             spid.c                                                 */
/*@F_PURPOSE:          Serial Synchronous Peripheral Interface Driver         */
/*@F_CREATED_BY:       Olivier DIETLIN                                        */
/*@F_CREATION_DATE:    05/04/2004                                             */
/*@F_MPROC_TYPE:       NEC_V850 Fx3/Dx3/Dx4,MC9S12xx, MC9S08xx, TX49, IMX53,  */
/*                     IMX6x, Renesas RL78_D1A, RL78_F12                      */
/************************************** (C) Copyright 2015 Magneti Marelli ****/

/*_____ I N C L U D E - F I L E S ____________________________________________*/

#ifdef __GHOS__
#include <INTEGRITY.h>
#endif /* __GHOS__ */

#include "syst.h"
#include "spid.h"
#include "spid_config.h"


#ifdef __MC9S12xx__
/******************************************************************************/
/* MC9S12 CODE                                                                */
/******************************************************************************/

/*_____ L O C A L - D E F I N E S ____________________________________________*/

/* Values to set into Baud rate register SPIBR */
#define SPID_FX_DIV_BY_2    0
#define SPID_FX_DIV_BY_4    (SPI_MSK_SPR0)
#define SPID_FX_DIV_BY_8    (SPI_MSK_SPR1)
#define SPID_FX_DIV_BY_16   (SPI_MSK_SPR1 + SPI_MSK_SPR0)
#define SPID_FX_DIV_BY_32   (SPI_MSK_SPR2)
#define SPID_FX_DIV_BY_64   (SPI_MSK_SPR2 + SPI_MSK_SPR0)
#define SPID_FX_DIV_BY_128  (SPI_MSK_SPR2 + SPI_MSK_SPR1)
#define SPID_FX_DIV_BY_256  (SPI_MSK_SPR2 + SPI_MSK_SPR1 + SPI_MSK_SPR0)

/* Values to set into Control register 1 SPICR1 */
#ifdef SPID_CHIP_SELECT_USED
  #define Spid_SPICR1_SSOE_INIT_VALUE     SPI_MSK_SSOE
  #define Spid_SPICR2_MODFEN_INIT_VALUE   SPI_MSK_MODFEN
#else
  #define Spid_SPICR1_SSOE_INIT_VALUE     ((ubyte)0x00)
  #define Spid_SPICR2_MODFEN_INIT_VALUE   ((ubyte)0x00)
#endif /* SPID_CHIP_SELECT_USED */

#ifndef SPID_SLAVE_MODE_USED
  #if (SPID_CLOCK_IDLE_STATE == 0)
    #if (SPID_DATA_SAMPLING_CLOCK_EDGE == 1)
    #define SPID_SPICR1_VALUE  ((SPI_MSK_MSTR)|Spid_SPICR1_SSOE_INIT_VALUE)
    #else
    #define SPID_SPICR1_VALUE  ((SPI_MSK_MSTR + SPI_MSK_CPHA)|Spid_SPICR1_SSOE_INIT_VALUE)
    #endif
  #else
    #if (SPID_DATA_SAMPLING_CLOCK_EDGE == 1)
    #define SPID_SPICR1_VALUE  ((SPI_MSK_MSTR + SPI_MSK_CPOL + SPI_MSK_CPHA)|Spid_SPICR1_SSOE_INIT_VALUE)
    #else
    #define SPID_SPICR1_VALUE  ((SPI_MSK_MSTR + SPI_MSK_CPOL)|Spid_SPICR1_SSOE_INIT_VALUE)
    #endif
  #endif
#else
  #if (SPID_CLOCK_IDLE_STATE == 0)
    #if (SPID_DATA_SAMPLING_CLOCK_EDGE == 1)
    #define SPID_SPICR1_VALUE  Spid_SPICR1_SSOE_INIT_VALUE
    #else
    #define SPID_SPICR1_VALUE  ((SPI_MSK_CPHA)|Spid_SPICR1_SSOE_INIT_VALUE)
    #endif
  #else
    #if (SPID_DATA_SAMPLING_CLOCK_EDGE == 1)
    #define SPID_SPICR1_VALUE  ((SPI_MSK_CPOL + SPI_MSK_CPHA)|Spid_SPICR1_SSOE_INIT_VALUE)
    #else
    #define SPID_SPICR1_VALUE  ((SPI_MSK_CPOL)|Spid_SPICR1_SSOE_INIT_VALUE)
    #endif
  #endif
#endif

/* Values to set into Control register 2 SPICR2 */
#ifdef SPID_BIDIR_MODE_USED
#define SPID_SPICR2_VALUE  ((SPI_MSK_SPISWAI + SPI_MSK_SPC0)|Spid_SPICR2_MODFEN_INIT_VALUE)
#else
#define SPID_SPICR2_VALUE  ((SPI_MSK_SPISWAI)|Spid_SPICR2_MODFEN_INIT_VALUE)
#endif


/*_____ L O C A L - F U N C T I O N S - P R O T O T Y P E S __________________*/


/* _____ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

#ifdef SPID_UserReceiveInterrupt
extern void SPID_UserReceiveInterrupt (void);
#endif


/*_____ G L O B A L - F U N C T I O N S ______________________________________*/

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
#ifdef SPID_ACTIVE_CHANNEL_0

  #ifndef SPID_SLAVE_MODE_USED
  /* Select clock speed */
  TARG_WriteByte(SPIBR, SPID_CLOCK_SELECTION);
  #endif

  /* Select mode */
  TARG_WriteByte(SPICR1, SPID_SPICR1_VALUE);
  TARG_WriteByte(SPICR2, SPID_SPICR2_VALUE);

  #ifdef SPID_AUTO_START_USED
  /* Start channel */
  TARG_WriteBit(SPICR1, SPI_BIT_SPE, 1);
  #endif

#endif /* SPID_ACTIVE_CHANNEL_0 */
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
#ifdef SPID_ACTIVE_CHANNEL_0
  /* Stop channel */
  TARG_WriteBit(SPICR1, SPI_BIT_SPE, 0);
#endif
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
#ifdef SPID_ACTIVE_CHANNEL_0
  /* Init and Start channel */
  SPID_Init();
#endif
}

/******************************************************************************/
/* Name: SPID_ReceiveInterrupt_it                                             */
/* Role: Service routine of interrupt generated by SPI                        */
/* Interface: void                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour:                                                                 */
/* DO                                                                         */
/*  [ Call user interrupt routine ]                                           */
/* OD                                                                         */
/******************************************************************************/
#ifdef SPID_UserReceiveInterrupt
ISR(SPID_ReceiveInterrupt_it)
{
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_EnterItDurationMeasurement(RTOS_MEAS_IT_SPID);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  #ifdef SPID_UserReceiveInterrupt
  SPID_UserReceiveInterrupt();
  #endif

  #ifdef __IT_DURATION_MEASUREMENT__
  RTOS_LeaveItDurationMeasurement(RTOS_MEAS_IT_SPID);
  #endif /* __IT_DURATION_MEASUREMENT__ */

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
}
#endif


/*_____ L O C A L - F U N C T I O N S ________________________________________*/

/******************************************************************************/
/* MC9S12 CODE                                                                */
/******************************************************************************/
#endif /* __MC9S12xx__ */


#ifdef __MC9S08AWxx__
/******************************************************************************/
/* MC9S08 CODE                                                                */
/******************************************************************************/

/*_____ L O C A L - D E F I N E S ____________________________________________*/

/* Values to set into Baud rate register SPIBR */
#define SPID_FX_DIV_BY_2    0
#define SPID_FX_DIV_BY_4    (SPI_MSK_SPR0)
#define SPID_FX_DIV_BY_8    (SPI_MSK_SPR1)
#define SPID_FX_DIV_BY_16   (SPI_MSK_SPR1 + SPI_MSK_SPR0)
#define SPID_FX_DIV_BY_32   (SPI_MSK_SPR2)
#define SPID_FX_DIV_BY_64   (SPI_MSK_SPR2 + SPI_MSK_SPR0)
#define SPID_FX_DIV_BY_128  (SPI_MSK_SPR2 + SPI_MSK_SPR1)
#define SPID_FX_DIV_BY_256  (SPI_MSK_SPR2 + SPI_MSK_SPR1 + SPI_MSK_SPR0)

/* Values to set into Control register 1 SPI1C1 */
#ifndef SPID_SLAVE_MODE_USED
  #if (SPID_CLOCK_IDLE_STATE == 0)
    #if (SPID_DATA_SAMPLING_CLOCK_EDGE == 1)
    #define SPID_SPI1C1_VALUE  (SPI_MSK_MSTR)
    #else
    #define SPID_SPI1C1_VALUE  (SPI_MSK_MSTR + SPI_MSK_CPHA)
    #endif
  #else
    #if (SPID_DATA_SAMPLING_CLOCK_EDGE == 1)
    #define SPID_SPI1C1_VALUE  (SPI_MSK_MSTR + SPI_MSK_CPOL + SPI_MSK_CPHA)
    #else
    #define SPID_SPI1C1_VALUE  (SPI_MSK_MSTR + SPI_MSK_CPOL)
    #endif
  #endif
#else
  #if (SPID_CLOCK_IDLE_STATE == 0)
    #if (SPID_DATA_SAMPLING_CLOCK_EDGE == 1)
    #define SPID_SPI1C1_VALUE  (0)
    #else
    #define SPID_SPI1C1_VALUE  (SPI_MSK_CPHA)
    #endif
  #else
    #if (SPID_DATA_SAMPLING_CLOCK_EDGE == 1)
    #define SPID_SPI1C1_VALUE  (SPI_MSK_CPOL + SPI_MSK_CPHA)
    #else
    #define SPID_SPI1C1_VALUE  (SPI_MSK_CPOL)
    #endif
  #endif
#endif

/* Values to set into Control register 2 SPI1C2 */
#ifdef SPID_BIDIR_MODE_USED
#define SPID_SPI1C2_VALUE  (SPI_MSK_SPISWAI + SPI_MSK_SPC0)
#else
#define SPID_SPI1C2_VALUE  (SPI_MSK_SPISWAI)
#endif


/*_____ L O C A L - F U N C T I O N S - P R O T O T Y P E S __________________*/


/* _____ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

#ifdef SPID_UserReceiveInterrupt
extern void SPID_UserReceiveInterrupt (void);
#endif


/*_____ G L O B A L - F U N C T I O N S ______________________________________*/

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
#ifdef SPID_ACTIVE_CHANNEL_0

  #ifndef SPID_SLAVE_MODE_USED
  /* Select clock speed */
  TARG_WriteByte(SPI1BR, SPID_CLOCK_SELECTION);
  #endif

  /* Select mode */
  TARG_WriteByte(SPI1C1, SPID_SPI1C1_VALUE);
  TARG_WriteByte(SPI1C2, SPID_SPI1C2_VALUE);

  #ifdef SPID_AUTO_START_USED
  /* Start channel */
  TARG_WriteBit(SPI1C1, SPI_BIT_SPE, 1);
  #endif

#endif /* SPID_ACTIVE_CHANNEL_0 */
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
#ifdef SPID_ACTIVE_CHANNEL_0
  /* Stop channel */
  TARG_WriteBit(SPI1C1, SPI_BIT_SPE, 0);
#endif
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
#ifdef SPID_ACTIVE_CHANNEL_0
  /* Init and Start channel */
  SPID_Init();
#endif
}

/******************************************************************************/
/* Name: SPID_ReceiveInterrupt_it                                             */
/* Role: Service routine of interrupt generated by SPI                        */
/* Interface: void                                                            */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour:                                                                 */
/* DO                                                                         */
/*  [ Call user interrupt routine ]                                           */
/* OD                                                                         */
/******************************************************************************/
#ifdef SPID_UserReceiveInterrupt
ISR(SPID_ReceiveInterrupt_it)
{
  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  ubyte OldMeasuredTask;

  RTOS_DisableAllInterrupts();
  OldMeasuredTask = RTOS_MeasuredTask;
  RTOS_TaskMeasurementEnterIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */

  #ifdef SPID_UserReceiveInterrupt
  SPID_UserReceiveInterrupt();
  #endif

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
}
#endif /* SPID_UserReceiveInterrupt */


/*_____ L O C A L - F U N C T I O N S ________________________________________*/

/******************************************************************************/
/* MC9S08 CODE                                                                */
/******************************************************************************/
#endif /* __MC9S08AWxx__ */


#ifdef __NEC_V850__
/******************************************************************************/
/* NEC V850 CODE                                                              */
/******************************************************************************/
#if (defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__))
typedef enum
{
  SPID_DISABLE_TRANSMIT_OPERATION = ((ubyte) 0x00),
  SPID_ENABLE_TRANSMIT_OPERATION  = ((ubyte) CSI_MSK_CB0TXE)
} SPID_TXE_t;

typedef enum
{
  SPID_DISABLE_RECEIVE_OPERATION = ((ubyte) 0x00),
  SPID_ENABLE_RECEIVE_OPERATION  = ((ubyte) CSI_MSK_CB0RXE)
} SPID_RXE_t;

typedef enum
{
  SPID_MSB_FIRST = ((ubyte) 0x00),
  SPID_LSB_FIRST = ((ubyte) CSI_MSK_CB0DIR)
} SPID_DIR_t;

typedef enum
{
  SPID_SINGLE_TRANSFER      = ((ubyte) 0x00),
  SPID_CONTINUOUS_TRANSFER  = ((ubyte) CSI_MSK_CB0TMS)
} SPID_TMS_t;

typedef enum
{
  SPID_COMM_START_TRIGGER_INVALID   = ((ubyte) 0x00),
  SPID_COMM_START_TRIGGER_VALID     = ((ubyte) CSI_MSK_CB0SCE)
} SPID_SCE_t;

typedef enum
{
  SPID_8_BITS_DATA_LENGHT  = ((ubyte) 0x00),
  SPID_9_BITS_DATA_LENGHT  = ((ubyte) 0x01),
  SPID_10_BITS_DATA_LENGHT = ((ubyte) 0x02),
  SPID_11_BITS_DATA_LENGHT = ((ubyte) 0x03),
  SPID_12_BITS_DATA_LENGHT = ((ubyte) 0x04),
  SPID_13_BITS_DATA_LENGHT = ((ubyte) 0x05),
  SPID_14_BITS_DATA_LENGHT = ((ubyte) 0x06),
  SPID_15_BITS_DATA_LENGHT = ((ubyte) 0x07),
  SPID_16_BITS_DATA_LENGHT = ((ubyte) 0x08)
} SPID_REGISTER_DATA_LENGHT_t;

typedef enum
{
  SPID_COMMUNICATION_TYPE_1 = ((ubyte) 0x00),
  SPID_COMMUNICATION_TYPE_2 = ((ubyte) CSI_MSK_CB0DAP),
  SPID_COMMUNICATION_TYPE_3 = ((ubyte) CSI_MSK_CB0CKP),
  SPID_COMMUNICATION_TYPE_4 = ((ubyte) CSI_MSK_CB0CKP + CSI_MSK_CB0DAP)
} SPID_CHANNEL_0_COMMUNICATION_TYPE_t;
#endif /* defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */

#ifdef __REL_V850_Dx4__
typedef enum
{
  SPID_DISABLE_TRANSMIT_OPERATION = ((ubyte) 0x00),
  SPID_ENABLE_TRANSMIT_OPERATION  = ((ubyte) CSI_MSK_CSIGnTXE)
} SPID_TXE_t;

typedef enum
{
  SPID_DISABLE_RECEIVE_OPERATION = ((ubyte) 0x00),
  SPID_ENABLE_RECEIVE_OPERATION  = ((ubyte) CSI_MSK_CSIGnRXE)
} SPID_RXE_t;

typedef enum
{
  SPID_MSB_FIRST = ((ubyte) 0x00),
  SPID_LSB_FIRST = ((ubyte) CSI_MSK_CSIGnDIR)
} SPID_DIR_t;

typedef enum
{
  SPID_16_BITS_DATA_LENGHT = ((ubyte) 0x00),
  SPID_1_BITS_DATA_LENGHT  = ((ubyte) 0x01),
  SPID_2_BITS_DATA_LENGHT  = ((ubyte) 0x02),
  SPID_3_BITS_DATA_LENGHT  = ((ubyte) 0x03),
  SPID_4_BITS_DATA_LENGHT  = ((ubyte) 0x04),
  SPID_5_BITS_DATA_LENGHT  = ((ubyte) 0x05),
  SPID_6_BITS_DATA_LENGHT  = ((ubyte) 0x06),
  SPID_7_BITS_DATA_LENGHT  = ((ubyte) 0x07),
  SPID_8_BITS_DATA_LENGHT  = ((ubyte) 0x08),
  SPID_9_BITS_DATA_LENGHT  = ((ubyte) 0x09),
  SPID_10_BITS_DATA_LENGHT = ((ubyte) 0x0a),
  SPID_11_BITS_DATA_LENGHT = ((ubyte) 0x0b),
  SPID_12_BITS_DATA_LENGHT = ((ubyte) 0x0c),
  SPID_13_BITS_DATA_LENGHT = ((ubyte) 0x0d),
  SPID_14_BITS_DATA_LENGHT = ((ubyte) 0x0e),
  SPID_15_BITS_DATA_LENGHT = ((ubyte) 0x0f)
} SPID_REGISTER_DATA_LENGHT_t;

typedef enum
{
  SPID_NO_PARITY        = ((ubyte) 0x00),
  SPID_ADD_PARITY_BIT   = ((ubyte) 0x01),
  SPID_ADD_ODD_PARITY   = ((ubyte) 0x02),
  SPID_ADD_EVEN_PARITY  = ((ubyte) 0x03)
} SPID_PARITY_t;

typedef enum
{
  SPID_COMMUNICATION_TYPE_1 = ((ubyte) 0x00),
  SPID_COMMUNICATION_TYPE_2 = ((ubyte) 0x01),
  SPID_COMMUNICATION_TYPE_3 = ((ubyte) 0x02),
  SPID_COMMUNICATION_TYPE_4 = ((ubyte) 0x03)
} SPID_CHANNEL_0_COMMUNICATION_TYPE_t;
#endif /* __REL_V850_Dx4__ */

/* Values to set into clock select register CBnCTL1 */
/* Preset values for the transmit/receive clock     */
#if defined(__NEC_V850_Fx3__)
#define SPID_FXP1_DIV_BY_2           0
#define SPID_FXP1_DIV_BY_4           (CSI_MSK_CB0CKS0)
#define SPID_FXP1_DIV_BY_8           (CSI_MSK_CB0CKS1)
#define SPID_FXP1_DIV_BY_16          (CSI_MSK_CB0CKS0 + CSI_MSK_CB0CKS1)
#define SPID_FXP1_DIV_BY_32          (CSI_MSK_CB0CKS2)
#define SPID_FXP1_DIV_BY_64          (CSI_MSK_CB0CKS0 + CSI_MSK_CB0CKS2)
#define SPID_FXP1_DIV_BY_128         (CSI_MSK_CB0CKS1 + CSI_MSK_CB0CKS2)
#define SPID_BAUD_RATE_GENERATOR     (CSI_MSK_CB0CKS1 + CSI_MSK_CB0CKS2)
#define SPID_TIMER_OUTPUT            (CSI_MSK_CB0CKS1 + CSI_MSK_CB0CKS2)
#define SPID_SLAVE_MODE              (CSI_MSK_CB0CKS0 + CSI_MSK_CB0CKS1 + CSI_MSK_CB0CKS2)
#endif /* defined(__NEC_V850_Fx3__) */

#if defined(__NEC_V850_Dx3__)
#define SPID_BAUD_RATE_GENERATOR     0
#define SPID_8MHz                    (CSI_MSK_CB0CKS0)
#define SPID_4MHz                    (CSI_MSK_CB0CKS1)
#define SPID_2MHz                    (CSI_MSK_CB0CKS0 + CSI_MSK_CB0CKS1)
#define SPID_1MHz                    (CSI_MSK_CB0CKS2)
#define SPID_500KHz                  (CSI_MSK_CB0CKS0 + CSI_MSK_CB0CKS2)
#define SPID_250KHz                  (CSI_MSK_CB0CKS1 + CSI_MSK_CB0CKS2)
#define SPID_SLAVE_MODE              (CSI_MSK_CB0CKS0 + CSI_MSK_CB0CKS1 + CSI_MSK_CB0CKS2)
#endif /* defined(__NEC_V850_Dx3__) */

#ifdef __REL_V850_Dx4__
#define SPID_BAUD_RATE_STOP     0
#define SPID_BAUD_RATE_GENERATOR(Channel, Baud) \
    ((ushort)((SPID_CHANNEL_ ## Channel ## _CLOCK_FREQUENCY)/Baud/2)&0x0FFF)
#define SPID_SLAVE_MODE              (CSI_MSK_CSIGnPRS0 + CSI_MSK_CSIGnPRS1 + CSI_MSK_CSIGnPRS2)

#endif /* __REL_V850_Dx4__ */

#if (defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__))
#define Spid_Msk_Bit0                (ubyte)(0x01)
#define Spid_Msk_Bit1                (ubyte)(0x02)
#define Spid_Msk_Bit2                (ubyte)(0x04)
#define Spid_Msk_Bit3                (ubyte)(0x08)
#define Spid_Msk_Bit4                (ubyte)(0x10)
#define Spid_Msk_Bit5                (ubyte)(0x20)
#define Spid_Msk_Bit6                (ubyte)(0x40)
#define Spid_Msk_Bit7                (ubyte)(0x80)
#endif /* defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */

#ifdef __REL_V850_Dx4__
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
#endif /* __REL_V850_Dx4__ */

#if (defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__))
#define Spid_SetCTLregister(Channel)                                           \
        /* Set selected clock speed, phase and edge */                         \
        TARG_WriteByte(CB ## Channel ## CTL1,                                  \
                       SPID_CHANNEL_ ## Channel ## _CLOCK_SELECTION        +   \
                       SPID_CHANNEL_ ## Channel ## _COMMUNICATION_TYPE);       \
        /* Select transfer length */                                           \
        TARG_WriteByte(CB ## Channel ## CTL2,                                  \
                       SPID_8_BITS_DATA_LENGHT);                               \
        /* Set selected mode and start the channel */                          \
        TARG_WriteByte(CB ## Channel ## CTL0,                                  \
                       CSI_MSK_CB0PWR  /* set the POWER Bit */             +   \
                       CSI_MSK_CB0TXE  /* enable transmit operations */    +   \
                       CSI_MSK_CB0RXE  /* enable receive operations */     +   \
                       SPID_CHANNEL_ ## Channel ## _DIRECTION_MODE         +   \
                       CSI_MSK_CB0SCE)
#endif /* defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */

#ifdef __REL_V850_Dx4__
#define Spid_SetCTLregister(Channel)                                            \
        /* Set Bit0 in CSIGnCTL0*/                                              \
        TARG_SetBits(CSIG ## Channel ## CTL0, CSI_MSK_CSIGnBIT0);               \
        /* Set CSIG phase and edge */                                           \
        if(SPID_CHANNEL_ ## Channel ## _COMMUNICATION_TYPE == 0)                \
        {                                                                       \
          TARG_ClearBitsInLong(CSIG ## Channel ## CTL1,CSI_MSK_CSIGnCKR);       \
          TARG_ClearBitsInLong(CSIG ## Channel ## CFG0,CSI_MSK_CSIGnDAP);       \
        }                                                                       \
        else if(SPID_CHANNEL_ ## Channel ## _COMMUNICATION_TYPE == 1)           \
        {                                                                       \
          TARG_ClearBitsInLong(CSIG ## Channel ## CTL1,CSI_MSK_CSIGnCKR);       \
          TARG_SetBitsInLong(CSIG ## Channel ## CFG0,CSI_MSK_CSIGnDAP);         \
        }                                                                       \
        else if(SPID_CHANNEL_ ## Channel ## _COMMUNICATION_TYPE == 2)           \
        {                                                                       \
          TARG_SetBitsInLong(CSIG ## Channel ## CTL1,CSI_MSK_CSIGnCKR);         \
          TARG_ClearBitsInLong(CSIG ## Channel ## CFG0,CSI_MSK_CSIGnDAP);       \
        }                                                                       \
        else if(SPID_CHANNEL_ ## Channel ## _COMMUNICATION_TYPE == 3)           \
        {                                                                       \
          TARG_SetBitsInLong(CSIG ## Channel ## CTL1,CSI_MSK_CSIGnCKR);         \
          TARG_SetBitsInLong(CSIG ## Channel ## CFG0,CSI_MSK_CSIGnDAP);         \
        }                                                                       \
        /* set the interrupt timing and the interrupt delay mode*/              \
        TARG_ClearBitsInLong(CSIG ## Channel ## CTL1,                           \
                             (CSI_MSK_CSIGnSLIT + CSI_MSK_CSIGnEDLE +           \
                              CSI_MSK_CSIGnDCS  + CSI_MSK_CSIGnLMB  +           \
                              CSI_MSK_CSIGnSIT  + CSI_MSK_CSIGnHSE  +           \
                              CSI_MSK_CSIGnSSE));                               \
        /* set CSIG transfer speed */                                           \
        TARG_WriteShort(CSIG ## Channel ## CTL2,                                \
                       SPID_CHANNEL_ ## Channel ## _CLOCK_SELECTION);           \
        /* Select transfer length and direction*/                               \
        TARG_WriteLong(CSIG ## Channel ## CFG0,                                 \
                       ((ulong)SPID_8_BITS_DATA_LENGHT << 24) +                 \
                       ((ulong)SPID_CHANNEL_ ## Channel ## _DIRECTION_MODE));   \
        /* Set selected mode and start the channel */                           \
        TARG_WriteByte(CSIG ## Channel ## CTL0,                                 \
                       CSI_MSK_CSIGnPWR  /* set the POWER Bit */             +  \
                       CSI_MSK_CSIGnTXE  /* enable transmit operations */    +  \
                       CSI_MSK_CSIGnRXE  /* enable receive operations  */       \
                       )
#endif /* __REL_V850_Dx4__ */

/*_____ L O C A L - F U N C T I O N S - P R O T O T Y P E S __________________*/


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
  /* SPI CHANNEL 0 ___Fx3, Dx3 & Dx4 ______________________________ */
  #ifdef SPID_CHANNEL_0_ACTIVE

  /* Set the SCK, SO and SI pins as alternate port mode */
  #ifdef __NEC_V850_Fx3__
  TARG_ClearBits(PFCE4, Spid_Msk_Bit0 + Spid_Msk_Bit1 + Spid_Msk_Bit2);
  TARG_ClearBits(PFC4, Spid_Msk_Bit0 + Spid_Msk_Bit1 + Spid_Msk_Bit2);
  TARG_SetBits(PMC4, Spid_Msk_Bit0 + Spid_Msk_Bit1 + Spid_Msk_Bit2);
  #endif /* __NEC_V850_Fx3__ */

  #if defined(__NEC_V850_Dx3__)
  #if defined(Spid_Channel0_Use_PortGroup_10) || \
      defined(__NEC_V850_DG3__)
  #if !defined(__NEC_V850_DG3__)
  TARG_WriteBit(PFSR0, BIT0, 1); /* use port group 10 */
  #endif /* !defined(__NEC_V850_DG3__) */
  #ifndef SPID_CHANNEL_0_TRANSMIT_ONLY
  #ifndef SPID_CHANNEL_0_SI_EXT_DRIVE
  TARG_WriteBit(PMC10, BIT5, 1); /* SI: Alternate mode */
  #endif /* SPID_CHANNEL_0_SI_EXT_DRIVE */
  #endif /* SPID_CHANNEL_0_TRANSMIT_ONLY */
  TARG_WriteBit(PMC10, BIT6, 1); /* SO: Alternate mode */
  TARG_WriteBit(PMC10, BIT7, 1); /* CLK: Alternate mode */
  #ifndef SPID_CHANNEL_0_TRANSMIT_ONLY
  #ifndef SPID_CHANNEL_0_SI_EXT_DRIVE
  TARG_WriteBit(PM10,  BIT5, 1); /* SI: input mode */
  #endif /* SPID_CHANNEL_0_SI_EXT_DRIVE */
  #endif /* SPID_CHANNEL_0_TRANSMIT_ONLY */
  TARG_WriteBit(PM10,  BIT6, 0); /* SO: output mode */
  #if (SPID_CHANNEL_0_CLOCK_SELECTION == SPID_SLAVE_MODE)
  TARG_WriteBit(PM10,  BIT7, 1); /* CLK: input mode */
  #else
  TARG_WriteBit(PM10,  BIT7, 0); /* CLK: output mode */
  #endif /* (SPID_CHANNEL_0_CLOCK_SELECTION == SPID_SLAVE_MODE) */
  #else
  TARG_WriteBit(PFSR0, BIT0, 0); /* use port group 4 */
  #ifndef SPID_CHANNEL_0_TRANSMIT_ONLY
  #ifndef SPID_CHANNEL_0_SI_EXT_DRIVE
  TARG_WriteBit(PMC4,  BIT0, 1); /* SI: Alternate mode */
  #endif /* SPID_CHANNEL_0_SI_EXT_DRIVE */
  #endif /* SPID_CHANNEL_0_TRANSMIT_ONLY */
  TARG_WriteBit(PMC4,  BIT1, 1); /* SO: Alternate mode */
  TARG_WriteBit(PMC4,  BIT2, 1); /* CLK: Alternate mode */
  #ifndef SPID_CHANNEL_0_TRANSMIT_ONLY
  #ifndef SPID_CHANNEL_0_SI_EXT_DRIVE
  TARG_WriteBit(PM4,   BIT0, 1); /* SI: input mode */
  #endif /* SPID_CHANNEL_0_SI_EXT_DRIVE */
  #endif /* SPID_CHANNEL_0_TRANSMIT_ONLY */
  TARG_WriteBit(PM4,   BIT1, 0); /* SO: output mode */
  #if (SPID_CHANNEL_0_CLOCK_SELECTION == SPID_SLAVE_MODE)
  TARG_WriteBit(PM4,   BIT2, 1); /* CLK: input mode */
  #else
  TARG_WriteBit(PM4,   BIT2, 0); /* CLK: output mode */
  #endif /* (SPID_CHANNEL_0_CLOCK_SELECTION == SPID_SLAVE_MODE) */
  #endif /* defined(Spid_Channel0_Use_PortGroup_10) || \
            defined(__NEC_V850_DG3__) */
  #endif /* defined(__NEC_V850_Dx3__) */

  #if defined(__NEC_V850_Dx3__)
  #if (SPID_CHANNEL_0_CLOCK_SELECTION == SPID_BAUD_RATE_GENERATOR)
  /* Configure the baud rate generator if used by channel 0 */
  TARG_WriteByte(PRSCM0, SPID_CHANNEL_0_BRG_CONFIGURATION);
  TARG_WriteByte(PRSM0,  CSI_MSK_BGCE0 );
  #endif /* SPID_CHANNEL_0_CLOCK_SELECTION */
  #endif /* __NEC_V850_Dx3__ */

  #ifdef __REL_V850_Dx4__
  /* Set the SSI, RY, SCK, SO and SI pins as alternate port mode */
  #if defined(Spid_Channel0_Use_PortGroup_0)
  TARG_SetBitsInShort(PMC0,  Spid_Msk_Bit12 + Spid_Msk_Bit13 + \
                             Spid_Msk_Bit14 + Spid_Msk_Bit15);
  TARG_SetBitsInShort(PFCE0, Spid_Msk_Bit12 + Spid_Msk_Bit13 + \
                             Spid_Msk_Bit14 + Spid_Msk_Bit15);
  TARG_SetBitsInShort(PFC0,  Spid_Msk_Bit12 + Spid_Msk_Bit13 + \
                             Spid_Msk_Bit14 + Spid_Msk_Bit15);

  /* SSI & SDI are controlled by PM */
  TARG_SetBitsInShort(PM0, Spid_Msk_Bit12 + Spid_Msk_Bit13);

  /* SDO & SCL are controlled by CSI module */
  TARG_SetBitsInShort(PIPC0, Spid_Msk_Bit14 + Spid_Msk_Bit15);
  #endif /* defined(Spid_Channel0_Use_PortGroup_0) */

  #if defined(Spid_Channel0_Use_PortGroup_4)
  TARG_SetBitsInShort(PMC4,    Spid_Msk_Bit3 + Spid_Msk_Bit4 + \
                               Spid_Msk_Bit5 + Spid_Msk_Bit9);
  TARG_ClearBitsInShort(PFCE4, Spid_Msk_Bit3 + Spid_Msk_Bit4 + \
                               Spid_Msk_Bit5 + Spid_Msk_Bit9);
  TARG_SetBitsInShort(PFC4,    Spid_Msk_Bit3 + Spid_Msk_Bit4 + \
                               Spid_Msk_Bit5 + Spid_Msk_Bit9);

  /* SDI & RDY are controlled by PM */
  TARG_SetBitsInShort(PM4, Spid_Msk_Bit3);
  TARG_ClearBitsInShort(PM4, Spid_Msk_Bit9);

  /* SDO & SCL are controlled by CSI module */
  TARG_SetBitsInShort(PIPC4, Spid_Msk_Bit4 + Spid_Msk_Bit5);
  #endif /* defined(Spid_Channel0_Use_PortGroup_4) */

  TARG_SetBits(FCLA24CTL0, Spid_Msk_Bit7); /* bypass SCL input  */
  TARG_SetBits(FCLA24CTL2, Spid_Msk_Bit7); /* bypass SDI input  */
  TARG_SetBits(FCLA24CTL3, Spid_Msk_Bit7); /* bypass SSI input  */
  #endif /* __REL_V850_Dx4__ */

  /* Set selected clock speed, phase and edge in CTL1           */
  /* Select transfer length in CTL2                             */
  /* Set selected mode (single, continuous, ... ) in CTL0       */
  /* Start channel                                              */
  Spid_SetCTLregister(0);
  #endif /* SPID_CHANNEL_0_ACTIVE */


  /* SPI CHANNEL 1 ___Fx3, Dx3 & Dx4 ______________________________ */
  /* ______________________________________________________________ */
  #ifdef SPID_CHANNEL_1_ACTIVE

  /* Set the SCK, SO and SI pins as alternate port mode */
  #ifdef __NEC_V850_Fx3__
  TARG_SetBits(PFC9L, Spid_Msk_Bit7);
  TARG_SetBits(PMC9L, Spid_Msk_Bit7);
  TARG_ClearBits(PFCE9L, Spid_Msk_Bit7);

  TARG_SetBits(PFC9H, Spid_Msk_Bit0 + Spid_Msk_Bit1);
  TARG_SetBits(PMC9H, Spid_Msk_Bit0 + Spid_Msk_Bit1);
  TARG_ClearBits(PFCE9H, Spid_Msk_Bit0 + Spid_Msk_Bit1);
  #endif /* __NEC_V850_Fx3__ */

  #if defined(__NEC_V850_Dx3__)
  #if defined(Spid_Channel1_Use_PortGroup_9)
  /* DG3 device only */
  TARG_WriteBit(PFSR0, BIT1, 1); /* use port group 9 */
  #ifndef SPID_CHANNEL_1_TRANSMIT_ONLY
  #ifndef SPID_CHANNEL_1_SI_EXT_DRIVE
  TARG_WriteBit(PMC9,  BIT0, 1); /* SI: Alternate mode */
  #endif /* SPID_CHANNEL_1_SI_EXT_DRIVE */
  #endif /* SPID_CHANNEL_1_TRANSMIT_ONLY */
  TARG_WriteBit(PMC9,  BIT1, 1); /* SO: Alternate mode */
  TARG_WriteBit(PMC9,  BIT2, 1); /* CLK: Alternate mode */
  #ifndef SPID_CHANNEL_1_TRANSMIT_ONLY
  #ifndef SPID_CHANNEL_1_SI_EXT_DRIVE
  TARG_WriteBit(PM9,   BIT0, 1); /* SI: input mode */
  #endif /* SPID_CHANNEL_1_SI_EXT_DRIVE */
  #endif /* SPID_CHANNEL_1_TRANSMIT_ONLY */
  TARG_WriteBit(PM9,   BIT1, 0); /* SO: output mode */
  TARG_WriteBit(PFC9,  BIT1, 1); /* output alternate */
  #if (SPID_CHANNEL_1_CLOCK_SELECTION == SPID_SLAVE_MODE)
  TARG_WriteBit(PM9,   BIT2, 1); /* CLK: input mode */
  #else
  TARG_WriteBit(PM9,   BIT2, 0); /* CLK: output mode */
  TARG_WriteBit(PFC9,  BIT2, 1); /* clock out selected */
  #endif /* (SPID_CHANNEL_1_CLOCK_SELECTION == SPID_SLAVE_MODE) */
  #else
  #if defined(__NEC_V850_DG3__)
  TARG_WriteBit(PFSR0, BIT1, 0); /* use port group 4 */
  #endif /* !defined(__NEC_V850_DG3__) */
  #ifndef SPID_CHANNEL_1_TRANSMIT_ONLY
  #ifndef SPID_CHANNEL_1_SI_EXT_DRIVE
  TARG_WriteBit(PMC4,  BIT3, 1); /* SI: Alternate mode */
  #endif /* SPID_CHANNEL_1_SI_EXT_DRIVE */
  #endif /* SPID_CHANNEL_1_TRANSMIT_ONLY */
  TARG_WriteBit(PMC4,  BIT4, 1); /* SO: Alternate mode */
  TARG_WriteBit(PMC4,  BIT5, 1); /* CLK: Alternate mode */
  #ifndef SPID_CHANNEL_1_TRANSMIT_ONLY
  #ifndef SPID_CHANNEL_1_SI_EXT_DRIVE
  TARG_WriteBit(PM4,   BIT3, 1); /* SI: input mode */
  #endif /* SPID_CHANNEL_1_SI_EXT_DRIVE */
  #endif /* SPID_CHANNEL_1_TRANSMIT_ONLY */
  TARG_WriteBit(PM4,   BIT4, 0); /* SO: output mode */
  #if (SPID_CHANNEL_1_CLOCK_SELECTION == SPID_SLAVE_MODE)
  TARG_WriteBit(PM4,   BIT5, 1); /* CLK: input mode */
  #else
  TARG_WriteBit(PM4,   BIT5, 0); /* CLK: output mode */
  #endif /* (SPID_CHANNEL_1_CLOCK_SELECTION == SPID_SLAVE_MODE) */
  #endif /* defined(Spid_Channel1_Use_PortGroup_9) */
  #endif /* defined(__NEC_V850_Dx3__) */

  #if defined(__NEC_V850_Dx3__)
  #if (SPID_CHANNEL_1_CLOCK_SELECTION == SPID_BAUD_RATE_GENERATOR)
  /* Configure the baud rate generator if used by channel 1 */
  TARG_WriteByte(PRSCM1, SPID_CHANNEL_1_BRG_CONFIGURATION);
  TARG_WriteByte(PRSM1,  CSI_MSK_BGCE0 );
  #endif /* SPID_CHANNEL_1_CLOCK_SELECTION */
  #endif /* __NEC_V850_Dx3__ */

  #ifdef __REL_V850_Dx4__
  /* Set the SSI, RY, SCK, SO and SI pins as alternate port mode */
  #if defined(Spid_Channel1_Use_PortGroup_0)
  TARG_SetBitsInShort(PMC0,    Spid_Msk_Bit0 + Spid_Msk_Bit1 + \
                               Spid_Msk_Bit2 + Spid_Msk_Bit3);
  TARG_ClearBitsInShort(PFCE0, Spid_Msk_Bit0 + Spid_Msk_Bit1 + \
                               Spid_Msk_Bit2 + Spid_Msk_Bit3);
  TARG_SetBitsInShort(PFC0,    Spid_Msk_Bit0 + Spid_Msk_Bit1 + \
                               Spid_Msk_Bit2 + Spid_Msk_Bit3);

  /* SDI & RDY are controlled by PM */
  TARG_SetBitsInShort(PM0, Spid_Msk_Bit0 + Spid_Msk_Bit2);

  /* SDO & SCL are controlled by CSI module */
  TARG_SetBitsInShort(PIPC0, Spid_Msk_Bit1 + Spid_Msk_Bit3);
  #endif /* defined(Spid_Channel1_Use_PortGroup_0) */

  #if defined(Spid_Channel1_Use_PortGroup_4)
  TARG_SetBitsInShort(PMC4,    Spid_Msk_Bit6 + Spid_Msk_Bit7 + \
                               Spid_Msk_Bit8 + Spid_Msk_Bit10);
  TARG_ClearBitsInShort(PFCE4, Spid_Msk_Bit6 + Spid_Msk_Bit7 + \
                               Spid_Msk_Bit8 + Spid_Msk_Bit10);
  TARG_SetBitsInShort(PFC4,    Spid_Msk_Bit6 + Spid_Msk_Bit7 + \
                               Spid_Msk_Bit8 + Spid_Msk_Bit10);

  /* SDI & RDY are controlled by PM */
  TARG_SetBitsInShort(PM4, Spid_Msk_Bit10 + Spid_Msk_Bit6);

  /* SDO & SCL are controlled by CSI module */
  TARG_SetBitsInShort(PIPC4, Spid_Msk_Bit7 + Spid_Msk_Bit8);
  #endif /* defined(Spid_Channel1_Use_PortGroup_4) */

  TARG_SetBits(FCLA24CTL4, Spid_Msk_Bit7); /* bypass SCL input  */
  TARG_SetBits(FCLA24CTL5, Spid_Msk_Bit7); /* bypass RDY input  */
  TARG_SetBits(FCLA24CTL6, Spid_Msk_Bit7); /* bypass SDI input  */
  TARG_SetBits(FCLA24CTL7, Spid_Msk_Bit7); /* bypass SSI input  */
  #endif /* __REL_V850_Dx4__ */

  /* Set selected clock speed, phase and edge in CTL1           */
  /* Select transfer length in CTL2                             */
  /* Set selected mode (single, continuous, ... ) in CTL0       */
  /* Start channel                                              */
  Spid_SetCTLregister(1);
  #endif /* SPID_CHANNEL_1_ACTIVE */


  /* SPI CHANNEL 2 ___Fx3, DJ3_HE, DL3 & Dx4 ______________________ */
  #ifdef SPID_CHANNEL_2_ACTIVE

  /* ______________________________________________________________ */
  /* Set the SCK, SO and SI pins as alternate port mode */
  #ifdef __NEC_V850_Fx3__
  TARG_ClearBits(PFCE9H, Spid_Msk_Bit2 + Spid_Msk_Bit3 + Spid_Msk_Bit4);
  TARG_SetBits  (PFC9H,  Spid_Msk_Bit2 + Spid_Msk_Bit3 + Spid_Msk_Bit4);
  TARG_SetBits  (PMC9H,  Spid_Msk_Bit2 + Spid_Msk_Bit3 + Spid_Msk_Bit4);
  #endif /* __NEC_V850_Fx3__ */

  #if defined(__NEC_V850_DJ3_HE__) || \
      defined(__NEC_V850_DL3__)
  #ifndef SPID_CHANNEL_2_TRANSMIT_ONLY
  #ifndef SPID_CHANNEL_2_SI_EXT_DRIVE
  TARG_WriteBit(PMC8,  BIT0, 1); /* SI: Alternate mode */
  #endif /* SPID_CHANNEL_2_SI_EXT_DRIVE */
  #endif /* SPID_CHANNEL_2_TRANSMIT_ONLY */
  TARG_WriteBit(PMC8,  BIT1, 1); /* SO: Alternate mode */
  TARG_WriteBit(PMC8,  BIT2, 1); /* CLK: Alternate mode */
  #ifndef SPID_CHANNEL_2_TRANSMIT_ONLY
  #ifndef SPID_CHANNEL_2_SI_EXT_DRIVE
  TARG_WriteBit(PM8,   BIT0, 1); /* SI: input mode */
  #endif /* SPID_CHANNEL_2_SI_EXT_DRIVE */
  #endif /* SPID_CHANNEL_2_TRANSMIT_ONLY */
  TARG_WriteBit(PM8,   BIT1, 0); /* SO: output mode */
  #if (SPID_CHANNEL_2_CLOCK_SELECTION == SPID_SLAVE_MODE)
  TARG_WriteBit(PM8,   BIT2, 1); /* CLK: input mode */
  #else
  TARG_WriteBit(PM8,   BIT2, 0); /* CLK: output mode */
  #endif /* (SPID_CHANNEL_2_CLOCK_SELECTION == SPID_SLAVE_MODE) */
  #endif /* defined(__NEC_V850_DJ3_HE__) || \
            defined(__NEC_V850_DL3__) */

  #if defined(__NEC_V850_Dx3__)
  #if (SPID_CHANNEL_2_CLOCK_SELECTION == SPID_BAUD_RATE_GENERATOR)
  /* Configure the baud rate generator if used by channel 2 */
  TARG_WriteByte(PRSCM2, SPID_CHANNEL_2_BRG_CONFIGURATION);
  TARG_WriteByte(PRSM2,  CSI_MSK_BGCE0 );
  #endif /* SPID_CHANNEL_2_CLOCK_SELECTION */
  #endif /* __NEC_V850_Dx3__ */

  #ifdef __REL_V850_Dx4__
  /* Set the SSI, RY, SCK, SO and SI pins as alternate port mode */
  #if defined(Spid_Channel2_Use_PortGroup_3)
  #ifdef SPID_CHANNEL_2_HANDSHAKE_ENABLE
  TARG_SetBitsInShort(PMC3,  Spid_Msk_Bit0 + Spid_Msk_Bit1 + \
                             Spid_Msk_Bit2 + Spid_Msk_Bit3);
  TARG_SetBitsInShort(PFCE3, Spid_Msk_Bit0 + Spid_Msk_Bit1 + \
                             Spid_Msk_Bit2 + Spid_Msk_Bit3);
  TARG_SetBitsInShort(PFC3,  Spid_Msk_Bit0 + Spid_Msk_Bit1 + \
                             Spid_Msk_Bit2 + Spid_Msk_Bit3);

  /* SDI & RDY are controlled by PM */
  TARG_SetBitsInShort(PM3, Spid_Msk_Bit0 + Spid_Msk_Bit3);
  #else
  TARG_SetBitsInShort(PMC3,  Spid_Msk_Bit0 + Spid_Msk_Bit1 + Spid_Msk_Bit2);
  TARG_SetBitsInShort(PFCE3, Spid_Msk_Bit0 + Spid_Msk_Bit1 + Spid_Msk_Bit2);
  TARG_SetBitsInShort(PFC3,  Spid_Msk_Bit0 + Spid_Msk_Bit1 + Spid_Msk_Bit2);

  /* SDI & RDY are controlled by PM */
  TARG_SetBitsInShort(PM3, Spid_Msk_Bit0);
  #endif /* SPID_CHANNEL_2_HANDSHAKE_ENABLE */

  /* SDO & SCL are controlled by CSI module */
  TARG_SetBitsInShort(PIPC3, Spid_Msk_Bit1 + Spid_Msk_Bit2);
  #endif /* defined(Spid_Channel2_Use_PortGroup_3) */

  #if defined(Spid_Channel2_Use_PortGroup_4)
  TARG_SetBitsInShort(PMC4, Spid_Msk_Bit9 + Spid_Msk_Bit10 + Spid_Msk_Bit11);
  TARG_ClearBitsInShort(PFCE4, Spid_Msk_Bit9 + Spid_Msk_Bit10 + Spid_Msk_Bit11);
  TARG_SetBitsInShort(PFC4, Spid_Msk_Bit9 + Spid_Msk_Bit10 + Spid_Msk_Bit11);

  /* SDI is controlled by PM */
  TARG_SetBitsInShort(PM4, Spid_Msk_Bit9);
  /* no RDY */

  /* SDO & SCL are controlled by CSI module */
  TARG_SetBitsInShort(PIPC4, Spid_Msk_Bit10 + Spid_Msk_Bit11);
  /* TARG_ClearBitsInShort(PM4, Spid_Msk_Bit10 + Spid_Msk_Bit11); */
  #endif /* defined(Spid_Channel2_Use_PortGroup_4) */

  TARG_SetBits(FCLA25CTL0, Spid_Msk_Bit7); /* bypass SCL input  */
  TARG_SetBits(FCLA25CTL1, Spid_Msk_Bit7); /* bypass RDY input  */
  TARG_SetBits(FCLA25CTL2, Spid_Msk_Bit7); /* bypass SDI input  */
  #endif /* __REL_V850_Dx4__ */

  /* Set selected clock speed, phase and edge in CTL1           */
  /* Select transfer length in CTL2                             */
  /* Set selected mode (single, continuous, ... ) in CTL0       */
  /* Start channel                                              */
  Spid_SetCTLregister(2);
  #endif /* SPID_CHANNEL_2_ACTIVE */

  /* SPI CHANNEL 3___Fx3 ONLY______________________________________ */
  /* ______________________________________________________________ */
  #ifdef SPID_CHANNEL_3_ACTIVE
  /* Set the SCK, SO and SI pins as alternate port mode */
  #ifdef __NEC_V850_Fx3__
  TARG_ClearBits(PFC6, Spid_Msk_Bit2 + Spid_Msk_Bit3 + Spid_Msk_Bit4);
  TARG_SetBits(PFCE6L, Spid_Msk_Bit2 + Spid_Msk_Bit3 + Spid_Msk_Bit4);
  TARG_SetBits(PMC6, Spid_Msk_Bit2 + Spid_Msk_Bit3 + Spid_Msk_Bit4);
  #endif /* __NEC_V850_Fx3__ */

  /* Set selected clock speed, phase and edge in CTL1           */
  /* Select transfer length in CTL2                             */
  /* Set selected mode (single, continuous, ... ) in CTL0       */
  /* Start channel                                              */
  Spid_SetCTLregister(3);
  #endif /* SPID_CHANNEL_3_ACTIVE */
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
  /* Stop active channels by clearing POWER bit */
  #ifdef SPID_CHANNEL_0_ACTIVE
  #if (defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__))
  TARG_WriteBit(CB0CTL0, CSI_BIT_CB0PWR, 0);
  #if defined(__NEC_V850_Dx3__)
  #if (SPID_CHANNEL_0_CLOCK_SELECTION == SPID_BAUD_RATE_GENERATOR)
  /* Configure the baud rate generator if used by channel 0 */
  TARG_WriteByte( PRSM0, 0);
  #endif /* SPID_CHANNEL_0_CLOCK_SELECTION */
  #endif /* __NEC_V850_Dx3__ */
  #endif /* defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */
  #ifdef __REL_V850_Dx4__
  TARG_WriteBit(CSIG0CTL0, CSI_BIT_CSIGnPWR, 0);
  #endif /* __REL_V850_Dx4__ */
  #endif /* SPID_CHANNEL_0_ACTIVE */

  #ifdef SPID_CHANNEL_1_ACTIVE
  #if (defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__))
  TARG_WriteBit(CB1CTL0, CSI_BIT_CB1PWR, 0);
  #if defined(__NEC_V850_Dx3__)
  #if (SPID_CHANNEL_1_CLOCK_SELECTION == SPID_BAUD_RATE_GENERATOR)
  /* Configure the baud rate generator if used by channel 0 */
  TARG_WriteByte( PRSM1, 0);
  #endif /* SPID_CHANNEL_1_CLOCK_SELECTION */
  #endif /* __NEC_V850_Dx3__ */
  #endif /* defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */
  #ifdef __REL_V850_Dx4__
  TARG_WriteBit(CSIG1CTL0, CSI_BIT_CSIGnPWR, 0);
  #endif /* __REL_V850_Dx4__ */
  #endif /* SPID_CHANNEL_1_ACTIVE */

  #ifdef SPID_CHANNEL_2_ACTIVE
  #if (defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__))
  TARG_WriteBit(CB2CTL0, CSI_BIT_CB2PWR, 0);
  #if defined(__NEC_V850_Dx3__)
  #if (SPID_CHANNEL_2_CLOCK_SELECTION == SPID_BAUD_RATE_GENERATOR)
  /* Configure the baud rate generator if used by channel 0 */
  TARG_WriteByte( PRSM2, 0);
  #endif /* SPID_CHANNEL_2_CLOCK_SELECTION */
  #endif /* __NEC_V850_Dx3__ */
  #endif /* defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */
  #ifdef __REL_V850_Dx4__
  TARG_WriteBit(CSIG2CTL0, CSI_BIT_CSIGnPWR, 0);
  #endif /* __REL_V850_Dx4__ */
  #endif /* SPID_CHANNEL_2_ACTIVE */

  /* only 3 channels on __NEC_V850_DL3__ product */
  #ifdef SPID_CHANNEL_3_ACTIVE
  TARG_WriteBit(CB3CTL0, CSI_BIT_CB3PWR, 0);
  #endif /* SPID_CHANNEL_3_ACTIVE */
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
  SPID_Init();
}

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
#ifdef SPID_CHANNEL_0_ACTIVE
#ifdef SPID_CHANNEL_0_SI_EXT_DRIVE
void Spid_EnableSerialInput0(void)
{
  #if defined(__NEC_V850_Dx3__)
  #if defined(Spid_Channel0_Use_PortGroup_10) || \
      defined(__NEC_V850_DG3__)
  TARG_WriteBit(PMC10, BIT5, 1); /* SI: Alternate mode */
  TARG_WriteBit(PM10,  BIT5, 1); /* SI: Input mode */
  #else
  TARG_WriteBit(PMC4,  BIT0, 1); /* SI: Alternate mode */
  TARG_WriteBit(PM4,   BIT0, 1); /* SI: Input mode */
  #endif /* defined(Spid_Channel0_Use_PortGroup_10) || \
            defined(__NEC_V850_DG3__) */
  #endif /* defined(__NEC_V850_Dx3__) */

  #ifdef __REL_V850_Dx4__
  #if defined(Spid_Channel0_Use_PortGroup_0)
  TARG_SetBitsInShort(PMC0, Spid_Msk_Bit13); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM0,  Spid_Msk_Bit13); /* SI: Input mode */
  #else
  TARG_SetBitsInShort(PMC4, Spid_Msk_Bit13); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM4,  Spid_Msk_Bit13); /* SI: Input mode */
  #endif /* defined(Spid_Channel0_Use_PortGroup_0) */
  #endif /* __REL_V850_Dx4__ */
}
#endif /* SPID_CHANNEL_0_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_0_ACTIVE */

#ifdef SPID_CHANNEL_1_ACTIVE
#ifdef SPID_CHANNEL_1_SI_EXT_DRIVE
void Spid_EnableSerialInput1(void)
{
  #if defined(__NEC_V850_Dx3__)
  #if defined(Spid_Channel1_Use_PortGroup_9)
  TARG_WriteBit(PMC9,  BIT0, 1); /* SI: Alternate mode */
  TARG_WriteBit(PM9,   BIT0, 1); /* SI: Input mode */
  #else
  TARG_WriteBit(PMC4,  BIT3, 1); /* SI: Alternate mode */
  TARG_WriteBit(PM4,   BIT3, 1); /* SI: Input mode */
  #endif /* defined(Spid_Channel1_Use_PortGroup_9) */
  #endif /* defined(__NEC_V850_Dx3__) */

  #ifdef __REL_V850_Dx4__
  #if defined(Spid_Channel1_Use_PortGroup_0)
  TARG_SetBitsInShort(PMC0, Spid_Msk_Bit2); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM0,  Spid_Msk_Bit2); /* SI: Input mode */
  #else
  TARG_SetBitsInShort(PMC4, Spid_Msk_Bit6); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM4,  Spid_Msk_Bit6); /* SI: Input mode */
  #endif /* defined(Spid_Channel1_Use_PortGroup_0) */
  #endif /* __REL_V850_Dx4__ */
}
#endif /* SPID_CHANNEL_1_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_1_ACTIVE */

#ifdef SPID_CHANNEL_2_ACTIVE
#ifdef SPID_CHANNEL_2_SI_EXT_DRIVE
void Spid_EnableSerialInput2(void)
{
  #if defined(__NEC_V850_DJ3_HE__) || \
      defined(__NEC_V850_DL3__)
  TARG_WriteBit(PMC8,  BIT0, 1); /* SI: Alternate mode */
  TARG_WriteBit(PM8,   BIT0, 1); /* SI: Input mode */
  #endif /* defined(__NEC_V850_DJ3_HE__) || \
            defined(__NEC_V850_DL3__) */

  #ifdef __REL_V850_Dx4__
  #if defined(Spid_Channel2_Use_PortGroup_3)
  TARG_SetBitsInShort(PMC3, Spid_Msk_Bit0); /* SI: Alternate mode */
  TARG_SetBitsInShort(PM3,  Spid_Msk_Bit0); /* SI: Input mode */
  #endif /* defined(Spid_Channel2_Use_PortGroup_3) */
  #endif /* __REL_V850_Dx4__ */
}
#endif /* SPID_CHANNEL_2_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_2_ACTIVE */

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
#ifdef SPID_CHANNEL_0_ACTIVE
#ifdef SPID_CHANNEL_0_SI_EXT_DRIVE
void Spid_DisableSerialInput0(void)
{
  #if defined(__NEC_V850_Dx3__)
  #if defined(Spid_Channel0_Use_PortGroup_10) || \
      defined(__NEC_V850_DG3__)
  TARG_WriteBit(PMC10, BIT5, 0); /* SI: Port mode */
  #else
  TARG_WriteBit(PMC4,  BIT0, 0); /* SI: Port mode */
  #endif /* defined(Spid_Channel0_Use_PortGroup_10) || \
            defined(__NEC_V850_DG3__) */
  #endif /* defined(__NEC_V850_Dx3__) */

  #ifdef __REL_V850_Dx4__
  #if defined(Spid_Channel0_Use_PortGroup_0)
  TARG_ClearBitsInShort(PMC0, Spid_Msk_Bit13); /* SI: Port mode */
  #else
  TARG_ClearBitsInShort(PMC4, Spid_Msk_Bit13); /* SI: Port mode */
  #endif /* defined(Spid_Channel0_Use_PortGroup_0) */
  #endif /* __REL_V850_Dx4__ */
}
#endif /* SPID_CHANNEL_0_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_0_ACTIVE */

#ifdef SPID_CHANNEL_1_ACTIVE
#ifdef SPID_CHANNEL_1_SI_EXT_DRIVE
void Spid_DisableSerialInput1(void)
{
  #if defined(__NEC_V850_Dx3__)
  #if defined(Spid_Channel1_Use_PortGroup_9)
  TARG_WriteBit(PMC9,  BIT0, 0); /* SI: Port mode */
  #else
  TARG_WriteBit(PMC4,  BIT3, 0); /* SI: Port mode */
  #endif /* defined(Spid_Channel1_Use_PortGroup_9) */
  #endif /* defined(__NEC_V850_Dx3__) */

  #ifdef __REL_V850_Dx4__
  #if defined(Spid_Channel0_Use_PortGroup_0)
  TARG_ClearBitsInShort(PMC0, Spid_Msk_Bit2); /* SI: Port mode */
  #else
  TARG_ClearBitsInShort(PMC4, Spid_Msk_Bit6); /* SI: Port mode */
  #endif /* defined(Spid_Channel0_Use_PortGroup_0) */
  #endif /* __REL_V850_Dx4__ */
}
#endif /* SPID_CHANNEL_1_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_1_ACTIVE */

#ifdef SPID_CHANNEL_2_ACTIVE
#ifdef SPID_CHANNEL_2_SI_EXT_DRIVE
void Spid_DisableSerialInput2(void)
{
  #if defined(__NEC_V850_DJ3_HE__) || \
      defined(__NEC_V850_DL3__)
  TARG_WriteBit(PMC8,  BIT0, 0); /* SI: Port mode */
  #endif /* defined(__NEC_V850_DJ3_HE__) || \
            defined(__NEC_V850_DL3__) */

  #ifdef __REL_V850_Dx4__
  #if defined(Spid_Channel2_Use_PortGroup_3)
  TARG_ClearBitsInShort(PMC3, Spid_Msk_Bit0); /* SI: Port mode */
  #endif /* defined(Spid_Channel2_Use_PortGroup_3) */
  #endif /* __REL_V850_Dx4__ */
}
#endif /* SPID_CHANNEL_2_SI_EXT_DRIVE */
#endif /* SPID_CHANNEL_2_ACTIVE */


/*_____ L O C A L - F U N C T I O N S ________________________________________*/

#ifdef SPID_CHANNEL_0_ACTIVE
ubyte Spid_ReceiveByte0(void)
{
  #if (defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__))
  TARG_WriteBit(CB0CTL0, CSI_BIT_CB0SCE, 0);
  #endif /* defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */

  return(SPID_RX0);
}
#endif /* SPID_CHANNEL_0_ACTIVE */

#ifdef SPID_CHANNEL_1_ACTIVE
ubyte Spid_ReceiveByte1(void)
{
  #if (defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__))
  TARG_WriteBit(CB1CTL0, CSI_BIT_CB1SCE, 0);
  #endif /* defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */

  return(SPID_RX1);
}
#endif /* SPID_CHANNEL_1_ACTIVE */

#ifdef SPID_CHANNEL_2_ACTIVE
ubyte Spid_ReceiveByte2(void)
{
  #if (defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__))
  TARG_WriteBit(CB2CTL0, CSI_BIT_CB2SCE, 0);
  #endif /* defined(__NEC_V850_Dx3__) || defined(__NEC_V850_Fx3__) */

  return(SPID_RX2);
}
#endif /* SPID_CHANNEL_2_ACTIVE */

#ifdef SPID_CHANNEL_3_ACTIVE
ubyte Spid_ReceiveByte3(void)
{
  TARG_WriteBit(CB3CTL0, CSI_BIT_CB3SCE, 0);

  return(SPID_RX3);
}
#endif /* SPID_CHANNEL_3_ACTIVE */


/******************************************************************************/
/* NEC V850 CODE                                                              */
/******************************************************************************/
#endif /* __NEC_V850__ */


#ifdef __TX49__

/*_____ L O C A L - D E F I N E S ____________________________________________*/

/* Values to set into Control register 2 SPICR2 */
#ifdef SPID_BIDIR_MODE_USED
#define SPID_SPICR2_VALUE  (SPI_MSK_SPISWAI + SPI_MSK_SPC0)
#else
#define SPID_SPICR2_VALUE  (SPI_MSK_SPISWAI)
#endif /* SPID_BIDIR_MODE_USED */


/*_____ L O C A L - F U N C T I O N S - P R O T O T Y P E S __________________*/


/* _____ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

#ifdef SPID_UserReceiveInterrupt_ch0
extern void SPID_UserReceiveInterrupt_ch0(void);
#endif /* SPID_UserReceiveInterrupt_ch0 */
#ifdef SPID_UserReceiveInterrupt_ch1
extern void SPID_UserReceiveInterrupt_ch1(void);
#endif /* SPID_UserReceiveInterrupt_ch1 */


/*_____ G L O B A L - F U N C T I O N S ______________________________________*/

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
#ifdef SPID_ACTIVE_CHANNEL_0
  /* gates the clock of the spi */
  TARG_WriteBit(CCRCRCR, SYS_BIT_SEI0G, 1);

  /* Active configuration mode */
  TARG_WriteLongLong(SEMCR_0, SPI_MSK_CONFIG_MODE);

  #ifndef SPID_SLAVE_MODE_USED_CHANNEL_0
  /* Select clock speed */
  TARG_WriteLongLong(SECR1_0, (ulonglong)(SPID_CLOCK_VALUE_CHANNEL_0 << SPI_SHIFT_SER_FIELD));
  /* enable Master mode */
  TARG_WriteBit(SECR0_0, SPI_BIT_MSTR, 1);
  #else
  TARG_WriteBit(SECR0_0, SPI_BIT_MSTR, 0);
  #endif

  /* Select bit order */
  TARG_WriteBit(SECR0_0, SPI_BIT_SBOS, SPI_BIT_ORDER_CHANNEL_0);
  /* Select sampling clock edge */
  TARG_WriteBit(SECR0_0, SPI_BIT_SPHA, SPID_DATA_SAMPLING_CLOCK_EDGE_CHANNEL_0);
  /* Select active clock level */
  TARG_WriteBit(SECR0_0, SPI_BIT_SPOL, SPID_CLOCK_IDLE_STATE_CHANNEL_0);
  /* Enable IDLE interrupt flag */
  TARG_WriteBit(SECR0_0, SPI_BIT_SILIE, 1);

  /* determine length of data to transmit */
  TARG_SetBits(SECR1_0, (ulonglong)(SPI_DATA_LENGTH_CHANNEL_0));
  /* Enable active mode */
  TARG_WriteLongLong(SEMCR_0, SPI_MSK_ACTIVE_MODE);

  /* Configure parallel port */
  /* MISO signal */
  RGTX49_SetPinFunction(GPIO_PIN_ESEI0MISO, 2);
  /* MOSI signal */
  RGTX49_SetPinFunction(GPIO_PIN_ESEI0MOSI, 2);
  /* SCLK signal */
  RGTX49_SetPinFunction(GPIO_PIN_ESEI0SCLK, 2);
  /* SSO 0 signal */
  RGTX49_SetPinFunction(GPIO_PIN_ESEI0SSO0, 2);
  /* SSI signal */
  RGTX49_SetPinFunction(GPIO_PIN_ESEI0SSI, 2);

  /* interrupt */
  #ifdef SPID_UserReceiveInterrupt_ch0
  TARG_SetBits(IMR45, INT_MSK_EIM_HIGH_LEVEL);
  #endif /* SPID_UserReceiveInterrupt_ch0 */

  #ifndef SPID_AUTO_START_USED_CHANNEL_0
  /* Stop channel */
  TARG_WriteBit(SEMCR_0, SPI_BIT_SESTP, 1);
  #endif

#endif /* SPID_ACTIVE_CHANNEL_0 */

#ifdef SPID_ACTIVE_CHANNEL_1
  /* gates the clock of the spi */
  TARG_WriteBit(CCRCRCR, SYS_BIT_SEI1G, 1);

  /* Active configuration mode */
  TARG_WriteLongLong(SEMCR_1, SPI_MSK_CONFIG_MODE);

  #ifndef SPID_SLAVE_MODE_USED_CHANNEL_1
  /* Select clock speed */
  TARG_WriteLongLong(SECR1_1, (ulonglong)(SPID_CLOCK_VALUE_CHANNEL_1 << SPI_SHIFT_SER_FIELD));
  /* enable Master mode */
  TARG_WriteBit(SECR0_1, SPI_BIT_MSTR, 1);
  #else
  TARG_WriteBit(SECR0_1, SPI_BIT_MSTR, 0);
  #endif

  /* Select bit order */
  TARG_WriteBit(SECR0_1, SPI_BIT_SBOS, SPI_BIT_ORDER_CHANNEL_1);
  /* Select sampling clock edge */
  TARG_WriteBit(SECR0_1, SPI_BIT_SPHA, SPID_DATA_SAMPLING_CLOCK_EDGE_CHANNEL_1);
  /* Select active clock level */
  TARG_WriteBit(SECR0_1, SPI_BIT_SPOL, SPID_CLOCK_IDLE_STATE_CHANNEL_1);
  /* Enable IDLE interrupt flag */
  TARG_WriteBit(SECR0_1, SPI_BIT_SILIE, 1);

  /* determine length of data to transmit */
  TARG_SetBits(SECR1_1, (ulonglong)(SPI_DATA_LENGTH_CHANNEL_1));
  /* Enable active mode */
  TARG_WriteLongLong(SEMCR_1, SPI_MSK_ACTIVE_MODE);

  /* Configure parallel port */
  /* MOSI signal */
  /* - MOSI :                                                                   */
  /*          SPI_MOSI_CH1_PIN_PNLGPP2_USED to select PNLGPP2 pin               */
  /*          SPI_MOSI_CH1_PIN_EBIF_AD10_USED to select EBIF_AD10 pin           */
  /*          SPI_MOSI_CH1_PIN_ESEI1MOSI_L_USED to select ESEI1MOSI_L pin       */
  #ifdef SPI_MOSI_CH1_PIN_PNLGPP2_USED
  RGTX49_SetPinFunction(GPIO_PIN_PNLGPP2, 1);
  #endif /* SPI_MOSI_CH1_PIN_PNLGPP2_USED */
  #ifdef SPI_MOSI_CH1_PIN_EBIF_AD10_USED
  RGTX49_SetPinFunction(GPIO_PIN_EBIF_AD10, 1);
  #endif /* SPI_MOSI_CH1_PIN_EBIF_AD10_USED */
  #ifdef SPI_MOSI_CH1_PIN_ESEI1MOSI_L_USED
  RGTX49_SetPinFunction(GPIO_PIN_ESEI1MOSI_L, 2);
  #endif /* SPI_MOSI_CH1_PIN_ESEI1MOSI_L_USED */

  /* MISO signal */
  /* - MISO :                                                                   */
  /*          SPI_MISO_CH1_PIN_PNLGPP3_USED to select PNLGPP3 pin               */
  /*          SPI_MISO_CH1_PIN_EBIF_AD11_USED to select EBIF_AD11 pin           */
  /*          SPI_MISO_CH1_PIN_ESEI1MISO_L_USED to select ESEI1MISO_L pin       */
  #ifdef SPI_MISO_CH1_PIN_PNLGPP3_USED
  RGTX49_SetPinFunction(GPIO_PIN_PNLGPP3, 1);
  #endif /* SPI_MISO_CH1_PIN_PNLGPP3_USED */
  #ifdef SPI_MISO_CH1_PIN_EBIF_AD11_USED
  RGTX49_SetPinFunction(GPIO_PIN_EBIF_AD11, 1);
  #endif /* SPI_MISO_CH1_PIN_EBIF_AD11_USED */
  #ifdef SPI_MISO_CH1_PIN_ESEI1MISO_L_USED
  RGTX49_SetPinFunction(GPIO_PIN_ESEI1MISO_L, 4);
  #endif /* SPI_MISO_CH1_PIN_ESEI1MISO_L_USED */

  /* SCLK signal */
  /* - SCLK :                                                                   */
  /*          SPI_SCLK_CH1_PIN_PNLGPP1_USED to select PNLGPP1 pin               */
  /*          SPI_SCLK_CH1_PIN_EBIF_AD12_USED to select EBIF_AD11 pin           */
  /*          SPI_SCLK_CH1_PIN_ESEI1SCLK_L_USED to select ESEI1SCLK_L pin       */
  #ifdef SPI_SCLK_CH1_PIN_PNLGPP1_USED
  RGTX49_SetPinFunction(GPIO_PIN_PNLGPP1, 1);
  #endif /* SPI_SCLK_CH1_PIN_PNLGPP1_USED */
  #ifdef SPI_SCLK_CH1_PIN_EBIF_AD12_USED
  RGTX49_SetPinFunction(GPIO_PIN_EBIF_AD12, 1);
  #endif /* SPI_SCLK_CH1_PIN_EBIF_AD12_USED */
  #ifdef SPI_SCLK_CH1_PIN_ESEI1SCLK_L_USED
  RGTX49_SetPinFunction(GPIO_PIN_ESEI1SCLK_L, 4);
  #endif /* SPI_SCLK_CH1_PIN_ESEI1SCLK_L_USED */

  /* SSO 0 signal */
  /* - SS0 :                                                                    */
  /*          SPI_SS0_CH1_PIN_PNLGPP4_USED to select PNLGPP4 pin                */
  /*          SPI_SS0_CH1_PIN_EBIF_AD9_USED to select EBIF_AD9 pin              */
  /*          SPI_SS0_CH1_PIN_ESEI1SSO0_L_USED to select ESEI1SSO0_L pin        */
  #ifdef SPI_SS0_CH1_PIN_PNLGPP4_USED
  RGTX49_SetPinFunction(GPIO_PIN_PNLGPP4, 1);
  #endif /* SPI_SS0_CH1_PIN_PNLGPP4_USED */
  #ifdef SPI_SS0_CH1_PIN_EBIF_AD9_USED
  RGTX49_SetPinFunction(GPIO_PIN_EBIF_AD9, 1);
  #endif /* SPI_SS0_CH1_PIN_EBIF_AD9_USED */
  #ifdef SPI_SS0_CH1_PIN_ESEI1SSO0_L_USED
  RGTX49_SetPinFunction(GPIO_PIN_ESEI1SSO0_L, 2);
  #endif /* SPI_SS0_CH1_PIN_ESEI1SSO0_L_USED */

  /* SSI signal */
  /* - SSI :                                                                    */
  /*          SPI_SSI_CH1_PIN_PNLSYNCIN_USED to select PNLSYNCIN pin            */
  /*          SPI_SSI_CH1_PIN_EBIF_AD8_USED to select EBIF_AD8 pin              */
  /*          SPI_SSI_CH1_PIN_ESEI0SSO0_USED to select ESEI0SSO0 pin            */
  #ifdef SPI_SSI_CH1_PIN_PNLSYNCIN_USED
  RGTX49_SetPinFunction(GPIO_PIN_PNLSYNCIN, 1);
  #endif /* SPI_SSI_CH1_PIN_PNLSYNCIN_USED */
  #ifdef SPI_SSI_CH1_PIN_EBIF_AD8_USED
  RGTX49_SetPinFunction(GPIO_PIN_EBIF_AD8, 2);
  #endif /* SPI_SSI_CH1_PIN_EBIF_AD8_USED */
  #ifdef SPI_SSI_CH1_PIN_ESEI0SSO0_USED
  RGTX49_SetPinFunction(GPIO_PIN_ESEI0SSO0, 1);
  #endif /* SPI_SSI_CH1_PIN_ESEI0SSO0_USED */

  /* interrupt */
  #ifdef SPID_UserReceiveInterrupt_ch1
  TARG_SetBits(IMR48, INT_MSK_EIM_HIGH_LEVEL);
  #endif /* SPID_UserReceiveInterrupt_ch1 */

  #ifndef SPID_AUTO_START_USED_CHANNEL_1
  /* Stop channel */
  TARG_WriteBit(SEMCR_1, SPI_BIT_SESTP, 1);
  #endif

#endif /* SPID_ACTIVE_CHANNEL_1 */
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
#ifdef SPID_ACTIVE_CHANNEL_0
  /* Stop channel */
  TARG_WriteBit(SEMCR_0, SPI_BIT_SESTP, 1);
#endif /* SPID_ACTIVE_CHANNEL_0 */

#ifdef SPID_ACTIVE_CHANNEL_1
  /* Stop channel */
  TARG_WriteBit(SEMCR_1, SPI_BIT_SESTP, 1);
#endif /* SPID_ACTIVE_CHANNEL_1 */
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
  /* Init and Start channel */
  SPID_Init();
}

/******************************************************************************/
/* Name: SPID_ReceiveInterrupt_it                                             */
/* Role: Service routine of interrupt generated by SPI                        */
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

  SPID_UserReceiveInterrupt_ch0();

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

  SPID_UserReceiveInterrupt_ch1();

  #ifdef __TASK_DURATION_MEASUREMENT_WITH_TIMER__
  RTOS_DisableAllInterrupts();
  RTOS_TaskMeasurementLeaveIt(OldMeasuredTask);
  RTOS_EnableAllInterrupts();
  #endif /* __TASK_DURATION_MEASUREMENT_WITH_TIMER__ */
}
#endif /* SPID_UserReceiveInterrupt_ch1 */


/*_____ L O C A L - F U N C T I O N S ________________________________________*/


#endif /* __TX49__ */


#ifdef __FSL_IMX53x__

/*_____ L O C A L - D E F I N E S ____________________________________________*/

#define SPI_LAST_CHANNEL_IN_CSPI      3
#define SPI_LAST_CHANNEL_IN_ECSPI_1   7
#define SPI_LAST_CHANNEL_IN_ECSPI_2  11


#define SPI_MODULE_CSPI               0
#define SPI_MODULE_ECSPI1             1
#define SPI_MODULE_ECSPI2             2


/*______ L O C A L - D A T A _________________________________________________*/

ulong Spid_BufferRxData;
ulong Spid_BufferRxDataE1;
ulong Spid_BufferRxDataE2;

/*_____ L O C A L - F U N C T I O N S - P R O T O T Y P E S __________________*/


/* _____ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

#ifdef SPID_UserReceiveInterrupt_ch0
extern void SPID_UserReceiveInterrupt_ch0(void);
#endif /* SPID_UserReceiveInterrupt_ch0 */
#ifdef SPID_UserReceiveInterrupt_ch1
extern void SPID_UserReceiveInterrupt_ch1(void);
#endif /* SPID_UserReceiveInterrupt_ch1 */

/*_____ G L O B A L - F U N C T I O N S ______________________________________*/

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
  ubyte RxData;

  switch(Channel)
  {
#ifdef SPI_CHANNEL_0_USED
    case  0 :
      RxData = Spid_BufferRxData;
      break;
#endif /* SPI_CHANNEL_0_USED */

#ifdef SPI_CHANNEL_1_USED
    case  1 :
      RxData = Spid_BufferRxData;
      break;
#endif /* SPI_CHANNEL_1_USED */

#ifdef SPI_CHANNEL_2_USED
    case  2 :
      RxData = Spid_BufferRxData;
      break;
#endif /* SPI_CHANNEL_2_USED */

#ifdef SPI_CHANNEL_3_USED
    case  3 :
      RxData = Spid_BufferRxData;
      break;
#endif /* SPI_CHANNEL_3_USED */

#ifdef SPI_CHANNEL_4_USED
    case  4 :
      RxData = Spid_BufferRxDataE1;
      break;
#endif /* SPI_CHANNEL_4_USED */

#ifdef SPI_CHANNEL_5_USED
    case  5 :
      RxData = Spid_BufferRxDataE1;
      break;
#endif /* SPI_CHANNEL_5_USED */

#ifdef SPI_CHANNEL_6_USED
    case  6 :
      RxData = Spid_BufferRxDataE1;
      break;
#endif /* SPI_CHANNEL_6_USED */

#ifdef SPI_CHANNEL_7_USED
    case  7 :
      RxData = Spid_BufferRxDataE1;
      break;
#endif /* SPI_CHANNEL_7_USED */

#ifdef SPI_CHANNEL_8_USED
    case  8 :
      RxData = Spid_BufferRxDataE2;
      break;
#endif /* SPI_CHANNEL_8_USED */

#ifdef SPI_CHANNEL_9_USED
    case  9 :
      RxData = Spid_BufferRxDataE2;
      break;
#endif /* SPI_CHANNEL_9_USED */

#ifdef SPI_CHANNEL_10_USED
    case 10 :
      RxData = Spid_BufferRxDataE2;
      break;
#endif /* SPI_CHANNEL_10_USED */

#ifdef SPI_CHANNEL_11_USED
    case 11 :
      RxData = Spid_BufferRxDataE2;
      break;
#endif /* SPI_CHANNEL_11_USED */

      default :
      RxData = 0;
      break;
  }

  return(RxData);
}

/******************************************************************************/
/* Name: SPID_TransmitByte                                                    */
/* Role: Provide the mean to start transmit of a byte on selected channel     */
/* Interface: Channel          IN  Communication channel number               */
/*             ByteToTransmit  IN  Byte to transmit on serial communication   */
/* Pre-condition: The transmit data register for the channel must be empty    */
/* Constraints: none                                                          */
/* DO                                                                         */
/*  [ Configure baud rate ]                                                   */
/*  [ Send the data]                                                          */
/* OD                                                                         */
/******************************************************************************/
void SPID_TransmitByte(ubyte Channel, ubyte DataByte)
{
  switch(Channel)
  {
#ifdef SPI_CHANNEL_0_USED
    case  0 :
      TARG_WriteLong(CSPI_CONREG, (TARG_ReadLong(CSPI_CONREG) & ~SPI_DATA_RATE_FMSK) | (SPI_CLOCK_CHANNEL_0));
      TARG_WriteLong(CSPI_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_0_USED */

#ifdef SPI_CHANNEL_1_USED
    case  1 :
      TARG_WriteLong(CSPI_CONREG, (TARG_ReadLong(CSPI_CONREG) & ~SPI_DATA_RATE_FMSK) | (SPI_CLOCK_CHANNEL_1));
      TARG_WriteLong(CSPI_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_1_USED */

#ifdef SPI_CHANNEL_2_USED
    case  2 :
      TARG_WriteLong(CSPI_CONREG, (TARG_ReadLong(CSPI_CONREG) & ~SPI_DATA_RATE_FMSK) | (SPI_CLOCK_CHANNEL_2));
      TARG_WriteLong(CSPI_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_2_USED */

#ifdef SPI_CHANNEL_3_USED
    case  3 :
      TARG_WriteLong(CSPI_CONREG, (TARG_ReadLong(CSPI_CONREG) & ~SPI_DATA_RATE_FMSK) | (SPI_CLOCK_CHANNEL_3));
      TARG_WriteLong(CSPI_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_3_USED */

#ifdef SPI_CHANNEL_4_USED
    case  4 :
      TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_4));
      TARG_WriteLong(ECSPI1_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_4_USED */

#ifdef SPI_CHANNEL_5_USED
    case  5 :
      TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_5));
      TARG_WriteLong(ECSPI1_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_5_USED */

#ifdef SPI_CHANNEL_6_USED
    case  6 :
      TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_6));
      TARG_WriteLong(ECSPI1_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_6_USED */

#ifdef SPI_CHANNEL_7_USED
    case  7 :
      TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_7));
      TARG_WriteLong(ECSPI1_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_7_USED */

#ifdef SPI_CHANNEL_8_USED
    case  8 :
      TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_8));
      TARG_WriteLong(ECSPI2_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_8_USED */

#ifdef SPI_CHANNEL_9_USED
    case  9 :
      TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_9));
      TARG_WriteLong(ECSPI2_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_9_USED */

#ifdef SPI_CHANNEL_10_USED
    case 10 :
      TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_10));
      TARG_WriteLong(ECSPI2_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_10_USED */

#ifdef SPI_CHANNEL_11_USED
    case 11 :
      TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_11));
      TARG_WriteLong(ECSPI2_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_11_USED */





    default :
      break;
  }
}

/******************************************************************************/
/* Name: SPID_NextOperation                                                   */
/* Role: Provide the mean to clear the TC bit and to flush Rx buffer          */
/* Interface: Channel  IN   Communication channel number                      */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour:                                                                 */
/* DO                                                                         */
/*  [ Clear transfer completed flag ]                                         */
/*  [ Store the received data ]                                               */
/* OD                                                                         */
/******************************************************************************/
void SPID_NextOperation(ubyte Channel)
{
  switch(Channel)
  {
#ifdef SPI_CHANNEL_0_USED
    case  0 :
      TARG_WriteBit(CSPI_STATREG, SPI_BIT_TC, 1);
      Spid_BufferRxData = TARG_ReadLong(CSPI_RXDATA);
      break;
#endif /* SPI_CHANNEL_0_USED */

#ifdef SPI_CHANNEL_1_USED
    case  1 :
      TARG_WriteBit(CSPI_STATREG, SPI_BIT_TC, 1);
      Spid_BufferRxData = TARG_ReadLong(CSPI_RXDATA);
      break;
#endif /* SPI_CHANNEL_1_USED */

#ifdef SPI_CHANNEL_2_USED
    case  2 :
      TARG_WriteBit(CSPI_STATREG, SPI_BIT_TC, 1);
      Spid_BufferRxData = TARG_ReadLong(CSPI_RXDATA);
      break;
#endif /* SPI_CHANNEL_2_USED */

#ifdef SPI_CHANNEL_3_USED
    case  3 :
      TARG_WriteBit(CSPI_STATREG, SPI_BIT_TC, 1);
      Spid_BufferRxData = TARG_ReadLong(CSPI_RXDATA);
      break;
#endif /* SPI_CHANNEL_3_USED */

#ifdef SPI_CHANNEL_4_USED
    case  4 :
      TARG_WriteBit(ECSPI1_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE1 = TARG_ReadLong(ECSPI1_RXDATA);
      break;
#endif /* SPI_CHANNEL_4_USED */

#ifdef SPI_CHANNEL_5_USED
    case  5 :
      TARG_WriteBit(ECSPI1_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE1 = TARG_ReadLong(ECSPI1_RXDATA);
      break;
#endif /* SPI_CHANNEL_5_USED */

#ifdef SPI_CHANNEL_6_USED
    case  6 :
      TARG_WriteBit(ECSPI1_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE1 = TARG_ReadLong(ECSPI1_RXDATA);
      break;
#endif /* SPI_CHANNEL_6_USED */

#ifdef SPI_CHANNEL_7_USED
    case  7 :
      TARG_WriteBit(ECSPI1_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE1 = TARG_ReadLong(ECSPI1_RXDATA);
      break;
#endif /* SPI_CHANNEL_7_USED */

#ifdef SPI_CHANNEL_8_USED
    case  8 :
      TARG_WriteBit(ECSPI2_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE2 = TARG_ReadLong(ECSPI2_RXDATA);
      break;
#endif /* SPI_CHANNEL_8_USED */

#ifdef SPI_CHANNEL_9_USED
    case  9 :
      TARG_WriteBit(ECSPI2_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE2 = TARG_ReadLong(ECSPI2_RXDATA);
      break;
#endif /* SPI_CHANNEL_9_USED */

#ifdef SPI_CHANNEL_10_USED
    case 10 :
      TARG_WriteBit(ECSPI2_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE2 = TARG_ReadLong(ECSPI2_RXDATA);
      break;
#endif /* SPI_CHANNEL_10_USED */

#ifdef SPI_CHANNEL_11_USED
    case 11 :
      TARG_WriteBit(ECSPI2_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE2 = TARG_ReadLong(ECSPI2_RXDATA);
      break;
#endif /* SPI_CHANNEL_11_USED */



    default :
      break;
  }
}

/******************************************************************************/
/* Name: SPID_OperationDone                                                   */
/* Role: Service routine to test end of transfer operation                    */
/* Interface: bool_t                                                          */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour:                                                                 */
/* DO                                                                         */
/*  [ Return current value of transfer completed flag ]                       */
/* OD                                                                         */
/******************************************************************************/
bool_t SPID_OperationDone(ubyte Channel)
{
  bool_t Result;

  Result = FALSE;

  switch(Channel)
  {
#ifdef SPI_CHANNEL_0_USED
    case  0 :
      Result = TARG_ReadBit(CSPI_STATREG, SPI_BIT_TC);
      break;
#endif /* SPI_CHANNEL_0_USED */

#ifdef SPI_CHANNEL_1_USED
    case  1 :
      Result = TARG_ReadBit(CSPI_STATREG, SPI_BIT_TC);
      break;
#endif /* SPI_CHANNEL_1_USED */

#ifdef SPI_CHANNEL_2_USED
    case  2 :
      Result = TARG_ReadBit(CSPI_STATREG, SPI_BIT_TC);
      break;
#endif /* SPI_CHANNEL_2_USED */

#ifdef SPI_CHANNEL_3_USED
    case  3 :
      Result = TARG_ReadBit(CSPI_STATREG, SPI_BIT_TC);
      break;
#endif /* SPI_CHANNEL_3_USED */

#ifdef SPI_CHANNEL_4_USED
    case  4 :
      Result = TARG_ReadBit(ECSPI1_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_4_USED */

#ifdef SPI_CHANNEL_5_USED
    case  5 :
      Result = TARG_ReadBit(ECSPI1_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_5_USED */

#ifdef SPI_CHANNEL_6_USED
    case  6 :
      Result = TARG_ReadBit(ECSPI1_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_6_USED */

#ifdef SPI_CHANNEL_7_USED
    case  7 :
      Result = TARG_ReadBit(ECSPI1_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_7_USED */

#ifdef SPI_CHANNEL_8_USED
    case  8 :
      Result = TARG_ReadBit(ECSPI2_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_8_USED */

#ifdef SPI_CHANNEL_9_USED
    case  9 :
      Result = TARG_ReadBit(ECSPI2_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_9_USED */

#ifdef SPI_CHANNEL_10_USED
    case 10 :
      Result = TARG_ReadBit(ECSPI2_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_10_USED */

#ifdef SPI_CHANNEL_11_USED
    case 11 :
      Result = TARG_ReadBit(ECSPI2_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_11_USED */


    default :
      break;
  }

  return(Result);
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
#ifdef SPI_CSPI_USED
  /* Select burst for 8 bits to send*/
  TARG_WriteLong(CSPI_CONREG, (TARG_ReadLong(CSPI_CONREG) & ~SPI_BURST_FMSK) | SPI_BURST_LENGTH_8 );

  /* Enable Master mode */
  TARG_WriteBit(CSPI_CONREG, SPI_BIT_MODE, SPI_MODE);

  /* Select active clock level */
  TARG_WriteBit(CSPI_CONREG, SPI_BIT_POL, SPI_POL);
  TARG_WriteBit(CSPI_CONREG, SPI_BIT_PHA, SPI_PHA);

  /* Chip select management */
  TARG_WriteBit(CSPI_CONREG, SPI_BIT_SSPOL, SPI_SSPOL);
  TARG_WriteBit(CSPI_CONREG, SPI_BIT_SSCTL, SPI_SSCTL);

  /* Master mode management */
  TARG_WriteBit(CSPI_CONREG, SPI_BIT_SMC, SPI_SMC);
  TARG_WriteBit(CSPI_CONREG, SPI_BIT_XCH, SPI_XCH);
  TARG_WriteLong(CSPI_CONREG, (TARG_ReadLong(CSPI_CONREG) & ~SPI_DRCTL_FMSK) | SPI_DRCTL );

  /* Enable active mode */
  TARG_WriteBit(CSPI_CONREG, SPI_BIT_EN, SPI_ENABLE);
#endif /* SPI_CSPI_USED */

#ifdef SPI_ECSPI1_USED
  /* Enable module (to configure registers) */
  TARG_WriteBit(ECSPI1_CONREG, SPI_E_BIT_EN, SPI_E1_ENABLE);

  /* Select active clock and data level */
  TARG_WriteLong(ECSPI1_CONFIGREG, (TARG_ReadLong(ECSPI1_CONFIGREG) & ~SPI_E_SCLK_PHA_FMSK) | SPI_E1_PHA);
  TARG_WriteLong(ECSPI1_CONFIGREG, (TARG_ReadLong(ECSPI1_CONFIGREG) & ~SPI_E_SCLK_POL_FMSK) | SPI_E1_POL);
  TARG_WriteLong(ECSPI1_CONFIGREG, (TARG_ReadLong(ECSPI1_CONFIGREG) & ~SPI_E_DATA_CTL_FMSK) | SPI_E1_DATA);
  TARG_WriteLong(ECSPI1_CONFIGREG, (TARG_ReadLong(ECSPI1_CONFIGREG) & ~SPI_E_SCLK_CTL_FMSK) | SPI_E1_CTL);

  /* Indicate HT message length */
  TARG_WriteLong(ECSPI1_CONFIGREG, (TARG_ReadLong(ECSPI1_CONFIGREG) & ~SPI_E_HT_LENGTH_FMSK) | SPI_E1_HTL);
  TARG_WriteBit(ECSPI1_CONREG, SPI_E_BIT_HT, SPI_E1_HT);

  /* Master mode management */
  TARG_WriteBit(ECSPI1_CONREG, SPI_BIT_XCH, SPI_E1_XCH);
  TARG_WriteBit(ECSPI1_CONREG, SPI_BIT_SMC, SPI_E1_SMC);

  /* Enable Master mode */
  TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~SPI_E_MODE_FMSK) | SPI_E1_BIT_MODE);
  TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~SPI_DRCTL_FMSK)  | SPI_E1_DRCTL );

  /* Chip select management */
  TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~SPI_E_SSCTL_FMSK) | SPI_E1_SSCTL);
  TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~SPI_E_SSPOL_FMSK) | SPI_E1_SSPOL);

  /* Select burst for 8 bits to send*/
  TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~SPI_E_BURST_FMSK) | SPI_E1_BURST_LENGTH_8);
#endif /* SPI_ECSPI1_USED */


#ifdef SPI_ECSPI2_USED
  /* Enable module (to configure registers) */
  TARG_WriteBit(ECSPI2_CONREG, SPI_E_BIT_EN, SPI_E2_ENABLE);

  /* Select active clock and data level */
  TARG_WriteLong(ECSPI2_CONFIGREG, (TARG_ReadLong(ECSPI2_CONFIGREG) & ~SPI_E_SCLK_PHA_FSBIT) | SPI_E2_PHA);
  TARG_WriteLong(ECSPI2_CONFIGREG, (TARG_ReadLong(ECSPI2_CONFIGREG) & ~SPI_E_SCLK_POL_FSBIT) | SPI_E2_POL);
  TARG_WriteLong(ECSPI2_CONFIGREG, (TARG_ReadLong(ECSPI2_CONFIGREG) & ~SPI_E_DATA_CTL_FSBIT) | SPI_E2_DATA);
  TARG_WriteLong(ECSPI2_CONFIGREG, (TARG_ReadLong(ECSPI2_CONFIGREG) & ~SPI_E_SCLK_CTL_FSBIT) | SPI_E2_CTL);

  /* Indicate HT message length */
  TARG_WriteLong(ECSPI2_CONFIGREG, (TARG_ReadLong(ECSPI2_CONFIGREG) & ~SPI_E_HT_LENGTH_FSBIT) | SPI_E2_HTL);
  TARG_WriteBit(ECSPI2_CONREG, SPI_E_BIT_HT, SPI_E2_HT);

  /* Master mode management */
  TARG_WriteBit(ECSPI2_CONREG, SPI_BIT_XCH, SPI_E2_XCH);
  TARG_WriteBit(ECSPI2_CONREG, SPI_BIT_SMC, SPI_E2_SMC);

  /* Enable Master mode */
  TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~SPI_E_MODE_FMSK) | SPI_E2_BIT_MODE);
  TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~SPI_DRCTL_FMSK)  | SPI_E2_DRCTL );

  /* Chip select management */
  TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~SPI_E_SSCTL_FSBIT) | SPI_E2_SSCTL);
  TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~SPI_E_SSPOL_FSBIT) | SPI_E2_SSPOL);

  /* Select burst for 8 bits to send*/
  TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~SPI_E_BURST_FMSK) | SPI_E2_BURST_LENGTH_8);
#endif /* SPI_ECSPI2_USED */



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
#ifdef SPI_CSPI_USED
  /* Stop channel */
  TARG_WriteBit(CSPI_CONREG, SPI_BIT_EN, 0);
#endif /* SPI_CSPI_USED */

#ifdef SPI_ECSPI1_USED
  /* Stop channel */
  TARG_WriteBit(ECSPI1_CONREG, SPI_E_BIT_EN, 0);
#endif /* SPI_ECSPI1_USED */

#ifdef SPI_ECSPI2_USED
  /* Stop channel */
  TARG_WriteBit(ECSPI2_CONREG, SPI_E_BIT_EN, 0);
#endif /* SPI_ECSPI2_USED */


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
  /* Init and Start channel */
  SPID_Init();
}

/******************************************************************************/
/* Name: SPID_ReceiveInterrupt_it                                             */
/* Role: Service routine of interrupt generated by SPI                        */
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
}
#endif /* SPID_UserReceiveInterrupt_ch0 */

#ifdef SPID_UserReceiveInterrupt_ch1
ISR(SPID_ReceiveInterrupt_ch1_it)
{
}
#endif /* SPID_UserReceiveInterrupt_ch1 */

/*_____ L O C A L - F U N C T I O N S ________________________________________*/

#endif /* __FSL_IMX53x__ */

#ifdef __FSL_IMX6x__


#if defined(C_COMP_GHS_ARM)
/* Suppress remark 1798: a questionable cast from type "volatile ulong *" to type
          "volatile bitfield_long_t *" may indicate illegal references. */
#pragma ghs nowarning 1798
#endif


/*______ G L O B A L - D A T A _______________________________________________*/

#ifdef __GHOS__
MemoryRegion SPID_MemoryRegion;
MemoryRegion SPID_VirtualMemoryRegion;
#endif /* __GHOS__ */


/*_____ L O C A L - D E F I N E S ____________________________________________*/

#define SPI_LAST_CHANNEL_IN_ECSPI_1      3
#define SPI_LAST_CHANNEL_IN_ECSPI_2      7
#define SPI_LAST_CHANNEL_IN_ECSPI_3     11
#define SPI_LAST_CHANNEL_IN_ECSPI_4     15


#define SPI_MODULE_ECSPI1             1
#define SPI_MODULE_ECSPI2             2
#define SPI_MODULE_ECSPI3             3
#define SPI_MODULE_ECSPI4             4


/*______ L O C A L - D A T A _________________________________________________*/




ulong Spid_BufferRxDataE1;
ulong Spid_BufferRxDataE2;
ulong Spid_BufferRxDataE3;
ulong Spid_BufferRxDataE4;



/*_____ L O C A L - F U N C T I O N S - P R O T O T Y P E S __________________*/


/* _____ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/

#ifdef SPID_UserReceiveInterrupt_ch0
extern void SPID_UserReceiveInterrupt_ch0(void);
#endif /* SPID_UserReceiveInterrupt_ch0 */
#ifdef SPID_UserReceiveInterrupt_ch1
extern void SPID_UserReceiveInterrupt_ch1(void);
#endif /* SPID_UserReceiveInterrupt_ch1 */

/*_____ G L O B A L - F U N C T I O N S ______________________________________*/

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
  ubyte RxData;

  switch(Channel)
  {

#ifdef SPI_CHANNEL_0_USED
    case  0 :
      RxData = Spid_BufferRxDataE1;
      break;
#endif /* SPI_CHANNEL_0_USED */

#ifdef SPI_CHANNEL_1_USED
    case  1 :
      RxData = Spid_BufferRxDataE1;
      break;
#endif /* SPI_CHANNEL_1_USED */

#ifdef SPI_CHANNEL_2_USED
    case  2 :
      RxData = Spid_BufferRxDataE1;
      break;
#endif /* SPI_CHANNEL_2_USED */

#ifdef SPI_CHANNEL_3_USED
    case  3 :
      RxData = Spid_BufferRxDataE1;
      break;
#endif /* SPI_CHANNEL_3_USED */

#ifdef SPI_CHANNEL_4_USED
    case  4 :
      RxData = Spid_BufferRxDataE2;
      break;
#endif /* SPI_CHANNEL_4_USED */

#ifdef SPI_CHANNEL_5_USED
    case  5 :
      RxData = Spid_BufferRxDataE2;
      break;
#endif /* SPI_CHANNEL_5_USED */

#ifdef SPI_CHANNEL_6_USED
    case 6 :
      RxData = Spid_BufferRxDataE2;
      break;
#endif /* SPI_CHANNEL_6_USED */

#ifdef SPI_CHANNEL_7_USED
    case 7 :
      RxData = Spid_BufferRxDataE2;
      break;
#endif /* SPI_CHANNEL_7_USED */

#ifdef SPI_CHANNEL_8_USED
    case  8 :
      RxData = Spid_BufferRxDataE3;
      break;
#endif /* SPI_CHANNEL_8_USED */

#ifdef SPI_CHANNEL_9_USED
    case  9 :
      RxData = Spid_BufferRxDataE3;
      break;
#endif /* SPI_CHANNEL_9_USED */

#ifdef SPI_CHANNEL_10_USED
    case 10 :
      RxData = Spid_BufferRxDataE3;
      break;
#endif /* SPI_CHANNEL_10_USED */

#ifdef SPI_CHANNEL_11_USED
    case 11 :
      RxData = Spid_BufferRxDataE3;
      break;
#endif /* SPI_CHANNEL_11_USED */

#ifdef SPI_CHANNEL_12_USED
    case  12 :
      RxData = Spid_BufferRxDataE4;
      break;
#endif /* SPI_CHANNEL_12_USED */

#ifdef SPI_CHANNEL_13_USED
    case  13 :
      RxData = Spid_BufferRxDataE4;
      break;
#endif /* SPI_CHANNEL_13_USED */

#ifdef SPI_CHANNEL_14_USED
    case 14 :
      RxData = Spid_BufferRxDataE4;
      break;
#endif /* SPI_CHANNEL_14_USED */

#ifdef SPI_CHANNEL_15_USED
    case 15 :
      RxData = Spid_BufferRxDataE4;
      break;
#endif /* SPI_CHANNEL_15_USED */

      default :
      RxData = 0;
      break;
  }

  return(RxData);
}

/******************************************************************************/
/* Name: SPID_TransmitByte                                                    */
/* Role: Provide the mean to start transmit of a byte on selected channel     */
/* Interface: Channel          IN  Communication channel number               */
/*             ByteToTransmit  IN  Byte to transmit on serial communication   */
/* Pre-condition: The transmit data register for the channel must be empty    */
/* Constraints: none                                                          */
/* DO                                                                         */
/*  [ Configure baud rate ]                                                   */
/*  [ Send the data]                                                          */
/* OD                                                                         */
/******************************************************************************/
void SPID_TransmitByte(ubyte Channel, ubyte DataByte)
{
  switch(Channel)
  {


#ifdef SPI_CHANNEL_0_USED
    case  0 :
      TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_0));
      TARG_WriteLong(ECSPI1_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_0_USED */

#ifdef SPI_CHANNEL_1_USED
    case  1 :
      TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_1));
      TARG_WriteLong(ECSPI1_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_1_USED */

#ifdef SPI_CHANNEL_2_USED
    case  2 :
      TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_2));
      TARG_WriteLong(ECSPI1_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_2_USED */

#ifdef SPI_CHANNEL_3_USED
    case  3 :
      TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_3));
      TARG_WriteLong(ECSPI1_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_3_USED */

#ifdef SPI_CHANNEL_4_USED
    case  4 :
      TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_4));
      TARG_WriteLong(ECSPI2_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_4_USED */

#ifdef SPI_CHANNEL_5_USED
    case  5 :
      TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_5));
      TARG_WriteLong(ECSPI2_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_5_USED */

#ifdef SPI_CHANNEL_6_USED
    case 6 :
      TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_6));
      TARG_WriteLong(ECSPI2_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_6_USED */

#ifdef SPI_CHANNEL_7_USED
    case 7 :
      TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_7));
      TARG_WriteLong(ECSPI2_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_7_USED */

#ifdef SPI_CHANNEL_8_USED
    case  8 :
      TARG_WriteLong(ECSPI3_CONREG, (TARG_ReadLong(ECSPI3_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_8));
      TARG_WriteLong(ECSPI3_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_8_USED */

#ifdef SPI_CHANNEL_9_USED
    case  9 :
      TARG_WriteLong(ECSPI3_CONREG, (TARG_ReadLong(ECSPI3_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_9));
      TARG_WriteLong(ECSPI3_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_9_USED */

#ifdef SPI_CHANNEL_10_USED
    case 10 :
      TARG_WriteLong(ECSPI3_CONREG, (TARG_ReadLong(ECSPI3_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_10));
      TARG_WriteLong(ECSPI3_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_10_USED */

#ifdef SPI_CHANNEL_11_USED
    case 11 :
      TARG_WriteLong(ECSPI3_CONREG, (TARG_ReadLong(ECSPI3_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_11));
      TARG_WriteLong(ECSPI3_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_11_USED */

#ifdef SPI_CHANNEL_12_USED
    case  12 :
      TARG_WriteLong(ECSPI4_CONREG, (TARG_ReadLong(ECSPI4_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_12));
      TARG_WriteLong(ECSPI4_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_12_USED */

#ifdef SPI_CHANNEL_13_USED
    case  13 :
      TARG_WriteLong(ECSPI4_CONREG, (TARG_ReadLong(ECSPI4_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_13));
      TARG_WriteLong(ECSPI4_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_13_USED */

#ifdef SPI_CHANNEL_14_USED
    case 14 :
      TARG_WriteLong(ECSPI4_CONREG, (TARG_ReadLong(ECSPI4_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_14));
      TARG_WriteLong(ECSPI4_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_14_USED */

#ifdef SPI_CHANNEL_15_USED
    case 15 :
      TARG_WriteLong(ECSPI4_CONREG, (TARG_ReadLong(ECSPI4_CONREG) & ~(SPI_E_PRE_DIVIDER_FMSK | SPI_E_POST_DIVIDER_FMSK)) | (SPI_CLOCK_CHANNEL_15));
      TARG_WriteLong(ECSPI4_TXDATA, DataByte);
      break;
#endif /* SPI_CHANNEL_15_USED */

    default :
      break;
  }
}

/******************************************************************************/
/* Name: SPID_NextOperation                                                   */
/* Role: Provide the mean to clear the TC bit and to flush Rx buffer          */
/* Interface: Channel  IN   Communication channel number                      */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour:                                                                 */
/* DO                                                                         */
/*  [ Clear transfer completed flag ]                                         */
/*  [ Store the received data ]                                               */
/* OD                                                                         */
/******************************************************************************/
void SPID_NextOperation(ubyte Channel)
{
  switch(Channel)
  {


#ifdef SPI_CHANNEL_0_USED
    case  0 :
      TARG_WriteBit(ECSPI1_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE1 = TARG_ReadLong(ECSPI1_RXDATA);
      break;
#endif /* SPI_CHANNEL_0_USED */

#ifdef SPI_CHANNEL_1_USED
    case  1 :
      TARG_WriteBit(ECSPI1_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE1 = TARG_ReadLong(ECSPI1_RXDATA);
      break;
#endif /* SPI_CHANNEL_1_USED */

#ifdef SPI_CHANNEL_2_USED
    case  2 :
      TARG_WriteBit(ECSPI1_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE1 = TARG_ReadLong(ECSPI1_RXDATA);
      break;
#endif /* SPI_CHANNEL_2_USED */

#ifdef SPI_CHANNEL_3_USED
    case  3 :
      TARG_WriteBit(ECSPI1_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE1 = TARG_ReadLong(ECSPI1_RXDATA);
      break;
#endif /* SPI_CHANNEL_3_USED */

#ifdef SPI_CHANNEL_4_USED
    case  4 :
      TARG_WriteBit(ECSPI2_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE2 = TARG_ReadLong(ECSPI2_RXDATA);
      break;
#endif /* SPI_CHANNEL_4_USED */

#ifdef SPI_CHANNEL_5_USED
    case  5 :
      TARG_WriteBit(ECSPI2_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE2 = TARG_ReadLong(ECSPI2_RXDATA);
      break;
#endif /* SPI_CHANNEL_5_USED */

#ifdef SPI_CHANNEL_6_USED
    case 6 :
      TARG_WriteBit(ECSPI2_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE2 = TARG_ReadLong(ECSPI2_RXDATA);
      break;
#endif /* SPI_CHANNEL_6_USED */

#ifdef SPI_CHANNEL_7_USED
    case 7 :
      TARG_WriteBit(ECSPI2_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE2 = TARG_ReadLong(ECSPI2_RXDATA);
      break;
#endif /* SPI_CHANNEL_7_USED */

#ifdef SPI_CHANNEL_8_USED
    case  8 :
      TARG_WriteBit(ECSPI3_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE3 = TARG_ReadLong(ECSPI3_RXDATA);
      break;
#endif /* SPI_CHANNEL_8_USED */

#ifdef SPI_CHANNEL_9_USED
    case  9 :
      TARG_WriteBit(ECSPI3_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE3 = TARG_ReadLong(ECSPI3_RXDATA);
      break;
#endif /* SPI_CHANNEL_9_USED */

#ifdef SPI_CHANNEL_10_USED
    case 10 :
      TARG_WriteBit(ECSPI3_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE3 = TARG_ReadLong(ECSPI3_RXDATA);
      break;
#endif /* SPI_CHANNEL_10_USED */

#ifdef SPI_CHANNEL_11_USED
    case 11 :
      TARG_WriteBit(ECSPI3_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE3 = TARG_ReadLong(ECSPI3_RXDATA);
      break;
#endif /* SPI_CHANNEL_11_USED */

#ifdef SPI_CHANNEL_12_USED
    case  12 :
      TARG_WriteBit(ECSPI4_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE4 = TARG_ReadLong(ECSPI4_RXDATA);
      break;
#endif /* SPI_CHANNEL_12_USED */

#ifdef SPI_CHANNEL_13_USED
    case  13 :
      TARG_WriteBit(ECSPI4_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE4 = TARG_ReadLong(ECSPI4_RXDATA);
      break;
#endif /* SPI_CHANNEL_13_USED */

#ifdef SPI_CHANNEL_14_USED
    case 14 :
      TARG_WriteBit(ECSPI4_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE4 = TARG_ReadLong(ECSPI4_RXDATA);
      break;
#endif /* SPI_CHANNEL_14_USED */

#ifdef SPI_CHANNEL_15_USED
    case 15 :
      TARG_WriteBit(ECSPI4_STATREG, SPI_E_BIT_TC, 1);
      Spid_BufferRxDataE4 = TARG_ReadLong(ECSPI4_RXDATA);
      break;
#endif /* SPI_CHANNEL_15_USED */



    default :
      break;
  }
}

/******************************************************************************/
/* Name: SPID_OperationDone                                                   */
/* Role: Service routine to test end of transfer operation                    */
/* Interface: bool_t                                                          */
/* Pre-condition: none                                                        */
/* Constraints: none                                                          */
/* Behaviour:                                                                 */
/* DO                                                                         */
/*  [ Return current value of transfer completed flag ]                       */
/* OD                                                                         */
/******************************************************************************/
bool_t SPID_OperationDone(ubyte Channel)
{
  bool_t Result;

  Result = FALSE;

  switch(Channel)
  {

#ifdef SPI_CHANNEL_0_USED
    case  0 :
      Result = TARG_ReadBit(ECSPI1_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_0_USED */

#ifdef SPI_CHANNEL_1_USED
    case  1 :
      Result = TARG_ReadBit(ECSPI1_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_1_USED */

#ifdef SPI_CHANNEL_2_USED
    case  2 :
      Result = TARG_ReadBit(ECSPI1_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_2_USED */

#ifdef SPI_CHANNEL_3_USED
    case  3 :
      Result = TARG_ReadBit(ECSPI1_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_3_USED */

#ifdef SPI_CHANNEL_4_USED
    case  4 :
      Result = TARG_ReadBit(ECSPI2_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_4_USED */

#ifdef SPI_CHANNEL_5_USED
    case  5 :
      Result = TARG_ReadBit(ECSPI2_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_5_USED */

#ifdef SPI_CHANNEL_6_USED
    case 6 :
      Result = TARG_ReadBit(ECSPI2_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_6_USED */

#ifdef SPI_CHANNEL_7_USED
    case 7 :
      Result = TARG_ReadBit(ECSPI2_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_7_USED */

#ifdef SPI_CHANNEL_8_USED
    case  8 :
      Result = TARG_ReadBit(ECSPI3_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_8_USED */

#ifdef SPI_CHANNEL_9_USED
    case  9 :
      Result = TARG_ReadBit(ECSPI3_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_9_USED */

#ifdef SPI_CHANNEL_10_USED
    case 10 :
      Result = TARG_ReadBit(ECSPI3_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_10_USED */

#ifdef SPI_CHANNEL_11_USED
    case 11 :
      Result = TARG_ReadBit(ECSPI3_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_11_USED */

#ifdef SPI_CHANNEL_12_USED
    case  12 :
      Result = TARG_ReadBit(ECSPI4_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_12_USED */

#ifdef SPI_CHANNEL_13_USED
    case  13 :
      Result = TARG_ReadBit(ECSPI4_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_13_USED */

#ifdef SPI_CHANNEL_14_USED
    case 14 :
      Result = TARG_ReadBit(ECSPI4_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_14_USED */

#ifdef SPI_CHANNEL_15_USED
    case 15 :
      Result = TARG_ReadBit(ECSPI4_STATREG, SPI_E_BIT_TC);
      break;
#endif /* SPI_CHANNEL_15_USED */


    default :
      break;
  }

  return(Result);
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
  #ifdef __GHOS__

  Value Attr;
  Address Start;
  Address Last;

  #ifdef __POLYSPACE__
  Attr = 0;
  #endif /* __POLYSPACE__ */

  /* Map in ECSPI registers */
  CheckSuccess(RequestResource((Object*)&SPID_MemoryRegion, "SPID_MemoryArea", "!systempassword"));
  CheckSuccess(GetMemoryRegionAddresses(SPID_MemoryRegion, &Start, &Last));
  /* Request a virtual memory region at the same address as the physical one */
  CheckSuccess(AllocateMemoryRegion(__ghs_VirtualMemoryRegionPool, ECSPI1_BASE_ADDR_ASM, ECSPI1_BASE_ADDR_ASM + Last - Start, &SPID_VirtualMemoryRegion));
  CheckSuccess(GetMemoryRegionAttributes(SPID_MemoryRegion, &Attr));
  CheckSuccess(SetMemoryRegionAttributes(SPID_VirtualMemoryRegion, Attr));
  CheckSuccess(MapMemoryRegion(SPID_VirtualMemoryRegion, SPID_MemoryRegion));
  CheckSuccess(GetMemoryRegionAddresses(SPID_VirtualMemoryRegion, &Start, &Last));

  #endif /* __GHOS__ */

#ifdef SPI_ECSPI1_USED
  /* Enable module (to configure registers) */
  TARG_WriteBit(ECSPI1_CONREG, SPI_E_BIT_EN, SPI_E1_ENABLE);

  /* Select active clock and data level */
  TARG_WriteLong(ECSPI1_CONFIGREG, (TARG_ReadLong(ECSPI1_CONFIGREG) & ~SPI_E_SCLK_PHA_FMSK) | SPI_E1_PHA);
  TARG_WriteLong(ECSPI1_CONFIGREG, (TARG_ReadLong(ECSPI1_CONFIGREG) & ~SPI_E_SCLK_POL_FMSK) | SPI_E1_POL);
  TARG_WriteLong(ECSPI1_CONFIGREG, (TARG_ReadLong(ECSPI1_CONFIGREG) & ~SPI_E_DATA_CTL_FMSK) | SPI_E1_DATA);
  TARG_WriteLong(ECSPI1_CONFIGREG, (TARG_ReadLong(ECSPI1_CONFIGREG) & ~SPI_E_SCLK_CTL_FMSK) | SPI_E1_CTL);

  /* Indicate HT message length */
  TARG_WriteLong(ECSPI1_CONFIGREG, (TARG_ReadLong(ECSPI1_CONFIGREG) & ~SPI_E_HT_LENGTH_FMSK) | SPI_E1_HTL);
  TARG_WriteBit(ECSPI1_CONREG, SPI_E_BIT_HT, SPI_E1_HT);

  /* Master mode management */
  TARG_WriteBit(ECSPI1_CONREG, SPI_E_BIT_XCH, SPI_E1_XCH);
  TARG_WriteBit(ECSPI1_CONREG, SPI_E_BIT_SMC, SPI_E1_SMC);

  /* Enable Master mode */
  TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~SPI_E_MODE_FMSK) | SPI_E1_BIT_MODE);
  TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~SPI_E_DRCTL_FMSK)  | SPI_E1_DRCTL );

  /* Chip select management */
  TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~SPI_E_SSCTL_FMSK) | SPI_E1_SSCTL);
  TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~SPI_E_SSPOL_FMSK) | SPI_E1_SSPOL);

  /* Select burst for 8 bits to send*/
  TARG_WriteLong(ECSPI1_CONREG, (TARG_ReadLong(ECSPI1_CONREG) & ~SPI_E_BURST_FMSK) | SPI_E1_BURST_LENGTH_8);
#endif /* SPI_ECSPI1_USED */


#ifdef SPI_ECSPI2_USED
  /* Enable module (to configure registers) */
  TARG_WriteBit(ECSPI2_CONREG, SPI_E_BIT_EN, SPI_E2_ENABLE);

  /* Select active clock and data level */
  TARG_WriteLong(ECSPI2_CONFIGREG, (TARG_ReadLong(ECSPI2_CONFIGREG) & ~SPI_E_SCLK_PHA_FMSK) | SPI_E2_PHA);
  TARG_WriteLong(ECSPI2_CONFIGREG, (TARG_ReadLong(ECSPI2_CONFIGREG) & ~SPI_E_SCLK_POL_FMSK) | SPI_E2_POL);
  TARG_WriteLong(ECSPI2_CONFIGREG, (TARG_ReadLong(ECSPI2_CONFIGREG) & ~SPI_E_DATA_CTL_FMSK) | SPI_E2_DATA);
  TARG_WriteLong(ECSPI2_CONFIGREG, (TARG_ReadLong(ECSPI2_CONFIGREG) & ~SPI_E_SCLK_CTL_FMSK) | SPI_E2_CTL);

  /* Indicate HT message length */
  TARG_WriteLong(ECSPI2_CONFIGREG, (TARG_ReadLong(ECSPI2_CONFIGREG) & ~SPI_E_HT_LENGTH_FMSK) | SPI_E2_HTL);
  TARG_WriteBit(ECSPI2_CONREG, SPI_E_BIT_HT, SPI_E2_HT);

  /* Master mode management */
  TARG_WriteBit(ECSPI2_CONREG, SPI_E_BIT_XCH, SPI_E2_XCH);
  TARG_WriteBit(ECSPI2_CONREG, SPI_E_BIT_SMC, SPI_E2_SMC);

  /* Enable Master mode */
  TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~SPI_E_MODE_FMSK) | SPI_E2_BIT_MODE);
  TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~SPI_E_DRCTL_FMSK)  | SPI_E2_DRCTL );

  /* Chip select management */
  TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~SPI_E_SSCTL_FMSK) | SPI_E2_SSCTL);
  TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~SPI_E_SSPOL_FMSK) | SPI_E2_SSPOL);

  /* Select burst for 8 bits to send*/
  TARG_WriteLong(ECSPI2_CONREG, (TARG_ReadLong(ECSPI2_CONREG) & ~SPI_E_BURST_FMSK) | SPI_E2_BURST_LENGTH_8);
#endif /* SPI_ECSPI2_USED */


#ifdef SPI_ECSPI3_USED
  /* Enable module (to configure registers) */
  TARG_WriteBit(ECSPI3_CONREG, SPI_E_BIT_EN, SPI_E3_ENABLE);

  /* Select active clock and data level */
  TARG_WriteLong(ECSPI3_CONFIGREG, (TARG_ReadLong(ECSPI3_CONFIGREG) & ~SPI_E_SCLK_PHA_FMSK) | SPI_E3_PHA);
  TARG_WriteLong(ECSPI3_CONFIGREG, (TARG_ReadLong(ECSPI3_CONFIGREG) & ~SPI_E_SCLK_POL_FMSK) | SPI_E3_POL);
  TARG_WriteLong(ECSPI3_CONFIGREG, (TARG_ReadLong(ECSPI3_CONFIGREG) & ~SPI_E_DATA_CTL_FMSK) | SPI_E3_DATA);
  TARG_WriteLong(ECSPI3_CONFIGREG, (TARG_ReadLong(ECSPI3_CONFIGREG) & ~SPI_E_SCLK_CTL_FMSK) | SPI_E3_CTL);

  /* Indicate HT message length */
  TARG_WriteLong(ECSPI3_CONFIGREG, (TARG_ReadLong(ECSPI1_CONFIGREG) & ~SPI_E_HT_LENGTH_FMSK) | SPI_E3_HTL);
  TARG_WriteBit(ECSPI3_CONREG, SPI_E_BIT_HT, SPI_E3_HT);

  /* Master mode management */
  TARG_WriteBit(ECSPI3_CONREG, SPI_E_BIT_XCH, SPI_E3_XCH);
  TARG_WriteBit(ECSPI3_CONREG, SPI_E_BIT_SMC, SPI_E3_SMC);

  /* Enable Master mode */
  TARG_WriteLong(ECSPI3_CONREG, (TARG_ReadLong(ECSPI3_CONREG) & ~SPI_E_MODE_FMSK) | SPI_E3_BIT_MODE);
  TARG_WriteLong(ECSPI3_CONREG, (TARG_ReadLong(ECSPI3_CONREG) & ~SPI_E_DRCTL_FMSK)  | SPI_E3_DRCTL );

  /* Chip select management */
  TARG_WriteLong(ECSPI3_CONREG, (TARG_ReadLong(ECSPI3_CONREG) & ~SPI_E_SSCTL_FMSK) | SPI_E3_SSCTL);
  TARG_WriteLong(ECSPI3_CONREG, (TARG_ReadLong(ECSPI3_CONREG) & ~SPI_E_SSPOL_FMSK) | SPI_E3_SSPOL);

  /* Select burst for 8 bits to send*/
  TARG_WriteLong(ECSPI3_CONREG, (TARG_ReadLong(ECSPI3_CONREG) & ~SPI_E_BURST_FMSK) | SPI_E3_BURST_LENGTH_8);
#endif /* SPI_ECSPI3_USED */


#ifdef SPI_ECSPI4_USED
  /* Enable module (to configure registers) */
  TARG_WriteBit(ECSPI4_CONREG, SPI_E_BIT_EN, SPI_E4_ENABLE);

  /* Select active clock and data level */
  TARG_WriteLong(ECSPI4_CONFIGREG, (TARG_ReadLong(ECSPI4_CONFIGREG) & ~SPI_E_SCLK_PHA_FMSK) | SPI_E4_PHA);
  TARG_WriteLong(ECSPI4_CONFIGREG, (TARG_ReadLong(ECSPI4_CONFIGREG) & ~SPI_E_SCLK_POL_FMSK) | SPI_E4_POL);
  TARG_WriteLong(ECSPI4_CONFIGREG, (TARG_ReadLong(ECSPI4_CONFIGREG) & ~SPI_E_DATA_CTL_FMSK) | SPI_E4_DATA);
  TARG_WriteLong(ECSPI4_CONFIGREG, (TARG_ReadLong(ECSPI4_CONFIGREG) & ~SPI_E_SCLK_CTL_FMSK) | SPI_E4_CTL);

  /* Indicate HT message length */
  TARG_WriteLong(ECSPI4_CONFIGREG, (TARG_ReadLong(ECSPI4_CONFIGREG) & ~SPI_E_HT_LENGTH_FMSK) | SPI_E4_HTL);
  TARG_WriteBit(ECSPI4_CONREG, SPI_E_BIT_HT, SPI_E4_HT);

  /* Master mode management */
  TARG_WriteBit(ECSPI4_CONREG, SPI_E_BIT_XCH, SPI_E4_XCH);
  TARG_WriteBit(ECSPI4_CONREG, SPI_E_BIT_SMC, SPI_E4_SMC);

  /* Enable Master mode */
  TARG_WriteLong(ECSPI4_CONREG, (TARG_ReadLong(ECSPI4_CONREG) & ~SPI_E_MODE_FMSK) | SPI_E4_BIT_MODE);
  TARG_WriteLong(ECSPI4_CONREG, (TARG_ReadLong(ECSPI4_CONREG) & ~SPI_E_DRCTL_FMSK)  | SPI_E4_DRCTL );

  /* Chip select management */
  TARG_WriteLong(ECSPI4_CONREG, (TARG_ReadLong(ECSPI4_CONREG) & ~SPI_E_SSCTL_FMSK) | SPI_E4_SSCTL);
  TARG_WriteLong(ECSPI4_CONREG, (TARG_ReadLong(ECSPI4_CONREG) & ~SPI_E_SSPOL_FMSK) | SPI_E4_SSPOL);

  /* Select burst for 8 bits to send*/
  TARG_WriteLong(ECSPI4_CONREG, (TARG_ReadLong(ECSPI4_CONREG) & ~SPI_E_BURST_FMSK) | SPI_E4_BURST_LENGTH_8);
#endif /* SPI_ECSPI4_USED */
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

#ifdef SPI_ECSPI1_USED
  /* Stop channel */
  TARG_WriteBit(ECSPI1_CONREG, SPI_E_BIT_EN, 0);
#endif /* SPI_ECSPI1_USED */

#ifdef SPI_ECSPI2_USED
  /* Stop channel */
  TARG_WriteBit(ECSPI2_CONREG, SPI_E_BIT_EN, 0);
#endif /* SPI_ECSPI2_USED */

#ifdef SPI_ECSPI3_USED
  /* Stop channel */
  TARG_WriteBit(ECSPI3_CONREG, SPI_E_BIT_EN, 0);
#endif /* SPI_ECSPI3_USED */

#ifdef SPI_ECSPI4_USED
  /* Stop channel */
  TARG_WriteBit(ECSPI4_CONREG, SPI_E_BIT_EN, 0);
#endif /* SPI_ECSPI4_USED */
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
  /* Init and Start channel */
  SPID_Init();
}

/******************************************************************************/
/* Name: SPID_ReceiveInterrupt_it                                             */
/* Role: Service routine of interrupt generated by SPI                        */
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
}
#endif /* SPID_UserReceiveInterrupt_ch0 */

#ifdef SPID_UserReceiveInterrupt_ch1
ISR(SPID_ReceiveInterrupt_ch1_it)
{
}
#endif /* SPID_UserReceiveInterrupt_ch1 */

/*_____ L O C A L - F U N C T I O N S ________________________________________*/


#if defined(C_COMP_GHS_ARM)
#pragma ghs endnowarning
#endif


#endif /* __FSL_IMX6x__*/



#ifdef __REL_RL78__

#ifdef __REL_RL78_D1x__

#ifdef __REL_RL78_D1A__

/*_____ L O C A L - D E F I N E S ____________________________________________*/

/* Values to set into clock select register SPSm                              */
/* Clock phase and polarity is fixed to type 1 (Latch on clock rising edge)   */
#define SPID_FX_DIV_BY_0      0
#define SPID_FX_DIV_BY_2     (SPI_MSK_PRS000)
#define SPID_FX_DIV_BY_4     (SPI_MSK_PRS001)
#define SPID_FX_DIV_BY_8     (SPI_MSK_PRS000 + SPI_MSK_PRS001)
#define SPID_FX_DIV_BY_16    (SPI_MSK_PRS002)
#define SPID_FX_DIV_BY_32    (SPI_MSK_PRS000 + SPI_MSK_PRS002)
#define SPID_FX_DIV_BY_64    (SPI_MSK_PRS001 + SPI_MSK_PRS002)
#define SPID_FX_DIV_BY_128   (SPI_MSK_PRS000 + SPI_MSK_PRS001 + SPI_MSK_PRS002)
#define SPID_FX_DIV_BY_256   (SPI_MSK_PRS003)
#define SPID_FX_DIV_BY_512   (SPI_MSK_PRS000 + SPI_MSK_PRS003)
#define SPID_FX_DIV_BY_1024  (SPI_MSK_PRS001 + SPI_MSK_PRS003)
#define SPID_FX_DIV_BY_2048  (SPI_MSK_PRS000 + SPI_MSK_PRS001 + SPI_MSK_PRS003)

/* FREQUENCY DIVISION FACTOR : Fmck(operation clock) / divison factor 2 = Transfer Clock(to be used by the module)*/

#define SPID_FX_OPRCLK_DIV_BY_1        0x0000
#define SPID_FX_OPRCLK_DIV_BY_2        0x0200
#define SPID_FX_OPRCLK_DIV_BY_3        0x0400
#define SPID_FX_OPRCLK_DIV_BY_4        0x0600
#define SPID_FX_OPRCLK_DIV_BY_5        0x0800
#define SPID_FX_OPRCLK_DIV_BY_6        0x0A00
#define SPID_FX_OPRCLK_DIV_BY_7        0x0C00
#define SPID_FX_OPRCLK_DIV_BY_8        0x0E00
#define SPID_FX_OPRCLK_DIV_BY_9        0x1000
#define SPID_FX_OPRCLK_DIV_BY_10       0x1200
#define SPID_FX_OPRCLK_DIV_BY_11       0x1400
#define SPID_FX_OPRCLK_DIV_BY_12       0x1600
#define SPID_FX_OPRCLK_DIV_BY_13       0x1800
#define SPID_FX_OPRCLK_DIV_BY_14       0x1A00
#define SPID_FX_OPRCLK_DIV_BY_15       0x1C00
#define SPID_FX_OPRCLK_DIV_BY_16       0x1E00
#define SPID_FX_OPRCLK_DIV_BY_17       0x2000
#define SPID_FX_OPRCLK_DIV_BY_18       0x2200
#define SPID_FX_OPRCLK_DIV_BY_19       0x2400
#define SPID_FX_OPRCLK_DIV_BY_20       0x2600
#define SPID_FX_OPRCLK_DIV_BY_21       0x2800
#define SPID_FX_OPRCLK_DIV_BY_22       0x2A00
#define SPID_FX_OPRCLK_DIV_BY_23       0x2C00
#define SPID_FX_OPRCLK_DIV_BY_24       0x2E00
#define SPID_FX_OPRCLK_DIV_BY_25       0x3000
#define SPID_FX_OPRCLK_DIV_BY_26       0x3200
#define SPID_FX_OPRCLK_DIV_BY_27       0x3400
#define SPID_FX_OPRCLK_DIV_BY_28       0x3600
#define SPID_FX_OPRCLK_DIV_BY_29       0x3800
#define SPID_FX_OPRCLK_DIV_BY_30       0x3A00
#define SPID_FX_OPRCLK_DIV_BY_31       0x3C00
#define SPID_FX_OPRCLK_DIV_BY_32       0x3E00
#define SPID_FX_OPRCLK_DIV_BY_33       0x4000
#define SPID_FX_OPRCLK_DIV_BY_34       0x4200
#define SPID_FX_OPRCLK_DIV_BY_35       0x4400
#define SPID_FX_OPRCLK_DIV_BY_36       0x4600
#define SPID_FX_OPRCLK_DIV_BY_37       0x4800
#define SPID_FX_OPRCLK_DIV_BY_38       0x4A00
#define SPID_FX_OPRCLK_DIV_BY_39       0x4C00
#define SPID_FX_OPRCLK_DIV_BY_40       0x4E00
#define SPID_FX_OPRCLK_DIV_BY_41       0x5000
#define SPID_FX_OPRCLK_DIV_BY_42       0x5200
#define SPID_FX_OPRCLK_DIV_BY_43       0x5400
#define SPID_FX_OPRCLK_DIV_BY_44       0x5600
#define SPID_FX_OPRCLK_DIV_BY_45       0x5800
#define SPID_FX_OPRCLK_DIV_BY_46       0x5A00
#define SPID_FX_OPRCLK_DIV_BY_47       0x5C00
#define SPID_FX_OPRCLK_DIV_BY_48       0x5E00
#define SPID_FX_OPRCLK_DIV_BY_49       0x6000
#define SPID_FX_OPRCLK_DIV_BY_50       0x6200
#define SPID_FX_OPRCLK_DIV_BY_51       0x6400
#define SPID_FX_OPRCLK_DIV_BY_52       0x6600
#define SPID_FX_OPRCLK_DIV_BY_53       0x6800
#define SPID_FX_OPRCLK_DIV_BY_54       0x6A00
#define SPID_FX_OPRCLK_DIV_BY_55       0x6C00
#define SPID_FX_OPRCLK_DIV_BY_56       0x6E00
#define SPID_FX_OPRCLK_DIV_BY_57       0x7000
#define SPID_FX_OPRCLK_DIV_BY_58       0x7200
#define SPID_FX_OPRCLK_DIV_BY_59       0x7400
#define SPID_FX_OPRCLK_DIV_BY_60       0x7600
#define SPID_FX_OPRCLK_DIV_BY_61       0x7800
#define SPID_FX_OPRCLK_DIV_BY_62       0x7A00
#define SPID_FX_OPRCLK_DIV_BY_63       0x7C00
#define SPID_FX_OPRCLK_DIV_BY_64       0x7E00
#define SPID_FX_OPRCLK_DIV_BY_65       0x8000
#define SPID_FX_OPRCLK_DIV_BY_66       0x8200
#define SPID_FX_OPRCLK_DIV_BY_67       0x8400
#define SPID_FX_OPRCLK_DIV_BY_68       0x8600
#define SPID_FX_OPRCLK_DIV_BY_69       0x8800
#define SPID_FX_OPRCLK_DIV_BY_70       0x8A00
#define SPID_FX_OPRCLK_DIV_BY_71       0x8C00
#define SPID_FX_OPRCLK_DIV_BY_72       0x8E00
#define SPID_FX_OPRCLK_DIV_BY_73       0x9000
#define SPID_FX_OPRCLK_DIV_BY_74       0x9200
#define SPID_FX_OPRCLK_DIV_BY_75       0x9400
#define SPID_FX_OPRCLK_DIV_BY_76       0x9600
#define SPID_FX_OPRCLK_DIV_BY_77       0x9800
#define SPID_FX_OPRCLK_DIV_BY_78       0x9A00
#define SPID_FX_OPRCLK_DIV_BY_79       0x9C00
#define SPID_FX_OPRCLK_DIV_BY_80       0x9E00
#define SPID_FX_OPRCLK_DIV_BY_81       0xA000
#define SPID_FX_OPRCLK_DIV_BY_82       0xA200
#define SPID_FX_OPRCLK_DIV_BY_83       0xA400
#define SPID_FX_OPRCLK_DIV_BY_84       0xA600
#define SPID_FX_OPRCLK_DIV_BY_85       0xA800
#define SPID_FX_OPRCLK_DIV_BY_86       0xAA00
#define SPID_FX_OPRCLK_DIV_BY_87       0xAC00
#define SPID_FX_OPRCLK_DIV_BY_88       0xAE00
#define SPID_FX_OPRCLK_DIV_BY_89       0xB000
#define SPID_FX_OPRCLK_DIV_BY_90       0xB200
#define SPID_FX_OPRCLK_DIV_BY_91       0xB400
#define SPID_FX_OPRCLK_DIV_BY_92       0xB600
#define SPID_FX_OPRCLK_DIV_BY_93       0xB800
#define SPID_FX_OPRCLK_DIV_BY_94       0xBA00
#define SPID_FX_OPRCLK_DIV_BY_95       0xBC00
#define SPID_FX_OPRCLK_DIV_BY_96       0xBE00
#define SPID_FX_OPRCLK_DIV_BY_97       0xC000
#define SPID_FX_OPRCLK_DIV_BY_98       0xC200
#define SPID_FX_OPRCLK_DIV_BY_99       0xC400
#define SPID_FX_OPRCLK_DIV_BY_100      0xC600
#define SPID_FX_OPRCLK_DIV_BY_101      0xC800
#define SPID_FX_OPRCLK_DIV_BY_102      0xCA00
#define SPID_FX_OPRCLK_DIV_BY_103      0xCC00
#define SPID_FX_OPRCLK_DIV_BY_104      0xCE00
#define SPID_FX_OPRCLK_DIV_BY_105      0xD000
#define SPID_FX_OPRCLK_DIV_BY_106      0xD200
#define SPID_FX_OPRCLK_DIV_BY_107      0xD400
#define SPID_FX_OPRCLK_DIV_BY_108      0xD600
#define SPID_FX_OPRCLK_DIV_BY_109      0xD800
#define SPID_FX_OPRCLK_DIV_BY_110      0xDA00
#define SPID_FX_OPRCLK_DIV_BY_111      0xDC00
#define SPID_FX_OPRCLK_DIV_BY_112      0xDE00
#define SPID_FX_OPRCLK_DIV_BY_113      0xE000
#define SPID_FX_OPRCLK_DIV_BY_114      0xE200
#define SPID_FX_OPRCLK_DIV_BY_115      0xE400
#define SPID_FX_OPRCLK_DIV_BY_116      0xE600
#define SPID_FX_OPRCLK_DIV_BY_117      0xE800
#define SPID_FX_OPRCLK_DIV_BY_118      0xEA00
#define SPID_FX_OPRCLK_DIV_BY_119      0xEC00
#define SPID_FX_OPRCLK_DIV_BY_120      0xEE00
#define SPID_FX_OPRCLK_DIV_BY_121      0xF000
#define SPID_FX_OPRCLK_DIV_BY_122      0xF200
#define SPID_FX_OPRCLK_DIV_BY_123      0xF400
#define SPID_FX_OPRCLK_DIV_BY_124      0xF600
#define SPID_FX_OPRCLK_DIV_BY_125      0xF800
#define SPID_FX_OPRCLK_DIV_BY_126      0xFA00
#define SPID_FX_OPRCLK_DIV_BY_127      0xFC00
#define SPID_FX_OPRCLK_DIV_BY_128      0xFE00


/* values to set into SCRmn                                                   */
/* data length selection */
#define SPID_DATA_LENGTH_7_BIT   ((ushort)0x0006)
#define SPID_DATA_LENGTH_8_BIT   ((ushort)0x0007)
#define SPID_DATA_LENGTH_9_BIT   ((ushort)0x0008)
#define SPID_DATA_LENGTH_10_BIT  ((ushort)0x0009)
#define SPID_DATA_LENGTH_11_BIT  ((ushort)0x000a)
#define SPID_DATA_LENGTH_12_BIT  ((ushort)0x000b)
#define SPID_DATA_LENGTH_13_BIT  ((ushort)0x000c)
#define SPID_DATA_LENGTH_14_BIT  ((ushort)0x000d)
#define SPID_DATA_LENGTH_15_BIT  ((ushort)0x000e)
#define SPID_DATA_LENGTH_16_BIT  ((ushort)0x000f)

/* Value to set into mode register SMRmn for Tx/Rx operation */
#define SPID_TX_RX_MODE  SPI_MSK_SMR00


/*______ L O C A L - T Y P E S _______________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ P R I V A T E - D A T A _____________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/*______ G L O B A L - F U N C T I O N S _____________________________________*/

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
#ifdef SPID_ACTIVE_CHANNEL_0

  /* supply SAU0 clock */
  TARG_WriteBit(PER0, SPI_BIT_SAU0EN, 1);
  /* Wait time after PER0 register write */
  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;

  /* Select clock speed */
  TARG_SetBitsInShort(SPS0, SPID_CLOCK_SELECTION_CHANNEL_0);

  /* disable CSI00 */
  TARG_WriteBit(ST0L, SPI_BIT_ST00, 1);

  /* disable INTCSI00 interrupt */
  TARG_WriteBit(MK0H, SPI_BIT_CSIMK00, 1);

  /* clear error flag */
  TARG_WriteShort(SIR00, SPI_MSK_OVCT00);

  /* Select mode */
  TARG_ClearBitsInShort(SMR00, SPI_MSK_MD001);
  TARG_ClearBitsInShort(SMR00, SPI_MSK_MD002);

  /* Transmission/reception, no stop bit, LSB start, 8-bit data length */
  TARG_ClearBitsInShort(SCR00, SPI_MSK_DLS00);
  TARG_SetBitsInShort(SCR00, SPID_DATA_LENGTH_SELECTION_CHANNEL_0);
  TARG_SetBitsInShort(SCR00, (SPI_MSK_RXE00 | SPI_MSK_TXE00));
  TARG_ClearBitsInShort(SCR00, SPI_MSK_DIR00);

  /* set second divide register */
  TARG_WriteShort(SDR00, SPID_OPERATION_CLOCK_DIVFAC_CH_0);

  /* output CSI00 clock value 1, output CSI00 data value 0 */
  TARG_ClearBitsInShort(SO0, SPI_MSK_SO00);
  TARG_SetBitsInShort(SO0, SPI_MSK_CKO00);

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM10, 0);
  TARG_WriteBit(P1, PORT_BIT_P10, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM12, 0);
  TARG_WriteBit(P1, PORT_BIT_P12, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM11, 1);

  /* Set the It flag for the first time */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF00, 0);

  /* enable CSI00 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE00, 1);

  /* enable CSI00 */
  TARG_WriteBit(SS0L, SPI_BIT_SS00, 1);
#endif

#ifdef SPID_ACTIVE_CHANNEL_1

  /* supply SAU0 clock */
  TARG_WriteBit(PER0, SPI_BIT_SAU0EN, 1);
  /* Wait time after PER0 register write */
  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;

  /* Select clock speed */
  TARG_SetBitsInShort(SPS0, SPID_CLOCK_SELECTION_CHANNEL_1);

  /* disable CSI01 */
  TARG_WriteBit(ST0L, SPI_BIT_ST01, 1);

  /* disable INTCSI01 interrupt */
  TARG_WriteBit(MK0H, SPI_BIT_CSIMK01, 1);

  /* clear error flag */
  TARG_WriteShort(SIR01, SPI_MSK_OVCT01);

  /* Select mode */
  TARG_ClearBitsInShort(SMR01, SPI_MSK_MD011);
  TARG_ClearBitsInShort(SMR01, SPI_MSK_MD012);

  /* Transmission/reception, no stop bit, LSB start, 8-bit data length */
  TARG_ClearBitsInShort(SCR01, SPI_MSK_DLS01);
  TARG_SetBitsInShort(SCR01, SPID_DATA_LENGTH_SELECTION_CHANNEL_1);
  TARG_SetBitsInShort(SCR01, (SPI_MSK_RXE01 | SPI_MSK_TXE01));
  TARG_ClearBitsInShort(SCR01, SPI_MSK_DIR01);

  /* set second divide register */
  TARG_WriteShort(SDR01, SPID_OPERATION_CLOCK_DIVFAC_CH_1);

  /* output CSI01 clock value 1, output CSI01 data value 0 */
  TARG_ClearBitsInShort(SO0, SPI_MSK_SO01);
  TARG_SetBitsInShort(SO0, SPI_MSK_CKO01);

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM74, 0);
  TARG_WriteBit(P7, PORT_BIT_P74, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM13, 0);
  TARG_WriteBit(P1, PORT_BIT_P13, 0);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM75, 1);

  /* Set the It flag for the first time */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF01, 0);

  /* enable CSI01 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE01, 1);

  /* enable CSI01 */

  TARG_WriteBit(SS0L, SPI_BIT_SS01, 1);
#endif

#ifdef SPID_ACTIVE_CHANNEL_2

  /* supply SAU1 clock */
  TARG_WriteBit(PER0, SPI_BIT_SAU1EN, 1);
  /* Wait time after PER0 register write */
  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;

  /* Select clock speed */
  TARG_SetBitsInShort(SPS1, SPID_CLOCK_SELECTION_CHANNEL_2);

  /* disable CSI10 */
  TARG_WriteBit(ST1L, SPI_BIT_ST10, 1);

  /* disable INTCSI10 interrupt */
  TARG_WriteBit(MK1H, SPI_BIT_CSIMK10, 1);

  /* clear error flag */
  TARG_WriteShort(SIR10, SPI_MSK_OVCT10);

  /* Select mode */
  TARG_ClearBitsInShort(SMR10, SPI_MSK_MD101);
  TARG_ClearBitsInShort(SMR10, SPI_MSK_MD102);

  /* Transmission/reception, no stop bit, LSB start, 8-bit data length */
  TARG_ClearBitsInShort(SCR10, SPI_MSK_DLS10);
  TARG_SetBitsInShort(SCR10, SPID_DATA_LENGTH_SELECTION_CHANNEL_2);
  TARG_SetBitsInShort(SCR10, (SPI_MSK_RXE10 | SPI_MSK_RXE10));
  TARG_ClearBitsInShort(SCR10, SPI_MSK_DIR10);

  /* set second divide register */
  TARG_WriteShort(SDR10, SPID_OPERATION_CLOCK_DIVFAC_CH_2);

  /* output CSI10 clock value 1, output CSI10 data value 0 */
  TARG_ClearBitsInShort(SO1, SPI_MSK_SO10);
  TARG_SetBitsInShort(SO1, SPI_MSK_CKO10);

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM13, PORT_BIT_PM133, 0);
  TARG_WriteBit(P13, PORT_BIT_P133, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM13, PORT_BIT_PM131, 0);
  TARG_WriteBit(P13, PORT_BIT_P131, 0);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM13, PORT_BIT_PM132, 1);

  /* Set the It flag for the first time */
  TARG_WriteBit(IF1H, SPI_BIT_CSIIF10, 0);

  /* enable CSI10 output */
  TARG_WriteBit(SOE1L, SPI_BIT_SOE10, 1);

  /* enable CSI10 */
  TARG_WriteBit(SS1L, SPI_BIT_SS10, 1);

#endif
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
#ifdef SPID_ACTIVE_CHANNEL_0

  /* disable CSI00 */
  TARG_WriteBit(ST0L, SPI_BIT_ST00, 1);

  /* disable CSI00 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE00, 0);

  /* disable INTCSI00 interrupt */
  TARG_WriteBit(MK0H, SPI_BIT_CSIMK00, 1);

  /* clear INTCSI00 interrupt flag */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF00, 0);


#endif

#ifdef SPID_ACTIVE_CHANNEL_1

  /* disable CSI01 */
  TARG_WriteBit(ST0L, SPI_BIT_ST01, 1);

  /* disable CSI01 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE01, 0);

  /* disable INTCSI01 interrupt */
  TARG_WriteBit(MK0H, SPI_BIT_CSIMK01, 1);

  /* clear INTCSI01 interrupt flag */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF01, 0);

#endif

#ifdef SPID_ACTIVE_CHANNEL_2

  /* disable CSI10 */
  TARG_WriteBit(ST1L, SPI_BIT_ST10, 1);

  /* disable CSI10 output */
  TARG_WriteBit(SOE1L, SPI_BIT_SOE10, 0);

  /* disable INTCSI10 interrupt */
  TARG_WriteBit(MK1H, SPI_BIT_CSIMK10, 1);

  /* clear INTCSI10 interrupt flag */
  TARG_WriteBit(IF1H, SPI_BIT_CSIIF10, 0);

#endif
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
#ifdef SPID_ACTIVE_CHANNEL_0

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM10, 0);
  TARG_WriteBit(P1, PORT_BIT_P10, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM12, 0);
  TARG_WriteBit(P1, PORT_BIT_P12, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM11, 1);

  /* clear INTCSI00 interrupt flag */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF00, 0);

  /* enable CSI00 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE00, 1);

  /* enable CSI00 */
  TARG_WriteBit(SS0L, SPI_BIT_SS00, 1);

#endif

#ifdef SPID_ACTIVE_CHANNEL_1

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM74, 0);
  TARG_WriteBit(P7, PORT_BIT_P74, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM13, 0);
  TARG_WriteBit(P1, PORT_BIT_P13, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM75, 1);

  /* clear INTCSI01 interrupt flag */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF01, 0);

  /* enable CSI01 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE01, 1);

  /* enable CSI01 */
  TARG_WriteBit(SS0L, SPI_BIT_SS01, 1);

#endif

#ifdef SPID_ACTIVE_CHANNEL_2

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM13, PORT_BIT_PM133, 0);
  TARG_WriteBit(P13, PORT_BIT_P133, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM13, PORT_BIT_PM131, 0);
  TARG_WriteBit(P13, PORT_BIT_P131, 0);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM13, PORT_BIT_PM132, 1);

  /* clear INTCSI10 interrupt flag */
  TARG_WriteBit(IF1H, SPI_BIT_CSIIF10, 0);

  /* enable CSI10 output */
  TARG_WriteBit(SOE1L, SPI_BIT_SOE10, 1);

  /* enable CSI10 */
  TARG_WriteBit(SS1L, SPI_BIT_SS10, 1);

#endif
}






/*______ P R I V A T E - F U N C T I O N S ___________________________________*/


/*______ L O C A L - F U N C T I O N S _______________________________________*/




#endif /* __REL_RL78_D1A__ */

#endif /* __REL_RL78_D1x__ */

#ifdef __REL_RL78_F1x__

#ifdef __REL_RL78_F12__

/*_____ L O C A L - D E F I N E S ____________________________________________*/

/* Values to set into clock select register SPSm                              */
#define SPID_FX_DIV_BY_0      0
#define SPID_FX_DIV_BY_2     (SPI_MSK_PRS000)
#define SPID_FX_DIV_BY_4     (SPI_MSK_PRS001)
#define SPID_FX_DIV_BY_8     (SPI_MSK_PRS000 + SPI_MSK_PRS001)
#define SPID_FX_DIV_BY_16    (SPI_MSK_PRS002)
#define SPID_FX_DIV_BY_32    (SPI_MSK_PRS000 + SPI_MSK_PRS002)
#define SPID_FX_DIV_BY_64    (SPI_MSK_PRS001 + SPI_MSK_PRS002)
#define SPID_FX_DIV_BY_128   (SPI_MSK_PRS000 + SPI_MSK_PRS001 + SPI_MSK_PRS002)
#define SPID_FX_DIV_BY_256   (SPI_MSK_PRS003)
#define SPID_FX_DIV_BY_512   (SPI_MSK_PRS000 + SPI_MSK_PRS003)
#define SPID_FX_DIV_BY_1024  (SPI_MSK_PRS001 + SPI_MSK_PRS003)
#define SPID_FX_DIV_BY_2048  (SPI_MSK_PRS000 + SPI_MSK_PRS001 + SPI_MSK_PRS003)

/* FREQUENCY DIVISION FACTOR : Fmck(operation clock) / divison factor 2 = Transfer Clock(to be used by the module)*/

#define SPID_FX_OPRCLK_DIV_BY_2        0x0000
#define SPID_FX_OPRCLK_DIV_BY_4        0x0200
#define SPID_FX_OPRCLK_DIV_BY_6        0x0400
#define SPID_FX_OPRCLK_DIV_BY_8        0x0600
#define SPID_FX_OPRCLK_DIV_BY_10       0x0800
#define SPID_FX_OPRCLK_DIV_BY_12       0x0A00
#define SPID_FX_OPRCLK_DIV_BY_14       0x0C00
#define SPID_FX_OPRCLK_DIV_BY_16       0x0E00
#define SPID_FX_OPRCLK_DIV_BY_18       0x1000
#define SPID_FX_OPRCLK_DIV_BY_20       0x1200
#define SPID_FX_OPRCLK_DIV_BY_22       0x1400
#define SPID_FX_OPRCLK_DIV_BY_24       0x1600
#define SPID_FX_OPRCLK_DIV_BY_26       0x1800
#define SPID_FX_OPRCLK_DIV_BY_28       0x1A00
#define SPID_FX_OPRCLK_DIV_BY_30       0x1C00
#define SPID_FX_OPRCLK_DIV_BY_32       0x1E00
#define SPID_FX_OPRCLK_DIV_BY_34       0x2000
#define SPID_FX_OPRCLK_DIV_BY_36       0x2200
#define SPID_FX_OPRCLK_DIV_BY_38       0x2400
#define SPID_FX_OPRCLK_DIV_BY_40       0x2600
#define SPID_FX_OPRCLK_DIV_BY_42       0x2800
#define SPID_FX_OPRCLK_DIV_BY_44       0x2A00
#define SPID_FX_OPRCLK_DIV_BY_46       0x2C00
#define SPID_FX_OPRCLK_DIV_BY_48       0x2E00
#define SPID_FX_OPRCLK_DIV_BY_50       0x3000
#define SPID_FX_OPRCLK_DIV_BY_52       0x3200
#define SPID_FX_OPRCLK_DIV_BY_54       0x3400
#define SPID_FX_OPRCLK_DIV_BY_56       0x3600
#define SPID_FX_OPRCLK_DIV_BY_58       0x3800
#define SPID_FX_OPRCLK_DIV_BY_60       0x3A00
#define SPID_FX_OPRCLK_DIV_BY_62       0x3C00
#define SPID_FX_OPRCLK_DIV_BY_64       0x3E00
#define SPID_FX_OPRCLK_DIV_BY_66       0x4000
#define SPID_FX_OPRCLK_DIV_BY_68       0x4200
#define SPID_FX_OPRCLK_DIV_BY_70       0x4400
#define SPID_FX_OPRCLK_DIV_BY_72       0x4600
#define SPID_FX_OPRCLK_DIV_BY_74       0x4800
#define SPID_FX_OPRCLK_DIV_BY_76       0x4A00
#define SPID_FX_OPRCLK_DIV_BY_78       0x4C00
#define SPID_FX_OPRCLK_DIV_BY_80       0x4E00
#define SPID_FX_OPRCLK_DIV_BY_82       0x5000
#define SPID_FX_OPRCLK_DIV_BY_84       0x5200
#define SPID_FX_OPRCLK_DIV_BY_86       0x5400
#define SPID_FX_OPRCLK_DIV_BY_88       0x5600
#define SPID_FX_OPRCLK_DIV_BY_90       0x5800
#define SPID_FX_OPRCLK_DIV_BY_92       0x5A00
#define SPID_FX_OPRCLK_DIV_BY_94       0x5C00
#define SPID_FX_OPRCLK_DIV_BY_96       0x5E00
#define SPID_FX_OPRCLK_DIV_BY_98       0x6000
#define SPID_FX_OPRCLK_DIV_BY_100      0x6200
#define SPID_FX_OPRCLK_DIV_BY_102      0x6400
#define SPID_FX_OPRCLK_DIV_BY_104      0x6600
#define SPID_FX_OPRCLK_DIV_BY_106      0x6800
#define SPID_FX_OPRCLK_DIV_BY_108      0x6A00
#define SPID_FX_OPRCLK_DIV_BY_110      0x6C00
#define SPID_FX_OPRCLK_DIV_BY_112      0x6E00
#define SPID_FX_OPRCLK_DIV_BY_114      0x7000
#define SPID_FX_OPRCLK_DIV_BY_116      0x7200
#define SPID_FX_OPRCLK_DIV_BY_118      0x7400
#define SPID_FX_OPRCLK_DIV_BY_120      0x7600
#define SPID_FX_OPRCLK_DIV_BY_122      0x7800
#define SPID_FX_OPRCLK_DIV_BY_124      0x7A00
#define SPID_FX_OPRCLK_DIV_BY_126      0x7C00
#define SPID_FX_OPRCLK_DIV_BY_128      0x7E00
#define SPID_FX_OPRCLK_DIV_BY_130      0x8000
#define SPID_FX_OPRCLK_DIV_BY_132      0x8200
#define SPID_FX_OPRCLK_DIV_BY_134      0x8400
#define SPID_FX_OPRCLK_DIV_BY_136      0x8600
#define SPID_FX_OPRCLK_DIV_BY_138      0x8800
#define SPID_FX_OPRCLK_DIV_BY_140      0x8A00
#define SPID_FX_OPRCLK_DIV_BY_142      0x8C00
#define SPID_FX_OPRCLK_DIV_BY_144      0x8E00
#define SPID_FX_OPRCLK_DIV_BY_146      0x9000
#define SPID_FX_OPRCLK_DIV_BY_148      0x9200
#define SPID_FX_OPRCLK_DIV_BY_150      0x9400
#define SPID_FX_OPRCLK_DIV_BY_152      0x9600
#define SPID_FX_OPRCLK_DIV_BY_154      0x9800
#define SPID_FX_OPRCLK_DIV_BY_156      0x9A00
#define SPID_FX_OPRCLK_DIV_BY_158      0x9C00
#define SPID_FX_OPRCLK_DIV_BY_160      0x9E00
#define SPID_FX_OPRCLK_DIV_BY_162      0xA000
#define SPID_FX_OPRCLK_DIV_BY_164      0xA200
#define SPID_FX_OPRCLK_DIV_BY_166      0xA400
#define SPID_FX_OPRCLK_DIV_BY_168      0xA600
#define SPID_FX_OPRCLK_DIV_BY_170      0xA800
#define SPID_FX_OPRCLK_DIV_BY_172      0xAA00
#define SPID_FX_OPRCLK_DIV_BY_174      0xAC00
#define SPID_FX_OPRCLK_DIV_BY_176      0xAE00
#define SPID_FX_OPRCLK_DIV_BY_178      0xB000
#define SPID_FX_OPRCLK_DIV_BY_180      0xB200
#define SPID_FX_OPRCLK_DIV_BY_182      0xB400
#define SPID_FX_OPRCLK_DIV_BY_184      0xB600
#define SPID_FX_OPRCLK_DIV_BY_186      0xB800
#define SPID_FX_OPRCLK_DIV_BY_188      0xBA00
#define SPID_FX_OPRCLK_DIV_BY_190      0xBC00
#define SPID_FX_OPRCLK_DIV_BY_192      0xBE00
#define SPID_FX_OPRCLK_DIV_BY_194      0xC000
#define SPID_FX_OPRCLK_DIV_BY_196      0xC200
#define SPID_FX_OPRCLK_DIV_BY_198      0xC400
#define SPID_FX_OPRCLK_DIV_BY_200      0xC600
#define SPID_FX_OPRCLK_DIV_BY_202      0xC800
#define SPID_FX_OPRCLK_DIV_BY_204      0xCA00
#define SPID_FX_OPRCLK_DIV_BY_206      0xCC00
#define SPID_FX_OPRCLK_DIV_BY_208      0xCE00
#define SPID_FX_OPRCLK_DIV_BY_210      0xD000
#define SPID_FX_OPRCLK_DIV_BY_212      0xD200
#define SPID_FX_OPRCLK_DIV_BY_214      0xD400
#define SPID_FX_OPRCLK_DIV_BY_216      0xD600
#define SPID_FX_OPRCLK_DIV_BY_218      0xD800
#define SPID_FX_OPRCLK_DIV_BY_220      0xDA00
#define SPID_FX_OPRCLK_DIV_BY_222      0xDC00
#define SPID_FX_OPRCLK_DIV_BY_224      0xDE00
#define SPID_FX_OPRCLK_DIV_BY_226      0xE000
#define SPID_FX_OPRCLK_DIV_BY_228      0xE200
#define SPID_FX_OPRCLK_DIV_BY_230      0xE400
#define SPID_FX_OPRCLK_DIV_BY_232      0xE600
#define SPID_FX_OPRCLK_DIV_BY_234      0xE800
#define SPID_FX_OPRCLK_DIV_BY_236      0xEA00
#define SPID_FX_OPRCLK_DIV_BY_238      0xEC00
#define SPID_FX_OPRCLK_DIV_BY_240      0xEE00
#define SPID_FX_OPRCLK_DIV_BY_242      0xF000
#define SPID_FX_OPRCLK_DIV_BY_244      0xF200
#define SPID_FX_OPRCLK_DIV_BY_246      0xF400
#define SPID_FX_OPRCLK_DIV_BY_248      0xF600
#define SPID_FX_OPRCLK_DIV_BY_250      0xF800
#define SPID_FX_OPRCLK_DIV_BY_252      0xFA00
#define SPID_FX_OPRCLK_DIV_BY_254      0xFC00
#define SPID_FX_OPRCLK_DIV_BY_256      0xFE00

/* FREQUENCY DIVISION FACTOR : Fmck(operation clock) / divison factor 2 = Transfer Clock(to be used by the module)*/

#define SPID_FX_UNITS_OPRCLK_DIV_BY_1        0x0000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_2        0x0200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_3        0x0400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_4        0x0600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_5        0x0800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_6        0x0A00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_7        0x0C00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_8        0x0E00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_9        0x1000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_10       0x1200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_11       0x1400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_12       0x1600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_13       0x1800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_14       0x1A00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_15       0x1C00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_16       0x1E00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_17       0x2000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_18       0x2200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_19       0x2400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_20       0x2600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_21       0x2800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_22       0x2A00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_23       0x2C00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_24       0x2E00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_25       0x3000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_26       0x3200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_27       0x3400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_28       0x3600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_29       0x3800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_30       0x3A00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_31       0x3C00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_32       0x3E00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_33       0x4000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_34       0x4200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_35       0x4400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_36       0x4600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_37       0x4800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_38       0x4A00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_39       0x4C00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_40       0x4E00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_41       0x5000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_42       0x5200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_43       0x5400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_44       0x5600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_45       0x5800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_46       0x5A00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_47       0x5C00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_48       0x5E00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_49       0x6000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_50       0x6200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_51       0x6400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_52       0x6600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_53       0x6800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_54       0x6A00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_55       0x6C00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_56       0x6E00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_57       0x7000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_58       0x7200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_59       0x7400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_60       0x7600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_61       0x7800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_62       0x7A00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_63       0x7C00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_64       0x7E00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_65       0x8000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_66       0x8200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_67       0x8400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_68       0x8600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_69       0x8800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_70       0x8A00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_71       0x8C00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_72       0x8E00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_73       0x9000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_74       0x9200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_75       0x9400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_76       0x9600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_77       0x9800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_78       0x9A00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_79       0x9C00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_80       0x9E00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_81       0xA000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_82       0xA200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_83       0xA400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_84       0xA600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_85       0xA800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_86       0xAA00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_87       0xAC00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_88       0xAE00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_89       0xB000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_90       0xB200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_91       0xB400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_92       0xB600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_93       0xB800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_94       0xBA00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_95       0xBC00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_96       0xBE00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_97       0xC000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_98       0xC200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_99       0xC400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_100      0xC600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_101      0xC800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_102      0xCA00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_103      0xCC00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_104      0xCE00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_105      0xD000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_106      0xD200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_107      0xD400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_108      0xD600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_109      0xD800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_110      0xDA00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_111      0xDC00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_112      0xDE00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_113      0xE000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_114      0xE200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_115      0xE400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_116      0xE600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_117      0xE800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_118      0xEA00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_119      0xEC00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_120      0xEE00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_121      0xF000
#define SPID_FX_UNITS_OPRCLK_DIV_BY_122      0xF200
#define SPID_FX_UNITS_OPRCLK_DIV_BY_123      0xF400
#define SPID_FX_UNITS_OPRCLK_DIV_BY_124      0xF600
#define SPID_FX_UNITS_OPRCLK_DIV_BY_125      0xF800
#define SPID_FX_UNITS_OPRCLK_DIV_BY_126      0xFA00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_127      0xFC00
#define SPID_FX_UNITS_OPRCLK_DIV_BY_128      0xFE00



/* values to set into SCRmn                                                   */
/* data length selection */
#define SPID_DATA_LENGTH_7_BIT   ((ushort)0x0006)
#define SPID_DATA_LENGTH_8_BIT   ((ushort)0x0007)
#define SPID_DATA_LENGTH_9_BIT   ((ushort)0x0008)
#define SPID_DATA_LENGTH_10_BIT  ((ushort)0x0009)
#define SPID_DATA_LENGTH_11_BIT  ((ushort)0x000a)
#define SPID_DATA_LENGTH_12_BIT  ((ushort)0x000b)
#define SPID_DATA_LENGTH_13_BIT  ((ushort)0x000c)
#define SPID_DATA_LENGTH_14_BIT  ((ushort)0x000d)
#define SPID_DATA_LENGTH_15_BIT  ((ushort)0x000e)
#define SPID_DATA_LENGTH_16_BIT  ((ushort)0x000f)

/* Value to set into mode register SMRmn for Tx/Rx operation */
#define SPID_TX_RX_MODE  SPI_MSK_SMR00

/*______ L O C A L - T Y P E S _______________________________________________*/


/*______ G L O B A L - D A T A _______________________________________________*/


/*______ P R I V A T E - D A T A _____________________________________________*/


/*______ L O C A L - D A T A _________________________________________________*/


/*______ L O C A L - M A C R O S _____________________________________________*/


/*______ I M P O R T - F U N C T I O N S - P R O T O T Y P E S _______________*/


/*______ L O C A L - F U N C T I O N S - P R O T O T Y P E S _________________*/


/*______ G L O B A L - F U N C T I O N S _____________________________________*/

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
#ifdef SPID_ACTIVE_CHANNEL_0

  /* supply SAU0 clock */
  TARG_WriteBit(PER0, SPI_BIT_SAU0EN, 1);
  /* Wait time after PER0 register write */
  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;

  /* Select clock speed */
  TARG_SetBitsInShort(SPS0, SPID_CLOCK_SELECTION_CHANNEL_0);

  /* disable CSI00 */
  TARG_WriteBit(ST0L, SPI_BIT_ST00, 1);

  /* disable INTCSI00 interrupt */
  TARG_WriteBit(MK0H, SPI_BIT_CSIMK00, 1);

  /* clear error flag */
  TARG_WriteShort(SIR00, SPI_MSK_OVCT00);

  /* Select mode */
  TARG_ClearBitsInShort(SMR00, SPI_MSK_MD001);
  TARG_ClearBitsInShort(SMR00, SPI_MSK_MD002);

  /* Transmission/reception, no stop bit, LSB start, 8-bit data length,Data-ClockPhase */
  TARG_SetBitsInShort(SCR00, SPI_MSK_DLS000 | SPI_MSK_DLS001);
  TARG_SetBitsInShort(SCR00, SPID_DATA_LENGTH_SELECTION_CHANNEL_0);
  TARG_SetBitsInShort(SCR00, (SPI_MSK_RXE00 | SPI_MSK_TXE00 | SPID_DATA_CLOCK_PHASE_CHANNEL_0));
  TARG_ClearBitsInShort(SCR00, SPI_MSK_DIR00);

  /* set second divide register */
  TARG_WriteShort(SDR00, SPID_OPERATION_CLOCK_DIVFAC_CH_0);

  /* output CSI00 clock value 1, output CSI00 data value 0 */
  TARG_ClearBitsInShort(SO0, SPI_MSK_SO00);
  TARG_SetBitsInShort(SO0, SPI_MSK_CKO00);

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM5, PORT_BIT_PM55, 0);
  TARG_WriteBit(P5, PORT_BIT_P55, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM17, 0);
  TARG_WriteBit(P1, PORT_BIT_P17, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM16, 1);

  /* Set the It flag for the first time */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF00, 0);

  /* enable CSI00 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE00, 1);

  /* enable CSI00 */
  TARG_WriteBit(SS0L, SPI_BIT_SS00, 1);
#endif

#ifdef SPID_ACTIVE_CHANNEL_1

  /* supply SAU0 clock */
  TARG_WriteBit(PER0, SPI_BIT_SAU0EN, 1);
  /* Wait time after PER0 register write */
  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;

  /* Select clock speed */
  TARG_SetBitsInShort(SPS0, SPID_CLOCK_SELECTION_CHANNEL_1);

  /* disable CSI01 */
  TARG_WriteBit(ST0L, SPI_BIT_ST01, 1);

  /* disable INTCSI01 interrupt */
  TARG_WriteBit(MK0H, SPI_BIT_CSIMK01, 1);

  /* clear error flag */
  TARG_WriteShort(SIR01, SPI_MSK_OVCT01);

  /* Select mode */
  TARG_ClearBitsInShort(SMR01, SPI_MSK_MD011);
  TARG_ClearBitsInShort(SMR01, SPI_MSK_MD012);

  /* Transmission/reception, no stop bit, LSB start, 8-bit data length,Data-ClockPhase */
  TARG_SetBitsInShort(SCR01, SPI_MSK_DLS010 | SPI_MSK_DLS011);
  TARG_SetBitsInShort(SCR01, SPID_DATA_LENGTH_SELECTION_CHANNEL_1);
  TARG_SetBitsInShort(SCR01, (SPI_MSK_RXE01 | SPI_MSK_TXE01 | SPID_DATA_CLOCK_PHASE_CHANNEL_1));
  TARG_ClearBitsInShort(SCR01, SPI_MSK_DIR01);

  /* set second divide register */
  TARG_WriteShort(SDR01, SPID_OPERATION_CLOCK_DIVFAC_CH_1);

  /* output CSI01 clock value 1, output CSI01 data value 0 */
  TARG_ClearBitsInShort(SO0, SPI_MSK_SO01);
  TARG_SetBitsInShort(SO0, SPI_MSK_CKO01);

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM75, 0);
  TARG_WriteBit(P7, PORT_BIT_P75, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM73, 0);
  TARG_WriteBit(P7, PORT_BIT_P73, 0);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM74, 1);

  /* Set the It flag for the first time */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF01, 0);

  /* enable CSI01 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE01, 1);

  /* enable CSI01 */

  TARG_WriteBit(SS0L, SPI_BIT_SS01, 1);
#endif

#ifdef SPID_ACTIVE_CHANNEL_2

  /* supply SAU0 clock */
  TARG_WriteBit(PER0, SPI_BIT_SAU0EN, 1);
  /* Wait time after PER0 register write */
  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;

  /* Select clock speed */
  TARG_SetBitsInShort(SPS0, SPID_CLOCK_SELECTION_CHANNEL_2);

  /* disable CSI10 */
  TARG_WriteBit(ST0L, SPI_BIT_ST02, 1);

  /* disable INTCSI10 interrupt */
  TARG_WriteBit(MK1L, SPI_BIT_CSIMK10, 1);

  /* clear error flag */
  TARG_WriteShort(SIR02, SPI_MSK_OVCT02);

  /* Select mode */
  TARG_ClearBitsInShort(SMR02, SPI_MSK_MD021);
  TARG_ClearBitsInShort(SMR02, SPI_MSK_MD022);

  /* Transmission/reception, no stop bit, LSB start, 8-bit data length,Data-ClockPhase */
  TARG_SetBitsInShort(SCR02, SPI_MSK_DLS020 | SPI_MSK_DLS021);
  TARG_SetBitsInShort(SCR02, SPID_DATA_LENGTH_SELECTION_CHANNEL_2);
  TARG_SetBitsInShort(SCR02, (SPI_MSK_RXE02 | SPI_MSK_TXE02 | SPID_DATA_CLOCK_PHASE_CHANNEL_2));
  TARG_ClearBitsInShort(SCR02, SPI_MSK_DIR02);

  /* set second divide register */
  TARG_WriteShort(SDR02, SPID_OPERATION_CLOCK_DIVFAC_CH_2);

  /* output CSI10 clock value 1, output CSI10 data value 0 */
  TARG_ClearBitsInShort(SO0, SPI_MSK_SO02);
  TARG_SetBitsInShort(SO0, SPI_MSK_CKO02);

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM0, PORT_BIT_PM04, 0);
  TARG_WriteBit(P0, PORT_BIT_P04, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM0, PORT_BIT_PM02, 0);
  TARG_WriteBit(P0, PORT_BIT_P02, 0);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM0, PORT_BIT_PM03, 1);

  /* Set the It flag for the first time */
  TARG_WriteBit(IF1L, SPI_BIT_CSIIF10, 0);

  /* enable CSI10 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE02, 1);

  /* enable CSI10 */
  TARG_WriteBit(SS0L, SPI_BIT_SS02, 1);

#endif

#ifdef SPID_ACTIVE_CHANNEL_3

  /* supply SAU0 clock */
  TARG_WriteBit(PER0, SPI_BIT_SAU0EN, 1);
  /* Wait time after PER0 register write */
  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;

  /* Select clock speed */
  TARG_SetBitsInShort(SPS0, SPID_CLOCK_SELECTION_CHANNEL_3);

  /* disable CSI11 */
  TARG_WriteBit(ST0L, SPI_BIT_ST03, 1);

  /* disable INTCSI11 interrupt */
  TARG_WriteBit(MK1L, SPI_BIT_CSIMK11, 1);

  /* clear error flag */
  TARG_WriteShort(SIR03, SPI_MSK_OVCT03);

  /* Select mode */
  TARG_ClearBitsInShort(SMR03, SPI_MSK_MD031);
  TARG_ClearBitsInShort(SMR03, SPI_MSK_MD032);

  /* Transmission/reception, no stop bit, LSB start, 8-bit data length,Data-ClockPhase */
  TARG_SetBitsInShort(SCR03, SPI_MSK_DLS030 | SPI_MSK_DLS031);
  TARG_SetBitsInShort(SCR03, SPID_DATA_LENGTH_SELECTION_CHANNEL_3);
  TARG_SetBitsInShort(SCR03, (SPI_MSK_RXE03 | SPI_MSK_TXE03| SPID_DATA_CLOCK_PHASE_CHANNEL_3));
  TARG_ClearBitsInShort(SCR03, SPI_MSK_DIR03);

  /* set second divide register */
  TARG_WriteShort(SDR03, SPID_OPERATION_CLOCK_DIVFAC_CH_3);

  /* output CSI11 clock value 1, output CSI11 data value 0 */
  TARG_ClearBitsInShort(SO0, SPI_MSK_SO03);
  TARG_SetBitsInShort(SO0, SPI_MSK_CKO03);

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM3, PORT_BIT_PM30, 0);
  TARG_WriteBit(P3, PORT_BIT_P30, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM5, PORT_BIT_PM51, 0);
  TARG_WriteBit(P5, PORT_BIT_P51, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM5, PORT_BIT_PM50, 1);

  /* Set the It flag for the first time */
  TARG_WriteBit(IF1L, SPI_BIT_CSIIF11, 0);

  /* enable CSI00 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE03, 1);

  /* enable CSI00 */
  TARG_WriteBit(SS0L, SPI_BIT_SS03, 1);
#endif

#ifdef SPID_ACTIVE_CHANNEL_4

  /* supply SAU1 clock */
  TARG_WriteBit(PER0, SPI_BIT_SAU1EN, 1);
  /* Wait time after PER0 register write */
  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;

  /* Select clock speed */
  TARG_SetBitsInShort(SPS1, SPID_CLOCK_SELECTION_CHANNEL_4);

  /* disable CSI20 */
  TARG_WriteBit(ST1L, SPI_BIT_ST10, 1);

  /* disable INTCSI20 interrupt */
  TARG_WriteBit(MK0H, SPI_BIT_CSIMK20, 1);

  /* clear error flag */
  TARG_WriteShort(SIR10, SPI_MSK_OVCT10);

  /* Select mode */
  TARG_ClearBitsInShort(SMR10, SPI_MSK_MD101);
  TARG_ClearBitsInShort(SMR10, SPI_MSK_MD102);

  /* Transmission/reception, no stop bit, LSB start, 8-bit data length,Data-ClockPhase */
  TARG_SetBitsInShort(SCR10, SPI_MSK_DLS100 | SPI_MSK_DLS101);
  TARG_SetBitsInShort(SCR10, SPID_DATA_LENGTH_SELECTION_CHANNEL_4);
  TARG_SetBitsInShort(SCR10, (SPI_MSK_RXE10 | SPI_MSK_TXE10 | SPID_DATA_CLOCK_PHASE_CHANNEL_4));
  TARG_ClearBitsInShort(SCR10, SPI_MSK_DIR10);

  /* set second divide register */
  TARG_WriteShort(SDR10, SPID_OPERATION_CLOCK_DIVFAC_CH_4);

  /* output CSI20 clock value 1, output CSI20 data value 0 */
  TARG_ClearBitsInShort(SO1, SPI_MSK_SO10);
  TARG_SetBitsInShort(SO1, SPI_MSK_CKO10);

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM15, 0);
  TARG_WriteBit(P1, PORT_BIT_P15, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM13, 0);
  TARG_WriteBit(P1, PORT_BIT_P13, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM14, 1);

  /* Set the It flag for the first time */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF20, 0);

  /* enable CSI00 output */
  TARG_WriteBit(SOE1L, SPI_BIT_SOE10, 1);

  /* enable CSI00 */
  TARG_WriteBit(SS1L, SPI_BIT_SS10, 1);
#endif

#ifdef SPID_ACTIVE_CHANNEL_5

  /* supply SAU1 clock */
  TARG_WriteBit(PER0, SPI_BIT_SAU1EN, 1);
  /* Wait time after PER0 register write */
  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;

  /* Select clock speed */
  TARG_SetBitsInShort(SPS1, SPID_CLOCK_SELECTION_CHANNEL_5);

  /* disable CSI21 */
  TARG_WriteBit(ST1L, SPI_BIT_ST11, 1);

  /* disable INTCSI21 interrupt */
  TARG_WriteBit(MK0H, SPI_BIT_CSIMK21, 1);

  /* clear error flag */
  TARG_WriteShort(SIR11, SPI_MSK_OVCT11);

  /* Select mode */
  TARG_ClearBitsInShort(SMR11, SPI_MSK_MD111);
  TARG_ClearBitsInShort(SMR11, SPI_MSK_MD112);

  /* Transmission/reception, no stop bit, LSB start, 8-bit data length,Data-ClockPhase */
  TARG_SetBitsInShort(SCR11, SPI_MSK_DLS110 | SPI_MSK_DLS111);
  TARG_SetBitsInShort(SCR11, SPID_DATA_LENGTH_SELECTION_CHANNEL_5);
  TARG_SetBitsInShort(SCR11, (SPI_MSK_RXE11 | SPI_MSK_TXE11 | SPID_DATA_CLOCK_PHASE_CHANNEL_5));
  TARG_ClearBitsInShort(SCR11, SPI_MSK_DIR11);

  /* set second divide register */
  TARG_WriteShort(SDR11, SPID_OPERATION_CLOCK_DIVFAC_CH_5);

  /* output CSI21 clock value 1, output CSI21 data value 0 */
  TARG_ClearBitsInShort(SO1, SPI_MSK_SO11);
  TARG_SetBitsInShort(SO1, SPI_MSK_CKO11);

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM70, 0);
  TARG_WriteBit(P7, PORT_BIT_P70, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM72, 0);
  TARG_WriteBit(P7, PORT_BIT_P72, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM71, 1);

  /* Set the It flag for the first time */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF21, 0);

  /* enable CSI00 output */
  TARG_WriteBit(SOE1L, SPI_BIT_SOE11, 1);

  /* enable CSI00 */
  TARG_WriteBit(SS1L, SPI_BIT_SS11, 1);
#endif

#ifdef SPID_ACTIVE_CHANNEL_6

  /* supply SAUS clock */
  TARG_WriteBit(PERX, SPI_BIT_SAUSEN, 1);
  /* Wait time after PER0 register write */
  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;

  /* Select clock speed */
  TARG_SetBitsInShort(SPSS, SPID_CLOCK_SELECTION_CHANNEL_6);

  /* disable CSIS0 */
  TARG_WriteBit(STSL, SPI_BIT_STS0, 1);

  /* disable INTCSIS0 interrupt */
  TARG_WriteBit(MK1H, SPI_BIT_CSIMKS0, 1);

  /* clear error flag */
  TARG_WriteShort(SIRS0, SPI_MSK_OVCTS0);

  /* Select mode */
  TARG_ClearBitsInShort(SMRS0, SPI_MSK_MDS01);
  TARG_ClearBitsInShort(SMRS0, SPI_MSK_MDS02);

  /* Transmission/reception, no stop bit, MSB start, n-bit data length ,Data-ClockPhase*/
  /*TARG_SetBitsInShort(SCRS0, SPI_MSK_DLSS00 | SPI_MSK_DLSS01);*/
  TARG_ClearBitsInShort(SCRS0, SPID_DATA_LENGTH_16_BIT);
  TARG_SetBitsInShort(SCRS0, SPID_DATA_LENGTH_SELECTION_CHANNEL_6);
  TARG_SetBitsInShort(SCRS0, (SPI_MSK_RXES0 | SPI_MSK_TXES0 | SPID_DATA_CLOCK_PHASE_CHANNEL_6));
  TARG_ClearBitsInShort(SCRS0, SPI_MSK_DIRS0);

  /* set second divide register */
  TARG_WriteShort(SDRS0, SPID_OPERATION_CLOCK_DIVFAC_CH_6);

  /* output CSIS0 clock value 1, output CSIS0 data value 0 */
  TARG_ClearBitsInShort(SOS, SPI_MSK_SOS0);
  TARG_SetBitsInShort(SOS, SPI_MSK_CKOS0);

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM10, 1);
  TARG_WriteBit(P1, PORT_BIT_P10, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM12, 1);
  TARG_WriteBit(P1, PORT_BIT_P12, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM11, 1);

  TARG_ClearBits(PMX0,PORT_MSK_PMX0);

  TARG_ClearBits(PMX1,PORT_MSK_PMX1);

  /* Set the It flag for the first time */
  TARG_WriteBit(IF1H, SPI_BIT_CSIIFS0, 0);

  /* enable CSI00 output */
  TARG_WriteBit(SOESL, SPI_BIT_SOES0, 1);

  /* enable CSI00 */
  TARG_WriteBit(SSSL, SPI_BIT_SSS0, 1);
#endif

#ifdef SPID_ACTIVE_CHANNEL_7

  /* supply SAUS clock */
  TARG_WriteBit(PERX, SPI_BIT_SAUSEN, 1);
  /* Wait time after PER0 register write */
  __NOP__;
  __NOP__;
  __NOP__;
  __NOP__;

  /* Select clock speed */
  TARG_SetBitsInShort(SPSS, SPID_CLOCK_SELECTION_CHANNEL_7);

  /* disable CSIS1 */
  TARG_WriteBit(STSL, SPI_BIT_STS1, 1);

  /* disable INTCSIS1 interrupt */
  TARG_WriteBit(MK1H, SPI_BIT_CSIMKS1, 1);

  /* clear error flag */
  TARG_WriteShort(SIRS1, SPI_MSK_OVCTS1);

  /* Select mode */
  TARG_ClearBitsInShort(SMRS1, SPI_MSK_MDS11);
  TARG_ClearBitsInShort(SMRS1, SPI_MSK_MDS12);

  /* Transmission/reception, no stop bit, LSB start, 8-bit data length,Data-ClockPhase */
  TARG_SetBitsInShort(SCRS1, SPI_MSK_DLSS10 | SPI_MSK_DLSS11);
  TARG_SetBitsInShort(SCRS1, SPID_DATA_LENGTH_SELECTION_CHANNEL_7);
  TARG_SetBitsInShort(SCRS1, (SPI_MSK_RXES1 | SPI_MSK_TXES1 | SPID_DATA_CLOCK_PHASE_CHANNEL_7));
  TARG_ClearBitsInShort(SCRS1, SPI_MSK_DIRS1);

  /* set second divide register */
  TARG_WriteShort(SDRS1, SPID_OPERATION_CLOCK_DIVFAC_CH_7);

  /* output CSIS1 clock value 1, output CSIS1 data value 0 */
  TARG_ClearBitsInShort(SOS, SPI_MSK_SOS1);
  TARG_SetBitsInShort(SOS, SPI_MSK_CKOS1);

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM5, PORT_BIT_PM55, 0);
  TARG_WriteBit(P5, PORT_BIT_P55, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM5, PORT_BIT_PM53, 0);
  TARG_WriteBit(P5, PORT_BIT_P53, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM5, PORT_BIT_PM54, 1);

  /* Set the It flag for the first time */
  TARG_WriteBit(IF1H, SPI_BIT_CSIIFS1, 0);

  /* enable CSI00 output */
  TARG_WriteBit(SOESL, SPI_BIT_SOES1, 1);

  /* enable CSI00 */
  TARG_WriteBit(SSSL, SPI_BIT_SSS1, 1);
#endif

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
#ifdef SPID_ACTIVE_CHANNEL_0

  /* disable CSI00 */
  TARG_WriteBit(ST0L, SPI_BIT_ST00, 1);

  /* disable CSI00 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE00, 0);

  /* disable INTCSI00 interrupt */
  TARG_WriteBit(MK0H, SPI_BIT_CSIMK00, 1);

  /* clear INTCSI00 interrupt flag */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF00, 0);

#endif

#ifdef SPID_ACTIVE_CHANNEL_1

  /* disable CSI01 */
  TARG_WriteBit(ST0L, SPI_BIT_ST01, 1);

  /* disable CSI01 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE01, 0);

  /* disable INTCSI01 interrupt */
  TARG_WriteBit(MK0H, SPI_BIT_CSIMK01, 1);

  /* clear INTCSI01 interrupt flag */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF01, 0);

#endif

#ifdef SPID_ACTIVE_CHANNEL_2

  /* disable CSI10 */
  TARG_WriteBit(ST0L, SPI_BIT_ST02, 1);

  /* disable CSI10 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE02, 0);

  /* disable INTCSI10 interrupt */
  TARG_WriteBit(MK1L, SPI_BIT_CSIMK10, 1);

  /* clear INTCSI10 interrupt flag */
  TARG_WriteBit(IF1L, SPI_BIT_CSIIF10, 0);

#endif

#ifdef SPID_ACTIVE_CHANNEL_3

  /* disable CSI11 */
  TARG_WriteBit(ST0L, SPI_BIT_ST03, 1);

  /* disable CSI11 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE03, 0);

  /* disable INTCSI11 interrupt */
  TARG_WriteBit(MK1L, SPI_BIT_CSIMK11, 1);

  /* clear INTCSI11 interrupt flag */
  TARG_WriteBit(IF1L, SPI_BIT_CSIIF11, 0);

#endif

#ifdef SPID_ACTIVE_CHANNEL_4

  /* disable CSI20 */
  TARG_WriteBit(ST1L, SPI_BIT_ST10, 1);

  /* disable CSI20 output */
  TARG_WriteBit(SOE1L, SPI_BIT_SOE10, 0);

  /* disable INTCSI20 interrupt */
  TARG_WriteBit(MK0H, SPI_BIT_CSIMK20, 1);

  /* clear INTCSI20 interrupt flag */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF20, 0);

#endif

#ifdef SPID_ACTIVE_CHANNEL_5

  /* disable CSI21 */
  TARG_WriteBit(ST1L, SPI_BIT_ST11, 1);

  /* disable CSI21 output */
  TARG_WriteBit(SOE1L, SPI_BIT_SOE11, 0);

  /* disable INTCSI21 interrupt */
  TARG_WriteBit(MK0H, SPI_BIT_CSIMK21, 1);

  /* clear INTCSI21 interrupt flag */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF21, 0);

#endif

#ifdef SPID_ACTIVE_CHANNEL_6

  /* disable CSIS0 */
  TARG_WriteBit(STSL, SPI_BIT_STS0, 1);

  /* disable CSIS0 output */
  TARG_WriteBit(SOESL, SPI_BIT_SOES0, 0);

  /* disable INTCSIS0 interrupt */
  TARG_WriteBit(MK1H, SPI_BIT_CSIMKS0, 1);

  /* clear INTCSIS0 interrupt flag */
  TARG_WriteBit(IF1H, SPI_BIT_CSIIFS0, 0);

#endif

#ifdef SPID_ACTIVE_CHANNEL_7

  /* disable CSIS1 */
  TARG_WriteBit(STSL, SPI_BIT_STS1, 1);

  /* disable CSIS1 output */
  TARG_WriteBit(SOESL, SPI_BIT_SOES1, 0);

  /* disable INTCSIS1 interrupt */
  TARG_WriteBit(MK1H, SPI_BIT_CSIMKS1, 1);

  /* clear INTCSIS1 interrupt flag */
  TARG_WriteBit(IF1H, SPI_BIT_CSIIFS1, 0);

#endif

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
#ifdef SPID_ACTIVE_CHANNEL_0

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM5, PORT_BIT_PM55, 0);
  TARG_WriteBit(P5, PORT_BIT_P55, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM17, 0);
  TARG_WriteBit(P1, PORT_BIT_P17, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM16, 1);

  /* clear INTCSI00 interrupt flag */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF00, 0);

  /* enable CSI00 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE00, 1);

  /* enable CSI00 */
  TARG_WriteBit(SS0L, SPI_BIT_SS00, 1);

#endif

#ifdef SPID_ACTIVE_CHANNEL_1

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM75, 0);
  TARG_WriteBit(P7, PORT_BIT_P75, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM73, 0);
  TARG_WriteBit(P7, PORT_BIT_P73, 0);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM74, 1);

  /* clear INTCSI01 interrupt flag */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF01, 0);

  /* enable CSI01 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE01, 1);

  /* enable CSI01 */
  TARG_WriteBit(SS0L, SPI_BIT_SS01, 1);

#endif

#ifdef SPID_ACTIVE_CHANNEL_2

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM0, PORT_BIT_PM04, 0);
  TARG_WriteBit(P0, PORT_BIT_P04, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM0, PORT_BIT_PM02, 0);
  TARG_WriteBit(P0, PORT_BIT_P02, 0);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM0, PORT_BIT_PM03, 1);

  /* clear INTCSI10 interrupt flag */
  TARG_WriteBit(IF1L, SPI_BIT_CSIIF10, 0);

  /* enable CSI10 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE02, 1);

  /* enable CSI10 */
  TARG_WriteBit(SS0L, SPI_BIT_SS02, 1);

#endif

#ifdef SPID_ACTIVE_CHANNEL_3

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM3, PORT_BIT_PM30, 0);
  TARG_WriteBit(P3, PORT_BIT_P30, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM5, PORT_BIT_PM51, 0);
  TARG_WriteBit(P5, PORT_BIT_P51, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM5, PORT_BIT_PM50, 1);

  /* clear INTCSI11 interrupt flag */
  TARG_WriteBit(IF1L, SPI_BIT_CSIIF11, 0);

  /* enable CSI11 output */
  TARG_WriteBit(SOE0L, SPI_BIT_SOE03, 1);

  /* enable CSI11 */
  TARG_WriteBit(SS0L, SPI_BIT_SS03, 1);

#endif

#ifdef SPID_ACTIVE_CHANNEL_4

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM15, 0);
  TARG_WriteBit(P1, PORT_BIT_P15, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM13, 0);
  TARG_WriteBit(P1, PORT_BIT_P13, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM14, 1);

  /* clear INTCSI20 interrupt flag */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF20, 0);

  /* enable CSI20 output */
  TARG_WriteBit(SOE1L, SPI_BIT_SOE10, 1);

  /* enable CSI20 */
  TARG_WriteBit(SS1L, SPI_BIT_SS10, 1);

#endif

#ifdef SPID_ACTIVE_CHANNEL_5

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM70, 0);
  TARG_WriteBit(P7, PORT_BIT_P70, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM72, 0);
  TARG_WriteBit(P7, PORT_BIT_P72, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM7, PORT_BIT_PM71, 1);

  /* clear INTCSI21 interrupt flag */
  TARG_WriteBit(IF0H, SPI_BIT_CSIIF21, 0);

  /* enable CSI21 output */
  TARG_WriteBit(SOE1L, SPI_BIT_SOE11, 1);

  /* enable CSI21 */
  TARG_WriteBit(SS1L, SPI_BIT_SS11, 1);

#endif

#ifdef SPID_ACTIVE_CHANNEL_6

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM10, 1);
  TARG_WriteBit(P1, PORT_BIT_P10, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM12, 1);
  TARG_WriteBit(P1, PORT_BIT_P12, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM1, PORT_BIT_PM11, 1);

  /* clear INTCSIS0 interrupt flag */
  TARG_WriteBit(IF1H, SPI_BIT_CSIIFS0, 0);

  /* enable CSIS0 output */
  TARG_WriteBit(SOESL, SPI_BIT_SOES0, 1);

  /* enable CSIS0 */
  TARG_WriteBit(SSSL, SPI_BIT_SSS0, 1);

#endif

#ifdef SPID_ACTIVE_CHANNEL_7

  /* Set the SCK pin port mode */
  TARG_WriteBit(PM5, PORT_BIT_PM55, 0);
  TARG_WriteBit(P5, PORT_BIT_P55, 1);

  /* Set the SO pin port mode */
  TARG_WriteBit(PM5, PORT_BIT_PM53, 0);
  TARG_WriteBit(P5, PORT_BIT_P53, 1);

  /* Set the SI pin port mode */
  TARG_WriteBit(PM5, PORT_BIT_PM54, 1);

  /* clear INTCSIS1 interrupt flag */
  TARG_WriteBit(IF1H, SPI_BIT_CSIIFS1, 0);

  /* enable CSIS1 output */
  TARG_WriteBit(SOESL, SPI_BIT_SOES1, 1);

  /* enable CSIS1 */
  TARG_WriteBit(SSSL, SPI_BIT_SSS1, 1);

#endif

}

#endif /* __REL_RL78_F12__ */

#endif /* __REL_RL78_F1x__ */

#endif /* __REL_RL78__ */

/*_____ E N D _____ (spid.c) _________________________________________________*/
