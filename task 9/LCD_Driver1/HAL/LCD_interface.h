/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   2 May 2023     ********************/
/******************   SW :         LCD       ********************/
/******************  version :     1.0       ********************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LCD_u8_LINE1   1
#define LCD_u8_LINE2   2

void LCD_void_INIT (void);
void LCD_void_Send_Comnd(u8 Copy_u8_Comnd);
void LCD_void_Send_char(u8 LCD_u8_char);
u8 LCD_u8_GO_TO_XY (u8 Copy_u8_line_Num , u8 Copy_u8_Location );

#endif
