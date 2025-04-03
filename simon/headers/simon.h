
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

void generate_random_sequence(uint8_t level);
void displaythesequence(uint8_t level);
uint8_t readplayer(uint8_t level);
bool checksequence(uint8_t sequence_ ,uint8_t inputValue);
//void reset (void);



#endif /* SIMON_H_ */