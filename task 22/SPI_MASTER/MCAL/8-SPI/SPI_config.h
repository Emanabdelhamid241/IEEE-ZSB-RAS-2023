/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   10 september 2023   ********************/
/******************   SW  :       SPI       ********************/
/******************  version :     1.0       ********************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#include "../1-DIO/DIO_interface.h"
/*option SPI_u8_MASTER_MODE
 * or SPI_u8_SALVE_MODE*/

#define SPI_u8_MODE       SPI_u8_MASTER_MODE

/*Options
 * SPI_u8_CLK_fosc_4
 * SPI_u8_CLK_fosc_16
 * SPI_u8_CLK_fosc_64
 * SPI_u8_CLK_fosc_128
 * SPI_u8_CLK_fosc_2
 * SPI_u8_CLK_fosc_8
 * SPI_u8_CLK_fosc_10
 * SPI_u8_CLK_fosc_64_DOUBLE_SPEED

                                */
#define SPI_u8_CLK     SPI_u8_CLK_fosc_64
#endif
