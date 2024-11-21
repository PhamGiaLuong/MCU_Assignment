/*
 * displayLCD.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phamgialuong
 */

#include "displayLCD.h"

char row1[20] = "";
char row2[20] = "";

// Display on LCD the next mode after change
// targetMode: next mode
void updateLCD_Change(uint8_t targetMode){
	sprintf(row1, "Changing to...");
	lcd_goto_XY(0, 0);
	lcd_send_string(row1);

	switch(targetMode){
	case AutoMode:
		sprintf(row2, "Auto Mode");
		lcd_goto_XY(1, 4);
		lcd_send_string(row2);
		break;
	case ModifyMode:
		sprintf(row2, "Modify Mode");
		lcd_goto_XY(1, 2);
		lcd_send_string(row2);
		break;
	case ManualMode:
		sprintf(row2, "Manual Mode");
		lcd_goto_XY(1, 2);
		lcd_send_string(row2);
		break;
	default:
		sprintf(row2, "undefine...");
		lcd_goto_XY(1, 2);
		lcd_send_string(row2);
		break;
	}
}

// Display info on LCD in Auto mode
void updateLCD_AutoMode(void){
	lcd_goto_XY(0, 0);
	sprintf(row1, "Lane X:    %d", getTimeCounter(X));
	lcd_send_string(row1);
	lcd_goto_XY(1, 0);
	sprintf(row2, "Lane Y:    %d", getTimeCounter(Y));
	lcd_send_string(row2);
}

// Display info on LCD in Modify mode
// color: Red, Green
void updateLCD_ModifyMode(uint8_t color){
	lcd_goto_XY(0, 0);

	switch(color){
	case Red:
		sprintf(row1, "Modify on Red");
		lcd_send_string(row1);
		break;
	case Green:
		sprintf(row1, "Modify on Green");
		lcd_send_string(row1);
		break;
	default:
		sprintf(row1, "Modify on ...");
		lcd_send_string(row1);
		break;
	}

	lcd_goto_XY(1, 0);
	sprintf(row2, "Value:    %d", getCounter());
	lcd_send_string(row2);
}

// Display info on LCD in Manual mode
void updateLCD_ManualMode(void){
//	the same as auto mode
}

