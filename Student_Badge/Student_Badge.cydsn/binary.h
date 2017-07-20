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
#include <project.h>
#ifndef BINARY_H_   /* Include guard */
#define BINARY_H_

/* Timing identifier flags */
#define BLINK_DELAY_ON 500
#define BLINK_DELAY_OFF 500
#define RESET_DELAY 250
#define NEW_MESSAGE_NUMBER 5
    
/* Function declarations */
void blink_zero(void);
void blink_one(void);
void new_message_binary(void);
void binary_encode(char c);
void binary_message(char* message);
    
#endif // BINARY_H_

