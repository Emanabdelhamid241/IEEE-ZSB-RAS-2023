/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   2 May 2023     ********************/
/******************   SW :         LCD       ********************/
/******************  version :     1.0       ********************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H
/*options
DIO_u8_PORTA
DIO_u8_PORTB
DIO_u8_PORTC
DIO_u8_PORTD
  */

#define LCD_u8_CONTROL_PORT  DIO_u8_PORTB
#define LCD_u8_RS_PIN        DIO_u8_PIN0
#define LCD_u8_RW_PIN        DIO_u8_PIN1
#define LCD_u8_E_PIN         DIO_u8_PIN2

#define LCD_u8_DATA_PORT  DIO_u8_PORTC

//macros of LCD MODE
/* options
 LCD_u8_MODE_8_bit
 LCD_u8_MODE_4_bit
 */
#define LCD_u8_MODE    LCD_u8_MODE_8_bit

#endif
