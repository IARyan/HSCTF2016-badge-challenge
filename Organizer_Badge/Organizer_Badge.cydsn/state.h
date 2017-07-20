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
#define MORSE 1
#define BINARY 2
#define SUBSTITUTION 3
#define FINAL 4
#define ORGANIZER 5

/* Global State Flag */
extern volatile uint8 badge_state;
    
uint8 verify_state(uint8 state);

#endif // STATE_H_