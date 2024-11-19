/*
 * global.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phamgialuong
 */
#include "global.h"


// Buffer store system time: update only at Modify mode
static uint8_t systemTime[3] = {7, 5, 2}; // Red, Green, Yellow

// Buffer store time for display: decrease by 1 every second
static uint8_t timeCounter[2] = {7, 5}; // lane X, lane Y

// Buffer store time value during user changes in Modify mode: before set to systemTime buffer
static uint8_t counter = 0;

// Set new value for led[color]
// color: Red, Green, Yellow
// value from counter variable
void setSystemTime(uint8_t color){
	systemTime[color] = counter;
	resetCounter();
}

// Reset timeCounter[lane] to systemTime[color]
// lane: X, Y
// color: Red, Green, Yellow
void resetTimeCounter(uint8_t lane, uinr8_t color){
	timeCounter[lane] = systemTime[color];
}

// Return timeCounter[lane]
// lane: X, Y
uint8_t getTimeCounter(uint8_t lane){
	return timeCounter[lane];
}

// Decrease timeCounter[lane]
// lane: X, Y
void decreaseTimeCounter(uint8_t lane){
	timeCounter[lane]--;
}

// Increase counter variable when user presses button in Modify mode
void increaseCounter(void){
	counter++;
}

// Reset counter to 0
void resetCounter(void){
	counter = 0;
}

// Return counter value
uint8_t getCounter(void){
	return counter;
}

// Check systemTime after Modify mode
void checkSystemTime(void){
	if(systemTime[Red] != systemTime[Green] + systemTime[Yellow]){
		systemTime[Green] = (systemTime[Red]/5)*4;
		systemTime[Yellow] = systemTime[Red] - systemTime[Green];
	}
}

// Check if the counter < 100
void checkCounter(void){
	if(counter >= 100) counter = 1;
}
