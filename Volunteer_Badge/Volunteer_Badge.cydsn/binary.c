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
#include "binary.h"
#include "state.h"

void blink_zero(void) {
    /* Verify state */
    if(!verify_state(VOLUNTEER)) {
        return;
    }
    turn_on(LEFT_LED);
    CyDelay(BLINK_DELAY_ON);
    turn_off(LEFT_LED);
    CyDelay(BLINK_DELAY_OFF);
}

void blink_one(void) {
    /* Verify state */
    if(!verify_state(VOLUNTEER)) {
        return;
    }
    turn_on(RIGHT_LED);
    CyDelay(BLINK_DELAY_ON);
    turn_off(RIGHT_LED);
    CyDelay(BLINK_DELAY_OFF);
}

void new_message_binary(void) {
    unsigned int i;
    uint8 original_color;
    original_color = get_color(LEFT_LED);
    set_color(LEFT_RIGHT_LED, WHITE);
    for (i=0; i<NEW_MESSAGE_NUMBER; i++) {
        /* Verify state */
    if(!verify_state(VOLUNTEER)) {
        return;
    }
       turn_on(LEFT_RIGHT_LED);
       CyDelay(RESET_DELAY);
       turn_off(LEFT_RIGHT_LED);
       CyDelay(RESET_DELAY);
    }
    set_color(LEFT_RIGHT_LED, original_color);
}

void binary_encode(char c){
    /* Verify state */
    if(!verify_state(VOLUNTEER)) {
       return;
    }
    switch(c) {
      case 'A':
      case 'a':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_one();
        break;
      case 'B':
      case 'b':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_one();
        blink_zero();
        break;
      case 'C':
      case 'c':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        break;
      case 'D':
      case 'd':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        break;
       case 'E':
       case 'e':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        break;
       case 'F':
       case 'f':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        break;
       case 'G':
       case 'g':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_one();
        break;
       case 'H':
       case 'h':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        break;
       case 'I':
       case 'i':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        break;
       case 'J':
       case 'j':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        break;
       case 'K':
       case 'k':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_one();
        break;
       case 'L':
       case 'l':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_zero();
        break;
       case 'M':
       case 'm':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_one();
        break;
       case 'N':
       case 'n':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_one();
        blink_zero();
        break;
       case 'O':
       case 'o':
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_one();
        blink_one();
        break;
       case 'P':
       case 'p':
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_zero();
        break;
       case 'Q':
       case 'q':
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_one();
        break;
       case 'R':
       case 'r':
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        blink_zero();
        break;
       case 'S':
       case 's':
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        break;
       case 'T':
       case 't':
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        break;
       case 'U':
       case 'u':
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        break;
       case 'V':
       case 'v':
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        break;
       case 'W':
       case 'w':
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_one();
        blink_one();
        break;
       case 'X':
       case 'x':
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        break;
       case 'Y':
       case 'y':
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        break;
       case 'Z':
       case 'z':
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        break;
       case '0':
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_zero();
        break;
       case '1':
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        blink_one();
        break;
       case '2':
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        blink_zero();
        break;
       case '3':
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        break;
       case '4':
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        blink_zero();
        break;
       case '5':
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_one();
        blink_zero();
        blink_one();
        break;
       case '6':
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        break;
       case '7':
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_zero();
        blink_one();
        blink_one();
        blink_one();
        break;
       case '8':
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_one();
        blink_zero();
        blink_zero();
        blink_zero();
        break;
       case '9':
        blink_zero();
        blink_zero();
        blink_one();
        blink_one();
        blink_one();
        blink_zero();
        blink_zero();
        blink_one();
        break;
       case '\n':
        /* Clear the screen on a new line */
        break;
   }
}

void binary_message(char* message) {
    unsigned int i;
    
    /* Signal new message to user */
    new_message_binary();
    
    /* Blink the encoded message */
    for (i=0; i < strlen(message); i++) {
        /* Verify state */
        if(!verify_state(VOLUNTEER)) {
            return;
        }
        binary_encode(message[i]);
    }
}
