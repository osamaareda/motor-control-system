/* 
 * File:   app.c
 * Author: osama reda
 * 
 * Created on October 18, 2023, 1:10 AM
 */
 
 
#include"app.h"

Std_ReturnType ret=E_NOT_OK;
uint8 in0=0,in1=0,in2=0,in3=0,t=200;
/*=============================main code===============================*/
void app_init(void){
    //component initialization
    ecual_init();
}
int main() {
    
    app_init();
    print_welcome();
    
while(1)
{
    
    /*========select betweem motor1 and motor2========*/
    while(in0==0){
        print_welcome();
        ret=keypad_read(&keypad,&in0);
    }
    __delay_ms(t);
    if(in0=='#'){
        print_select_bage();
        do{
            ret=keypad_read(&keypad,&in1);
        }while(in1=='0');
        __delay_ms(100);
        /*==========motor1 operation=========*/
        
        while(in1=='1'){
            do{
                print_motor1_operation();
                ret=keypad_read(&keypad,&in2);
            }while(in2==0);
            __delay_ms(t);
            if(in2=='1'){
                led_on(&motor1_led1);
                led_off(&motor1_led2);
                ret=dc_motor_move_right(&motor1);
                in2=0;
            }
            else if(in2=='2'){
                led_off(&motor1_led1);
                led_on(&motor1_led2);
                ret=dc_motor_move_left(&motor1);
                in2=0;
            }
            else if(in2=='4'){
                led_off(&motor1_led1);
                led_off(&motor1_led2);
                ret=dc_motor_stop(&motor1);
                in2=0;               
            }
            /*=====go back to select page=====*/
            else if(in2=='5'){
                in1=0;
                in2=0;
                break;
            }
            /*=====go back to start page=====*/
            else if(in2=='#'){
                led_off(&motor1_led1);
                led_off(&motor1_led2);
                ret=dc_motor_stop(&motor1);
                led_off(&motor2_led1);
                led_off(&motor2_led2);
                ret=dc_motor_stop(&motor2);
                ret=lcd_send_command(&lcd,_LCD_CLEAR);
                ret=lcd_send_command(&lcd,_LCD_RETURN_HOME);
                in0=0;
                in1=0;
                in2=0;
                break;
            }
            else{
                ret=lcd_send_command(&lcd,_LCD_CLEAR);
                ret=lcd_send_command(&lcd,_LCD_RETURN_HOME);
                print_invalid();
                __delay_ms(1000);
                in2=0;
            }
        }
         /*==========motor2 operation=========*/
        
        while(in1=='2'){
            do{
            print_motor2_operation();
            ret=keypad_read(&keypad,&in2);
            }while(in2==0);
            __delay_ms(t);
            if(in2=='1'){
                led_on(&motor2_led1);
                led_off(&motor2_led2);
                ret=dc_motor_move_right(&motor2);
                in2=0;
            }
            else if(in2=='2'){
                led_off(&motor2_led1);
                led_on(&motor2_led2);
                ret=dc_motor_move_left(&motor2);
                in2=0;
            }
            else if(in2=='4'){
                led_off(&motor2_led1);
                led_off(&motor2_led2);
                ret=dc_motor_stop(&motor2);
                in2=0;
            }
            /*=====go back to select page=====*/
            else if(in2=='5'){
                in1=0;
                in2=0;
                break;
            }
            /*=====go back to start page=====*/
            else if(in2=='#'){
                led_off(&motor1_led1);
                led_off(&motor1_led2);
                ret=dc_motor_stop(&motor1);
                led_off(&motor2_led1);
                led_off(&motor2_led2);
                ret=dc_motor_stop(&motor2);
                ret=lcd_send_command(&lcd,_LCD_CLEAR);
                ret=lcd_send_command(&lcd,_LCD_RETURN_HOME);
                in0=0;
                in1=0;
                in2=0;
                break;
            }
            else{
                ret=lcd_send_command(&lcd,_LCD_CLEAR);
                ret=lcd_send_command(&lcd,_LCD_RETURN_HOME);
                print_invalid();
                __delay_ms(1000);
                in2=0;
            }
        }
    }
    else{
        in0=0;
    }
}
    return (EXIT_SUCCESS);
}
/*========================custom characters=========================*/
uint8 customChar1[] = {0x01,0x03,0x07,0x0E,0x1E,0x1F,0x1F,0x1F};
uint8 customChar2[] = {0x1F,0x1F,0x1F,0x0E,0x0E,0x1F,0x1F,0x1F};
uint8 customChar3[] = {0x10,0x18,0x1C,0x06,0x07,0x1F,0x1F,0x1F};
uint8 customChar4[] = {0x13,0x18,0x1C,0x1E,0x0F,0x07,0x03,0x01};
uint8 customChar5[] = {0x1F,0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F};
uint8 customChar6[] = {0x1B,0x03,0x07,0x0F,0x1E,0x1C,0x18,0x10};
uint8 customChar7[] = {0x01,0x03,0x07,0x0E,0x1C,0x1F,0x1F,0x1F};
uint8 customChar8[] = {0x1F,0x1F,0x1F,0x0E,0x04,0x1F,0x1F,0x1F};
uint8 customChar9[] = {0x10,0x18,0x1C,0x06,0x03,0x1F,0x1F,0x1F};
uint8 customChar10[] = {0x1F,0x1F,0x1E,0x1C,0x0D,0x07,0x03,0x01};
uint8 customChar11[] = {0x1F,0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x1F};
uint8 customChar12[] = {0x1F,0x1F,0x0F,0x07,0x16,0x1C,0x18,0x10};
/*=========================to print welcome==========================*/
void print_welcome(void){
    ret=lcd_send_string_pos(&lcd,1,7,"welcome");
    ret=lcd_send_custom_char(&lcd,2,9,customChar1,0);
    ret=lcd_send_custom_char(&lcd,2,10,customChar2,1);
    ret=lcd_send_custom_char(&lcd,2,11,customChar3,2);
    ret=lcd_send_custom_char(&lcd,3,9,customChar4,3);
    ret=lcd_send_custom_char(&lcd,3,10,customChar5,4);
    ret=lcd_send_custom_char(&lcd,3,11,customChar6,5);
    ret=lcd_send_string_pos(&lcd,4,3,"press on to start");
}
/*=========================to print invalid==========================*/
void print_invalid(void){
    ret=lcd_send_string_pos(&lcd,1,7,"invalid");
    ret=lcd_send_custom_char(&lcd,2,9,customChar7,0);
    ret=lcd_send_custom_char(&lcd,2,10,customChar8,1);
    ret=lcd_send_custom_char(&lcd,2,11,customChar9,2);
    ret=lcd_send_custom_char(&lcd,3,9,customChar10,3);
    ret=lcd_send_custom_char(&lcd,3,10,customChar11,4);
    ret=lcd_send_custom_char(&lcd,3,11,customChar12,5);
    ret=lcd_send_string_pos(&lcd,4,3,"enter valid op");
}
/*======================to print select page========================*/
void print_select_bage(void){
    ret=lcd_send_string_pos(&lcd,1,1,"select motor       ");
    ret=lcd_send_string_pos(&lcd,2,1,"1-motor1           ");
    ret=lcd_send_string_pos(&lcd,3,1,"2-motor2           ");
    ret=lcd_send_string_pos(&lcd,4,1,"                   ");
}
/*=================to print motor1 operation page===================*/
void print_motor1_operation(void){
    ret=lcd_send_string_pos(&lcd,1,1,"1-motor1 on CW     ");
    ret=lcd_send_string_pos(&lcd,2,1,"2-motor1 on CCW    ");
    ret=lcd_send_string_pos(&lcd,3,1,"4-motor1 off       ");
    ret=lcd_send_string_pos(&lcd,4,1,"5-back             ");
}
/*=================to print motor2 operation page===================*/
void print_motor2_operation(void){
    ret=lcd_send_string_pos(&lcd,1,1,"1-motor2 on CW     ");
    ret=lcd_send_string_pos(&lcd,2,1,"2-motor2 on CCW    ");
    ret=lcd_send_string_pos(&lcd,3,1,"4-motor2 off       ");
    ret=lcd_send_string_pos(&lcd,4,1,"5-back             ");
}