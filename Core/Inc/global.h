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
#include "displayLCD.h"
#include "trafficLight.h"
#include "button.h"
#include "scheduler.h"
#include "autoModeFSM.h"
#include "manualModeFSM.h"
#include "modifyModeFSM.h"

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

enum systemStates {InitAuto, Sleep,
					Auto_RedGreen, Auto_RedYellow, Auto_GreenRed, Auto_YellowRed,
					Man_RedGreen, Man_RedYellow, Man_GreenRed, Man_YellowRed,
					WaitRed, RedReleased, RedPressed, RedLongPressed,
					WaitGreen, GreenReleased, GreenPressed, GreenLongPressed};
extern enum systemStates autoState;
extern enum systemStates manualState;
extern enum systemStates modifyState;

extern uint8_t timeFlag;

void setSystemTime(uint8_t color);
void resetTimeCounter(uint8_t lane, uint8_t color);
void clearTimeCounter(void);
uint8_t getTimeCounter(uint8_t lane);
void decreaseTimeCounter(void);
void increaseCounter(void);
void decreaseCounter(void);
void setManualCounter(void);
void extendManualCounter(void);
void resetCounter(void);
uint8_t getCounter(void);
void checkSystemTime(void);
void checkCounter(void);
void setTimeFlag(void);

#endif /* INC_GLOBAL_H_ */
