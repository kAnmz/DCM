/******************************************************************************/
/**
* \file       sbcc_priv.h
* \brief      SBC Controller module private header
* \details
*
* \author     Weiwen.CHEN
* \date       25/12/2017
* \par        History:
*
\verbatim
  Version     Author                    Date            Desc
  1.0         Weiwen.CHEN               25/12/2017
\endverbatim
*
*/
/**************** (C) Copyright 2018 Magneti Marelli Guangzhou ****************/

#ifndef SBCC_H
#define SBCC_H
/* _____ I N C L U D E - F I L E S ___________________________________________*/
#include "Platform_Types.h"

/* _____ G L O B A L - D E F I N E ___________________________________________*/
/* COMMAND Masks */
#define Sbcc_BTS_WRITE                          0x00000000U
#define Sbcc_BTS_READ                           0x40000000U
#define Sbcc_BTS_READ_CLR                       0x80000000U
#define Sbcc_BTS_READ_DEV_INFOR                 0xC0000000U

/* Global Status Byte */
#define Sbcc_BTS_GSB_GSBN                       0x80U
#define Sbcc_BTS_GSB_RSTB                       0x40U
#define Sbcc_BTS_GSB_SPIE                       0x20U
#define Sbcc_BTS_GSB_PLE                        0x10U
#define Sbcc_BTS_GSB_FE                         0x08U
#define Sbcc_BTS_GSB_DE                         0x04U
#define Sbcc_BTS_GSB_GW                         0x02U
#define Sbcc_BTS_GSB_FS                         0x01U

// /* Control register address*/
// #define Sbcc_CR1_Addr                           0x01000000U
// #define Sbcc_CR2_Addr                           0x02000000U
// #define Sbcc_CR3_Addr                           0x03000000U
// #define Sbcc_CR4_Addr                           0x04000000U
// #define Sbcc_CR5_Addr                           0x05000000U
// #define Sbcc_CR6_Addr                           0x06000000U
// #define Sbcc_CR7_Addr                           0x07000000U
// #define Sbcc_CR8_Addr                           0x08000000U
// #define Sbcc_CR9_Addr                           0x09000000U
// #define Sbcc_CR10_Addr                          0x0A000000U
// #define Sbcc_CR11_Addr                          0x0B000000U
// #define Sbcc_CR12_Addr                          0x0C000000U
// #define Sbcc_CR13_Addr                          0x0D000000U
// #define Sbcc_CR14_Addr                          0x0E000000U
// #define Sbcc_CR15_Addr                          0x0F000000U
// #define Sbcc_CR16_Addr                          0x10000000U
// #define Sbcc_CR17_Addr                          0x11000000U
// #define Sbcc_CR18_Addr                          0x12000000U
// #define Sbcc_ConfReg_Addr                       0x3F000000U

/* Control register address*/
/* -------- L99DZ300 -----------*/
#define Sbcc_CR1_Addr_DZ300                     0x26000000U  
#define Sbcc_CR2_Addr_DZ300                     0x27000000U
#define Sbcc_CR3_Addr_DZ300                     0x2C000000U
#define Sbcc_CR4_Addr_DZ300                     0x30000000U
#define Sbcc_CR4bis_Addr_DZ300                  0x31000000U
#define Sbcc_CR5_Addr_DZ300                     0x32000000U
#define Sbcc_CR6_Addr_DZ300                     0x33000000U
#define Sbcc_CR7_Addr_DZ300                     0x34000000U
#define Sbcc_CR8_Addr_DZ300                     0x35000000U
#define Sbcc_CR9_Addr_DZ300                     0x36000000U
#define Sbcc_CR10_Addr_DZ300                    0x37000000U
#define Sbcc_CR11_Addr_DZ300                    0x38000000U
#define Sbcc_CR12_Addr_DZ300                    0x39000000U
#define Sbcc_CR13_Addr_DZ300                    0x3A000000U
#define Sbcc_CR14_Addr_DZ300                    0x3B000000U
#define Sbcc_CR15_Addr_DZ300                    0x3C000000U
#define Sbcc_CR16_Addr_DZ300                    0x3D000000U
#define Sbcc_CR17_Addr_DZ300                    0x3E000000U
#define Sbcc_CR18_Addr_DZ300                    0x3F000000U

/* Status register address */
/* -------- L99DZ300 -----------*/
#define Sbcc_SR1_Addr_DZ300                     0x01000000U 
#define Sbcc_SR2_Addr_DZ300                     0x02000000U
#define Sbcc_SR3_Addr_DZ300                     0x03000000U
#define Sbcc_SR4_Addr_DZ300                     0x04000000U
#define Sbcc_SR5_Addr_DZ300                     0x05000000U
#define Sbcc_SR6_Addr_DZ300                     0x06000000U
#define Sbcc_SR7_Addr_DZ300                     0x07000000U
#define Sbcc_SR8_Addr_DZ300                     0x08000000U

