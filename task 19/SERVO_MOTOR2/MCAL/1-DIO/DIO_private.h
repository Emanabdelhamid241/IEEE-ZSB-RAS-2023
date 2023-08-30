#ifndef PRIVATE_H_
#define PRIVATE_H_

#include "../../libraries/types.h"
#include"../../libraries/Error_State.h"

//macros for PARTA
#define DIO_u8_PORTA_REG        *((volatile u8*)0x3B)
#define DIO_u8_DDRA_REG         *((volatile u8*)0x3A)
#define DIO_u8_PINA_REG         *((volatile u8*)0x39)
//macros for PARTB
#define DIO_u8_PORTB_REG        *((volatile u8*)0x38)
#define DIO_u8_DDRB_REG         *((volatile u8*)0x37)
#define DIO_u8_PINB_REG         *((volatile u8*)0x36)
//macros for PARTC
#define DIO_u8_PORTC_REG        (*((volatile u8*)0x35))
#define DIO_u8_DDRC_REG        ( *((volatile u8*)0x34))
#define DIO_u8_PINC_REG         (*((volatile u8*)0x33))
//macros for PARTD
#define DIO_u8_PORTD_REG        *((volatile u8*)0x32)
#define DIO_u8_DDRD_REG         *((volatile u8*)0x31)
#define DIO_u8_PIND_REG         *((volatile u8*)0x30)

// macros for pins DIRCTIONS
 #define DIO_u8_INTIAL_INPUT     0
 #define DIO_u8_INTIAL_OUTPUT    1

// macros for pins VALUES
#define DIO_u8_INTIAL_LOW            0
#define DIO_u8_INTIAL_HIGH           1 
#define DIO_u8_INTIAL_FLOAT          0 
#define DIO_u8_INTIAL_PULL_UP        1
//macros
 #define   DIO_u8_PORTA 0
 #define   DIO_u8_PORTB 1
 #define   DIO_u8_PORTC  2
 #define   DIO_u8_PORTD   3

 #define   DIO_u8_PIN0  0
 #define   DIO_u8_PIN1  1
 #define   DIO_u8_PIN2  2
 #define   DIO_u8_PIN3  3
 #define   DIO_u8_PIN4  4
 #define   DIO_u8_PIN5  5
 #define   DIO_u8_PIN6  6
 #define   DIO_u8_PIN7  7

 #define   DIO_u8_INPUT 0
 #define   DIO_u8_OUTPUT 1
             
 #define   DIO_u8_LOW 0
 #define   DIO_u8_HIGH 1
             

//macros for Function to concatenate pin

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)        CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)   0b##b7##b6##b5##b4##b3##b2##b1##b0
#endif
