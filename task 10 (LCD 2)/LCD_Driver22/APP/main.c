// MCAL layer
#include"../mcal/interface.h"
//HAL layer
#include"../HAL/lCD_interface.h"

// libraries layer
#include "../libraries/types.h"
#include"../libraries/Error_State.h"

#include "../libraries/math.h"

#include<util/delay.h>

int main(void){
	u8 counter=0;
	DIO_voidInit();
	LCD_enum_INIT();

//	array of stikers
	  u8 stiker0[8] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 };
//	  u8 stiker1[8] = { 0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00 };
//	  u8 stiker2[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };
//	  u8 stiker3[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00 };
//	  u8 stiker4[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 };
//	  u8 stiker5[8] = { 0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18 };
//	  u8 stiker6[8] = { 0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04 };
//	  u8 stiker7[8] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 };

	  LCD_enum_Send_Custom_char(0 , stiker0);
//	  LCD_enum_Send_Custom_char(1 , stiker1);
//	  LCD_enum_Send_Custom_char(2 , stiker2);
 //	  LCD_enum_Send_Custom_char(3 , stiker3);
 //	  LCD_enum_Send_Custom_char(4 , stiker4);

	  u8 switchb0 ;

	LCD_enum_GO_TO_XY(LCD_u8_LINE1,6);
	LCD_enum_Send_String("hello");
	LCD_enum_GO_TO_XY(LCD_u8_LINE2,6);
	LCD_enum_Send_String("EMAN");
	_delay_ms(500);
	LCD_enum_Clear();

	while(1){
		DIO_u8_Get_Pin_Value(DIO_u8_PORTB, DIO_u8_PIN1, &switchb0);
//		DIO_u8_Get_Pin_Value(DIO_u8_PORTB, DIO_u8_PIN1, &switchb1);
//		DIO_u8_Get_Pin_Value(DIO_u8_PORTB, DIO_u8_PIN2, &switchb2);
//		DIO_u8_Get_Pin_Value(DIO_u8_PORTB, DIO_u8_PIN3, &switchb3);
//		DIO_u8_Get_Pin_Value(DIO_u8_PORTB, DIO_u8_PIN4, &switchb4);
//		DIO_u8_Get_Pin_Value(DIO_u8_PORTB, DIO_u8_PIN5, &switchb5);
//		DIO_u8_Get_Pin_Value(DIO_u8_PORTB, DIO_u8_PIN6, &switchb6);
//		DIO_u8_Get_Pin_Value(DIO_u8_PORTB, DIO_u8_PIN7, &switchb7);
		    	_delay_ms(200);

		    	if(switchb0==1){
//to print first custom char

		    		LCD_enum_Send_char(0);
		    		counter++;
		    	}
//		    	else if(switchb1){
//		    		counter++;
//		    		LCD_enum_Send_char(1);
//
//		    	}
//		       	else if(switchb2){
// 		    		counter++;
//		      		LCD_enum_Send_char(2); }
//		      	else if(switchb3){
//    	    		counter++;
//  	    		LCD_enum_Send_char(3); }
//   	    	else if(switchb4){
// 		    		counter++;
// 		    		LCD_enum_Send_char(4);}
// 		    	else if(switchb5){
// 		    		counter++;
//		       		LCD_enum_Send_char(5);}
// 		    	else if(switchb6){
//      			 counter++;
//      			 LCD_enum_Send_char(6);}
//			   	else if(switchb7){
//		  			  counter++;
//	     			  LCD_enum_Send_char(7);}
//		    	else {
//		    		return 0;
//		    	}

 //check the end of the first line in LCD
if(counter == 17){
	LCD_enum_GO_TO_XY(LCD_u8_LINE2,0);
}
//check the end of the second line in LCD
else if(counter == 34){
	LCD_enum_Clear();
}
}
	return 0;
}


