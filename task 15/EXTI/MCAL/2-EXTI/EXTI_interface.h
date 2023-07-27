/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   27 july 2023     ********************/
/******************   SW :         EXTI      ********************/
/******************  version :     1.0       ********************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "EXTI_config.h"

ES_t  EXTI_enum_EXTI_Enable(u8 Copy_u8_EXTI_Index,u8 Copy_u8_Edge_Index);
ES_t  EXTI_enum_EXTI_Disable(u8 Copy_u8_EXTI_Index);
ES_t EXTI_enum_Set_Call_Back( u8 Copy_u8_EXTI_Index,void(*Copy_u8_EXTI_pf)(void));


//ES_t  EXTI_enum_EXTI_Enable(void);
#endif
