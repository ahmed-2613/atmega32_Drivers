#ifndef ALGOBIT_H
#define ALGOBIT_H

//Bitwise operations
#define set_bit(Reg, BitNum)				(Reg |= 1 << BitNum)		//Set given bit in a variable
#define reset_bit(Reg, BitNum)				(Reg &= ~(1 << BitNum))		//Reset given bit in a variable
#define toggle_bit(Reg, BitNum)				(Reg ^= 1 << BitNum)		//Toggle state of a given bit in a variable
#define get_bit(Reg, BitNum)				((Reg >> BitNum) & 0x01)	//Get value of a given bit in a variable


//Half-Byte operations
#define set_upper(byte)			(byte |= 0xF0)		//Set upper half of a byte
#define reset_upper(byte)		(byte &= 0x0F)		//Reset upper half of a byte
#define toggle_upper(byte)		(byte ^= 0xF0)		//Toggle values of upper half of a byte
#define get_upper(byte)			(byte >> 0x04)		//Get value of upper half of a byte

#define set_lower(byte)			(byte |= 0x0F)		//Set lower half of a byte
#define reset_lower(byte)		(byte &= 0xF0)		//Reset lower half of a byte
#define toggle_lower(byte)		(byte ^= 0x0F)		//Toggle values of lower half of a byte
#define get_lower(byte)			(byte & 0x0F)		//Get value of lower half of a byte

#define insert_upper(byte, value)	(byte = (byte & 0x0F) | (value << 0x04))		//Set values of upper bit of a byte by a given value
#define insert_lower(byte, value)	(byte = (byte & 0xF0) | value)				//Set values of half a byte by a given value


//Full size operations
#define toggle_variable(var)	(var ^= 0xFF);	//Toggle bits of a given variable

#endif
