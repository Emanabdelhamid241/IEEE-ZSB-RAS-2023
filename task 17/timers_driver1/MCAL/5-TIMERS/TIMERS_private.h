/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   7 August 2023     ********************/
/******************   SW :         TIMERS        ********************/
/******************  version :     1.0       ********************/
#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

/* Define TIMER Registers*/
#define TIMERS_u8_TIMSK_REG      *((volatile u8 *)0x59)
#define TIMERS_u8_TIFR_REG     *((volatile u8 *)0x58)
#define TIMERS_u8_TCCR0_REG     *((volatile u8 *)0x53)
#define TIMERS_u8_TCNT0_REG     *((volatile u8 *)0x52)
#define TIMERS_u8_OCR0_REG     *((volatile u8 *)0x5C)

/*TCCR0*/
#define timers_WGM01_BIT3              3
#define timers_WGM00_BIT6              6

/*TIMSK*/
#define timers_TOIE0_BIT0              0
#define timers_OCIE0_BIT1              1

/*TCCR0*/
#define timers_CS00_BIT0              0
#define timers_CS01_BIT1              1
#define timers_CS02_BIT2              2

/*preload value*/
#define TIMERO_u8_preload_value        192

/*COMPARE MATCH VALUE*/
#define  COMPARE_MATCH_VALUE            99
/*counter of OVF*/
#define TIMER0_u8_Counter_of_OVF       3907
#define TIMER0_u8_Counter_of_OVF_CTC   10000


/**/
#define NORMAL_MODE   1
#define CTC_MODE      2

#endif
