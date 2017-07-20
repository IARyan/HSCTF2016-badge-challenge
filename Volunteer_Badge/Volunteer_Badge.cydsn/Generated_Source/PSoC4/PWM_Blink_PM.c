/*******************************************************************************
* File Name: PWM_Blink_PM.c
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

#include "PWM_Blink.h"

static PWM_Blink_backupStruct PWM_Blink_backup;


/*******************************************************************************
* Function Name: PWM_Blink_SaveConfig
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
*  PWM_Blink_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Blink_SaveConfig(void) 
{

    #if(!PWM_Blink_UsingFixedFunction)
        #if(!PWM_Blink_PWMModeIsCenterAligned)
            PWM_Blink_backup.PWMPeriod = PWM_Blink_ReadPeriod();
        #endif /* (!PWM_Blink_PWMModeIsCenterAligned) */
        PWM_Blink_backup.PWMUdb = PWM_Blink_ReadCounter();
        #if (PWM_Blink_UseStatus)
            PWM_Blink_backup.InterruptMaskValue = PWM_Blink_STATUS_MASK;
        #endif /* (PWM_Blink_UseStatus) */

        #if(PWM_Blink_DeadBandMode == PWM_Blink__B_PWM__DBM_256_CLOCKS || \
            PWM_Blink_DeadBandMode == PWM_Blink__B_PWM__DBM_2_4_CLOCKS)
            PWM_Blink_backup.PWMdeadBandValue = PWM_Blink_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Blink_KillModeMinTime)
             PWM_Blink_backup.PWMKillCounterPeriod = PWM_Blink_ReadKillTime();
        #endif /* (PWM_Blink_KillModeMinTime) */

        #if(PWM_Blink_UseControl)
            PWM_Blink_backup.PWMControlRegister = PWM_Blink_ReadControlRegister();
        #endif /* (PWM_Blink_UseControl) */
    #endif  /* (!PWM_Blink_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Blink_RestoreConfig
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
*  PWM_Blink_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Blink_RestoreConfig(void) 
{
        #if(!PWM_Blink_UsingFixedFunction)
            #if(!PWM_Blink_PWMModeIsCenterAligned)
                PWM_Blink_WritePeriod(PWM_Blink_backup.PWMPeriod);
            #endif /* (!PWM_Blink_PWMModeIsCenterAligned) */

            PWM_Blink_WriteCounter(PWM_Blink_backup.PWMUdb);

            #if (PWM_Blink_UseStatus)
                PWM_Blink_STATUS_MASK = PWM_Blink_backup.InterruptMaskValue;
            #endif /* (PWM_Blink_UseStatus) */

            #if(PWM_Blink_DeadBandMode == PWM_Blink__B_PWM__DBM_256_CLOCKS || \
                PWM_Blink_DeadBandMode == PWM_Blink__B_PWM__DBM_2_4_CLOCKS)
                PWM_Blink_WriteDeadTime(PWM_Blink_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Blink_KillModeMinTime)
                PWM_Blink_WriteKillTime(PWM_Blink_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Blink_KillModeMinTime) */

            #if(PWM_Blink_UseControl)
                PWM_Blink_WriteControlRegister(PWM_Blink_backup.PWMControlRegister);
            #endif /* (PWM_Blink_UseControl) */
        #endif  /* (!PWM_Blink_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Blink_Sleep
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
*  PWM_Blink_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Blink_Sleep(void) 
{
    #if(PWM_Blink_UseControl)
        if(PWM_Blink_CTRL_ENABLE == (PWM_Blink_CONTROL & PWM_Blink_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Blink_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Blink_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Blink_UseControl) */

    /* Stop component */
    PWM_Blink_Stop();

    /* Save registers configuration */
    PWM_Blink_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Blink_Wakeup
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
*  PWM_Blink_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Blink_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Blink_RestoreConfig();

    if(PWM_Blink_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Blink_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
