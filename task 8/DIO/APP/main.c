// MCAL layer
#include"../mcal/interface.h"

// libraries layer
#include "../libraries/types.h"
#include "../libraries/math.h"

void delay(void)
{
	for(int x=0;x<1000;x++)
		for(int y=0;y<1000;y++)
			__asm("NOP");
}

int main(){
	void DIO_voidInit();
	//Pins Directions


	DIO_u8_Set_Pin_Direction(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_OUTPUT);

	DIO_u8_Set_Pin_Direction(DIO_u8_PORTC,DIO_u8_PIN7,DIO_u8_OUTPUT);



	while(1){

		        DIO_u8_Set_Pin_Value(DIO_u8_PORTC,DIO_u8_PIN7,DIO_u8_HIGH);
		        DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_HIGH);
				delay();

				DIO_u8_Set_Pin_Value(DIO_u8_PORTC,DIO_u8_PIN7,DIO_u8_LOW);
		        DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_LOW);
				delay();
//Set Pin Value
		DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_HIGH);


	}
return 0;
}
