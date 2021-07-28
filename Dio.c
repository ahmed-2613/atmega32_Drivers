#include "Std_Types.h"
#include "Algobit.h"
#define Register
#include "Atmega32.h"

/*------------------------------------------------------------------*/
/*---------------------------Output---------------------------------*/

//Write to a single pin
void Dio_Pin_Write(uint8_t Pin, uint8_t Value)
{
	uint8_t Group = get_upper(Pin);
	reset_upper(Pin);

	//Input error check
	if(Pin > Pin7)
		return;
	if(Value > 1)
		return;

	switch(Group)
	{
	case GroupA: Value ? set_bit(PORTA, Pin) : reset_bit(PORTA, Pin); break;
	case GroupB: Value ? set_bit(PORTB, Pin) : reset_bit(PORTB, Pin); break;
	case GroupC: Value ? set_bit(PORTC, Pin) : reset_bit(PORTC, Pin); break;
	case GroupD: Value ? set_bit(PORTD, Pin) : reset_bit(PORTD, Pin); break;
	}

	return;
}

//Toggle O/P value of a given pin
void Dio_Pin_Toggle(uint8_t Pin)
{
	uint8_t Group = get_upper(Pin);
	reset_upper(Pin);

	//Input error check
	if(Pin > Pin7)
		return;

	switch(Group)
	{
	case GroupA: toggle_bit(PORTA, Pin); break;
	case GroupB: toggle_bit(PORTB, Pin); break;
	case GroupC: toggle_bit(PORTC, Pin); break;
	case GroupD: toggle_bit(PORTD, Pin); break;
	}

	return;
}

//Write to a whole Port
void Dio_Port_Write(uint8_t Group, uint8_t Value)
{
	switch(Group)
	{
	case GroupA: PORTA = Value; break;
	case GroupB: PORTB = Value; break;
	case GroupC: PORTC = Value; break;
	case GroupD: PORTD = Value; break;
	}

	return;
}

//Write to half a Port
void Dio_Upper_Write(uint8_t Group, uint8_t Value)
{
	switch(Group)
	{
	case GroupA: insert_upper(PORTA, Value); break;
	case GroupB: insert_upper(PORTB, Value); break;
	case GroupC: insert_upper(PORTC, Value); break;
	case GroupD: insert_upper(PORTD, Value); break;
	}

	return;
}
void Dio_Lower_Write(uint8_t Group, uint8_t Value)
{
	switch(Group)
	{
	case GroupA: insert_lower(PORTA, Value); break;
	case GroupB: insert_lower(PORTB, Value); break;
	case GroupC: insert_lower(PORTC, Value); break;
	case GroupD: insert_lower(PORTD, Value); break;
	}

	return;
}


//Get driven O/P value of a pin
uint8_t Get_Pin_Value(uint8_t Pin)
{
	uint8_t Group = get_upper(Pin);
	reset_upper(Pin);

	//Input error check
	if(Pin > Pin7)
		return 0xFF;

	switch(Group)
	{
	case GroupA: return get_bit(PORTA, Pin);
	case GroupB: return get_bit(PORTB, Pin);
	case GroupC: return get_bit(PORTC, Pin);
	case GroupD: return get_bit(PORTD, Pin);
	}

	return 0xFF;
}

//Get driven O/P value of a port
uint16_t Get_Port_Value(uint8_t Group)
{
	switch(Group)
	{
	case GroupA: return PORTA;
	case GroupB: return PORTB;
	case GroupC: return PORTC;
	case GroupD: return PORTD;
	}

	return 0xFFF;
}

//Get driven O/P value of half a port
uint8_t Get_Upper_Value(uint8_t Group)
{
	switch(Group)
	{
	case GroupA: return get_upper(PORTA);
	case GroupB: return get_upper(PORTB);
	case GroupC: return get_upper(PORTC);
	case GroupD: return get_upper(PORTD);
	}

	return 0xFF;
}
uint8_t Get_Lower_Value(uint8_t Group)
{
	switch(Group)
	{
	case GroupA: return get_lower(PORTA);
	case GroupB: return get_lower(PORTB);
	case GroupC: return get_lower(PORTC);
	case GroupD: return get_lower(PORTD);
	}

	return 0xFF;
}


/*------------------------------------------------------------------*/
/*-----------------------Direction set-----------------------------*/

