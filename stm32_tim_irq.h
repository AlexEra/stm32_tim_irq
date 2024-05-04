#include "tim.h"

#if !defined(STM32_TIM_IRQ_H)
#define STM32_TIM_IRQ_H


typedef struct {
	void (*p_irq_tim_func) (tim_irq_t *p_tim_irq); // указатель на обработчик прерывания
	void (*p_irq_processing) (void); // указатель на функцию, которая будет обрабатывать событие
	TIM_HandleTypeDef *p_tim; // указатель на структуру таймера
	uint8_t irq_flag; // флаг состояния таймера
} tim_irq_t;
tim_irq_t irq_tim_1, irq_tim_2, irq_tim_3, irq_tim_4; // структуры для обработки прерываний таймеров
#if defined(__STM32F405xx_H) || defined__STM32F407xx_H()
tim_irq_t irq_tim_5, irq_tim_6, irq_tim_7, irq_tim_8, irq_tim_9,
irq_tim_10, irq_tim_11, irq_tim_12, irq_tim_13, irq_tim_14;
#endif

/**
 * @brief Функция, вызываемая в цикле для выполнения периодических действий по таймеру
 * @param p_tim_irq указатель на структуру для обработки прерываний
 */
void tim_irq_processing(tim_irq_t *p_tim_irq);

/**
 * @brief Функция по умолчанию для запуска таймера в режиме прерывания
 * @param p_tim_irq указатель на структуру для обработки прерывания
 */
void tim_irq_default_start(tim_irq_t *p_tim_irq);

/**
 * @brief Функция по умолчанию для остановки работы таймера в режиме прерывания 
 * @param p_tim_irq указатель на структуру для обработки прерывания
 */
void tim_irq_default_stop(tim_irq_t *p_tim_irq);

#endif
