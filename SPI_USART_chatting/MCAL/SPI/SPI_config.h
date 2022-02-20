#ifndef __SPI__CONFIG__
#define __SPI__CONFIG__
#include "SPI_private.h"
/*
 *choose spi state to make it on or off :-
 *1- u8_SPI_ENABLE  
 *2- u8_SPI_DISABLE
 */
#define u8_SPI_STATE						u8_SPI_ENABLE

/*
 *choose which to transmit first LSB or MSB from SPDR:- 
 *1- u8_SPI_LSB_TRANS_FRIST
 *2- u8_SPI_MSB_TRANS_FRIST
 */
#define u8_SPI_DATA_TRANS_ORDER				u8_SPI_MSB_TRANS_FRIST
/*
 * choose MCU used this SPI driver in is :-
 * 1- u8_SPI_MASTER
 * 2- u8_SPI_SLAVE
 */
#define u8_SPI_SELECT_SPI_MODE				u8_SPI_MASTER
/*
 *choose IDLE state of SPI (LEADING and TRAILLING EDGES of SPI )
 *1- u8_SPI_CLK_LEADING_RISING_EDGE
 *2- u8_SPI_CLK_LEADING_FALLING_EDGE
 */
#define u8_SPI_CLK_OPERATION_CONFIG			u8_SPI_CLK_LEADING_RISING_EDGE
/*
 *choose Sampling Edge of SPI :-
 *1- u8_SPI_SAMPLE_ON_LEADING_EDGE
 *2- u8_SPI_SAMPLE_ON_TRAILLING_EDGE
 */
#define u8_SPI_SAMPLING_OPERATION_CONFIG	u8_SPI_SAMPLE_ON_LEADING_EDGE
/*
 *choose relation between Fsoc and SPI CLk
 *1- u8_SPI_CLK_FSOC_BY_2
 *2- u8_SPI_CLK_FSOC_BY_4
 *3- u8_SPI_CLK_FSOC_BY_8
 *4- u8_SPI_CLK_FSOC_BY_16
 *5- u8_SPI_CLK_FSOC_BY_32
 *6- u8_SPI_CLK_FSOC_BY_64
 *7- u8_SPI_CLK_FSOC_BY_128
 */
#define u8_SPI_CLK_CONFIG					 u8_SPI_CLK_FSOC_BY_64


#define u8_SPI_SCK_PIN						7
#define u8_SPI_MISO_PIN						6
#define u8_SPI_MOSI_PIN						5
#define u8_SPI_SS_PIN						4



#endif
