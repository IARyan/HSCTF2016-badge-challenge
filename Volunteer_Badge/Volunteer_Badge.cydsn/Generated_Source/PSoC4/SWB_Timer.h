/*******************************************************************************
* File Name: SWB_Timer.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the SWB_Timer
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_SWB_Timer_H)
#define CY_TCPWM_SWB_Timer_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} SWB_Timer_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  SWB_Timer_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define SWB_Timer_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define SWB_Timer_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define SWB_Timer_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define SWB_Timer_QUAD_ENCODING_MODES            (0lu)

/* Signal modes */
#define SWB_Timer_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define SWB_Timer_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define SWB_Timer_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define SWB_Timer_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define SWB_Timer_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define SWB_Timer_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define SWB_Timer_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define SWB_Timer_TC_RUN_MODE                    (0lu)
#define SWB_Timer_TC_COUNTER_MODE                (0lu)
#define SWB_Timer_TC_COMP_CAP_MODE               (2lu)
#define SWB_Timer_TC_PRESCALER                   (0lu)

/* Signal modes */
#define SWB_Timer_TC_RELOAD_SIGNAL_MODE          (1lu)
#define SWB_Timer_TC_COUNT_SIGNAL_MODE           (1lu)
#define SWB_Timer_TC_START_SIGNAL_MODE           (1lu)
#define SWB_Timer_TC_STOP_SIGNAL_MODE            (0lu)
#define SWB_Timer_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define SWB_Timer_TC_RELOAD_SIGNAL_PRESENT       (1lu)
#define SWB_Timer_TC_COUNT_SIGNAL_PRESENT        (1lu)
#define SWB_Timer_TC_START_SIGNAL_PRESENT        (1lu)
#define SWB_Timer_TC_STOP_SIGNAL_PRESENT         (1lu)
#define SWB_Timer_TC_CAPTURE_SIGNAL_PRESENT      (1lu)

/* Interrupt Mask */
#define SWB_Timer_TC_INTERRUPT_MASK              (3lu)

/* PWM Mode */
/* Parameters */
#define SWB_Timer_PWM_KILL_EVENT                 (0lu)
#define SWB_Timer_PWM_STOP_EVENT                 (0lu)
#define SWB_Timer_PWM_MODE                       (4lu)
#define SWB_Timer_PWM_OUT_N_INVERT               (0lu)
#define SWB_Timer_PWM_OUT_INVERT                 (0lu)
#define SWB_Timer_PWM_ALIGN                      (0lu)
#define SWB_Timer_PWM_RUN_MODE                   (0lu)
#define SWB_Timer_PWM_DEAD_TIME_CYCLE            (0lu)
#define SWB_Timer_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define SWB_Timer_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define SWB_Timer_PWM_COUNT_SIGNAL_MODE          (3lu)
#define SWB_Timer_PWM_START_SIGNAL_MODE          (0lu)
#define SWB_Timer_PWM_STOP_SIGNAL_MODE           (0lu)
#define SWB_Timer_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define SWB_Timer_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define SWB_Timer_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define SWB_Timer_PWM_START_SIGNAL_PRESENT       (0lu)
#define SWB_Timer_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define SWB_Timer_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define SWB_Timer_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define SWB_Timer_TC_PERIOD_VALUE                (65535lu)
#define SWB_Timer_TC_COMPARE_VALUE               (65535lu)
#define SWB_Timer_TC_COMPARE_BUF_VALUE           (65535lu)
#define SWB_Timer_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define SWB_Timer_PWM_PERIOD_VALUE               (65535lu)
#define SWB_Timer_PWM_PERIOD_BUF_VALUE           (65535lu)
#define SWB_Timer_PWM_PERIOD_SWAP                (0lu)
#define SWB_Timer_PWM_COMPARE_VALUE              (65535lu)
#define SWB_Timer_PWM_COMPARE_BUF_VALUE          (65535lu)
#define SWB_Timer_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define SWB_Timer__LEFT 0
#define SWB_Timer__RIGHT 1
#define SWB_Timer__CENTER 2
#define SWB_Timer__ASYMMETRIC 3

