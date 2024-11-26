/*
 * trafficLight.c
 *
 *  Created on: Nov 19, 2024
 *      Author: phamgialuong
 */

#include "trafficLight.h"

// Turn led on lane
// color: Red, Green, Yellow
// lane: X, Y
void turnLed(uint8_t lane, uint8_t color){
	switch(lane){
	case X: // Lane X
		switch(color){
		case Red:
			HAL_GPIO_WritePin(GPIOB, LaneX_A_Pin, 1);
			HAL_GPIO_WritePin(GPIOC, LaneX_B_Pin, 1);
			break;
		case Green:
			HAL_GPIO_WritePin(GPIOB, LaneX_A_Pin, 0);
			HAL_GPIO_WritePin(GPIOC, LaneX_B_Pin, 1);
			break;
		case Yellow:
			HAL_GPIO_WritePin(GPIOB, LaneX_A_Pin, 1);
			HAL_GPIO_WritePin(GPIOC, LaneX_B_Pin, 0);
			break;
		default:
			break;
		}
		break;
	case Y: // Lane Y
		switch(color){
		case Red:
			HAL_GPIO_WritePin(GPIOA, LaneY_A_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LaneY_B_Pin, 1);
			break;
		case Green:
			HAL_GPIO_WritePin(GPIOA, LaneY_A_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, LaneY_B_Pin, 1);
			break;
		case Yellow:
			HAL_GPIO_WritePin(GPIOA, LaneY_A_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LaneY_B_Pin, 0);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

uint8_t toggle = 1;

// Blinking Red leds
void blinkRedLeds(void){
	if(toggle == 1){
		turnLed(X, Red);
		turnLed(Y, Red);
		toggle = 0;
	}else{
		clearAllLeds();
		toggle = 1;
	}
}

// Blinking Green leds
void blinkGreenLeds(void){
	if(toggle == 1){
		turnLed(X, Green);
		turnLed(Y, Green);
		toggle = 0;
	}else{
		clearAllLeds();
		toggle = 1;
	}
}


// Turn off all traffic leds
void clearAllLeds(void){
	HAL_GPIO_WritePin(GPIOA, LaneY_A_Pin | LaneY_B_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, LaneX_A_Pin, 0);
	HAL_GPIO_WritePin(GPIOC, LaneX_B_Pin, 0);
}

