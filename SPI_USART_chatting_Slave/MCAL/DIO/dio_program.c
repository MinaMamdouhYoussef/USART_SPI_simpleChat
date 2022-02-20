/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: DIO
 *  Layer arch : MCAL
 *  Created on: Jan 15, 2022
 *	version: 1
 *
 */

#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/primitive_data_types.h"
#include "../../LIBRARY/atmega32_registers.h"
#include "dio_interface.h"
#include "dio_private.h"


uint8_t DIO_u8SetPinVal(uint8_t u8_PortNum,uint8_t u8_PinNum,uint8_t u8_PinState)     
{
	uint8_t u8_ErrorState = u8_DIO_OK;
	if(u8_PinNum>=u8_DIO_PIN0 && u8_PinNum<=u8_DIO_PIN7)
	{
		switch(u8_PortNum)
		{
			case u8_DIO_PORTA: if(u8_PinState == u8_DIO_PIN_LOW)
								{
									CLR_BIT(Ru8_PORTA,u8_PinNum) ;
								}
								else if(u8_PinState == u8_DIO_PIN_HIGH)
								{
									SET_BIT(Ru8_PORTA,u8_PinNum) ;
								}
								else 
								{
									u8_ErrorState = u8_DIO_NOK ; 
								}

							   break;
							   
			case u8_DIO_PORTB:	if(u8_PinState == u8_DIO_PIN_LOW)
								{
									CLR_BIT(Ru8_PORTB,u8_PinNum) ;
								}
								else if(u8_PinState == u8_DIO_PIN_HIGH)
								{
									SET_BIT(Ru8_PORTB,u8_PinNum) ;
								}
								else 
								{
									u8_ErrorState = u8_DIO_NOK ; 
								}
							   break;
							   
			case u8_DIO_PORTC:  if(u8_PinState == u8_DIO_PIN_LOW)
								{
									CLR_BIT(Ru8_PORTC,u8_PinNum) ;
								}
								else if(u8_PinState == u8_DIO_PIN_HIGH)
								{
									SET_BIT(Ru8_PORTC,u8_PinNum) ;
								}
								else 
								{
									u8_ErrorState = u8_DIO_NOK ; 
								}

								break;
								
			case u8_DIO_PORTD: if(u8_PinState == u8_DIO_PIN_LOW)
							   {
									CLR_BIT(Ru8_PORTD,u8_PinNum) ;
							   }
							   else if(u8_PinState == u8_DIO_PIN_HIGH)
							   {
									SET_BIT(Ru8_PORTD,u8_PinNum) ;
							   }
							   else 
							   {
									u8_ErrorState = u8_DIO_NOK ; 
							   }
								break;
								
			default          : u8_ErrorState = u8_DIO_NOK ; 
								break ; 
		}
	}
	else 
	{
		u8_ErrorState = u8_DIO_NOK ; 
	}
	return u8_ErrorState  ; 
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t DIO_u8SetPinDir(uint8_t u8_PortNum,uint8_t u8_PinNum,uint8_t u8_PinDir)      
{
	
	uint8_t u8_ErrorState = u8_DIO_OK;
	if(u8_PinNum>=u8_DIO_PIN0 && u8_PinNum<=u8_DIO_PIN7)
	{
		switch(u8_PortNum)
		{
			case u8_DIO_PORTA: if(u8_PinDir ==u8_DIO_OUTPUT_PIN)
							   {
									SET_BIT(Ru8_DDRA,u8_PinNum) ;
							   }
							   else if(u8_PinDir ==u8_DIO_INPUT_PIN)
							   {
									CLR_BIT(Ru8_DDRA,u8_PinNum) ;
							   }
							   else 
							   {
									u8_ErrorState = u8_DIO_NOK ; 
							   }
							   break;
	
			case u8_DIO_PORTB: if(u8_PinDir ==u8_DIO_OUTPUT_PIN)
							   {
									SET_BIT(Ru8_DDRB,u8_PinNum) ;
							   }
							   else if(u8_PinDir ==u8_DIO_INPUT_PIN)
							   {
									CLR_BIT(Ru8_DDRB,u8_PinNum) ;
							   }
							   else 
							   {
									u8_ErrorState = u8_DIO_NOK ; 
							   }
							   break;
							   
			case u8_DIO_PORTC:  if(u8_PinDir ==u8_DIO_OUTPUT_PIN)
							    {
									SET_BIT(Ru8_DDRC,u8_PinNum) ;
								}
								else if(u8_PinDir ==u8_DIO_INPUT_PIN)
								{
									CLR_BIT(Ru8_DDRC,u8_PinNum) ;
								}
								else 
								{
									u8_ErrorState = u8_DIO_NOK ; 
								}
								break;
		
			case u8_DIO_PORTD: if(u8_PinDir ==u8_DIO_OUTPUT_PIN)
							    {
									SET_BIT(Ru8_DDRD,u8_PinNum) ;
								}
								else if(u8_PinDir ==u8_DIO_INPUT_PIN)
								{
									CLR_BIT(Ru8_DDRD,u8_PinNum) ;
								}
								else 
								{
									u8_ErrorState = u8_DIO_NOK ; 
								}
								break;
			
			default          : u8_ErrorState = u8_DIO_NOK ; 
								break ; 
		}
	}
	else 
	{
		u8_ErrorState = u8_DIO_NOK ; 
	}
	return u8_ErrorState  ; 
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t DIO_u8SetPortVal(uint8_t u8_PortNum,uint8_t u8_PortState)
{
		uint8_t u8_ErrorState = u8_DIO_OK;

		switch(u8_PortNum)
		{
			case u8_DIO_PORTA: Ru8_PORTA = u8_PortState ;  break ;			   
			case u8_DIO_PORTB: Ru8_PORTB = u8_PortState ;  break ;	
			case u8_DIO_PORTC: Ru8_PORTC = u8_PortState ;  break ;	
			case u8_DIO_PORTD: Ru8_PORTD = u8_PortState ;  break ;	
			default          : u8_ErrorState = u8_DIO_NOK; break ; 
		}
		
	return u8_ErrorState  ; 
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t DIO_u8SetPortDir(uint8_t u8_PortNum,uint8_t u8_PortDir)
{
		uint8_t u8_ErrorState = u8_DIO_OK;
		switch(u8_PortNum)
		{
			case u8_DIO_PORTA: Ru8_DDRA = u8_PortDir ;     break ;			   
			case u8_DIO_PORTB: Ru8_DDRB = u8_PortDir ;     break ;	
			case u8_DIO_PORTC: Ru8_DDRC = u8_PortDir ;     break ;	
			case u8_DIO_PORTD: Ru8_DDRD = u8_PortDir ;     break ;	
			default          : u8_ErrorState = u8_DIO_NOK; break ; 
		}
		
	return u8_ErrorState  ; 
}


////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t DIO_u8GetPinVal(uint8_t u8_PortNum,uint8_t u8_PinNum,uint8_t* pu8_ReturnedPinVal)      
{
		uint8_t u8_ErrorState = u8_DIO_OK;
		if(u8_PinNum>=u8_DIO_PIN0 && u8_PinNum<=u8_DIO_PIN7)
		{
			switch(u8_PortNum)
			{
				case u8_DIO_PORTA: (*pu8_ReturnedPinVal) = GET_BIT(Ru8_PINA,u8_PinNum)  ; break ;
				case u8_DIO_PORTB: (*pu8_ReturnedPinVal) = GET_BIT(Ru8_PINB,u8_PinNum)  ; break ;
				case u8_DIO_PORTC: (*pu8_ReturnedPinVal) = GET_BIT(Ru8_PINC,u8_PinNum)  ; break ;
				case u8_DIO_PORTD: (*pu8_ReturnedPinVal) = GET_BIT(Ru8_PIND,u8_PinNum)  ; break ;
				default          : u8_ErrorState = u8_DIO_NOK; 							 break ; 
			}
		}
		else 
		{
			u8_ErrorState = u8_DIO_NOK;
		}
	return u8_ErrorState  ; 
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t DIO_u8GetPortVal(uint8_t u8_PortNum,uint8_t* pu8_ReturnedPortVal)           
{
	uint8_t u8_ErrorState = u8_DIO_OK;

	switch(u8_PortNum)
	{
		case u8_DIO_PORTA: (*pu8_ReturnedPortVal) = Ru8_PINA ;  break ;
		case u8_DIO_PORTB: (*pu8_ReturnedPortVal) = Ru8_PINB ;  break ;
		case u8_DIO_PORTC: (*pu8_ReturnedPortVal) = Ru8_PINC ;  break ;
		case u8_DIO_PORTD: (*pu8_ReturnedPortVal) = Ru8_PIND ;  break ;
		default          :  u8_ErrorState = u8_DIO_NOK; 	    break ;
	}

	return u8_ErrorState  ; 
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t DIO_u8TogPinVal(uint8_t u8_PortNum,uint8_t u8_PinNum)           
{
		uint8_t u8_ErrorState = u8_DIO_OK;
		if(u8_PinNum>=u8_DIO_PIN0 && u8_PinNum<=u8_DIO_PIN7)
		{
			switch(u8_PortNum)
			{
				case u8_DIO_PORTA: TOG_BIT(Ru8_PORTA,u8_PinNum) ;  break ;
				case u8_DIO_PORTB: TOG_BIT(Ru8_PORTB,u8_PinNum) ;  break ;
				case u8_DIO_PORTC: TOG_BIT(Ru8_PORTC,u8_PinNum) ;  break ;
				case u8_DIO_PORTD: TOG_BIT(Ru8_PORTD,u8_PinNum) ;  break ;
				default          :  u8_ErrorState = u8_DIO_NOK;   break ; 
			}
		}
		else 
		{
			u8_ErrorState = u8_DIO_NOK;
		}
	return u8_ErrorState  ; 
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void DIO_voidDisablePullUps(void)   
{
	SET_BIT(Ru8_SFIOR,u8_PUD) ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void DIO_voidEnablePullUps(void)  
{
	CLR_BIT(Ru8_SFIOR,u8_PUD) ;
}
