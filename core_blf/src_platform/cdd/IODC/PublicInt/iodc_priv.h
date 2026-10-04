/******************************************************************************/
/*@F_NAME:           iodc_priv.h                                              */
/*@F_PURPOSE:        local header file of iodc module                         */
/*@F_CREATED_BY:     M. Sergent                                               */
/*@F_CREATION_DATE:  19/09/2000                                               */
/*@F_MPROC_TYPE:     target independent                                       */
/************************************** (C) Copyright 2010 Magneti Marelli ****/

#ifndef IODC_PRIV_H
#define IODC_PRIV_H


/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "syst.h"
#include "iodc_config.h"
#include "iodc.h"
#include "iodd.h"


/*______ L O C A L - D E F I N E _____________________________________________*/


/*______ L O C A L - T Y P E S________________________________________________*/

typedef struct
{
  ubyte  EventType;
  void   (*const EventCallBackFct)(void);
} IODC_InputEventManagement_t;


/*______ L O C A L - D A T A _________________________________________________*/


/*______ L O C A L - M A C R O S _____________________________________________*/

/*----------------------------------------------------------------------------*/
/*Name : Iodc_CreateDirectInput                                               */
/*Role : Create a direct input                                                */
/*Interface :                                                                 */
/*  - IN : number of input                                                    */
/*  - IN : logical state (POSITIVE : normal HW input, NEGATIVE : inverted HW  */
/*           input)                                                           */
/*  - IN : name of pin used                                                   */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*  - use a macro for a static configuration                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [create the direct input]                                               */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC Iodc_CreateDirectInput                                                 */
/* (                                                                          */
/* IN : VirtualId                                                             */
/* )                                                                          */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*DO                                                                          */
/*   [ use define of configuration with IODD_PinSetUpInput service to create  */
/*   the direct input ]                                                       */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#define Iodc_CreateDirectInput(VirtualId)                    \
        IODD_PinSetUpInput(IODC_DirectIn_Port_ ## VirtualId, \
                           IODC_DirectIn_Bit_ ## VirtualId,  \
                           IODC_DirectIn_Irq_ ## VirtualId,  \
                           IODC_DirectIn_PullUp_ ## VirtualId)


/*----------------------------------------------------------------------------*/
/*Name : Iodc_CreateOutput                                                    */
/*Role : Create a output                                                      */
/*Interface :                                                                 */
/*  - IN : number of output                                                   */
/*  - IN : logical state (POSITIVE : normal HW output, NEGATIVE : inverted HW */
/*           output)                                                          */
/*  - IN : name of pin used                                                   */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*  - use a macro for a static configuration                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [create the output]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC Iodc_CreateOutput                                                      */
/* (                                                                          */
/* IN : VirtualId                                                             */
/* )                                                                          */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*DO                                                                          */
/*   [ use define of configuration with IODD_PinSetUpOutput service to create */
/*   the output ]                                                             */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#define Iodc_CreateOutput(VirtualId)                         \
        IODC_SelectCreateType(IODC_GetCreateType(VirtualId), \
                              _CREATE,                       \
                              VirtualId)


/* sub-macros used by Iodc_CreateOutput in function the output type */

#define IODC_GetCreateType(VirtualId) \
        IODC_Out_Type_ ## VirtualId

#define IODC_SelectCreateType(Type, Action, VirtualId) \
        IODC_SetCreateAction(Type, Action, VirtualId)

#define IODC_SetCreateAction(Type, Action, VirtualId ) \
        Type ## Action(VirtualId)

/* direct output setting */
#define IODC_NORMAL_CREATE(VirtualId)                    \
        IODD_PinSetUpOutput(IODC_Out_Port_ ## VirtualId, \
                            IODC_Out_Bit_ ## VirtualId,  \
                            IODC_Out_Drain_ ## VirtualId)

/* direct output setting */
#define IODC_NORMAL_SETUP_REFRESH_CREATE(VirtualId)      \
        IODD_PinSetUpOutput(IODC_Out_Port_ ## VirtualId, \
                            IODC_Out_Bit_ ## VirtualId,  \
                            IODC_Out_Drain_ ## VirtualId)

/* option dependent direct output */
#define IODC_SEL_NORMAL_CREATE(VirtualId)                      \
        {                                                      \
          if (IODC_Out_Option_ ## VirtualId == TRUE)           \
          {                                                    \
            IODD_PinSetUpOutput(IODC_Out_Port_ ## VirtualId,   \
                                IODC_Out_Bit_ ## VirtualId,    \
                                IODC_Out_Drain_ ## VirtualId); \
          }                                                    \
        }

/* Multiplexed, no setting */
#define IODC_BYMATRIX_CREATE(VirtualId)

/* option dependent output */

#define IODC_SEL_BYMATRIX_CREATE(VirtualId)

#define IODC_DYNAMIC_CREATE(VirtualId)                  \
        {                                               \
          if (IODC_Out_Option_ ## VirtualId == TRUE)    \
          {                                             \
            if (IODC_Out_Select_ ## VirtualId == FALSE) \
            {                                           \
              IODC_NORMAL_CREATE(VirtualId);            \
            }                                           \
            else                                        \
            {                                           \
              IODC_BYMATRIX_CREATE(VirtualId);          \
            }                                           \
          }                                             \
        }


/*----------------------------------------------------------------------------*/
/*Name : Iodc_CreateColumnOutput                                              */
/*Role : Create a output to drive the led matrix by column                    */
/*Interface :                                                                 */
/*  - IN : number of output                                                   */
/*  - IN : logical state (POSITIVE : normal HW output, NEGATIVE : inverted HW */
/*           output)                                                          */
/*  - IN : name of pin used                                                   */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*  - use a macro for a static configuration                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [create the output]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC Iodc_CreateColumnOutput                                                */
/* (                                                                          */
/* IN : Id                                                                    */
/* )                                                                          */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*DO                                                                          */
/*   [ use define of configuration with IODD_PinSetUpOutput service to create */
/*   the output to drive the led matrix ]                                     */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#define Iodc_CreateColumnOutput(VirtualId)                     \
        IODD_PinSetUpOutput(IODC_ColumnOut_Port_ ## VirtualId, \
                            IODC_ColumnOut_Bit_ ## VirtualId,  \
                            IODC_ColumnOut_Drain_ ## VirtualId)


/*----------------------------------------------------------------------------*/
/*Name : Iodc_CreateLineOutput                                                */
/*Role : Create a output to drive the led matrix by line if configured        */
/*Interface :                                                                 */
/*  - IN : number of output                                                   */
/*  - IN : logical state (POSITIVE : normal HW output, NEGATIVE : inverted HW */
/*           output)                                                          */
/*  - IN : name of pin used                                                   */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*  - use a macro for a static configuration                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [create the output]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC Iodc_CreateLineOutput                                                  */
/* (                                                                          */
/* IN : VirtualId                                                             */
/* )                                                                          */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*DO                                                                          */
/*   [ use define of configuration with IODD_PinSetUpOutput service to create */
/*   the output to drive the led matrix line ]                                */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#define Iodc_CreateLineOutput(VirtualId)                     \
        IODD_PinSetUpOutput(IODC_LineOut_Port_ ## VirtualId, \
                            IODC_LineOut_Bit_ ## VirtualId,  \
                            IODC_LineOut_Drain_ ## VirtualId)


/*----------------------------------------------------------------------------*/
/*Name : Iodc_CreateColumnOutputInMux                                         */
/*Role : Create a output to drive the input matrix by column                  */
/*Interface :                                                                 */
/*  - IN : number of output                                                   */
/*  - IN : number of matrix where is located the column                       */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*  - use a macro for a static configuration                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [create the output]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC Iodc_CreateColumnOutputInMux                                           */
/* (                                                                          */
/* IN : VirtualId                                                             */
/* IN : MatrixNb                                                              */
/* )                                                                          */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*DO                                                                          */
/*   [ use define of configuration with IODD_PinSetUpOutput service to create */
/*   the output to drive the input matrix 'MatrixNb' ]                        */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#define Iodc_CreateColumnOutputInMux(VirtualId, MatrixNb)                          \
        IODD_PinSetUpOutput(IODC_InMux_Column_Port_ ## VirtualId ## _ ## MatrixNb, \
                            IODC_InMux_Column_Bit_ ## VirtualId ## _ ## MatrixNb,  \
                            IODC_InMux_Column_Drain_ ## VirtualId ## _ ## MatrixNb)


/*----------------------------------------------------------------------------*/
/*Name : Iodc_CreateLineInputInMux                                            */
/*Role : Create a output to drive the led matrix by line if configured        */
/*Interface :                                                                 */
/*  - IN : number of output                                                   */
/*  - IN : number of line where is located the column                         */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*  - use a macro for a static configuration                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [create the output]                                                     */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC Iodc_CreateLineInputInMux                                              */
/* (                                                                          */
/* IN : VirtualId                                                             */
/* IN : MatrixNb                                                              */
/* )                                                                          */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*DO                                                                          */
/*   [ use define of configuration with IODD_PinSetUpInput service to create  */
/*   the input to sample the input matrix line ]                              */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#define Iodc_CreateLineInputInMux(VirtualId, MatrixNb)                          \
        IODD_PinSetUpInput(IODC_InMux_Line_Port_ ## VirtualId ## _ ## MatrixNb, \
                           IODC_InMux_Line_Bit_ ## VirtualId ## _ ## MatrixNb,  \
                           IODC_InMux_Line_Irq_ ## VirtualId ## _ ## MatrixNb,  \
                           IODC_InMux_Line_PullUp_ ## VirtualId ## _ ## MatrixNb)


/*----------------------------------------------------------------------------*/
/*Name : Iodc_ActiveColumn / Iodc_InactiveColumn                              */
/*Role : drive the column of the leds matrix                                  */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*  -                                                                         */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set / clear column state]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define Iodc_ActiveColumn(ColumnId)                       \
        IODD_SetPinData(IODC_ColumnOut_Port_ ## ColumnId, \
                        IODC_ColumnOut_Bit_ ## ColumnId,  \
                        IODC_ColumnOut_Logic_ ## ColumnId)

#define Iodc_InactiveColumn(ColumnId)                     \
        IODD_SetPinData(IODC_ColumnOut_Port_ ## ColumnId, \
                        IODC_ColumnOut_Bit_ ## ColumnId,  \
                        !(IODC_ColumnOut_Logic_ ## ColumnId))


/*----------------------------------------------------------------------------*/
/*Name : Iodc_ActiveLine / Iodc_InactiveLine                                  */
/*Role : drive the line of the leds matrix                                    */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*  -                                                                         */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set / clear column state]                                              */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define Iodc_ActiveLine(LineId)                       \
        IODD_SetPinData(IODC_LineOut_Port_ ## LineId, \
                        IODC_LineOut_Bit_ ## LineId,  \
                        IODC_LineOut_Logic_ ## LineId)

#define Iodc_InactiveLine(LineId)                     \
        IODD_SetPinData(IODC_LineOut_Port_ ## LineId, \
                        IODC_LineOut_Bit_ ## LineId,  \
                        !(IODC_LineOut_Logic_ ## LineId))


#ifdef IODC_INPUT_MATRIX_USED

/*----------------------------------------------------------------------------*/
/*Name : Iodc_ActiveColumn_InMux                                              */
/*Role : drive the column of the input matrix 'MatrixNb'                      */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*  -                                                                         */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [set column state]                                                      */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define Iodc_ActiveColumn_InMux(ColumnId, MatrixNb) \
        Iodc_ActiveColumn ## ColumnId ## _InMux (MatrixNb)

/* Column 0 ***********/
#if IODC_COL_NB_ROTARY_SW_1 == 0

#define Iodc_ActiveColumnIODC_COL_NB_ROTARY_SW_1_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_0_ ## MatrixNb,   \
                        IODC_InMux_Column_Bit_0_ ## MatrixNb,    \
                        IODC_InMux_Column_Logic_0_ ## MatrixNb)

#endif /* IODC_COL_NB_ROTARY_SW_1 == 0 */

#if IODC_COL_NB_ROTARY_SW_2 == 0

#define Iodc_ActiveColumnIODC_COL_NB_ROTARY_SW_2_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_0_ ## MatrixNb,   \
                        IODC_InMux_Column_Bit_0_ ## MatrixNb,    \
                        IODC_InMux_Column_Logic_0_ ## MatrixNb)

#endif /* IODC_COL_NB_ROTARY_SW_2 == 0 */

#if (IODC_COL_NB_ROTARY_SW_1 != 0) || (IODC_COL_NB_ROTARY_SW_2 != 0)

#define Iodc_ActiveColumn0_InMux(MatrixNb)                     \
        IODD_SetPinData(IODC_InMux_Column_Port_0_ ## MatrixNb, \
                        IODC_InMux_Column_Bit_0_ ## MatrixNb,  \
                        IODC_InMux_Column_Logic_0_ ## MatrixNb)

#endif /* (IODC_COL_NB_ROTARY_SW_1 != 0) || (IODC_COL_NB_ROTARY_SW_2 != 0) */

/* Column 1 ***********/
#if IODC_COL_NB_ROTARY_SW_1 == 1

#define Iodc_ActiveColumnIODC_COL_NB_ROTARY_SW_1_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_1_ ## MatrixNb,   \
                        IODC_InMux_Column_Bit_1_ ## MatrixNb,    \
                        IODC_InMux_Column_Logic_1_ ## MatrixNb)

#endif /* IODC_COL_NB_ROTARY_SW_1 == 1 */

#if IODC_COL_NB_ROTARY_SW_2 == 1

#define Iodc_ActiveColumnIODC_COL_NB_ROTARY_SW_2_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_1_ ## MatrixNb,   \
                        IODC_InMux_Column_Bit_1_ ## MatrixNb,    \
                        IODC_InMux_Column_Logic_1_ ## MatrixNb)

#endif /* IODC_COL_NB_ROTARY_SW_2 == 1 */

#if (IODC_COL_NB_ROTARY_SW_1 != 1) || (IODC_COL_NB_ROTARY_SW_2 != 1)

#define Iodc_ActiveColumn1_InMux(MatrixNb)                     \
        IODD_SetPinData(IODC_InMux_Column_Port_1_ ## MatrixNb, \
                        IODC_InMux_Column_Bit_1_ ## MatrixNb,  \
                        IODC_InMux_Column_Logic_1_ ## MatrixNb)

#endif /* IODC_COL_NB_ROTARY_SW_2 == 1 */

/* Column 2 ***********/
#if IODC_COL_NB_ROTARY_SW_1 == 2

#define Iodc_ActiveColumnIODC_COL_NB_ROTARY_SW_1_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_2_ ## MatrixNb,   \
                        IODC_InMux_Column_Bit_2_ ## MatrixNb,    \
                        IODC_InMux_Column_Logic_2_ ## MatrixNb)

#endif /* IODC_COL_NB_ROTARY_SW_1 == 2 */

#if IODC_COL_NB_ROTARY_SW_2 == 2

#define Iodc_ActiveColumnIODC_COL_NB_ROTARY_SW_2_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_2_ ## MatrixNb,   \
                        IODC_InMux_Column_Bit_2_ ## MatrixNb,    \
                        IODC_InMux_Column_Logic_2_ ## MatrixNb)

#endif /* IODC_COL_NB_ROTARY_SW_2 == 2 */

#if (IODC_COL_NB_ROTARY_SW_1 != 2) || (IODC_COL_NB_ROTARY_SW_2 != 2)

#define Iodc_ActiveColumn2_InMux(MatrixNb)                     \
        IODD_SetPinData(IODC_InMux_Column_Port_2_ ## MatrixNb, \
                        IODC_InMux_Column_Bit_2_ ## MatrixNb,  \
                        IODC_InMux_Column_Logic_2_ ## MatrixNb)

#endif /* (IODC_COL_NB_ROTARY_SW_1 != 2) || (IODC_COL_NB_ROTARY_SW_2 != 2) */

/* Column 3 ***********/
#if IODC_COL_NB_ROTARY_SW_1 == 3

#define Iodc_ActiveColumnIODC_COL_NB_ROTARY_SW_1_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_3_ ## MatrixNb,   \
                        IODC_InMux_Column_Bit_3_ ## MatrixNb,    \
                        IODC_InMux_Column_Logic_3_ ## MatrixNb)

#endif /* IODC_COL_NB_ROTARY_SW_1 == 3 */

#if IODC_COL_NB_ROTARY_SW_2 == 3

#define Iodc_ActiveColumnIODC_COL_NB_ROTARY_SW_2_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_3_ ## MatrixNb,   \
                        IODC_InMux_Column_Bit_3_ ## MatrixNb,    \
                        IODC_InMux_Column_Logic_3_ ## MatrixNb)

#endif /* IODC_COL_NB_ROTARY_SW_2 == 3 */

#if (IODC_COL_NB_ROTARY_SW_1 != 3) || (IODC_COL_NB_ROTARY_SW_2 != 3)

#define Iodc_ActiveColumn3_InMux(MatrixNb)                     \
        IODD_SetPinData(IODC_InMux_Column_Port_3_ ## MatrixNb, \
                        IODC_InMux_Column_Bit_3_ ## MatrixNb,  \
                        IODC_InMux_Column_Logic_3_ ## MatrixNb)

#endif /* (IODC_COL_NB_ROTARY_SW_1 != 3) || (IODC_COL_NB_ROTARY_SW_2 != 3) */

/*----------------------------------------------------------------------------*/
/*Name : Iodc_InactiveColumn_InMux1                                           */
/*Role : drive the column of the input matrix 'MatrixNb'                      */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*  -                                                                         */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [ clear column state]                                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
#define Iodc_InactiveColumn_InMux(ColumnId, MatrixNb) \
        Iodc_InactiveColumn ## ColumnId ## _InMux (MatrixNb)

/* Column 0 ***********/
#if IODC_COL_NB_ROTARY_SW_1 == 0

#define Iodc_InactiveColumnIODC_COL_NB_ROTARY_SW_1_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_0_ ## MatrixNb,     \
                        IODC_InMux_Column_Bit_0_ ## MatrixNb,      \
                        !(IODC_InMux_Column_Logic_0_ ## MatrixNb))

#endif /* IODC_COL_NB_ROTARY_SW_1 == 0 */

#if IODC_COL_NB_ROTARY_SW_2 == 0

#define Iodc_InactiveColumnIODC_COL_NB_ROTARY_SW_2_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_0_ ## MatrixNb,     \
                        IODC_InMux_Column_Bit_0_ ## MatrixNb,      \
                        !(IODC_InMux_Column_Logic_0_ ## MatrixNb))

#endif /* IODC_COL_NB_ROTARY_SW_2 == 0 */

#if (IODC_COL_NB_ROTARY_SW_1 != 0) || (IODC_COL_NB_ROTARY_SW_2 != 0)

#define Iodc_InactiveColumn0_InMux(MatrixNb)                   \
        IODD_SetPinData(IODC_InMux_Column_Port_0_ ## MatrixNb, \
                        IODC_InMux_Column_Bit_0_ ## MatrixNb,  \
                        !(IODC_InMux_Column_Logic_0_ ## MatrixNb))

#endif /* (IODC_COL_NB_ROTARY_SW_1 != 0) || (IODC_COL_NB_ROTARY_SW_2 != 0) */

/* Column 1 ***********/
#if IODC_COL_NB_ROTARY_SW_1 == 1

#define Iodc_InactiveColumnIODC_COL_NB_ROTARY_SW_1_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_1_ ## MatrixNb,     \
                        IODC_InMux_Column_Bit_1_ ## MatrixNb,      \
                        !(IODC_InMux_Column_Logic_1_ ## MatrixNb))

#endif /* IODC_COL_NB_ROTARY_SW_1 == 1 */

#if IODC_COL_NB_ROTARY_SW_2 == 1

#define Iodc_InactiveColumnIODC_COL_NB_ROTARY_SW_2_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_1_ ## MatrixNb,     \
                        IODC_InMux_Column_Bit_1_ ## MatrixNb,      \
                        !(IODC_InMux_Column_Logic_1_ ## MatrixNb))

#endif /* IODC_COL_NB_ROTARY_SW_2 == 1 */

#if (IODC_COL_NB_ROTARY_SW_1 != 1) || (IODC_COL_NB_ROTARY_SW_2 != 1)

#define Iodc_InactiveColumn1_InMux(MatrixNb)                   \
        IODD_SetPinData(IODC_InMux_Column_Port_1_ ## MatrixNb, \
                        IODC_InMux_Column_Bit_1_ ## MatrixNb,  \
                        !(IODC_InMux_Column_Logic_1_ ## MatrixNb))

#endif /* (IODC_COL_NB_ROTARY_SW_1 != 1) || (IODC_COL_NB_ROTARY_SW_2 != 1) */

/* Column 2 ***********/
#if IODC_COL_NB_ROTARY_SW_1 == 2

#define Iodc_InactiveColumnIODC_COL_NB_ROTARY_SW_1_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_2_ ## MatrixNb,     \
                        IODC_InMux_Column_Bit_2_ ## MatrixNb,      \
                        !(IODC_InMux_Column_Logic_2_ ## MatrixNb))

#endif /* IODC_COL_NB_ROTARY_SW_1 == 2 */

#if IODC_COL_NB_ROTARY_SW_2 == 2

#define Iodc_InactiveColumnIODC_COL_NB_ROTARY_SW_2_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_2_ ## MatrixNb,     \
                        IODC_InMux_Column_Bit_2_ ## MatrixNb,      \
                        !(IODC_InMux_Column_Logic_2_ ## MatrixNb))

#endif /* IODC_COL_NB_ROTARY_SW_2 == 2 */

#if (IODC_COL_NB_ROTARY_SW_1 != 2) || (IODC_COL_NB_ROTARY_SW_2 != 2)

#define Iodc_InactiveColumn2_InMux(MatrixNb)                   \
        IODD_SetPinData(IODC_InMux_Column_Port_2_ ## MatrixNb, \
                        IODC_InMux_Column_Bit_2_ ## MatrixNb,  \
                        !(IODC_InMux_Column_Logic_2_ ## MatrixNb))

#endif /* (IODC_COL_NB_ROTARY_SW_1 != 2) || (IODC_COL_NB_ROTARY_SW_2 != 2) */

/* Column 3 ***********/
#if IODC_COL_NB_ROTARY_SW_1 == 3

#define Iodc_InactiveColumnIODC_COL_NB_ROTARY_SW_1_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_3_ ## MatrixNb,     \
                        IODC_InMux_Column_Bit_3_ ## MatrixNb,      \
                        !(IODC_InMux_Column_Logic_3_ ## MatrixNb))

#endif /* IODC_COL_NB_ROTARY_SW_1 == 3 */

#if IODC_COL_NB_ROTARY_SW_2 == 3

#define Iodc_InactiveColumnIODC_COL_NB_ROTARY_SW_2_InMux(MatrixNb) \
        IODD_SetPinData(IODC_InMux_Column_Port_3_ ## MatrixNb,     \
                        IODC_InMux_Column_Bit_3_ ## MatrixNb,      \
                        !(IODC_InMux_Column_Logic_3_ ## MatrixNb))

#endif /* IODC_COL_NB_ROTARY_SW_2 == 3 */

#if (IODC_COL_NB_ROTARY_SW_1 != 3) || (IODC_COL_NB_ROTARY_SW_2 != 3)

#define Iodc_InactiveColumn3_InMux(MatrixNb)                   \
        IODD_SetPinData(IODC_InMux_Column_Port_3_ ## MatrixNb, \
                        IODC_InMux_Column_Bit_3_ ## MatrixNb,  \
                        !(IODC_InMux_Column_Logic_3_ ## MatrixNb))

#endif /* (IODC_COL_NB_ROTARY_SW_1 != 3) || (IODC_COL_NB_ROTARY_SW_2 != 3) */


/*----------------------------------------------------------------------------*/
/*Name : Iodc_MatrixLine_acquisition                                          */
/*Role : Read the not filtered state of a input line in matrix                */
/*Interface :                                                                 */
/*  - IN  : number of input                                                   */
/*  - OUT : state of the input (TRUE, FALSE)                                  */
/*Pre-condition : -                                                           */
/*Constraints : -                                                             */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [read the not filtered state of the requested input]                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
/*PROC Iodc_MatrixLine_acquisition                                            */
/*  (                                                                         */
/*  IN : VirtualPinId (UBYTE)                                                 */
/*  OUT : StateOfPin (IODC_ACTIVE, IODC_INACTIVE)                             */
/*  )                                                                         */
/*                                                                            */
/*DATA                                                                        */
/*ATAD                                                                        */
/*                                                                            */
/*DO                                                                          */
/*   [read the not filtered state of the requested line] =                    */
/*   DO                                                                       */
/*     StateOfPin := [ read with IODD_GetPinData service ]                    */
/*     [ return StateOfPin = [ type of logic of VirtualPinId ] ]              */
/*   OD                                                                       */
/*OD                                                                          */
/*----------------------------------------------------------------------------*/
#define Iodc_MatrixLine_acquisition(VirtualId, MatrixNb)                                \
        ((ubyte) ((IODD_GetPinData(IODC_InMux_Line_Port_ ## VirtualId ## _ ## MatrixNb, \
                                   IODC_InMux_Line_Bit_ ## VirtualId ## _ ## MatrixNb)) \
         == (IODC_InMux_Line_Logic_ ## VirtualId ## _ ## MatrixNb))                     \
        )

#endif /* IODC_INPUT_MATRIX_USED */


/*______ P R I V A T E - F U N C T I O N S - P R O T O T Y P E S _____________*/

/*----------------------------------------------------------------------------*/
/*Name : IODC_ConfigureHw                                                     */
/*Role : configure the pin of micro according to define of pin used           */
/*          this function is called by IODC_SystemInit function. So,          */
/*          the configuration of each pin must be write here.                 */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [create the hardware configuration ]                                    */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void IODC_ConfigureHw(void);

/*----------------------------------------------------------------------------*/
/*Name : Iodc_SetupIoRefresh                                                  */
/*Role : Refresh configuration of each pin                                    */
/*       this function is called by IODC_Task function.                       */
/*Interface :                                                                 */
/*Pre-condition : -                                                           */
/*Constraints :                                                               */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [Refresh the hardware configuration ]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void Iodc_SetupIoRefresh(void);

#ifdef __EOL_ENABLE__

/*----------------------------------------------------------------------------*/
/*Name : Iodc_InitEolDigitalInPin                                             */
/*Role : configure the pin of micro according to define of pin used           */
/*          this function is called by EOL module.                            */
/*          So, the configuration of each EOL pin must be write here.         */
/*Interface : none                                                            */
/*Pre-condition : none                                                        */
/*Constraints : none                                                          */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [create the hardware configuration for EOL module]                      */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void Iodc_InitEolDigitalInPin(void);

#endif /* __EOL_ENABLE__ */


#endif /* IODC_PRIV_H */

/*_____END _____ (iodc_priv.h) _______________________________________________*/
