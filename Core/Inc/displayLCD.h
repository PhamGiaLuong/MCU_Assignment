/*
 * displayLCD.h
 *
 *  Created on: Nov 19, 2024
 *      Author: phamgialuong
 */

#ifndef INC_DISPLAYLCD_H_
#define INC_DISPLAYLCD_H_

#include "global.h"
#include "I2C_LCD.h"

void updateLCD_ChangeToAuto(void);
void updateLCD_ChangeToModify(void);
void updateLCD_ChangeToManual(void);
void updateLCD_ManualMode(void);
void updateLCD_TrafficTime(void);
void updateLCD_ModifyRed(void);
void updateLCD_ModifyGreen(void);


#endif /* INC_DISPLAYLCD_H_ */
