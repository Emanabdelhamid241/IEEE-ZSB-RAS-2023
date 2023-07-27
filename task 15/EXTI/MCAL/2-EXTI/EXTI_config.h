/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   27 july 2023     ********************/
/******************   SW :         EXTI      ********************/
/******************  version :     1.0       ********************/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H
/*macros of ints*/
#define EXTI_u8_INT0   0
#define EXTI_u8_INT1   1
#define EXTI_u8_INT2   2

/*macros of Edge Source*/
#define  EXTI_u8_RAISING_EDGE            0
#define  EXTI_u8_FALLING_EDGE            1
#define  EXTI_u8_ANY_LOGICAL_CHANGE      2
#define  EXTI_u8_LOW_LEVEL               3
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
