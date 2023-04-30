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

	DIO_u8_Set_Pin_Direction(DIO_u8_PORTC,DIO_u8_PIN0,DIO_u8_INPUT);

	DIO_u8_Set_Pin_Direction(DIO_u8_PORTC,DIO_u8_PIN2,DIO_u8_OUTPUT);

	DIO_u8_Set_Pin_Direction(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_OUTPUT);

	DIO_u8_Set_Port_Direction(DIO_u8_PORTD,DIO_u8_OUTPUT);
//Switches
	u8 switcha;
	u8 switchc;
	while(1){
//Set Pin Value
		DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_HIGH);
		DIO_u8_Set_Port_Value(DIO_u8_PORTD,DIO_u8_HIGH);
//	Get Pin Values
		DIO_u8_Get_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN0,&switcha);
		DIO_u8_Get_Pin_Value(DIO_u8_PORTC,DIO_u8_PIN0,&switchc);
//	Switch a
		if(switcha == DIO_u8_HIGH){
//TURN ON
			DIO_u8_Set_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH);
		}
		else{
//TURN OFF
			DIO_u8_Set_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_LOW);
		}
//switch c
		if(switchc == DIO_u8_HIGH){
//TURN ON
			DIO_u8_Set_Pin_Value(DIO_u8_PORTC,DIO_u8_PIN2,DIO_u8_HIGH);
		}
		else{
//TURN OFF
			DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
		}
	}
return 0;
}
