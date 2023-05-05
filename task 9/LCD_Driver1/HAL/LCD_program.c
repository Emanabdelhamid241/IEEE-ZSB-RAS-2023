/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   2 May 2023     ********************/
/******************   SW :         LCD       ********************/
/******************  version :     1.0       ********************/
//libraries layer
#include"../libraries/math.h"
#include"../libraries/types.h"

//MCAL layer
#include"../MCAL/interface.h"



//HAL layer
#include"LCD_interface.h"
#include"LCD_config.h"
#include"LCD_private.h"

//#define F_CPU 8000000UL
#include<util/delay.h>

void LCD_void_INIT (void){
	_delay_ms(35);
//to set CMND
	LCD_void_Send_Comnd(FUN_SET_8BIT_2LINES_5X7);
	_delay_us(40);
	LCD_void_Send_Comnd(DIS_ON_CURSOR_ON_BLINKING);
	_delay_ms(40);
	LCD_void_Send_Comnd(DISPLAY_CLEAR);
	_delay_ms(1);
	LCD_void_Send_Comnd(ENTRY_MOOD);

}
//to send a command
void LCD_void_Send_Comnd(u8 Copy_u8_Comnd){
//RS =0
 DIO_u8_Set_Pin_Value ( LCD_u8_CONTROL_PORT,  LCD_u8_RS_PIN,  DIO_u8_LOW );
//RW = 0

 DIO_u8_Set_Pin_Value ( LCD_u8_CONTROL_PORT,  LCD_u8_RW_PIN,  DIO_u8_LOW );

//Write Command
 DIO_u8_Set_Port_Value ( LCD_u8_DATA_PORT,  Copy_u8_Comnd);

//E = 1
 DIO_u8_Set_Pin_Value ( LCD_u8_CONTROL_PORT,  LCD_u8_E_PIN,  DIO_u8_HIGH );
_delay_us(1);

//E = 0
 DIO_u8_Set_Pin_Value ( LCD_u8_CONTROL_PORT,  LCD_u8_E_PIN,  DIO_u8_LOW );

}
//to send a character
void LCD_void_Send_char(u8 Copy_u8_char){
	//RS =0
	 DIO_u8_Set_Pin_Value ( LCD_u8_CONTROL_PORT,  LCD_u8_RS_PIN,  DIO_u8_HIGH );
	//RW = 0

	 DIO_u8_Set_Pin_Value ( LCD_u8_CONTROL_PORT,  LCD_u8_RW_PIN,  DIO_u8_LOW );

	//Write char
	 DIO_u8_Set_Port_Value ( LCD_u8_DATA_PORT,  Copy_u8_char);

	//E = 1
	 DIO_u8_Set_Pin_Value ( LCD_u8_CONTROL_PORT,  LCD_u8_E_PIN,  DIO_u8_HIGH );
	 _delay_us(1);

	//E = 0
	 DIO_u8_Set_Pin_Value ( LCD_u8_CONTROL_PORT,  LCD_u8_E_PIN,  DIO_u8_LOW );

}
//function to set a location
u8 LCD_u8_GO_TO_XY (u8 Copy_u8_line_Num , u8 Copy_u8_Location ){
	u8 Local_u8_Erorr_State = ES_OK;
	if(Copy_u8_Location <= 39 ){
		switch (Copy_u8_line_Num)
		{
		case LCD_u8_LINE1 : LCD_void_Send_Comnd(ADDRESS_OF_LINE1+Copy_u8_Location);break;
		case LCD_u8_LINE2 : LCD_void_Send_Comnd(ADDRESS_OF_LINE2+Copy_u8_Location);break;
        default   :  Local_u8_Erorr_State = ES_NOK;

		}
	}
		else {
			Local_u8_Erorr_State = ES_NOK;


	}
return Local_u8_Erorr_State;
}
