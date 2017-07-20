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
#ifndef SUBSTITUTION_H_   /* Include guard */
#define SUBSTITUTION_H_
    
#define CHAR_ON_TIME 500
#define CHAR_OFF_TIME 500
#define RESET_DELAY 250

#define NEW_MESSAGE_NUMBER 5

/* Function declarations */
void new_message_substitution(void);
void new_char(void);
void blink_char(void);
void substitution_encode(char c);
void substitution_message(char* message);
    
#endif // SUBSTITUTION_H_

