/* 
 * File:   initialize.h
 * Author: osama reda
 *
 * Created on October 18, 2023, 1:10 AM
 */
#include "init.h"



/*===========================keypad configuration=========================*/
keypad_config_t keypad={.keypad_rows_pins[0].port=PORTA_INDEX,.keypad_rows_pins[0].pin=PIN1,
                        .keypad_rows_pins[1].port=PORTA_INDEX,.keypad_rows_pins[1].pin=PIN2,
                        .keypad_rows_pins[2].port=PORTA_INDEX,.keypad_rows_pins[2].pin=PIN3,
                        .keypad_rows_pins[3].port=PORTA_INDEX,.keypad_rows_pins[3].pin=PIN5,
                        .keypad_columns_pins[0].port=PORTC_INDEX,.keypad_columns_pins[0].pin=PIN4,
                        .keypad_columns_pins[1].port=PORTC_INDEX,.keypad_columns_pins[1].pin=PIN5,
                        .keypad_columns_pins[2].port=PORTC_INDEX,.keypad_columns_pins[2].pin=PIN6,
                        .keypad_columns_pins[3].port=PORTC_INDEX,.keypad_columns_pins[2].pin=PIN7};

/*============================lcd configuration===========================*/
lcd_config_t lcd={.lcd_rs.port=PORTB_INDEX,.lcd_rs.pin=PIN6,
                  .lcd_en.port=PORTB_INDEX,.lcd_en.pin=PIN7,
                  .lcd_pins[0].port=PORTD_INDEX,.lcd_pins[0].pin=PIN0,
                  .lcd_pins[1].port=PORTD_INDEX,.lcd_pins[1].pin=PIN1,
                  .lcd_pins[2].port=PORTD_INDEX,.lcd_pins[2].pin=PIN2,
                  .lcd_pins[3].port=PORTD_INDEX,.lcd_pins[3].pin=PIN3};

/*============================motor configuration===========================*/
//motor1
dc_motor_config_t motor1={.dc_motor_pin0.port=PORTB_INDEX,.dc_motor_pin0.pin=PIN2,
                          .dc_motor_pin1.port=PORTB_INDEX,.dc_motor_pin1.pin=PIN3};
//motor2
dc_motor_config_t motor2={.dc_motor_pin0.port=PORTD_INDEX,.dc_motor_pin0.pin=PIN6,
                          .dc_motor_pin1.port=PORTD_INDEX,.dc_motor_pin1.pin=PIN7};

/*============================leds configuration===========================*/
led_config_t motor1_led1={.led_pin.port=PORTB_INDEX,.led_pin.pin=PIN4};
led_config_t motor2_led1={.led_pin.port=PORTB_INDEX,.led_pin.pin=PIN5};
led_config_t motor1_led2={.led_pin.port=PORTD_INDEX,.led_pin.pin=PIN4};
led_config_t motor2_led2={.led_pin.port=PORTD_INDEX,.led_pin.pin=PIN5};
void ecual_init(void){
    Std_ReturnType ret=E_NOT_OK;
    ret=keypad_init(&keypad);
    ret=lcd_init(&lcd);
    ret=dc_motor_init(&motor1);
    ret=dc_motor_init(&motor2);
    ret=led_init(&motor1_led1);
    ret=led_init(&motor1_led2);
    ret=led_init(&motor2_led1);
    ret=led_init(&motor2_led2);
}