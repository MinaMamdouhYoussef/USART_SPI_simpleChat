/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: USART
 *  Layer arch : MCAL
 *  Created on: Jan 26, 2022
 *	version:1
 *
 */


#ifndef __USART__INTERFACE__
#define __USART__INTERFACE__

#define u8_USART_DATA_NOT_SENT 					130
#define u8_USART_DATA_SENT	 					131

#define u8_USART_DATA_OVER_RUN					140
#define u8_USART_FRAME_ERROR					141
#define u8_USART_PARITY_ERROR					142	
#define u8_USART_NOT_RECEIVED					143
#define u8_USART_RECEIVED_NULL_PTR_ARG			144
#define u8_USART_RECEIVED_CORRECT				145
#define u8_MAX_WAIT_IN_MS				    	12000




void USART_voidInit(void) ;

uint8_t USART_u8TransData(uint8_t u8_DataSent) ;
uint8_t USART_u8ReceiveData(uint8_t* pu8_DataReceive) ;
uint8_t USART_u8TransStr(uint8_t* pu8_StrSent) ;
uint8_t USART_u8ReceiveStr(uint8_t* pu8_StrReceive, uint8_t u8_strSize,uint8_t u8_terminator);
















#endif
