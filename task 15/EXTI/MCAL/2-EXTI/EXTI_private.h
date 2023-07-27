/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   27 july 2023     ********************/
/******************   SW :         EXTI      ********************/
/******************  version :     1.0       ********************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/*Define for EXTI Registers*/
#define EXTI_u8_MCUCR_REG   *((volatile u8*)0x55)
#define EXTI_u8_MCUCSR_REG   *((volatile u8*)0x54)
#define EXTI_u8_GIFR_REG   *((volatile u8*)0x5A)
#define EXTI_u8_GICR_REG   *((volatile u8*)0x5B)


#endif
