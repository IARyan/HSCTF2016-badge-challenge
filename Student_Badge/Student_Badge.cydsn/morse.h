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
#ifndef MORSE_H_   /* Include guard */
#define MORSE_H_
 
/* Timing identifier flags */
#define DOT_ON_TIME 500
#define DOT_OFF_TIME 250
    
#define DASH_ON_TIME 1500
#define DASH_OFF_TIME 250
    
#define CHAR_SEPARATE_TIME 1000
#define WORD_SEPARATE_TIME 1000
#define NEW_MESSAGE_NUMBER 5
#define RESET_DELAY 250

/* Function declarations */
void blinkdot(uint8 led_flag);
void blinkdash(uint8 led_flag);
void new_message_morse(void);
void char_separate(void);
void morse_encode(uint8 led_flag, char c);
void morse_message(uint8 led_flag, char* message);
    
#endif // MORSE_H_

