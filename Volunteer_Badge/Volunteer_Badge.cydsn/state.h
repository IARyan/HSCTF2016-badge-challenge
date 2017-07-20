/* ========================================
 *
 * Copyright Nullify, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF NULLIY.
 *
 * ========================================
*/
#ifndef STATE_H_   /* Include guard */
#define STATE_H_
#include <project.h>
    
/* Badge State Flags */
#define VOLUNTEER 1
#define ORGANIZER 2

/* Global State Flag */
extern volatile uint8 badge_state;
    
/* Function declarations */
uint8 verify_state(uint8 state);

#endif // STATE_H_