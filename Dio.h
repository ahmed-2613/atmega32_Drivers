#ifndef ATMEGA32_DIO_H
#define ATMEGA32_DIO_H

#include "Atmega32.h"

/*------------------------------------------------------------------*/
/*-----------------------Direction set-----------------------------*/

//Set Direction of a single pin
void Dio_Set_Pin(uint8_t Pin, uint8_t State);

//Set direction of a whole port
void Dio_Set_Port(uint8_t Group, uint8_t State);

//Set direction of a half a port
void Dio_Set_Upper(uint8_t Group, uint8_t State);
void Dio_Set_Lower(uint8_t Group, uint8_t State);

//Get the direction of a given Pin
uint8_t Get_Pin_Status(uint8_t Pin);


/*------------------------------------------------------------------*/
/*---------------------------Output---------------------------------*/

//Write to a single pin
void Dio_Pin_Write(uint8_t Pin, uint8_t Value);

//Toggle O/P value of a given pin
void Dio_Pin_Toggle(uint8_t Pin);

//Write to a whole Port
void Dio_Port_Write(uint8_t Group, uint8_t Value);

//Write to half a Port
void Dio_Upper_Write(uint8_t Group, uint8_t Value);
void Dio_Lower_Write(uint8_t Group, uint8_t Value);


//Get driven O/P value of a pin
uint8_t Get_Pin_Value(uint8_t Pin);

//Get driven O/P value of a port
uint16_t Get_Port_Value(uint8_t Group);

//Get driven O/P value of half a port
uint8_t Get_Upper_Value(uint8_t Group);
uint8_t Get_Lower_Value(uint8_t Group);


/*------------------------------------------------------------------*/
/*---------------------------Input----------------------------------*/

//Read from a single pin
uint8_t Dio_Pin_Read(uint8_t Pin);

//Read from a whole Port
uint16_t Dio_Port_Read(uint8_t Group);

//Read from half a Port
uint8_t Dio_Upper_Read(uint8_t Group);
uint8_t Dio_Lower_Read(uint8_t Group);


#endif /* ATMEGA32_DIO_H */
