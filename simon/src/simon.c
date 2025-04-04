/*
* simon.c
*
* Created: 4/3/2025 9:00:06 PM
*  Author: Mohamed
*/

#include <avr/io.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "simon.h"
#define  F_CPU 8000000U
#include <util/delay.h>

//#define maxlevels  100
uint8_t sequence[100] ={0};

void setupleds(void)
{
	setBit(DDRB,0);
	setBit(DDRB,1);
	setBit(DDRB,2);
	setBit(DDRB,3);
}


void setupbuttons(void)
{
	clearBit(DDRC,0);
	setBit(PORTC,0);
	
	clearBit(DDRC,1);
	setBit(PORTC,1);
	
	clearBit(DDRC,2);
	setBit(PORTC,2);
	
	clearBit(DDRC,3);
	setBit(PORTC,3);
}


void generate_random_sequence(uint8_t level)
{
	for(uint8_t i =0; i < level ; i++)
	{
		sequence[i] = (rand() % 4 );
	}
}


void displaythesequence(uint8_t level)
{
	for(unsigned int i =0; i < level ; i++)
	{
		setBit(PORTB,sequence[i]);
		_delay_ms(500);
		clearBit(PORTB,sequence[i]);
		_delay_ms(500);
		
	}
}

uint8_t readplayer()
{
	uint8_t player_input=7;
	while(1)
	{
		if(readBit(PINC,0) == 0 )
		{
			player_input=0;
			_delay_ms(50);
			break;
		}
		else if(readBit(PINC,1) == 0 )
		{
			player_input=1;
			_delay_ms(50);
			break;
		}
		else if(readBit(PINC,2) == 0 )
		{
			player_input=2;
			_delay_ms(50);
			break;
		}
		else if(readBit(PINC,3) == 0 )
		{
			player_input=3;
			_delay_ms(50);
			break;
		}
	}
	return player_input;
}


bool checksequence(uint8_t i ,uint8_t inputValue)
{
	//sequence // 2 0 1 1
	//user       2 0 3 1
	
	if(inputValue == sequence[i])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void reset (void)
{
	setBit(PORTB,0);
	setBit(PORTB,1);
	setBit(PORTB,2);
	setBit(PORTB,3);
	
}
