/*******************************************************************************
* File Name: SWL.c  
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
#include "SWL.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SWL_PC =   (SWL_PC & \
                                (uint32)(~(uint32)(SWL_DRIVE_MODE_IND_MASK << (SWL_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SWL_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SWL_Write
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
void SWL_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SWL_DR & (uint8)(~SWL_MASK));
    drVal = (drVal | ((uint8)(value << SWL_SHIFT) & SWL_MASK));
    SWL_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SWL_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SWL_DM_STRONG     Strong Drive 
*  SWL_DM_OD_HI      Open Drain, Drives High 
*  SWL_DM_OD_LO      Open Drain, Drives Low 
*  SWL_DM_RES_UP     Resistive Pull Up 
*  SWL_DM_RES_DWN    Resistive Pull Down 
*  SWL_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SWL_DM_DIG_HIZ    High Impedance Digital 
*  SWL_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SWL_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SWL__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SWL_Read
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
*  Macro SWL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SWL_Read(void) 
{
    return (uint8)((SWL_PS & SWL_MASK) >> SWL_SHIFT);
}


/*******************************************************************************
* Function Name: SWL_ReadDataReg
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
uint8 SWL_ReadDataReg(void) 
{
    return (uint8)((SWL_DR & SWL_MASK) >> SWL_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SWL_INTSTAT) 

    /*******************************************************************************
    * Function Name: SWL_ClearInterrupt
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
    uint8 SWL_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SWL_INTSTAT & SWL_MASK);
		SWL_INTSTAT = maskedStatus;
        return maskedStatus >> SWL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
