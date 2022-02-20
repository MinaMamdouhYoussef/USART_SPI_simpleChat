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

int main(void)
{
	//Array to receive message from Terminal
	uint8_t pu8_ReceiveMessage[u8_MESSAGE_SIZE] ;

	//intializinig both USART and SPI
	USART_voidInit() ;
	SPI_voidInit() ;

	while(1)
	{
		//slave receive string from master
		SPI_voidSlaveReceiveArr(pu8_ReceiveMessage,u8_MESSAGE_SIZE) ;
		//slave show the data on terminal using USART
		USART_u8TransStr(pu8_ReceiveMessage);
		//make new line
		USART_u8TransData('\r')  ;
	}
}