#define SWB_Timer__X1 0
#define SWB_Timer__X2 1
#define SWB_Timer__X4 2

#define SWB_Timer__PWM 4
#define SWB_Timer__PWM_DT 5
#define SWB_Timer__PWM_PR 6

#define SWB_Timer__INVERSE 1
#define SWB_Timer__DIRECT 0

#define SWB_Timer__CAPTURE 2
#define SWB_Timer__COMPARE 0

#define SWB_Timer__TRIG_LEVEL 3
#define SWB_Timer__TRIG_RISING 0
#define SWB_Timer__TRIG_FALLING 1
#define SWB_Timer__TRIG_BOTH 2

#define SWB_Timer__INTR_MASK_TC 1
#define SWB_Timer__INTR_MASK_CC_MATCH 2
#define SWB_Timer__INTR_MASK_NONE 0
#define SWB_Timer__INTR_MASK_TC_CC 3

#define SWB_Timer__UNCONFIG 8
#define SWB_Timer__TIMER 1
#define SWB_Timer__QUAD 3
#define SWB_Timer__PWM_SEL 7

#define SWB_Timer__COUNT_UP 0
#define SWB_Timer__COUNT_DOWN 1
#define SWB_Timer__COUNT_UPDOWN0 2
#define SWB_Timer__COUNT_UPDOWN1 3


/* Prescaler */
#define SWB_Timer_PRESCALE_DIVBY1                ((uint32)(0u << SWB_Timer_PRESCALER_SHIFT))
#define SWB_Timer_PRESCALE_DIVBY2                ((uint32)(1u << SWB_Timer_PRESCALER_SHIFT))
#define SWB_Timer_PRESCALE_DIVBY4                ((uint32)(2u << SWB_Timer_PRESCALER_SHIFT))
#define SWB_Timer_PRESCALE_DIVBY8                ((uint32)(3u << SWB_Timer_PRESCALER_SHIFT))
#define SWB_Timer_PRESCALE_DIVBY16               ((uint32)(4u << SWB_Timer_PRESCALER_SHIFT))
#define SWB_Timer_PRESCALE_DIVBY32               ((uint32)(5u << SWB_Timer_PRESCALER_SHIFT))
#define SWB_Timer_PRESCALE_DIVBY64               ((uint32)(6u << SWB_Timer_PRESCALER_SHIFT))
#define SWB_Timer_PRESCALE_DIVBY128              ((uint32)(7u << SWB_Timer_PRESCALER_SHIFT))

/* TCPWM set modes */
#define SWB_Timer_MODE_TIMER_COMPARE             ((uint32)(SWB_Timer__COMPARE         <<  \
                                                                  SWB_Timer_MODE_SHIFT))
#define SWB_Timer_MODE_TIMER_CAPTURE             ((uint32)(SWB_Timer__CAPTURE         <<  \
                                                                  SWB_Timer_MODE_SHIFT))
#define SWB_Timer_MODE_QUAD                      ((uint32)(SWB_Timer__QUAD            <<  \
                                                                  SWB_Timer_MODE_SHIFT))
#define SWB_Timer_MODE_PWM                       ((uint32)(SWB_Timer__PWM             <<  \
                                                                  SWB_Timer_MODE_SHIFT))
#define SWB_Timer_MODE_PWM_DT                    ((uint32)(SWB_Timer__PWM_DT          <<  \
                                                                  SWB_Timer_MODE_SHIFT))
#define SWB_Timer_MODE_PWM_PR                    ((uint32)(SWB_Timer__PWM_PR          <<  \
                                                                  SWB_Timer_MODE_SHIFT))

/* Quad Modes */
#define SWB_Timer_MODE_X1                        ((uint32)(SWB_Timer__X1              <<  \
                                                                  SWB_Timer_QUAD_MODE_SHIFT))
#define SWB_Timer_MODE_X2                        ((uint32)(SWB_Timer__X2              <<  \
                                                                  SWB_Timer_QUAD_MODE_SHIFT))
