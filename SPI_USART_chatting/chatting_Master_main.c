/*
 * SPI_master_main.c
 *
 *  Created on: Feb 6, 2022
 *      Author: CompuSity
 */

#include "LIBRARY/BIT_MATH.h"
#include "LIBRARY/atmega32_registers.h"
#include "LIBRARY/primitive_data_types.h"
#include "MCAL/DIO/dio_interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/USART/usart_interface.h"

#define u8_MESSAGE_SIZE						255
#define u8_ENTER_FOR_ENDING_MESSAGE			'\r'

int main(void)
{
	//Array to receive message from Terminal
	uint8_t pu8_sendMessage[u8_MESSAGE_SIZE] ;

	//intializinig both USART and SPI
	USART_voidInit() ;
	SPI_voidInit() ;


	while(1)
	{
		//receive string from user
		USART_u8ReceiveStr(pu8_sendMessage,u8_MESSAGE_SIZE,u8_ENTER_FOR_ENDING_MESSAGE);

		// send string string using spi to the slave
		SPI_voidMasterSendArr(pu8_sendMessage,u8_MESSAGE_SIZE) ;
	}
}
