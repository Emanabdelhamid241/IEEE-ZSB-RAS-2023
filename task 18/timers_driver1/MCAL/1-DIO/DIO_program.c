// libraries layer
#include "../../libraries/math.h"
#include "../../libraries/types.h"
#include"../../libraries/Error_State.h"


//MCAL Layer
#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"

void DIO_voidInit(void){
	DIO_u8_DDRA_REG = CONC(DIO_U8_PA7_INTIAL_DIRECTION, DIO_U8_PA6_INTIAL_DIRECTION, DIO_U8_PA5_INTIAL_DIRECTION, DIO_U8_PA4_INTIAL_DIRECTION,
		                   DIO_U8_PA3_INTIAL_DIRECTION, DIO_U8_PA2_INTIAL_DIRECTION, DIO_U8_PA1_INTIAL_DIRECTION, DIO_U8_PA0_INTIAL_DIRECTION);
		                 			
	DIO_u8_DDRB_REG = CONC(DIO_U8_PB7_INTIAL_DIRECTION, DIO_U8_PB6_INTIAL_DIRECTION, DIO_U8_PB5_INTIAL_DIRECTION, DIO_U8_PB4_INTIAL_DIRECTION,
				           DIO_U8_PB3_INTIAL_DIRECTION, DIO_U8_PB2_INTIAL_DIRECTION, DIO_U8_PB1_INTIAL_DIRECTION, DIO_U8_PB0_INTIAL_DIRECTION);
					                                                                                                                      
	DIO_u8_DDRC_REG = CONC(DIO_U8_PC7_INTIAL_DIRECTION, DIO_U8_PC6_INTIAL_DIRECTION, DIO_U8_PC5_INTIAL_DIRECTION, DIO_U8_PC4_INTIAL_DIRECTION,
		                   DIO_U8_PC3_INTIAL_DIRECTION, DIO_U8_PC2_INTIAL_DIRECTION, DIO_U8_PC1_INTIAL_DIRECTION, DIO_U8_PC0_INTIAL_DIRECTION);

	DIO_u8_DDRD_REG = CONC(DIO_U8_PD7_INTIAL_DIRECTION, DIO_U8_PD6_INTIAL_DIRECTION, DIO_U8_PD5_INTIAL_DIRECTION, DIO_U8_PD4_INTIAL_DIRECTION,
				           DIO_U8_PD3_INTIAL_DIRECTION, DIO_U8_PD2_INTIAL_DIRECTION, DIO_U8_PD1_INTIAL_DIRECTION, DIO_U8_PD0_INTIAL_DIRECTION);

	DIO_u8_PORTA_REG = CONC(DIO_U8_PA7_INTIAL_VALUE, DIO_U8_PA6_INTIAL_VALUE, DIO_U8_PA5_INTIAL_VALUE, DIO_U8_PA4_INTIAL_VALUE,
						    DIO_U8_PA3_INTIAL_VALUE, DIO_U8_PA2_INTIAL_VALUE, DIO_U8_PA1_INTIAL_VALUE, DIO_U8_PA0_INTIAL_VALUE);

    DIO_u8_PORTB_REG = CONC(DIO_U8_PB7_INTIAL_VALUE, DIO_U8_PB6_INTIAL_VALUE, DIO_U8_PB5_INTIAL_VALUE, DIO_U8_PB4_INTIAL_VALUE,
						   	DIO_U8_PB3_INTIAL_VALUE, DIO_U8_PB2_INTIAL_VALUE, DIO_U8_PB1_INTIAL_VALUE, DIO_U8_PB0_INTIAL_VALUE);
												 
    DIO_u8_PORTC_REG = CONC(DIO_U8_PC7_INTIAL_VALUE, DIO_U8_PC6_INTIAL_VALUE, DIO_U8_PC5_INTIAL_VALUE, DIO_U8_PC4_INTIAL_VALUE,
					        DIO_U8_PC3_INTIAL_VALUE, DIO_U8_PC2_INTIAL_VALUE, DIO_U8_PC1_INTIAL_VALUE, DIO_U8_PC0_INTIAL_VALUE);
																		   
    DIO_u8_PORTD_REG = CONC(DIO_U8_PD7_INTIAL_VALUE, DIO_U8_PD6_INTIAL_VALUE, DIO_U8_PD5_INTIAL_VALUE, DIO_U8_PD4_INTIAL_VALUE,
						    DIO_U8_PD3_INTIAL_VALUE, DIO_U8_PD2_INTIAL_VALUE, DIO_U8_PD1_INTIAL_VALUE, DIO_U8_PD0_INTIAL_VALUE);
    }

