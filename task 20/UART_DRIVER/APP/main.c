//HAL layer
#include "../libraries/types.h"
#include"../libraries/Error_State.h"

#include "../libraries/math.h"
//MCAL  DIO
#include "../MCAL/1-DIO/DIO_interface.h"
#include "../MCAL/7-UART/UART_interface.h"

#include<util/delay.h>


#define string_check  "#h#"
int main(){
	u8 data,string;
	DIO_voidInit();
	UART_enum_INIT();
//	DIO_u8_Set_Port_Direction(DIO_u8_PORTA,DIO_u8_OUTPUT);
//	DIO_u8_Set_Port_Value(DIO_u8_PORTA,DIO_u8_LOW);

	DIO_u8_Set_Pin_Direction(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_INPUT);
	DIO_u8_Set_Pin_Direction(DIO_u8_PORTD,DIO_u8_PIN1,DIO_u8_OUTPUT);
//test
//	DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);

//print in terminal
	UART_enum_Send_String("enter r , y or g ");
	while(1){
	UART_enum_RECIEVE_String (&string);
UART_enum_RECIEVE_Byte(&data);

switch(data){
case 'r':	DIO_u8_Set_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
break;
case 'y':	DIO_u8_Set_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
break;
case 'g':	DIO_u8_Set_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
break;
}

if(string==string_check){
	DIO_u8_Set_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
}

	}


	return 0;
}
