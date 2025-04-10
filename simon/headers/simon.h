
/** simon.h
*
* Created: 4/3/2025 9:00:20 PM
*  Author: Mohamed
*/


#ifndef SIMON_H_
#define SIMON_H_


#include "bitmin.h"
#include <stdlib.h>
#include <stdbool.h>


	
void setupleds(void);
void setupbuttons(void);
void setup_buzzer(void);



void generate_random_sequence(uint8_t level);
void displaythesequence(uint8_t level);
bool checksequence(uint8_t sequence_ ,uint8_t inputValue);
void button_press_buzz(uint8_t player_input);
void success_indicator(void);
void failure_indicator(void);

void costum_delay(uint16_t _time);

void reset (void);
uint8_t readplayer();



#endif /* SIMON_H_ */