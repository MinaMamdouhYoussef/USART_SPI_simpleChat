#ifndef __SPI__PRIVATE__
#define __SPI__PRIVATE__


//SPCR bits numbers and names 
#
#define u8_SPI_SPIE							7
#define u8_SPI_SPE							6
#define u8_SPI_DORD							5
#define u8_SPI_MSTR							4
#define u8_SPI_CPOL							3
#define u8_SPI_CPHA							2
#define u8_SPI_SPR1							1
#define u8_SPI_SPR0							0

//SPSR bits numbers and names 
#define u8_SPI_SPIF							7
#define u8_SPI_WCOL							6
#define u8_SPI_SPI2X						0		


#define u8_SPI_ENABLE 						8
#define u8_SPI_DISABLE						9

#define u8_SPI_LSB_TRANS_FRIST				10
#define u8_SPI_MSB_TRANS_FRIST				11

#define u8_SPI_MASTER						12
#define u8_SPI_SLAVE						13


#define u8_SPI_CLK_LEADING_RISING_EDGE		14
#define u8_SPI_CLK_LEADING_FALLING_EDGE		15


#define u8_SPI_SAMPLE_ON_LEADING_EDGE		16
#define u8_SPI_SAMPLE_ON_TRAILLING_EDGE		17


#define u8_SPI_CLK_FSOC_BY_2				18
#define u8_SPI_CLK_FSOC_BY_4				19
#define u8_SPI_CLK_FSOC_BY_8				20
#define u8_SPI_CLK_FSOC_BY_16				21
#define u8_SPI_CLK_FSOC_BY_32				22
#define u8_SPI_CLK_FSOC_BY_64				23
#define u8_SPI_CLK_FSOC_BY_128				24

#define u8_SPI_FLAG_SET						1
#define u8_SPI_INTIAL_VAL					0

#endif 