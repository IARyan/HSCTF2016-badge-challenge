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
#include "morse.h"

void blinkdot(uint8 led_flag) {
    turn_on(led_flag);
    CyDelay(DOT_ON_TIME);
    turn_off(led_flag);
    CyDelay(DOT_OFF_TIME);
}

void blinkdash(uint8 led_flag) {
    turn_on(led_flag);
    CyDelay(DASH_ON_TIME);
    turn_off(led_flag);
    CyDelay(DASH_OFF_TIME);
}

void new_message_morse(void) {
    unsigned int i;
    uint8 original_color;
    original_color = get_color(LEFT_LED);
    set_color(LEFT_RIGHT_LED, WHITE);
    for (i=0; i<NEW_MESSAGE_NUMBER; i++) {
       turn_on(LEFT_RIGHT_LED);
       CyDelay(RESET_DELAY);
       turn_off(LEFT_RIGHT_LED);
       CyDelay(RESET_DELAY);
    }
    set_color(LEFT_RIGHT_LED, original_color);
}

void char_separate(void) {
    CyDelay(CHAR_SEPARATE_TIME);
}

void morse_encode(uint8 led_flag, char c){
    switch(c) {
      case 'A':
      case 'a':
        blinkdot(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
      case 'B':
      case 'b':
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
      case 'C':
      case 'c':
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
      case 'D':
      case 'd':
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case 'E':
       case 'e':
        blinkdot(led_flag);
        char_separate();
        break;
       case 'F':
       case 'f':
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case 'G':
       case 'g':
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case 'H':
       case 'h':
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case 'I':
       case 'i':
        blinkdot(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case 'J':
       case 'j':
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case 'K':
       case 'k':
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case 'L':
       case 'l':
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case 'M':
       case 'm':
        blinkdash(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case 'N':
       case 'n':
        blinkdash(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case 'O':
       case 'o':
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case 'P':
       case 'p':
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case 'Q':
       case 'q':
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case 'R':
       case 'r':
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case 'S':
       case 's':
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case 'T':
       case 't':
        blinkdash(led_flag);
        char_separate();
        break;
       case 'U':
       case 'u':
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case 'V':
       case 'v':
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case 'W':
       case 'w':
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case 'X':
       case 'x':
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case 'Y':
       case 'y':
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case 'Z':
       case 'z':
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case '0':
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case '1':
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case '2':
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case '3':
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case '4':
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case '5':
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case '6':
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case '7':
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case '8':
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case '9':
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        char_separate();
        break;
       case '.':
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case ',':
        blinkdash(led_flag);
        blinkdash(led_flag);
        blinkdot(led_flag);
        blinkdot(led_flag);
        blinkdash(led_flag);
        blinkdash(led_flag);
        char_separate();
        break;
       case ' ':
        CyDelay(WORD_SEPARATE_TIME);
        break;
       case '\n':
        break;
   }
}

void morse_message(uint8 led_flag, char* message) {
    unsigned int i;
    
    new_message_morse();
    
    for (i=0; i < strlen(message); i++) {
        morse_encode(led_flag, message[i]);
    }
}
