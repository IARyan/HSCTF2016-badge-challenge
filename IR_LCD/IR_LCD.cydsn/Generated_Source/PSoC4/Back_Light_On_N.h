/*******************************************************************************
* File Name: Back_Light_On_N.h  
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

#if !defined(CY_PINS_Back_Light_On_N_H) /* Pins Back_Light_On_N_H */
#define CY_PINS_Back_Light_On_N_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Back_Light_On_N_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Back_Light_On_N_Write(uint8 value) ;
void    Back_Light_On_N_SetDriveMode(uint8 mode) ;
uint8   Back_Light_On_N_ReadDataReg(void) ;
uint8   Back_Light_On_N_Read(void) ;
uint8   Back_Light_On_N_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Back_Light_On_N_DRIVE_MODE_BITS        (3)
#define Back_Light_On_N_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Back_Light_On_N_DRIVE_MODE_BITS))
#define Back_Light_On_N_DRIVE_MODE_SHIFT       (0x00u)
#define Back_Light_On_N_DRIVE_MODE_MASK        (0x07u << Back_Light_On_N_DRIVE_MODE_SHIFT)

#define Back_Light_On_N_DM_ALG_HIZ         (0x00u << Back_Light_On_N_DRIVE_MODE_SHIFT)
#define Back_Light_On_N_DM_DIG_HIZ         (0x01u << Back_Light_On_N_DRIVE_MODE_SHIFT)
#define Back_Light_On_N_DM_RES_UP          (0x02u << Back_Light_On_N_DRIVE_MODE_SHIFT)
#define Back_Light_On_N_DM_RES_DWN         (0x03u << Back_Light_On_N_DRIVE_MODE_SHIFT)
#define Back_Light_On_N_DM_OD_LO           (0x04u << Back_Light_On_N_DRIVE_MODE_SHIFT)
#define Back_Light_On_N_DM_OD_HI           (0x05u << Back_Light_On_N_DRIVE_MODE_SHIFT)
#define Back_Light_On_N_DM_STRONG          (0x06u << Back_Light_On_N_DRIVE_MODE_SHIFT)
#define Back_Light_On_N_DM_RES_UPDWN       (0x07u << Back_Light_On_N_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Back_Light_On_N_MASK               Back_Light_On_N__MASK
#define Back_Light_On_N_SHIFT              Back_Light_On_N__SHIFT
#define Back_Light_On_N_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Back_Light_On_N_PS                     (* (reg32 *) Back_Light_On_N__PS)
/* Port Configuration */
#define Back_Light_On_N_PC                     (* (reg32 *) Back_Light_On_N__PC)
/* Data Register */
#define Back_Light_On_N_DR                     (* (reg32 *) Back_Light_On_N__DR)
/* Input Buffer Disable Override */
#define Back_Light_On_N_INP_DIS                (* (reg32 *) Back_Light_On_N__PC2)


#if defined(Back_Light_On_N__INTSTAT)  /* Interrupt Registers */

    #define Back_Light_On_N_INTSTAT                (* (reg32 *) Back_Light_On_N__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Back_Light_On_N_H */


/* [] END OF FILE */
