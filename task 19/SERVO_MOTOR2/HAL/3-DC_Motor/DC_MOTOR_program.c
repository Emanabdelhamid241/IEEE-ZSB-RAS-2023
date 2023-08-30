/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   22 july 2023    ********************/
/******************   SW : DC MOTOR       ********************/
/******************  version :     1.0       ********************/
//from libraries layer
#include"../../libraries/types.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/math.h"

//MCAL layer (DIO)
#include"../../MCAL/1-DIO/DIO_interface.h"

//HAL layer
#include "DC_MOTOR_config.h"
#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_private.h"

#include<util/delay.h>


ES_t DC_MOTOR_enum_INIT(){
	ES_t Local_enu_Erorr_State=ES_OK ;
	DIO_u8_Set_Pin_Direction(DC_MOTOR_EN1_PORT , DC_MOTOR_EN1_PIN , DIO_u8_INTIAL_OUTPUT);
	DIO_u8_Set_Pin_Direction(DC_MOTOR_INPUT1_PORT , DC_MOTOR_INPUT1_PIN , DIO_u8_INTIAL_OUTPUT);
	DIO_u8_Set_Pin_Direction(DC_MOTOR_INPUT2_PORT , DC_MOTOR_INPUT2_PIN , DIO_u8_INTIAL_OUTPUT);


	DIO_u8_Set_Pin_Value  (DC_MOTOR_EN1_PORT, DC_MOTOR_EN1_PIN,DIO_u8_INTIAL_LOW );
	DIO_u8_Set_Pin_Value  (DC_MOTOR_INPUT1_PORT, DC_MOTOR_INPUT1_PIN,DIO_u8_INTIAL_HIGH );
	DIO_u8_Set_Pin_Value  (DC_MOTOR_INPUT2_PORT, DC_MOTOR_INPUT2_PIN,DIO_u8_INTIAL_HIGH );

	return Local_enu_Erorr_State;

}

ES_t DC_MOTOR_enum_Start(u8 copy_u8_DC_MOTOT_Direction){
	ES_t Local_enu_Erorr_State=ES_OK ;
	DIO_u8_Set_Pin_Value  (DC_MOTOR_EN1_PORT, DC_MOTOR_EN1_PIN,DIO_u8_HIGH );


if(copy_u8_DC_MOTOT_Direction == CW){
	DIO_u8_Set_Pin_Value  (DC_MOTOR_INPUT1_PORT, DC_MOTOR_INPUT1_PIN,DIO_u8_HIGH );
	DIO_u8_Set_Pin_Value  (DC_MOTOR_INPUT2_PORT, DC_MOTOR_INPUT2_PIN,DIO_u8_LOW );

}
else if(copy_u8_DC_MOTOT_Direction==CCW){
	DIO_u8_Set_Pin_Value  (DC_MOTOR_INPUT1_PORT, DC_MOTOR_INPUT1_PIN,DIO_u8_LOW );
	DIO_u8_Set_Pin_Value  (DC_MOTOR_INPUT2_PORT, DC_MOTOR_INPUT2_PIN,DIO_u8_HIGH );
}
	else{
		Local_enu_Erorr_State= ES_NOK ;
}
return Local_enu_Erorr_State;
}
ES_t DC_MOTOR_enum_Stop(){
	ES_t Local_enu_Erorr_State=ES_OK;
//STOP DC MOTOR
	DIO_u8_Set_Pin_Value  (DC_MOTOR_EN1_PORT, DC_MOTOR_EN1_PIN,DIO_u8_LOW );
	DIO_u8_Set_Pin_Value  (DC_MOTOR_INPUT1_PORT, DC_MOTOR_INPUT1_PIN,DIO_u8_LOW );
		DIO_u8_Set_Pin_Value  (DC_MOTOR_INPUT2_PORT, DC_MOTOR_INPUT2_PIN,DIO_u8_LOW );

	Local_enu_Erorr_State=ES_NOK;

	return Local_enu_Erorr_State;

}

