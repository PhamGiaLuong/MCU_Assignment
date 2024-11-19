/*
 * global.h
 *
 *  Created on: Nov 19, 2024
 *      Author: phamgialuong
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdio.h>
#include <stdint.h>
#include "main.h"
#include "I2C_LCD.h"
#include "trafficLight.h"

// Lane
#define X 0
#define Y 1

// Led color
#define Red		0
#define Green	1
#define Yellow	2

// Mode
#define AutoMode 	5
#define ModifyMode	6
#define ManualMode	7

void setSystemTime(uint8_t color);
void resetTimeCounter(uint8_t lane, uinr8_t color);
uint8_t getTimeCounter(uint8_t lane);
void decreaseTimeCounter(uint8_t lane);
void increaseCounter(void);
void resetCounter(void);
uint8_t getCounter(void);
void checkSystemTime(void);
void checkCounter(void);

#endif /* INC_GLOBAL_H_ */
