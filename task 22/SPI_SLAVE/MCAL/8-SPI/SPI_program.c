/******************  name : Eman Abd Elhamed  ********************/
/******************  Date :   10 september 2023   ********************/
/******************   SW  :       SPI       ********************/
/******************  version :     1.0       ********************/
#include"../../libraries/types.h"
#include"../../libraries/Error_State.h"
#include"../../libraries/math.h"


#include"SPI_config.h"
#include"SPI_private.h"
#include "../1-DIO/DIO_interface.h"

ES_t SPI_enum_INIT(void)
{
//	ES_t Local_enu_Erorr_State= ES_OK;

	/*data order= MSB first */
	CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_DORD_BIT5);

	/*Choose CPOL and CPHA => Falling,Raising / setup,sample */
	SET_BIT(SPI_u8_SPCR_REG,SPI_u8_CPOL_BIT3);
	SET_BIT(SPI_u8_SPCR_REG,SPI_u8_CPHA_BIT2);
#if SPI_u8_MODE == SPI_u8_MASTER_MODE
	/*CONFIG PINs OF MASTER MODE*/
	DIO_u8_Set_Pin_Direction(SPI_u8_MOSI_PORT,SPI_u8_MOSI_PIN,DIO_u8_OUTPUT);
	DIO_u8_Set_Pin_Direction(SPI_u8_MISO_PORT,SPI_u8_MISO_PIN,DIO_u8_INPUT);
	DIO_u8_Set_Pin_Direction(SPI_u8_SCK_PORT,SPI_u8_SCK_PIN,DIO_u8_OUTPUT);
	DIO_u8_Set_Pin_Direction(SPI_u8_SS_PORT,SPI_u8_SS_PIN,DIO_u8_INPUT);

	DIO_u8_Set_Pin_Value(SPI_u8_MOSI_PORT,SPI_u8_MOSI_PIN,DIO_u8_INTIAL_LOW);
	DIO_u8_Set_Pin_Value(SPI_u8_MISO_PORT,SPI_u8_MISO_PIN,DIO_u8_INTIAL_FLOAT);
	DIO_u8_Set_Pin_Value(SPI_u8_SCK_PORT,SPI_u8_SCK_PIN,DIO_u8_INTIAL_LOW);
	DIO_u8_Set_Pin_Value(SPI_u8_SS_PORT,SPI_u8_SS_PIN,DIO_u8_INTIAL_PULL_UP);
	/*master mode*/
	SET_BIT(SPI_u8_SPCR_REG,SPI_u8_MSTR_BIT4);

#elif SPI_u8_MODE == SPI_u8_SLAVE_MODE
	/*CONFIG PINs OF SLAVE MODE*/
		DIO_u8_Set_Pin_Direction(SPI_u8_MOSI_PORT,SPI_u8_MOSI_PIN,DIO_u8_INPUT);
		DIO_u8_Set_Pin_Direction(SPI_u8_MISO_PORT,SPI_u8_MISO_PIN,DIO_u8_OUTPUT);
		DIO_u8_Set_Pin_Direction(SPI_u8_SCK_PORT,SPI_u8_SCK_PIN,DIO_u8_INPUT);
		DIO_u8_Set_Pin_Direction(SPI_u8_SS_PORT,SPI_u8_SS_PIN,DIO_u8_INPUT);

		DIO_u8_Set_Pin_Value(SPI_u8_MOSI_PORT,SPI_u8_MOSI_PIN,DIO_u8_INTIAL_FLOAT);
		DIO_u8_Set_Pin_Value(SPI_u8_MISO_PORT,SPI_u8_MISO_PIN,DIO_u8_INTIAL_LOW);
		DIO_u8_Set_Pin_Value(SPI_u8_SCK_PORT,SPI_u8_SCK_PIN,DIO_u8_INTIAL_FLOAT);
		DIO_u8_Set_Pin_Value(SPI_u8_SS_PORT,SPI_u8_SS_PIN,DIO_u8_INTIAL_PULL_UP);
	/*slave mode*/
    CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_MSTR_BIT4);

#endif

#if SPI_u8_CLK==SPI_u8_CLK_fosc_4
   /*CLK=fosc/4*/
	CLR_BIT(SPI_u8_SPSR_REG,SPI_u8_SPI2X_BIT0);
	CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT0);
	CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT1);
#elif SPI_u8_CLK==SPI_u8_CLK_fosc_16
   /*CLK=fosc/16*/
	CLR_BIT(SPI_u8_SPSR_REG,SPI_u8_SPI2X_BIT0);
	SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT0);
	CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT1);
#elif SPI_u8_CLK==SPI_u8_CLK_fosc_64
   /*CLK=fosc/64*/
	CLR_BIT(SPI_u8_SPSR_REG,SPI_u8_SPI2X_BIT0);
	CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT0);
	SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT1);
#elif SPI_u8_CLK==SPI_u8_CLK_fosc_128
   /*CLK=fosc/128*/
	CLR_BIT(SPI_u8_SPSR_REG,SPI_u8_SPI2X_BIT0);
	SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT0);
	SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT1);
#elif SPI_u8_CLK==SPI_u8_CLK_fosc_2
   /*CLK=fosc/64*/
	SET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPI2X_BIT0);
	CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT0);
	CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT1);
#elif SPI_u8_CLK==SPI_u8_CLK_fosc_8
   /*CLK=fosc/64*/
	SET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPI2X_BIT0);
	SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT0);
	CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT1);
#elif SPI_u8_CLK==SPI_u8_CLK_fosc_10
   /*CLK=fosc/64*/
	SET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPI2X_BIT0);
	CLR_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT0);
	SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT1);
#elif SPI_u8_CLK==SPI_u8_CLK_fosc_64_DOUBLE_SPEED
   /*CLK=fosc/64 double speed*/
	SET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPI2X_BIT0);
	SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR0_BIT0);
	SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPR1_BIT1);
#endif
		/*Enable SPI*/
		SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPE_BIT6);

	return ES_OK;
}
ES_t SPI_enum_trans_recieve(u8 Copy_u8_Treansmitted_Byte ,u8 * Copy_pu8_Recieved_Byte )
{
	ES_t Local_enu_Erorr_State= ES_OK;
if(Copy_pu8_Recieved_Byte!= NULL)
{
	/*send byte*/
	SPI_u8_SPDR_REG =Copy_u8_Treansmitted_Byte;
	/*Chack if the transmission is completed*/
	while(!GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPIF_BIT7));
	/*Read byte*/
	*Copy_pu8_Recieved_Byte = SPI_u8_SPDR_REG;
	Local_enu_Erorr_State= ES_NOK;
}

		return Local_enu_Erorr_State;

}
ES_t SPI_enum_Send_Byte(u8 Copy_u8_send_Byte )
{
	ES_t Local_enu_Erorr_State= ES_OK;
/*send byte*/
	SPI_u8_SPDR_REG=Copy_u8_send_Byte;
//	/*Chack if the transmission is completed*/
//		while(!GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPIF_BIT7));

		return Local_enu_Erorr_State;

}
ES_t SPI_enum_recieve_Byte(u8 * Copy_pu8_Recieved_Byte )
{
	ES_t Local_enu_Erorr_State= ES_OK;
if(Copy_pu8_Recieved_Byte!= NULL){
	/*Chack if the transmission is completed*/
		while(!GET_BIT(SPI_u8_SPSR_REG,SPI_u8_SPIF_BIT7));
		/*Read byte*/
		*Copy_pu8_Recieved_Byte = SPI_u8_SPDR_REG;
}

		return Local_enu_Erorr_State;

}

