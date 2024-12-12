/*
 * modifyModeFSM.c
 *
 *  Created on: Nov 22, 2024
 *      Author: phamgialuong
 */

#include "modifyModeFSM.h"

void modifyModeFSM(void){
	switch(modifyState){
	case WaitRed:
		if(isPressedOnButton(1)){
			increaseCounter();
			modifyState = RedPressed;
		}
		if(hasJustLongPressedOnButton(0)){
			deleteTaskSch(updateLCD_ModifyRed);
			addTaskSch(updateLCD_ModifyGreen, 100, 300);
			deleteTaskSch(blinkRedLeds);
			addTaskSch(blinkGreenLeds, 100, 250);
			modifyState = WaitGreen;
		}
		break;
	case RedReleased:
		checkCounter();
		if(isPressedOnButton(0)){
			if(getCounter() > 0) setSystemTime(Red);
			modifyState = WaitRed;
		}
		if(isPressedOnButton(1)){
			increaseCounter();
			modifyState = RedPressed;
		}
		break;
	case RedPressed:
		if(isPressedOnButton(1) == 0){
			modifyState = RedReleased;
		}
		if(isLongPressedOnButton(1)){
			increaseCounter();
			addTaskSch(increaseCounter, 500, 500);
			modifyState = RedLongPressed;
		}
		break;
	case RedLongPressed:
		if(isPressedOnButton(1) == 0){
			deleteTaskSch(increaseCounter);
			modifyState = RedReleased;
		}
		break;
	case WaitGreen:
		if(isPressedOnButton(1)){
			increaseCounter();
			modifyState = GreenPressed;
		}
		if(hasJustLongPressedOnButton(0)){
			deleteTaskSch(updateLCD_ModifyGreen);
			deleteTaskSch(blinkGreenLeds);
			// Print change mode info
			lcd_clear_display();
			addTaskSch(updateLCD_ChangeToAuto, 50, 0);
			// Prepare for next mode
			addTaskSch(lcd_clear_display, 2000, 0);
			addTaskSch(updateLCD_TrafficTime, 2050, 300);
			autoState = InitAuto;
			modifyState = Sleep;
		}
		break;
	case GreenReleased:
		checkCounter();
		if(isPressedOnButton(0)){
			if(getCounter() > 0) setSystemTime(Green);
			modifyState = WaitGreen;
		}
		if(isPressedOnButton(1)){
			increaseCounter();
			modifyState = GreenPressed;
		}
		break;
	case GreenPressed:
		if(isPressedOnButton(1) == 0){
			modifyState = GreenReleased;
		}
		if(isLongPressedOnButton(1)){
			increaseCounter();
			addTaskSch(increaseCounter, 500, 500);
			modifyState = GreenLongPressed;
		}
		break;
	case GreenLongPressed:
		if(isPressedOnButton(1) == 0){
			deleteTaskSch(increaseCounter);
			modifyState = GreenReleased;
		}
		break;
	default:
		break;
	}
}

