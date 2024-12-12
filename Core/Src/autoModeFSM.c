/*
 * autoModeFSM.c
 *
 *  Created on: Nov 21, 2024
 *      Author: phamgialuong
 */

#include "autoModeFSM.h"

void changeToManualMode(void){
	deleteTaskSch(updateLCD_TrafficTime);
	// Print change state info on LCD
	lcd_clear_display();
	addTaskSch(updateLCD_ChangeToManual, 100, 0);
	// Prepare for next mode
	addTaskSch(lcd_clear_display, 2000, 0);
	addTaskSch(updateLCD_ManualMode, 2100, 300);
	addTaskSch(decreaseCounter, 2150, 1000);
	setManualCounter();
	turnLed(X, Red);
	turnLed(Y, Green);

	manualState = Man_RedGreen;
	autoState = Sleep;
}

void autoModeFSM(void){
	switch(autoState){
	case InitAuto:
		checkSystemTime();
		turnLed(X, Red);
		turnLed(Y, Green);
		resetTimeCounter(X, Red);
		resetTimeCounter(Y, Green);
		autoState = Auto_RedGreen;
		break;
	case Auto_RedGreen:
		// Change to next state
		if(getTimeCounter(Y) <= 0){
			turnLed(Y, Yellow);
			resetTimeCounter(Y, Yellow);
			autoState = Auto_RedYellow;
		}
		// Change to Manual mode
		if(hasJustLongPressedOnButton(0)){
			changeToManualMode();
		}
		break;
	case Auto_RedYellow:
		// Change to next state
		if(getTimeCounter(X) <= 0){
			turnLed(X, Green);
			turnLed(Y, Red);
			resetTimeCounter(X, Green);
			resetTimeCounter(Y, Red);
			autoState = Auto_GreenRed;
		}
		// Change to Manual mode
		if(hasJustLongPressedOnButton(0)){
			changeToManualMode();
		}
		break;
	case Auto_GreenRed:
		// Change to next state
		if(getTimeCounter(X) <= 0){
			turnLed(X, Yellow);
			resetTimeCounter(X, Yellow);
			autoState = Auto_YellowRed;
		}
		// Change to Manual mode
		if(hasJustLongPressedOnButton(0)){
			changeToManualMode();
		}
		break;
	case Auto_YellowRed:
		// Change to next state
		if(getTimeCounter(X) <= 0){
			turnLed(X, Red);
			turnLed(Y, Green);
			resetTimeCounter(X, Red);
			resetTimeCounter(Y, Green);
			autoState = Auto_RedGreen;
		}
		// Change to Manual mode
		if(hasJustLongPressedOnButton(0)){
			changeToManualMode();
		}
		break;
	default:
		break;
	}
}
