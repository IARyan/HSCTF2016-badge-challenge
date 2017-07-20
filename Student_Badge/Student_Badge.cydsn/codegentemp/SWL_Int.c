/*******************************************************************************
* File Name: SWL_Int.c  
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
#include <SWL_Int.h>

#if !defined(SWL_Int__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START SWL_Int_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: SWL_Int_Start
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
void SWL_Int_Start(void)
{
    /* For all we know the interrupt is active. */
    SWL_Int_Disable();

    /* Set the ISR to point to the SWL_Int Interrupt. */
    SWL_Int_SetVector(&SWL_Int_Interrupt);

    /* Set the priority. */
    SWL_Int_SetPriority((uint8)SWL_Int_INTC_PRIOR_NUMBER);

    /* Enable it. */
    SWL_Int_Enable();
}


/*******************************************************************************
* Function Name: SWL_Int_StartEx
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
void SWL_Int_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    SWL_Int_Disable();

    /* Set the ISR to point to the SWL_Int Interrupt. */
    SWL_Int_SetVector(address);

    /* Set the priority. */
    SWL_Int_SetPriority((uint8)SWL_Int_INTC_PRIOR_NUMBER);

    /* Enable it. */
    SWL_Int_Enable();
}


/*******************************************************************************
* Function Name: SWL_Int_Stop
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
void SWL_Int_Stop(void)
{
    /* Disable this interrupt. */
    SWL_Int_Disable();

    /* Set the ISR to point to the passive one. */
    SWL_Int_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: SWL_Int_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for SWL_Int.
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
CY_ISR(SWL_Int_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START SWL_Int_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: SWL_Int_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling SWL_Int_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use SWL_Int_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void SWL_Int_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + SWL_Int__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: SWL_Int_GetVector
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
cyisraddress SWL_Int_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + SWL_Int__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: SWL_Int_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling SWL_Int_Start
*   or SWL_Int_StartEx will override any effect this method would 
*   have had. This method should only be called after SWL_Int_Start or 
*   SWL_Int_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void SWL_Int_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((SWL_Int__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *SWL_Int_INTC_PRIOR = (*SWL_Int_INTC_PRIOR & (uint32)(~SWL_Int__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SWL_Int_GetPriority
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
uint8 SWL_Int_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((SWL_Int__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*SWL_Int_INTC_PRIOR & SWL_Int__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: SWL_Int_Enable
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
void SWL_Int_Enable(void)
{
    /* Enable the general interrupt. */
    *SWL_Int_INTC_SET_EN = SWL_Int__INTC_MASK;
}


/*******************************************************************************
* Function Name: SWL_Int_GetState
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
uint8 SWL_Int_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*SWL_Int_INTC_SET_EN & (uint32)SWL_Int__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: SWL_Int_Disable
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
void SWL_Int_Disable(void)
{
    /* Disable the general interrupt. */
    *SWL_Int_INTC_CLR_EN = SWL_Int__INTC_MASK;
}


/*******************************************************************************
* Function Name: SWL_Int_SetPending
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
void SWL_Int_SetPending(void)
{
    *SWL_Int_INTC_SET_PD = SWL_Int__INTC_MASK;
}


/*******************************************************************************
* Function Name: SWL_Int_ClearPending
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
void SWL_Int_ClearPending(void)
{
    *SWL_Int_INTC_CLR_PD = SWL_Int__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
