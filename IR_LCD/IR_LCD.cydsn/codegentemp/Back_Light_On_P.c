/*******************************************************************************
* File Name: Back_Light_On_P.c  
* Version 2.5
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
#include "Back_Light_On_P.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Back_Light_On_P_PC =   (Back_Light_On_P_PC & \
                                (uint32)(~(uint32)(Back_Light_On_P_DRIVE_MODE_IND_MASK << (Back_Light_On_P_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Back_Light_On_P_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Back_Light_On_P_Write
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
void Back_Light_On_P_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Back_Light_On_P_DR & (uint8)(~Back_Light_On_P_MASK));
    drVal = (drVal | ((uint8)(value << Back_Light_On_P_SHIFT) & Back_Light_On_P_MASK));
    Back_Light_On_P_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Back_Light_On_P_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Back_Light_On_P_DM_STRONG     Strong Drive 
*  Back_Light_On_P_DM_OD_HI      Open Drain, Drives High 
*  Back_Light_On_P_DM_OD_LO      Open Drain, Drives Low 
*  Back_Light_On_P_DM_RES_UP     Resistive Pull Up 
*  Back_Light_On_P_DM_RES_DWN    Resistive Pull Down 
*  Back_Light_On_P_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Back_Light_On_P_DM_DIG_HIZ    High Impedance Digital 
*  Back_Light_On_P_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Back_Light_On_P_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Back_Light_On_P__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Back_Light_On_P_Read
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
*  Macro Back_Light_On_P_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Back_Light_On_P_Read(void) 
{
    return (uint8)((Back_Light_On_P_PS & Back_Light_On_P_MASK) >> Back_Light_On_P_SHIFT);
}


/*******************************************************************************
* Function Name: Back_Light_On_P_ReadDataReg
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
uint8 Back_Light_On_P_ReadDataReg(void) 
{
    return (uint8)((Back_Light_On_P_DR & Back_Light_On_P_MASK) >> Back_Light_On_P_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Back_Light_On_P_INTSTAT) 

    /*******************************************************************************
    * Function Name: Back_Light_On_P_ClearInterrupt
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
    uint8 Back_Light_On_P_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Back_Light_On_P_INTSTAT & Back_Light_On_P_MASK);
		Back_Light_On_P_INTSTAT = maskedStatus;
        return maskedStatus >> Back_Light_On_P_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
