/*******************************************************************************
* File Name: SWL.h  
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

#if !defined(CY_PINS_SWL_H) /* Pins SWL_H */
#define CY_PINS_SWL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SWL_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SWL_Write(uint8 value) ;
void    SWL_SetDriveMode(uint8 mode) ;
uint8   SWL_ReadDataReg(void) ;
uint8   SWL_Read(void) ;
uint8   SWL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SWL_DRIVE_MODE_BITS        (3)
#define SWL_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SWL_DRIVE_MODE_BITS))

#define SWL_DM_ALG_HIZ         (0x00u)
#define SWL_DM_DIG_HIZ         (0x01u)
#define SWL_DM_RES_UP          (0x02u)
#define SWL_DM_RES_DWN         (0x03u)
#define SWL_DM_OD_LO           (0x04u)
#define SWL_DM_OD_HI           (0x05u)
#define SWL_DM_STRONG          (0x06u)
#define SWL_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SWL_MASK               SWL__MASK
#define SWL_SHIFT              SWL__SHIFT
#define SWL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SWL_PS                     (* (reg32 *) SWL__PS)
/* Port Configuration */
#define SWL_PC                     (* (reg32 *) SWL__PC)
/* Data Register */
#define SWL_DR                     (* (reg32 *) SWL__DR)
/* Input Buffer Disable Override */
#define SWL_INP_DIS                (* (reg32 *) SWL__PC2)


#if defined(SWL__INTSTAT)  /* Interrupt Registers */

    #define SWL_INTSTAT                (* (reg32 *) SWL__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SWL_DRIVE_MODE_SHIFT       (0x00u)
#define SWL_DRIVE_MODE_MASK        (0x07u << SWL_DRIVE_MODE_SHIFT)


#endif /* End Pins SWL_H */


/* [] END OF FILE */
