/******************************************************************************/
/*@F_NAME:           iodd.h                                                   */
/*@F_PURPOSE:        Public interface for IODD module                         */
/*@F_CREATED_BY:     Yanbin SHEN                                              */
/*@F_CREATION_DATE:  Jun/22/2020                                              */
/*@F_LANGUAGE :      ANSI C                                                   */
/*@F_MPROC_TYPE:     Cypress Traveo II series                                 */
/********************************************** (C) Copyright 2020 Marelli ****/

/*
* \defgroup group_IODD_macro Macro
* \defgroup group_IODD_functions Functions
* \{
*   \defgroup group_IODD_functions_init       Initialization Functions
*   \defgroup group_IODD_functions_gpio       GPIO Functions
*   \defgroup group_IODD_functions_sio        SIO Functions
*   \defgroup group_IODD_functions_interrupt  Port Interrupt Functions
* \}
* \defgroup group_IODD_data_structures Data structures
* \defgroup group_IODD_enums Enumerated types
*/

#ifndef IODD_TV2_H
#define IODD_TV2_H

#if defined(__CY_TV2__)

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"

/*port / bit mask name and library function definition*/
#include "iodd_priv_tv2.h"

/*______ G L O B A L - D E F I N E S _________________________________________*/

/** \addtogroup group_IODD_macro
* \{
*/

/** Driver major version */
#define IODD_DRV_VERSION_MAJOR       0

/** Driver minor version */
#define IODD_DRV_VERSION_MINOR       1

#define IODD_HIGH ((ubyte) 1)
#define IODD_LOW  ((ubyte) 0)

#define IODD_ENABLE ((ubyte) 1)
#define IODD_DISABLE ((ubyte)0)

/** \} group_IODD_macro */


/** \cond INTERNAL */

/* General Constants */
#define IODD_PRT_HALF                      CY_GPIO_PRT_HALF       /**< Half-way point of a GPIO port */
#define IODD_PRT_DEINIT                    CY_GPIO_PRT_DEINIT     /**< De-init value for port registers */
        
/* GPIO Masks */        
#define IODD_HSIOM_MASK                    CY_GPIO_HSIOM_MASK                     /**< HSIOM selection mask */
#define IODD_OUT_MASK                      CY_GPIO_OUT_MASK                       /**< Single pin mask for OUT register */
#define IODD_IN_MASK                       CY_GPIO_IN_MASK                        /**< Single pin mask for IN register */
#define IODD_CFG_DM_MASK                   CY_GPIO_CFG_DM_MASK                    /**< Single pin mask for drive mode in CFG register */
#define IODD_CFG_IN_VTRIP_SEL_MASK         CY_GPIO_CFG_IN_VTRIP_SEL_MASK          /**< Single pin mask for VTRIP selection in CFG IN register */
#define IODD_CFG_OUT_SLOW_MASK             CY_GPIO_CFG_OUT_SLOW_MASK              /**< Single pin mask for slew rate in CFG OUT register */
#define IODD_CFG_OUT_DRIVE_SEL_MASK        CY_GPIO_CFG_OUT_DRIVE_SEL_MASK         /**< Single pin mask for drive strength in CFG OUT register */
#define IODD_CFG_OUT2_DRIVE_SEL_TRIM_MASK  CY_GPIO_CFG_OUT2_DRIVE_SEL_TRIM_MASK   /**< Single pin mask for drive select trim in CFG OUT2 register */
#define IODD_INTR_STATUS_MASK              CY_GPIO_INTR_STATUS_MASK               /**< Single pin mask for interrupt status in INTR register */
#define IODD_INTR_EN_MASK                  CY_GPIO_INTR_EN_MASK                   /**< Single pin mask for interrupt status in INTR register */
#define IODD_INTR_MASKED_MASK              CY_GPIO_INTR_MASKED_MASK               /**< Single pin mask for masked interrupt status in INTR_MASKED register */
#define IODD_INTR_SET_MASK                 CY_GPIO_INTR_SET_MASK                  /**< Single pin mask for setting the interrupt in INTR_MASK register */
#define IODD_INTR_EDGE_MASK                CY_GPIO_INTR_EDGE_MASK                 /**< Single pin mask for interrupt edge type in INTR_EDGE register */
#define IODD_INTR_FLT_EDGE_MASK            CY_GPIO_INTR_FLT_EDGE_MASK             /**< Single pin mask for setting filtered interrupt */