#define SWB_Timer_MODE_X4                        ((uint32)(SWB_Timer__X4              <<  \
                                                                  SWB_Timer_QUAD_MODE_SHIFT))

/* Counter modes */
#define SWB_Timer_COUNT_UP                       ((uint32)(SWB_Timer__COUNT_UP        <<  \
                                                                  SWB_Timer_UPDOWN_SHIFT))
#define SWB_Timer_COUNT_DOWN                     ((uint32)(SWB_Timer__COUNT_DOWN      <<  \
                                                                  SWB_Timer_UPDOWN_SHIFT))
#define SWB_Timer_COUNT_UPDOWN0                  ((uint32)(SWB_Timer__COUNT_UPDOWN0   <<  \
                                                                  SWB_Timer_UPDOWN_SHIFT))
#define SWB_Timer_COUNT_UPDOWN1                  ((uint32)(SWB_Timer__COUNT_UPDOWN1   <<  \
                                                                  SWB_Timer_UPDOWN_SHIFT))

/* PWM output invert */
#define SWB_Timer_INVERT_LINE                    ((uint32)(SWB_Timer__INVERSE         <<  \
                                                                  SWB_Timer_INV_OUT_SHIFT))
#define SWB_Timer_INVERT_LINE_N                  ((uint32)(SWB_Timer__INVERSE         <<  \
                                                                  SWB_Timer_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define SWB_Timer_TRIG_RISING                    ((uint32)SWB_Timer__TRIG_RISING)
#define SWB_Timer_TRIG_FALLING                   ((uint32)SWB_Timer__TRIG_FALLING)
#define SWB_Timer_TRIG_BOTH                      ((uint32)SWB_Timer__TRIG_BOTH)
#define SWB_Timer_TRIG_LEVEL                     ((uint32)SWB_Timer__TRIG_LEVEL)

/* Interrupt mask */
#define SWB_Timer_INTR_MASK_TC                   ((uint32)SWB_Timer__INTR_MASK_TC)
#define SWB_Timer_INTR_MASK_CC_MATCH             ((uint32)SWB_Timer__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define SWB_Timer_CC_MATCH_SET                   (0x00u)
#define SWB_Timer_CC_MATCH_CLEAR                 (0x01u)
#define SWB_Timer_CC_MATCH_INVERT                (0x02u)
#define SWB_Timer_CC_MATCH_NO_CHANGE             (0x03u)
#define SWB_Timer_OVERLOW_SET                    (0x00u)
#define SWB_Timer_OVERLOW_CLEAR                  (0x04u)
#define SWB_Timer_OVERLOW_INVERT                 (0x08u)
#define SWB_Timer_OVERLOW_NO_CHANGE              (0x0Cu)
#define SWB_Timer_UNDERFLOW_SET                  (0x00u)
#define SWB_Timer_UNDERFLOW_CLEAR                (0x10u)
#define SWB_Timer_UNDERFLOW_INVERT               (0x20u)
#define SWB_Timer_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define SWB_Timer_PWM_MODE_LEFT                  (SWB_Timer_CC_MATCH_CLEAR        |   \
                                                         SWB_Timer_OVERLOW_SET           |   \
                                                         SWB_Timer_UNDERFLOW_NO_CHANGE)
#define SWB_Timer_PWM_MODE_RIGHT                 (SWB_Timer_CC_MATCH_SET          |   \
                                                         SWB_Timer_OVERLOW_NO_CHANGE     |   \
                                                         SWB_Timer_UNDERFLOW_CLEAR)
#define SWB_Timer_PWM_MODE_ASYM                  (SWB_Timer_CC_MATCH_INVERT       |   \
                                                         SWB_Timer_OVERLOW_SET           |   \
                                                         SWB_Timer_UNDERFLOW_CLEAR)

