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
#include "state.h"

/* Global Structures used to signal state change for badge  */
volatile struct Magic_Toggle_Sequence Volunteer_Sequence;
volatile struct Magic_Toggle_Sequence Organizer_Sequence;

/* Signal handler for left toggle press */
CY_ISR( SWL_Handler ) {
    uint8* sequance; 
    uint8 index;
    
    /* Determine what state the badge is currently in */
    switch(badge_state) {
        case VOLUNTEER:
            sequance = get_magic_toggle_sequance(ORGANIZER);
            index = get_magic_toggle_index(ORGANIZER);
            
            /* Check if the toggle is the next value in the sequance */
            if (sequance[index] == LEFT_TOGGLE) {
                index += 1;
            }
            else {
                index = 0;
            }
                   
           /* If the sequance is found change the state of the badge */
           if (index == strlen(sequance)){
            badge_state = ORGANIZER;
            PWM_Organizer_Start();
            index = 0;
           }
        
           /* Update the value in the toggle struct */
            set_magic_toggle_index(ORGANIZER, index);
        break;
        case ORGANIZER:
            sequance = get_magic_toggle_sequance(VOLUNTEER);
            index = get_magic_toggle_index(VOLUNTEER);
            
            /* Check if the toggle is the next value in the sequance */
            if (sequance[index] == LEFT_TOGGLE) {
                index += 1;
            }
            else {
                index = 0;
            }
                   
           /* If the sequance is found change the state of the badge */
           if (index == strlen(sequance)){
            badge_state = VOLUNTEER;
            PWM_Organizer_Stop();
            turn_off(LEFT_RIGHT_LED);
            set_color(LEFT_RIGHT_LED, GREEN);
            turn_on(LEFT_RIGHT_LED);
            index = 0;
           }
        
           /* Update the value in the VOLUNTEER toggle struct */
            set_magic_toggle_index(VOLUNTEER, index);
        break;
    }
    
    /* Delay for a long press and clear interrupt */
    CyDelay(TOGGLE_DELAY);
    SWL_ClearInterrupt();
}

/* Signal handler for right toggle press */
CY_ISR( SWR_Handler ) {
    uint8* sequance; 
    uint8 index;
    
    /* Determine what state the badge is currently in */
    switch(badge_state) {
        case VOLUNTEER:
            sequance = get_magic_toggle_sequance(ORGANIZER);
            index = get_magic_toggle_index(ORGANIZER);
            
            /* Check if the toggle is the next value in the sequance */
            if (sequance[index] == RIGHT_TOGGLE) {
                index += 1;
            }
            else {
                index = 0;
            }
                   
           /* If the sequance is found change the state of the badge */
           if (index == strlen(sequance)){
            badge_state = ORGANIZER;
            PWM_Organizer_Start();
            index = 0;
           }
        
           /* Update the value in the toggle struct */
            set_magic_toggle_index(ORGANIZER, index);
        break;
        case ORGANIZER:
            sequance = get_magic_toggle_sequance(VOLUNTEER);
            index = get_magic_toggle_index(VOLUNTEER);
            
            /* Check if the toggle is the next value in the sequance */
            if (sequance[index] == RIGHT_TOGGLE) {
                index += 1;
            }
            else {
                index = 0;
            }
                   
           /* If the sequance is found change the state of the badge */
           if (index == strlen(sequance)){
            badge_state = VOLUNTEER;
            PWM_Organizer_Stop();
            turn_off(LEFT_RIGHT_LED);
            set_color(LEFT_RIGHT_LED, GREEN);
            turn_on(LEFT_RIGHT_LED);
            index = 0;
           }
        
           /* Update the value in the VOLUNTEER toggle struct */
            set_magic_toggle_index(VOLUNTEER, index);
        break;
    }
    
    /* Delay for a long press and clear interrupt */
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

/* Signal handler for organizer lights */
CY_ISR( ORG_Handler ) {
    /* */
    uint8 current_color_left = get_color(LEFT_LED);
    uint8 current_color_right = get_color(RIGHT_LED);
    uint32 rand_num_left = (rand() % 7) + 1;
    uint32 rand_num_right = (rand() % 7) + 1;
    
    while (current_color_left == rand_num_left){
        rand_num_left = (rand() % 7) + 1;
    }
    
   while (current_color_right == rand_num_right){
        rand_num_right = (rand() % 7) + 1;
    }
    
    set_color(LEFT_LED, rand_num_left);
    set_color(RIGHT_LED, rand_num_right);
    turn_off(LEFT_RIGHT_LED);
    turn_on(LEFT_RIGHT_LED);
    
    ORG_Int_ClearPending();
    PWM_Organizer_ReadStatusRegister();
}

/* Sets the magic toogle sequence of the global toggle state change structure */
void set_magic_toggle_sequance(uint8 state_flag, uint8* sequance) {
    switch(state_flag) {
        case VOLUNTEER:
            memmove(Volunteer_Sequence.sequance, sequance, MAX_SEQUENCE_SIZE);
        break;
        case ORGANIZER:
            memmove(Organizer_Sequence.sequance, sequance, MAX_SEQUENCE_SIZE);
        break;
    }   
    
}

/* Gets the magic toogle sequence of the global toggle state change structure */
uint8* get_magic_toggle_sequance(uint8 state_flag) {
    switch(state_flag) {
        case VOLUNTEER:
            return Volunteer_Sequence.sequance;
        break;
        case ORGANIZER:
             return Organizer_Sequence.sequance;
        break;
    }
    return NULL;
}

/* Sets the index of the magic toogle sequence of the global toggle state change structure */
void set_magic_toggle_index(uint8 state_flag, uint8 value) {
    switch(state_flag) {
        case VOLUNTEER:
            Volunteer_Sequence.index = value;
        break;
        case ORGANIZER:
            Organizer_Sequence.index = value;
        break;
    }
}

/* Gets the index of the magic toogle sequence of the global toggle state change structure */
uint8 get_magic_toggle_index(uint8 state_flag) {
        switch(state_flag) {
        case VOLUNTEER:
            return Volunteer_Sequence.index;
        break;
        case ORGANIZER:
            return Organizer_Sequence.index;
        break;
    }
    return -1;
}

/* Initialize the magic toogle structures */
void init_magic_toggle_sequance(uint8 state_flag, uint8* sequance) {
    set_magic_toggle_sequance(state_flag, sequance);
    set_magic_toggle_index(state_flag, 0);
}

void enable_toggle_interrupts() {
    /* Setup toggle interrupts  */
    SWB_Int_StartEx( SWB_Handler );
    SWL_Int_StartEx( SWL_Handler );
    SWR_Int_StartEx( SWR_Handler );
    ORG_Int_StartEx( ORG_Handler );
    /* Seed random */
    srand(time(NULL));
}