/* Bit offsets for port pin */
#define IODD_HSIOM_OFFSET                  CY_GPIO_HSIOM_OFFSET           /**< Port pin bits offset for HSIOM */
#define IODD_DRIVE_MODE_OFFSET             CY_GPIO_DRIVE_MODE_OFFSET      /**< Port pin bits offset for Drive mode */
#define IODD_INBUF_OFFSET                  CY_GPIO_INBUF_OFFSET           /**< Port pin bits offset for input buffer */
#define IODD_INTR_CFG_OFFSET               CY_GPIO_INTR_CFG_OFFSET        /**< Port pin bits offset for interrupt config */
#define IODD_CFG_SIO_OFFSET                CY_GPIO_CFG_SIO_OFFSET         /**< Port pin bits offset for SIO config */
#define IODD_CFG_OUT_DRIVE_OFFSET          CY_GPIO_CFG_OUT_DRIVE_OFFSET   /**< Port pin bits offset for drive strength */

/* Bit offset multipliers for port pin */
#define IODD_DRIVE_TRIM_OFFSET_MULT        CY_GPIO_DRIVE_TRIM_OFFSET_MULT     /**< Port pin bits offset multiplier for drive strength trim value */

/* Bit offsets for register bits */
#define IODD_CFG_OUT_DRIVE_REG_OFFSET      CY_GPIO_CFG_OUT_DRIVE_REG_OFFSET   /**< Register bits offset for drive strength function */
#define IODD_INTR_FILT_REG_OFFSET          CY_GPIO_INTR_FILT_REG_OFFSET       /**< Register bits offset for filtered interrupt config function */

#define IODD_ZERO   CY_GPIO_ZERO      /**< Constant zero */

/** \endcond */


/***************************************
*        Function Constants
***************************************/

/**
* \addtogroup group_IODD_macro
* \{
*/

/**
* \defgroup group_IODD_driveModes Pin drive mode
* \{
* Constants to be used for setting the drive mode of the pin.
*/
#define IODD_DM_ANALOG                CY_GPIO_DM_ANALOG                /**< \brief Analog High-Z. Input buffer off */
#define IODD_DM_PULLUP_IN_OFF         CY_GPIO_DM_PULLUP_IN_OFF         /**< \brief Resistive Pull-Up. Input buffer off */
#define IODD_DM_PULLDOWN_IN_OFF       CY_GPIO_DM_PULLDOWN_IN_OFF       /**< \brief Resistive Pull-Down. Input buffer off */
#define IODD_DM_OD_DRIVESLOW_IN_OFF   CY_GPIO_DM_OD_DRIVESLOW_IN_OFF   /**< \brief Open Drain, Drives Low. Input buffer off */
#define IODD_DM_OD_DRIVESHIGH_IN_OFF  CY_GPIO_DM_OD_DRIVESHIGH_IN_OFF  /**< \brief Open Drain, Drives High. Input buffer off */
#define IODD_DM_STRONG_IN_OFF         CY_GPIO_DM_STRONG_IN_OFF         /**< \brief Strong Drive. Input buffer off */
#define IODD_DM_PULLUP_DOWN_IN_OFF    CY_GPIO_DM_PULLUP_DOWN_IN_OFF    /**< \brief Resistive Pull-Up/Down. Input buffer off */
#define IODD_DM_HIGHZ                 CY_GPIO_DM_HIGHZ                 /**< \brief Digital High-Z. Input buffer on */
#define IODD_DM_PULLUP                CY_GPIO_DM_PULLUP                /**< \brief Resistive Pull-Up. Input buffer on */
#define IODD_DM_PULLDOWN              CY_GPIO_DM_PULLDOWN              /**< \brief Resistive Pull-Down. Input buffer on */
#define IODD_DM_OD_DRIVESLOW          CY_GPIO_DM_OD_DRIVESLOW          /**< \brief Open Drain, Drives Low. Input buffer on */
#define IODD_DM_OD_DRIVESHIGH         CY_GPIO_DM_OD_DRIVESHIGH         /**< \brief Open Drain, Drives High. Input buffer on */
#define IODD_DM_STRONG                CY_GPIO_DM_STRONG                /**< \brief Strong Drive. Input buffer on */
#define IODD_DM_PULLUP_DOWN           CY_GPIO_DM_PULLUP_DOWN           /**< \brief Resistive Pull-Up/Down. Input buffer on */
/** \} */

/**
* \defgroup group_IODD_vtrip Voltage trip mode
* \{
* Constants to be used for setting the voltage trip type on the pin.
*/
#define IODD_VTRIP_CMOS              CY_GPIO_VTRIP_CMOS  /**< \brief Input buffer compatible with CMOS and I2C interfaces */
#define IODD_VTRIP_TTL               CY_GPIO_VTRIP_TTL   /**< \brief Input buffer compatible with TTL and MediaLB interfaces */
/** \} */          

