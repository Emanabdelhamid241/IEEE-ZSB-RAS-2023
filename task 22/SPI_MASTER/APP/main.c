//HAL layer
#include "../libraries/types.h"
#include"../libraries/Error_State.h"

#include "../libraries/math.h"
//MCAL  DIO
#include "../MCAL/1-DIO/DIO_interface.h"
#include "../MCAL/8-SPI/SPI_interface.h"

#include<util/delay.h>


int main(){
	u8 local_u8_data=0;
//	DIO_voidInit();
	SPI_enum_INIT();
	DIO_u8_Set_Pin_Direction(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT);
	DIO_u8_Set_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);

	while(1){
		SPI_enum_trans_recieve(5,&local_u8_data);
		if(local_u8_data==10){
			DIO_u8_Set_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		}
		_delay_ms(2000);
	}


	return 0;
}
