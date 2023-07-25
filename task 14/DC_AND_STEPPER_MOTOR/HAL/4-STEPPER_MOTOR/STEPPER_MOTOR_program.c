/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   22 july 2023    ********************/
/******************   SW : STEPPER MOTOR       ********************/
/******************  version :     1.0       ********************/
//from libraries layer
#include"../../libraries/types.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/math.h"

//MCAL layer (DIO)
#include"../../MCAL/interface.h"

//HAL layer
#include "STEPPER_MOTOR_config.h"
#include "STEPPER_MOTOR_interface.h"
#include "STEPPER_MOTOR_private.h"

#include<util/delay.h>

ES_t Stepper_motor_enum_INIT (){
	ES_t Local_enu_Erorr_State=ES_OK;

	 DIO_u8_Set_Pin_Direction  (STEPPER_MOTOR_BLUE_PORT, STEPPER_MOTOR_BLUE_PIN, DIO_u8_OUTPUT );
	 DIO_u8_Set_Pin_Direction  (STEPPER_MOTOR_PINK_PORT,STEPPER_MOTOR_PINK_PIN, DIO_u8_OUTPUT );
	 DIO_u8_Set_Pin_Direction  (STEPPER_MOTOR_YELLOW_PORT,STEPPER_MOTOR_YELLOW_PIN , DIO_u8_OUTPUT );
	 DIO_u8_Set_Pin_Direction  (STEPPER_MOTOR_ORANGE_PORT,STEPPER_MOTOR_ORANGE_PIN, DIO_u8_OUTPUT );


	 DIO_u8_Set_Pin_Value (STEPPER_MOTOR_BLUE_PORT,STEPPER_MOTOR_BLUE_PIN ,DIO_u8_HIGH );
	 DIO_u8_Set_Pin_Value (STEPPER_MOTOR_PINK_PORT,STEPPER_MOTOR_PINK_PIN ,DIO_u8_HIGH );
     DIO_u8_Set_Pin_Value (STEPPER_MOTOR_YELLOW_PORT,STEPPER_MOTOR_YELLOW_PIN ,DIO_u8_HIGH );
     DIO_u8_Set_Pin_Value (STEPPER_MOTOR_ORANGE_PORT,STEPPER_MOTOR_ORANGE_PIN ,DIO_u8_HIGH );
return Local_enu_Erorr_State;
}