#if (SWB_Timer_CY_TCPWM_V2)
    #if(SWB_Timer_CY_TCPWM_4000)
        #define SWB_Timer_PWM_MODE_CENTER                (SWB_Timer_CC_MATCH_INVERT       |   \
                                                                 SWB_Timer_OVERLOW_NO_CHANGE     |   \
                                                                 SWB_Timer_UNDERFLOW_CLEAR)
    #else
        #define SWB_Timer_PWM_MODE_CENTER                (SWB_Timer_CC_MATCH_INVERT       |   \
                                                                 SWB_Timer_OVERLOW_SET           |   \
                                                                 SWB_Timer_UNDERFLOW_CLEAR)
    #endif /* (SWB_Timer_CY_TCPWM_4000) */
#else
    #define SWB_Timer_PWM_MODE_CENTER                (SWB_Timer_CC_MATCH_INVERT       |   \
                                                             SWB_Timer_OVERLOW_NO_CHANGE     |   \
                                                             SWB_Timer_UNDERFLOW_CLEAR)
#endif /* (SWB_Timer_CY_TCPWM_NEW) */

/* Command operations without condition */
#define SWB_Timer_CMD_CAPTURE                    (0u)
#define SWB_Timer_CMD_RELOAD                     (8u)
#define SWB_Timer_CMD_STOP                       (16u)
#define SWB_Timer_CMD_START                      (24u)

/* Status */
#define SWB_Timer_STATUS_DOWN                    (1u)
#define SWB_Timer_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   SWB_Timer_Init(void);
void   SWB_Timer_Enable(void);
void   SWB_Timer_Start(void);
void   SWB_Timer_Stop(void);

void   SWB_Timer_SetMode(uint32 mode);
void   SWB_Timer_SetCounterMode(uint32 counterMode);
void   SWB_Timer_SetPWMMode(uint32 modeMask);
void   SWB_Timer_SetQDMode(uint32 qdMode);

void   SWB_Timer_SetPrescaler(uint32 prescaler);
void   SWB_Timer_TriggerCommand(uint32 mask, uint32 command);
void   SWB_Timer_SetOneShot(uint32 oneShotEnable);
uint32 SWB_Timer_ReadStatus(void);

void   SWB_Timer_SetPWMSyncKill(uint32 syncKillEnable);
void   SWB_Timer_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   SWB_Timer_SetPWMDeadTime(uint32 deadTime);
void   SWB_Timer_SetPWMInvert(uint32 mask);

void   SWB_Timer_SetInterruptMode(uint32 interruptMask);
uint32 SWB_Timer_GetInterruptSourceMasked(void);
uint32 SWB_Timer_GetInterruptSource(void);
void   SWB_Timer_ClearInterrupt(uint32 interruptMask);
void   SWB_Timer_SetInterrupt(uint32 interruptMask);

void   SWB_Timer_WriteCounter(uint32 count);
uint32 SWB_Timer_ReadCounter(void);

uint32 SWB_Timer_ReadCapture(void);
uint32 SWB_Timer_ReadCaptureBuf(void);

void   SWB_Timer_WritePeriod(uint32 period);
uint32 SWB_Timer_ReadPeriod(void);
void   SWB_Timer_WritePeriodBuf(uint32 periodBuf);
uint32 SWB_Timer_ReadPeriodBuf(void);

void   SWB_Timer_WriteCompare(uint32 compare);
uint32 SWB_Timer_ReadCompare(void);
void   SWB_Timer_WriteCompareBuf(uint32 compareBuf);
uint32 SWB_Timer_ReadCompareBuf(void);

void   SWB_Timer_SetPeriodSwap(uint32 swapEnable);
void   SWB_Timer_SetCompareSwap(uint32 swapEnable);

void   SWB_Timer_SetCaptureMode(uint32 triggerMode);
void   SWB_Timer_SetReloadMode(uint32 triggerMode);
void   SWB_Timer_SetStartMode(uint32 triggerMode);
void   SWB_Timer_SetStopMode(uint32 triggerMode);
void   SWB_Timer_SetCountMode(uint32 triggerMode);

