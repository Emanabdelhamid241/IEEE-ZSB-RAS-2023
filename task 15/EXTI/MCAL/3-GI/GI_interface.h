/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   27 july 2023     ********************/
/******************   SW :         GI         ********************/
/******************  version :     1.0       ********************/
#ifndef GI_INTERFACE_H
#define GI_INTERFACE_H

#define GI_u8_PIN7  7
#define GI_u8_SREG_REG       *((volatile u8*)0x5f)

ES_t  GI_enum_GI_Enable(void);
ES_t  GI_enum_GI_Disable(void);

#endif
