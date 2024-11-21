/*
 * button.h
 *
 *  Created on: Oct 27, 2024
 *      Author: phamgialuong
 *      Manual:
 *      	- Fix readPin function according to pin configuration
 *      	- Call initButton function before using
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

// Buttons' state
#define buttonIsPressed GPIO_PIN_RESET
#define buttonIsReleased GPIO_PIN_SET

void initButton(uint8_t numOfButton, uint16_t durationForLongPress, uint8_t Tick);
void buttonReading(void);
unsigned char isPressedOnButton(uint8_t index);
unsigned char isLongPressedOnButton(uint8_t index);

#endif /* INC_BUTTON_H_ */
