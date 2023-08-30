/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   2 May 2023     ********************/
/******************   SW :         LCD       ********************/
/******************  version :     1.0       ********************/
//libraries layer
//#include"../libraries/math.h"
#include"../../libraries/types.h"
#include"../../libraries/Error_State.h"

//MCAL layer
#include"../../MCAL/1-DIO/DIO_interface.h"



//HAL layer
#include"LCD_interface.h"
#include"LCD_config.h"
#include"LCD_private.h"

//#define F_CPU 8000000UL
#include<util/delay.h>

ES_t LCD_enum_INIT (void){
	_delay_ms(35);
//to set CMND
	LCD_enum_Send_Comnd(FUN_SET_8BIT_2LINES_5X7);
	_delay_us(40);
	LCD_enum_Send_Comnd(DIS_ON_CURSOR_ON_BLINKING);
	_delay_ms(40);
	LCD_enum_Send_Comnd(DISPLAY_CLEAR);
	_delay_ms(1);
	LCD_enum_Send_Comnd(ENTRY_MOOD);
    return ES_OK;
}
//to send a command
ES_t LCD_enum_Send_Comnd(u8 Copy_u8_Comnd){
#if  LCD_u8_MODE == LCD_u8_MODE_8_bit
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
 return ES_OK;
#elif  LCD_u8_MODE == LCD_u8_MODE_4_bit
//code for send command if mode 4 bit
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

//write the rest of the cmnd
  DIO_u8_Set_Port_Value ( LCD_u8_DATA_PORT,  Copy_u8_Comnd<<4);

  //E = 1
    DIO_u8_Set_Pin_Value ( LCD_u8_CONTROL_PORT,  LCD_u8_E_PIN,  DIO_u8_HIGH );
   _delay_us(1);

   //E = 0
    DIO_u8_Set_Pin_Value ( LCD_u8_CONTROL_PORT,  LCD_u8_E_PIN,  DIO_u8_LOW );
return ES_OK;

#endif

}
//function to send a character
ES_t LCD_enum_Send_char(u8 Copy_u8_char){
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
	    return ES_OK;

}
//function to set a location
ES_t LCD_enum_GO_TO_XY (u8 Copy_u8_line_Num , u8 Copy_u8_Location ){
//	u8 Local_u8_Erorr_State = ES_OK;
	if(Copy_u8_Location <= 39 ){
		switch (Copy_u8_line_Num)
		{
		case LCD_u8_LINE1 : LCD_enum_Send_Comnd(ADDRESS_OF_LINE1+Copy_u8_Location);break;
		case LCD_u8_LINE2 : LCD_enum_Send_Comnd(ADDRESS_OF_LINE2+Copy_u8_Location);break;
        default   :  return ES_NOK;

		}

	}
		else {
			return ES_NOK;


	}
    return ES_OK;
}
//function to send string
ES_t LCD_enum_Send_String(u8 *copy_pu8_string){
	for (u8 i ; copy_pu8_string[i] != '\0'; i++){
		LCD_enum_Send_char(copy_pu8_string[i]);
	}
	return ES_OK;
}

//function to clear
ES_t LCD_enum_Clear (void){
	LCD_enum_Send_Comnd(DISPLAY_CLEAR);
	_delay_ms(1);
	return ES_OK;
}

//function to send custom char
ES_t LCD_enum_Send_Custom_char(u8 Copy_u8_Location , u8 * Copy_pu8_char_Array){
	if(Copy_pu8_char_Array != NULL && Copy_u8_Location < MAX_CHARACTERS )
	    {
		LCD_enum_Send_Comnd(ADDRESS_OF_CGRAM + (Copy_u8_Location * MAX_CHARACTERS ));
	        for (u8 Local_u8_Counter = 0; Local_u8_Counter < MAX_CHARACTERS ; Local_u8_Counter++)
	        {
	        	LCD_enum_Send_char(Copy_pu8_char_Array[Local_u8_Counter]);
	        }
	        LCD_enum_GO_TO_XY(LCD_u8_LINE1,0);
//	        LCD_enum_Send_char(Copy_u8_Location);
	        return ES_OK;

	    }
	    else
	    {
	        return ES_NOK;
	    }

}
ES_t LCD_enum_Send_Num(u32 Copy_LCD_u32_Num)
{
	u8 arr[10], i = 0, j = 0;
	if (Copy_LCD_u32_Num == 0)
	{
		LCD_enum_Send_char('0');
	}
	else
	{
		while (Copy_LCD_u32_Num)
		{
			arr[i] = Copy_LCD_u32_Num % 10 + '0';
			Copy_LCD_u32_Num /= 10;
			i++;
		}

		for (j = i; j > 0; j--)
		{
			LCD_enum_Send_char(arr[j - 1]);
		}
	}
    return ES_NOK;
}
