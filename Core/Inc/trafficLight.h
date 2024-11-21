/*
 * trafficLight.h
 *
 *  Created on: Nov 19, 2024
 *      Author: phamgialuong
 */

#ifndef INC_TRAFFICLIGHT_H_
#define INC_TRAFFICLIGHT_H_

#include "global.h"

void turnLed(uint8_t lane, uint8_t color);
void blinkLed(uint8_t color);
//void toggleTrafficLights(void);
void clearAllLeds(void);

#endif /* INC_TRAFFICLIGHT_H_ */
