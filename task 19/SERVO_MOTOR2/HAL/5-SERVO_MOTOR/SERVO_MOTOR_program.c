/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   20 August 2023    ********************/
/******************   SW : SERVO MOTOR       ********************/
/******************  version :     1.0       ********************/
#include"../../libraries/types.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/math.h"

//MCAL layer (DIO)
#include"../../MCAL/1-DIO/DIO_interface.h"
#include"../../MCAL/5-TIMERS/TIMERS_interface.h"

//HAL layer
#include "SERVO_MOTOR_config.h"
#include "SERVO_MOTOR_private.h"

#include<util/delay.h>

ES_t SERVO_motor_enum_INIT (void)
{
ES_t  Local_enu_Erorr_State = ES_OK ;
DIO_u8_Set_Pin_Direction(DIO_u8_PORTD,DIO_u8_PIN5,DIO_u8_OUTPUT);
TIMERS_enum_TIMER1_INIT();

return Local_enu_Erorr_State;
}

ES_t SERVO_MOTOR_enum_SET_Servo_Motor_Angle(u16 Copy_u16_Servo_Motor_Angle)
{
	ES_t Local_enu_Erorr_State= ES_OK;
	if(Copy_u16_Servo_Motor_Angle <= TIMERS_SERVO_u8_MAX_ANGLE)
	{

		TIMERS_u16_OCR1A_REG = ((Copy_u16_Servo_Motor_Angle*1000UL)/TIMERS_SERVO_u8_MAX_ANGLE)+999;

	}
	else{
		Local_enu_Erorr_State= ES_NOK;

	}
			return Local_enu_Erorr_State;

}
