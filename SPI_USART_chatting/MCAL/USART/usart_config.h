/*
 *  Author: Mina Mamdouh Youssef
 *  Driver: USART
 *  Layer arch : MCAL
 *  Created on: Jan 26, 2022
 *	version:1
 *
 */

#ifndef __USART__CONFIG__
#define __USART__CONFIG__



#define u8_USART_ENABLE							1
#define u8_USART_DISABLE						2
#define u8_USART_5BITS_TO_TRANS					3
#define u8_USART_6BITS_TO_TRANS					4
#define u8_USART_7BITS_TO_TRANS					5
#define u8_USART_8BITS_TO_TRANS					6
#define u8_USART_PARITY_DISABLE					7
#define u8_USART_PARITY_EVEN					8
#define u8_USART_PARITY_ODD						9


/* config Rx interrupt (make interrupt when data presents in the receive buffer of USART) enable by :
 * 1-u8_USART_ENABLE (to enable the interrupt of receiving data from Rx of the usart)
 * 2-u8_USART_DISABLE (to disable the interrupt of receiving data from Rx of  usart)
 */
#define u8_USART_RX_COMP_INT_STATE			u8_USART_DISABLE

/* config Tx interrupt (make int when all data in the transmit shift reg shifted ) enable by :
 * 1-u8_USART_ENABLE (to enable the interrupt of transmitting data from Tx of the usart)
 * 2-u8_USART_DISABLE (to disable the interrupt of transmitting data from Tx of  usart)
 */

#define u8_USART_TX_COMP_INT_STATE			u8_USART_DISABLE

/* config transmit buffer interrupt (make int when the data reg of the transmit is empty shifted ) enable by :
 * 1-u8_USART_ENABLE
 * 2-u8_USART_DISABLE
 */

#define u8_USART_DATA_REG_EMPTY_INT_STATE			u8_USART_DISABLE

/* config Tx state by enable or disable the transmit state (Tx state ) :
 * 1-u8_USART_ENABLE
 * 2-u8_USART_DISABLE
 */

#define u8_USART_TRANS_STATE				u8_USART_ENABLE

/* config Rx state by enable or disable the Receive state (Rx state ) :
 * 1-u8_USART_ENABLE
 * 2-u8_USART_DISABLE
 */

#define u8_USART_RECEIVE_STATE				 u8_USART_ENABLE

/*
 * Config the number of usefull data in the Transmit packet of the usart
 *1-u8_USART_5BITS_TO_TRANS
 *2-u8_USART_6BITS_TO_TRANS
 *3-u8_USART_7BITS_TO_TRANS
 *4-u8_USART_8BITS_TO_TRANS
 * */
#define u8_USART_USEFULL_DATA_IN_FRAME		u8_USART_8BITS_TO_TRANS
/*
 * Config parity state :-
 * 1-u8_USART_PARITY_DISABLE
 * 2-u8_USART_PARITY_EVEN
 * 3-u8_USART_PARITY_ODD
 * */
#define u8_USART_PARITY_CONFIG				u8_USART_PARITY_DISABLE






#define u8_USART_PORT							u8_DIO_PORTD
#define	u8_USART_RX_PIN							u8_DIO_PIN0
#define	u8_USART_TX_PIN							u8_DIO_PIN1


#endif
