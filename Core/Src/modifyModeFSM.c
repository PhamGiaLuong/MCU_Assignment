/*
 * modifyModeFSM.c
 *
 *  Created on: Nov 22, 2024
 *      Author: phamgialuong
 */

#include "modifyModeFSM.h"

void modifyModeFSM(void){
	switch(state){
	case WaitRed:
		if(isPressedOnButton(1)){
			increaseCounter();
			state = RedPressed;
		}
		if(hasJustLongPressedOnButton(0)){
			deleteTaskSch(updateLCD_ModifyRed);
			addTaskSch(updateLCD_ModifyGreen, 100, 300);
			deleteTaskSch(blinkRedLeds);
			addTaskSch(blinkGreenLeds, 100, 250);
			state = WaitGreen;
		}
		break;
	case RedReleased:
		checkCounter();
		if(isPressedOnButton(0)){
			if(getCounter() > 0) setSystemTime(Red);
			state = WaitRed;
		}
		if(isPressedOnButton(1)){
			increaseCounter();
			state = RedPressed;
		}
		break;
	case RedPressed:
		if(isPressedOnButton(1) == 0){
			state = RedReleased;
		}
		if(isLongPressedOnButton(1)){
			increaseCounter();
			addTaskSch(increaseCounter, 500, 500);
			state = RedLongPressed;
		}
		break;
	case RedLongPressed:
		if(isPressedOnButton(1) == 0){
			deleteTaskSch(increaseCounter);
			state = RedReleased;
		}
		break;
	case WaitGreen:
		if(isPressedOnButton(1)){
			increaseCounter();
			state = GreenPressed;
		}
		if(hasJustLongPressedOnButton(0)){
			deleteTaskSch(updateLCD_ModifyGreen);
			deleteTaskSch(blinkGreenLeds);
			deleteTaskSch(modifyModeFSM);
			// Print change mode info
			lcd_clear_display();
			addTaskSch(updateLCD_ChangeToAuto, 50, 0);
			// Prepare for next mode
			addTaskSch(lcd_clear_display, 2000, 0);
			addTaskSch(autoModeFSM, 100, 50);
			state = InitAuto;
		}
		break;
	case GreenReleased:
		checkCounter();
		if(isPressedOnButton(0)){
			if(getCounter() > 0) setSystemTime(Green);
			state = WaitGreen;
		}
		if(isPressedOnButton(1)){
			increaseCounter();
			state = GreenPressed;
		}
		break;
	case GreenPressed:
		if(isPressedOnButton(1) == 0){
			state = GreenReleased;
		}
		if(isLongPressedOnButton(1)){
			increaseCounter();
			addTaskSch(increaseCounter, 500, 500);
			state = GreenLongPressed;
		}
		break;
	case GreenLongPressed:
		if(isPressedOnButton(1) == 0){
			deleteTaskSch(increaseCounter);
			state = GreenReleased;
		}
		break;
	default:
		break;
	}
}

