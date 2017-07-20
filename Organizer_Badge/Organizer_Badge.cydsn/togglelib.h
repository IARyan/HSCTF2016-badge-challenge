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
#ifndef TOGGLELIB_H_   /* Include guard */
#define TOGGLELIB_H_
#include <project.h>
#include "lightlib.h"

/* Toggle Flags */
#define LEFT_TOGGLE 1
#define RIGHT_TOGGLE 2
#define BOARD_TOGGLE 3

/* Toggle delay after button press (milliseconds) */
#define TOGGLE_DELAY 150
    
/* Max toggle sequence size */
#define MAX_SEQUENCE_SIZE 20

/* Structure used to keep track of RGB LED state */
struct Magic_Toggle_Sequence {
   uint8 sequance[MAX_SEQUENCE_SIZE];
   uint8 index;
};

/* Function declarations */
void init_magic_toggle_sequance(uint8 state_flag, uint8* sequance);
void set_magic_toggle_sequance(uint8 state_flag, uint8* sequance);
uint8* get_magic_toggle_sequance(uint8 state_flag);
void set_magic_toggle_index(uint8 state_flag, uint8 value);
uint8 get_magic_toggle_index(uint8 state_flag);
void enable_toggle_interrupts();

#endif // TOGGLELIB_H_