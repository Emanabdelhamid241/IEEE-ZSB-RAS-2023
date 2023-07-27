/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   27 july 2023     ********************/
/******************   SW :         EXTI      ********************/
/******************  version :     1.0       ********************/

//libraries layer
#include"../../libraries/math.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/types.h"

//MCAL
#include "EXTI_config.h"
#include "EXTI_private.h"


/*Global pointer to function*/
static void (*EXTI_Apf_EXTI[3])(void)={NULL,NULL,NULL};



/*function to enable */
ES_t  EXTI_enum_EXTI_Enable(u8 Copy_u8_EXTI_Index,u8 Copy_u8_Edge_Index){
		 ES_t Local_enu_Erorr_State = ES_OK ;
         switch(Copy_u8_EXTI_Index)
         {
         case EXTI_u8_INT0:
        	 switch(Copy_u8_Edge_Index)
			 {
        	 case EXTI_u8_RAISING_EDGE:
        		 SET_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT0_ISC01);
        		 SET_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT0_ISC00);
        		 /* Enable EXTI0 >>> PIC */
        		 	 SET_BIT(EXTI_u8_GICR_REG  ,EXTI0_u8_PIN6  );
        		 break;
        	 case EXTI_u8_FALLING_EDGE:
        	       SET_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT0_ISC01);
        	       CLR_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT0_ISC00);
        	       /* Enable EXTI0 >>> PIC */
        	         SET_BIT(EXTI_u8_GICR_REG  ,EXTI0_u8_PIN6  );
        	         		 break;
        	 case EXTI_u8_ANY_LOGICAL_CHANGE:
        	    	 CLR_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT0_ISC01);
            		 SET_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT0_ISC00);
            		 /* Enable EXTI0 >>> PIC */
            		 SET_BIT(EXTI_u8_GICR_REG  ,EXTI0_u8_PIN6  );
        	         		 break;
        	 case EXTI_u8_LOW_LEVEL:
       	        CLR_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT0_ISC01);
        		 CLR_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT0_ISC00);
        		 /* Enable EXTI0 >>> PIC */
        		    SET_BIT(EXTI_u8_GICR_REG  ,EXTI0_u8_PIN6  );
        	         		 break;
        	 default :Local_enu_Erorr_State = ES_NOK ;
			 }
        	 break;
        	 case EXTI_u8_INT1:
        	         	 switch(Copy_u8_Edge_Index)
        	 			 {
        	         	 case EXTI_u8_RAISING_EDGE:
        	         		 SET_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT1_ISC11);
        	         		 SET_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT1_ISC10);
        	         		 /* Enable EXTI1 >>> PIC */
        	         		 	 SET_BIT(EXTI_u8_GICR_REG  ,EXTI1_u8_PIN7  );
        	         		 break;
        	         	 case EXTI_u8_FALLING_EDGE:
        	         	       SET_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT1_ISC11);
        	         	       CLR_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT1_ISC10);
        	         	       /* Enable EXTI1 >>> PIC */
        	         	         SET_BIT(EXTI_u8_GICR_REG  ,EXTI1_u8_PIN7  );
        	         	         		 break;
        	         	 case EXTI_u8_ANY_LOGICAL_CHANGE:
        	         	    	 CLR_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT1_ISC11);
        	             		 SET_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT1_ISC10);
        	             		 /* Enable EXTI1 >>> PIC */
        	             		 SET_BIT(EXTI_u8_GICR_REG  ,EXTI1_u8_PIN7  );
        	         	         		 break;
        	         	 case EXTI_u8_LOW_LEVEL:
        	        	        CLR_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT1_ISC11);
        	         		 CLR_BIT(EXTI_u8_MCUCR_REG  ,EXTI_u8_INT1_ISC10);
        	         		 /* Enable EXTI1 >>> PIC */
        	         		    SET_BIT(EXTI_u8_GICR_REG  ,EXTI1_u8_PIN7  );
        	         	         		 break;
        	         	 default :Local_enu_Erorr_State = ES_NOK ;
        	 			 }
        	         	 break;
        	         	case EXTI_u8_INT2:
        	         	     switch(Copy_u8_Edge_Index)
           	 			 {
        	            	 case EXTI_u8_RAISING_EDGE:
        	         	        		 SET_BIT(EXTI_u8_MCUCSR_REG  ,EXTI_u8_INT2_ISC2);
        	         	         /* Enable EXTI2 >>> PIC */
        	         	     	 	 SET_BIT(EXTI_u8_GICR_REG  ,EXTI2_u8_PIN5  );
        	         	        	  break;
        	         	       case EXTI_u8_FALLING_EDGE:
        	   	         	       CLR_BIT(EXTI_u8_MCUCSR_REG  ,EXTI_u8_INT2_ISC2);
   	        	         	       /* Enable EXTI1 >>> PIC */
           	         	         SET_BIT(EXTI_u8_GICR_REG  ,EXTI2_u8_PIN5  );
               	         		 break;

        	         	   	   default :Local_enu_Erorr_State = ES_NOK ;
           	 			 }
                	         	 break;
         }
		 return Local_enu_Erorr_State;

}
ES_t  EXTI_enum_EXTI_Disable(u8 Copy_u8_EXTI_Index){
	 ES_t Local_enu_Erorr_State = ES_OK ;
     switch(Copy_u8_EXTI_Index){
     case EXTI_u8_INT0 :
    	 /* Disable EXTI0 >>> PIC */
    	   CLR_BIT(EXTI_u8_GICR_REG  ,EXTI0_u8_PIN6  );
    	 break;
     case EXTI_u8_INT1 :
       	 /* Disable EXTI1 >>> PIC */
          CLR_BIT(EXTI_u8_GICR_REG  ,EXTI1_u8_PIN7  );
       	 break;
     case EXTI_u8_INT2 :
         /* Disable EXTI2 >>> PIC */
         CLR_BIT(EXTI_u8_GICR_REG  ,EXTI2_u8_PIN5  );
      	 break;

     }
	 return Local_enu_Erorr_State;
}


