#include "../../LIBRARY/primitive_data_types.h"
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/atmega32_registers.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "../TIMERS/timers_interface.h"

void SPI_voidInit(void)
{

	TIMERS_voidInit() ;

	#if u8_SPI_DATA_TRANS_ORDER == u8_SPI_LSB_TRANS_FRIST
		SET_BIT(Ru8_SPCR,u8_SPI_DORD) ;
	#elif u8_SPI_DATA_TRANS_ORDER == u8_SPI_MSB_TRANS_FRIST
		CLR_BIT(Ru8_SPCR,u8_SPI_DORD) ;
	#else
		#error "bre-build wrong config DATA_TRANS_ORDER"
	#endif


	#if u8_SPI_SELECT_SPI_MODE == u8_SPI_MASTER
		SET_BIT(Ru8_SPCR,u8_SPI_MSTR) ;
		SET_BIT(Ru8_DDRB,u8_SPI_SCK_PIN);
		CLR_BIT(Ru8_DDRB,u8_SPI_MISO_PIN);
		SET_BIT(Ru8_DDRB,u8_SPI_MOSI_PIN);
		SET_BIT(Ru8_DDRB,u8_SPI_SS_PIN);
		SET_BIT(Ru8_PORTB,u8_SPI_SS_PIN);

		//SET_BIT(Ru8_PORTB,u8_SPI_SS_PIN);
	#elif u8_SPI_SELECT_SPI_MODE == u8_SPI_SLAVE
		CLR_BIT(Ru8_SPCR,u8_SPI_MSTR) ;
		CLR_BIT(Ru8_DDRB,u8_SPI_SCK_PIN);
		SET_BIT(Ru8_DDRB,u8_SPI_MISO_PIN);
		CLR_BIT(Ru8_DDRB,u8_SPI_MOSI_PIN);
		CLR_BIT(Ru8_DDRB,u8_SPI_SS_PIN);
	#else
		#error "bre-build wrong config SELECT_SPI_MODE"
	#endif

	#if u8_SPI_CLK_OPERATION_CONFIG == u8_SPI_CLK_LEADING_RISING_EDGE
		CLR_BIT(Ru8_SPCR,u8_SPI_CPOL) ;
	#elif u8_SPI_CLK_OPERATION_CONFIG == u8_SPI_CLK_LEADING_FALLING_EDGE
		SET_BIT(Ru8_SPCR,u8_SPI_CPOL) ;
	#else
		#error "bre-build wrong config CLK_OPERATION_CONFIG"
	#endif


	#if u8_SPI_SAMPLING_OPERATION_CONFIG == u8_SPI_SAMPLE_ON_LEADING_EDGE
		CLR_BIT(Ru8_SPCR,u8_SPI_CPHA) ;
	#elif u8_SPI_SAMPLING_OPERATION_CONFIG == u8_SPI_SAMPLE_ON_TRAILLING_EDGE
		SET_BIT(Ru8_SPCR,u8_SPI_CPHA) ;
	#else
		#error "bre-build wrong config SAMPLING_OPERATION_CONFIG"
	#endif
	


	#if u8_SPI_CLK_CONFIG == u8_SPI_CLK_FSOC_BY_2
		CLR_BIT(Ru8_SPCR,u8_SPI_SPR1) ;
		CLR_BIT(Ru8_SPCR,u8_SPI_SPR0) ;
		SET_BIT(Ru8_SPSR,u8_SPI_SPI2X) ;
	#elif u8_SPI_CLK_CONFIG == u8_SPI_CLK_FSOC_BY_4
		CLR_BIT(Ru8_SPCR,u8_SPI_SPR1) ;
		CLR_BIT(Ru8_SPCR,u8_SPI_SPR0) ;
		CLR_BIT(Ru8_SPSR,u8_SPI_SPI2X) ;
	#elif u8_SPI_CLK_CONFIG == u8_SPI_CLK_FSOC_BY_8
		CLR_BIT(Ru8_SPCR,u8_SPI_SPR1) ;
		SET_BIT(Ru8_SPCR,u8_SPI_SPR0) ;
        SET_BIT(Ru8_SPSR,u8_SPI_SPI2X) ;
	#elif u8_SPI_CLK_CONFIG == u8_SPI_CLK_FSOC_BY_16
		CLR_BIT(Ru8_SPCR,u8_SPI_SPR1) ;
	    SET_BIT(Ru8_SPCR,u8_SPI_SPR0) ;
	    CLR_BIT(Ru8_SPSR,u8_SPI_SPI2X) ;
	#elif u8_SPI_CLK_CONFIG == u8_SPI_CLK_FSOC_BY_32
		SET_BIT(Ru8_SPCR,u8_SPI_SPR1) ;
	    CLR_BIT(Ru8_SPCR,u8_SPI_SPR0) ;
	    SET_BIT(Ru8_SPSR,u8_SPI_SPI2X) ;
	#elif u8_SPI_CLK_CONFIG == u8_SPI_CLK_FSOC_BY_64
		SET_BIT(Ru8_SPCR,u8_SPI_SPR1) ;
	    SET_BIT(Ru8_SPCR,u8_SPI_SPR0) ;
	    CLR_BIT(Ru8_SPSR,u8_SPI_SPI2X) ;
	#elif u8_SPI_CLK_CONFIG == u8_SPI_CLK_FSOC_BY_128
		SET_BIT(Ru8_SPCR,u8_SPI_SPR1) ;
	    SET_BIT(Ru8_SPCR,u8_SPI_SPR0) ;
	    CLR_BIT(Ru8_SPSR,u8_SPI_SPI2X) ;
	#else 
		#error "bre-build wrong config SPI_CLK_CONFIG"
	#endif

#if	u8_SPI_STATE == u8_SPI_ENABLE
	SET_BIT(Ru8_SPCR,u8_SPI_SPE) ;
#elif u8_SPI_STATE == u8_SPI_DISABLE
	CLR_BIT(Ru8_SPCR,u8_SPI_SPE) ;
#else
	#error "bre-build wrong config SPI_STATE "
#endif
	
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//function that send and receive on Byte at the same time by returning the received and take the sending in argument 
uint8_t SPI_voidMasterTransever(uint8_t u8_dataSent)
{
	CLR_BIT(Ru8_PORTB,u8_SPI_SS_PIN);

	Ru8_SPDR = u8_dataSent  ;

	while(GET_BIT(Ru8_SPSR,u8_SPI_SPIF)!=u8_SPI_FLAG_SET) ;

	SET_BIT(Ru8_PORTB,u8_SPI_SS_PIN);

	return Ru8_SPDR  ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//function that send and receive on Byte at the same time by returning the received and take the sending in argument
uint8_t SPI_voidSlaveTransever(uint8_t u8_dataSent)
{
	Ru8_SPDR = u8_dataSent ;

	while(GET_BIT(Ru8_SPSR,u8_SPI_SPIF)!=u8_SPI_FLAG_SET) ;

	Ru8_PORTC = Ru8_SPDR  ;

	return Ru8_SPDR ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//function that receive Array of bytes or string in array pointer pu8_dataReceive with array size u8_arrSize
void SPI_voidSlaveReceiveArr(uint8_t* pu8_dataReceive,uint8_t u8_arrSize)
{
	uint8_t u8_dummy, u8_indexArr = u8_SPI_INTIAL_VAL ; 
	
	while(u8_indexArr<u8_arrSize)
	{
		pu8_dataReceive[u8_indexArr] = SPI_voidSlaveTransever(u8_dummy)  ;

		if(pu8_dataReceive[u8_indexArr] == NULL_CHAR)
		{
			break ; 
		}
		++u8_indexArr ;
	}
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//function that send Array of bytes or string in array pointer pu8_dataSent with array size u8_arrSize
void SPI_voidMasterSendArr(uint8_t* pu8_dataSent,uint8_t u8_arrSize)
{
	uint8_t u8_dummy, u8_indexArr = u8_SPI_INTIAL_VAL ; 
	
	do
	{
		if(pu8_dataSent[u8_indexArr] == NULL_CHAR)
		{
			u8_dummy = SPI_voidMasterTransever(pu8_dataSent[u8_indexArr])  ;
			break ;
		}
		else 
		{
			u8_dummy = SPI_voidMasterTransever(pu8_dataSent[u8_indexArr])  ;
			++u8_indexArr ;

		}
	}while (pu8_dataSent[u8_indexArr-1] != NULL_CHAR && u8_indexArr<(u8_arrSize-1)) ;

}
