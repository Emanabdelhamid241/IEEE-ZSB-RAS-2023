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


#define len 4

#define pass "0000"
u8 Local_u8_input[len] ;
int main(void){
	u8 Local_u8_Key,Local_u8_Counter=0,flag=0;
	u8 spass[]=pass;
	u8 Local_u8_index_input ;


	            DIO_voidInit();
				LCD_enum_INIT();
				KPD_enum_Init();
				LCD_enum_Send_String("enter password");
				_delay_ms(1000);
					LCD_enum_Clear ();


	while(1){
       	KPD_enum_Get_Key_State(&Local_u8_Key);
/*is there is no keys pressed*/
	/*no displaying on LCD*/
	if(Local_u8_Key != KPD_u8_Keys_NO_Pressed  ){
         LCD_enum_Send_char('*');

         Local_u8_input[Local_u8_index_input] = Local_u8_Key;
         Local_u8_index_input++;
         Local_u8_Counter++;
	}
    	 if (Local_u8_Counter == len) {
    		 for(Local_u8_index_input =0 ;Local_u8_index_input<len ; Local_u8_index_input++){
    		 				if(Local_u8_input[Local_u8_index_input] == spass[Local_u8_index_input]){
    		 					LCD_enum_Clear ();
    		 					 LCD_enum_Send_String ("Correct Password");
    		 					_delay_ms(1000);
    		 				 LCD_enum_Clear ();
    		 				 break;
    		 				}
    		 				else{
//    		 				    			LCD_enum_Clear ();
    		 				    			 LCD_enum_Send_String ("wrong Password,");
    		 				    			 LCD_enum_GO_TO_XY(2,0);
    		 				    			LCD_enum_Send_String ("please try again");
    		 				    			_delay_ms(1000);
    		 				    			LCD_enum_Clear ();
    		                      }
                 }
    	 }

//     			Local_u8_Counter++;
//     			if(Local_u8_Counter>=4){
//         			LCD_enum_Clear ();
//       			 LCD_enum_Send_String ("please try again after 1 min");
//       			 _delay_ms(60000);
//      			LCD_enum_Clear ();
//     			}

//    		}
	}
	return 0;
	}