ES_t EXTI_enum_Set_Call_Back( u8 Copy_u8_EXTI_Index,void(*Copy_u8_EXTI_pf)(void)){
	 ES_t Local_enu_Erorr_State = ES_OK ;
if((Copy_u8_EXTI_Index<=EXTI_u8_INT2)&& Copy_u8_EXTI_pf!=NULL){
	EXTI_Apf_EXTI [Copy_u8_EXTI_Index]  =  Copy_u8_EXTI_pf;
}
else{
	Local_enu_Erorr_State = ES_NOK ;
}
return Local_enu_Erorr_State;
}

//prototype FOR ISR EXTI0
void __vector_1(void)        __attribute__((signal));
void __vector_1(void) {
	if(EXTI_Apf_EXTI[EXTI_u8_INT0]!= NULL){
	EXTI_Apf_EXTI[EXTI_u8_INT0]();
	}
}
//prototype FOR ISR EXTI1
void __vector_2(void)        __attribute__((signal));
void __vector_2(void) {
	if(EXTI_Apf_EXTI[EXTI_u8_INT1]!= NULL){
		EXTI_Apf_EXTI[EXTI_u8_INT1]();
		}

}
//prototype FOR ISR EXTI2
void __vector_3(void)        __attribute__((signal));
void __vector_3(void) {
	if(EXTI_Apf_EXTI[EXTI_u8_INT2]!= NULL){
		EXTI_Apf_EXTI[EXTI_u8_INT2]();
		}

}

//ES_t  EXTI_enum_EXTI_Enable(void){
//	 ES_t Local_enu_Erorr_State = ES_OK ;
//
//	 /* 1-select edge source >>>> falling edge*/
//	 SET_BIT(EXTI_u8_MCUCR_REG  ,falling_ISC01  );
//	 CLR_BIT(EXTI_u8_MCUCR_REG  ,falling_ISC00);
//
//	 /*2-  Enable EXTI0 >>> PIC */
//	 SET_BIT(EXTI_u8_GICR_REG  ,DIO_u8_PIN6  );
//
//	return Local_enu_Erorr_State;
//}