//Set Direction of a single pin
void Dio_Set_Pin(uint8_t Pin, uint8_t State)
{
	uint8_t Group = get_upper(Pin);
	reset_upper(Pin);

	//Input error check
	if(Pin > Pin7)
		return;
	if(State > 1)
		return;

	switch(Group)
	{
	case GroupA: State ? set_bit(DDRA, Pin) : reset_bit(DDRA, Pin); break;
	case GroupB: State ? set_bit(DDRB, Pin) : reset_bit(DDRB, Pin); break;
	case GroupC: State ? set_bit(DDRC, Pin) : reset_bit(DDRC, Pin); break;
	case GroupD: State ? set_bit(DDRD, Pin) : reset_bit(DDRD, Pin); break;
	}

	return;
}

//Set direction of a whole port
void Dio_Set_Port(uint8_t Group, uint8_t State)
{
	//Input error check
	if(State > 1)
		return;

	switch(Group)
	{
	case GroupA: State ? (DDRA = 0xFF) : (DDRA = 0x00); break;
	case GroupB: State ? (DDRB = 0xFF) : (DDRB = 0x00); break;
	case GroupC: State ? (DDRC = 0xFF) : (DDRC = 0x00); break;
	case GroupD: State ? (DDRD = 0xFF) : (DDRD = 0x00); break;
	}

	return;
}

//Set direction of a half a port
void Dio_Set_Upper(uint8_t Group, uint8_t State)
{
	//Input error check
	if(State > 1)
		return;

	switch(Group)
	{
	case GroupA: State ? set_upper(DDRA) : reset_upper(DDRA); break;
	case GroupB: State ? set_upper(DDRB) : reset_upper(DDRD); break;
	case GroupC: State ? set_upper(DDRC) : reset_upper(DDRC); break;
	case GroupD: State ? set_upper(DDRD) : reset_upper(DDRD); break;
	}

	return;
}
void Dio_Set_Lower(uint8_t Group, uint8_t State)
{
	//Input error check
	if(State > 1)
		return;

	switch(Group)
	{
	case GroupA: State ? set_lower(DDRA) : reset_lower(DDRA); break;
	case GroupB: State ? set_lower(DDRB) : reset_lower(DDRB); break;
	case GroupC: State ? set_lower(DDRC) : reset_lower(DDRC); break;
	case GroupD: State ? set_lower(DDRD) : reset_lower(DDRD); break;
	}

	return;
}

//Get the direction of a given Pin
uint8_t Get_Pin_Status(uint8_t Pin)
{
	uint8_t Group = get_upper(Pin);
	reset_upper(Pin);
	return get_bit(Group, Pin);
}


/*------------------------------------------------------------------*/
/*---------------------------Input----------------------------------*/

//Read from a single pin
uint8_t Dio_Pin_Read(uint8_t Pin)
{
	uint8_t Group = get_upper(Pin);
	reset_upper(Pin);

	//Input error check
	if(Pin > Pin7)
		return 0xFF;	//0xFF is error indicator

	switch(Group)
	{
	case GroupA: return get_bit(PINA, Pin);
	case GroupB: return get_bit(PINB, Pin);
	case GroupC: return get_bit(PINC, Pin);
	case GroupD: return get_bit(PIND, Pin);
	}

	return 0xFF;	//Group error
}

//Read from a whole Port
uint16_t Dio_Port_Read(uint8_t Group)
{
	switch(Group)
	{
	case GroupA: return PINA;
	case GroupB: return PINB;
	case GroupC: return PINC;
	case GroupD: return PIND;
	}

	return 0xFFF;	//Group error

}

//Read from half a Port
uint8_t Dio_Upper_Read(uint8_t Group)
{
	switch(Group)
	{
	case GroupA: return get_upper(PINA);
	case GroupB: return get_upper(PINB);
	case GroupC: return get_upper(PINC);
	case GroupD: return get_upper(PIND);
	}

	return 0xFF;	//Group error
}
uint8_t Dio_Lower_Read(uint8_t Group)
{
	switch(Group)
	{
	case GroupA: return get_lower(PINA);
	case GroupB: return get_lower(PINB);
	case GroupC: return get_lower(PINC);
	case GroupD: return get_lower(PIND);
	}

	return 0xFF;	//Group error
}
