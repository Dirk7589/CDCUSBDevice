/**
*@file rotary.c
*@author Dirk Dubois
*@date April 29, 2013
*/
#include "rotary.h"

void readRotary(void)
{
	int8_t direction = hardware.encoderDirection;
	int8_t position = hardware.encoderPosition;
	// Rotary encoder -------------------------------------------------------------------------
	hardware.encoderState = RE_A | RE_B << 1;
	if(hardware.encoderPreviousState != 0xFF) // Check for first time check
	{
		if(hardware.encoderPreviousState == 0b00 && hardware.encoderState == 0b01) 
		{
			// Going counter-clockwise
			hardware.encoderDirection = -1;
			hardware.encoderPosition--;
		}

		else if(hardware.encoderPreviousState == 0b01 && hardware.encoderState == 0b00) 
		{		
			// Going clockwise
			hardware.encoderDirection = 1;
			hardware.encoderPosition++;
		}
	}
	// Save the current state
	hardware.encoderPreviousState = hardware.encoderState;

	// Our encoder has 12 ticks per rotation
	if (hardware.encoderPosition > NUMBER_OF_TICKS)
	{ 
		hardware.encoderPosition = 0;
	}
	if (hardware.encoderPosition < 0)
	{	
		hardware.encoderPosition = NUMBER_OF_TICKS;
	}
	
	direction = hardware.encoderDirection;
	int8_t position = hardware.encoderPosition;
	
	if(direction == 1)
	{
		TURN_LEFT = 1;
		TURN_RIGHT = 0; 
	}
	if(direction == -1)
	{
		TURN_LEFT = 0;
		TURN_RIGHT = 1;
	}
	if (!SWITCH0)
	{
		PUSH_BUTTON = 1;
	}
}
void rotaryFunction()
{

}
