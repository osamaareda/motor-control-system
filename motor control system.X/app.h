/* 
 * File:   app.h
 * Author: osama reda
 *
 * Created on October 18, 2023, 1:10 AM
 */

#ifndef APP_H
#define	APP_H

/*-----------------------includes-------------------------*/
#include"init.h"


/*----------------macros declaration-----------------*/
//frequency
#define _XTAL_FREQ          8000000
//modes
#define CARS_MODE           0
#define WHEN_GREEN_ON       1
#define WHEN_YELLOW_BLINK   2

/*----------------function declaration-----------------*/
void print_welcome(void);
void print_invalid(void);
void print_select_bage(void);
void print_motor1_operation(void);
void print_motor2_operation(void);
void print_diriction_page(void);
#endif	/* APP_H */