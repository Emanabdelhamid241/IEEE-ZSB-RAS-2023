/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   22 july 2023    ********************/
/******************   SW : STEPPER MOTOR       ********************/
/******************  version :     1.0       ********************/
#ifndef STEPPER_MOTOR_CONFIG_H
#define STEPPER_MOTOR_CONFIG_H

//macros of port
#define STEPPER_MOTOR_BLUE_PORT    DIO_u8_PORTD
#define STEPPER_MOTOR_PINK_PORT    DIO_u8_PORTD
#define STEPPER_MOTOR_YELLOW_PORT  DIO_u8_PORTD
#define STEPPER_MOTOR_ORANGE_PORT  DIO_u8_PORTD

//macros of pins
#define STEPPER_MOTOR_BLUE_PIN    DIO_u8_PIN0
#define STEPPER_MOTOR_PINK_PIN    DIO_u8_PIN1
#define STEPPER_MOTOR_YELLOW_PIN  DIO_u8_PIN4
#define STEPPER_MOTOR_ORANGE_PIN  DIO_u8_PIN3

#define  periodic_time_delay 10

#define    CW     1
#define    CCW    2

#define    number_of_steps_in_full_step      4
#define    number_of_steps_in_half_step      8

#endif
