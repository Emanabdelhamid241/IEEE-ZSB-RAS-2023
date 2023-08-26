/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   23 August 2023   ********************/
/******************   SW  :       UART       ********************/
/******************  version :     1.0       ********************/
#include"../../libraries/types.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/math.h"

//MCAL layer
#include "UART_config.h"
#include "UART_private.h"

#include "../../MCAL/1-DIO/DIO_interface.h"


#include<util/delay.h>
ES_t  UART_enum_INIT (void)
{
	ES_t Local_enu_Erorr_State= ES_OK;
	u16 local_u16_baud_rate_value = UART_u8_inital_baud_rate_9600;
    u8 local_u8_UCSRC_value= UART_INTIAL_UCSRC_value;


     /*Normal speed*/
	CLR_BIT(UART_u8_UCSRA_REG,UART_u8_U2X_BIT1);

	/*Disable MPCM */
	CLR_BIT (UART_u8_UCSRA_REG ,UART_u8_MPCM_BIT0);

	/*Enable Rx ,Tx*/
	SET_BIT(UART_u8_UCSRB_REG,UART_u8_TXEN_BIT3);
	SET_BIT(UART_u8_UCSRB_REG,UART_u8_RXEN_BIT4);


	/*Select 8 bit */
	CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSZ2_BIT2);
	SET_BIT(local_u8_UCSRC_value,UART_u8_UCSZ0_BIT1);
	SET_BIT(local_u8_UCSRC_value,UART_u8_UCSZ1_BIT2);

     /*Select Asynch Mode */
	CLR_BIT(local_u8_UCSRC_value,UART_u8_UMSEL_BIT6);

	/*NO Parity Bit*/
	CLR_BIT(local_u8_UCSRC_value,UART_u8_UPM0_BIT4);
	CLR_BIT(local_u8_UCSRC_value,UART_u8_UPM1_BIT5);

	/*Enable 2 Stop Bits*/
	CLR_BIT(local_u8_UCSRC_value,UART_u8_USBS_BIT3);

    /*Update UCSRC REG*/
	UART_u8_UCSRC_REG=local_u8_UCSRC_value;

	/*baud rate = 9600*/
	    UART_u8_UBRRL_REG= (u8)local_u16_baud_rate_value;
	    UART_u8_UBRRH_REG= (u8)(local_u16_baud_rate_value >> no_of_bit_of_one_byte);


	//test
	DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);

	return Local_enu_Erorr_State;
}
ES_t  UART_enum_SEND_Byte (u8 copy_UART_u8_data_byte)
{
	ES_t Local_enu_Erorr_State= ES_OK;
     /* wait until the transmit reg is empty*/
	while (GET_BIT(UART_u8_UCSRA_REG,UART_u8_UDRE_BIT5)==0);

	/* send data byte */
	UART_u8_UDR_REG=copy_UART_u8_data_byte;
	return Local_enu_Erorr_State;

}
ES_t  UART_enum_RECIEVE_Byte (u8 *copy_UART_pu8_recieve_byte)
{
	ES_t Local_enu_Erorr_State= ES_OK;

	if(copy_UART_pu8_recieve_byte != NULL)
	{
//		DIO_u8_Set_Pin_Value(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);

	/* wait until the data is recieved */
	while (!GET_BIT(UART_u8_UCSRA_REG,UART_u8_RXC_BIT7));
//while(((UART_u8_UCSRA_REG >>7)&1)==0);
	/* read data byte*/
	*copy_UART_pu8_recieve_byte=UART_u8_UDR_REG;


	}
	else{

			Local_enu_Erorr_State = ES_NOK;
		    }
	return Local_enu_Erorr_State;



}

ES_t UART_enum_Send_String(u8 *copy_pu8_string)
{
	ES_t Local_enu_Erorr_State= ES_OK;
	if(copy_pu8_string!= NULL){
	for (u8 Local_u8_Iterator ; copy_pu8_string[Local_u8_Iterator] != '\0'; Local_u8_Iterator++){
		 /* wait until the transmit reg is empty*/
			while (GET_BIT(UART_u8_UCSRA_REG,UART_u8_UDRE_BIT5)==0);

			/* send data byte */
			UART_u8_UDR_REG=copy_pu8_string[Local_u8_Iterator];
	}
	}
	else{
		Local_enu_Erorr_State = ES_NOK;
	    }

	return Local_enu_Erorr_State;
}
ES_t  UART_enum_RECIEVE_String (u8 * copy_UART_pu8_recieve_String)
{
	ES_t Local_enu_Erorr_State= ES_OK;
	u8 i=0;
	u8 local_u8_counter=0;
		if(copy_UART_pu8_recieve_String != NULL)
		{
if(copy_UART_pu8_recieve_String[i]==recieve_sring_mark)   local_u8_counter++;
if(local_u8_counter<=2){
	/* wait until the data is recieved */
		while (!GET_BIT(UART_u8_UCSRA_REG,UART_u8_RXC_BIT7));
		/* read data byte*/
		copy_UART_pu8_recieve_String[i]=UART_u8_UDR_REG;

}
		}
		else{
				Local_enu_Erorr_State = ES_NOK;
			    }
		return Local_enu_Erorr_State;

}