u8 DIO_u8_Set_Pin_Direction  (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Pin_Direction ){
	u8 Local_u8_Erorr_State = ES_OK ;
	if((Copy_u8_Port_ID <= DIO_u8_PORTD ) && (Copy_u8_Pin_ID <= DIO_u8_PIN7) && ((Copy_u8_Pin_Direction == DIO_u8_INTIAL_INPUT)||(Copy_u8_Pin_Direction == DIO_u8_INTIAL_OUTPUT)))
	{
        switch (Copy_u8_Port_ID)
        {
               case DIO_u8_PORTA:
            	   switch (Copy_u8_Pin_Direction)
            	   {
                    	   case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRA_REG,Copy_u8_Pin_ID);break;
                    	   case DIO_u8_INPUT:CLR_BIT(DIO_u8_DDRA_REG,Copy_u8_Pin_ID);break;
			           	     default :Local_u8_Erorr_State = ES_NOK ;

            	   }
                  break;
               case DIO_u8_PORTB:
             	   switch (Copy_u8_Pin_Direction)
             	   {
                     	   case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRB_REG,Copy_u8_Pin_ID);break;
                     	   case DIO_u8_INPUT:CLR_BIT(DIO_u8_DDRB_REG,Copy_u8_Pin_ID);break;
			           	     default :Local_u8_Erorr_State = ES_NOK ;

             	   }
                   break;
               case DIO_u8_PORTC:
                   switch (Copy_u8_Pin_Direction)
                 	   {
                         	   case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRC_REG,Copy_u8_Pin_ID);break;
                         	   case DIO_u8_INPUT:CLR_BIT(DIO_u8_DDRC_REG,Copy_u8_Pin_ID);break;
  			           	     default :Local_u8_Erorr_State = ES_NOK ;

                 	   }
                       break;

               case DIO_u8_PORTD:
                    switch (Copy_u8_Pin_Direction)
                     	   {
                             	   case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRD_REG,Copy_u8_Pin_ID);break;
                             	   case DIO_u8_INPUT:CLR_BIT (DIO_u8_DDRD_REG,Copy_u8_Pin_ID);break;
      			           	     default :Local_u8_Erorr_State = ES_NOK ;

                     	   }
                           break;
        }
	}
	else {
		Local_u8_Erorr_State = ES_NOK ;
	}
	return Local_u8_Erorr_State ;
}