/**
* \defgroup group_IODD_vtrip_auto Voltage trip mode
* \{
* Constants to be used for setting the input buffer mode (trip points and hysteresis) for GPIO5V.
*/
#define IODD_VTRIP_DIS_AUTO    CY_GPIO_VTRIP_DIS_AUTO  /**< \brief Input buffer is not compatible with automotive */
#define IODD_VTRIP_SEL_AUTO    CY_GPIO_VTRIP_SEL_AUTO  /**< \brief Input buffer is compatible with automotive */
/** \} */

/**
* \defgroup group_IODD_slewRate Slew Rate Mode
* \{
* Constants to be used for setting the slew rate of the pin.
*/
#define IODD_SLEW_FAST     CY_GPIO_SLEW_FAST  /**< \brief Fast slew rate */
#define IODD_SLEW_SLOW     CY_GPIO_SLEW_SLOW  /**< \brief Slow slew rate */
/** \} */

/**
* \defgroup group_IODD_driveStrength Pin drive strength
* \{
* Constants to be used for setting the drive strength of the pin.
*/
#define IODD_DRIVE_FULL    CY_GPIO_DRIVE_FULL /**< \brief Full drive strength: Max drive current */
#define IODD_DRIVE_1_2     CY_GPIO_DRIVE_1_2  /**< \brief 1/2 drive strength: 1/2 drive current */
#define IODD_DRIVE_1_4     CY_GPIO_DRIVE_1_4  /**< \brief 1/4 drive strength: 1/4 drive current */
/** \} */

/**
* \defgroup group_IODD_driveStrength_trim Pin drive strength
* \{
* Constants to be used for setting the drive strength trim value of the pin.
*/
#define IODD_DRIVE_STRENGTH_DEFAULT     CY_GPIO_DRIVE_STRENGTH_DEFAULT /**< \brief Default drive strength: 50 ohm */
#define IODD_DRIVE_STRENGTH_120OHM      CY_GPIO_DRIVE_STRENGTH_120OHM  /**< \brief Default drive strength: 120 ohm */
#define IODD_DRIVE_STRENGTH_90OHM       CY_GPIO_DRIVE_STRENGTH_90OHM   /**< \brief Default drive strength: 90 ohm */
#define IODD_DRIVE_STRENGTH_60OHM       CY_GPIO_DRIVE_STRENGTH_60OHM   /**< \brief Default drive strength: 60 ohm */
#define IODD_DRIVE_STRENGTH_50OHM       CY_GPIO_DRIVE_STRENGTH_50OHM   /**< \brief Default drive strength: 50 ohm */
#define IODD_DRIVE_STRENGTH_30OHM       CY_GPIO_DRIVE_STRENGTH_30OHM   /**< \brief Default drive strength: 30 ohm */
#define IODD_DRIVE_STRENGTH_20OHM       CY_GPIO_DRIVE_STRENGTH_20OHM   /**< \brief Default drive strength: 20 ohm */
#define IODD_DRIVE_STRENGTH_15OHM       CY_GPIO_DRIVE_STRENGTH_15OHM   /**< \brief Default drive strength: 15 ohm */
/** \} */

/**
* \defgroup group_IODD_interruptTrigger Interrupt trigger type
* \{
* Constants to be used for setting the interrupt trigger type on the pin.
*/
#define IODD_INTR_DISABLE    CY_GPIO_INTR_DISABLE  /**< \brief Disable the pin interrupt generation */
#define IODD_INTR_RISING     CY_GPIO_INTR_RISING   /**< \brief Rising-Edge interrupt */
#define IODD_INTR_FALLING    CY_GPIO_INTR_FALLING  /**< \brief Falling-Edge interrupt */
#define IODD_INTR_BOTH       CY_GPIO_INTR_BOTH     /**< \brief Both-Edge interrupt */
/** \} */

/** \} group_IODD_macro */


/*------ Interrupt Sense Control -------------------------------------------- */

#define IODD_IT_FALLING_EDGE(PortName, PinNumber) \
        Iodd_SetInterruptEdge(Iodd_getPortAddr(PortName), PinNumber, IODD_INTR_FALLING);

#define IODD_IT_RISING_EDGE(PortName,PinNumber)  \
        Iodd_SetInterruptEdge(Iodd_getPortAddr(PortName), PinNumber, IODD_INTR_RISING);

#define IODD_IT_BOTH_EDGE(PortName,PinNumber)    \
        Iodd_SetInterruptEdge(Iodd_getPortAddr(PortName), PinNumber, IODD_INTR_BOTH);

#define IODD_IT_DISABLE(PortName,PinNumber) \
        Iodd_SetInterruptEdge(Iodd_getPortAddr(PortName), PinNumber, IODD_INTR_DISABLE);


/*------ Input Pin Mode ----------------------------------------------------- */


/*------ Pull-device control ------------------------------------------------ */


/*------ Input Pull Up Mode ------------------------------------------------- */

/* If a pin is only connected to an analog signal, the input buffer should be 
   disabled to avoid crowbar currents */

