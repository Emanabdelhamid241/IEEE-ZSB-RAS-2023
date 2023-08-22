/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   4 August 2023     ********************/
/******************   SW :         ADC        ********************/
/******************  version :     1.0       ********************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include"ADC_config.h"

ES_t  ADC_enum_ADC_INIT(void);

ES_t  ADC_enum_GET_DIGITAL_VALUE_Synch_Non_Blocking(u8 Copy_u8_ADC_Channel_NB,u16 * Copy_pu16_ADC_Digital_Value);

ES_t  ADC_enum_GET_DIGITAL_VALUE_ASynch(u8 Copy_u8_ADC_Channel_NB,void(*Copy_pf_ADC_notifction)(void));

ES_t  ADC_enum_GET_ADC_REG_VALUE(u16 * Copy_pu16_ADC_Value);

#endif
