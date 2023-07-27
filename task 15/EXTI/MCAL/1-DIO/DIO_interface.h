// macros
#ifndef INTERFACE_H
#define INTERFACE_H

#include "../../libraries/types.h"
#include"../../libraries/Error_State.h"


 #define   DIO_u8_PORTA   0
 #define   DIO_u8_PORTB   1
 #define   DIO_u8_PORTC   2
 #define   DIO_u8_PORTD   3

 #define   DIO_u8_PIN0    0
 #define   DIO_u8_PIN1    1
 #define   DIO_u8_PIN2    2
 #define   DIO_u8_PIN3    3
 #define   DIO_u8_PIN4    4
 #define   DIO_u8_PIN5    5
 #define   DIO_u8_PIN6    6
 #define   DIO_u8_PIN7    7

 #define   DIO_u8_INPUT    0
 #define   DIO_u8_OUTPUT   1

#define   DIO_u8_LOW 0
 #define   DIO_u8_HIGH 1

#define   DIO_u8_INTIAL_INPUT   0
#define   DIO_u8_INTIAL_OUTPUT  1


             
 #define   DIO_u8_INTIAL_LOW   0
 #define   DIO_u8_INTIAL_HIGH  1
             
 #define   DIO_u8_INTIAL_FLOAT    0
 #define   DIO_u8_INTIAL_PULL_UP  1

void DIO_voidInit(void);

u8 DIO_u8_Set_Pin_Direction  (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Pin_Direction );

u8 DIO_u8_Set_Pin_Value      (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Pin_Value );

u8 DIO_u8_Get_Pin_Value      (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 * Copy_u8_Returned_Pin_Value );

u8 DIO_u8_Set_Port_Direction (u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_Direction );

u8 DIO_u8_Set_Port_Value     (u8 Copy_u8_Port_ID, u8 Copy_u8_Port_Value );

u8 DIO_u8_Get_Port_Value     (u8 Copy_u8_Port_ID, u8 * Copy_u8_Returned_Port_Value );


#endif
