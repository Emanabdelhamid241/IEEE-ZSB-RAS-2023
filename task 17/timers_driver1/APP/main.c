//libraries layer
#include"../libraries/math.h"
#include"../libraries/Error_State.h"
#include"../libraries/types.h"

//MCAL
#include "../MCAL/1-DIO/DIO_interface.h"
#include "../MCAL/3-GI/GI_interface.h"
#include "../MCAL/5-TIMERS/TIMERS_interface.h"
//HAL
#include "../HAL/1-LCD/LCD_interface.h"

#include <util/delay.h>
void APP_void_tog_led();

int main(){
    DIO_voidInit();
    LCD_enum_INIT();
		    DIO_u8_Set_Pin_Direction(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_INTIAL_OUTPUT);
		    DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);

	        GI_enum_GI_Enable();
	        TIMERS_enum_TIMER0_CTC_SET_CALL_BACK(&APP_void_tog_led);
	        	    TIMERS_enum_TIMER0_INIT();
	        	    LCD_enum_GO_TO_XY(1,0);

			LCD_enum_Send_String("Counter:");

while(1);

return 0;
}
void APP_void_tog_led(){
u8 switcha;
static u8 counter=0;
DIO_u8_Set_Pin_Direction(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_INPUT);
while(1){
	DIO_u8_Get_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN7,&switcha);
    _delay_ms(200);

	if(switcha== DIO_u8_HIGH){
//TURN ON
			DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
			counter++;
			LCD_enum_GO_TO_XY(2,0);
			LCD_enum_Send_Num(counter);
			switcha=0;
		}
		else{
//TURN OFF
			DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
		}
}
}