/**
 * @brief The digital input buffer provides a high-impedance buffer for the external digital input.
 */
#define Iodd_getPortAddr(PortName) GPIO_PRT##PortName

/**
 * @brief Resistive Pull-Up. Input buffer off
 */
#define IODD_PULL_UP(PortName, PinNumber) \
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_PULLUP_IN_OFF)

/**
 * @brief Resistive Pull-Up. Input buffer on
 */
#define IODD_PULL_UP_WITH_INPUT_BUFFER(PortName, PinNumber) \
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_PULLUP)

/**
 * @brief Digital High-Z. Input buffer on 
 */
#define IODD_NO_PULL_UP(PortName, PinNumber) \
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_HIGHZ)

/**
 * @brief Resistive Pull-Down. Input buffer off
 */
#define IODD_PULL_DOWN(PortName, PinNumber) \
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_PULLUP_DOWN_IN_OFF)

/**
 * @brief Resistive Pull-Down. Input buffer on
 */
#define IODD_PULL_DOWN_WITH_INPUT_BUFFER(PortName, PinNumber) \
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_PULLUP_DOWN)

#define IODD_NO_PULL_OPTION(PortName, PinNumber) \

/**
 * @brief  Resistive Pull-Up/Down. Input buffer off
 */
#define IODD_PULL_UP_DOWN(PortName, PinNumber) \
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_PULLUP_DOWN_IN_OFF)

/**
 * @brief  Resistive Pull-Up/Down. Input buffer on
 */
#define IODD_PULL_UP_DOWN_WITH_INPUT_BUFFER(PortName, PinNumber) \
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_PULLUP_DOWN)

/*------ Output Open Drain State -------------------------------------------- */

/**
 * @brief Open Drain, Drives HIGH. Input buffer off
 */
#define IODD_OPEN_DRAIN_DRIVES_HIGH(PortName, PinNumber)\
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_PULLUP_DOWN_IN_OFF)

/**
 * @brief Open Drain, Drives High. Input buffer on
 */
#define IODD_OPEN_DRAIN_DRIVES_HIGH_WITH_INPUT_BUFFER(PortName, PinNumber)\
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_PULLUP_DOWN)

/**
 * @brief Open Drain, Drives Low. Input buffer off
 */
#define IODD_OPEN_DRAIN_DRIVES_LOW(PortName, PinNumber)\
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_OD_DRIVESLOW_IN_OFF)

/**
 * @brief Open Drain, Drives Low. Input buffer on
 */
#define IODD_OPEN_DRAIN_DRIVES_LOW_WITH_INPUT_BUFFER(PortName, PinNumber)\
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_OD_DRIVESLOW)

/*------ Output High-Impedance selection ------------------------------------ */

/**
 * @brief Analog High-Z. In
 */
#define IODD_ANALOG_HIGH_IMPEDANCE(PortName, PinNumber) \
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_ANALOG)

/**
 * @brief Digital High-Z. Input buffer on
 */
#define IODD_DIGITAL_HIGH_IMPEDANCE(PortName, PinNumber) \
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_HIGHZ)

/*------ Strong Drive Mode -------------------------------------------------- */

/**
 * @brief Strong Drive. Input buffer off
 */
#define IODD_STRONG_DRIVE_OUTPUT(PortName, PinNumber)\
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_STRONG_IN_OFF)

/**
 * @brief Strong Drive. Input buffer on
 */
#define IODD_STRONG_DRIVE_WITH_INPUT_BUFFER(PortName, PinNumber)\
        Iodd_SetDrivemode(Iodd_getPortAddr(PortName), PinNumber, IODD_DM_STRONG)

/*______ G L O B A L - T Y P E S _____________________________________________*/


/*______ G L O B A L - M A C R O S ___________________________________________*/

/*----------------------------------------------------------------------------*/
/* Name : IODD_PinSetUpInput                                                  */
/* Role : Set up a microcontroler pin to work as an input                     */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*                                                                            */
/*   - PinMode     IN, use mode of the pin                                    */
/*                                    Cypress Traveo II                       */
/*                                         [IODD_IT_DISABLE,                  */
/*                                          IODD_IT_RISING_EDGE,              */
/*                                          IODD_IT_FALLING_EDGE,             */
/*                                          IODD_IT_BOTH_EDGE]                */
/*   - PullUpState IN, state of the pull-up on the pin if the pin has         */
/*                     a pull-up                                              */
/*                                    Cypress Traveo II                       */
/*                                      [IODD_PULL_UP,                        */
/*                                       IODD_NO_PULL_UP                      */
/*                                       IODD_PULL_DOWN,                      */
/*                                       IODD_PULL_UP_DOWN                    */
/*                                       IODD_PULL_UP_WITH_INPUT_BUFFER,      */
/*                                       IODD_PULL_DOWN_WITH_INPUT_BUFFER,    */
/*                                       IODD_PULL_UP_DOWN_WITH_INPUT_BUFFER] */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_PinSetUpInput(PortName,                         \
                           PinNumber,                        \
                           PinMode,                          \
                           PullUpState)                      \
        Iodd_Write(Iodd_getPortAddr(PortName), PinNumber, IODD_LOW); \
        Iodd_SetHSIOM(Iodd_getPortAddr(PortName), PinNumber, 0);     \
        PullUpState(PortName, PinNumber);          \
        PinMode(PortName, PinNumber)



