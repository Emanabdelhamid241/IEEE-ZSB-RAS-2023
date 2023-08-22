/******************  name : Eman Abd Elhamed ********************/
/******************  Date :   18 August 2023 ********************/
/******************   SW :         WDT       ********************/
/******************  version :     1.0       ********************/
#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

/*WDT REGISTER*/
#define WDT_u8_WDTCR_REG      *((volatile u8 *)0x41)

/*BITS OF WDTCR REG */
#define WDT_WDP0_BIT0              0
#define WDT_WDP1_BIT1              1
#define WDT_WDP2_BIT2              2
#define WDT_WDE_BIT3               3
#define WDT_WDTOE_BIT4             4


#endif