void   SWB_Timer_SaveConfig(void);
void   SWB_Timer_RestoreConfig(void);
void   SWB_Timer_Sleep(void);
void   SWB_Timer_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define SWB_Timer_BLOCK_CONTROL_REG              (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define SWB_Timer_BLOCK_CONTROL_PTR              ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define SWB_Timer_COMMAND_REG                    (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define SWB_Timer_COMMAND_PTR                    ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define SWB_Timer_INTRRUPT_CAUSE_REG             (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define SWB_Timer_INTRRUPT_CAUSE_PTR             ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define SWB_Timer_CONTROL_REG                    (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__CTRL )
#define SWB_Timer_CONTROL_PTR                    ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__CTRL )
#define SWB_Timer_STATUS_REG                     (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__STATUS )
#define SWB_Timer_STATUS_PTR                     ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__STATUS )
#define SWB_Timer_COUNTER_REG                    (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__COUNTER )
#define SWB_Timer_COUNTER_PTR                    ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__COUNTER )
#define SWB_Timer_COMP_CAP_REG                   (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__CC )
#define SWB_Timer_COMP_CAP_PTR                   ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__CC )
#define SWB_Timer_COMP_CAP_BUF_REG               (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define SWB_Timer_COMP_CAP_BUF_PTR               ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define SWB_Timer_PERIOD_REG                     (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__PERIOD )
#define SWB_Timer_PERIOD_PTR                     ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__PERIOD )
#define SWB_Timer_PERIOD_BUF_REG                 (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define SWB_Timer_PERIOD_BUF_PTR                 ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define SWB_Timer_TRIG_CONTROL0_REG              (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define SWB_Timer_TRIG_CONTROL0_PTR              ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define SWB_Timer_TRIG_CONTROL1_REG              (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define SWB_Timer_TRIG_CONTROL1_PTR              ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define SWB_Timer_TRIG_CONTROL2_REG              (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define SWB_Timer_TRIG_CONTROL2_PTR              ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define SWB_Timer_INTERRUPT_REQ_REG              (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__INTR )
#define SWB_Timer_INTERRUPT_REQ_PTR              ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__INTR )
#define SWB_Timer_INTERRUPT_SET_REG              (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__INTR_SET )
#define SWB_Timer_INTERRUPT_SET_PTR              ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__INTR_SET )
#define SWB_Timer_INTERRUPT_MASK_REG             (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define SWB_Timer_INTERRUPT_MASK_PTR             ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define SWB_Timer_INTERRUPT_MASKED_REG           (*(reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__INTR_MASKED )
#define SWB_Timer_INTERRUPT_MASKED_PTR           ( (reg32 *) SWB_Timer_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define SWB_Timer_MASK                           ((uint32)SWB_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define SWB_Timer_RELOAD_CC_SHIFT                (0u)
#define SWB_Timer_RELOAD_PERIOD_SHIFT            (1u)
#define SWB_Timer_PWM_SYNC_KILL_SHIFT            (2u)
#define SWB_Timer_PWM_STOP_KILL_SHIFT            (3u)
#define SWB_Timer_PRESCALER_SHIFT                (8u)
#define SWB_Timer_UPDOWN_SHIFT                   (16u)
#define SWB_Timer_ONESHOT_SHIFT                  (18u)
#define SWB_Timer_QUAD_MODE_SHIFT                (20u)
#define SWB_Timer_INV_OUT_SHIFT                  (20u)
#define SWB_Timer_INV_COMPL_OUT_SHIFT            (21u)
#define SWB_Timer_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define SWB_Timer_RELOAD_CC_MASK                 ((uint32)(SWB_Timer_1BIT_MASK        <<  \
                                                                            SWB_Timer_RELOAD_CC_SHIFT))
#define SWB_Timer_RELOAD_PERIOD_MASK             ((uint32)(SWB_Timer_1BIT_MASK        <<  \
                                                                            SWB_Timer_RELOAD_PERIOD_SHIFT))
#define SWB_Timer_PWM_SYNC_KILL_MASK             ((uint32)(SWB_Timer_1BIT_MASK        <<  \
                                                                            SWB_Timer_PWM_SYNC_KILL_SHIFT))
