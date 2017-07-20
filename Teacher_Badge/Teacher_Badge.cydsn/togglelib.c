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
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lightlib.h"
#include "togglelib.h"


volatile uint8 ltp_count = 0;
volatile uint8 rtp_count = 0;

/* Signal handler for left toggle press */
CY_ISR( SWL_Handler ) {
    uint8 new_color_left;
    uint8 current_color_left; 
    
    ltp_count += 1;
    
    if (ltp_count == LIGHT_CHANGE_NUM) {
        current_color_left = get_color(LEFT_LED);
        new_color_left = (rand() % 7) + 1;
        
        while (new_color_left == current_color_left){
            new_color_left = (rand() % 7) + 1;
        }
        set_color(LEFT_LED, new_color_left);
        ltp_count = 0;
    }
    
    /* Clear interrupt */
    CyDelay(TOGGLE_DELAY);
    SWL_ClearInterrupt();
}

/* Signal handler for right toggle press */
CY_ISR( SWR_Handler ) {  
    uint8 new_color_right;
    uint8 current_color_right; 
    
    rtp_count += 1;
    
    if (rtp_count == LIGHT_CHANGE_NUM) {
        current_color_right = get_color(RIGHT_LED);
        new_color_right = (rand() % 7) + 1;
        
        while (new_color_right == current_color_right){
            new_color_right = (rand() % 7) + 1;
        }
        set_color(RIGHT_LED, new_color_right);
        rtp_count = 0;
    }
    
    /* Clear interrupt */
    CyDelay(TOGGLE_DELAY);
    SWR_ClearInterrupt();
}

/* Signal handler for on board toggle press */
CY_ISR( SWB_Handler ) {
    /* Flip IR Status */
    if (get_status(IR_LED) == OFF) {
        turn_on(IR_LED);
    } 
    else {
         turn_off(IR_LED);
    }
    
    if (get_status(BOARD_LED) == OFF) {
        turn_on(BOARD_LED);
    } 
    else {
         turn_off(BOARD_LED);
    }
    

    /* Clear interrupt */
    SWB_ClearInterrupt();
}

void clear_toggle_press_count() {
    /* Clear press count variables */
    ltp_count = 0;
    rtp_count = 0;
}

void enable_toggle_interrupts() {
    /* Setup toggle interrupts  */
    SWB_Int_StartEx( SWB_Handler );
    SWL_Int_StartEx( SWL_Handler );
    SWR_Int_StartEx( SWR_Handler );
    /* Seed random */
    srand(time(NULL));
}