/* -------- L99DZ300 CR1 (0x26) -----------*/
#define Sbcc_CR1_CAN_LOOP_EN_DZ300              0x00800000U 
#define Sbcc_CR1_LIN_TXD_TOUT_DZ300             0x00400000U
#define Sbcc_CR1_LIN_WU_CONFIG_DZ300            0x00200000U
#define Sbcc_CR1_ECV_HV_DZ300                   0x00080000U
#define Sbcc_CR1_DISABLE_CP_DITH_DZ300          0x00040000U
#define Sbcc_CR1_CMP_CONFIG_EN_DZ300            0x00020000U
#define Sbcc_CR1_WD_CONFIG_EN_DZ300             0x00010000U
#define Sbcc_CR1_MASK_OL_HS1_DZ300              0x00008000U
#define Sbcc_CR1_MASK_OL_LS1_DZ300              0x00004000U
#define Sbcc_CR1_MASK_TW_DZ300                  0x00002000U
#define Sbcc_CR1_MASK_EC_OL_DZ300               0x00001000U
#define Sbcc_CR1_MASK_OL_DZ300                  0x00000800U
#define Sbcc_CR1_MASK_SPIE_DZ300                0x00000400U
#define Sbcc_CR1_MASK_PLE_DZ300                 0x00000200U
#define Sbcc_CR1_MASK_GW_DZ300                  0x00000100U
#define Sbcc_CR1_CP_OFF_EN_DZ300                0x00000080U
#define Sbcc_CR1_CAN_AUTO_BIAS_DZ300            0x00000010U
#define Sbcc_CR1_DIR1_EN_DZ300                  0x00000008U
#define Sbcc_CR1_V2_1_DZ300                     0x00000004U
#define Sbcc_CR1_V2_0_DZ300                     0x00000002U
#define Sbcc_CR1_TRIG_DZ300                     0x00000001U

/* -------- L99DZ300 CR17 (0x3E)-----------*/ 
#define Sbcc_CR17_T2_ON_2_DZ300                 0x00200000U 
#define Sbcc_CR17_T2_ON_1_DZ300                 0x00100000U
#define Sbcc_CR17_T2_ON_0_DZ300                 0x00080000U
#define Sbcc_CR17_T2_PER_2_DZ300                0x00040000U
#define Sbcc_CR17_T2_PER_1_DZ300                0x00020000U
#define Sbcc_CR17_T2_PER_0_DZ300                0x00010000U 
#define Sbcc_CR17_T1_ON_2_DZ300                 0x00002000U
#define Sbcc_CR17_T1_ON_1_DZ300                 0x00001000U
#define Sbcc_CR17_T1_ON_0_DZ300                 0x00000800U
#define Sbcc_CR17_T1_PER_2_DZ300                0x00000400U
#define Sbcc_CR17_T1_PER_1_DZ300                0x00000200U
#define Sbcc_CR17_T1_PER_0_DZ300                0x00000100U 
#define Sbcc_CR17_V1_RESET_1_DZ300              0x00000080U
#define Sbcc_CR17_V1_RESET_0_DZ300              0x00000040U
#define Sbcc_CR17_WD_TIME_DZ300                 0x00000010U
#define Sbcc_CR17_STBY_SEL_DZ300                0x00000002U
#define Sbcc_CR17_GO_STBY_DZ300                 0x00000001U

/* -------- L99DZ300 CR18 (0x3F)-----------*/
#define Sbcc_CR18_EI2_PU_DZ300                  0x00800000U 
#define Sbcc_CR18_EI1_PU_DZ300                  0x00100000U
#define Sbcc_CR18_EI2_EN_DZ300                  0x00080000U
#define Sbcc_CR18_EI1_EN_DZ300                  0x00010000U
#define Sbcc_CR18_EI2_FILT_1_DZ300              0X00008000U
#define Sbcc_CR18_EI2_FILT_0_DZ300              0X00004000U
#define Sbcc_CR18_EI1_FILT_1_DZ300              0X00000200U
#define Sbcc_CR18_EI1_FILT_0_DZ300              0X00000100U
#define Sbcc_CR18_HEN_DZ300                     0X00000080U
#define Sbcc_CR18_CAN_REC_ONLY_DZ300            0x00000040U
#define Sbcc_CR18_CAN_ACT_DZ300                 0x00000020U
#define SBcc_CR18_LIN_WU_EN_DZ300               0x00000010U
#define SBcc_CR18_CAN_WU_EN_DZ300               0x00000008U
#define Sbcc_CR18_TIMER_NINT_WAKE_SEL_DZ300     0x00000004U
#define Sbcc_CR18_TIMER_NINT_END_Z300           0x00000002U
#define Sbcc_CR18_TRIG_DZ300                    0x00000001U 

