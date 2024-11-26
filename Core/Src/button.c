/*
 * button.c
 *
 *  Created on: Oct 27, 2024
 *      Author: phamgialuong
 *      Manual: call initButton function before using
 *      		modify readPin function to fit with pin configuration
 */

#include "button.h"

// The number of buttons
#define maxButton 10
uint8_t numberOfButton = 3;
uint8_t buttonTick = 0;

// Buttons' buffers for de-bouncing
static GPIO_PinState buttonBuffer[maxButton] = {buttonIsReleased};
static GPIO_PinState debounceBuffer1[maxButton] = {buttonIsReleased};
static GPIO_PinState debounceBuffer2[maxButton] = {buttonIsReleased};
static GPIO_PinState debounceBuffer3[maxButton] = {buttonIsReleased};

// For long press handle
uint16_t longPressDurationTime = 100; //time duration for long press: 100x10ms
static uint16_t counterForLongPressButton[maxButton];
static uint8_t flagForLongPressButton[maxButton];

// Initial the number of button and time duration for long press
void initButton(uint8_t numOfButton, uint16_t durationForLongPress, uint8_t Tick){
	if(numOfButton <= maxButton) numberOfButton = numOfButton;
	else numberOfButton = maxButton;
	buttonTick = Tick;
	longPressDurationTime = durationForLongPress/buttonTick;
}

// Read button's state
GPIO_PinState readPin(uint8_t button){
	GPIO_PinState result = GPIO_PIN_SET;
	switch(button){
	case 0:
		result = HAL_GPIO_ReadPin(GPIOB, Button0_Pin);
		break;
	case 1:
		result = HAL_GPIO_ReadPin(GPIOB, Button1_Pin);
		break;
	default:
		break;
	}
	return result;
}

// Handle buttons (three times reading)
void buttonReading(void){
	for(uint8_t i = 0; i < numberOfButton; i++){
		debounceBuffer3[i] = debounceBuffer2[i];
		debounceBuffer2[i] = debounceBuffer1[i];
		debounceBuffer1[i] = readPin(i);
		if((debounceBuffer1[i] == debounceBuffer2[i]) && (debounceBuffer2[i] == debounceBuffer3[i])){
			buttonBuffer[i] = debounceBuffer1[i];
		}
		if(buttonBuffer[i] == buttonIsPressed){
			if(counterForLongPressButton[i] < longPressDurationTime){
				counterForLongPressButton[i]++;
			}else{
				flagForLongPressButton[i] = 1;
			}
		}else{
			counterForLongPressButton[i] = 0;
			flagForLongPressButton[i] = 0;
		}
	}
}

// Check if the button is pressed
unsigned char isPressedOnButton(uint8_t index){
	if(index >= numberOfButton) return 0;
	return (buttonBuffer[index] == buttonIsPressed) ? 1 : 0;
}

// Check if the button is pressed longer
unsigned char isLongPressedOnButton(uint8_t index){
	if(index >= numberOfButton) return 0xff;
	return (flagForLongPressButton[index] == 1) ? 1 : 0;
}

// Buffer for rising signal detection
static uint8_t lastSignalPress[maxButton];
static uint8_t currentSignalPress[maxButton];

static uint8_t lastSignalLongPress[maxButton];
static uint8_t currentSignalLongPress[maxButton];

// Check for the rising signal on press flag
uint8_t hasJustPressedOnButton(uint8_t index){
	lastSignalPress[index] = currentSignalPress[index];
	currentSignalPress[index] = isPressedOnButton(index);
	if(lastSignalPress[index]==0 && currentSignalPress[index]==1)
		return 1;
	return 0;
}

// Check for the rising signal on long press flag
uint8_t hasJustLongPressedOnButton(uint8_t index){
	lastSignalLongPress[index] = currentSignalLongPress[index];
	currentSignalLongPress[index] = isLongPressedOnButton(index);
	if(lastSignalLongPress[index]==0 && currentSignalLongPress[index]==1)
		return 1;
	return 0;
}
