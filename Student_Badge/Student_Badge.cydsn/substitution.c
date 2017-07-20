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
#include <string.h>
#include "lightlib.h"
#include "substitution.h"
#include "state.h"


void blink_char(void) {
    /* Verify state */
    if(!verify_state(SUBSTITUTION)) {
        return;
    }
    turn_on(LEFT_LED);
    CyDelay(CHAR_ON_TIME);
    turn_off(LEFT_LED);
    CyDelay(CHAR_OFF_TIME);
}

void new_char(void) {
    /* Verify state */
    if(!verify_state(SUBSTITUTION)) {
        return;
    }
    turn_on(RIGHT_LED);
    CyDelay(CHAR_ON_TIME);
    turn_off(RIGHT_LED);
    CyDelay(CHAR_OFF_TIME);
}

void new_message_substitution(void) {
    unsigned int i;
    uint8 original_color;
    original_color = get_color(LEFT_LED);
    set_color(LEFT_RIGHT_LED, WHITE);
    for (i=0; i<NEW_MESSAGE_NUMBER; i++) {
        /* Verify state */
        if(!verify_state(SUBSTITUTION)) {
            return;
        }
       turn_on(LEFT_RIGHT_LED);
       CyDelay(RESET_DELAY);
       turn_off(LEFT_RIGHT_LED);
       CyDelay(RESET_DELAY);
    }
    set_color(LEFT_RIGHT_LED, original_color);
}


void substitution_encode(char c){
    int i;
    /* Verify state */
    if(!verify_state(SUBSTITUTION)) {
        return;
    }
    switch(c) {
      case 'A':
      case 'a':
        for (i=0; i<1; i++) {
         blink_char();   
        }
        new_char();
        break;
      case 'B':
      case 'b':
        for (i=0; i<2; i++) {
         blink_char();   
        }
        new_char();
        break;
      case 'C':
      case 'c':
        for (i=0; i<3; i++) {
         blink_char();   
        }
        new_char();
        break;
      case 'D':
      case 'd':
        for (i=0; i<4; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'E':
       case 'e':
        for (i=0; i<5; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'F':
       case 'f':
        for (i=0; i<6; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'G':
       case 'g':
        for (i=0; i<7; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'H':
       case 'h':
        for (i=0; i<8; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'I':
       case 'i':
        for (i=0; i<9; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'J':
       case 'j':
        for (i=0; i<10; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'K':
       case 'k':
        for (i=0; i<11; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'L':
       case 'l':
        for (i=0; i<12; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'M':
       case 'm':
        for (i=0; i<13; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'N':
       case 'n':
        for (i=0; i<14; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'O':
       case 'o':
        for (i=0; i<15; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'P':
       case 'p':
        for (i=0; i<16; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'Q':
       case 'q':
        for (i=0; i<17; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'R':
       case 'r':
        for (i=0; i<18; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'S':
       case 's':
        for (i=0; i<19; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'T':
       case 't':
        for (i=0; i<20; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'U':
       case 'u':
        for (i=0; i<21; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'V':
       case 'v':
        for (i=0; i<22; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'W':
       case 'w':
        for (i=0; i<23; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'X':
       case 'x':
        for (i=0; i<24; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'Y':
       case 'y':
        for (i=0; i<25; i++) {
         blink_char();   
        }
        new_char();
        break;
       case 'Z':
       case 'z':
        for (i=0; i<26; i++) {
         blink_char();   
        }
        new_char();
        break;
       case '\n':
        break;
   }
}

void substitution_message(char* message) {
    unsigned int i;
    
    new_message_substitution();
    
    for (i=0; i < strlen(message); i++) {
        /* Verify state */
        if(!verify_state(SUBSTITUTION)) {
            return;
        }
        substitution_encode(message[i]);
    }
}
