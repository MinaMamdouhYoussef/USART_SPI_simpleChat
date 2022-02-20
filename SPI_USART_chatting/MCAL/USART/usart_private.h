/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: USART
 *  Layer arch : MCAL
 *  Created on: Jan 26, 2022
 *	version:1
 *
 */

#ifndef __USART__PRIVATE__
#define __USART__PRIVATE__


//bits num. of Ru8_UCSRA register (flags)
#define u8_USART_RXC						7
#define u8_USART_TXC						6
#define u8_USART_UDRE						5
#define u8_USART_FE							4
#define u8_USART_DOR						3
#define u8_USART_PE							2
#define u8_USART_U2X						1
#define u8_USART_MPCM						0

//bits num. of Ru8_UCSRB register 
#define u8_USART_RXCIE						7
#define u8_USART_TXCIE						6
#define u8_USART_UDRIE						5
#define u8_USART_RXEN						4
#define u8_USART_TXEN						3
#define u8_USART_UCSZ2						2

//bits num. of UCSRC register with name Ru8_UBRRH_UCSRC
#define u8_USART_URSEL						7  /*setting this bit in Ru8_UBRRH_UCSRC Reg to 1 in the same line you put 
												*the needed options for the remainning bits make you in UCSRC and setting 
												*this bit to 0 in the same line you puy the needed options for remainning bits 
												*make you in UBBRH */ 
#define u8_USART_UMSEL						6
#define u8_USART_UPM1						5
#define u8_USART_UPM0						4
#define u8_USART_USBS						3
#define u8_USART_UCSZ1						2
#define u8_USART_UCSZ0						1
#define u8_USART_UCPOL						0

//bits num. of UBBRH with name Ru8_UBRRH_UCSRC
#define u8_USART_UBRR11                     3 //higher order (MSB) Baud control bits 
#define u8_USART_UBRR10                     2 //higher order (MSB) Baud control bits 
#define u8_USART_UBRR9                      1 //higher order (MSB) Baud control bits 
#define u8_USART_UBRR8      	            0 //higher order (MSB) Baud control bits 


#define u8_USART_SET						1

#define u8_USART_BAUD_RATE_9600  			51

#define u8_USART_INTIALIZING_VAL			0
 
#define u8_USART_MAX_FSOC					20000000

#define u16_USART_MAX_UBRR					4096

#define u8_USART_MAX_NUM_OF_BITS_IN_REG		8

#define u8_USART_BAUD_ASYN_NORMAL_FACTOR	16


#define u8_USART_DATA_REG_EMPTY				1
#define u8_USART_DATA_REG_FULL				0

#define u8_USART_FLAG_SET					1
#define u8_USART_FLAG_CLEAR					0











#endif
