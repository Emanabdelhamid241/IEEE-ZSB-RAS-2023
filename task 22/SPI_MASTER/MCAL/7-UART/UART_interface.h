/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   23 August 2023   ********************/
/******************   SW  :       UART       ********************/
/******************  version :     1.0       ********************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

ES_t  UART_enum_INIT (void);
ES_t  UART_enum_SEND_Byte (u8 copy_UART_u8_data_byte);
ES_t  UART_enum_RECIEVE_Byte (u8 * copy_UART_pu8_recieve_byte);
ES_t UART_enum_Send_String(u8 *copy_pu8_string);
ES_t  UART_enum_RECIEVE_String (u8 * copy_UART_pu8_recieve_String);
#endif
