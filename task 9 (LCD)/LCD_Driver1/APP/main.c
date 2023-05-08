// MCAL layer
#include"../mcal/interface.h"
//HAL layer
#include"../HAL/lCD_interface.h"

// libraries layer
#include "../libraries/types.h"
#include"../libraries/Error_State.h"

//#include "../libraries/math.h"

//#include<util/delay.h>
void delay(void)
{
	for(int x=0;x<500;x++)
		for(int y=0;y<500;y++)
			__asm("NOP");
}

int main(void){
//	while(1){
	DIO_voidInit();
	LCD_enum_INIT();

	LCD_enum_GO_TO_XY(LCD_u8_LINE1,6);
	LCD_enum_Send_String("hello");

	LCD_enum_GO_TO_XY(LCD_u8_LINE2,6);

	LCD_enum_Send_char('E');
	LCD_enum_Send_char('M');
	LCD_enum_Send_char('A');
	LCD_enum_Send_char('N');

	delay();
	while(1);

return 0;
}
