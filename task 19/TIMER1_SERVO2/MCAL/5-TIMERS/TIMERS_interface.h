/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   7 August 2023     ********************/
/******************   SW :         TIMERS        ********************/
/******************  version :     1.0       ********************/
#include "TIMERS_config.h"
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

ES_t TIMERS_enum_TIMER0_INIT(u8 Copy_u8_MODE);
ES_t TIMERS_enum_TIMER1_INIT(u8 Copy_u8_MODE);

ES_t TIMERS_enum_TIMER0_SET_CALL_BACK(void(*Copy_pf_TIMER0)(void),u8 Copy_u8_MODE);

ES_t TIMERS_enum_TIMER0_SET_COMPARE_MATCH_VALUE(u8 Copy_u8_OCR0_Value);
ES_t TIMERS_enum_TIMER0_SET_PRESCAlER_VALUE(u8 Copy_u8_TCNT0_Value);
u8 TIMERS_enum_TIMER0_REED_TIMER_VALUE(void);
ES_t TIMERS_enum_TIMER1_SET_COMPARE_MATCH_VALUE_A(u16 Copy_u16_ICR1_Value);

ES_t TIMERS_enum_TIMER1_SET_PRESCAlER_VALUE(u16 Copy_u16_TCNT1_Value);
		u16 TIMERS_enum_TIMER1_REED_TIMER_VALUE(void);

#endif
