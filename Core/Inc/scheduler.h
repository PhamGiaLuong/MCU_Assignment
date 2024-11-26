/*
 * scheduler.h
 *
 *  Created on: Nov 11, 2024
 *      Author: phamgialuong
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct task{
	void (*pTask)(void);
	uint32_t delay;
	uint32_t period;
	uint8_t runMe;

	struct task* next;
	struct task* previous;
} taskNode;

void initScheduler(uint8_t timerInterruptDuration);
void addTaskSch(void (*taskFunction)(), uint32_t taskDelay, uint32_t taskPeriod);
taskNode* deleteTaskSch(void (*taskFunction)());
void updateSch(void);
void dispatchTaskSch(void);

#endif /* INC_SCHEDULER_H_ */
