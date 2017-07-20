/* ========================================
 *
 * Red Badge source code. The volunteer badge
 * is used to send encoded morse code message.
 *
 * Author(s): Ryan Grandgenett <rmgrandgenett@unomaha.edu>
 *
 * Eye Color: Red
 * Stage1: Morse Code
 * Stage2: Binary
 * Stage3: Substitution
 * Stage4: Serial
 * Stage5: Organizer
 *
 * Serial: Print the morse code output
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
#include "lightlib.h"
#include "togglelib.h"
#include "state.h"
#include "morse.h"
#include "binary.h"
#include "substitution.h"

int main()
{
    uint8 morse_sequance[MAX_SEQUENCE_SIZE] = {LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, 0};
    uint8 binary_sequance[MAX_SEQUENCE_SIZE] = {RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, 0};
    uint8 substitution_sequance[MAX_SEQUENCE_SIZE] = {LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, 0};;
    uint8 final_stage_sequance[MAX_SEQUENCE_SIZE] = {RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, 0};
    uint8 organizer_sequance[MAX_SEQUENCE_SIZE] = {RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, 0};

    /* Enable interrupts (needed for toggles and organizer PWRM) */
    CyGlobalIntEnable;

    /* Enable toggle buttons */
    enable_toggle_interrupts();

    /* Initialize LEDs to off and default color value */
    init_led(RED);
      
    /* Set the toggle button magic sequences */
    init_magic_toggle_sequance(MORSE, morse_sequance);
    init_magic_toggle_sequance(BINARY, binary_sequance);
    init_magic_toggle_sequance(SUBSTITUTION, substitution_sequance);
    init_magic_toggle_sequance(FINAL, final_stage_sequance);
    init_magic_toggle_sequance(ORGANIZER, organizer_sequance);
    
    /* Set the default state to volunteer badge settings */
    badge_state = ORGANIZER;
    PWM_Organizer_Start();
    
    for(;;)
    {   switch(badge_state) {
        case MORSE:
            init_led(RED);
            morse_message(LEFT_RIGHT_LED, "797JNBWJ");
        break;
        case BINARY:
            init_led(MAGENTA);
            binary_message("TP6QZY52");
        break;
        case SUBSTITUTION:
            init_led(YELLOW);
            substitution_message("HCFFFCHA");
        break;
        case FINAL:
            init_led(CYAN);
            turn_on(LEFT_LED);
            CyDelay(RESET_DELAY);
            turn_off(LEFT_LED);
            turn_on(RIGHT_LED);
            CyDelay(RESET_DELAY);
            turn_off(RIGHT_LED);  
        break;
        case ORGANIZER:
            CySysPmSleep();
        break;
        }      
    }
}