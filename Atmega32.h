#ifndef ATMEGA32
#define ATMEGA32

#ifdef Register
	#define SFIOR	 *((volatile uint8_t*) 0x50)

	#define PORTA	 *((volatile uint8_t*) 0x3B)
	#define DDRA	 *((volatile uint8_t*) 0x3A)
	#define PINA	 *((volatile uint8_t*) 0x39)

	#define PORTB	 *((volatile uint8_t*) 0x38)
	#define DDRB	 *((volatile uint8_t*) 0x37)
	#define PINB	 *((volatile uint8_t*) 0x36)

	#define PORTC	 *((volatile uint8_t*) 0x35)
	#define DDRC	 *((volatile uint8_t*) 0x34)
	#define PINC	 *((volatile uint8_t*) 0x33)

	#define PORTD	 *((volatile uint8_t*) 0x32)
	#define DDRD	 *((volatile uint8_t*) 0x31)
	#define PIND	 *((volatile uint8_t*) 0x30)

#endif //Register

//Digital States
#define Input 0
#define Output 1
#define Input_Pullup 2

//Logical States
#define low  0
#define Logic_Low  0

#define Logic_High 1
#define High 1

#define Enable 	1
#define Disable 0

//Groups
#define GroupA 0
#define GroupB 1
#define GroupC 2
#define GroupD 3

//Ports
#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3

//Pins
#define Pin0 0x0
#define Pin1 0x1
#define Pin2 0x2
#define Pin3 0x3
#define Pin4 0x4
#define Pin5 0x5
#define Pin6 0x6
#define Pin7 0x7

//Port-Pin Compound (Using Hexa-Compound Structure)
#define PA0 0x00
#define PA1 0x01
#define PA2 0x02
#define PA3 0x03
#define PA4 0x04
#define PA5 0x05
#define PA6 0x06
#define PA7 0x07

#define PB0 0x10
#define PB1 0x11
#define PB2 0x12
#define PB3 0x13
#define PB4 0x14
#define PB5 0x15
#define PB6 0x16
#define PB7 0x17
#define PC0 0x20
#define PC1 0x21
#define PC2 0x22
#define PC3 0x23
#define PC4 0x24
#define PC5 0x25
#define PC6 0x26
#define PC7 0x27

#define PD0 0x30
#define PD1 0x31
#define PD2 0x32
#define PD3 0x33
#define PD4 0x34
#define PD5 0x35
#define PD6 0x36
#define PD7 0x37

#endif //ATMEGA32