#define IODD_PinSetUpExtIntWakeup(PortName,\
                                  PinNumber,\
                                  IntSource,\
                                  DectionType,\
                                  PinMode) \
        PinMode(PortName, PinNumber)\
        Iodd_SetFilter(Iodd_getPortAddr(PortName), PinNumber)\
        Iodd_ClearInterrupt(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/* Name : IODD_SetPinDirectionIn                                              */
/* Role : Set direction register to set pin in input                          */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinDirectionIn(PortName,                     \
                               PinNumber)                    \
        Iodd_Write(Iodd_getPortAddr(PortName), PinNumber, IODD_LOW); \
        Iodd_SetVtrip(Iodd_getPortAddr(PortName), PinNumber, IODD_VTRIP_TTL);\
        Iodd_SetVtripAuto(Iodd_getPortAddr(PortName), PinNumber, IODD_VTRIP_SEL_AUTO)

/*----------------------------------------------------------------------------*/
/* Name : IODD_SetPinDirectionOut                                             */
/* Role : Set direction register to set pin in output                         */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [set up the pin as requested]                                          */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinDirectionOut(PortName,  \
                                PinNumber) \
        Iodd_Write(Iodd_getPortAddr(PortName), PinNumber, IODD_LOW);\
        Iodd_SetHSIOM(Iodd_getPortAddr(PortName), PinNumber, 0)
        


/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPullUpData                                                   */
/*Role : Set the pull-up state                                                */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the pull-up state]                                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPullUpData(PortName,PinNumber) \
        IODD_PULL_UP(PortName, PinNumber)


