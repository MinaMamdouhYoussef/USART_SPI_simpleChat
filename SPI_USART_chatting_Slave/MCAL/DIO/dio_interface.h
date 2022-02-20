/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: DIO
 *  Layer arch : MCAL
 *  Created on: Jan 15, 2022
 *	version: 1
 *
 */


#ifndef __DIO__INTERFACE__
#define __DIO__INTERFACE__


#define u8_DIO_PIN0                     	  0
#define u8_DIO_PIN1                    	 	  1
#define u8_DIO_PIN2                    		  2
#define u8_DIO_PIN3                    	  	  3
#define u8_DIO_PIN4                     	  4
#define u8_DIO_PIN5                   	      5
#define u8_DIO_PIN6                           6
#define u8_DIO_PIN7                     	  7

#define u8_DIO_PORTA                	      8
#define u8_DIO_PORTB            	          9
#define u8_DIO_PORTC        	              10
#define u8_DIO_PORTD    	                  11
										  
#define u8_DIO_INPUT_PIN                      0
#define u8_DIO_OUTPUT_PIN                     1
										  
#define u8_DIO_PIN_LOW				          0
#define u8_DIO_PIN_HIGH						  1

#define u8_DIO_INPUT_PORT                     0b00000000
#define u8_DIO_OUTPUT_PORT                    0b11111111
										  
#define u8_DIO_PORT_LOW				          0b00000000
#define u8_DIO_PORT_HIGH					  0b11111111

#define u8_DIO_OK							  2
#define u8_DIO_NOK							  3


uint8_t DIO_u8SetPinVal(uint8_t u8_PortNum,uint8_t u8_PinNum,uint8_t u8_PinState)     		;
uint8_t DIO_u8SetPinDir(uint8_t u8_PortNum,uint8_t u8_PinNum,uint8_t u8_PinDir)             ;
uint8_t DIO_u8SetPortVal(uint8_t u8_PortNum,uint8_t u8_PortState)                           ;
uint8_t DIO_u8SetPortDir(uint8_t u8_PortNum,uint8_t u8_PortDir)                             ;
uint8_t DIO_u8GetPinVal(uint8_t u8_PortNum,uint8_t u8_PinNum,uint8_t* pu8_ReturnedPinVal)   ;   
uint8_t DIO_u8GetPortVal(uint8_t u8_PortNum,uint8_t* pu8_ReturnedPortVal)                   ;
uint8_t DIO_u8TogPinVal(uint8_t u8_PortNum,uint8_t u8_PinNum)                               ;
void DIO_voidDisablePullUps(void)                                                           ;
void DIO_voidEnablePullUps(void)                                                            ;



#endif
