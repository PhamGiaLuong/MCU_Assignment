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

void updateLCD_Change(uint8_t targetMode);
void updateLCD_AutoMode(void);
void updateLCD_ModifyMode(uint8_t color);
void updateLCD_ManualMode(void);


#endif /* INC_DISPLAYLCD_H_ */