/* Status L99DZ300 register SR1*/
#define Sbcc_SR1_HB1_LS_SC_DZ300                ((uint32)0x01U << 8U)
#define Sbcc_SR1_HB2_LS_SC_DZ300                ((uint32)0x01U << 9U)
#define Sbcc_SR1_HB3_LS_SC_DZ300                ((uint32)0x01U << 10U)
#define Sbcc_SR1_HB4_LS_SC_DZ300                ((uint32)0x01U << 11U)
#define Sbcc_SR1_HB5_LS_SC_DZ300                ((uint32)0x01U << 12U)
#define Sbcc_SR1_HB6_LS_SC_DZ300                ((uint32)0x01U << 13U)
#define Sbcc_SR1_TW_CL1_DZ300                   ((uint32)0x01U << 16U)
#define Sbcc_SR1_TW_CL2_DZ300                   ((uint32)0x01U << 17U)
#define Sbcc_SR1_TW_CL3_DZ300                   ((uint32)0x01U << 18U)
#define Sbcc_SR1_TW_CL4_DZ300                   ((uint32)0x01U << 19U)
#define Sbcc_SR1_TW_CL5_DZ300                   ((uint32)0x01U << 20U)
#define Sbcc_SR1_TW_CL6_DZ300                   ((uint32)0x01U << 21U)
#define Sbcc_SR1_TW_CL7_DZ300                   ((uint32)0x01U << 22U)
#define Sbcc_SR1_TW_CL8_DZ300                   ((uint32)0x01U << 23U)

/* Status L99DZ300 register SR2*/
#define Sbcc_SR2_HB1_HS_SC_DZ300                ((uint32)0x01U << 8U)
#define Sbcc_SR2_HB2_HS_SC_DZ300                ((uint32)0x01U << 9U)
#define Sbcc_SR2_HB3_HS_SC_DZ300                ((uint32)0x01U << 10U)
#define Sbcc_SR2_HB4_HS_SC_DZ300                ((uint32)0x01U << 11U)
#define Sbcc_SR2_HB5_HS_SC_DZ300                ((uint32)0x01U << 12U)
#define Sbcc_SR2_HB6_HS_SC_DZ300                ((uint32)0x01U << 13U)
#define Sbcc_SR2_TSD1_CL1_DZ300                 ((uint32)0x01U << 16U)
#define Sbcc_SR2_TSD1_CL2_DZ300                 ((uint32)0x01U << 17U)
#define Sbcc_SR2_TSD1_CL3_DZ300                 ((uint32)0x01U << 18U)
#define Sbcc_SR2_TSD1_CL4_DZ300                 ((uint32)0x01U << 19U)
#define Sbcc_SR2_TSD1_CL5_DZ300                 ((uint32)0x01U << 20U)
#define Sbcc_SR2_TSD1_CL6_DZ300                 ((uint32)0x01U << 21U)
#define Sbcc_SR2_TSD1_CL7_DZ300                 ((uint32)0x01U << 22U)
#define Sbcc_SR2_TSD1_CL8_DZ300                 ((uint32)0x01U << 23U)

/* Status L99DZ300 register SR3*/
#define Sbcc_SR3_CAN_SUP_LOW_DZ300              ((uint32)0x01U << 3U)
#define Sbcc_SR3_IP_SUP_LOW_DZ300               ((uint32)0x01U << 4U)
#define Sbcc_SR3_SGNDLOSS_DZ300                 ((uint32)0x01U << 5U)

/* Status L99DZ300 register SR4*/
#define Sbcc_SR4_ECV_VHI_DZ300                  ((uint32)0x01U << 16U)
#define Sbcc_SR4_ECV_VNR_DZ300                  ((uint32)0x01U << 17U)
#define Sbcc_SR4_EI1_STATE_DZ300                ((uint32)0x01U << 18U)
#define Sbcc_SR4_EI2_STATE_DZ300                ((uint32)0x01U << 21U)
#define Sbcc_SR4_WD_TIMER_STATE_0_DZ300         ((uint32)0x01U << 22U)
#define Sbcc_SR4_WD_TIMER_STATE_1_DZ300         ((uint32)0x01U << 23U)

/* Status L99DZ300 register SR5*/
#define Sbcc_SR5_HB4_HS_OL_DZ300                ((uint32)0x01U << 6U)
#define Sbcc_SR5_HB4_LS_OL_DZ300                ((uint32)0x01U << 7U)
#define Sbcc_SR5_HB5_HS_OL_DZ300                ((uint32)0x01U << 8U)
#define Sbcc_SR5_HB5_LS_OL_DZ300                ((uint32)0x01U << 9U)
#define Sbcc_SR5_HB6_HS_OL_DZ300                ((uint32)0x01U << 10U)
#define Sbcc_SR5_HB6_LS_OL_DZ300                ((uint32)0x01U << 11U)
#define Sbcc_SR5_HS14_OL_DZ300                  ((uint32)0x01U << 19U)

/* Status L99DZ300 register SR6*/
#define Sbcc_SR6_HS14_OC_DZ300                  ((uint32)0x01U << 19U)
#define Sbcc_SR6_HB6_LS_OC                      ((uint32)0x01U << 11U)
#define Sbcc_SR6_HB6_HS_OC                      ((uint32)0x01U << 10U)
#define Sbcc_SR6_HB5_LS_OC                      ((uint32)0x01U << 9U)
#define Sbcc_SR6_HB5_HS_OC                      ((uint32)0x01U << 8U)
#define Sbcc_SR6_HB4_LS_OC                      ((uint32)0x01U << 7U)
#define Sbcc_SR6_HB4_HS_OC                      ((uint32)0x01U << 6U)

