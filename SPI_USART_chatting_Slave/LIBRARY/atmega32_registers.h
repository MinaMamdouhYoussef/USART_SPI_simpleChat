#ifndef __ATMEG32__REGISTERS__
#define __ATMEG32__REGISTERS__


#define Ru8_SREG			 *((volatile uint8_t*)0x5F)
#define Ru8_SPH              *((volatile uint8_t*)0x5E)
#define Ru8_SPL              *((volatile uint8_t*)0x5D)

#define Ru8_OCR0             *((volatile uint8_t*)0x5C)
#define Ru8_TIMSK            *((volatile uint8_t*)0x59)
#define Ru8_TIFR             *((volatile uint8_t*)0x58)
#define Ru8_TCNT0            *((volatile uint8_t*)0x52)
#define Ru8_TCCR0            *((volatile uint8_t*)0x53)


#define Ru8_GICR             *((volatile uint8_t*)0x5B)
#define Ru8_GIFR             *((volatile uint8_t*)0x5A)
#define Ru8_SPMCR            *((volatile uint8_t*)0x57)
#define Ru8_TWCR             *((volatile uint8_t*)0x56)
#define Ru8_MCUCR            *((volatile uint8_t*)0x55)
#define Ru8_MCUCSR           *((volatile uint8_t*)0x54)
#define Ru8_OSCCAL_OCDR      *((volatile uint8_t*)0x51)
#define Ru8_SFIOR            *((volatile uint8_t*)0x50)
		
#define Ru8_TCCR1A           *((volatile uint8_t*)0x4F)
#define Ru8_TCCR1B           *((volatile uint8_t*)0x4E)
#define Ru8_TCNT1H           *((volatile uint8_t*)0x4D)
#define Ru8_TCNT1L           *((volatile uint8_t*)0x4C)
#define Ru8_OCR1AH           *((volatile uint8_t*)0x4B)
#define Ru8_OCR1AL           *((volatile uint8_t*)0x4A)
#define Ru8_OCR1BH           *((volatile uint8_t*)0x49)
#define Ru8_OCR1BL           *((volatile uint8_t*)0x48)
#define Ru8_ICR1H            *((volatile uint8_t*)0x47)
#define Ru8_ICR1L            *((volatile uint8_t*)0x46)
#define Ru8_TCCR2            *((volatile uint8_t*)0x45)
#define Ru8_TCNT2            *((volatile uint8_t*)0x44)
#define Ru8_OCR2             *((volatile uint8_t*)0x43)
#define Ru8_ASSR             *((volatile uint8_t*)0x42)
#define Ru8_WDTCR            *((volatile uint8_t*)0x41)
#define Ru8_UBRRH_UCSRC      *((volatile uint8_t*)0x40)
		
#define Ru8_EEARH            *((volatile uint8_t*)0x3F)
#define Ru8_EEARL            *((volatile uint8_t*)0x3E)
#define Ru8_EEDR             *((volatile uint8_t*)0x3D)
#define Ru8_EECR             *((volatile uint8_t*)0x3C)

#define Ru8_PORTA            *((volatile uint8_t*)0x3B) /* this register controls pull ups for each pin in portA when DDR for this pin
                                                         *  set as input and controls the high and low state when DDR for this pin set as output */
#define Ru8_DDRA             *((volatile uint8_t*)0x3A) // control direction for each pin in portA
#define Ru8_PINA             *((volatile uint8_t*)0x39)/* Read the actual state applied on the portA pins with any direction for this pin
														* but it commonly used with the input pins */

#define Ru8_PORTB            *((volatile uint8_t*)0x38) /* this register controls pull ups for each pin in portB when DDR for this pin
                                                         *  set as input and controls the high and low state when DDR for this pin set as output */
#define Ru8_DDRB             *((volatile uint8_t*)0x37) // control direction for each pin in portB
#define Ru8_PINB             *((volatile uint8_t*)0x36) /* Read the actual state applied on the portB pins with any direction for this pin
														 * but it commonly used with the input pins */ 

#define Ru8_PORTC            *((volatile uint8_t*)0x35) /* this register controls pull ups for each pin in portC when DDR for this pin
                                                         * set as input and controls the high and low state when DDR for this pin set as output */
#define Ru8_DDRC             *((volatile uint8_t*)0x34) // control direction for each pin in portC
#define Ru8_PINC             *((volatile uint8_t*)0x33) /* Read the actual state applied on the portC pins with any direction for this pin
														 * but it commonly used with the input pins */

#define Ru8_PORTD            *((volatile uint8_t*)0x32) /* this register controls pull ups for each pin in portD when DDR for this pin
                                                         * set as input and controls the high and low state when DDR for this pin set as output */
#define Ru8_DDRD             *((volatile uint8_t*)0x31) // control direction for each pin in portD
#define Ru8_PIND             *((volatile uint8_t*)0x30) /* Read the actual state applied on the portD pins with any direction for this pin
														 * but it commonly used with the input pins */
		
#define Ru8_SPDR             *((volatile uint8_t*)0x2F)
#define Ru8_SPSR             *((volatile uint8_t*)0x2E)
#define Ru8_SPCR             *((volatile uint8_t*)0x2D)
#define Ru8_UDR              *((volatile uint8_t*)0x2C)
#define Ru8_UCSRA            *((volatile uint8_t*)0x2B) 
#define Ru8_UCSRB            *((volatile uint8_t*)0x2A)
#define Ru8_UBRRL            *((volatile uint8_t*)0x29)
#define Ru8_ACSR             *((volatile uint8_t*)0x28)
#define Ru8_ADMUX            *((volatile uint8_t*)0x27)
#define Ru8_ADCSRA           *((volatile uint8_t*)0x26)
#define Ru8_ADCH             *((volatile uint8_t*)0x25)
#define Ru8_ADCL             *((volatile uint8_t*)0x24)
#define Ru8_TWDR             *((volatile uint8_t*)0x23)
#define Ru8_TWAR             *((volatile uint8_t*)0x22)
#define Ru8_TWSR			 *((volatile uint8_t*)0x21)
#define Ru8_TWBR			 *((volatile uint8_t*)0x20)


#endif