/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPullDownData                                                 */
/*Role : Set the pull-down state                                              */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the pull-up state]                                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPullDownData(PortName,PinNumber) \
        IODD_PULL_DOWN(PortName, PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_GetDriveMode                                                    */
/*Role : Configures the pin output buffer drive mode and input buffer enable  */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - Vtrip OUT, Pin output buffer drive mode. Options are detailed in        */
/*              \ref group_gpio_driveMode macros                              */
/*                                                                            */
/*Constraints : This function modifies a port register in a read-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ get Connects the specified High speed Input Ouput Multiplexer(HSIOM)  */
/*      selection to the pin.]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetDriveMode(PortName, PinNumber) \
        Iodd_GetDrivemode(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetVoltageThresholdMode                                         */
/*Role : Configures the GPIO pin input buffer voltage threshold mode.         */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - Vtrip OUT, Pin voltage threshold mode. Options are detailed in          */
/*              \ref group_gpio_vtrip macros                                  */
/*                                                                            */
/*Constraints : This function modifies a port register in a read-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ setting voltage threshold for pin.]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetVoltageThresholdMode(PortName, PinNumber, Mode)\
        Iodd_SetVtrip(Iodd_getPortAddr(PortName), PinNumber, Mode)

/*----------------------------------------------------------------------------*/
/*Name : IODD_GetVoltageThresholdMode                                         */
/*Role : get the voltage threshold mode config                                */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - Vtrip OUT, Pin voltage threshold mode. Options are detailed in          */
/*              \ref group_gpio_vtrip macros                                  */
/*                                                                            */
/*Constraints : This function modifies a port register in a read-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ Returns the pin input buffer voltage threshold mode.]                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetVoltageThresholdMode(PortName, PinNumber)\
        Iodd_GetVtrip(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetVtripAutomotiveMode                                          */
/*Role : Configures the input buffer voltage compatible mode                  */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - Mode IN, \ref group_gpio_vtrip macros                                   */
/*                                                                            */
/*Constraints : This function modifies a port register in a read-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*  [ Configures the GPIO pin input buffer for automotive compatible or not.] */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetVtripAutomotiveMode(PortName, PinNumber, Mode)\
        Iodd_SetVtripAuto(Iodd_getPortAddr(PortName), PinNumber, Mode)

/*----------------------------------------------------------------------------*/
/*Name : IODD_GetVtripAutomotiveMode                                          */
/*Role : get the input buffer voltage compatible mode                         */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - VtripAuto OUT, \ref group_gpio_vtrip macros                             */
/*                                                                            */
/*Constraints : This function modifies a port register in a read-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ Returns the pin input buffer voltage whether it is automotive         */
/*      compatible or not]                                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetVtripAutomotiveMode(PortName, PinNumber)\
        Iodd_GetVtripAuto(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetSlewRateMode                                                 */
/*Role : Configures the pin output buffer slew rate.                          */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - SlewRate  IN, \ref group_gpio_slewRate macros                           */
/*                                    [IODD_SLEW_FAST]                        */
/*                                    [IODD_SLEW_SLOW]                        */
/*                                                                            */
/*Constraints : This function modifies a port register in a read-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ setting pin output buffer slew rate ]                                 */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetSlewRateMode(PortName, PinNumber, Mode)\
        Iodd_SetSlewRate(Iodd_getPortAddr(PortName), PinNumber, Mode)

/*----------------------------------------------------------------------------*/
/*Name : IODD_GetSlewRateMode                                                 */
/*Role : get the pin output buffer slew rate                                  */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - SlewRate OUT, \ref group_gpio_slewRate macros                           */
/*                                    [IODD_SLEW_FAST]                        */
/*                                    [IODD_SLEW_SLOW]                        */
/*                                                                            */
/*Constraints : This function modifies a port register in a read-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ Returns the pin output buffer slew rate]                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetSlewRateMode(PortName, PinNumber)\
        Iodd_GetSlewRateMode(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetDriveStrength                                                */
/*Role : Configures the pin output buffer drive strength.                     */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - DriveStrength IN,  Pin drive strength                                   */
/*                                    [GPIO_DRIVE_FULL]                       */
/*                                    [GPIO_DRIVE_1_2 ]                       */
/*                                    [GPIO_DRIVE_1_4 ]                       */
/*                                    [GPIO_DRIVE_1_8 ]                       */
/*                                                                            */
/*                                                                            */
/*Constraints : This function modifies a port register in a read-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ setting drive strength for Pin output buffer ]                        */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetDriveStrength(PortName, PinNumber, Strength)\
        Iodd_SetDriveSel(Iodd_getPortAddr(PortName), PinNumber, Strength)

/*----------------------------------------------------------------------------*/
/*Name : IODD_GetDriveStrength                                                */
/*Role : get the pin output buffer drive strength                             */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - DriveStrength OUT, Pin drive strength                                   */
/*                                    [GPIO_DRIVE_FULL]                       */
/*                                    [GPIO_DRIVE_1_2 ]                       */
/*                                    [GPIO_DRIVE_1_4 ]                       */
/*                                    [GPIO_DRIVE_1_8 ]                       */
/*                                                                            */
/*Constraints : This function modifies a port register in a read-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ Returns the pin output buffer drive strength. ]                       */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetDriveStrength(PortName, PinNumber)\
        Iodd_GetDriveSel(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/* Name : IODD_EnableIrq                                                      */
/* Role : Enable interrupt request                                            */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [ Configures the pin interrupt to be forwarded to the CPU NVIC]        */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_EnableIrq(PortName, PinNumber)\
        Iodd_SetInterruptMask(Iodd_getPortAddr(PortName), PinNumber, IODD_ENABLE)

/*----------------------------------------------------------------------------*/
/* Name : IODD_DisableIrq                                                     */
/* Role : Disable interrupt request                                           */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [ Configures the pin interrupt not to be forwarded to the CPU NVIC]    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_DisableIrq(PortName, PinNumber)\
        Iodd_SetInterruptMask(Iodd_getPortAddr(PortName), PinNumber, IODD_DISABLE)



/*----------------------------------------------------------------------------*/
/* Name : IODD_ReadStatusIrq                                                  */
/* Role : Read interrupt request flag                                         */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [read the interrupt status]                                            */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_ReadStatusIrq(PortName, PinNumber)\
        Iodd_GetInterruptStatus(Iodd_getPortAddr(PortName), PinNumber)
       

/*----------------------------------------------------------------------------*/
/* Name : IODD_ClearStatusIrq                                                 */
/* Role : Clear interrupt request flag                                        */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/* Pre-condition : -                                                          */
/* Constraints : -                                                            */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Clear the interrupt status]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_ClearStatusIrq(PortName, PinNumber)\
        Iodd_ClearInterrupt(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/* Name : IODD_SetGlitchFilterIrq                                             */
/* Role : Configures which pin on the port connects to the port filter.       */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/* Pre-condition : -                                                          */
/* Constraints : Only one Pin of Port can be set glitch filter to Interrupt   */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Clear the interrupt status]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_SetGlitchFilterIrq(PortName, PinNumber)\
        Iodd_SetFilter(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/* Name : IODD_GetGlitchFilterIrq                                             */
/* Role : Clear interrupt request flag                                        */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber OUT, pin number of pin :                                      */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/* Pre-condition : -                                                          */
/* Constraints : Only one Pin of Port can be set glitch filter to Interrupt   */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Clear the interrupt status]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_GetGlitchFilterIrq(PortName)\
        Iodd_GetFilter(Iodd_getPortAddr(PortName))

/*----------------------------------------------------------------------------*/
/* Name : IODD_GetInterruptEdge                                               */
/* Role : Get the current setting pin detect interrupt edge type              */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - PinMode  OUT, use mode of the pin                                       */
/*                                    Cypress Traveo II                       */
/*                                    [IODD_IT_DISABLE,                       */
/*                                     IODD_IT_RISING_EDGE,                   */
/*                                     IODD_IT_FALLING_EDGE,                  */
/*                                     IODD_IT_BOTH_EDGE]                     */
/* Pre-condition : -                                                          */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Clear the interrupt status]                                           */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_GetInterruptEdge(PortName, PinNumber)\
        Iodd_GetInterruptEdge(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/* Name : IODD_GetInterruptMask                                               */
/* Role : Get Pin interrupt Mask setting flag                                 */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - Mask      OUT                                                           */
/*      0 = Pin interrupt not forwarded to CPU interrupt controller           */
/*      1 = Pin interrupt masked and forwarded to CPU interrupt controller    */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*   [ Returns the state of the pin interrupt mask to determine whether it is */
/*    configured to be forwarded to the CPU interrupt controller.]            */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_GetInterruptMask(PortName, PinNumber)\
        Iodd_GetInterruptMask(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/* Name : IODD_GetInterruptStatusMasked                                       */
/* Role : Get Pin Interrupt status masked                                     */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - Mask      OUT                                                           */
/* 0 = Pin interrupt not detected or not forwarded to CPU interrupt controller*/
/* 1 = Pin interrupt detected and forwarded to CPU interrupt controller       */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Return the pin's current interrupt state after being masked.]         */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/
#define IODD_GetInterruptStatusMasked(PortName, PinNumber)\
        Iodd_GetInterruptStatusMasked(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/* Name : IODD_SetSoftwareInterruptTrigger                                    */
/* Role : setting a Pin to generate trigger interrupt request                 */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/* Behavior :                                                                 */
/*   DO                                                                       */
/*     [Force a pin interrupt to trigger.]                                    */
/*   OD                                                                       */
/*----------------------------------------------------------------------------*/       
#define IODD_SetSoftwareInterruptTrigger(PortName, PinNumber)\
        Iodd_SetSwInterrupt(Iodd_getPortAddr(PortName), PinNumber)


/*----------------------------------------------------------------------------*/
/*Name : IODD_PinSetUpOutput                                                  */
/*Role : Set up a microcontroler pin to work as an output                     */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - DriveMode IN, for Cypress Traveo II                                     */
/*                       [IODD_STRONG_DRIVE_OUTPUT                            */
/*                        IODD_OPEN_DRAIN_DRIVES_HIGH                         */
/*                        IODD_OPEN_DRAIN_DRIVES_HIGH_WITH_INPUT_BUFFER       */
/*                        IODD_OPEN_DRAIN_DRIVES_LOW                          */
/*                        IODD_OPEN_DRAIN_DRIVES_LOW_WITH_INPUT_BUFFER]       */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set up the pin as requested]                                           */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_PinSetUpOutput(PortName,\
                            PinNumber,\
                            DriveMode)\
        Iodd_Write(Iodd_getPortAddr(PortName), PinNumber, IODD_LOW);\
        Iodd_SetHSIOM(Iodd_getPortAddr(PortName), PinNumber, 0);\
        DriveMode(PortName, PinNumber)


/*----------------------------------------------------------------------------*/
/*Name : IODD_SetOpenDrainData                                                */
/*Role : Set the open-drain state                                             */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - State     IN, requested bit state [IODD_HIGH, IODD_LOW]                 */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the open-drain state]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetOpenDrainData(PortName,PinNumber,State) \
        do\
        {\
          if(IODD_LOW == State)\
          {\
            IODD_OPEN_DRAIN_DRIVES_LOW(PortName, PinNumber);\
          }\
          else\
          {\
            IODD_OPEN_DRAIN_DRIVES_LOW(PortName, PinNumber);\
          }\
        } while (0)
        


/*#define IODD_SetOpenDrainData(PortName,PinNumber) */


/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPinStatus                                                    */
/*Role : Get the status of the pin                                            */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - State     OUT, state of the pin (IODD_HIGH, IODD_LOW)                   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [get the pin state]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetPinStatus(PortName, \
                          PinNumber) \
        Iodd_Read(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_GetPinData                                                      */
/*Role : Get the pin state                                                    */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - State     OUT, state of the pin (IODD_HIGH, IODD_LOW)                   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [get the pin state]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetPinData(PortName,\
                        PinNumber) \
        Iodd_Read(Iodd_getPortAddr(PortName), PinNumber)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPinData                                                      */
/*Role : Set a state on the pin                                               */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*                                                                            */
/*  - State     IN, requested output state of the pin [IODD_HIGH, IODD_LOW]   */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested state on the pin]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinData(PortName,\
                        PinNumber,\
                        State) \
        Iodd_Write(Iodd_getPortAddr(PortName), PinNumber, State)

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPinStatusInverse                                             */
/*Role : Set a inverse state on the pin                                       */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the inverse state on the pin]                                      */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPinStatusInverse(PortName, PinNumber)\
        Iodd_Inv(Iodd_getPortAddr(PortName), PinNumber)


/*----------------------------------------------------------------------------*/
/*Name : IODD_ReadBytePortIn                                                  */
/*Role : Read an 8-bits port                                                  */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints : can not read an output port                                   */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the requested port]                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_ReadBytePortIn(PortName) \

