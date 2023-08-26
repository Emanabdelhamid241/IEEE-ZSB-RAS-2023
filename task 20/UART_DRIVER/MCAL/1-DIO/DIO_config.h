#ifndef CONFIG_H
#define CONFIG_H
//set initial DIRECTIONS
/*
 DIO_u8_INTIAL_INPUT  
 or 
 DIO_u8_INTIAL_OUTPUT
 */
//PARTA
#define DIO_U8_PA0_INTIAL_DIRECTION        DIO_u8_INTIAL_OUTPUT
#define DIO_U8_PA1_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PA2_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PA3_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PA4_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PA5_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PA6_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PA7_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
//PARTB
#define DIO_U8_PB0_INTIAL_DIRECTION        DIO_u8_INTIAL_OUTPUT
#define DIO_U8_PB1_INTIAL_DIRECTION        DIO_u8_INTIAL_OUTPUT
#define DIO_U8_PB2_INTIAL_DIRECTION        DIO_u8_INTIAL_OUTPUT
#define DIO_U8_PB3_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PB4_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PB5_INTIAL_DIRECTION        DIO_u8_INTIAL_OUTPUT
#define DIO_U8_PB6_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PB7_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
//PARTC
#define DIO_U8_PC0_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PC1_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PC2_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PC3_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PC4_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PC5_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PC6_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PC7_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
//PARTD
#define DIO_U8_PD0_INTIAL_DIRECTION        DIO_u8_INTIAL_INPUT
#define DIO_U8_PD1_INTIAL_DIRECTION        DIO_u8_INTIAL_OUTPUT
#define DIO_U8_PD2_INTIAL_DIRECTION        DIO_u8_INTIAL_OUTPUT
#define DIO_U8_PD3_INTIAL_DIRECTION        DIO_u8_INTIAL_OUTPUT
#define DIO_U8_PD4_INTIAL_DIRECTION        DIO_u8_INTIAL_OUTPUT
#define DIO_U8_PD5_INTIAL_DIRECTION        DIO_u8_INTIAL_OUTPUT
#define DIO_U8_PD6_INTIAL_DIRECTION        DIO_u8_INTIAL_OUTPUT
#define DIO_U8_PD7_INTIAL_DIRECTION        DIO_u8_INTIAL_OUTPUT

//SET INTIAL VALUES
/*
 DIO_u8_INTIAL_LOW
 OR
 DIO_u8_INTIAL_HIGH
 OR
 DIO_u8_INTIAL_FLOAT
 OR
 DIO_u8_INTIAL_PULL_UP
 */

//PARTA
#define DIO_U8_PA0_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PA1_INTIAL_VALUE        DIO_u8_INTIAL_FLOAT
#define DIO_U8_PA2_INTIAL_VALUE        DIO_u8_INTIAL_FLOAT
#define DIO_U8_PA3_INTIAL_VALUE        DIO_u8_INTIAL_FLOAT
#define DIO_U8_PA4_INTIAL_VALUE        DIO_u8_INTIAL_FLOAT
#define DIO_U8_PA5_INTIAL_VALUE        DIO_u8_INTIAL_FLOAT
#define DIO_U8_PA6_INTIAL_VALUE        DIO_u8_INTIAL_FLOAT
#define DIO_U8_PA7_INTIAL_VALUE        DIO_u8_INTIAL_FLOAT
//PARTB
#define DIO_U8_PB0_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PB1_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PB2_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PB3_INTIAL_VALUE        DIO_u8_INTIAL_FLOAT
#define DIO_U8_PB4_INTIAL_VALUE        DIO_u8_INTIAL_FLOAT
#define DIO_U8_PB5_INTIAL_VALUE        DIO_u8_INTIAL_FLOAT
#define DIO_U8_PB6_INTIAL_VALUE        DIO_u8_INTIAL_FLOAT
#define DIO_U8_PB7_INTIAL_VALUE        DIO_u8_INTIAL_FLOAT
//PARTC
#define DIO_U8_PC0_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PC1_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PC2_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PC3_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PC4_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PC5_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PC6_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PC7_INTIAL_VALUE        DIO_u8_INTIAL_LOW
//PARTD
#define DIO_U8_PD0_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PD1_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PD2_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PD3_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PD4_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PD5_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PD6_INTIAL_VALUE        DIO_u8_INTIAL_LOW
#define DIO_U8_PD7_INTIAL_VALUE        DIO_u8_INTIAL_LOW

#endif