/* Status L99DZ300 register SR7*/
#define Sbcc_SR7_VS_UV_DZ300                    ((uint32)0x01U << 0U)
#define Sbcc_SR7_VS_OV_DZ300                    ((uint32)0x01U << 1U)
#define Sbcc_SR7_VSREG_UV_DZ300                 ((uint32)0x01U << 2U)
#define Sbcc_SR7_VSREG_OV_DZ300                 ((uint32)0x01U << 3U)
#define Sbcc_SR7_V1FAIL_DZ300                   ((uint32)0x01U << 5U)
#define Sbcc_SR7_V2FAIL_DZ300                   ((uint32)0x01U << 6U)
#define Sbcc_SR7_V2SC_DZ300                     ((uint32)0x01U << 7U)
#define Sbcc_SR7_TW_DZ300                       ((uint32)0x01U << 8U)
#define Sbcc_SR7_CP_LOW_DZ300                   ((uint32)0x01U << 9U)
#define Sbcc_SR7_SPI_SCK_CNT                    ((uint32)0x01U << 10U)
#define Sbcc_SR7_SPI_INV_CMD                    ((uint32)0x01U << 11U)
#define Sbcc_SR7_DSMON_LS1                      ((uint32)0x01U << 12U) 
#define Sbcc_SR7_DSMON_LS2                      ((uint32)0x01U << 13U) 
#define Sbcc_SR7_DSMON_HS1                      ((uint32)0x01U << 14U) 
#define Sbcc_SR7_DSMON_HS2                      ((uint32)0x01U << 15U)  
#define Sbcc_SR7_CANTO_DZ300                    ((uint32)0x01U << 16U)
#define Sbcc_SR7_CAN_TXD_DOM_DZ300              ((uint32)0x01U << 17U)
#define SbCC_SR7_CAN_PERM_DOM_DZ300             ((uint32)0x01U << 18U)
#define SbCC_SR7_CAN_PERM_REC_DZ300             ((uint32)0x01U << 19U)
#define SbCC_SR7_CAN_RXD_REC_DZ300              ((uint32)0x01U << 20U)

#define SbCC_SR7_LIN_PERM_REC_DZ300             ((uint32)0x01U << 21U)
#define Sbcc_SR7_LIN_TXD_DOM_DZ300              ((uint32)0x01U << 22U)
#define SbCC_SR7_LIN_PERM_DOM_DZ300             ((uint32)0x01U << 23U)

/* Status L99DZ300 register SR8*/
#define Sbcc_SR8_VPOR_DZ300                     ((uint32)0x01U << 0U)
#define Sbcc_SR8_WDFAIL_DZ300                   ((uint32)0x01U << 1U)
#define Sbcc_SR8_FORCED_SLEEP_WD_DZ300          ((uint32)0x01U << 2U)
#define Sbcc_SR8_FORCED_SLEEP_TSD2_V1SC_DZ300   ((uint32)0x01U << 3U)
#define Sbcc_SR8_TSD1_DZ300                     ((uint32)0x01U << 4U)
#define Sbcc_SR8_TSD2_DZ300                     ((uint32)0x01U << 5U)
#define Sbcc_SR8_DEVICE_STATE_0_DZ300           ((uint32)0x01U << 6U)
#define Sbcc_SR8_DEVICE_STATE_1_DZ300           ((uint32)0x01U << 7U)
#define Sbcc_SR8_V1UV_DZ300                     ((uint32)0x01U << 15U)
#define Sbcc_SR8_DEBUG_ACTIVE_DZ300             ((uint32)0x01U << 16U)
#define Sbcc_SR8_WAKE_TIMER_DZ300               ((uint32)0x01U << 17U)
#define Sbcc_SR8_WAKE_LIN_DZ300                 ((uint32)0x01U << 18U)
#define Sbcc_SR8_WAKE_CAN_DZ300                 ((uint32)0x01U << 19U)
#define Sbcc_SR8_EI1_WAKE_DZ300                 ((uint32)0x01U << 20U)
#define Sbcc_SR8_EI2_WAKE_DZ300                 ((uint32)0x01U << 23U) 

/* Out config type */
#define Sbcc_OUT_CFG_OFF                        0U
#define Sbcc_OUT_CFG_ON                         1U
#define Sbcc_OUT_CFG_TIMER1                     2U
#define Sbcc_OUT_CFG_TIMER2                     3U
#define Sbcc_OUT_CFG_PWM1                       4U
#define Sbcc_OUT_CFG_PWM2                       5U
#define Sbcc_OUT_CFG_PWM3                       6U
#define Sbcc_OUT_CFG_PWM4                       7U
#define Sbcc_OUT_CFG_PWM5                       8U
#define Sbcc_OUT_CFG_PWM6                       9U
#define Sbcc_OUT_CFG_PWM7                       10U
#define Sbcc_OUT_CFG_PWM8                       11U
#define Sbcc_OUT_CFG_PWM9                       12U
#define Sbcc_OUT_CFG_PWM10                      13U
#define Sbcc_OUT_CFG_DIR1                       14U
#define Sbcc_OUT_CFG_DIR2                       15U

