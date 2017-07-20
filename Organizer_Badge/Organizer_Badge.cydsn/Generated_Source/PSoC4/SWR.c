/*******************************************************************************
* File Name: SWR.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SWR.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SWR_PC =   (SWR_PC & \
                                (uint32)(~(uint32)(SWR_DRIVE_MODE_IND_MASK << (SWR_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SWR_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SWR_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void SWR_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SWR_DR & (uint8)(~SWR_MASK));
    drVal = (drVal | ((uint8)(value << SWR_SHIFT) & SWR_MASK));
    SWR_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SWR_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SWR_DM_STRONG     Strong Drive 
*  SWR_DM_OD_HI      Open Drain, Drives High 
*  SWR_DM_OD_LO      Open Drain, Drives Low 
*  SWR_DM_RES_UP     Resistive Pull Up 
*  SWR_DM_RES_DWN    Resistive Pull Down 
*  SWR_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SWR_DM_DIG_HIZ    High Impedance Digital 
*  SWR_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SWR_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SWR__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SWR_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro SWR_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SWR_Read(void) 
{
    return (uint8)((SWR_PS & SWR_MASK) >> SWR_SHIFT);
}


/*******************************************************************************
* Function Name: SWR_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 SWR_ReadDataReg(void) 
{
    return (uint8)((SWR_DR & SWR_MASK) >> SWR_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SWR_INTSTAT) 

    /*******************************************************************************
    * Function Name: SWR_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 SWR_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SWR_INTSTAT & SWR_MASK);
		SWR_INTSTAT = maskedStatus;
        return maskedStatus >> SWR_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
