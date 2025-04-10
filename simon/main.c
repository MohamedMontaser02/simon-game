/*
* simon_Game.c
*
* Created: 4/3/2025 8:59:49 PM
* Author : Mohamed
*/
#define  F_CPU 8000000U

#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "simon.h"
uint8_t level_=1;

int main(void)
{
	setupleds();
	setupbuttons();
	setup_buzzer();
	
	
	
	srand(3);
	DDRA=0xff;

	while (1)
	{
		
		generate_random_sequence(level_);
		displaythesequence(level_);
		
		uint8_t gameover=0;
		for (uint8_t i=0;i<level_;i++)
		{
			uint8_t inputValue= readplayer();
			

			if(inputValue==0)
			{
				
				PORTA=0xff;
			}

			_delay_ms(500);

			bool result=checksequence(i ,inputValue);
			
			if (result==0)
			{
				gameover=1;
				break;
			}
			
		}
		if (gameover == 0)
		{
			success_indicator();
			level_++;
		}
		else if (gameover == 1)
		{
			failure_indicator();
			level_=1;
		}
		
		
	}
}