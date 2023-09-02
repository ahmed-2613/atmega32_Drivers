#include "Std_Types.h"
#include "Algobit.h"
#include "ATmega32.h"


//Initialize Properties of ADC
uint8_t ADC_Initialize(uint8_t ref, uint8_t Adj, uint8_t prescaler)
{
	if(ref == 2 || ref > 3 || Adj > 1 || prescaler > 7)
		return 0xFF;	//Input error

	//Select reference
	ADMUX |= (ref << 6) + (Adj << 5) ;
	ADCSRA |= prescaler;

	reset_bit(ADCSRA, ADIF);	//Clear Interrupt Flag

	return 0x00;
}

//Start Conversion
uint16_t ADC_Start_Conversion(uint8_t channel)
{
	if(channel > 7)
		return 0xFFFF;

	reset_bit(ADCSRA, ADIE);	//Disable ADC Interrupt
	reset_bit(ADCSRA, ADATE);	//Disable Auto Trigger Mode

	ADMUX |= channel;			//Set desired channel
	set_bit(ADCSRA, ADEN);		//Enable ADC
	set_bit(ADCSRA, ADSC);		//Start Conversion

	//Polling
	while(!get_bit(ADCSRA, ADIF));
		reset_bit(ADCSRA, ADIF);	//Clear Interrupt Flag

	return ADCDR;	//Fetch Result
}
