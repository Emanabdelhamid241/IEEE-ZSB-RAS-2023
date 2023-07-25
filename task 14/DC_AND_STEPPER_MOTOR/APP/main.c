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
#include "../HAL/1-LCD/LCD_interface.h"
#include "../HAL/2-KPD/KPD_interface.h"

#define CW 1
#define CCW 2

u8 pass[]="0000"  ;
u8 Local_u8_input[5] = {'\0'};
u8 Local_u8_index_input = 0;

int main(void){
	u8 Local_u8_Key,Local_u8_Counter;
	DIO_voidInit();
	LCD_enum_INIT();
	KPD_enum_Init();
	LCD_enum_Send_String("enter password");


	while(1){

		//

//               			 _delay_ms(200);

	KPD_enum_Get_Key_State(&Local_u8_Key);
	_delay_ms(20);
/*is there is no keys pressed*/
	/*no displaying on LCD*/
	if(Local_u8_Key != KPD_u8_Keys_NO_Pressed  ){
		LCD_enum_GO_TO_XY (1 , 2);

         LCD_enum_Send_char('*');
         Local_u8_input[Local_u8_index_input] = Local_u8_Key;
         Local_u8_index_input++;
    	 if (Local_u8_index_input >= 4) {
    		if (Local_u8_input[Local_u8_index_input] ==pass[Local_u8_index_input]) {
    			LCD_enum_Clear ();
    		    LCD_enum_Send_String ("Correct Password");
    		                   			 _delay_ms(200);
    		                 			LCD_enum_Clear ();
    		                 			LCD_enum_GO_TO_XY (1 , 0);
    		                		    LCD_enum_Send_String ("1-DC MOTOR");
    		                		    LCD_enum_GO_TO_XY (2 , 0);
    		                		    LCD_enum_Send_String ("2-STEPPER MOTOR");
    		                		    if(Local_u8_input==1){

    		                		    	LCD_enum_Clear ();
    		                		   		LCD_enum_GO_TO_XY (1 , 0);
    		                	   		    LCD_enum_Send_String ("1-CW");
    		                	   		 LCD_enum_GO_TO_XY (1 , 5);
    		                	   	    LCD_enum_Send_String ("2-CCW");
    		                		    	 LCD_enum_GO_TO_XY (2 , 0);
    		                		    	 LCD_enum_Send_String ("3-STOP");
                                            if(Local_u8_input==1)	DC_MOTOR_enum_Start(CW);
                                            else if(Local_u8_input==2)	DC_MOTOR_enum_Start(CCW);
                                            else if(Local_u8_input==3)	DC_MOTOR_enum_Stop();

    		                		    }
    		                		    else if(Local_u8_input==2){
    		                		    	LCD_enum_Clear ();
    		                		   	LCD_enum_GO_TO_XY (1 , 0);
    		                	    LCD_enum_Send_String ("1-CW");
    		               	   		 LCD_enum_GO_TO_XY (2 , 0);
    		                	   	    LCD_enum_Send_String ("2-CCW");
    		                                  if(Local_u8_input==1)	Stepper_moter_enum_Move(CW);
    		                                      else if(Local_u8_input==2)	Stepper_moter_enum_Move(CCW);
    		                		    }

                 }
    		else{
    			LCD_enum_Clear ();
    			 LCD_enum_Send_String ("wrong Password,please try again");
     			Local_u8_Counter++;
     			if(Local_u8_Counter>=4){
         			LCD_enum_Clear ();
       			 LCD_enum_Send_String ("please try again after 1 min");
       			 _delay_ms(60000);
      			LCD_enum_Clear ();
     			}

    		}
    	 }}
	}
	return 0;
	}
