/* ========================================
 *
 * Red Badge source code. The volunteer badge
 * is used to send encoded morse code message.
 *
 * Author(s): Ryan Grandgenett <rmgrandgenett@unomaha.edu>
 *
 * Eye Color: Blue
 * Serial: Binary code output
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
#include "morse.h"

int main()
{

    /* Enable interrupts (needed for toggles and organizer PWRM) */
    CyGlobalIntEnable;

    /* Enable toggle buttons */
    enable_toggle_interrupts();
    
    /* Initialize LEDs to off and default color value */
    init_led(BLUE);
    
    /* Show encoded message to the user forever */ 
    for(;;)
    {  
        init_led(BLUE);
        clear_toggle_press_count();
        morse_message(LEFT_RIGHT_LED, "ZM6CCPB4");
      
    }
}