ES_t Stepper_moter_enum_Move(u8 copy_u8_direction,u8 copy_u8_Angle){
u8 Local_u8_step_Counter;
ES_t Local_enu_Erorr_State=ES_OK;

//to calculate number of steps for custom angle
u8 Number_Of_Steps = ((copy_u8_Angle*Namber_Of_Steps_for_360degree)/degree_360);
u8 Number_Of_Forloop =Number_Of_Steps/number_of_steps_in_full_step;
//FOR LOOP TO ROTATE AT CUSTOM ANGLE

if(copy_u8_direction==CW){
for (Local_u8_step_Counter=start;Local_u8_step_Counter>Number_Of_Forloop;Local_u8_step_Counter++){

     //step1 -------->BLUE PIN IS LOW
 DIO_u8_Set_Pin_Value (STEPPER_MOTOR_BLUE_PORT,STEPPER_MOTOR_BLUE_PIN ,DIO_u8_LOW );
 DIO_u8_Set_Pin_Value (STEPPER_MOTOR_PINK_PORT,STEPPER_MOTOR_PINK_PIN ,DIO_u8_HIGH );
 DIO_u8_Set_Pin_Value (STEPPER_MOTOR_YELLOW_PORT,STEPPER_MOTOR_YELLOW_PIN ,DIO_u8_HIGH );
 DIO_u8_Set_Pin_Value (STEPPER_MOTOR_ORANGE_PORT,STEPPER_MOTOR_ORANGE_PIN ,DIO_u8_HIGH );
	_delay_ms(periodic_time_delay);
    //step1 -------->PINK PIN IS LOW
DIO_u8_Set_Pin_Value (STEPPER_MOTOR_BLUE_PORT,STEPPER_MOTOR_BLUE_PIN ,DIO_u8_HIGH );
DIO_u8_Set_Pin_Value (STEPPER_MOTOR_PINK_PORT,STEPPER_MOTOR_PINK_PIN ,DIO_u8_LOW );
DIO_u8_Set_Pin_Value (STEPPER_MOTOR_YELLOW_PORT,STEPPER_MOTOR_YELLOW_PIN ,DIO_u8_HIGH );
DIO_u8_Set_Pin_Value (STEPPER_MOTOR_ORANGE_PORT,STEPPER_MOTOR_ORANGE_PIN ,DIO_u8_HIGH );
	_delay_ms(periodic_time_delay);
	//step1 -------->YELLOW PIN IS LOW
DIO_u8_Set_Pin_Value (STEPPER_MOTOR_BLUE_PORT,STEPPER_MOTOR_BLUE_PIN ,DIO_u8_HIGH );
DIO_u8_Set_Pin_Value (STEPPER_MOTOR_PINK_PORT,STEPPER_MOTOR_PINK_PIN ,DIO_u8_HIGH );
DIO_u8_Set_Pin_Value (STEPPER_MOTOR_YELLOW_PORT,STEPPER_MOTOR_YELLOW_PIN ,DIO_u8_LOW );
DIO_u8_Set_Pin_Value (STEPPER_MOTOR_ORANGE_PORT,STEPPER_MOTOR_ORANGE_PIN ,DIO_u8_HIGH );
	_delay_ms(periodic_time_delay);
	//step1 -------->ORANGE PIN IS LOW
DIO_u8_Set_Pin_Value (STEPPER_MOTOR_BLUE_PORT,STEPPER_MOTOR_BLUE_PIN ,DIO_u8_HIGH );
DIO_u8_Set_Pin_Value (STEPPER_MOTOR_PINK_PORT,STEPPER_MOTOR_PINK_PIN ,DIO_u8_HIGH );
DIO_u8_Set_Pin_Value (STEPPER_MOTOR_YELLOW_PORT,STEPPER_MOTOR_YELLOW_PIN ,DIO_u8_HIGH );
DIO_u8_Set_Pin_Value (STEPPER_MOTOR_ORANGE_PORT,STEPPER_MOTOR_ORANGE_PIN ,DIO_u8_LOW );
	_delay_ms(periodic_time_delay);
}
}
else if (copy_u8_direction==CCW){
	for (Local_u8_step_Counter=start;Local_u8_step_Counter>Number_Of_Forloop;Local_u8_step_Counter++){

	     //step1 -------->BLUE PIN IS LOW
	 DIO_u8_Set_Pin_Value (STEPPER_MOTOR_BLUE_PORT,STEPPER_MOTOR_BLUE_PIN ,DIO_u8_HIGH );
	 DIO_u8_Set_Pin_Value (STEPPER_MOTOR_PINK_PORT,STEPPER_MOTOR_PINK_PIN ,DIO_u8_HIGH );
	 DIO_u8_Set_Pin_Value (STEPPER_MOTOR_YELLOW_PORT,STEPPER_MOTOR_YELLOW_PIN ,DIO_u8_HIGH );
	 DIO_u8_Set_Pin_Value (STEPPER_MOTOR_ORANGE_PORT,STEPPER_MOTOR_ORANGE_PIN ,DIO_u8_LOW );
		_delay_ms(periodic_time_delay);
	    //step1 -------->PINK PIN IS LOW
	DIO_u8_Set_Pin_Value (STEPPER_MOTOR_BLUE_PORT,STEPPER_MOTOR_BLUE_PIN ,DIO_u8_HIGH );
	DIO_u8_Set_Pin_Value (STEPPER_MOTOR_PINK_PORT,STEPPER_MOTOR_PINK_PIN ,DIO_u8_HIGH );
	DIO_u8_Set_Pin_Value (STEPPER_MOTOR_YELLOW_PORT,STEPPER_MOTOR_YELLOW_PIN ,DIO_u8_LOW );
	DIO_u8_Set_Pin_Value (STEPPER_MOTOR_ORANGE_PORT,STEPPER_MOTOR_ORANGE_PIN ,DIO_u8_HIGH );
		_delay_ms(periodic_time_delay);
		//step1 -------->YELLOW PIN IS LOW
	DIO_u8_Set_Pin_Value (STEPPER_MOTOR_BLUE_PORT,STEPPER_MOTOR_BLUE_PIN ,DIO_u8_HIGH );
	DIO_u8_Set_Pin_Value (STEPPER_MOTOR_PINK_PORT,STEPPER_MOTOR_PINK_PIN ,DIO_u8_LOW );
	DIO_u8_Set_Pin_Value (STEPPER_MOTOR_YELLOW_PORT,STEPPER_MOTOR_YELLOW_PIN ,DIO_u8_HIGH );
	DIO_u8_Set_Pin_Value (STEPPER_MOTOR_ORANGE_PORT,STEPPER_MOTOR_ORANGE_PIN ,DIO_u8_HIGH );
		_delay_ms(periodic_time_delay);
		//step1 -------->ORANGE PIN IS LOW
	DIO_u8_Set_Pin_Value (STEPPER_MOTOR_BLUE_PORT,STEPPER_MOTOR_BLUE_PIN ,DIO_u8_LOW );
	DIO_u8_Set_Pin_Value (STEPPER_MOTOR_PINK_PORT,STEPPER_MOTOR_PINK_PIN ,DIO_u8_HIGH );
	DIO_u8_Set_Pin_Value (STEPPER_MOTOR_YELLOW_PORT,STEPPER_MOTOR_YELLOW_PIN ,DIO_u8_HIGH );
	DIO_u8_Set_Pin_Value (STEPPER_MOTOR_ORANGE_PORT,STEPPER_MOTOR_ORANGE_PIN ,DIO_u8_HIGH );
		_delay_ms(periodic_time_delay);
	}
}
	return Local_enu_Erorr_State;
}
