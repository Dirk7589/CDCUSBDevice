/**
*@file rotary.h
*@author Dirk Dubois
*@date July 18, 2012
*/

#ifndef _ROTARY_H
#define _ROTARY_H

/**Includes*/
#include <stdint.h>
//Internal defines

// Rotary encoder
#define RE_A RB5
#define RE_B RB4

// Switch
#define SWITCH0	RB3 /**<Define the push button of the rotary encoder*/

// Overall hardware state
struct hardwareState {
	
	// Rotary Encoder position
	int encoderPosition;
	unsigned char encoderState;
	unsigned char encoderPreviousState;
	int encoderDirection;
	
	// Push button
	unsigned char buttonState;
	unsigned char buttonDebounce;

}hardware;

//Output defines
uint8_t TURN_LEFT;
uint8_t TURN_RIGHT;
uint8_t PUSH_BUTTON;
uint8_t NUMBER_OF_TICKS;

void readRotary(void);

/*A function that acts on information stored in the hardware struct. Sets a bit high when you turn
left or right. Also allows for a button push. 1 is considered active.*/
void rotaryFunction();

#endif