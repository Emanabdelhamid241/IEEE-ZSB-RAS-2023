/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   2 May 2023     ********************/
/******************   SW :         LCD       ********************/
/******************  version :     1.0       ********************/
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H


#define FUN_SET_8BIT_2LINES_5X7      0b00111000
#define DIS_ON_CURSOR_ON_BLINKING    0b00001111
#define DISPLAY_CLEAR                0x01
#define ENTRY_MOOD                   0b00000110

//macros for addresses
#define ADDRESS_OF_LINE1               0x80
#define ADDRESS_OF_LINE2               0xc0


#define LCD_u8_MODE_8_bit     1
#define LCD_u8_MODE_4_bit     2



#define ADDRESS_OF_CGRAM             0x40
#define MAX_CHARACTERS                8


#endif
