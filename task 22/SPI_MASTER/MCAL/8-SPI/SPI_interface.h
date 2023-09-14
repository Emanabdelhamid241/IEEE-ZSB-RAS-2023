/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   10 september 2023   ********************/
/******************   SW  :       SPI       ********************/
/******************  version :     1.0       ********************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


ES_t SPI_enum_INIT(void);
ES_t SPI_enum_trans_recieve(u8 Copy_u8_Treansmitted_Byte ,u8 * Copy_pu8_Recieved_Byte );
ES_t SPI_enum_Send_Byte(u8 Copy_u8_send_Byte );
ES_t SPI_enum_recieve_Byte(u8 * Copy_pu8_Recieved_Byte );

#endif
