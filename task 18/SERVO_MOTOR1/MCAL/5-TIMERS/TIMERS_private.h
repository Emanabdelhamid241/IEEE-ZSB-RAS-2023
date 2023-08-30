/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   7 August 2023     ********************/
/******************   SW :         TIMERS        ********************/
/******************  version :     1.0       ********************/
#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

/* Define TIMER Registers of timer0 */
#define TIMERS_u8_TIMSK_REG      *((volatile u8 *)0x59)
#define TIMERS_u8_TIFR_REG     *((volatile u8 *)0x58)
#define TIMERS_u8_TCCR0_REG     *((volatile u8 *)0x53)
#define TIMERS_u8_TCNT0_REG     *((volatile u8 *)0x52)
#define TIMERS_u8_OCR0_REG     *((volatile u8 *)0x5C)

/*Define TIMER Registers of timer1 */
#define TIMERS_u8_TCCR1A_REG      *((volatile u8 *)0x4F)
#define TIMERS_u8_TCCR1B_REG      *((volatile u8 *)0x4E)
#define TIMERS_u8_TCNT1H_REG      *((volatile u8 *)0x4D)
#define TIMERS_u8_TCNT1L_REG      *((volatile u8 *)0x4C)

#define TIMERS_u16_TCNT1_REG      *((volatile u16 *)0x4C)

#define TIMERS_u16_OCR1AH_REG      *((volatile u16 *)0x4B)
#define TIMERS_u16_OCR1AL_REG      *((volatile u16 *)0x4A)

#define TIMERS_u16_OCR1A_REG      *((volatile u16 *)0x4A)

#define TIMERS_u16_ICR1H_REG      *((volatile u16 *)0x47)
#define TIMERS_u16_ICR1L_REG      *((volatile u16 *)0x46)

#define TIMERS_u16_ICR1_REG      *((volatile u16 *)0x46)


/*TIMER0 TIMSK*/
#define timers_TOIE0_BIT0              0
#define timers_OCIE0_BIT1              1

/*TIMER0 TCCR0*/
#define timers_CS00_BIT0              0
#define timers_CS01_BIT1              1
#define timers_CS02_BIT2              2
#define timers_WGM01_BIT3             3
#define timers_COM00_BIT4             4
#define timers_COM01_BIT5             5
#define timers_WGM00_BIT6             6


/*TIMER0 preload value*/
#define TIMERO_u8_preload_value        192

/*TIMER0 COMPARE MATCH VALUE*/
#define  COMPARE_MATCH_VALUE            99
/*TIMER0 counter of OVF*/
#define TIMER0_u8_Counter_of_OVF       3907
#define TIMER0_u8_Counter_of_OVF_CTC   10000


/*macros for modes*/
#define NORMAL_MODE                 1
#define CTC_MODE                    2
#define FAST_PWM_MODE               3
#define PHASE_CORRECT_PWM_MODE      4

/*TIMER1 TCCR1A */
#define timers_WGM10_BIT0              0
#define timers_WGM11_BIT1              1
#define timers_COM1A0_BIT6             6
#define timers_COM1A1_BIT7             7



/*TIMER1 TCCR1B */
#define timers_CS10_BIT0              0
#define timers_CS11_BIT1              1
#define timers_CS12_BIT2              2
#define timers_WGM12_BIT3             3
#define timers_WGM13_BIT4             4

/*TIMER1 TOP Value IN OCI1*/
#define TIMER1_u16_TOP_Value_IN_OCI1     19999

#endif