u8 DIO_u8_Set_Pin_Value  (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Pin_Value ){
	u8 Local_u8_Erorr_State = ES_OK ;
	if((Copy_u8_Port_ID <= DIO_u8_PORTD ) && (Copy_u8_Pin_ID <= DIO_u8_PIN7) && ((Copy_u8_Pin_Value == DIO_u8_INPUT)||(Copy_u8_Pin_Value == DIO_u8_OUTPUT)))
	{
		switch (Copy_u8_Port_ID)
		{
		case DIO_u8_PORTA :
			switch (Copy_u8_Pin_Value)
			{
			     case DIO_u8_HIGH :SET_BIT(DIO_u8_PORTA_REG,Copy_u8_Pin_ID);break;
           	     case DIO_u8_LOW:CLR_BIT (DIO_u8_PORTA_REG,Copy_u8_Pin_ID);break;
           	     default :Local_u8_Erorr_State = ES_NOK ;

			}
			break;
		case DIO_u8_PORTB :
			switch (Copy_u8_Pin_Value)
				{
				     case DIO_u8_HIGH :SET_BIT(DIO_u8_PORTB_REG,Copy_u8_Pin_ID);break;
	           	     case DIO_u8_LOW:CLR_BIT (DIO_u8_PORTB_REG,Copy_u8_Pin_ID);break;
	           	     default :Local_u8_Erorr_State = ES_NOK ;

				}
	     	break;
		case DIO_u8_PORTC :
			switch (Copy_u8_Pin_Value)
					{
					     case DIO_u8_HIGH :SET_BIT(DIO_u8_PORTC_REG,Copy_u8_Pin_ID);break;
		           	     case DIO_u8_LOW:CLR_BIT (DIO_u8_PORTC_REG,Copy_u8_Pin_ID);break;
		           	     default :Local_u8_Erorr_State = ES_NOK ;

					}
		   break;
		case DIO_u8_PORTD :
			switch (Copy_u8_Pin_Value)
						{
						     case DIO_u8_HIGH :SET_BIT(DIO_u8_PORTD_REG,Copy_u8_Pin_ID);break;
			           	     case DIO_u8_LOW:CLR_BIT (DIO_u8_PORTD_REG,Copy_u8_Pin_ID);break;
			           	     default :Local_u8_Erorr_State = ES_NOK ;
						}
			break;
		}
	}
	else {
			Local_u8_Erorr_State = ES_NOK ;
		}
		return Local_u8_Erorr_State ;
}

u8 DIO_u8_Get_Pin_Value      (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 *Copy_u8_Returned_Pin_Value ){
	u8 Local_u8_Erorr_State = ES_OK ;
    u8 Local_u8_Pin_Value ;
	if((Copy_u8_Port_ID <= DIO_u8_PORTD ) && (Copy_u8_Pin_ID <= DIO_u8_PIN7) && (Copy_u8_Returned_Pin_Value != NULL)){
		switch (Copy_u8_Port_ID)
		{
		     case DIO_u8_PORTA :
		      Local_u8_Pin_Value = GET_BIT (DIO_u8_PINA_REG, Copy_u8_Pin_ID) ;

		    	 if (Local_u8_Pin_Value == DIO_u8_LOW){
		    		 *Copy_u8_Returned_Pin_Value = DIO_u8_LOW ;
		    	 }
		    	 else
		    	 {
		    		 *Copy_u8_Returned_Pin_Value = DIO_u8_HIGH ;
		    	 }
		     break;
		     case DIO_u8_PORTB :
		    	 Local_u8_Pin_Value = GET_BIT(DIO_u8_PINB_REG,Copy_u8_Pin_ID ) ;
		    		    	 if (Local_u8_Pin_Value == DIO_u8_LOW){
		    		    		 * Copy_u8_Returned_Pin_Value = DIO_u8_LOW ;
		    		    	 }
		    		    	 else
		    		    	 {
		    		    		 * Copy_u8_Returned_Pin_Value = DIO_u8_HIGH ;
		    		    	 }
		    		     break;
		     case DIO_u8_PORTC :
		    	 Local_u8_Pin_Value = GET_BIT(DIO_u8_PINC_REG,Copy_u8_Pin_ID ) ;
		    		    	 if (Local_u8_Pin_Value ==DIO_u8_LOW){
		    		    		 * Copy_u8_Returned_Pin_Value = DIO_u8_LOW ;
		    		    	 }
		    		    	 else
		    		    	 {
		    		    		 * Copy_u8_Returned_Pin_Value = DIO_u8_HIGH ;
		    		    	 }
		    		     break;
		     case DIO_u8_PORTD :
		    	 Local_u8_Pin_Value = GET_BIT(DIO_u8_PIND_REG,Copy_u8_Pin_ID ) ;
		    	 if (Local_u8_Pin_Value ==DIO_u8_LOW){
		    		 *Copy_u8_Returned_Pin_Value = DIO_u8_LOW ;
		    		    	 }
		    		    	 else
		    		    	 {
		    		    		 *Copy_u8_Returned_Pin_Value = DIO_u8_HIGH ;
		    		    	 }
		    		     break;
		}
	}
	else {
			Local_u8_Erorr_State = ES_NOK ;
		}
		return Local_u8_Erorr_State ;
}

