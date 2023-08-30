/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   4 August 2023     ********************/
/******************   SW :         ADC        ********************/
/******************  version :     1.0       ********************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* Define ADC Registers*/
#define ADC_u8_ADMUX_REG      *((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REG     *((volatile u8 *)0x26)
#define ADC_u8_ADCH_REG       *((volatile u8 *)0x25)
#define ADC_u8_ADCL_REG       *((volatile u8 *)0x24)

#define ADC_u16_ADC_REG      *((volatile u16 *)0x24)

#define ADC_u8_SFIOR_REG      *((volatile u8 *)0x50)


/*macros of bits of ADMUX*/
#define ADC_u8_REFS1_BIT7          7
#define ADC_u8_REFS0_BIT6          6
#define ADC_u8_ADLAR_BIT5          5

/*macros of bits of ADCSRA*/
#define ADC_u8_ADPS0_BIT0          0
#define ADC_u8_ADPS1_BIT1          1
#define ADC_u8_ADPS2_BIT2          2
#define ADC_u8_ADIE_BIT3           3
#define ADC_u8_ADIF_BIT4           4
#define ADC_u8_ADATE_BIT5          5
#define ADC_u8_ADSC_BIT6           6
#define ADC_u8_ADEN_BIT7           7



/*numbers of channels*/
#define ADC_u8_Max_Channels_NB     32

/**/
#define CLEAR_MUX_BITS                    0b11100000

#endif
