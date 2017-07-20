/*******************************************************************************
* File Name: IR_REC.h  
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

#if !defined(CY_PINS_IR_REC_H) /* Pins IR_REC_H */
#define CY_PINS_IR_REC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "IR_REC_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    IR_REC_Write(uint8 value) ;
void    IR_REC_SetDriveMode(uint8 mode) ;
uint8   IR_REC_ReadDataReg(void) ;
uint8   IR_REC_Read(void) ;
uint8   IR_REC_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define IR_REC_DRIVE_MODE_BITS        (3)
#define IR_REC_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - IR_REC_DRIVE_MODE_BITS))

#define IR_REC_DM_ALG_HIZ         (0x00u)
#define IR_REC_DM_DIG_HIZ         (0x01u)
#define IR_REC_DM_RES_UP          (0x02u)
#define IR_REC_DM_RES_DWN         (0x03u)
#define IR_REC_DM_OD_LO           (0x04u)
#define IR_REC_DM_OD_HI           (0x05u)
#define IR_REC_DM_STRONG          (0x06u)
#define IR_REC_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define IR_REC_MASK               IR_REC__MASK
#define IR_REC_SHIFT              IR_REC__SHIFT
#define IR_REC_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IR_REC_PS                     (* (reg32 *) IR_REC__PS)
/* Port Configuration */
#define IR_REC_PC                     (* (reg32 *) IR_REC__PC)
/* Data Register */
#define IR_REC_DR                     (* (reg32 *) IR_REC__DR)
/* Input Buffer Disable Override */
#define IR_REC_INP_DIS                (* (reg32 *) IR_REC__PC2)


#if defined(IR_REC__INTSTAT)  /* Interrupt Registers */

    #define IR_REC_INTSTAT                (* (reg32 *) IR_REC__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define IR_REC_DRIVE_MODE_SHIFT       (0x00u)
#define IR_REC_DRIVE_MODE_MASK        (0x07u << IR_REC_DRIVE_MODE_SHIFT)


#endif /* End Pins IR_REC_H */


/* [] END OF FILE */
