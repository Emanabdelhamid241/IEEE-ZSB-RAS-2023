// MCAL layer
#include"../MCAL/interface.h"
//HAL layer
#include "../libraries/types.h"
#include"../libraries/Error_State.h"

#include "../libraries/math.h"
//MCAL  DIO
#include "../MCAL/interface.h"

#include<util/delay.h>
//HAL layer
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"


u8 pass[]="0000"  ;
u8 Local_u8_input[5] = {'\0'};
u8 Local_u8_index_input = 0;

int main(void){

	u8 Local_u8_Key,Local_u8_Counter;
	DIO_voidInit();
	LCD_enum_INIT();
	KPD_enum_Init();


	while(1){
//
//					LCD_enum_Send_String("hello");
//               			 _delay_ms(20);

	KPD_enum_Get_Key_State(&Local_u8_Key);
	_delay_ms(20);
	LCD_enum_GO_TO_XY (1 , 5);
	         LCD_enum_Send_char('*');
/*is there is no keys pressed*/
	/*no displaying on LCD*/
//	if(Local_u8_Key != KPD_u8_Keys_NO_Pressed  ){
//		LCD_enum_GO_TO_XY (1 , 5);
//
//         LCD_enum_Send_char('*');
//         Local_u8_input[Local_u8_index_input] = Local_u8_Key;
//         Local_u8_index_input++;
//    	 if (Local_u8_index_input >= 4) {
//    		if (Local_u8_input[Local_u8_index_input] ==pass[Local_u8_index_input]) {
//    			LCD_enum_Clear ();
//    		    LCD_enum_Send_String ("Correct Password");
//                 }
//    		else{
//    			LCD_enum_Clear ();
//    			 LCD_enum_Send_String ("wrong Password,please try again");
//     			Local_u8_Counter++;
//     			if(Local_u8_Counter>=4){
//         			LCD_enum_Clear ();
//       			 LCD_enum_Send_String ("please try again after 1 min");
//       			 _delay_ms(60000);
//      			LCD_enum_Clear ();
//     			}
//
//    		}
//	}
//	}
	}
	return 0;
	}
