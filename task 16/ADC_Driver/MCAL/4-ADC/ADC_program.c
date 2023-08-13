/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   4 August 2023     ********************/
/******************   SW :         ADC        ********************/
/******************  version :     1.0       ********************/

//libraries layer
#include"../../libraries/math.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/types.h"

//MCAL
#include "ADC_config.h"
#include "ADC_private.h"


/*Global pointer to function*/
static void (*ADC_pf_ADC_notification)(u16) = NULL;
/*ADC busy flag*/
static u8 ADC_u8_busy_flag=0;

ES_t  ADC_enum_ADC_INIT(void){
	 ES_t Local_enu_Erorr_State = ES_OK ;

	 /* 1- select Vref = AVCC*/
    CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS1_BIT7);
    SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_REFS0_BIT6);

	 /* 2-Right Adjust */
    CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADLAR_BIT5);

	 /* 3-Enable AutoTrigger */
    CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADATE_BIT5);

	 /* 4-Select CLK/64  */
    SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADPS2_BIT2);
    SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADPS1_BIT1);
    CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADPS0_BIT0);


	 /* 5-Enable ADC */
    SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADEN_BIT7);

	 return Local_enu_Erorr_State;

}

ES_t  ADC_enum_GET_DIGITAL_VALUE_Synch_Non_Blocking(u8 Copy_u8_ADC_Channel_NB,u16 * Copy_pu16_ADC_Digital_Value){
	 ES_t Local_enu_Erorr_State = ES_OK ;
	 u32 Local_u32_ADC_TiomeOut_Counter = ADC_u8_initial_counter ;

     if((Copy_u8_ADC_Channel_NB < ADC_u8_Max_Channels_NB) && (Copy_pu16_ADC_Digital_Value != NULL) && (ADC_u8_busy_flag ==0)){
    	 /*set ADC flag is busy*/
    	 	 	ADC_u8_busy_flag=1;
    	 /*1- clear MUX4....0*/
    	 ADC_u8_ADMUX_REG &= CLEAR_MUX_BITS;

    	 /*2- Select Channel NB*/
    	 ADC_u8_ADMUX_REG |= Copy_u8_ADC_Channel_NB;

    	 /*3- Start Conversion*/
    	    SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADSC_BIT6);

    	    /*4- wait flag=1*/
    	    while ((!GET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIF_BIT4))&&(Local_u32_ADC_TiomeOut_Counter<ADC_u32_TIME_OUT_MAX_VALUE))
    	    {
    	    	Local_u32_ADC_TiomeOut_Counter++;
    	    }
    	    if(GET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIF_BIT4)!=0)/*Local_u32_ADC_TiomeOut_Counter<ADC_u32_TIME_OUT_MAX_VALUE*/
    	    {

    	    /*5-Clear flag*/
    	    SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIF_BIT4);
    	    /*clear ADC busy flag*/
    	      ADC_u8_busy_flag=0;
    	    /*6-Read DIGITAL Value*/
    	    *Copy_pu16_ADC_Digital_Value = ADC_u16_ADC_REG ;
    	    }
    	    else{
    	    	 Local_enu_Erorr_State= ES_NOK;

    	    }

     }
     else{
    	 Local_enu_Erorr_State= ES_NOK;
     }
	 return Local_enu_Erorr_State;
}

ES_t  ADC_enum_GET_DIGITAL_VALUE_ASynch(u8 Copy_u8_ADC_Channel_NB,void(*Copy_pf_ADC_notifction)(u16))
{
		 ES_t Local_enu_Erorr_State = ES_OK ;
     if((Copy_u8_ADC_Channel_NB < ADC_u8_Max_Channels_NB) && (Copy_pf_ADC_notifction != NULL) && (ADC_u8_busy_flag ==0)){
    	 /*set ADC flag is busy*/
    	 	ADC_u8_busy_flag=1;

    	 /*Update  pointer to function*/
    	 ADC_pf_ADC_notification=Copy_pf_ADC_notifction;
    	 /*Enable ADC interrupt*/
   	    SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIE_BIT3);
       /*1- clear MUX4....0*/
   	  ADC_u8_ADMUX_REG &= CLEAR_MUX_BITS;
       	 /*2- Select Channel NB*/
   	   	 ADC_u8_ADMUX_REG |= Copy_u8_ADC_Channel_NB;
       	 /*3- Start Conversion*/
         SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADSC_BIT6);


     }
     else{
        	 Local_enu_Erorr_State= ES_NOK;
         }

	 return Local_enu_Erorr_State;

}
ES_t  ADC_enum_GET_ADC_REG_VALUE(u16 * Copy_pu16_ADC_Value)
{
	 ES_t Local_enu_Erorr_State = ES_OK ;
	 if(Copy_pu16_ADC_Value!= NULL)
	 {
		 /*read ADC REG*/
		 *Copy_pu16_ADC_Value= ADC_u16_ADC_REG ;

	 }
	 else{
    	 Local_enu_Erorr_State= ES_NOK;
     }

	 return Local_enu_Erorr_State;

}
//prototype FOR ISR
void __vector_16(void)        __attribute__((signal));
void __vector_16(void)
{
	if(ADC_pf_ADC_notification!= NULL)
	{
		/*clear ADC busy flag */
		 ADC_u8_busy_flag=0;
		/*clear PIE of ADC */
   	    CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIE_BIT3);
   	   	/*calling notification function*/
   		ADC_pf_ADC_notification(ADC_u16_ADC_REG);
	}

	}
