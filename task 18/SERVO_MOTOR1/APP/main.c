//libraries layer
#include"../libraries/math.h"
#include"../libraries/Error_State.h"
#include"../libraries/types.h"

//MCAL
#include "../MCAL/1-DIO/DIO_interface.h"
#include "../MCAL/3-GI/GI_interface.h"
#include "../MCAL/4-ADC/ADC_interface.h"
#include "../MCAL/5-TIMERS/TIMERS_interface.h"

#include <util/delay.h>

int main(){
	u16 local_u16_servo_motor_value=0;
	u16 local_u16__led_brightness_value=0 ;
	u16 local_u16_degital_value=0;

		        DIO_voidInit();
		        DIO_u8_Set_Pin_Direction(0,0,0);
		        DIO_u8_Set_Pin_Direction(1,3,1);


DIO_u8_Set_Pin_Direction(3,5,1);
//DIO_u8_Set_Pin_Direction(1,0,1);

		    TIMERS_enum_TIMER0_INIT();
		    TIMERS_enum_TIMER1_INIT();
	        ADC_enum_ADC_INIT();

	while(1){
//		ADC_enum_GET_DIGITAL_VALUE_Synch_Non_Blocking(ADC_u8_CHANNEL_0,&local_u16_degital_value);
//		local_u16_servo_motor_value=(u8)((local_u16_degital_value * 180UL)/1023) ;
	    TIMERS_enum_TIMER1_SET_Servo_Motor_Angle(60);

//        _delay_ms(100);
//		TIMERS_enum_TIMER1_SET_COMPARE_MATCH_VALUE_A(1999);

				TIMERS_enum_TIMER0_SET_COMPARE_MATCH_VALUE(local_u16__led_brightness_value);
	            local_u16__led_brightness_value++;
	            _delay_ms(100);
	}
	return 0;
}
