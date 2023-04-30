// MCAL layer
#include"../mcal/interface.h"

// libraries layer
#include "../libraries/types.h"
#include "../libraries/math.h"

int main(){
	void DIO_voidInit(void);
	//Pins Directions
	DIO_u8_Set_Pin_Direction(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_INPUT);

	DIO_u8_Set_Pin_Direction(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_OUTPUT);

	DIO_u8_Set_Pin_Direction(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_OUTPUT);
//Switches
	u8 switcha;
	while(1){
//Set Pin Value
		DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_HIGH);
//	Get Pin Values
		DIO_u8_Get_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN0,&switcha);
//	Switch a
		if(switcha == DIO_u8_HIGH){
//TURN ON
			DIO_u8_Set_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH);
		}
		else{
//TURN OFF
			DIO_u8_Set_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_LOW);
		}

	}
return 0;
}
