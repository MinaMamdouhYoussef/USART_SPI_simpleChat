/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: Timer0
 *  Layer arch : MCAL
 *  Created on: Jan 10, 2022
 *  Modified on : Jan 20, 2022
 *	version:3
 *
 */

		
#ifndef __timers__interface__		
#define __timers__interface__		

#include "../../LIBRARY/primitive_data_types.h"

#define u8_NO_CLK_TIMER_STOP                5
#define u8_INTERNAL_CLK_NO_PRE              6
#define u8_INTERNAL_CLK_PRE_8				7
#define u8_INTERNAL_CLK_PRE_64				8
#define u8_INTERNAL_CLK_PRE_256				9
#define u8_INTERNAL_CLK_PRE_1024			10
#define u8_EXTERNAL_CLK_FALLING				11
#define u8_EXTERNAL_CLK_RISING				12


#define u8_OC0_DISCONNECTED							13
#define u8_OC0_CLEAR_ON_COMPARE_MATCH				14
#define u8_OC0_SET_ON_COMPARE_MATCH	  				15
#define u8_TOGGLE_ON_COMPARE_MATCH					16
		
		
		
#define u8_OK										1
#define u8_NOK										0
		
		
#define u8_MAX_8BIT_REG_HOLD						255
		
		
/*choose one of timer 0 modes :- 		
 *1-u8_NORMAL_MODE							  			
 *2-u8_CTC_MODE													
 */		
#define u8_TIMER0_MODE_CONFIG 			    		u8_NORMAL_MODE
							
/* choose clock source:-							
 *1-u8_NO_CLK_TIMER_STOP   							
 *2-u8_INTERNAL_CLK_NO_PRE  						
 *3-u8_INTERNAL_CLK_PRE_8							
 *4-u8_INTERNAL_CLK_PRE_64							
 *5-u8_INTERNAL_CLK_PRE_256							
 *6-u8_INTERNAL_CLK_PRE_1024						
 *7-u8_EXTERNAL_CLK_FALLING							
 *8-u8_EXTERNAL_CLK_RISING							
 */							
#define u8_TIMER0_1_CLOCK_SELECT					u8_INTERNAL_CLK_PRE_8
		
/*OC0 config if one of pwm modes set:-		
 *1-u8_OC0_DISCONNECTED						
 *2-u8_OC0_CLEAR_ON_COMPARE_MATCH		
 *3-u8_OC0_SET_ON_COMPARE_MATCH	  		
 */		
#define u8_TIMER0_COMP_MATCH_PWM_CONFIG				u8_OC0_DISCONNECTED
		
/*OC0 config if one of non-pwm modes set:-		
 *1-u8_OC0_DISCONNECTED						
 *2-u8_TOGGLE_ON_COMPARE_MATCH		
 *3-u8_OC0_CLEAR_ON_COMPARE_MATCH		
 *4-u8_OC0_SET_ON_COMPARE_MATCH			
 */		
#define u8_TIMER0_COMP_MATCH_NON_PWM_CONFIG 		u8_OC0_DISCONNECTED
		
		


#define u8_TIMER0_OVER_FLOW							17
#define u8_TIMER0_COMPARE_ON_MATCH					18
#define u8_TIMER0_FLAG_NOT_USED						19
#define u8_TIMER0_FLAG_USED							20
#define u8_WAITING_FIRST_INT_WAIT_NOT_BEGIN			21
#define u8_FINISH_INTERRUPT_WAITING					22
#define u8_BEGIN_INTERRUPT_WAITING					23
#define u8_INTIAL_COUNTER_VAL						0
#define u8_Flag_RAISED								1
#define u8_USART_TRANSMIT_CORRECT					24



void TIMERS_voidInit(void) ; 
uint8_t TIMER0_u8StartWithclockAndPrescalerSelect(uint8_t u8_preScallerVal) ;
uint8_t TIMERS_u8ClearIntFlag(uint8_t u8_wantedIntClearFlag) ;
uint8_t TIMERS_u8GetIntFlag(uint8_t u8_wantedIntClearFlag,uint8_t* pu8_returnIntFlag) ;
uint8_t TIMERS_u8IntModesEn(uint8_t u8_wantedIntModeEn) ;
uint8_t TIMERS_u8IntModesDis(uint8_t u8_wantedIntModeDis) ;
uint8_t Timer0_u8setCompareRegTicksBeforeOV(uint8_t u8_wantedTicksToCompare) ;
uint8_t Timer0_u8setOverFlowRegTicksBeforeOV(uint8_t u8_wantedTicksBeforeOV) ;
uint8_t TIMER0_u8setCallBack(uint8_t u8_wantedISRModeToSet,void(*ISRFuncToSet)(void))  ;
void    TIMER0_voidstop(void) ;
uint8_t TIMER0_u8BusyWaitMS(uint32_t u32_BusyTimeInMilliSec) ;
uint8_t TIMER0_u8BusyWaitUS(uint32_t u32_BusyTimeInMicroSec) ; 
uint8_t TIMER0_u8InterruptWait(uint32_t u32_BusyTimeInMilliSec) ;



#endif
