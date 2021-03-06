/*******************************************************************************
* File Name: Right_LED_Green.c  
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
#include "Right_LED_Green.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Right_LED_Green_PC =   (Right_LED_Green_PC & \
                                (uint32)(~(uint32)(Right_LED_Green_DRIVE_MODE_IND_MASK << (Right_LED_Green_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Right_LED_Green_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Right_LED_Green_Write
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
void Right_LED_Green_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Right_LED_Green_DR & (uint8)(~Right_LED_Green_MASK));
    drVal = (drVal | ((uint8)(value << Right_LED_Green_SHIFT) & Right_LED_Green_MASK));
    Right_LED_Green_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Right_LED_Green_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Right_LED_Green_DM_STRONG     Strong Drive 
*  Right_LED_Green_DM_OD_HI      Open Drain, Drives High 
*  Right_LED_Green_DM_OD_LO      Open Drain, Drives Low 
*  Right_LED_Green_DM_RES_UP     Resistive Pull Up 
*  Right_LED_Green_DM_RES_DWN    Resistive Pull Down 
*  Right_LED_Green_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Right_LED_Green_DM_DIG_HIZ    High Impedance Digital 
*  Right_LED_Green_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Right_LED_Green_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Right_LED_Green__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Right_LED_Green_Read
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
*  Macro Right_LED_Green_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Right_LED_Green_Read(void) 
{
    return (uint8)((Right_LED_Green_PS & Right_LED_Green_MASK) >> Right_LED_Green_SHIFT);
}


/*******************************************************************************
* Function Name: Right_LED_Green_ReadDataReg
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
uint8 Right_LED_Green_ReadDataReg(void) 
{
    return (uint8)((Right_LED_Green_DR & Right_LED_Green_MASK) >> Right_LED_Green_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Right_LED_Green_INTSTAT) 

    /*******************************************************************************
    * Function Name: Right_LED_Green_ClearInterrupt
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
    uint8 Right_LED_Green_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Right_LED_Green_INTSTAT & Right_LED_Green_MASK);
		Right_LED_Green_INTSTAT = maskedStatus;
        return maskedStatus >> Right_LED_Green_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
