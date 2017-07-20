/*******************************************************************************
* File Name: PWM_Organizer_PM.c
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

#include "PWM_Organizer.h"

static PWM_Organizer_backupStruct PWM_Organizer_backup;


/*******************************************************************************
* Function Name: PWM_Organizer_SaveConfig
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
*  PWM_Organizer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Organizer_SaveConfig(void) 
{

    #if(!PWM_Organizer_UsingFixedFunction)
        #if(!PWM_Organizer_PWMModeIsCenterAligned)
            PWM_Organizer_backup.PWMPeriod = PWM_Organizer_ReadPeriod();
        #endif /* (!PWM_Organizer_PWMModeIsCenterAligned) */
        PWM_Organizer_backup.PWMUdb = PWM_Organizer_ReadCounter();
        #if (PWM_Organizer_UseStatus)
            PWM_Organizer_backup.InterruptMaskValue = PWM_Organizer_STATUS_MASK;
        #endif /* (PWM_Organizer_UseStatus) */

        #if(PWM_Organizer_DeadBandMode == PWM_Organizer__B_PWM__DBM_256_CLOCKS || \
            PWM_Organizer_DeadBandMode == PWM_Organizer__B_PWM__DBM_2_4_CLOCKS)
            PWM_Organizer_backup.PWMdeadBandValue = PWM_Organizer_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Organizer_KillModeMinTime)
             PWM_Organizer_backup.PWMKillCounterPeriod = PWM_Organizer_ReadKillTime();
        #endif /* (PWM_Organizer_KillModeMinTime) */

        #if(PWM_Organizer_UseControl)
            PWM_Organizer_backup.PWMControlRegister = PWM_Organizer_ReadControlRegister();
        #endif /* (PWM_Organizer_UseControl) */
    #endif  /* (!PWM_Organizer_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Organizer_RestoreConfig
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
*  PWM_Organizer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Organizer_RestoreConfig(void) 
{
        #if(!PWM_Organizer_UsingFixedFunction)
            #if(!PWM_Organizer_PWMModeIsCenterAligned)
                PWM_Organizer_WritePeriod(PWM_Organizer_backup.PWMPeriod);
            #endif /* (!PWM_Organizer_PWMModeIsCenterAligned) */

            PWM_Organizer_WriteCounter(PWM_Organizer_backup.PWMUdb);

            #if (PWM_Organizer_UseStatus)
                PWM_Organizer_STATUS_MASK = PWM_Organizer_backup.InterruptMaskValue;
            #endif /* (PWM_Organizer_UseStatus) */

            #if(PWM_Organizer_DeadBandMode == PWM_Organizer__B_PWM__DBM_256_CLOCKS || \
                PWM_Organizer_DeadBandMode == PWM_Organizer__B_PWM__DBM_2_4_CLOCKS)
                PWM_Organizer_WriteDeadTime(PWM_Organizer_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Organizer_KillModeMinTime)
                PWM_Organizer_WriteKillTime(PWM_Organizer_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Organizer_KillModeMinTime) */

            #if(PWM_Organizer_UseControl)
                PWM_Organizer_WriteControlRegister(PWM_Organizer_backup.PWMControlRegister);
            #endif /* (PWM_Organizer_UseControl) */
        #endif  /* (!PWM_Organizer_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Organizer_Sleep
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
*  PWM_Organizer_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Organizer_Sleep(void) 
{
    #if(PWM_Organizer_UseControl)
        if(PWM_Organizer_CTRL_ENABLE == (PWM_Organizer_CONTROL & PWM_Organizer_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Organizer_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Organizer_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Organizer_UseControl) */

    /* Stop component */
    PWM_Organizer_Stop();

    /* Save registers configuration */
    PWM_Organizer_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Organizer_Wakeup
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
*  PWM_Organizer_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Organizer_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Organizer_RestoreConfig();

    if(PWM_Organizer_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Organizer_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
