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


//PINS OF EXTRI Index
#define    EXTI0_u8_PIN6          6
#define    EXTI1_u8_PIN7          7
#define    EXTI2_u8_PIN5          5

//INT0
#define   EXTI_u8_INT0_ISC01         1
#define   EXTI_u8_INT0_ISC00         0
//INT1
#define   EXTI_u8_INT1_ISC11         3
#define   EXTI_u8_INT1_ISC10         2
//INT2
#define   EXTI_u8_INT2_ISC2          6


#endif
