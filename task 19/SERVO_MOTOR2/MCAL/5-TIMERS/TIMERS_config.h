/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   7 August 2023     ********************/
/******************   SW :         TIMERS        ********************/
/******************  version :     1.0       ********************/
#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H

//freqancy
#define F_CPU   8000000UL

/*intial counter value*/
#define TIMERS_u8_intial_counter_value   0

/*choice mode */
/*options
NORMAL_MODE       or
CTC_MODE          or
FAST_PWM_MODE     or
  */
#define  TIMER_MODE           FAST_PWM_MODE

/*TIMER1 set angle of sarvo motor = 0 */
#define TIMER1_u16_angle_zero          999

/*TIMER1 set angle of sarvo motor = 0 */
#define TIMER1_u16_angle_180          3999

#define TIMERS_SERVO_u8_MAX_ANGLE     180
#endif
