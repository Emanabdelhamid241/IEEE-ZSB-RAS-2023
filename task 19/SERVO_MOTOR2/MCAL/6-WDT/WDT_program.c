/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   18 August 2023 ********************/
/******************   SW :         WDT       ********************/
/******************  version :     1.0       ********************/
//libraries layer
#include"../../libraries/math.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/types.h"

//MCAL Layer
#include "WDT_config.h"
#include "WDT_private.h"

ES_t  WDT_enum_WDT_Enable (void){
	ES_t Local_enu_Erorr_State= ES_OK;
	/*ENABLE WDT =2.1Sec */
	SET_BIT(WDT_u8_WDTCR_REG, WDT_WDP0_BIT0);
	SET_BIT(WDT_u8_WDTCR_REG, WDT_WDP1_BIT1);
	SET_BIT(WDT_u8_WDTCR_REG, WDT_WDP2_BIT2);
//	WDT_u8_WDTCR_REG= 0b00001111;
return Local_enu_Erorr_State;

}
ES_t  WDT_enum_WDT_Disable (void){
	ES_t Local_enu_Erorr_State= ES_OK;
		/*DISABLE WDT =2.1Sec */
	WDT_u8_WDTCR_REG |= ((1<<WDT_WDTOE_BIT4) | (1<<WDT_WDE_BIT3));
	WDT_u8_WDTCR_REG = 0x00;
//	SET_BIT(WDT_u8_WDTCR_REG, WDT_WDE_BIT3);
//	SET_BIT(WDT_u8_WDTCR_REG, WDT_WDTOE_BIT4);


	return Local_enu_Erorr_State;

}
