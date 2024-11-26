/*
 * scheduler.c
 *
 *  Created on: Nov 11, 2024
 *      Author: phamgialuong
 *      Manual: set Tick's value in initScheduler function
 */

#include "scheduler.h"

// Timer interrupt duration (ms)
uint8_t schTick = 10;

taskNode* head = NULL;
uint8_t schedulerSize = 0;

taskNode* freeList = NULL;
uint8_t freeListSize = 0;

// Add used task memory to freeList
void freeTask(taskNode* task){
	if(freeListSize >= 10){
		free(task);
	}else{
		task->next = freeList;
		freeList = task;
		freeListSize++;
	}
}

// Allocate memory if freeList not NULL
taskNode* allocateTask(void){
	if(freeList == NULL) return NULL;
	taskNode* tmp = freeList;
	freeList = freeList->next;
	tmp->next = NULL;
	freeListSize--;
	return tmp;
}

// Set timer interrupt duration for Scheduler
void initScheduler(uint8_t timerInterruptDuration){
	schTick = timerInterruptDuration;
}

// Add new task to Scheduler
void addTaskSch(void (*taskFunction)(), uint32_t taskDelay, uint32_t taskPeriod){
	taskDelay = taskDelay / schTick;
	taskPeriod = taskPeriod / schTick;

	// Check if the same task is existed
	taskNode* tmp = deleteTaskSch(taskFunction);
	if(tmp == NULL){
		// If it's not found, allocate memory from freeList
		tmp = allocateTask();
		if(tmp == NULL){
			// If freeList is NULL, dynamic allocate
			tmp = (taskNode*)malloc(sizeof(taskNode));
		}
		tmp->pTask = taskFunction;
		tmp->delay = taskDelay;
		tmp->period = taskPeriod;
		tmp->runMe = 0;
		tmp->next = NULL;
		tmp->previous = NULL;
	}else{
		// If there's existed, update its delay
		// and re-add to task list
		tmp->delay = tmp->period;
	}

	if(schedulerSize == 0){
		// First node
		head = tmp;
		schedulerSize++;
	}else{
		if((tmp->delay < head->delay) || (tmp->delay==0 && head->delay!=0)){
			// Add first
			tmp->next = head;
			head->previous = tmp;
			head = tmp;
		}else{
			taskNode* node = head;
			uint32_t totalDelay = node->delay;
			while((totalDelay <= tmp->delay) && (node->next != NULL)){
				// Find suitable place
				totalDelay += node->next->delay;
				node = node->next;
			}
			if(node->next == NULL && totalDelay <= tmp->delay){
				// Add tail
				tmp->delay -= totalDelay;
				node->next = tmp;
				tmp->previous = node;
				schedulerSize++;
				return;
			}else{ // Add middle
				tmp->delay -= (totalDelay - node->delay);
				node->previous->next = tmp;
				tmp->previous = node->previous;
				tmp->next = node;
				node->previous = tmp;
			}
		}
		// If new node is not added at the end of linked list,
		// update the delay for it's next task
		tmp->next->delay -= tmp->delay;
		schedulerSize++;
	}
}

// Delete the task has the same function pointer
taskNode* deleteTaskSch(void (*taskFunction)()){
	if(schedulerSize >= 1){
		taskNode* tmp = head;
		if(taskFunction == head->pTask){
			// Delete first node of the list
			if(schedulerSize == 1){
				// One node list
				head = NULL;
			}else{ // More than 1 node list
				head = head->next;
				head->previous = NULL;
				tmp->next = NULL;
				if(tmp->delay > 0) head->delay += tmp->delay;
			}
		}else{
			while(tmp->pTask != taskFunction){
				tmp = tmp->next;
				if(tmp == NULL) return NULL;
			}
			if(tmp->next == NULL){
				// Delete node at the end of the list
				tmp->previous->next = NULL;
				tmp->previous = NULL;
			}else{ // Delete node in the middle of the list
				tmp->previous->next = tmp->next;
				tmp->next->previous = tmp->previous;
				tmp->next->delay += tmp->delay;
				tmp->next = NULL;
				tmp->previous = NULL;
			}
		}
		schedulerSize--;
		return tmp;
	}else{
		return NULL;
	}
}

// Update delay value of the first task of the list
// call at timer interrupt function
void updateSch(void){
	if(head != NULL){
		if(head->delay > 0) head->delay--;
		if(head->delay <= 0){
			head->runMe++;
		}
	}
}

// Run task if it's delay is greater than 0
void dispatchTaskSch(void){
	if(head != NULL && head->runMe > 0){
		(*head->pTask)();
		head->runMe--;
		if(head->period > 0){
			addTaskSch(head->pTask, head->period*schTick, head->period*schTick);
		}else{
			freeTask(deleteTaskSch(head->pTask));
		}
		// Handling the case that more than 1 task are scheduled at once time
		while(head->delay == 0){
			(*head->pTask)();
			if(head->period > 0){
				addTaskSch(head->pTask, head->period*schTick, head->period*schTick);
			}else{
				freeTask(deleteTaskSch(head->pTask));
			}
			if(head == NULL) return;
		}
	}
}
