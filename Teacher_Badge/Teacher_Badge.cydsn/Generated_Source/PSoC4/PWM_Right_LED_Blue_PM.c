/*******************************************************************************
* File Name: PWM_Right_LED_Blue_PM.c
* Version 3.10
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_Right_LED_Blue.h"

static PWM_Right_LED_Blue_backupStruct PWM_Right_LED_Blue_backup;


/*******************************************************************************
* Function Name: PWM_Right_LED_Blue_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Right_LED_Blue_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Right_LED_Blue_SaveConfig(void) 
{

    #if(!PWM_Right_LED_Blue_UsingFixedFunction)
        #if(!PWM_Right_LED_Blue_PWMModeIsCenterAligned)
            PWM_Right_LED_Blue_backup.PWMPeriod = PWM_Right_LED_Blue_ReadPeriod();
        #endif /* (!PWM_Right_LED_Blue_PWMModeIsCenterAligned) */
        PWM_Right_LED_Blue_backup.PWMUdb = PWM_Right_LED_Blue_ReadCounter();
        #if (PWM_Right_LED_Blue_UseStatus)
            PWM_Right_LED_Blue_backup.InterruptMaskValue = PWM_Right_LED_Blue_STATUS_MASK;
        #endif /* (PWM_Right_LED_Blue_UseStatus) */

        #if(PWM_Right_LED_Blue_DeadBandMode == PWM_Right_LED_Blue__B_PWM__DBM_256_CLOCKS || \
            PWM_Right_LED_Blue_DeadBandMode == PWM_Right_LED_Blue__B_PWM__DBM_2_4_CLOCKS)
            PWM_Right_LED_Blue_backup.PWMdeadBandValue = PWM_Right_LED_Blue_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Right_LED_Blue_KillModeMinTime)
             PWM_Right_LED_Blue_backup.PWMKillCounterPeriod = PWM_Right_LED_Blue_ReadKillTime();
        #endif /* (PWM_Right_LED_Blue_KillModeMinTime) */

        #if(PWM_Right_LED_Blue_UseControl)
            PWM_Right_LED_Blue_backup.PWMControlRegister = PWM_Right_LED_Blue_ReadControlRegister();
        #endif /* (PWM_Right_LED_Blue_UseControl) */
    #endif  /* (!PWM_Right_LED_Blue_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Right_LED_Blue_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Right_LED_Blue_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Right_LED_Blue_RestoreConfig(void) 
{
        #if(!PWM_Right_LED_Blue_UsingFixedFunction)
            #if(!PWM_Right_LED_Blue_PWMModeIsCenterAligned)
                PWM_Right_LED_Blue_WritePeriod(PWM_Right_LED_Blue_backup.PWMPeriod);
            #endif /* (!PWM_Right_LED_Blue_PWMModeIsCenterAligned) */

            PWM_Right_LED_Blue_WriteCounter(PWM_Right_LED_Blue_backup.PWMUdb);

            #if (PWM_Right_LED_Blue_UseStatus)
                PWM_Right_LED_Blue_STATUS_MASK = PWM_Right_LED_Blue_backup.InterruptMaskValue;
            #endif /* (PWM_Right_LED_Blue_UseStatus) */

            #if(PWM_Right_LED_Blue_DeadBandMode == PWM_Right_LED_Blue__B_PWM__DBM_256_CLOCKS || \
                PWM_Right_LED_Blue_DeadBandMode == PWM_Right_LED_Blue__B_PWM__DBM_2_4_CLOCKS)
                PWM_Right_LED_Blue_WriteDeadTime(PWM_Right_LED_Blue_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Right_LED_Blue_KillModeMinTime)
                PWM_Right_LED_Blue_WriteKillTime(PWM_Right_LED_Blue_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Right_LED_Blue_KillModeMinTime) */

            #if(PWM_Right_LED_Blue_UseControl)
                PWM_Right_LED_Blue_WriteControlRegister(PWM_Right_LED_Blue_backup.PWMControlRegister);
            #endif /* (PWM_Right_LED_Blue_UseControl) */
        #endif  /* (!PWM_Right_LED_Blue_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Right_LED_Blue_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Right_LED_Blue_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Right_LED_Blue_Sleep(void) 
{
    #if(PWM_Right_LED_Blue_UseControl)
        if(PWM_Right_LED_Blue_CTRL_ENABLE == (PWM_Right_LED_Blue_CONTROL & PWM_Right_LED_Blue_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Right_LED_Blue_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Right_LED_Blue_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Right_LED_Blue_UseControl) */

    /* Stop component */
    PWM_Right_LED_Blue_Stop();

    /* Save registers configuration */
    PWM_Right_LED_Blue_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Right_LED_Blue_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Right_LED_Blue_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Right_LED_Blue_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Right_LED_Blue_RestoreConfig();

    if(PWM_Right_LED_Blue_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Right_LED_Blue_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
