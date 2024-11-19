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
			HAL_GPIO_WritePin(GPIOB, LaneX_A_Pin, 1);
			HAL_GPIO_WritePin(GPIOC, LaneX_B_Pin, 0);
			break;
		case Yellow:
			HAL_GPIO_WritePin(GPIOB, LaneX_A_Pin, 0);
			HAL_GPIO_WritePin(GPIOC, LaneX_B_Pin, 1);
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
			HAL_GPIO_WritePin(GPIOA, LaneY_A_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LaneY_B_Pin, 0);
			break;
		case Yellow:
			HAL_GPIO_WritePin(GPIOA, LaneY_A_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, LaneY_B_Pin, 1);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

// Pre-process for blinking led[color]
// color: Red, Green, Yellow
// Note: call this function ahead of toggleTrafficLights function
// 		for only the first time of blinking mode for each led
void blinkLed(uint8_t color){
	switch(color){
	case Red:
		HAL_GPIO_WritePin(GPIOA, LaneY_A_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LaneY_B_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LaneX_A_Pin, 1);
		HAL_GPIO_WritePin(GPIOC, LaneX_B_Pin, 1);
		break;
	case Green:
		HAL_GPIO_WritePin(GPIOA, LaneY_A_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LaneY_B_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, LaneX_A_Pin, 1);
		HAL_GPIO_WritePin(GPIOC, LaneX_B_Pin, 0);
		break;
	case Yellow:
		HAL_GPIO_WritePin(GPIOA, LaneY_A_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LaneY_B_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, LaneX_A_Pin, 0);
		HAL_GPIO_WritePin(GPIOC, LaneX_B_Pin, 1);
		break;
	default:
		break;
	}
}

// Toggle the output signal of leds for blinky animation
void toggleTrafficLights(void){
	HAL_GPIO_TogglePin(GPIOA, LaneY_A_Pin | LaneY_B_Pin);
	HAL_GPIO_TogglePin(GPIOB, LaneX_A_Pin);
	HAL_GPIO_TogglePin(GPIOC, LaneX_B_Pin);
}

// Turn off all traffic leds
void clearAllLeds(void){
	HAL_GPIO_WritePin(GPIOA, LaneY_A_Pin | LaneY_B_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, LaneX_A_Pin, 0);
	HAL_GPIO_WritePin(GPIOC, LaneX_B_Pin, 0);
}

