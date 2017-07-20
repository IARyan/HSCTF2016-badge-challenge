/* ========================================
 *
 * Red Badge source code. The volunteer badge
 * is used to send encoded morse code message.
 *
 * Author(s): Ryan Grandgenett <rmgrandgenett@unomaha.edu>
 *
 * Eye Color: Green
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
#include "binary.h"
#include "state.h"

int main()
{
    uint8 volunteer_sequance[MAX_SEQUENCE_SIZE] = {LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, 0};
    uint8 organizer_sequance[MAX_SEQUENCE_SIZE] = {RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, RIGHT_TOGGLE, LEFT_TOGGLE, 0};

    /* Enable interrupts (needed for toggles and organizer PWRM) */
    CyGlobalIntEnable;

    /* Enable toggle buttons */
    enable_toggle_interrupts();
    
    /* Initialize LEDs to off and default color value */
    init_led(GREEN);
    
    /* Set the toggle button magic sequences */
    init_magic_toggle_sequance(VOLUNTEER, volunteer_sequance);
    init_magic_toggle_sequance(ORGANIZER, organizer_sequance);
    
    /* Set the default state to volunteer badge settings */
     badge_state = VOLUNTEER;
    
    for(;;)
    {  
        switch(badge_state) {
        case VOLUNTEER:
            init_led(GREEN);
            binary_message("QL5EGTN5");   
        break;
        case ORGANIZER:
            CySysPmSleep();
        break;
       }
      
    }
}