/*----------------------------------------------------------------------------*/
/*Name : IODD_ReadShortPortIn                                                 */
/*Role : Read an 16-bits port                                                 */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*                       JP0 is 8 bit accessible                              */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port direction]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_ReadShortPortIn(PortName) \

/*----------------------------------------------------------------------------*/
/*Name : IODD_WriteBytePortOut                                                */
/*Role : Write into 8-bits port                                               */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - Value     IN, ubyte Value                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_WriteBytePortOut(PortName,Value) \

/*----------------------------------------------------------------------------*/
/*Name : IODD_WriteShortPortOut                                               */
/*Role : Write into 16-bits port                                              */
/*Interface :                                                                 */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*                       JP0 is 8 bit accessible                              */
/*  - Value     IN, ushort value                                              */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port direction]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_WriteShortPortOut(PortName,Value) \

/*----------------------------------------------------------------------------*/
/*Name : IODD_WriteBytePortDirection                                          */
/*Role : Change 8-bits port direction                                         */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - Value     IN, ubyte value                                               */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port direction]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_WriteBytePortDirection(PortName, Value) \

/*----------------------------------------------------------------------------*/
/*Name : IODD_WriteShortPortDirection                                         */
/*Role : Change 16-bits port direction                                        */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - Value     IN, ushort value                                              */
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [write the requested port direction]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_WriteShortPortDirection(PortName,\
                                    Value) \