u8 DIO_u8_Set_Port_Direction (u8 Copy_u8_Port_ID, u8 Copy_u8_Port_Direction ){
	u8 Local_u8_Erorr_State = ES_OK ;
	if((Copy_u8_Port_ID <= DIO_u8_PORTD ) && ((Copy_u8_Port_Direction == DIO_u8_INPUT)||(Copy_u8_Port_Direction == DIO_u8_OUTPUT)))
	{
		switch (Copy_u8_Port_ID)
		{
		case DIO_u8_PORTA :
			switch (Copy_u8_Port_Direction)
			{
			    case DIO_u8_OUTPUT : DIO_u8_PORTA_REG = 0xff;break;
			    case DIO_u8_INPUT : DIO_u8_PORTA_REG = 0x00;break;
			}
			break;
			case DIO_u8_PORTB :
				switch (Copy_u8_Port_Direction)
				{
				    case DIO_u8_OUTPUT : DIO_u8_PORTB_REG = 0xff;break;
				    case DIO_u8_INPUT : DIO_u8_PORTB_REG = 0x00;break;
				}
				break;
				case DIO_u8_PORTC :
					switch (Copy_u8_Port_Direction)
					{
					    case DIO_u8_OUTPUT : DIO_u8_PORTC_REG = 0xff;break;
					    case DIO_u8_INPUT : DIO_u8_PORTC_REG = 0x00;break;
					}
					break;
					case DIO_u8_PORTD :
						switch (Copy_u8_Port_Direction)
						{
						    case DIO_u8_OUTPUT : DIO_u8_PORTD_REG = 0xff;break;
						    case DIO_u8_INPUT : DIO_u8_PORTD_REG = 0x00;break;
						}
						break;
						default:Local_u8_Erorr_State = ES_NOK ;

		}
	}
	else {
				Local_u8_Erorr_State = ES_NOK ;
			}
			return Local_u8_Erorr_State ;

}

u8 DIO_u8_Set_Port_Value     (u8 Copy_u8_Port_ID, u8 Copy_u8_Port_Value ){
	u8 Local_u8_Erorr_State = ES_OK ;

			switch (Copy_u8_Port_ID)
			{
			case DIO_u8_PORTA:DIO_u8_PORTA_REG =Copy_u8_Port_Value; break;
			case DIO_u8_PORTB:DIO_u8_PORTB_REG =Copy_u8_Port_Value; break;
			case DIO_u8_PORTC:DIO_u8_PORTC_REG =Copy_u8_Port_Value; break;
			case DIO_u8_PORTD:DIO_u8_PORTD_REG =Copy_u8_Port_Value; break;
			default :Local_u8_Erorr_State = ES_NOK;
			}
			return Local_u8_Erorr_State ;

}

u8 DIO_u8_Get_Port_Value     (u8 Copy_u8_Port_ID, u8 * Copy_u8_Returned_Port_Value ){
	u8 Local_u8_Erorr_State = ES_OK ;
    if (Copy_u8_Returned_Port_Value != NULL){
		switch (Copy_u8_Port_ID)
		{
		case DIO_u8_PORTA :* Copy_u8_Returned_Port_Value =DIO_u8_PORTA_REG; break;
		case DIO_u8_PORTB :* Copy_u8_Returned_Port_Value =DIO_u8_PORTB_REG; break;
		case DIO_u8_PORTC :* Copy_u8_Returned_Port_Value =DIO_u8_PORTC_REG; break;
		case DIO_u8_PORTD :* Copy_u8_Returned_Port_Value =DIO_u8_PORTD_REG; break;
		default :Local_u8_Erorr_State = ES_NOK;
		}}
		else {
			Local_u8_Erorr_State = ES_NOK ;
		}
	return Local_u8_Erorr_State ;

}