#define SWB_Timer_PWM_STOP_KILL_MASK             ((uint32)(SWB_Timer_1BIT_MASK        <<  \
                                                                            SWB_Timer_PWM_STOP_KILL_SHIFT))
#define SWB_Timer_PRESCALER_MASK                 ((uint32)(SWB_Timer_8BIT_MASK        <<  \
                                                                            SWB_Timer_PRESCALER_SHIFT))
#define SWB_Timer_UPDOWN_MASK                    ((uint32)(SWB_Timer_2BIT_MASK        <<  \
                                                                            SWB_Timer_UPDOWN_SHIFT))
#define SWB_Timer_ONESHOT_MASK                   ((uint32)(SWB_Timer_1BIT_MASK        <<  \
                                                                            SWB_Timer_ONESHOT_SHIFT))
#define SWB_Timer_QUAD_MODE_MASK                 ((uint32)(SWB_Timer_3BIT_MASK        <<  \
                                                                            SWB_Timer_QUAD_MODE_SHIFT))
#define SWB_Timer_INV_OUT_MASK                   ((uint32)(SWB_Timer_2BIT_MASK        <<  \
                                                                            SWB_Timer_INV_OUT_SHIFT))
#define SWB_Timer_MODE_MASK                      ((uint32)(SWB_Timer_3BIT_MASK        <<  \
                                                                            SWB_Timer_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define SWB_Timer_CAPTURE_SHIFT                  (0u)
#define SWB_Timer_COUNT_SHIFT                    (2u)
#define SWB_Timer_RELOAD_SHIFT                   (4u)
#define SWB_Timer_STOP_SHIFT                     (6u)
#define SWB_Timer_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define SWB_Timer_CAPTURE_MASK                   ((uint32)(SWB_Timer_2BIT_MASK        <<  \
                                                                  SWB_Timer_CAPTURE_SHIFT))
#define SWB_Timer_COUNT_MASK                     ((uint32)(SWB_Timer_2BIT_MASK        <<  \
                                                                  SWB_Timer_COUNT_SHIFT))
#define SWB_Timer_RELOAD_MASK                    ((uint32)(SWB_Timer_2BIT_MASK        <<  \
                                                                  SWB_Timer_RELOAD_SHIFT))
#define SWB_Timer_STOP_MASK                      ((uint32)(SWB_Timer_2BIT_MASK        <<  \
                                                                  SWB_Timer_STOP_SHIFT))
#define SWB_Timer_START_MASK                     ((uint32)(SWB_Timer_2BIT_MASK        <<  \
                                                                  SWB_Timer_START_SHIFT))

/* MASK */
#define SWB_Timer_1BIT_MASK                      ((uint32)0x01u)
#define SWB_Timer_2BIT_MASK                      ((uint32)0x03u)
#define SWB_Timer_3BIT_MASK                      ((uint32)0x07u)
#define SWB_Timer_6BIT_MASK                      ((uint32)0x3Fu)
#define SWB_Timer_8BIT_MASK                      ((uint32)0xFFu)
#define SWB_Timer_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define SWB_Timer_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define SWB_Timer_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(SWB_Timer_QUAD_ENCODING_MODES     << SWB_Timer_QUAD_MODE_SHIFT))       |\
         ((uint32)(SWB_Timer_CONFIG                  << SWB_Timer_MODE_SHIFT)))

#define SWB_Timer_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(SWB_Timer_PWM_STOP_EVENT          << SWB_Timer_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(SWB_Timer_PWM_OUT_INVERT          << SWB_Timer_INV_OUT_SHIFT))         |\
         ((uint32)(SWB_Timer_PWM_OUT_N_INVERT        << SWB_Timer_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(SWB_Timer_PWM_MODE                << SWB_Timer_MODE_SHIFT)))

#define SWB_Timer_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(SWB_Timer_PWM_RUN_MODE         << SWB_Timer_ONESHOT_SHIFT))
            
#define SWB_Timer_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(SWB_Timer_PWM_ALIGN            << SWB_Timer_UPDOWN_SHIFT))

