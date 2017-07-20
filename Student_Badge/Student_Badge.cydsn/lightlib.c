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
#include "lightlib.h"


/* Allocate a structure for each led in the project */
volatile struct RGB_LED_State Left_LED_State;
volatile struct RGB_LED_State Right_LED_State;
volatile struct LED_State IR_LED_State;
volatile struct LED_State Board_LED_State;

/*
 * Sets the color of the of the passed in led_flag.
 */
void set_color(uint8 led_flag, uint8 color) {
    switch(led_flag) {
        case LEFT_LED:
            Left_LED_State.color = color;
        break;
        case RIGHT_LED:
            Right_LED_State.color = color;
        break;
        case LEFT_RIGHT_LED:
            set_color(LEFT_LED, color);
            set_color(RIGHT_LED, color);
        break;
    }    
}

void set_status(uint8 led_flag, uint8 status) {
    switch(led_flag) {
        case LEFT_LED:
            Left_LED_State.status = status;
        break;
        case RIGHT_LED:
            Right_LED_State.status = status;
        break;
        case LEFT_RIGHT_LED:
            set_status(LEFT_LED, status);
            set_status(RIGHT_LED, status);
        break;
        case IR_LED:
            IR_LED_State.status = status;
        break;
        case BOARD_LED:
           Board_LED_State.status = status;
        break;
    }    
}

uint8 get_color(uint8 led_flag) {
    switch(led_flag) {
        case LEFT_LED:
            return Left_LED_State.color;
        break;
        case RIGHT_LED:
            return Right_LED_State.color;
        break;
    }
    return -1;
}

uint8 get_status(uint8 led_flag) {
    switch(led_flag) {
        case LEFT_LED:
            return Left_LED_State.status;
        break;
        case RIGHT_LED:
            return Right_LED_State.status;
        break;
        case IR_LED:
            return IR_LED_State.status;
        break;
        case BOARD_LED:
           return Board_LED_State.status;
        break;
    }  
    return -1;
}

void turn_on(uint8 led_flag) {
    switch(led_flag) {
        case LEFT_LED:
            switch(get_color(LEFT_LED)) {
                case RED:
                    PWM_Left_LED_Red_Start();
                break;
                case BLUE:
                    Left_LED_Blue_Write(1);
                break;
                case MAGENTA:
                    PWM_Left_LED_Red_Start();
                    Left_LED_Blue_Write(1);
                break;
                case GREEN:
                    Left_LED_Green_Write(1);
                break;
                case YELLOW:
                    PWM_Left_LED_Red_Start();
                    Left_LED_Green_Write(1);
                break;
                case CYAN:
                    Left_LED_Blue_Write(1);
                    Left_LED_Green_Write(1);
                break;
                case WHITE:
                    PWM_Left_LED_Red_Start();
                    Left_LED_Blue_Write(1);
                    Left_LED_Green_Write(1);
                break;
            }
        set_status(LEFT_LED, ON);
        break;
        case RIGHT_LED:
            switch(get_color(RIGHT_LED)) {
                case RED:
                    PWM_Right_LED_Red_Start();
                break;
                case BLUE:
                    Right_LED_Blue_Write(1);
                break;
                case MAGENTA:
                    PWM_Right_LED_Red_Start();
                    Right_LED_Blue_Write(1);
                break;
                case GREEN:
                    Right_LED_Green_Write(1);
                break;
                case YELLOW:
                    PWM_Right_LED_Red_Start();
                    Right_LED_Green_Write(1);
                break;
                case CYAN:
                    Right_LED_Blue_Write(1);
                    Right_LED_Green_Write(1);
                break;
                case WHITE:
                    PWM_Right_LED_Red_Start();
                    Right_LED_Blue_Write(1);
                    Right_LED_Green_Write(1);
                break;
            }
        set_status(RIGHT_LED, ON);
        break;
        case LEFT_RIGHT_LED:
            turn_on(LEFT_LED);
            turn_on(RIGHT_LED);
        break;
        case IR_LED:
            IR_LED_Write(1);
            set_status(IR_LED, ON);
        break;
        case BOARD_LED:
            Board_LED_Write(1);
            set_status(BOARD_LED, ON);

        break;
    }    
}

void turn_off(uint8 led_flag) {
    switch(led_flag) {
        case LEFT_LED:
            PWM_Left_LED_Red_Stop();
            Left_LED_Blue_Write(0);
            Left_LED_Green_Write(0);
            set_status(LEFT_LED, OFF);
        break;
        case RIGHT_LED:
            PWM_Right_LED_Red_Stop();
            Right_LED_Blue_Write(0);
            Right_LED_Green_Write(0);
            set_status(RIGHT_LED, OFF);
        break;
        case LEFT_RIGHT_LED:
            turn_off(LEFT_LED);
            turn_off(RIGHT_LED);
        break;
        case IR_LED:
            IR_LED_Write(0);
            set_status(IR_LED, OFF);
        break;
        case BOARD_LED:
            Board_LED_Write(0);
           set_status(BOARD_LED, OFF);
        break;
    }    
}

void turn_on_all_led(void) {
    turn_on(LEFT_LED);
    turn_on(RIGHT_LED); 
    turn_on(IR_LED); 
    turn_on(BOARD_LED); 
}

void turn_off_all_led(void) {
    turn_off(LEFT_LED);
    turn_off(RIGHT_LED); 
    turn_off(IR_LED); 
    turn_off(BOARD_LED); 
}

void init_led(uint8 color) {
    /* Turn off all leds */
    turn_off_all_led();
    
    /* Set default led color */
    set_color(LEFT_LED, color);
    set_color(RIGHT_LED, color);
}