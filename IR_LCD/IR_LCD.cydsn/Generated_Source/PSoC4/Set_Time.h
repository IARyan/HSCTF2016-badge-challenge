/*******************************************************************************
* File Name: Set_Time.h  
* Version 2.5
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Set_Time_H) /* Pins Set_Time_H */
#define CY_PINS_Set_Time_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Set_Time_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Set_Time_Write(uint8 value) ;
void    Set_Time_SetDriveMode(uint8 mode) ;
uint8   Set_Time_ReadDataReg(void) ;
uint8   Set_Time_Read(void) ;
uint8   Set_Time_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Set_Time_DRIVE_MODE_BITS        (3)
#define Set_Time_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Set_Time_DRIVE_MODE_BITS))
#define Set_Time_DRIVE_MODE_SHIFT       (0x00u)
#define Set_Time_DRIVE_MODE_MASK        (0x07u << Set_Time_DRIVE_MODE_SHIFT)

#define Set_Time_DM_ALG_HIZ         (0x00u << Set_Time_DRIVE_MODE_SHIFT)
#define Set_Time_DM_DIG_HIZ         (0x01u << Set_Time_DRIVE_MODE_SHIFT)
#define Set_Time_DM_RES_UP          (0x02u << Set_Time_DRIVE_MODE_SHIFT)
#define Set_Time_DM_RES_DWN         (0x03u << Set_Time_DRIVE_MODE_SHIFT)
#define Set_Time_DM_OD_LO           (0x04u << Set_Time_DRIVE_MODE_SHIFT)
#define Set_Time_DM_OD_HI           (0x05u << Set_Time_DRIVE_MODE_SHIFT)
#define Set_Time_DM_STRONG          (0x06u << Set_Time_DRIVE_MODE_SHIFT)
#define Set_Time_DM_RES_UPDWN       (0x07u << Set_Time_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Set_Time_MASK               Set_Time__MASK
#define Set_Time_SHIFT              Set_Time__SHIFT
#define Set_Time_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Set_Time_PS                     (* (reg32 *) Set_Time__PS)
/* Port Configuration */
#define Set_Time_PC                     (* (reg32 *) Set_Time__PC)
/* Data Register */
#define Set_Time_DR                     (* (reg32 *) Set_Time__DR)
/* Input Buffer Disable Override */
#define Set_Time_INP_DIS                (* (reg32 *) Set_Time__PC2)


#if defined(Set_Time__INTSTAT)  /* Interrupt Registers */

    #define Set_Time_INTSTAT                (* (reg32 *) Set_Time__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Set_Time_H */


/* [] END OF FILE */
