/*
 * manualModeFSM.c
 *
 *  Created on: Nov 22, 2024
 *      Author: phamgialuong
 */

#include "manualModeFSM.h"

void manualModeFSM(void){
	switch(state){
	case Man_RedGreen:
		// Reset remain time
		if(hasJustPressedOnButton(0)){
			setManualCounter();
		}
		// Remain time expired
		if(getCounter() <= 0){
			deleteTaskSch(manualModeFSM);
			deleteTaskSch(updateLCD_ManualMode);
			deleteTaskSch(decreaseCounter);
			// Print change mode info
			lcd_clear_display();
			addTaskSch(updateLCD_ChangeToAuto, 50, 0);
			// Prepare for next mode
			resetTimeCounter(X, Red);
			resetTimeCounter(Y, Green);
			addTaskSch(lcd_clear_display, 2000, 0);
			addTaskSch(updateLCD_TrafficTime, 2100, 300);
			addTaskSch(decreaseTimeCounter, 2100, 1000);
			addTaskSch(autoModeFSM, 200, 50);
			state = Auto_RedGreen;
		}
		// Go to Modify mode
		if(hasJustLongPressedOnButton(0)){
			deleteTaskSch(manualModeFSM);
			deleteTaskSch(updateLCD_ManualMode);
			deleteTaskSch(decreaseCounter);
			// Print change mode info
			lcd_clear_display();
			addTaskSch(updateLCD_ChangeToModify, 50, 0);
			// Prepare for next mode
			addTaskSch(lcd_clear_display, 2000, 0);
			addTaskSch(updateLCD_ModifyRed, 2100, 300);
			addTaskSch(modifyModeFSM, 200, 50);
			addTaskSch(blinkRedLeds, 200, 250);
			resetCounter();
			state = WaitRed;
		}
		if(hasJustPressedOnButton(1)){
			deleteTaskSch(updateLCD_ManualMode);
			// Prepare for next mode
			turnLed(Y, Yellow);
			resetTimeCounter(X, Yellow);
			resetTimeCounter(Y, Yellow);
			lcd_clear_display();
			addTaskSch(updateLCD_TrafficTime, 100, 300);
			addTaskSch(decreaseTimeCounter, 1000, 1000);
			state = Man_RedYellow;
		}
		break;
	case Man_RedYellow:
		if(getTimeCounter(X) <= 0){
			deleteTaskSch(decreaseTimeCounter);
			deleteTaskSch(updateLCD_TrafficTime);
			lcd_clear_display();
			addTaskSch(updateLCD_ManualMode, 100, 300);
			addTaskSch(decreaseCounter, 100, 1000);
			setManualCounter();
			turnLed(X, Green);
			turnLed(Y, Red);
			state = Man_GreenRed;
		}
		break;
	case Man_GreenRed:
		// Reset remain time
		if(hasJustPressedOnButton(0)){
			setManualCounter();
		}
		// Remain time expired
		if(getCounter() <= 0){
			deleteTaskSch(manualModeFSM);
			deleteTaskSch(updateLCD_ManualMode);
			deleteTaskSch(decreaseCounter);
			// Print change mode info
			lcd_clear_display();
			addTaskSch(updateLCD_ChangeToAuto, 50, 0);
			// Prepare for next mode
			resetTimeCounter(X, Green);
			resetTimeCounter(Y, Red);
			addTaskSch(lcd_clear_display, 2000, 0);
			addTaskSch(updateLCD_TrafficTime, 2100, 300);
			addTaskSch(decreaseTimeCounter, 2100, 1000);
			addTaskSch(autoModeFSM, 200, 50);
			state = Auto_GreenRed;
		}
		// Go to Modify mode
		if(hasJustLongPressedOnButton(0)){
			deleteTaskSch(manualModeFSM);
			deleteTaskSch(updateLCD_ManualMode);
			deleteTaskSch(decreaseCounter);
			// Print change mode info
			lcd_clear_display();
			addTaskSch(updateLCD_ChangeToModify, 50, 0);
			// Prepare for next mode
			addTaskSch(lcd_clear_display, 2000, 0);
			addTaskSch(updateLCD_ModifyRed, 2100, 300);
			addTaskSch(modifyModeFSM, 200, 50);
			addTaskSch(blinkRedLeds, 200, 250);
			resetCounter();
			state = WaitRed;
		}
		if(hasJustPressedOnButton(1)){
			deleteTaskSch(updateLCD_ManualMode);
			// Prepare for next mode
			turnLed(Y, Yellow);
			resetTimeCounter(X, Yellow);
			resetTimeCounter(Y, Yellow);
			lcd_clear_display();
			addTaskSch(updateLCD_TrafficTime, 100, 300);
			addTaskSch(decreaseTimeCounter, 1000, 1000);
			state = Man_YellowRed;
		}
		break;
	case Man_YellowRed:
		if(getTimeCounter(X) <= 0){
			deleteTaskSch(decreaseTimeCounter);
			deleteTaskSch(updateLCD_TrafficTime);
			lcd_clear_display();
			addTaskSch(updateLCD_ManualMode, 100, 300);
			addTaskSch(decreaseCounter, 100, 1000);
			setManualCounter();
			turnLed(X, Red);
			turnLed(Y, Green);

			state = Man_RedGreen;
		}
		break;
	default:
		break;
	}
}

