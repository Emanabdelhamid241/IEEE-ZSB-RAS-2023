/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   7 August 2023     ********************/
/******************   SW :         TIMERS        ********************/
/******************  version :     1.0       ********************/

//libraries layer
#include"../../libraries/math.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/types.h"

//MCAL
#include "TIMERS_config.h"
#include "TIMERS_private.h"


/*Global pointer to function to TIMER0 OVF and CTC*/
static void (*TIMERS_pf_TIMER0[2])(void) = {NULL,NULL};

ES_t TIMERS_enum_TIMER0_INIT(u8 Copy_u8_MODE)
{
	 ES_t Local_enu_Erorr_State = ES_OK ;

#if  Copy_u8_MODE == NORMAL_MODE
	 /*Select normal mode*/
	 CLR_BIT(TIMERS_u8_TCCR0_REG,timers_WGM01_BIT3);
	 CLR_BIT(TIMERS_u8_TCCR0_REG,timers_WGM00_BIT6);

	 /*Enable OVF Interrupt*/
	SET_BIT(TIMERS_u8_TIMSK_REG,timers_TOIE0_BIT0);

	/*set reload value*/
	TIMERS_u8_TCNT0_REG=TIMERO_u8_preload_value;

#elif Copy_u8_MODE == CTC_MODE
	/*Select CTC mode*/
		 SET_BIT(TIMERS_u8_TCCR0_REG,timers_WGM01_BIT3);
		 CLR_BIT(TIMERS_u8_TCCR0_REG,timers_WGM00_BIT6);

		 /*Enable CTC Interrupt*/
		SET_BIT(TIMERS_u8_TIMSK_REG,timers_OCIE0_BIT1);

		/*set compare match unit register*/
		TIMERS_u8_OCR0_REG=COMPARE_MATCH_VALUE;

#elif Copy_u8_MODE == FAST_PWM_NON_INVERTING_MODE
	/*Select FAST PWM mode*/
		 SET_BIT(TIMERS_u8_TCCR0_REG,timers_WGM01_BIT3);
		 SET_BIT(TIMERS_u8_TCCR0_REG,timers_WGM00_BIT6);

		 /*Select HW Action on oc0 pin to non interting*/
		SET_BIT(TIMERS_u8_TCCR0_REG,timers_COM01_BIT5);
		CLR_BIT(TIMERS_u8_TCCR0_REG,timers_COM00_BIT4);

#elif Copy_u8_MODE == PHASE_CORRECT_PWM_NON_INVERTING_MODE
	/*Select FAST PWM mode*/
		 CLR_BIT(TIMERS_u8_TCCR0_REG,timers_WGM01_BIT3);
		 SET_BIT(TIMERS_u8_TCCR0_REG,timers_WGM00_BIT6);

		 /*Select HW Action on oc0 pin to non interting*/
		SET_BIT(TIMERS_u8_TCCR0_REG,timers_COM01_BIT5);
		CLR_BIT(TIMERS_u8_TCCR0_REG,timers_COM00_BIT4);


#endif
/*set prescaler value CLK/8 */
CLR_BIT(TIMERS_u8_TCCR0_REG,timers_CS00_BIT0);
SET_BIT(TIMERS_u8_TCCR0_REG,timers_CS01_BIT1);
CLR_BIT(TIMERS_u8_TCCR0_REG,timers_CS02_BIT2);


return Local_enu_Erorr_State;
}
ES_t TIMERS_enum_TIMER1_INIT(u8 Copy_u8_MODE)
{
	ES_t Local_enu_Erorr_State = ES_OK ;
#if  Copy_u8_MODE == FAST_PWM_NON_INVERTING_MODE
	/*select timer1 mode --> 14(fast PWM) (ICR1=Top Value)*/
	CLR_BIT(TIMERS_u8_TCCR1A_REG,timers_WGM10_BIT0);
	SET_BIT(TIMERS_u8_TCCR1A_REG,timers_WGM11_BIT1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,timers_WGM12_BIT3);
	SET_BIT(TIMERS_u8_TCCR1B_REG,timers_WGM13_BIT4);

	/*SELECT HM Action on OC1A Pin --> non inverting*/
	CLR_BIT(TIMERS_u8_TCCR1A_REG,timers_COM1A0_BIT6);
	SET_BIT(TIMERS_u8_TCCR1A_REG,timers_COM1A1_BIT7);

	/*SET TOP Value IN OCI1 */
	TIMERS_u16_ICR1_REG = TIMER1_u16_TOP_Value_IN_OCI1;
#endif
	/*Angle of servo motor = 0 */
//	TIMERS_u16_OCR1A_REG = TIMER1_u16_angle_zero;

	/*Angle of servo motor = 180 */
//		TIMERS_u16_OCR1A_REG = TIMER1_u16_angle_180 ;


	/*set prescaler value CLK/8 */
	CLR_BIT(TIMERS_u8_TCCR1B_REG,timers_CS10_BIT0);
	SET_BIT(TIMERS_u8_TCCR1B_REG,timers_CS11_BIT1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,timers_CS12_BIT2);

	return Local_enu_Erorr_State;

}
ES_t TIMERS_enum_TIMER0_SET_CALL_BACK(void(*Copy_pf_TIMER0)(void),u8 Copy_u8_MODE){
	ES_t Local_enu_Erorr_State = ES_OK ;
	if(Copy_pf_TIMER0 !=NULL)
	{

		TIMERS_pf_TIMER0[Copy_u8_MODE]=Copy_pf_TIMER0;

	}
	else
	{
		Local_enu_Erorr_State=ES_NOK;
	}
	return Local_enu_Erorr_State;
}