/* channel status flag masks */
#define Sbcc_CHANNEL_RUN                        0x01U
#define Sbcc_CHANNEL_WAIT                       0x02U
#define Sbcc_CHANNEL_DISABLED                   0x04U
#define Sbcc_CHANNEL_RESUME                     0x08U
#define Sbcc_CHANNEL_FEEDBACK_VALID             0x10U
#define Sbcc_CHANNEL_FEEDBACK_VALIDATING        0x20U
#define Sbcc_CHANNEL_UNDERLOAD_PRESENT          0x40U
#define Sbcc_CHANNEL_OVERLOAD_PRESENT           0x80U
#define Sbcc_CHANNEL_NO_FLAG                    0x00U

/** Diagnostic machine possible states  */
/** Diagnosis feedback selection step */
#define Sbcc_DIAG_STS_SEL_FB                    0U
/** Diagnosis wait feedback syncronization event */
#define Sbcc_DIAG_STS_WAIT_SEM                  1U
/** Diagnosis wait feedback stabilization step */
#define Sbcc_DIAG_STS_WAIT_STAB                 2U
/** Diagnosis acquire feedback step */
#define Sbcc_DIAG_STS_ACQUIRING                 3U
/** Total diagnosis steps */
#define Sbcc_DIAG_STEPS                         4U


/* _____ G L O B A L - T Y P E S _____________________________________________*/
/** \brief Diagnosis step function type */
typedef void (* Sbcc_DiagFunctions_t)(uint8 Device);

typedef enum
{
  SBCC_INDEX_TABLE_PING = 0,
  SBCC_INDEX_TABLE_PONG
}Sbcc_IndexTableType_t;

typedef enum
{
  SBCC_OUTPUT_LS = 0,
  SBCC_OUTPUT_HS
}Sbcc_OutputType_t;

typedef union
{
  uint32 Word;
  struct
  {
    uint32 Reserved:8;              /**< Reserved */
    uint32 HB1_LS_SC:1;               /**< Indicates the short-circuit condition on LS of HB1*/
    uint32 HB2_LS_SC:1;               /**< Indicates the short-circuit condition on LS of HB2*/
    uint32 HB3_LS_SC:1;               /**< Indicates the short-circuit condition on LS of HB3*/
    uint32 HB4_LS_SC:1;               /**< Indicates the short-circuit condition on LS of HB4*/
    uint32 HB5_LS_SC:1;               /**< Indicates the short-circuit condition on LS of HB5*/
    uint32 HB6_LS_SC:1;               /**< Indicates the short-circuit condition on LS of HB6*/
    uint32 Reserved1:2;              /**< Reserved */
    uint32 TW_CL1:1;                  /**< Indicates the cluster 1 has reached the thermal warning threshold */
    uint32 TW_CL2:1;                  /**< Indicates the cluster 2 has reached the thermal warning threshold */
    uint32 TW_CL3:1;                  /**< Indicates the cluster 3 has reached the thermal warning threshold */
    uint32 TW_CL4:1;                  /**< Indicates the cluster 4 has reached the thermal warning threshold */
    uint32 TW_CL5:1;                  /**< Indicates the cluster 5 has reached the thermal warning threshold */
    uint32 TW_CL6:1;                  /**< Indicates the cluster 6 has reached the thermal warning threshold */
    uint32 TW_CL7:1;                  /**< Indicates the cluster 7 has reached the thermal warning threshold */
    uint32 TW_CL8:1;                  /**< Indicates the cluster 8 has reached the thermal warning threshold */
    uint32 Reserved2:8;               /**< Reserved */
  }Bits;
} Sbcc_StatusRegister1_DZ300_t; 

typedef union
{
  uint32 Word;
  struct
  {
    uint32 Reserved:8;      /**< Reserved */
    uint32 HB1_HS_SC:1;       /**< Indicates the short-circuit condition on HS of HB1*/
    uint32 HB2_HS_SC:1;       /**< Indicates the short-circuit condition on HS of HB2*/
    uint32 HB3_HS_SC:1;       /**< Indicates the short-circuit condition on HS of HB3*/
    uint32 HB4_HS_SC:1;       /**< Indicates the short-circuit condition on HS of HB4*/
    uint32 HB5_HS_SC:1;       /**< Indicates the short-circuit condition on HS of HB5*/
    uint32 HB6_HS_SC:1;       /**< Indicates the short-circuit condition on HS of HB6*/
    uint32 Reserved1:2;      /**< Reserved */
    uint32 TSD1_CL1:1;        /**< Indicates the cluster 1 has reached the thermal shutdown threshold (TSD1) and the output cluster was shutdown */
    uint32 TSD1_CL2:1;        /**< Indicates the cluster 2 has reached the thermal shutdown threshold (TSD1) and the output cluster was shutdown */
    uint32 TSD1_CL3:1;        /**< Indicates the cluster 3 has reached the thermal shutdown threshold (TSD1) and the output cluster was shutdown */
    uint32 TSD1_CL4:1;        /**< Indicates the cluster 4 has reached the thermal shutdown threshold (TSD1) and the output cluster was shutdown */
    uint32 TSD1_CL5:1;        /**< Indicates the cluster 5 has reached the thermal shutdown threshold (TSD1) and the output cluster was shutdown */
    uint32 TSD1_CL6:1;        /**< Indicates the cluster 6 has reached the thermal shutdown threshold (TSD1) and the output cluster was shutdown */
    uint32 TSD1_CL7:1;        /**< Indicates the cluster 7 has reached the thermal shutdown threshold (TSD1) and the output cluster was shutdown */
    uint32 TSD1_CL8:1;        /**< Indicates the cluster 8 has reached the thermal shutdown threshold (TSD1) and the output cluster was shutdown */
    uint32 Reserved2:8;       /**< Reserved */
  }Bits;
} Sbcc_StatusRegister2_DZ300_t;  

