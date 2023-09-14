/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   23 August 2023   ********************/
/******************   SW  :       UART       ********************/
/******************  version :     1.0       ********************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define UART_u8_UBRRH_REG      *((volatile u8*)0x40)
#define UART_u8_UCSRC_REG      *((volatile u8*)0x40)

#define UART_u8_UDR_REG        *((volatile u8*)0x2C)
#define UART_u8_UCSRA_REG      *((volatile u8*)0x2B)
#define UART_u8_UCSRB_REG      *((volatile u8*)0x2A)

#define UART_u8_UBRRL_REG      *((volatile u8*)0x29)

/*BITS OF UCSRA */
#define  UART_u8_MPCM_BIT0                      0
#define  UART_u8_U2X_BIT1                       1
#define  UART_u8_UDRE_BIT5                       5
#define  UART_u8_RXC_BIT7                       7



/*BITS OF UCSRB */
#define  UART_u8_UCSZ2_BIT2                      2
#define  UART_u8_TXEN_BIT3                      3
#define  UART_u8_RXEN_BIT4                      4

/* UCSRC */
#define  UART_u8_UCSZ0_BIT1                      1
#define  UART_u8_UCSZ1_BIT2                      2
#define  UART_u8_USBS_BIT3                       3
#define  UART_u8_UPM0_BIT4                       4
#define  UART_u8_UPM1_BIT5                       5
#define  UART_u8_UMSEL_BIT6                      6

/**/
#define UART_INTIAL_UCSRC_value                0b10000000

    /*baud rate = 9600*/
#define UART_u8_inital_baud_rate_9600     103

/*no of bit of one byte*/
#define no_of_bit_of_one_byte              8


#endif
