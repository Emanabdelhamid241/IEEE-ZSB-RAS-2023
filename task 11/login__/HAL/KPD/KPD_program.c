/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   9 july 2023    ********************/
/******************   SW :         KPD       ********************/
/******************  version :     1.0       ********************/
//from libraries layer
#include"../../libraries/types.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/math.h"

//MCAL layer (DIO)
#include"../../MCAL/interface.h"

//HAL layer
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

#include<util/delay.h>


const u8 KPD_Au8_Keys[4][4] = KPD_Keys ;
	const u8 KPD_Au8_Rows_Pins[4] ={KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};
	const u8 KPD_Au8_Cols_Pins[4] ={KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};

	ES_t KPD_enum_Init(void)
	{
		ES_t Local_enu_Erorr_State = ES_NOK;

		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_R1_PIN , DIO_u8_INTIAL_INPUT);
		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_R2_PIN , DIO_u8_INTIAL_INPUT);
		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_R3_PIN , DIO_u8_INTIAL_INPUT);
		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_R4_PIN , DIO_u8_INTIAL_INPUT);

		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_C1_PIN , DIO_u8_INTIAL_OUTPUT);
		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_C2_PIN , DIO_u8_INTIAL_OUTPUT);
		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_C3_PIN , DIO_u8_INTIAL_OUTPUT);
		DIO_u8_Set_Pin_Direction(KPD_u8_PORT , KPD_u8_C4_PIN , DIO_u8_INTIAL_OUTPUT);

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

	*Copy_pu8_Returned_Key = KPD_u8_Keys_NO_Pressed;
 u8 Local_enu_Erorr_State = ES_NOK ;
 u8 Local_u8_Rows_Counter, Local_u8_Cols_Counter, Local_u8_Pin_Value, Local_u8_Flag =0;
 if (Copy_pu8_Returned_Key != NULL ){
/* activate each row by for loop */
	 for (Local_u8_Rows_Counter=0; Local_u8_Rows_Counter<=3; Local_u8_Rows_Counter++){
		 DIO_u8_Set_Pin_Value (KPD_u8_PORT, KPD_Au8_Rows_Pins[Local_u8_Rows_Counter],  DIO_u8_LOW );

		 /*check which input pin has zero		  */
		 for (Local_u8_Cols_Counter=0; Local_u8_Cols_Counter<=3; Local_u8_Cols_Counter++){
			 DIO_u8_Get_Pin_Value  ( KPD_u8_PORT, KPD_Au8_Cols_Pins[Local_u8_Cols_Counter], &Local_u8_Pin_Value );
//           if switch is pressed
			 if (Local_u8_Pin_Value == DIO_u8_LOW)
            {
          /*Debouncing */
         _delay_ms(20);
         /*check if the pin is still pressed */
		 while (Local_u8_Pin_Value == DIO_u8_LOW){
			 DIO_u8_Get_Pin_Value  ( KPD_u8_PORT,  KPD_Au8_Cols_Pins[Local_u8_Cols_Counter], &Local_u8_Pin_Value );
			 Local_enu_Erorr_State= ES_OK;
		 }
      *Copy_pu8_Returned_Key = KPD_Au8_Keys[Local_u8_Rows_Counter][Local_u8_Cols_Counter];
       Local_u8_Flag =1;
        break;
            }
		 }
/*deactivate rows */
		 DIO_u8_Set_Pin_Value(KPD_u8_PORT,KPD_Au8_Rows_Pins[Local_u8_Rows_Counter],DIO_u8_HIGH);
		 			if(Local_u8_Flag == 1)
		 				break;
	 }
 }
 else{
	 Local_enu_Erorr_State= ES_NOK;

 }
 return Local_enu_Erorr_State;
}