typedef union
{
  uint32 Word;
  struct
  {
    uint32 Reserved:3;          /**< Reserved */
    uint32 CAN_SUP_LOW:1;       /**< Indicates that voltage at CAN supply pin reached the CAN supply low warning threshold*/
    uint32 IP_SUP_LOW:1;        /**< Indicates that Internal IP voltage supply (analog and/or digital) is less than 3V*/
    uint32 SGNDLOSS:1;          /**< Indicates  that ground at SGND pin has been lost*/
    uint32 Reserved1:26;        /**< Reserved*/
  }Bits;
} Sbcc_StatusRegister3_DZ300_t; 

typedef union
{
  uint32 Word;
  struct
  {
    uint32 Reserved:16;          /**< Reserved */
    uint32 ECV_VHI:1;            /**< Indicates the electro chrome voltage is too high*/
    uint32 ECV_VNR:1;            /**< Indicates the electro chrome voltage is not reached*/
    uint32 EI1_STATE:1;          /**< Indicates the momentary status of EI1*/
    uint32 Reserved1:2;          /**< Reserved*/
    uint32 EI2_STATE:1;          /**< Indicates the momentary status of EI2*/
    uint32 WD_TIMER_STATE:2;     /**< Indicates the Watchdog timer status*/
    uint32 Reserved2:8;          /**< Reserved */
  }Bits;
} Sbcc_StatusRegister4_DZ300_t; 

typedef union
{
  uint32 Word;
  struct
  {
    uint32 HB1_HS_OL:1;          /**< Indicates an open-load condition was detected at the output */
    uint32 HB1_LS_OL:1;          /**< Indicates an open-load condition was detected at the output */
    uint32 HB2_HS_OL:1;          /**< Indicates an open-load condition was detected at the output */
    uint32 HB2_LS_OL:1;          /**< Indicates an open-load condition was detected at the output */
    uint32 HB3_HS_OL:1;          /**< Indicates an open-load condition was detected at the output */
    uint32 HB3_LS_OL:1;          /**< Indicates an open-load condition was detected at the output */
    uint32 HB4_HS_OL:1;          /**< Indicates an open-load condition was detected at the output */
    uint32 HB4_LS_OL:1;          /**< Indicates an open-load condition was detected at the output */
    uint32 HB5_HS_OL:1;          /**< Indicates an open-load condition was detected at the output */
    uint32 HB5_LS_OL:1;          /**< Indicates an open-load condition was detected at the output */
    uint32 HB6_HS_OL:1;          /**< Indicates an open-load condition was detected at the output */
    uint32 HB6_LS_OL:1;          /**< Indicates an open-load condition was detected at the output */
    uint32 HS7_OL:1;             /**< Indicates an open-load condition was detected at the output */
    uint32 HS8_OL:1;             /**< Indicates an open-load condition was detected at the output */
    uint32 HS9_OL:1;             /**< Indicates an open-load condition was detected at the output */
    uint32 HS10_OL:1;            /**< Indicates an open-load condition was detected at the output */
    uint32 HS11_OL:1;            /**< Indicates an open-load condition was detected at the output */
    uint32 HS12_OL:1;            /**< Indicates an open-load condition was detected at the output */
    uint32 HS13_OL:1;            /**< Indicates an open-load condition was detected at the output */
    uint32 HS14_OL:1;            /**< Indicates an open-load condition was detected at the output */
    uint32 HS15_OL:1;            /**< Indicates an open-load condition was detected at the output */
    uint32 HS0_OL:1;             /**< Indicates an open-load condition was detected at the output */
    uint32 GH_OL:1;              /**< Indicates an open-load condition was detected at the output */
    uint32 ECV_OL:1;             /**< Indicates an open-load condition was detected at the output */
    uint32 Reserved:8;           /**< Reserved */
  }Bits;
} Sbcc_StatusRegister5_DZ300_t;

typedef union
{
  uint32 Word;
  struct
  {
    uint32 HB1_HS_OC:1;          /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HB1_LS_OC:1;          /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HB2_HS_OC:1;          /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HB2_LS_OC:1;          /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HB3_HS_OC:1;          /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HB3_LS_OC:1;          /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HB4_HS_OC:1;          /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HB4_LS_OC:1;          /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HB5_HS_OC:1;          /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HB5_LS_OC:1;          /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HB6_HS_OC:1;          /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HB6_LS_OC:1;          /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HS7_OC:1;             /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HS8_OC:1;             /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HS9_OC:1;             /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HS10_OC:1;            /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HS11_OC:1;            /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HS12_OC:1;            /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HS13_OC:1;            /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HS14_OC:1;            /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HS15_OC:1;            /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 HS0_OC:1;             /**< Indicates the output was shutdown due to overcurrent condition */
    uint32 DSMON_HEAT:1;         /**< Indicates a short-circuit condition was detected */
    uint32 ECV_OC:1;             /**< Indicates the output was shut down due to overcurrent condition */
    uint32 Reserved:8;           /**< Reserved */
  }Bits;
} Sbcc_StatusRegister6_DZ300_t;

