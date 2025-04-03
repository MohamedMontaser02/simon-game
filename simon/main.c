/*
* simon_Game.c
*
* Created: 4/3/2025 8:59:49 PM
* Author : Mohamed
*/


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
	
	
	
	bool result ;
	srand(4);
	
	while (1)
	{
		generate_random_sequence(level_);
		displaythesequence(level_);
		
		uint8_t gameover=0;
		for (uint8_t i=0;i<level_;i++)  //level 4  // 2 0 1 1
		//user   2 0 3 1
		{
			uint8_t inputValue= readplayer(level_);
			result=checksequence(i ,inputValue);
			
			if (result==0)
			{
				gameover=1;
			}
			
		}
		if (gameover == 0)
		{
			level_++;
		}
		else if (gameover == 1)
		{
			//reset ();
		}
		
		
	}
}