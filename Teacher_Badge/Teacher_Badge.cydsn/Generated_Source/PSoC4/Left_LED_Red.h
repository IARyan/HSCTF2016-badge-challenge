/*******************************************************************************
* File Name: Left_LED_Red.h  
* Version 2.10
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

#if !defined(CY_PINS_Left_LED_Red_H) /* Pins Left_LED_Red_H */
#define CY_PINS_Left_LED_Red_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Left_LED_Red_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Left_LED_Red_Write(uint8 value) ;
void    Left_LED_Red_SetDriveMode(uint8 mode) ;
uint8   Left_LED_Red_ReadDataReg(void) ;
uint8   Left_LED_Red_Read(void) ;
uint8   Left_LED_Red_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Left_LED_Red_DRIVE_MODE_BITS        (3)
#define Left_LED_Red_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Left_LED_Red_DRIVE_MODE_BITS))

#define Left_LED_Red_DM_ALG_HIZ         (0x00u)
#define Left_LED_Red_DM_DIG_HIZ         (0x01u)
#define Left_LED_Red_DM_RES_UP          (0x02u)
#define Left_LED_Red_DM_RES_DWN         (0x03u)
#define Left_LED_Red_DM_OD_LO           (0x04u)
#define Left_LED_Red_DM_OD_HI           (0x05u)
#define Left_LED_Red_DM_STRONG          (0x06u)
#define Left_LED_Red_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Left_LED_Red_MASK               Left_LED_Red__MASK
#define Left_LED_Red_SHIFT              Left_LED_Red__SHIFT
#define Left_LED_Red_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Left_LED_Red_PS                     (* (reg32 *) Left_LED_Red__PS)
/* Port Configuration */
#define Left_LED_Red_PC                     (* (reg32 *) Left_LED_Red__PC)
/* Data Register */
#define Left_LED_Red_DR                     (* (reg32 *) Left_LED_Red__DR)
/* Input Buffer Disable Override */
#define Left_LED_Red_INP_DIS                (* (reg32 *) Left_LED_Red__PC2)


#if defined(Left_LED_Red__INTSTAT)  /* Interrupt Registers */

    #define Left_LED_Red_INTSTAT                (* (reg32 *) Left_LED_Red__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Left_LED_Red_DRIVE_MODE_SHIFT       (0x00u)
#define Left_LED_Red_DRIVE_MODE_MASK        (0x07u << Left_LED_Red_DRIVE_MODE_SHIFT)


#endif /* End Pins Left_LED_Red_H */


/* [] END OF FILE */
