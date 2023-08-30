/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   9 july 2023    ********************/
/******************   SW :         KPD       ********************/
/******************  version :     1.0       ********************/
#include "KPD_config.h"
#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H



	ES_t KPD_enum_Init(void);
ES_t KPD_enum_Get_Key_State(u8 * Copy_pu8_Returned_Key);

#endif