typedef union
{
  uint32 Word;
  struct
  {
    uint32 VS_UV:1;          /**< Indicates the voltage at Vs has reached the undervoltage threshold */
    uint32 VS_OV:1;          /**< Indicates the voltage at Vs has reached the overvoltage threshold */
    uint32 VSREG_UV:1;       /**< Indicates the voltage at Vsreg has reached the undervoltage threshold */
    uint32 VSREG_OV:1;       /**< Indicates the voltage at Vsreg has reached the overvoltage threshold */
    uint32 Reserved:1;       /**< Reserved */
    uint32 V1FAIL:1;         /**< Indicates a V1 fail event occurred since last readout */
    uint32 V2FAIL:1;         /**< Indicates a V2 fail event occurred since last readout */
    uint32 V2SC:1;           /**< Indicates a short-circuit to GND condition of V2 at turn on of the regulator */
    uint32 TW:1;             /**< Indicates the temperature has reached the thermal warning threshold */
    uint32 CP_LOW:1;         /**< Indicates that the charge pump voltage is too low */
    uint32 SPI_SCK_CNT:1;    /**< Indicates an SPI frame with wrong number of CLK cycles was detected */
    uint32 SPI_INV_CMD:1;    /**< Indicates one of the following conditions was detected */
    uint32 DSMON_LS1:1;      /**< Indicates a short-circuit or open-load condition was detected */
    uint32 DSMON_LS2:1;      /**< Indicates a short-circuit or open-load condition was detected */
    uint32 DSMON_HS1:1;      /**< Indicates a short-circuit or open-load condition was detected */
    uint32 DSMON_HS2:1;      /**< Indicates a short-circuit or open-load condition was detected */
    uint32 CANTO:1;          /**< Indicates that there was a transition from BIAS ON to BIAS OFF */
    uint32 CAN_TXD_DOM:1;    /**< Indicates the CAN TXD signal permanent dominant */
    uint32 CAN_PERM_DOM:1;   /**< Indicates the CAN bus signal permanent dominant */
    uint32 CAN_PERM_REC:1;   /**< Indicates the CAN bus signal permanent recessive */
    uint32 CAN_RXD_REC:1;    /**< Indicates the CAN RXD signal permanent recessive */
    uint32 LIN_PERM_REC:1;   /**< Indicates the LIN bus signal permanent recessive */
    uint32 LIN_TXD_DOM:1;    /**< Indicates the LIN TXD signal dominant timeout */
    uint32 LIN_PERM_DOM:1;   /**< Indicates the LIN bus signal dominant timeou */
    uint32 Reserved1:8;       /**< Reserved */
  }Bits;
} Sbcc_StatusRegister7_DZ300_t;

typedef union
{
  uint32 Word;
  struct
  {
    uint32 VPOR:1;                      /**< Indicates the VSREG Power-on Reset threshold (VPOR) reached */
    uint32 WDFAIL:1;                    /**< Indicates the Watchdog failure */
    uint32 FORCED_SLEEP_WD:1;           /**< Indicates the Device entered forced sleep mode due to multiple watchdog failures */
    uint32 FROCED_SLEEP_TSD2_V1SC:1;    /**< Indicates the Forced sleep TSD2 / V1 short-circuit */
    uint32 TSD1:1;                      /**< Indicates the thermal shutdown 1 was reached */
    uint32 TSD2:1;                      /**< Indicates the thermal shutdown 2 was reached */
    uint32 DEVICE_STATE_0:2;            /**< Indicates the V2 short-circuit detection */
    uint32 WDFAIL_CNT_0:1;              /**< Indicates the number of subsequent watchdog failures */
    uint32 WDFAIL_CNT_1:1;              /**< Indicates the number of subsequent watchdog failures */
    uint32 WDFAIL_CNT_2:1;              /**< Indicates the number of subsequent watchdog failures */
    uint32 WDFAIL_CNT_3:1;              /**< Indicates the number of subsequent watchdog failures */
    uint32 V1_RESTART_0:1;              /**< Indicates the number of TSD2 events that caused a restart of voltage regulator V1 */
    uint32 V1_RESTART_1:1;              /**< Indicates the number of TSD2 events that caused a restart of voltage regulator V1 */
    uint32 V1_RESTART_2:1;              /**< Indicates the number of TSD2 events that caused a restart of voltage regulator V1 */
    uint32 V1UV:1;                      /**< Indicates the undervoltage condition at voltage regulator V1 */
    uint32 DEBUG_ACTIVE:1;              /**< Indicates the Debug mode active */
    uint32 WAKE_TIMER:1;                /**< Indicates the Wake-up from timer */
    uint32 WAKE_LIN:1;                  /**< Indicates the Wake-up from LIN */
    uint32 WAKE_CAN:1;                  /**< Indicates the Wake-up from CAN*/
    uint32 EI1_WAKE:1;                  /**< Indicates the External interrupt 1 wake-up*/
    uint32 Reserved:2;                  /**< Reserved */
    uint32 EI2_WAKE:1;                  /**< Indicates the External interrupt 2 wake-up */
    uint32 Reserved1:8;                 /**< Reserved */
  }Bits;
} Sbcc_StatusRegister8_DZ300_t;

