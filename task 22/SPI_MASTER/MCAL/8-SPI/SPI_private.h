/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   10 september 2023   ********************/
/******************   SW  :       SPI       ********************/
/******************  version :     1.0       ********************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


#define SPI_u8_SPDR_REG            *((volatile u8*)0x2F)
#define SPI_u8_SPSR_REG            *((volatile u8*)0x2E)
#define SPI_u8_SPCR_REG            *((volatile u8*)0x2D)


/* SPCR*/
#define    SPI_u8_SPR0_BIT0       0
#define    SPI_u8_SPR1_BIT1       1
#define    SPI_u8_CPHA_BIT2       2
#define    SPI_u8_CPOL_BIT3       3
#define    SPI_u8_MSTR_BIT4       4
#define    SPI_u8_DORD_BIT5       5
#define    SPI_u8_SPE_BIT6       6

/*SPSR*/
#define    SPI_u8_SPI2X_BIT0             0
#define    SPI_u8_SPIF_BIT7             7

/*SPI modes*/
#define SPI_u8_MASTER_MODE  1
#define SPI_u8_SLAVE_MODE  2

/*PORT*/
#define SPI_u8_MOSI_PORT       DIO_u8_PORTB
#define SPI_u8_MISO_PORT      DIO_u8_PORTB
#define SPI_u8_SCK_PORT       DIO_u8_PORTB
#define SPI_u8_SS_PORT       DIO_u8_PORTB
/*pins*/
#define SPI_u8_MOSI_PIN       DIO_u8_PIN5
#define SPI_u8_MISO_PIN       DIO_u8_PIN6
#define SPI_u8_SCK_PIN       DIO_u8_PIN7
#define SPI_u8_SS_PIN       DIO_u8_PIN4

/*CLK*/
#define SPI_u8_CLK_fosc_4                     0
#define SPI_u8_CLK_fosc_16                    1
#define SPI_u8_CLK_fosc_64                    2
#define SPI_u8_CLK_fosc_128                   3
#define SPI_u8_CLK_fosc_2                     4
#define SPI_u8_CLK_fosc_8                     5
#define SPI_u8_CLK_fosc_10                    6
#define SPI_u8_CLK_fosc_64_DOUBLE_SPEED       7

#endif
