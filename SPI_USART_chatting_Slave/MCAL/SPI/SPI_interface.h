#ifndef	__SPI__INTERFACE__
#define __SPI__INTERFACE__


void SPI_voidInit(void) ;

//function that send and receive on Byte at the same time by returning the received and take the sending in argument
uint8_t SPI_voidMasterTransever(uint8_t u8_dataSent) ;

uint8_t SPI_voidSlaveTransever(uint8_t u8_dataSent) ;

//function that receive Array of bytes or string in array pointer pu8_dataReceive with array size u8_arrSize
void SPI_voidSlaveReceiveArr(uint8_t* pu8_dataReceive,uint8_t u8_arrSize) ;

//function that send Array of bytes or string in array pointer pu8_dataSent with array size u8_arrSize
void SPI_voidMasterSendArr(uint8_t* pu8_dataSent,uint8_t u8_arrSize) ;

#endif