/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPortDirectionIn                                              */
/*Role : Set 8-bits port to operate as an input                               */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested port in input]                                       */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPortDirectionIn(PortName)\

/*----------------------------------------------------------------------------*/
/*Name : IODD_SetPortDirectionOut                                             */
/*Role : Set 8-bits port to operate as an output                              */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*Pre-condition : -                                                           */
/*Constraints :  -                                                            */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set the requested port in output]                                      */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_SetPortDirectionOut(PortName) \

/*----------------------------------------------------------------------------*/
/*Name : IODD_ALTER_FUNC                                                      */
/*Role : Configures the HSIOM connection to the pin                           */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - AlternatePin IN, en_hsiom_sel_t type pin definition                     */
/*                                                                            */
/*Pre-condition : -                                                           */
/*Constraints : This function modifies a port register in a read-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ Connects the specified High speed Input Ouput Multiplexer(HSIOM)      */
/*      selection to the pin.]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_ALTER_FUNC(PortName,PinNumber, AlternatePin) \
        Iodd_SetHSIOM(Iodd_getPortAddr(PortName), PinNumber, AlternatePin)  /* \ref en_hsiom_sel_t*/

/*----------------------------------------------------------------------------*/
/*Name : IODD_GetAlternateMode                                                */
/*Role : Configures the HSIOM connection to the pin                           */
/*Interface :                                                                 */
/*  - PortName  IN, name of port for :                                        */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,...]*/
/*  - PinNumber IN, pin number of pin :                                       */
/*                                    Cypress Traveo II                       */
/*                                    [0,1,2,3,4,5,6,7]                       */
/*  - AlternateMode OUT, en_hsiom_sel_t type pin definition                   */
/*                                                                            */
/*Constraints : This function modifies a port register in a read-modify-write */
/*            operation. It is not thread safe as the resource is shared among*/
/*            multiple pins on a port.                                        */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ get Connects the specified High speed Input Ouput Multiplexer(HSIOM)  */
/*      selection to the pin.]                                                */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define IODD_GetAlternateMode(PortName, PinNumber)\
        Iodd_GetHSIOM(Iodd_getPortAddr(PortName), PinNumber)

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/


#endif /* defined(__CY_TV2__) */
#endif /* IODD_TV2_H */

    /*______ E N D _____ (iodd.h) ________________________________________________*/

