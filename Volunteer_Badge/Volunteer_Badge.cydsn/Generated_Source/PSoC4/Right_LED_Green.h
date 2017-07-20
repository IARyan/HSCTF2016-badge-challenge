/*******************************************************************************
* File Name: Right_LED_Green.h  
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

#if !defined(CY_PINS_Right_LED_Green_H) /* Pins Right_LED_Green_H */
#define CY_PINS_Right_LED_Green_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Right_LED_Green_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Right_LED_Green_Write(uint8 value) ;
void    Right_LED_Green_SetDriveMode(uint8 mode) ;
uint8   Right_LED_Green_ReadDataReg(void) ;
uint8   Right_LED_Green_Read(void) ;
uint8   Right_LED_Green_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Right_LED_Green_DRIVE_MODE_BITS        (3)
#define Right_LED_Green_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Right_LED_Green_DRIVE_MODE_BITS))

#define Right_LED_Green_DM_ALG_HIZ         (0x00u)
#define Right_LED_Green_DM_DIG_HIZ         (0x01u)
#define Right_LED_Green_DM_RES_UP          (0x02u)
#define Right_LED_Green_DM_RES_DWN         (0x03u)
#define Right_LED_Green_DM_OD_LO           (0x04u)
#define Right_LED_Green_DM_OD_HI           (0x05u)
#define Right_LED_Green_DM_STRONG          (0x06u)
#define Right_LED_Green_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Right_LED_Green_MASK               Right_LED_Green__MASK
#define Right_LED_Green_SHIFT              Right_LED_Green__SHIFT
#define Right_LED_Green_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Right_LED_Green_PS                     (* (reg32 *) Right_LED_Green__PS)
/* Port Configuration */
#define Right_LED_Green_PC                     (* (reg32 *) Right_LED_Green__PC)
/* Data Register */
#define Right_LED_Green_DR                     (* (reg32 *) Right_LED_Green__DR)
/* Input Buffer Disable Override */
#define Right_LED_Green_INP_DIS                (* (reg32 *) Right_LED_Green__PC2)


#if defined(Right_LED_Green__INTSTAT)  /* Interrupt Registers */

    #define Right_LED_Green_INTSTAT                (* (reg32 *) Right_LED_Green__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Right_LED_Green_DRIVE_MODE_SHIFT       (0x00u)
#define Right_LED_Green_DRIVE_MODE_MASK        (0x07u << Right_LED_Green_DRIVE_MODE_SHIFT)


#endif /* End Pins Right_LED_Green_H */


/* [] END OF FILE */
