/*******************************************************************************
* File Name: SWR.h  
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

#if !defined(CY_PINS_SWR_H) /* Pins SWR_H */
#define CY_PINS_SWR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SWR_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SWR_Write(uint8 value) ;
void    SWR_SetDriveMode(uint8 mode) ;
uint8   SWR_ReadDataReg(void) ;
uint8   SWR_Read(void) ;
uint8   SWR_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SWR_DRIVE_MODE_BITS        (3)
#define SWR_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SWR_DRIVE_MODE_BITS))

#define SWR_DM_ALG_HIZ         (0x00u)
#define SWR_DM_DIG_HIZ         (0x01u)
#define SWR_DM_RES_UP          (0x02u)
#define SWR_DM_RES_DWN         (0x03u)
#define SWR_DM_OD_LO           (0x04u)
#define SWR_DM_OD_HI           (0x05u)
#define SWR_DM_STRONG          (0x06u)
#define SWR_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define SWR_MASK               SWR__MASK
#define SWR_SHIFT              SWR__SHIFT
#define SWR_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SWR_PS                     (* (reg32 *) SWR__PS)
/* Port Configuration */
#define SWR_PC                     (* (reg32 *) SWR__PC)
/* Data Register */
#define SWR_DR                     (* (reg32 *) SWR__DR)
/* Input Buffer Disable Override */
#define SWR_INP_DIS                (* (reg32 *) SWR__PC2)


#if defined(SWR__INTSTAT)  /* Interrupt Registers */

    #define SWR_INTSTAT                (* (reg32 *) SWR__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define SWR_DRIVE_MODE_SHIFT       (0x00u)
#define SWR_DRIVE_MODE_MASK        (0x07u << SWR_DRIVE_MODE_SHIFT)


#endif /* End Pins SWR_H */


/* [] END OF FILE */
