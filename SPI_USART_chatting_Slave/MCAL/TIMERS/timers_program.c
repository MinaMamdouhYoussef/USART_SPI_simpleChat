/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: Timer0
 *  Layer arch : MCAL
 *  Created on: Jan 10, 2022
 *  Modified on : Jan 15, 2022
 *	version:3
 *
 */

#include "../../LIBRARY/primitive_data_types.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/atmega32_registers.h"
#include "timers_private.h"
#include "timers_interface.h"

static void (*Timer0CompareMatchSetCallBackISR)(void) = NULL_POINTER; 
static void (*Timer0OverFlowSetCallBackISR)(void) = NULL_POINTER; 

uint8_t gu8_FinishIntWaitFlag = u8_WAITING_FIRST_INT_WAIT_NOT_BEGIN ;
static uint8_t gu8_FlagIfTimer0Used = u8_TIMER0_FLAG_NOT_USED ;
static uint64_t gu64_IntWaitcounter = u8_INTIAL_COUNTER_VAL ;


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////


void TIMERS_voidInit(void)
{
	#if	u8_TIMER0_MODE_CONFIG==u8_NORMAL_MODE
		CLR_BIT(Ru8_TCCR0,u8_WGM00_BIT) ;
		CLR_BIT(Ru8_TCCR0,u8_WGM01_BIT) ;
		CLR_BIT(Ru8_TCCR0,u8_FOC0_BIT) ;
	#elif u8_TIMER0_MODE_CONFIG==u8_CTC_MODE
		CLR_BIT(Ru8_TCCR0,u8_WGM00_BIT) ;
		SET_BIT(Ru8_TCCR0,u8_WGM01_BIT) ;
		CLR_BIT(Ru8_TCCR0,u8_FOC0_BIT) ;
	#else
		#error "error in prebuild timer0 config"
	#endif
	
	
	
	#if	u8_TIMER0_MODE_CONFIG==u8_NORMAL_MODE||u8_TIMER0_MODE_CONFIG==u8_CTC_MODE
		#if u8_TIMER0_COMP_MATCH_NON_PWM_CONFIG==u8_OC0_DISCONNECTED
			CLR_BIT(Ru8_TCCR0,u8_COM00_BIT) ;
			CLR_BIT(Ru8_TCCR0,u8_COM01_BIT) ;
		#elif u8_TIMER0_COMP_MATCH_NON_PWM_CONFIG==u8_TOGGLE_ON_COMPARE_MATCH
			SET_BIT(Ru8_TCCR0,u8_COM00_BIT) ;
			CLR_BIT(Ru8_TCCR0,u8_COM01_BIT) ;
		#elif u8_TIMER0_COMP_MATCH_NON_PWM_CONFIG==u8_OC0_CLEAR_ON_COMPARE_MATCH
			CLR_BIT(Ru8_TCCR0,u8_COM00_BIT) ;
			SET_BIT(Ru8_TCCR0,u8_COM01_BIT) ;
		#elif u8_TIMER0_COMP_MATCH_NON_PWM_CONFIG==u8_OC0_SET_ON_COMPARE_MATCH
			SET_BIT(Ru8_TCCR0,u8_COM00_BIT) ;
			SET_BIT(Ru8_TCCR0,u8_COM01_BIT) ;
		#else 
			#error "oc0 config error "
		#endif
		
	#else 
		#error "error in prebuild timer0 config"
	#endif
	
	
	#if u8_TIMER0_1_CLOCK_SELECT==u8_NO_CLK_TIMER_STOP
		CLR_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
		CLR_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
		CLR_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
	#elif u8_TIMER0_1_CLOCK_SELECT==u8_INTERNAL_CLK_NO_PRE
		CLR_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
		CLR_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
		SET_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
	#elif u8_TIMER0_1_CLOCK_SELECT==u8_INTERNAL_CLK_PRE_8
		CLR_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
		SET_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
		CLR_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
	#elif u8_TIMER0_1_CLOCK_SELECT==u8_INTERNAL_CLK_PRE_64
		CLR_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
		SET_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
		SET_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
	#elif u8_TIMER0_1_CLOCK_SELECT==u8_INTERNAL_CLK_PRE_256
		SET_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
		CLR_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
		CLR_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
	#elif u8_TIMER0_1_CLOCK_SELECT==u8_INTERNAL_CLK_PRE_1024
		SET_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
		CLR_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
		SET_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
	#elif u8_TIMER0_1_CLOCK_SELECT==u8_EXTERNAL_CLK_FALLING
		SET_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
		SET_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
		CLR_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
	#elif u8_TIMER0_1_CLOCK_SELECT==u8_EXTERNAL_CLK_RISING
		SET_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
		SET_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
		SET_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
	#else
		#error "wrong clock select config"
	#endif

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t TIMER0_u8StartWithclockAndPrescalerSelect(uint8_t u8_preScallerVal) 
{
	uint8_t u8_ErrorFlag = u8_OK ; 
	switch(u8_preScallerVal)
	{
		case u8_INTERNAL_CLK_NO_PRE:
			CLR_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
			CLR_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
			SET_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
			break ; 
		case u8_INTERNAL_CLK_PRE_8:
			CLR_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
			SET_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
			CLR_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
			break ; 
		case u8_INTERNAL_CLK_PRE_64:
			CLR_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
			SET_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
			SET_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
			break ;
		case u8_INTERNAL_CLK_PRE_256:
			SET_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
			CLR_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
			CLR_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
			break ; 
		case u8_INTERNAL_CLK_PRE_1024:
			SET_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
			CLR_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
			SET_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
			break ;
		case u8_EXTERNAL_CLK_FALLING : 
			SET_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
			SET_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
			CLR_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
			break ;
		case u8_EXTERNAL_CLK_RISING:
			SET_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
			SET_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
			SET_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
			break ; 
		
		default : u8_ErrorFlag = u8_NOK ; 
		break ;
	}
	return u8_ErrorFlag ; 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void TIMER0_voidstop(void)
{
	CLR_BIT(Ru8_TCCR0,u8_CS02_BIT) ;
	CLR_BIT(Ru8_TCCR0,u8_CS01_BIT) ;
	CLR_BIT(Ru8_TCCR0,u8_CS00_BIT) ;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t TIMERS_u8ClearIntFlag(uint8_t u8_wantedIntClearFlag)
{
		uint8_t u8_ErrorFlag = u8_OK ; 
	switch(u8_wantedIntClearFlag)
	{
		case u8_TIMER0_OVER_FLOW			: SET_BIT(Ru8_TIFR,u8_TOV0_BIT) ;
											  break ;
		case u8_TIMER0_COMPARE_ON_MATCH		: SET_BIT(Ru8_TIFR,u8_OCF0_BIT) ;
											  break ;
		default								: u8_ErrorFlag = u8_NOK ;
											  break ; 
	}
	return u8_ErrorFlag ; 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t TIMERS_u8GetIntFlag(uint8_t u8_wantedIntClearFlag,uint8_t* pu8_retturnIntFlag)
{
		uint8_t u8_ErrorFlag = u8_OK ; 
	switch(u8_wantedIntClearFlag)
	{
		case u8_TIMER0_OVER_FLOW			: (*pu8_retturnIntFlag) = GET_BIT(Ru8_TIFR,u8_TOV0_BIT) ;
											  break ;
		case u8_TIMER0_COMPARE_ON_MATCH		: (*pu8_retturnIntFlag) = GET_BIT(Ru8_TIFR,u8_OCF0_BIT) ;
											  break ;
		default								: u8_ErrorFlag = u8_NOK ;
											  break ; 
	}
	return u8_ErrorFlag ; 
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t TIMERS_u8IntModesEn(uint8_t u8_wantedIntModeEn)
{
	uint8_t u8_ErrorFlag = u8_OK ; 
	switch(u8_wantedIntModeEn)
	{
		case u8_TIMER0_OVER_FLOW			:  SET_BIT(Ru8_TIFR,u8_TOV0_BIT) ;
											   SET_BIT(Ru8_TIMSK,u8_TOIE0_BIT);
											   break ; 
		case u8_TIMER0_COMPARE_ON_MATCH		:  SET_BIT(Ru8_TIFR,u8_OCF0_BIT) ;
											   SET_BIT(Ru8_TIMSK,u8_OCIE0_BIT);
											   break ;
		default 							:  u8_ErrorFlag = u8_NOK ; 
											   break ; 
	}
	return u8_ErrorFlag ; 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t TIMERS_u8IntModesDis(uint8_t u8_wantedIntModeDis)
{
	uint8_t u8_ErrorFlag = u8_OK ; 
	switch(u8_wantedIntModeDis)
	{
		case u8_TIMER0_OVER_FLOW			:  CLR_BIT(Ru8_TIMSK,u8_TOIE0_BIT);
											   break ; 
		case u8_TIMER0_COMPARE_ON_MATCH		:  CLR_BIT(Ru8_TIMSK,u8_OCIE0_BIT);
											   break ;
		default 							:  u8_ErrorFlag = u8_NOK ; 
											   break ; 
	}
	return u8_ErrorFlag ; 
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t Timer0_u8setOverFlowRegTicksBeforeOV(uint8_t u8_wantedTicksBeforeOV)
{
	uint8_t u8_ErrorFlag = u8_OK ; 
	uint8_t u8_SetTimer0CounterReg ; 
	if(u8_wantedTicksBeforeOV<=u8_MAX_8BIT_REG_HOLD)
	{
		u8_SetTimer0CounterReg = u8_MAX_8BIT_REG_HOLD-u8_wantedTicksBeforeOV ; 
		Ru8_TCNT0=u8_SetTimer0CounterReg ;
	}
	else 
	{
		u8_ErrorFlag = u8_NOK ; 
	}
	return u8_ErrorFlag ; 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t Timer0_u8setCompareRegTicksBeforeOV(uint8_t u8_wantedTicksToCompare)
{
	uint8_t u8_ErrorFlag = u8_OK ; 
	if(u8_wantedTicksToCompare<=u8_MAX_8BIT_REG_HOLD)
	{
		Ru8_OCR0 = u8_wantedTicksToCompare ;
	}
	else 
	{
		u8_ErrorFlag = u8_NOK ; 
	}
	return u8_ErrorFlag ; 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t TIMER0_u8setCallBack(uint8_t u8_wantedISRModeToSet,void(*ISRFuncToSet)(void)) 
{
	uint8_t u8_ErrorFlag = u8_OK ; 
	if(ISRFuncToSet!=NULL_POINTER)
	{
		switch(u8_wantedISRModeToSet)
		{
			case u8_TIMER0_OVER_FLOW			:  Timer0OverFlowSetCallBackISR = ISRFuncToSet ; 
												   break ; 
			case u8_TIMER0_COMPARE_ON_MATCH		:  Timer0CompareMatchSetCallBackISR = ISRFuncToSet ; 
											       break ;
			default 							:  u8_ErrorFlag = u8_NOK ; 
											       break ; 
		}
	}
	else 
	{
		u8_ErrorFlag = u8_NOK ; 
	}
	return u8_ErrorFlag ; 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void __vector_10 (void)      __attribute__((signal));
void __vector_10 (void)
{
	if(Timer0CompareMatchSetCallBackISR!=NULL_POINTER)
	{
		Timer0CompareMatchSetCallBackISR();
	}
	else 
	{
		//do nothing
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void __vector_11 (void)      __attribute__((signal));
void __vector_11 (void)
{
	if(Timer0OverFlowSetCallBackISR!=NULL_POINTER)
	{
		Timer0OverFlowSetCallBackISR() ;
	}
	else 
	{
		//do nothing
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//busy wait with prescaller 8
uint8_t TIMER0_u8BusyWaitMS(uint32_t u32_BusyTimeInMilliSec)
{
	uint8_t u8_Timer0FlagIfUsed = u8_TIMER0_FLAG_NOT_USED ;
	if(gu8_FlagIfTimer0Used== u8_TIMER0_FLAG_NOT_USED)
	{
		volatile uint64_t u64_BusyWaitcounter = u8_INTIAL_COUNTER_VAL ;
		volatile uint8_t u8_CheckCompareFlag ;
		TIMERS_u8IntModesDis(u8_TIMER0_OVER_FLOW) ;
		TIMERS_u8IntModesDis(u8_TIMER0_COMPARE_ON_MATCH) ;
		TIMER0_u8StartWithclockAndPrescalerSelect(u8_INTERNAL_CLK_PRE_8) ;
		TIMERS_u8ClearIntFlag(u8_TIMER0_COMPARE_ON_MATCH) ;
		Timer0_u8setCompareRegTicksBeforeOV(u8_NUM_OF_COUNTS_FOR_250_uS_with_8_pre) ;
		Timer0_u8setOverFlowRegTicksBeforeOV(u8_MAX_TIMER0_COUNTS) ;
		while(u64_BusyWaitcounter <=(uint64_t)(u32_BusyTimeInMilliSec*u8_NUMBER_OF_COUNTS_TO_COMP_1mS_with_8_pre))
		{
			TIMERS_u8GetIntFlag(u8_TIMER0_COMPARE_ON_MATCH,(&u8_CheckCompareFlag)) ;
			if(u8_CheckCompareFlag == u8_Flag_RAISED )
			{
				TIMERS_u8ClearIntFlag(u8_TIMER0_COMPARE_ON_MATCH) ;
				u64_BusyWaitcounter++ ;
			}
		}
	}
	else
	{
		u8_Timer0FlagIfUsed = u8_TIMER0_FLAG_USED ;
	}
	return u8_Timer0FlagIfUsed ;
	
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//busy wait with prescaller 8
uint8_t TIMER0_u8BusyWaitUS(uint32_t u32_BusyTimeInMicroSec)
{
	uint8_t u8_Timer0FlagIfUsed = u8_TIMER0_FLAG_NOT_USED ;
	if(gu8_FlagIfTimer0Used== u8_TIMER0_FLAG_NOT_USED)
	{
		volatile uint32_t u32_BusyWaitcounter = u8_INTIAL_COUNTER_VAL ;
		volatile uint8_t u8_CheckCompareFlag ;
		TIMERS_u8IntModesDis(u8_TIMER0_OVER_FLOW) ;
		TIMERS_u8IntModesDis(u8_TIMER0_COMPARE_ON_MATCH) ;
		TIMER0_u8StartWithclockAndPrescalerSelect(u8_INTERNAL_CLK_PRE_8) ;
		TIMERS_u8ClearIntFlag(u8_TIMER0_COMPARE_ON_MATCH) ;
		Timer0_u8setCompareRegTicksBeforeOV(u8_NUM_OF_COUNTS_FOR_250_uS_with_8_pre) ;
		Timer0_u8setOverFlowRegTicksBeforeOV(u8_MAX_TIMER0_COUNTS) ;
		while(u32_BusyWaitcounter <=u32_BusyTimeInMicroSec)
		{
			TIMERS_u8GetIntFlag(u8_TIMER0_COMPARE_ON_MATCH,(&u8_CheckCompareFlag)) ;
			if(u8_CheckCompareFlag == u8_Flag_RAISED )
			{
				TIMERS_u8ClearIntFlag(u8_TIMER0_COMPARE_ON_MATCH) ;
				u32_BusyWaitcounter++ ;
			}
		}
	}
	else
	{
		u8_Timer0FlagIfUsed = u8_TIMER0_FLAG_USED ;
	}
	return u8_Timer0FlagIfUsed ;
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t TIMER0_u8InterruptWait(uint32_t u32_BusyTimeInMilliSec)
{
	uint8_t u8_Timer0FlagIfUsed = u8_TIMER0_FLAG_NOT_USED ;
	if(gu8_FlagIfTimer0Used==u8_TIMER0_FLAG_NOT_USED &&gu8_FinishIntWaitFlag != u8_BEGIN_INTERRUPT_WAITING )
	{
		gu64_IntWaitcounter = (uint64_t)(u32_BusyTimeInMilliSec*u8_NUMBER_OF_COUNTS_TO_COMP_1mS_with_8_pre) ;
		Timer0_u8setCompareRegTicksBeforeOV(u8_NUM_OF_COUNTS_FOR_250_uS_with_8_pre) ;
		Timer0_u8setOverFlowRegTicksBeforeOV(u8_MAX_TIMER0_COUNTS) ;
		gu8_FlagIfTimer0Used = u8_TIMER0_FLAG_USED ;
		TIMERS_u8IntModesEn(u8_TIMER0_COMPARE_ON_MATCH);
		TIMER0_u8setCallBack(u8_TIMER0_COMPARE_ON_MATCH,void_IntWaitControlFlagCount) ;
		TIMER0_u8StartWithclockAndPrescalerSelect(u8_INTERNAL_CLK_PRE_8) ;
		gu8_FinishIntWaitFlag = u8_BEGIN_INTERRUPT_WAITING ;

	}
	else
	{
		u8_Timer0FlagIfUsed = u8_TIMER0_FLAG_USED ;
	}
	return u8_Timer0FlagIfUsed ;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void void_IntWaitControlFlagCount(void)
{

	if(gu8_FlagIfTimer0Used==u8_TIMER0_FLAG_USED&&gu64_IntWaitcounter > u8_INTIAL_COUNTER_VAL)
	{
		gu64_IntWaitcounter-- ;
	}
	else
	{
		gu8_FlagIfTimer0Used = u8_TIMER0_FLAG_NOT_USED ;
		gu8_FinishIntWaitFlag = u8_FINISH_INTERRUPT_WAITING ;
	}
}
