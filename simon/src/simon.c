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
uint8_t blink_time =1000;


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

void setup_buzzer(void)
{
	setBit(DDRB,4);
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
		costum_delay(blink_time);
		clearBit(PORTB,sequence[i]);
		costum_delay(blink_time);
		
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
			button_press_buzz(player_input);
			_delay_ms(50);
			break;
		}
		else if(readBit(PINC,1) == 0 )
		{
			player_input=1;
			button_press_buzz(player_input);
			_delay_ms(50);
			break;
		}
		else if(readBit(PINC,2) == 0 )
		{
			player_input=2;
			button_press_buzz(player_input);
			_delay_ms(50);
			break;
		}
		else if(readBit(PINC,3) == 0 )
		{
			player_input=3;
			button_press_buzz(player_input);
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

void button_press_buzz(uint8_t player_input)
{
	
	while(readBit(PINC,player_input)==0)
	{
		setBit(PORTB,4);
	}
	 clearBit(PORTB, 4);
			 
}


void success_indicator(void)
{
	
	for(uint8_t i=0 ; i<3 ;i++)
	{
		
		for(uint8_t j=0 ; j<=4 ;j++)
		{   
			setBit(PORTB,j);
		}
		_delay_ms(100);
		
		for(uint8_t j=0 ; j<=4 ;j++)
		{
			clearBit(PORTB,j);
		}
		_delay_ms(100);
	}
	
	if(blink_time>=50 )
	{
		blink_time =blink_time -50 ;
	}
}


void failure_indicator(void)
{
		
		for(uint8_t j=0 ; j<=4 ;j++)
		{
			setBit(PORTB,j);
		}
		_delay_ms(500);
		
		for(uint8_t j=0 ; j<=4 ;j++)
		{
			clearBit(PORTB,j);
		}
}

void costum_delay(uint8_t _time)
{
	for(uint8_t i=0 ; i<_time ; i++)
	{
		_delay_ms(1);
	}
}
		
		
		
		