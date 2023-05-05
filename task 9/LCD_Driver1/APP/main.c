// MCAL layer
#include"../mcal/interface.h"
//HAL layer
#include"../HAL/lCD_interface.h"

// libraries layer
#include "../libraries/types.h"
#include "../libraries/math.h"



int main(){
	void DIO_voidInit();
	void LCD_void_INIT (void);

	LCD_u8_GO_TO_XY(LCD_u8_LINE1,5);

	 LCD_void_Send_char("E");
	 LCD_void_Send_char("M");
	 LCD_void_Send_char("A");
	 LCD_void_Send_char("N");

	while(1);

return 0;
}
