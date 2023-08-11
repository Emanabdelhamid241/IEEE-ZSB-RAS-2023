//libraries layer
#include"../libraries/math.h"
#include"../libraries/Error_State.h"
#include"../libraries/types.h"

//MCAL
#include "../MCAL/1-DIO/DIO_interface.h"
#include "../MCAL/4-ADC/ADC_interface.h"
#include "../HAL/1-LCD/LCD_interface.h"

#include <util/delay.h>

//void ADC_void_ADC_Call_Back(u16 Copy_u16_ADC_VALUE );
static u16 APP_ADC_u16_DIGITAL_VALUE=0;

int main(){
	u16 LOCAL_ADC_u16_ANALOG_VALUE=0;
	u32 LOCAL_ADC_u16_RES_VALUE=0;

	DIO_voidInit();
    ADC_enum_ADC_INIT();
    LCD_enum_INIT();

    while(1){
//    	ADC_enum_GET_DIGITAL_VALUE_ASynch(ADC_u8_CHANNEL_0,&ADC_void_ADC_Call_Back);
    	ADC_enum_GET_DIGITAL_VALUE_Synch_Non_Blocking(ADC_u8_CHANNEL_0,&APP_ADC_u16_DIGITAL_VALUE);
    LOCAL_ADC_u16_ANALOG_VALUE=(u16)(APP_ADC_u16_DIGITAL_VALUE * 5000UL)/1024 ; /*range of mv to avoid floating numbers */
    LOCAL_ADC_u16_RES_VALUE = ((10000*1024UL)/LOCAL_ADC_u16_ANALOG_VALUE) - 10000;
	LCD_enum_GO_TO_XY(1,1);
	LCD_enum_Send_String("hello");
	_delay_ms(1000);
	    	LCD_enum_Clear();

	LCD_enum_GO_TO_XY(1,1);
	LCD_enum_Send_char('V');
	LCD_enum_Send_char(':');
	LCD_enum_GO_TO_XY(1,6);
	LCD_enum_Send_Num(LOCAL_ADC_u16_ANALOG_VALUE);

	LCD_enum_GO_TO_XY(2,1);
	LCD_enum_Send_char('r');
	LCD_enum_Send_char(':');
    LCD_enum_GO_TO_XY(2,6);
    LCD_enum_Send_Num(LOCAL_ADC_u16_RES_VALUE);
    	_delay_ms(1000);
    	LCD_enum_Clear();
//   u16 LOCAL_ADC_u16_TEMP_VALUE=LOCAL_ADC_u16_ANALOG_VALUE/10;
//   if(LOCAL_ADC_u16_TEMP_VALUE<2500)
//   {
//	   		DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
//
//   }
//   else{
//	   		DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
//
//   }

//    if (LOCAL_ADC_u16_TEMP_VALUE<25){
//		DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
//    }
//    else if ((LOCAL_ADC_u16_ANALOG_VALUE>=25)&&(LOCAL_ADC_u16_ANALOG_VALUE<=30)){
//		DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
//
//    }
//    else if (LOCAL_ADC_u16_ANALOG_VALUE>30){
//    		DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
//
//        }

    }
	return 0;
}
void ADC_void_ADC_Call_Back(u16 Copy_u16_ADC_VALUE ){
//	ADC_enum_GET_ADC_REG_VALUE(&APP_ADC_u16_DIGITAL_VALUE);
	APP_ADC_u16_DIGITAL_VALUE=Copy_u16_ADC_VALUE;
}

