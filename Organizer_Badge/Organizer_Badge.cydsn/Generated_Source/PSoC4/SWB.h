/*******************************************************************************
* File Name: SWB.h  
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

#if !defined(CY_PINS_SWB_H) /* Pins SWB_H */
#define CY_PINS_SWB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SWB_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SWB_Write(uint8 value) ;
void    SWB_SetDriveMode(uint8 mode) ;
uint8   SWB_ReadDataReg(void) ;
uint8   SWB_Read(void) ;
uint8   SWB_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SWB_DRIVE_MODE_BITS        (3)
#define SWB_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SWB_DRIVE_MODE_BITS))

#define SWB_DM_ALG_HIZ         (0x00u)
#define SWB_DM_DIG_HIZ         (0x01u)
#define SWB_DM_RES_UP          (0x02u)
#define SWB_DM_RES_DWN         (0x03u)
#define SWB_DM_OD_LO           (0x04u)
#define SWB_DM_OD_HI           (0x05u)
#define SWB_DM_STRONG          (0x06u)
#define SWB_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SWB_MASK               SWB__MASK
#define SWB_SHIFT              SWB__SHIFT
#define SWB_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SWB_PS                     (* (reg32 *) SWB__PS)
/* Port Configuration */
#define SWB_PC                     (* (reg32 *) SWB__PC)
/* Data Register */
#define SWB_DR                     (* (reg32 *) SWB__DR)
/* Input Buffer Disable Override */
#define SWB_INP_DIS                (* (reg32 *) SWB__PC2)


#if defined(SWB__INTSTAT)  /* Interrupt Registers */

    #define SWB_INTSTAT                (* (reg32 *) SWB__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SWB_DRIVE_MODE_SHIFT       (0x00u)
#define SWB_DRIVE_MODE_MASK        (0x07u << SWB_DRIVE_MODE_SHIFT)


#endif /* End Pins SWB_H */


/* [] END OF FILE */