ES_t TIMERS_enum_TIMER0_SET_COMPARE_MATCH_VALUE(u8 Copy_u8_OCR0_Value)
{
	ES_t Local_enu_Erorr_State= ES_OK;
    TIMERS_u8_OCR0_REG = Copy_u8_OCR0_Value;

	return Local_enu_Erorr_State;

}
ES_t TIMERS_enum_TIMER0_SET_PRESCAlER_VALUE(u8 Copy_u8_TCNT0_Value){
			ES_t Local_enu_Erorr_State= ES_OK;
			TIMERS_u8_TCNT0_REG = Copy_u8_TCNT0_Value;

					return Local_enu_Erorr_State;
		}
u8 TIMERS_enum_TIMER0_REED_TIMER_VALUE(void)
		{
return TIMERS_u8_TCNT0_REG;
		}

ES_t TIMERS_enum_TIMER1_SET_COMPARE_MATCH_VALUE_A(u16 Copy_u16_ICR1_Value)
{
	ES_t Local_enu_Erorr_State= ES_OK;
	TIMERS_u16_ICR1_REG = Copy_u16_ICR1_Value;

		return Local_enu_Erorr_State;
}
		ES_t TIMERS_enum_TIMER1_SET_PRESCAlER_VALUE(u16 Copy_u16_TCNT1_Value){
			ES_t Local_enu_Erorr_State= ES_OK;
				TIMERS_u16_TCNT1_REG = Copy_u16_TCNT1_Value;

					return Local_enu_Erorr_State;
		}

		u16 TIMERS_enum_TIMER1_REED_TIMER_VALUE(void)
		{
return TIMERS_u16_TCNT1_REG;
		}



/* prototype FOR ISR of TIMER0 OVF */
void __vector_11(void)        __attribute__((signal));
void __vector_11(void)
{
static u16 Local_TIMERS_u16_Counter_OVF =TIMERS_u8_intial_counter_value;
Local_TIMERS_u16_Counter_OVF++;
if(Local_TIMERS_u16_Counter_OVF==TIMER0_u8_Counter_of_OVF)
{
	/*update preload value*/
	TIMERS_u8_TCNT0_REG=TIMERO_u8_preload_value;
	/*Clear OVF counter*/
	Local_TIMERS_u16_Counter_OVF=TIMERS_u8_intial_counter_value;
	/*Call APP Function*/
	if(TIMERS_pf_TIMER0[NORMAL_MODE] != NULL)
	{
		TIMERS_pf_TIMER0[NORMAL_MODE]();
	}

}
}
/* prototype FOR ISR of CTC MODE */
void __vector_10(void)        __attribute__((signal));
void __vector_10(void)
{
static u16 Local_TIMERS_u16_Counter_OVF_CTC =TIMERS_u8_intial_counter_value;
Local_TIMERS_u16_Counter_OVF_CTC++;
if(Local_TIMERS_u16_Counter_OVF_CTC==TIMER0_u8_Counter_of_OVF_CTC)
{

	/*Clear OVF counter*/
	Local_TIMERS_u16_Counter_OVF_CTC=TIMERS_u8_intial_counter_value;
	/*Call APP Function*/
	if(TIMERS_pf_TIMER0[CTC_MODE] != NULL)
	{
		TIMERS_pf_TIMER0[CTC_MODE]();
	}

}
}
