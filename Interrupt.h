#ifndef INTERRUPT_H
#define INTERRUPT_H

#define Vector		//to extract interrupt vectors
#include "Atmega32.h"
#include "Interrupt_Handler.h"


/*------------------------------------------------------------------*/
/*-----------------------Global Interrupt---------------------------*/
//Enable/Disable Global Interrupt
uint8_t Global_Interrupt_Configure(uint8_t State);

/*------------------------------------------------------------------*/
/*---------------------External Interrupts--------------------------*/
//Set External Interrupt
uint8_t External_Interrupt_Configure(uint8_t INT, uint8_t State);

//External Interrupt Trigger Configuration
uint8_t Interrupt_Trigger_Configure(uint8_t INT, uint8_t Trigger);

//External Interrupt Flag Clear
uint8_t Interrupt_Flag_Clear(uint8_t INT);

#endif /* INTERRUPT_H */
