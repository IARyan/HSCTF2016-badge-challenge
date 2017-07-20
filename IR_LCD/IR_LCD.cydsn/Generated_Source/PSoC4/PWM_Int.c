/*******************************************************************************
* File Name: PWM_Int.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <PWM_Int.h>

#if !defined(PWM_Int__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START PWM_Int_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: PWM_Int_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void PWM_Int_Start(void)
{
    /* For all we know the interrupt is active. */
    PWM_Int_Disable();

    /* Set the ISR to point to the PWM_Int Interrupt. */
    PWM_Int_SetVector(&PWM_Int_Interrupt);

    /* Set the priority. */
    PWM_Int_SetPriority((uint8)PWM_Int_INTC_PRIOR_NUMBER);

    /* Enable it. */
    PWM_Int_Enable();
}


/*******************************************************************************
* Function Name: PWM_Int_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void PWM_Int_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    PWM_Int_Disable();

    /* Set the ISR to point to the PWM_Int Interrupt. */
    PWM_Int_SetVector(address);

    /* Set the priority. */
    PWM_Int_SetPriority((uint8)PWM_Int_INTC_PRIOR_NUMBER);

    /* Enable it. */
    PWM_Int_Enable();
}


/*******************************************************************************
* Function Name: PWM_Int_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void PWM_Int_Stop(void)
{
    /* Disable this interrupt. */
    PWM_Int_Disable();

    /* Set the ISR to point to the passive one. */
    PWM_Int_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: PWM_Int_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for PWM_Int.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(PWM_Int_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START PWM_Int_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: PWM_Int_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling PWM_Int_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use PWM_Int_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void PWM_Int_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + PWM_Int__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: PWM_Int_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress PWM_Int_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + PWM_Int__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: PWM_Int_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling PWM_Int_Start
*   or PWM_Int_StartEx will override any effect this method would 
*   have had. This method should only be called after PWM_Int_Start or 
*   PWM_Int_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void PWM_Int_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((PWM_Int__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *PWM_Int_INTC_PRIOR = (*PWM_Int_INTC_PRIOR & (uint32)(~PWM_Int__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: PWM_Int_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 3, 0 being the highest.
*
*******************************************************************************/
uint8 PWM_Int_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((PWM_Int__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*PWM_Int_INTC_PRIOR & PWM_Int__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: PWM_Int_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void PWM_Int_Enable(void)
{
    /* Enable the general interrupt. */
    *PWM_Int_INTC_SET_EN = PWM_Int__INTC_MASK;
}


/*******************************************************************************
* Function Name: PWM_Int_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 PWM_Int_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*PWM_Int_INTC_SET_EN & (uint32)PWM_Int__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: PWM_Int_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void PWM_Int_Disable(void)
{
    /* Disable the general interrupt. */
    *PWM_Int_INTC_CLR_EN = PWM_Int__INTC_MASK;
}


/*******************************************************************************
* Function Name: PWM_Int_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void PWM_Int_SetPending(void)
{
    *PWM_Int_INTC_SET_PD = PWM_Int__INTC_MASK;
}


/*******************************************************************************
* Function Name: PWM_Int_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void PWM_Int_ClearPending(void)
{
    *PWM_Int_INTC_CLR_PD = PWM_Int__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
