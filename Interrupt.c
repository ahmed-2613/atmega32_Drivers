#include "Std_Types.h"
#include "Algobit.h"
#include "Atmega32.h"

/*------------------------------------------------------------------*/
/*-----------------------Global Interrupt---------------------------*/
uint8_t Global_Interrupt_Configure(uint8_t State)
{
	if(State > 1)
		return 0xFF;	//Input error

	State ? set_bit(SREG, 7) : reset_bit(SREG, 7);

	return 0;
}

/*------------------------------------------------------------------*/
/*---------------------External Interrupts--------------------------*/
//Set External Interrupt
uint8_t External_Interrupt_Configure(uint8_t INT, uint8_t State)
{
	if(State > 1)
		return 0xFF;			//Input error

	switch(INT)
	{
	case INT0: State ? set_bit(GICR, INT0) : reset_bit(GICR, INT0); break;
	case INT1: State ? set_bit(GICR, INT1) : reset_bit(GICR, INT1); break;
	case INT2: State ? set_bit(GICR, INT2) : reset_bit(GICR, INT2); break;
	default:
		return 0xFF;	//Input error
	}

	return 0x00;	//No error
}

//External Interrupt Trigger Configuration
uint8_t Interrupt_Trigger_Configure(uint8_t INT, uint8_t Trigger)
{
	switch(INT)
	{
	case INT0: 	switch(Trigger)
				{
				case Low_Level: 		reset_bit(MCUCR, 1);	reset_bit(MCUCR, 0); 	break;
				case Logical_Change: 	reset_bit(MCUCR, 1);	set_bit(MCUCR, 0); 		break;
				case Falling_Edge:		set_bit(MCUCR, 1);		reset_bit(MCUCR, 0); 	break;
				case Rising_Edge: 		set_bit(MCUCR, 1);		set_bit(MCUCR, 0); 		break;
				default:
					return 0xFF;	//Input error
				} break;

	case INT1: 	switch(Trigger)
				{
				case Low_Level: 		reset_bit(MCUCR, 3);	reset_bit(MCUCR, 2); 	break;
				case Logical_Change: 	reset_bit(MCUCR, 3);	set_bit(MCUCR, 2); 		break;
				case Falling_Edge:		set_bit(MCUCR, 3);		reset_bit(MCUCR, 2); 	break;
				case Rising_Edge: 		set_bit(MCUCR, 3);		set_bit(MCUCR, 2); 		break;
				default:
					return 0xFF;	//Input error
				} break;

	case INT2: 	reset_bit(GICR, 5);		//Disable Interrupt2
				switch(Trigger)
				{
				case Falling_Edge:		reset_bit(MCUCSR, 6); 	break;
				case Rising_Edge: 		set_bit(MCUCSR, 6);		break;
				default:
					set_bit(GICR, INT2);	//Enable Interrupt2
					return 0xFF;	//Input error
				}
				set_bit(GIFR, INT2);	//Clear Interrupt2 Flag
				set_bit(GICR, INT2);	//Enable Interrupt2
				break;
	default:
		return 0xFF;	//Input error
	}

	return 0x00;	//No error
}

//External Interrupt Flag Clear
uint8_t Interrupt_Flag_Clear(uint8_t INT)
{
	switch(INT)
	{
	case INT0: set_bit(GIFR, INT0); break;
	case INT1: set_bit(GIFR, INT1); break;
	case INT2: set_bit(GIFR, INT2); break;
	default:
		return 0xFF;	//Input error
	}

	return 0x00;	//No error
}

