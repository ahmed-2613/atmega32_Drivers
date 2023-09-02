#ifndef ATMEGA32_ADC_H
#define ATMEGA32_ADC_H

#include "ATmega32.h"
#include "Std_Types.h"


//Initialize Properties of ADC
uint8_t ADC_Initialize(uint8_t ref, uint8_t Adj, uint8_t prescaler);

//Start Conversion
uint16_t ADC_Start_Conversion(uint8_t channel);


#endif /* ATMEGA32_ADC_H */
