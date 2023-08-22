/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   7 August 2023     ********************/
/******************   SW :         TIMERS        ********************/
/******************  version :     1.0       ********************/
#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H
/*intial counter value*/
#define TIMERS_u8_intial_counter_value   0

/*choice mode */
/*options
NORMAL_MODE       or
CTC_MODE          or
FAST_PWM_INVERTING_MODE     or
  */
//#define  TIMER0_MODE           NORMAL_MODE
//
//#define  TIMER1_MODE           PHASE_CORRECT_PWM_INVERTING_MODE

/*TIMER1 set angle of sarvo motor = 0 */
#define TIMER1_u16_angle_zero          999

/*TIMER1 set angle of sarvo motor = 0 */
#define TIMER1_u16_angle_180          1999

/*macros for modes*/
#define NORMAL_MODE                           1
#define CTC_MODE                              2
#define FAST_PWM_NON_INVERTING_MODE               3
#define PHASE_CORRECT_PWM_NON_INVERTING_MODE                4

#endif
