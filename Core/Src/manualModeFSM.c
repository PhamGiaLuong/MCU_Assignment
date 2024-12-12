/*
 * manualModeFSM.c
 *
 *  Created on: Nov 22, 2024
 *      Author: phamgialuong
 */

#include "manualModeFSM.h"

void remainingTimeExpired(void){
	deleteTaskSch(updateLCD_ManualMode);
	deleteTaskSch(decreaseCounter);
	// Print change mode info
	lcd_clear_display();
	addTaskSch(updateLCD_ChangeToAuto, 50, 0);
	// Prepare for next mode
	addTaskSch(lcd_clear_display, 2000, 0);
	addTaskSch(updateLCD_TrafficTime, 2100, 300);
	addTaskSch(decreaseTimeCounter, 2100, 1000);
}

void changeToModifyMode(void){
	deleteTaskSch(updateLCD_ManualMode);
	deleteTaskSch(decreaseCounter);
	// Print change mode info
	lcd_clear_display();
	addTaskSch(updateLCD_ChangeToModify, 50, 0);
	// Prepare for next mode
	addTaskSch(lcd_clear_display, 2000, 0);
	addTaskSch(updateLCD_ModifyRed, 2100, 300);
	addTaskSch(blinkRedLeds, 200, 250);
	resetCounter();
	modifyState = WaitRed;
}

void changeToAmberState(void){
	deleteTaskSch(updateLCD_ManualMode);
	// Prepare for next state
	resetTimeCounter(X, Yellow);
	resetTimeCounter(Y, Yellow);
	lcd_clear_display();
	addTaskSch(updateLCD_TrafficTime, 100, 300);
	addTaskSch(decreaseTimeCounter, 1000, 1000);
}

void changeToNextState(uint8_t x, uint8_t y){
	deleteTaskSch(updateLCD_TrafficTime);
	lcd_clear_display();
	addTaskSch(updateLCD_ManualMode, 100, 300);
	addTaskSch(decreaseCounter, 100, 1000);
	setManualCounter();
	turnLed(X, x);
	turnLed(Y, y);
}

void manualModeFSM(void){
	switch(manualState){
	case Man_RedGreen:
		// Extend remaining time
		if(hasJustPressedOnButton(1)){
			extendManualCounter();
		}
		// Remaining time expired
		if(getCounter() <= 0){
			remainingTimeExpired();
			resetTimeCounter(X, Red);
			resetTimeCounter(Y, Green);
			autoState = Auto_RedGreen;
			manualState = Sleep;
		}
		// Change to Modify mode
		if(hasJustLongPressedOnButton(0)){
			changeToModifyMode();
			manualState = Sleep;
		}
		// Change to next state
		if(hasJustLongPressedOnButton(1)){
			changeToAmberState();
			turnLed(Y, Yellow);
			manualState = Man_RedYellow;
		}
		break;
	case Man_RedYellow:
		if(getTimeCounter(X) <= 0){
			changeToNextState(Green, Red);
			manualState = Man_GreenRed;
		}
		break;
	case Man_GreenRed:
		// Extend remaining time
		if(hasJustPressedOnButton(1)){
			extendManualCounter();
		}
		// Remaining time expired
		if(getCounter() <= 0){
			remainingTimeExpired();
			resetTimeCounter(X, Green);
			resetTimeCounter(Y, Red);
			autoState = Auto_GreenRed;
			manualState = Sleep;
		}
		// Change to Modify mode
		if(hasJustLongPressedOnButton(0)){
			changeToModifyMode();
			manualState = Sleep;
		}
		// Change to next state
		if(hasJustLongPressedOnButton(1)){
			changeToAmberState();
			turnLed(X, Yellow);
			manualState = Man_YellowRed;
		}
		break;
	case Man_YellowRed:
		if(getTimeCounter(X) <= 0){
			changeToNextState(Red, Green);
			manualState = Man_RedGreen;
		}
		break;
	default:
		break;
	}
}

