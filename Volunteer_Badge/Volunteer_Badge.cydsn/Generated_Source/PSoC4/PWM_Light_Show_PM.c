/*******************************************************************************
* File Name: PWM_Light_Show_PM.c
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

#include "PWM_Light_Show.h"

static PWM_Light_Show_backupStruct PWM_Light_Show_backup;


/*******************************************************************************
* Function Name: PWM_Light_Show_SaveConfig
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
*  PWM_Light_Show_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Light_Show_SaveConfig(void) 
{

    #if(!PWM_Light_Show_UsingFixedFunction)
        #if(!PWM_Light_Show_PWMModeIsCenterAligned)
            PWM_Light_Show_backup.PWMPeriod = PWM_Light_Show_ReadPeriod();
        #endif /* (!PWM_Light_Show_PWMModeIsCenterAligned) */
        PWM_Light_Show_backup.PWMUdb = PWM_Light_Show_ReadCounter();
        #if (PWM_Light_Show_UseStatus)
            PWM_Light_Show_backup.InterruptMaskValue = PWM_Light_Show_STATUS_MASK;
        #endif /* (PWM_Light_Show_UseStatus) */

        #if(PWM_Light_Show_DeadBandMode == PWM_Light_Show__B_PWM__DBM_256_CLOCKS || \
            PWM_Light_Show_DeadBandMode == PWM_Light_Show__B_PWM__DBM_2_4_CLOCKS)
            PWM_Light_Show_backup.PWMdeadBandValue = PWM_Light_Show_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Light_Show_KillModeMinTime)
             PWM_Light_Show_backup.PWMKillCounterPeriod = PWM_Light_Show_ReadKillTime();
        #endif /* (PWM_Light_Show_KillModeMinTime) */

        #if(PWM_Light_Show_UseControl)
            PWM_Light_Show_backup.PWMControlRegister = PWM_Light_Show_ReadControlRegister();
        #endif /* (PWM_Light_Show_UseControl) */
    #endif  /* (!PWM_Light_Show_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Light_Show_RestoreConfig
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
*  PWM_Light_Show_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Light_Show_RestoreConfig(void) 
{
        #if(!PWM_Light_Show_UsingFixedFunction)
            #if(!PWM_Light_Show_PWMModeIsCenterAligned)
                PWM_Light_Show_WritePeriod(PWM_Light_Show_backup.PWMPeriod);
            #endif /* (!PWM_Light_Show_PWMModeIsCenterAligned) */

            PWM_Light_Show_WriteCounter(PWM_Light_Show_backup.PWMUdb);

            #if (PWM_Light_Show_UseStatus)
                PWM_Light_Show_STATUS_MASK = PWM_Light_Show_backup.InterruptMaskValue;
            #endif /* (PWM_Light_Show_UseStatus) */

            #if(PWM_Light_Show_DeadBandMode == PWM_Light_Show__B_PWM__DBM_256_CLOCKS || \
                PWM_Light_Show_DeadBandMode == PWM_Light_Show__B_PWM__DBM_2_4_CLOCKS)
                PWM_Light_Show_WriteDeadTime(PWM_Light_Show_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Light_Show_KillModeMinTime)
                PWM_Light_Show_WriteKillTime(PWM_Light_Show_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Light_Show_KillModeMinTime) */

            #if(PWM_Light_Show_UseControl)
                PWM_Light_Show_WriteControlRegister(PWM_Light_Show_backup.PWMControlRegister);
            #endif /* (PWM_Light_Show_UseControl) */
        #endif  /* (!PWM_Light_Show_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Light_Show_Sleep
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
*  PWM_Light_Show_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Light_Show_Sleep(void) 
{
    #if(PWM_Light_Show_UseControl)
        if(PWM_Light_Show_CTRL_ENABLE == (PWM_Light_Show_CONTROL & PWM_Light_Show_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Light_Show_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Light_Show_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Light_Show_UseControl) */

    /* Stop component */
    PWM_Light_Show_Stop();

    /* Save registers configuration */
    PWM_Light_Show_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Light_Show_Wakeup
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
*  PWM_Light_Show_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Light_Show_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Light_Show_RestoreConfig();

    if(PWM_Light_Show_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Light_Show_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
