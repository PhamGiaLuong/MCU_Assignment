/*
 * displayLCD.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phamgialuong
 */

#include "displayLCD.h"

char row1[20] = "";
char row2[20] = "";

// Display on LCD the next mode is Automatic
void updateLCD_ChangeToAuto(void){
	sprintf(row1, "Changing to...");
	lcd_goto_XY(0, 0);
	lcd_send_string(row1);

	sprintf(row2, "Auto Mode");
	lcd_goto_XY(1, 4);
	lcd_send_string(row2);
}

// Display on LCD the next mode is Modify
void updateLCD_ChangeToModify(void){
	sprintf(row1, "Changing to...");
	lcd_goto_XY(0, 0);
	lcd_send_string(row1);

	sprintf(row2, "Modify Mode");
	lcd_goto_XY(1, 2);
	lcd_send_string(row2);
}

// Display on LCD the next mode is Manual
void updateLCD_ChangeToManual(void){
	sprintf(row1, "Changing to...");
	lcd_goto_XY(0, 0);
	lcd_send_string(row1);

	sprintf(row2, "Manual Mode");
	lcd_goto_XY(1, 2);
	lcd_send_string(row2);
}

// Display on LCD remaining time in Manual
void updateLCD_ManualMode(void){
	lcd_goto_XY(0, 0);
	sprintf(row1, "Manual mode");
	lcd_send_string(row1);

	lcd_goto_XY(1, 0);
	sprintf(row2, "Remain:    %d ", getCounter());
	lcd_send_string(row2);
}

// Display on LCD current time counter
void updateLCD_TrafficTime(void){
	lcd_goto_XY(0, 0);
	sprintf(row1, "Lane X:    %d ", getTimeCounter(X));
	lcd_send_string(row1);
	lcd_goto_XY(1, 0);
	sprintf(row2, "Lane Y:    %d ", getTimeCounter(Y));
	lcd_send_string(row2);
}

// Display info on LCD about Modify Red time
void updateLCD_ModifyRed(void){
	lcd_goto_XY(0, 0);
	sprintf(row1, "Modify on Red");
	lcd_send_string(row1);

	lcd_goto_XY(1, 0);
	sprintf(row2, "Value:    %d ", getCounter());
	lcd_send_string(row2);
}

// Display info on LCD about Modify Green time
void updateLCD_ModifyGreen(void){
	lcd_goto_XY(0, 0);
	sprintf(row1, "Modify on Green");
	lcd_send_string(row1);

	lcd_goto_XY(1, 0);
	sprintf(row2, "Value:    %d ", getCounter());
	lcd_send_string(row2);
}
