/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   2 May 2023     ********************/
/******************   SW :         LCD       ********************/
/******************  version :     1.0       ********************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

//macros for lines
#define LCD_u8_LINE1   1
#define LCD_u8_LINE2   2

ES_t LCD_enum_INIT (void);
ES_t LCD_enum_Send_Comnd(u8 Copy_u8_Comnd);
ES_t LCD_enum_Send_char(u8 Copy_u8_char);
ES_t LCD_enum_GO_TO_XY (u8 Copy_u8_line_Num , u8 Copy_u8_Location );
ES_t LCD_enum_Send_String(u8 *copy_pu8_string);
ES_t LCD_enum_Clear (void);
ES_t LCD_enum_Send_Custom_char(u8 Copy_u8_Location , u8 * Copy_pu8_char_Array);
ES_t LCD_enum_Send_Num(u32 Copy_LCD_u32_Num);
#endif
