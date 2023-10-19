/* 
 * File:   initialize.h
 * Author: osama reda
 *
 * Created on October 18, 2023, 1:10 AM
 */

#ifndef ECUAL_INIT_H
#define	ECUAL_INIT_H
/*-------------------includes---------------------*/
#include "ECUAL/LED/led.h"
#include "ECUAL/LCD/lcd.h"
#include "ECUAL/KEYPAD/keypad.h"
#include "ECUAL/DC_MOTOR/dc_motor.h"

/*--------------function declaration--------------*/
void ecual_init(void);
/*--------------------externs---------------------*/
extern keypad_config_t keypad;
extern lcd_config_t lcd;
extern dc_motor_config_t motor1;
extern dc_motor_config_t motor2;
extern led_config_t motor1_led1;
extern led_config_t motor2_led1;
extern led_config_t motor1_led2;
extern led_config_t motor2_led2;
#endif	/* ECUAL_INIT_H */