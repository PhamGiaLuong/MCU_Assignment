/*
 * displayLCD.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phamgialuong
 */

#include "displayLCD.h"

// Display on LCD the next mode after change
// targetMode: next mode
void updateLCD_Change(uint8_t targetMode){
	char str[20];
	sprintf(str, "Changing to...");
	lcd_goto_XY(1, 1);
	lcd_send_string(str);

	switch(targetMode){
	case AutoMode:
		sprintf(str, "Auto Mode");
		lcd_goto_XY(2, 4);
		lcd_send_string(str);
		break;
	case ModifyMode:
		sprintf(str, "Modify Mode");
		lcd_goto_XY(2, 2);
		lcd_send_string(str);
		break;
	case ManualMode:
		sprintf(str, "Manual Mode");
		lcd_goto_XY(2, 2);
		lcd_send_string(str);
		break;
	default:
		sprintf(str, "undefine...");
		lcd_goto_XY(2, 2);
		lcd_send_string(str);
		break;
	}
}

// Display info on LCD in Auto mode
void updateLCD_AutoMode(void){
	char str1[15];
	char str2[15];
	lcd_goto_XY(1, 0);
	sprintf(str1, "Lane X:  %d", getTimeCounter(X));
	lcd_send_string(str1);
	lcd_goto_XY(2, 0);
	sprintf(str2, "Lane Y:  %d", getTimeCounter(Y));
	lcd_send_string(str2);
}

// Display info on LCD in Modify mode
// color: Red, Green
void updateLCD_ModifyMode(uint8_t color){
	char str[20];
	lcd_goto_XY(1, 0);

	switch(color){
	case Red:
		sprintf(str, "Modify on Red");
		lcd_send_string(str);
		break;
	case Green:
		sprintf(str, "Modify on Green");
		lcd_send_string(str);
		break;
	default:
		sprintf(str, "Modify on ...");
		lcd_send_string(str);
		break;
	}

	lcd_goto_XY(2, 0);
	sprintf(str, "Value:  %d", getCounter());
}

// Display info on LCD in Manual mode
void updateLCD_ManualMode(void){
//	the same as auto mode
}

