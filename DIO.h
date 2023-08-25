#ifndef ATMEGA32_DIO_H
#define ATMEGA32_DIO_H

#include "ATmega32.h"
#include "Std_Types.h"

/*------------------------------------------------------------------*/
/*-----------------------Direction set-----------------------------*/

//Set Direction of a single pin
uint8_t DIO_Set_Pin(uint8_t Pin, uint8_t State);

//Set direction of a whole port
uint8_t DIO_Set_Port(uint8_t Group, uint8_t State);

//Set direction of a half a port
uint8_t DIO_Set_Upper(uint8_t Group, uint8_t State);
uint8_t DIO_Set_Lower(uint8_t Group, uint8_t State);

//Get the direction of a given Pin
uint8_t DIO_Get_Pin_Direction(uint8_t Pin);

//Get the direction of a given Group
uint8_t DIO_Get_Port_Direction(uint8_t Group);

/*------------------------------------------------------------------*/
/*---------------------------Output---------------------------------*/

//Write to a single pin
uint8_t DIO_Pin_Write(uint8_t Pin, uint8_t Value);

//Toggle O/P value of a given pin
uint8_t DIO_Pin_Toggle(uint8_t Pin);

//Write to a whole Port
uint8_t DIO_Port_Write(uint8_t Group, uint8_t Value);

//Write to half a Port
uint8_t DIO_Upper_Write(uint8_t Group, uint8_t Value);
uint8_t DIO_Lower_Write(uint8_t Group, uint8_t Value);


//Get driven O/P value of a pin
uint8_t DIO_Get_Pin_Value(uint8_t Pin);

//Get driven O/P value of a port
uint16_t DIO_Get_Port_Value(uint8_t Group);

//Get driven O/P value of half a port
uint8_t DIO_Get_Upper_Value(uint8_t Group);
uint8_t DIO_Get_Lower_Value(uint8_t Group);


/*------------------------------------------------------------------*/
/*---------------------------Input----------------------------------*/

//Read from a single pin
uint8_t DIO_Pin_Read(uint8_t Pin);

//Read from a whole Port
uint16_t DIO_Port_Read(uint8_t Group);

//Read from half a Port
uint8_t DIO_Upper_Read(uint8_t Group);
uint8_t DIO_Lower_Read(uint8_t Group);

/*------------------------------------------------------------------*/
/*-------------------Pull_Up Configuration--------------------------*/

//Enable/Disable Pull-Up Configuration associated with each Input Channel
uint8_t DIO_Pullup_Configure(uint8_t Pin, uint8_t State);

//Globally Enable/Disable Pull-Up Configurations of ALL Channels
//This overrides the Configuration of single pins
uint8_t DIO_Global_Pullup_Configure(uint8_t State);

//Get state(Enable/Disable) of the Global Pull-Up Configuration
uint8_t DIO_Get_Global_Pullup();

#endif /* ATMEGA32_DIO_H */
