/* ========================================
 *
 * Red Badge source code. The volunteer badge
 * is used to send encoded morse code message.
 *
 * Author(s): Ryan Grandgenett <rmgrandgenett@unomaha.edu>
 *
 * Eye Color: Red
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
#include <string.h>
#include <stdio.h>
#include "state.h"

/* Global variable used to keep track of badge state */
volatile uint8 badge_state = 0;

uint8 verify_state(uint8 state) {
    if (badge_state == state) {
        return 1;   
    }
    else {
        return 0;
    }
}