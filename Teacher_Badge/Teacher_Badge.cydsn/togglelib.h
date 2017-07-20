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
#define LIGHT_CHANGE_NUM 10
    
/* Toggle State Flags */
#define RELEASED 0
#define PRESSED 1

/* Globals used to keep track of toggle state */
extern volatile uint8 left_toggle_state;
extern volatile uint8 right_toggle_state;

/* Function declarations */
void init_magic_toggle_sequance(uint8 state_flag, uint8* sequance);
void set_magic_toggle_sequance(uint8 state_flag, uint8* sequance);
uint8* get_magic_toggle_sequance(uint8 state_flag);
void set_magic_toggle_index(uint8 state_flag, uint8 value);
uint8 get_magic_toggle_index(uint8 state_flag);
void enable_toggle_interrupts();
void clear_toggle_press_count();

#endif // TOGGLELIB_H_