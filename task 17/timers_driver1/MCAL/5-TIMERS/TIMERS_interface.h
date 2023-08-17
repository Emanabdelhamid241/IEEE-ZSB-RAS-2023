/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   7 August 2023     ********************/
/******************   SW :         TIMERS        ********************/
/******************  version :     1.0       ********************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

ES_t TIMERS_enum_TIMER0_INIT(void);
ES_t TIMERS_enum_TIMER0_SET_CALL_BACK(void(*Copy_pf)(void));
ES_t TIMERS_enum_TIMER0_CTC_SET_CALL_BACK(void(*Copy_pf)(void));


#endif
