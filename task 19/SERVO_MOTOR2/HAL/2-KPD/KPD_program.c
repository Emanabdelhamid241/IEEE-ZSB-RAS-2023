/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   9 july 2023    ********************/
/******************   SW :         KPD       ********************/
/******************  version :     1.0       ********************/
//from libraries layer
#include"../../libraries/types.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/math.h"

//MCAL layer (DIO)
#include"../../MCAL/1-DIO/DIO_interface.h"

//HAL layer
#include "KPD_config.h"
#include "KPD_private.h"

//#define F_CPU 8000000UL
#include <util/delay.h>


     const u8 KPD_Au8_Keys[4][4]   = KPD_Keys ;
	 const u8 KPD_Au8_Rows_Pins[4] ={KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};
	 const u8 KPD_Au8_Cols_Pins[4] ={KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};

	ES_t KPD_enum_Init(void)
	{
		ES_t Local_enu_Erorr_State = ES_OK;
//		DIO_u8_Set_Pin_Value(2 , 0 , 0);

		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_R1_PIN , DIO_u8_INTIAL_OUTPUT);
		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_R2_PIN , DIO_u8_INTIAL_OUTPUT);
		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_R3_PIN , DIO_u8_INTIAL_OUTPUT);
		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_R4_PIN , DIO_u8_INTIAL_OUTPUT);

		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_C1_PIN , DIO_u8_INTIAL_INPUT);
		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_C2_PIN , DIO_u8_INTIAL_INPUT);
		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_C3_PIN , DIO_u8_INTIAL_INPUT);
		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_C4_PIN , DIO_u8_INTIAL_INPUT);

		DIO_u8_Set_Pin_Value(KPD_u8_PORT , KPD_u8_R1_PIN , DIO_u8_INTIAL_HIGH);
		DIO_u8_Set_Pin_Value(KPD_u8_PORT , KPD_u8_R2_PIN , DIO_u8_INTIAL_HIGH);
		DIO_u8_Set_Pin_Value(KPD_u8_PORT , KPD_u8_R3_PIN , DIO_u8_INTIAL_HIGH);
		DIO_u8_Set_Pin_Value(KPD_u8_PORT , KPD_u8_R4_PIN , DIO_u8_INTIAL_HIGH);

		DIO_u8_Set_Pin_Value(KPD_u8_PORT , KPD_u8_C1_PIN , DIO_u8_INTIAL_PULL_UP);
		DIO_u8_Set_Pin_Value(KPD_u8_PORT , KPD_u8_C2_PIN , DIO_u8_INTIAL_PULL_UP);
		DIO_u8_Set_Pin_Value(KPD_u8_PORT , KPD_u8_C3_PIN , DIO_u8_INTIAL_PULL_UP);
		DIO_u8_Set_Pin_Value(KPD_u8_PORT , KPD_u8_C4_PIN , DIO_u8_INTIAL_PULL_UP);

		return Local_enu_Erorr_State;
	}
ES_t KPD_enum_Get_Key_State(u8 *Copy_pu8_Returned_Key){

 ES_t Local_enu_Erorr_State = ES_OK ;
 u8 Local_u8_Rows_Counter, Local_u8_Cols_Counter, Local_u8_Key_Value=0, Local_u8_Flag =DIO_u8_LOW;
 if ( Copy_pu8_Returned_Key != NULL ){
		*Copy_pu8_Returned_Key = KPD_u8_Keys_NO_Pressed;



/* activate each row by for loop */
	 for (Local_u8_Rows_Counter=KPD_u8_R1; Local_u8_Rows_Counter<=KPD_u8_R4; Local_u8_Rows_Counter++){
		 DIO_u8_Set_Pin_Value (KPD_u8_PORT, KPD_Au8_Rows_Pins[Local_u8_Rows_Counter],  DIO_u8_LOW );
//			DIO_u8_Set_Pin_Value(2 , 0 , 1);

		 /*check which input pin has zero		  */
		 for (Local_u8_Cols_Counter=KPD_u8_C1; Local_u8_Cols_Counter<=KPD_u8_C4; Local_u8_Cols_Counter++){
			 DIO_u8_Get_Pin_Value  ( KPD_u8_PORT, KPD_Au8_Cols_Pins[Local_u8_Cols_Counter], &Local_u8_Key_Value );
//	 			DIO_u8_Set_Pin_Value(2 , 0 , 1);

//           if switch is pressed
			 if (Local_u8_Key_Value == DIO_u8_LOW)
            {

          /*Debouncing */
         _delay_ms(20);
		 DIO_u8_Get_Pin_Value  ( KPD_u8_PORT, KPD_Au8_Cols_Pins[Local_u8_Cols_Counter], &Local_u8_Key_Value );
//			DIO_u8_Set_Pin_Value(2 , 1 , 1);

         /*check if the pin is still pressed */
		 while (Local_u8_Key_Value == DIO_u8_LOW){
			 DIO_u8_Get_Pin_Value  ( KPD_u8_PORT,  KPD_Au8_Cols_Pins[Local_u8_Cols_Counter], &Local_u8_Key_Value );
//			 Local_enu_Erorr_State= ES_OK;
		 }
      *Copy_pu8_Returned_Key = KPD_Au8_Keys[Local_u8_Rows_Counter][Local_u8_Cols_Counter];
       Local_u8_Flag =DIO_u8_HIGH;
        break;
            }
		 }
/*deactivate rows */
		 DIO_u8_Set_Pin_Value(KPD_u8_PORT,KPD_Au8_Rows_Pins[Local_u8_Rows_Counter],DIO_u8_HIGH);
		 			if(Local_u8_Flag == DIO_u8_HIGH)
		 				break;
	 }
 }
 else
     {
	 Local_enu_Erorr_State = ES_NOK;
     }
 return Local_enu_Erorr_State;
}
