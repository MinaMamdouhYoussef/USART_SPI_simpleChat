/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: USART
 *  Layer arch : MCAL
 *  Created on: Jan 26, 2022
 *	version:1
 *
 */


#include "../../LIBRARY/primitive_data_types.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/atmega32_registers.h"
#include "../TIMERS/timers_interface.h"
#include "../DIO/dio_interface.h"
#include "usart_config.h"
#include "usart_private.h"
#include "usart_interface.h"


extern uint8_t gu8_FinishIntWaitFlag ;  


void USART_voidInit(void) 
{
	TIMERS_voidInit();
	CLR_BIT(Ru8_UCSRA,u8_USART_UDRE);
	CLR_BIT(Ru8_UCSRA,u8_USART_FE);
	CLR_BIT(Ru8_UCSRA,u8_USART_DOR);
	CLR_BIT(Ru8_UCSRA,u8_USART_PE);

	//U2X is disabled 
	CLR_BIT(Ru8_UCSRA,u8_USART_U2X);
	//multiprocessor (Master-Slave) disabled
	CLR_BIT(Ru8_UCSRA,u8_USART_MPCM);
	

    DIO_u8SetPinDir(u8_USART_PORT,u8_USART_RX_PIN,u8_DIO_INPUT_PIN);
	DIO_u8SetPinDir(u8_USART_PORT,u8_USART_TX_PIN,u8_DIO_OUTPUT_PIN);
	
	//DIO_u8SetPinVal(u8_USART_PORT,u8_USART_RX_PIN,u8_DIO_PIN_HIGH);
	DIO_u8SetPinVal(u8_USART_PORT,u8_USART_TX_PIN,u8_DIO_PIN_HIGH);
	
	#if u8_USART_RX_COMP_INT_STATE==u8_USART_ENABLE
		SET_BIT(Ru8_UCSRB,u8_USART_RXCIE) ; 
	#elif u8_USART_RX_COMP_INT_STATE==u8_USART_DISABLE
		CLR_BIT(Ru8_UCSRB,u8_USART_RXCIE) ; 
	#else 
		#error "Pre-build config error in set Rx int state "
	#endif
	
	
	#if u8_USART_TX_COMP_INT_STATE==u8_USART_ENABLE
		SET_BIT(Ru8_UCSRB,u8_USART_TXCIE) ; 
	#elif u8_USART_TX_COMP_INT_STATE==u8_USART_DISABLE
		CLR_BIT(Ru8_UCSRB,u8_USART_TXCIE) ; 
	#else
		#error "Pre-build config error in set Tx int state"
	#endif
	
	
	#if u8_USART_DATA_REG_EMPTY_INT_STATE==u8_USART_ENABLE
		SET_BIT(Ru8_UCSRB,u8_USART_UDRIE) ; 
	#elif u8_USART_DATA_REG_EMPTY_INT_STATE== u8_USART_DISABLE
		CLR_BIT(Ru8_UCSRB,u8_USART_UDRIE) ; 
	#else
		#error "Pre-build config error in set Data Reg Empty int state"
	#endif
	
	
	#if u8_USART_TRANS_STATE==u8_USART_ENABLE 
		SET_BIT(Ru8_UCSRB,u8_USART_TXEN) ; 
	#elif u8_USART_TRANS_STATE== u8_USART_DISABLE
		CLR_BIT(Ru8_UCSRB,u8_USART_TXEN) ; 		
	#else 
		#error "Pre-build config error in set Transmit state"
	#endif
	
	
	
	#if u8_USART_RECEIVE_STATE==u8_USART_ENABLE
		SET_BIT(Ru8_UCSRB,u8_USART_RXEN) ; 
	#elif u8_USART_RECEIVE_STATE==u8_USART_DISABLE
		CLR_BIT(Ru8_UCSRB,u8_USART_RXEN) ; 
	#else 
		#error "Pre-build config error in set Receive state"
	#endif
	
	
	
	#if u8_USART_USEFULL_DATA_IN_FRAME==u8_USART_5BITS_TO_TRANS
		#if u8_USART_PARITY_CONFIG==u8_USART_PARITY_DISABLE
			Ru8_UBRRH_UCSRC = ((u8_USART_SET<<u8_USART_URSEL) | (u8_USART_SET<<u8_USART_USBS)) ; 
			CLR_BIT(Ru8_UCSRB,u8_USART_UCSZ2) ; 
		#elif u8_USART_PARITY_CONFIG==u8_USART_PARITY_EVEN
			Ru8_UBRRH_UCSRC = ((u8_USART_SET<<u8_USART_URSEL) |(u8_USART_SET<<u8_USART_UPM1)|(u8_USART_SET<<u8_USART_USBS)) ; 
			CLR_BIT(Ru8_UCSRB,u8_USART_UCSZ2) ; 
		#elif u8_USART_PARITY_CONFIG==u8_USART_PARITY_ODD
			Ru8_UBRRH_UCSRC = ((u8_USART_SET<<u8_USART_URSEL) |(u8_USART_SET<<u8_USART_UPM1)
							  |(u8_USART_SET<<u8_USART_UPM0)|(u8_USART_SET<<u8_USART_USBS)) ; 
			CLR_BIT(Ru8_UCSRB,u8_USART_UCSZ2) ; 
		#else 
			#error "Pre-build config error in set Parity Config"
		#endif
		
	#elif u8_USART_USEFULL_DATA_IN_FRAME==u8_USART_6BITS_TO_TRANS
		#if u8_USART_PARITY_CONFIG==u8_USART_PARITY_DISABLE
			Ru8_UBRRH_UCSRC = ((u8_USART_SET<<u8_USART_URSEL) | (u8_USART_SET<<u8_USART_USBS)| (u8_USART_SET<<u8_USART_UCSZ0)) ; 
			CLR_BIT(Ru8_UCSRB,u8_USART_UCSZ2) ; 
		#elif u8_USART_PARITY_CONFIG==u8_USART_PARITY_EVEN
			Ru8_UBRRH_UCSRC = ((u8_USART_SET<<u8_USART_URSEL) |(u8_USART_SET<<u8_USART_UPM1)
							   |(u8_USART_SET<<u8_USART_USBS)| (u8_USART_SET<<u8_USART_UCSZ0)) ; 
			CLR_BIT(Ru8_UCSRB,u8_USART_UCSZ2) ; 
		#elif u8_USART_PARITY_CONFIG==u8_USART_PARITY_ODD
			Ru8_UBRRH_UCSRC = ((u8_USART_SET<<u8_USART_URSEL) |(u8_USART_SET<<u8_USART_UPM1)
							  |(u8_USART_SET<<u8_USART_UPM0)|(u8_USART_SET<<u8_USART_USBS)| (u8_USART_SET<<u8_USART_UCSZ0)) ; 
			CLR_BIT(Ru8_UCSRB,u8_USART_UCSZ2) ; 
		#else 
			#error "Pre-build config error in set Parity Config"
		#endif
		
	#elif u8_USART_USEFULL_DATA_IN_FRAME==u8_USART_7BITS_TO_TRANS
		#if u8_USART_PARITY_CONFIG==u8_USART_PARITY_DISABLE
			Ru8_UBRRH_UCSRC = ((u8_USART_SET<<u8_USART_URSEL) | (u8_USART_SET<<u8_USART_USBS)| (u8_USART_SET<<u8_USART_UCSZ1)) ; 
			CLR_BIT(Ru8_UCSRB,u8_USART_UCSZ2) ; 
		#elif u8_USART_PARITY_CONFIG==u8_USART_PARITY_EVEN
			Ru8_UBRRH_UCSRC = ((u8_USART_SET<<u8_USART_URSEL) |(u8_USART_SET<<u8_USART_UPM1)
								|(u8_USART_SET<<u8_USART_USBS)|| (u8_USART_SET<<u8_USART_UCSZ1)) ; 
			CLR_BIT(Ru8_UCSRB,u8_USART_UCSZ2) ; 
		#elif u8_USART_PARITY_CONFIG==u8_USART_PARITY_ODD
			Ru8_UBRRH_UCSRC = ((u8_USART_SET<<u8_USART_URSEL) |(u8_USART_SET<<u8_USART_UPM1)
							  |(u8_USART_SET<<u8_USART_UPM0)|(u8_USART_SET<<u8_USART_USBS)| (u8_USART_SET<<u8_USART_UCSZ1)) ; 
			CLR_BIT(Ru8_UCSRB,u8_USART_UCSZ2) ; 
		#else 
			#error "Pre-build config error in set Parity Config"
		#endif
	#elif u8_USART_USEFULL_DATA_IN_FRAME==u8_USART_8BITS_TO_TRANS
		#if u8_USART_PARITY_CONFIG==u8_USART_PARITY_DISABLE
			Ru8_UBRRH_UCSRC = ((u8_USART_SET<<u8_USART_URSEL)
							  |(u8_USART_SET<<u8_USART_UCSZ1) |(u8_USART_SET<<u8_USART_UCSZ0)) ; 
			CLR_BIT(Ru8_UCSRB,u8_USART_UCSZ2) ; 
		#elif u8_USART_PARITY_CONFIG==u8_USART_PARITY_EVEN
			Ru8_UBRRH_UCSRC = ((u8_USART_SET<<u8_USART_URSEL) |(u8_USART_SET<<u8_USART_UPM1)
							   |(u8_USART_SET<<u8_USART_USBS) |(u8_USART_SET<<u8_USART_UCSZ1)|(u8_USART_SET<<u8_USART_UCSZ0)) ; 
			CLR_BIT(Ru8_UCSRB,u8_USART_UCSZ2) ; 
		#elif u8_USART_PARITY_CONFIG==u8_USART_PARITY_ODD
			Ru8_UBRRH_UCSRC = ((u8_USART_SET<<u8_USART_URSEL) |(u8_USART_SET<<u8_USART_UPM1) |(u8_USART_SET<<u8_USART_UPM0)
							  |(u8_USART_SET<<u8_USART_USBS)  |(u8_USART_SET<<u8_USART_UCSZ1)|(u8_USART_SET<<u8_USART_UCSZ0)) ; 
			CLR_BIT(Ru8_UCSRB,u8_USART_UCSZ2) ; 
		#else 
			#error "Pre-build config error in set Parity Config"
		#endif
	#else 
		#error "Pre-build config error in set Trans usefull data size "
	#endif 
	
		
	Ru8_UBRRL = u8_USART_BAUD_RATE_9600;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t USART_u8TransData(uint8_t u8_DataSent)
{
	uint8_t u8_DataState = u8_USART_DATA_NOT_SENT ;
	TIMERS_u8IntModesEn(u8_TIMER0_COMPARE_ON_MATCH) ;
	TIMER0_u8InterruptWait(u8_MAX_WAIT_IN_MS) ;
	while(gu8_FinishIntWaitFlag!=u8_FINISH_INTERRUPT_WAITING)
	{
		if(GET_BIT(Ru8_UCSRA,u8_USART_UDRE)==u8_USART_DATA_REG_EMPTY)
		{
			Ru8_UDR = u8_DataSent ;
			SET_BIT(Ru8_UCSRA,u8_USART_TXC) ;
			u8_DataState = u8_USART_DATA_SENT ;
			break ;
		}

	}

	TIMERS_u8IntModesDis(u8_TIMER0_COMPARE_ON_MATCH) ;
	return  u8_DataState ; 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t USART_u8ReceiveData(uint8_t* pu8_DataReceive)
{
	uint8_t u8_ReturnReciveState = u8_USART_NOT_RECEIVED ;   
	if(pu8_DataReceive!=NULL_POINTER)
	{
		TIMERS_u8IntModesEn(u8_TIMER0_COMPARE_ON_MATCH) ;
		TIMER0_u8InterruptWait(u8_MAX_WAIT_IN_MS) ;
		while(gu8_FinishIntWaitFlag!=u8_FINISH_INTERRUPT_WAITING)
		{
			if(GET_BIT(Ru8_UCSRA,u8_USART_RXC)==u8_USART_FLAG_SET)
			{
				if(GET_BIT(Ru8_UCSRA,u8_USART_FE)==u8_USART_FLAG_SET)
				{
					u8_ReturnReciveState = u8_USART_FRAME_ERROR ; 
				}
				else if((GET_BIT(Ru8_UCSRA,u8_USART_DOR)==u8_USART_FLAG_SET))
				{
					u8_ReturnReciveState = u8_USART_DATA_OVER_RUN ; 
				}
				else if((GET_BIT(Ru8_UCSRA,u8_USART_PE)==u8_USART_FLAG_SET) && (u8_USART_PARITY_CONFIG != u8_USART_PARITY_DISABLE))
				{
					u8_ReturnReciveState = u8_USART_PARITY_ERROR ; 
				}
				else 
				{
					u8_ReturnReciveState = u8_USART_RECEIVED_CORRECT ; 
				}
				*pu8_DataReceive = Ru8_UDR ;
				break ;
			}
		}
		TIMERS_u8IntModesDis(u8_TIMER0_COMPARE_ON_MATCH) ;
	}
	else
	{
		u8_ReturnReciveState = u8_USART_RECEIVED_NULL_PTR_ARG ;  
	}
	return u8_ReturnReciveState ;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t USART_u8TransStr(uint8_t* pu8_StrSent)
{
	uint8_t u8_ReturnTransState = u8_USART_DATA_SENT , u8_indexArr = u8_INTIAL_COUNTER_VAL;

	if(pu8_StrSent != NULL_POINTER)
	{
		while(pu8_StrSent[u8_indexArr] !=NULL_CHAR && u8_ReturnTransState == u8_USART_DATA_SENT)
		{
			u8_ReturnTransState = USART_u8TransData(pu8_StrSent[u8_indexArr])  ;
			u8_indexArr++ ;
		}

	}
	else
	{
		u8_ReturnTransState = u8_USART_DATA_NOT_SENT ;
	}

	return  u8_ReturnTransState ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t USART_u8ReceiveStr(uint8_t* pu8_StrReceive, uint8_t u8_strSize,uint8_t u8_terminator)
{
	uint8_t u8_ReturnTransState = u8_USART_RECEIVED_CORRECT , u8_indexArr = u8_INTIAL_COUNTER_VAL;
	if(pu8_StrReceive != NULL_POINTER)
	{
		do
		{
			if(u8_ReturnTransState==u8_USART_RECEIVED_CORRECT)
			{
				u8_ReturnTransState = USART_u8ReceiveData(&(pu8_StrReceive[u8_indexArr]))  ;
				u8_indexArr++ ;
			}
			else
			{
				u8_ReturnTransState = u8_USART_NOT_RECEIVED ;
 				break ;
			}
		}while(pu8_StrReceive[u8_indexArr-1] != u8_terminator && (u8_indexArr<u8_strSize)) ;

		pu8_StrReceive[u8_indexArr-1] = NULL_CHAR ;
	}
	else
	{
		u8_ReturnTransState = u8_USART_RECEIVED_NULL_PTR_ARG ;
	}
	return u8_ReturnTransState ;
}

