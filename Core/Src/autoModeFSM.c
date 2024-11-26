/*
 * autoModeFSM.c
 *
 *  Created on: Nov 21, 2024
 *      Author: phamgialuong
 */

#include "autoModeFSM.h"

void autoModeFSM(void){
	switch(state){
	case InitAuto:
		checkSystemTime();
		turnLed(X, Red);
		turnLed(Y, Green);
		resetTimeCounter(X, Red);
		resetTimeCounter(Y, Green);
		addTaskSch(decreaseTimeCounter, 2000, 1000);
		addTaskSch(updateLCD_TrafficTime, 2100, 300);
		state = Auto_RedGreen;
		break;
	case Auto_RedGreen:
		if(getTimeCounter(Y) <= 0){
			turnLed(Y, Yellow);
			resetTimeCounter(Y, Yellow);
			state = Auto_RedYellow;
		}
		break;
	case Auto_RedYellow:
		if(getTimeCounter(X) <= 0){
			turnLed(X, Green);
			turnLed(Y, Red);
			resetTimeCounter(X, Green);
			resetTimeCounter(Y, Red);
			state = Auto_GreenRed;
		}
		break;
	case Auto_GreenRed:
		if(getTimeCounter(X) <= 0){
			turnLed(X, Yellow);
			resetTimeCounter(X, Yellow);
			state = Auto_YellowRed;
		}
		break;
	case Auto_YellowRed:
		if(getTimeCounter(X) <= 0){
			turnLed(X, Red);
			turnLed(Y, Green);
			resetTimeCounter(X, Red);
			resetTimeCounter(Y, Green);
			state = Auto_RedGreen;
		}
		break;
	default:
		break;
	}
	if(hasJustLongPressedOnButton(0)){
		deleteTaskSch(autoModeFSM);
		deleteTaskSch(updateLCD_TrafficTime);
		// Print change state info on LCD
		lcd_clear_display();
		addTaskSch(updateLCD_ChangeToManual, 100, 0);
		// Prepare for next mode
		addTaskSch(lcd_clear_display, 2000, 0);
		addTaskSch(updateLCD_ManualMode, 2100, 300);
		addTaskSch(setManualCounter, 2050, 0);
		addTaskSch(decreaseCounter, 2050, 1000);
		turnLed(X, Red);
		turnLed(Y, Green);

		addTaskSch(manualModeFSM, 200, 50);
		state = Man_RedGreen;
	}
}
