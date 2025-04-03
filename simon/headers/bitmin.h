/*
 * bitmin.h
 *
 * Created: 3/13/2025 8:48:46 PM
 *  Author: Mohamed
 */ 


#ifndef BITMIN_H_
#define BITMIN_H_



//to set bit in register
#define setBit(reg,bit)   (reg|=(1U<<bit))


//to clear bit in register
#define clearBit(reg,bit)   (reg&=~(1U<<bit))


//to read bit in register
#define readBit(reg,bit)    (1&(reg>>bit))


//to toggle a bit in register
#define toggleBit(reg,bit)    reg^=(1U<<bit)

#endif /* BITMIN_H_ */