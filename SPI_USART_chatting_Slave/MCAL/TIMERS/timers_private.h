/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: Timer0
 *  Layer arch : MCAL
 *  Created on: Jan 10, 2022
 *  Modified on : Jan 20, 2022
 *	version:3
 *
 */



#ifndef __TIMERS__PRIVATE__
#define __TIMERS__PRIVATE__



// Timer0 registers
#define u8_OCR0  							*((volatile uint8_t*)0x5C)
#define u8_TIMSK 							*((volatile uint8_t*)0x59)
#define u8_TIFR  							*((volatile uint8_t*)0x58)
#define u8_TCNT0 							*((volatile uint8_t*)0x52)
#define u8_TCCR0 							*((volatile uint8_t*)0x53)

//TIMER CONFIG MODES
#define u8_NORMAL_MODE										1
#define u8_CTC_MODE											3



//TCCR0 BIT NAMES 
#define u8_FOC0_BIT											7
#define u8_WGM00_BIT										6
#define u8_COM00_BIT										5
#define u8_COM01_BIT										4
#define u8_WGM01_BIT										3
#define u8_CS02_BIT											2
#define u8_CS01_BIT											1
#define u8_CS00_BIT											0

//TIFR BIT NAMES 
#define u8_OCF0_BIT											1
#define u8_TOV0_BIT											0

//TIMSK BIT NAMES
#define u8_OCIE0_BIT										1
#define u8_TOIE0_BIT										0

#define u8_NUM_OF_COUNTS_FOR_250_uS_with_8_pre 				250
#define u8_MAX_TIMER0_COUNTS								255
#define u8_NUMBER_OF_COUNTS_TO_COMP_1mS_with_8_pre			4


void void_IntWaitControlFlagCount(void) ;


#endif
