/*******************************************************************************
* File Name: SWB_Timer_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
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

#include "SWB_Timer.h"

static SWB_Timer_BACKUP_STRUCT SWB_Timer_backup;


/*******************************************************************************
* Function Name: SWB_Timer_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SWB_Timer_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: SWB_Timer_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SWB_Timer_Sleep(void)
{
    if(0u != (SWB_Timer_BLOCK_CONTROL_REG & SWB_Timer_MASK))
    {
        SWB_Timer_backup.enableState = 1u;
    }
    else
    {
        SWB_Timer_backup.enableState = 0u;
    }

    SWB_Timer_Stop();
    SWB_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: SWB_Timer_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SWB_Timer_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: SWB_Timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SWB_Timer_Wakeup(void)
{
    SWB_Timer_RestoreConfig();

    if(0u != SWB_Timer_backup.enableState)
    {
        SWB_Timer_Enable();
    }
}


/* [] END OF FILE */
