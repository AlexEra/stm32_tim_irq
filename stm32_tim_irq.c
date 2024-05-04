#include "stm32_tim_irq.h"


/** 
 * @brief Обрабтчик, автоматически вызывается только в момент возникновения прерывания
 * @param p_tim_irq указатель на структуру для обработки прерываний
*/
static void tim_irq_callback(tim_irq_t *p_tim_irq) {
	p_tim_irq->irq_flag = 1;
	if (p_tim_irq->p_irq_tim_func != NULL) p_tim_irq->p_irq_tim_func(p_tim_irq);
}

void tim_irq_processing(tim_irq_t *p_tim_irq) {
	if (p_tim_irq->irq_flag) {
		p_tim_irq->irq_flag = 0;
		if (p_tim_irq->p_irq_processing != NULL) p_tim_irq->p_irq_processing();
	}
}

void tim_irq_default_start(tim_irq_t *p_tim_irq) {
    __HAL_TIM_SET_COUNTER(p_tim_irq->p_tim, 0); // zeroing the timer counter
    __HAL_TIM_CLEAR_FLAG(p_tim_irq->p_tim, TIM_FLAG_UPDATE);
    HAL_TIM_Base_Start_IT(p_tim_irq->p_tim);
}

void tim_irq_default_stop(tim_irq_t *p_tim_irq) {
	HAL_TIM_Base_Stop_IT(p_tim_irq->p_tim);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM1) {
		tim_irq_callback(&irq_tim_1);
	} else if (htim->Instance == TIM2) {
		tim_irq_callback(&irq_tim_2);
	} else if (htim->Instance == TIM3) {
		tim_irq_callback(&irq_tim_3);
	} else if (htim->Instance == TIM4) {
		tim_irq_callback(&irq_tim_4);
	}
#if defined(__STM32F405xx_H) || defined(__STM32F407xx_H)
	else if (htim->Instance == TIM5) {
		tim_irq_callback(&irq_tim_5);
	} else if (htim->Instance == TIM6) {
		tim_irq_callback(&irq_tim_6);
	} else if (htim->Instance == TIM7) {
		tim_irq_callback(&irq_tim_7);
	} else if (htim->Instance == TIM8) {
		tim_irq_callback(&irq_tim_8);
	} else 	if (htim->Instance == TIM9) {
		tim_irq_callback(&irq_tim_9);
	} else if (htim->Instance == TIM10) {
		tim_irq_callback(&irq_tim_10);
	} else if (htim->Instance == TIM11) {
		tim_irq_callback(&irq_tim_11);
	} else if (htim->Instance == TIM12) {
		tim_irq_callback(&irq_tim_12);
	} else if (htim->Instance == TIM13) {
		tim_irq_callback(&irq_tim_13);
	} else if (htim->Instance == TIM14) {
		tim_irq_callback(&irq_tim_14);
	}
#endif
}
