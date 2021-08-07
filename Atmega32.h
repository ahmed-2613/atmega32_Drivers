#ifndef ATMEGA32
#define ATMEGA32

/* Registers */
#define reg_addr_8(addr)	*((volatile uint8_t*) addr)		//address for 8-bit registers
#define reg_addr_16(addr)	*((volatile uint16_t*) addr)	//address for 16-bit registers

#define SREG		reg_addr_8(0x5F)	//Status Register
#define GICR		reg_addr_8(0x5B)	//General Interrupt Control Register
#define GIFR		reg_addr_8(0x5A)	//General Interrupt Flag Register
#define MCUCR		reg_addr_8(0x55)	//MCU Control Register
#define MCUCSR		reg_addr_8(0x54)	//MCU Control Status Register

#define SFIOR		reg_addr_8(0x50)	//Special Function I/O Register

//GroupA Registers
#define PORTA	 	reg_addr_8(0x3B)
#define DDRA	 	reg_addr_8(0x3A)
#define PINA	 	reg_addr_8(0x39)

//GroupB Registers
#define PORTB	 	reg_addr_8(0x38)
#define DDRB	 	reg_addr_8(0x37)
#define PINB	 	reg_addr_8(0x36)

//GroupC Registers
#define PORTC	 	reg_addr_8(0x35)
#define DDRC	 	reg_addr_8(0x34)
#define PINC	 	reg_addr_8(0x33)

//GroupD Registers
#define PORTD	 	reg_addr_8(0x32)
#define DDRD	 	reg_addr_8(0x31)
#define PIND	 	reg_addr_8(0x30)
/* !Registers */


/* Vectors */
#define Vector_No(n)	__vector_ ## n		//Generate vector address from vector table

//Reset Vector
#define RESET_vect		Vector_No(0)

//External Vectors
#define INT0_vect		Vector_No(1)	//External Interrupt Request 0
#define INT1_vect		Vector_No(2)	//External Interrupt Request 1
#define INT2_vect		Vector_No(3)	//External Interrupt Request 2

//Timer/Counter2 Vectors
#define TIMER2_COMP_vect		Vector_No(4)	//Timer/Counter2 Compare Match
#define TIMER2_OVF_vect			Vector_No(5)	//Timer/Counter2 Overflow

//Timer/Counter1 Vectors
#define TIMER1_CAPT_vect		Vector_No(6)	//Timer/Counter1 Capture Event
#define TIMER1_COMPA_vect		Vector_No(7)	//Timer/Counter1 Compare Match A
#define TIMER1_COMPB_vect		Vector_No(8)	//Timer/Counter1 Compare Match B
#define TIMER1_OVF_vect			Vector_No(9)	//Timer/Counter1 Overflow

//Timer/Counter0 Vectors
#define TIMER0_COMP_vect		Vector_No(10)	//Timer/Counter0 Compare Match
#define TIMER0_OVF_vect			Vector_No(11)	//Timer/Counter0 Overflow

//SPI - Serial Transfer Complete
#define SPI_STC_vect		Vector_No(12)

//USART Vectors
#define USART_RXC_vect			Vector_No(13)	//USART, Rx Complete
#define USART_DReg_vect			Vector_No(14)	//USART Data Register Empty
#define USART_TXC_vect			Vector_No(15)	//USART, Tx Complete

//ADC Conversion Complete
#define ADC_vect			Vector_No(16)

//EEPROM Ready
#define EE_RDY_vect			Vector_No(17)

//Analog Comparator
#define ANA_COMP_vect		Vector_No(18)

//Two-wire Serial Interface
#define TWI_vect			Vector_No(19)

//Store Program Memory Ready
#define SPM_RDY_vect		Vector_No(20)

//Default Vector
#define Default_vect		__vector_default
/* !Vectors */


//Digital States
#define Input 0
#define Output 1
#define Input_Pullup 2

//Logical States
#define low  0
#define Logic_Low  0
#define Logic_High 1
#define High 1
#define Disable 0
#define Enable 	1

//Triggers
#define Low_Level			0x0
#define Logical_Change		0x1
#define Falling_Edge		0x2
#define Rising_Edge			0x3


//External Interrupts
#define INT0 0x6
#define INT1 0x7
#define INT2 0x5

//Groups
#define GroupA 0x0
#define GroupB 0x1
#define GroupC 0x2
#define GroupD 0x3

//Ports
#define PortA 0x0
#define PortB 0x1
#define PortC 0x2
#define PortD 0x3

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
