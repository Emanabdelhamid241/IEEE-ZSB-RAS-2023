/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   20 August 2023    ********************/
/******************   SW : SERVO MOTOR       ********************/
/******************  version :     1.0       ********************/
#ifndef SERVO_MOTOR_PRIVATE_H
#define SERVO_MOTOR_PRIVATE_H

#define TIMERS_SERVO_u8_MAX_ANGLE    180UL

#define TIMERS_u16_OCR1A_REG      *((volatile u16 *)0x4A)
#define TIMER1_u16_angle_zero    999
#endif