#define SWB_Timer_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(SWB_Timer_PWM_KILL_EVENT      << SWB_Timer_PWM_SYNC_KILL_SHIFT))

#define SWB_Timer_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(SWB_Timer_PWM_DEAD_TIME_CYCLE  << SWB_Timer_PRESCALER_SHIFT))

#define SWB_Timer_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(SWB_Timer_PWM_PRESCALER        << SWB_Timer_PRESCALER_SHIFT))

#define SWB_Timer_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(SWB_Timer_TC_PRESCALER            << SWB_Timer_PRESCALER_SHIFT))       |\
         ((uint32)(SWB_Timer_TC_COUNTER_MODE         << SWB_Timer_UPDOWN_SHIFT))          |\
         ((uint32)(SWB_Timer_TC_RUN_MODE             << SWB_Timer_ONESHOT_SHIFT))         |\
         ((uint32)(SWB_Timer_TC_COMP_CAP_MODE        << SWB_Timer_MODE_SHIFT)))
        
#define SWB_Timer_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(SWB_Timer_QUAD_PHIA_SIGNAL_MODE   << SWB_Timer_COUNT_SHIFT))           |\
         ((uint32)(SWB_Timer_QUAD_INDEX_SIGNAL_MODE  << SWB_Timer_RELOAD_SHIFT))          |\
         ((uint32)(SWB_Timer_QUAD_STOP_SIGNAL_MODE   << SWB_Timer_STOP_SHIFT))            |\
         ((uint32)(SWB_Timer_QUAD_PHIB_SIGNAL_MODE   << SWB_Timer_START_SHIFT)))

#define SWB_Timer_PWM_SIGNALS_MODES                                                              \
        (((uint32)(SWB_Timer_PWM_SWITCH_SIGNAL_MODE  << SWB_Timer_CAPTURE_SHIFT))         |\
         ((uint32)(SWB_Timer_PWM_COUNT_SIGNAL_MODE   << SWB_Timer_COUNT_SHIFT))           |\
         ((uint32)(SWB_Timer_PWM_RELOAD_SIGNAL_MODE  << SWB_Timer_RELOAD_SHIFT))          |\
         ((uint32)(SWB_Timer_PWM_STOP_SIGNAL_MODE    << SWB_Timer_STOP_SHIFT))            |\
         ((uint32)(SWB_Timer_PWM_START_SIGNAL_MODE   << SWB_Timer_START_SHIFT)))

#define SWB_Timer_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(SWB_Timer_TC_CAPTURE_SIGNAL_MODE  << SWB_Timer_CAPTURE_SHIFT))         |\
         ((uint32)(SWB_Timer_TC_COUNT_SIGNAL_MODE    << SWB_Timer_COUNT_SHIFT))           |\
         ((uint32)(SWB_Timer_TC_RELOAD_SIGNAL_MODE   << SWB_Timer_RELOAD_SHIFT))          |\
         ((uint32)(SWB_Timer_TC_STOP_SIGNAL_MODE     << SWB_Timer_STOP_SHIFT))            |\
         ((uint32)(SWB_Timer_TC_START_SIGNAL_MODE    << SWB_Timer_START_SHIFT)))
        
#define SWB_Timer_TIMER_UPDOWN_CNT_USED                                                          \
                ((SWB_Timer__COUNT_UPDOWN0 == SWB_Timer_TC_COUNTER_MODE)                  ||\
                 (SWB_Timer__COUNT_UPDOWN1 == SWB_Timer_TC_COUNTER_MODE))

#define SWB_Timer_PWM_UPDOWN_CNT_USED                                                            \
                ((SWB_Timer__CENTER == SWB_Timer_PWM_ALIGN)                               ||\
                 (SWB_Timer__ASYMMETRIC == SWB_Timer_PWM_ALIGN))               
        
#define SWB_Timer_PWM_PR_INIT_VALUE              (1u)
#define SWB_Timer_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_SWB_Timer_H */

/* [] END OF FILE */
