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
volatile uint8 show_flag = 0;
static uint32 last_quote_num;

/* Signal handler for left toggle press */
CY_ISR( IR_Handler ) {
    LED_Write(1); 
    show_flag = 1;
    IR_REC_ClearInterrupt();
}


/* Signal handler for organizer lights */
CY_ISR( PWM_Handler ) {
    PWM_Int_ClearPending();
    PWM_Timer_ReadStatusRegister();
}

char* get_mario_quote(){
    uint32 quote_num = (rand() % 11) + 1;
    
    while (quote_num == last_quote_num){
        quote_num = (rand() % 11) + 1;
    }
    
    switch(quote_num){
        case 1:
            return "Let's-a go!";
        break;
        case 2:
            return "Okey dokey!";
        break;
        case 3:
            return "Here we go!";
        break;
        case 4:
            return "It's-a me, Mario!";
        break;
        case 5:
            return "So long-a Bowser!";
        break;
        case 6:
            return "Nighty-nighty...";
        break;
        case 7:
            return "Ah spaghetti...";
        break;
        case 8:
            return "Ah ravioli...";
        break;
        case 9:
            return "Press start to play!";
        break;
        case 10:
            return "Mama mia!";
        break;
    }
    return "Oh Nooooo!";
}

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    CyGlobalIntEnable;

    /* Setup IR Interupt Handlers */
    IR_Int_StartEx( IR_Handler );
    PWM_Int_StartEx( PWM_Handler );

    /* Supply 5 Vdd to LCD display from MCU and power up Back Light*/
    Power_Up_LCD_Pin_1_Write(1);
    Back_Light_On_N_Write(0);
    Back_Light_On_P_Write(1);

    /* Start LCD display */    
    LCD_Char_Start();
    LCD_Char_DisplayOn();
    
    /* Seed random */
    srand(time(NULL));
    
    /* Star the timer to change the quotes */
    PWM_Timer_Start();
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        if (!show_flag) {
          // Make sure on board led is off
          LED_Write(0); 
          LCD_Char_Position(0,0);
          LCD_Char_PrintString("Bowser Says:");
          LCD_Char_Position(1,0);
          LCD_Char_PrintString("IR Required For Flag"); 
          LCD_Char_Position(2,0);
          LCD_Char_PrintString("Mario Says:");  
          LCD_Char_Position(3,0);
          LCD_Char_PrintString("                    ");
          LCD_Char_Position(3,0);
          LCD_Char_PrintString(get_mario_quote());  
          CySysPmSleep();
        } else {
          LCD_Char_ClearDisplay();
          LCD_Char_Position(0,0);
          LCD_Char_PrintString("Bowser Says:");
          LCD_Char_Position(1,0);
          LCD_Char_PrintString("N...n...NO!!!");
          LCD_Char_Position(2,0);
          LCD_Char_PrintString("null{c81e96410ec768c");
          LCD_Char_Position(3,0);
          LCD_Char_PrintString("33eeb43b49c738b17}");
          show_flag = 0;
          /* Display flag for 5 seconds */
          CyDelay(5000);
          LCD_Char_ClearDisplay();
        }
        
        /* Place your application code here. */
    }
}



/* [] END OF FILE */
