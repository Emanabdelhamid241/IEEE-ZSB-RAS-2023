/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   27 july 2023     ********************/
/******************   SW :         GI         ********************/
/******************  version :     1.0       ********************/

//libraries layer
#include"../../libraries/math.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/types.h"

//MCAL
#include "GI_config.h"
#include "GI_private.h"

ES_t  GI_enum_GI_Enable(void){
	SET_BIT(GI_u8_SREG_REG,GI_u8_PIN7);
return ES_OK;
}
ES_t  GI_enum_GI_Disable(void){
	CLR_BIT(GI_u8_SREG_REG,GI_u8_PIN7);
	return ES_OK;

}
