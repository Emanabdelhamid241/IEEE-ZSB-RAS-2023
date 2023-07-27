//libraries layer
#include"../libraries/math.h"
#include"../libraries/Error_State.h"
#include"../libraries/types.h"

//MCAL
#include "../MCAL/1-DIO/DIO_interface.h"
#include "../MCAL/2-EXTI/EXTI_interface.h"
#include "../MCAL/3-GI/GI_interface.h"


void TOG_LED(void);

int main(){
DIO_voidInit();
GI_enum_GI_Enable();
EXTI_enum_Set_Call_Back( EXTI_u8_INT0,&TOG_LED);
EXTI_enum_EXTI_Enable(EXTI_u8_INT0,EXTI_u8_ANY_LOGICAL_CHANGE);
while(1);


	return 0;
}

void TOG_LED(void)
{
static u8 Local_u8_Flag =0;
	if(Local_u8_Flag == 0)
	{
		DIO_u8_Set_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		Local_u8_Flag=1;
	}
	else{
		DIO_u8_Set_Pin_Value(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
				Local_u8_Flag=0;
	}
}