typedef struct
{
  Sbcc_StatusRegister1_DZ300_t    SR1;
  Sbcc_StatusRegister2_DZ300_t    SR2;
  Sbcc_StatusRegister3_DZ300_t    SR3;
  Sbcc_StatusRegister4_DZ300_t    SR4;
  Sbcc_StatusRegister5_DZ300_t    SR5;
  Sbcc_StatusRegister6_DZ300_t    SR6;
  Sbcc_StatusRegister7_DZ300_t    SR7;
  Sbcc_StatusRegister8_DZ300_t    SR8;
} Sbcc_AllStatusRegister_DZ300_t;

/** \brief  Channel description and diagnosis structure.\n
  Note : this structure could be divided in two because the first part
  are only a const values. This could be done if there is a need
  of reduce the space occupied in RAM */
typedef struct
{
  Sbcc_OutputType_t   OutType;/**<  Output HS or LS */
  uint8   Duty;               /**< Applied duty cycle */
  uint8   Flags;              /**< Channel Running flags */
  uint16  DiagValue;          /**< Last acquired channel analog feedback */
} Sbcc_Channel_t;

typedef struct
{
  uint8    RegInedx;
  uint32   HS_Bit;
  uint32   LS_Bit;
  uint32   BitMask;
  uint8    BitOffset;
} Sbcc_OutputBitCfg_t;

/** \brief  Device diagnosis structure */
typedef struct
{
  uint8   DiagAnalogInput;  /**< Device analog feedback reference */
  uint8   FeedbackSelected; /**< Current feedback selected */
  uint16  HoldSampleCnt;    /**< Waiting stabilization and sampling counter */
  uint8   DiagSts;          /**< Diagnosis machine current status */
  /* There are 3 bytes unused */
} Sbcc_Device_t;

typedef struct {
  uint8 MatureTime;
  uint8 DematureTime;
  uint8 TempClId;
  uint32 OcrMask;
  uint32 OcrAlertMask;
  uint32 OlMask;
  uint32 OcMask;
} Sbcc_DiagCfg_t;

typedef struct {
  uint32 State: 2;
  uint32 ErrType: 3;
  uint32 LastErr: 3;
  uint32 WaitFb: 1;
  uint32 SuspendOCR: 1;
  uint32 DiagTimer: 8;
  uint32 ProtectTimer: 16;
} Sbcc_DiagInfo_t;

typedef struct
{
  volatile uint32  WDRefreshTimer; 
  volatile uint32  WD_WDToggleValue;
} WD_WdgMsg_t;


/* _____ G L O B A L - D A T A _______________________________________________*/
extern uint8 SBCM_InitSbcFlag;
/* _____ G L O B A L - M A C R O S ___________________________________________*/

/* _____ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
/*----------------------------------------------------------------------------*/
/*Name : BRsHwSbcInit    			                                          */
/*Role : Initialize hardware/application module 						      */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void SBCM_BRsHwSbcInit(void);

/*----------------------------------------------------------------------------*/
/*Name : BRsHwSbcInit    			                                          */
/*Role : Initialize hardware/application module 						      */
/*Interface :                                                                 */
/*  - IN  : none	                                                          */
/*  - OUT : none  							                                  */
/*Pre-condition : none			                                              */
/*Constraints   : none             			                                  */
/*Behavior :                                                                  */
/*  DO                                                                        */
/*    [initialize parameters and main loop]                                   */
/*  OD                                                                        */
/*----------------------------------------------------------------------------*/
extern void SBCM_BMInitBRsHwSbc(void);

/******************************************************************************
* Name         :  Imcd_SpiTransferErrorCallback
* Called by    :  Spid_SpiEventChannel5()
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called for Spi Transfer error callout
******************************************************************************/
extern void SbcM_SpiTransferErrorCallback(void);

/******************************************************************************
* Name         :  Imcd_SpiTransferCompleteCallback
* Called by    :  Spid_SpiEventChannel5()
* Preconditions:  None
* Parameters   :  None
* Return code  :  None
* Description  :  This function is called for Spi Transfer Complete Callout
******************************************************************************/
extern void SbcM_SpiTransferCompleteCallback(void);

extern boolean Sbcc_WatchdogMonitor(void);

extern void SBCM_initWDMsg(void);

extern void Sbcc_Reset(void);

extern boolean GetSbcc_WDFlag(void);

extern boolean Sbcc_WatchdogMonitorFLASH(void);
#endif /* SBCC_PRIV_H */

/* _____ E N D _____ (sbcc_priv.h) ___________________________________________*/

