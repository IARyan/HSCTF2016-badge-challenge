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

#ifndef LIGHTLIB_H_   /* Include guard */
#define LIGHTLIB_H_

/* LED identifier flags */
#define LEFT_LED 1
#define RIGHT_LED 2
#define LEFT_RIGHT_LED 3
#define IR_LED 4
#define BOARD_LED 5

/* LED color flags */
#define RED 1
#define BLUE 2
#define MAGENTA 3
#define GREEN 4
#define YELLOW 5
#define CYAN 6
#define WHITE 7
    
/* State Flags */
#define OFF 0
#define ON 1
    
/* Structure used to keep track of RGB LED state */
struct RGB_LED_State {
   uint8 status;
   uint8 color;
};

/* Structure used to keep track of regular LED state */
struct LED_State {
   uint8 status;
};

/* Global LED state tracking structures */
extern volatile struct RGB_LED_State Left_LED_State;
extern volatile struct RGB_LED_State Right_LED_State;
extern volatile struct LED_State IR_LED_State;
extern volatile struct LED_State Board_LED_State;

/* Function declarations */
void set_color(uint8 led_flag, uint8 color);
void set_status(uint8 led_flag, uint8 status) ;
uint8 get_color(uint8 led_flag);
uint8 get_status(uint8 led_flag);
void turn_on(uint8 led_flag);
void turn_off(uint8 led_flag);
void turn_on_all_led(void);
void turn_off_all_led(void);
void init_led(uint8 color);

#endif // LIGHTLIB_H_
