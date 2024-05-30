#pragma once

#include <map>
#include <stdint.h>
#include "tim.h"


typedef struct {
	void (*p_irq_tim_func) (void); // указатель на обработчик прерывания
	void (*p_irq_processing) (void); // указатель на функцию, которая будет обрабатывать событие
	volatile uint8_t irq_flag; // флаг состояния таймера
} tim_irq_t;


extern std::map<TIM_HandleTypeDef*, tim_irq_t> tim_irq_service;


void user_tim_handler(TIM_HandleTypeDef &timer);
void add_tim_callback(TIM_HandleTypeDef &timer, void (*p_fcn) (void));
void add_tim_handler(TIM_HandleTypeDef &timer, void (*p_fcn) (void));
void tim_start(TIM_HandleTypeDef &timer);
void tim_stop(TIM_HandleTypeDef &timer);
