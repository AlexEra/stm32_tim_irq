# stm32_tim_irq
Automatic timers interrupts processing with HAL library

**Warning!!** Before using generation option with "\*.c/\*.h" configuration files should be enabled in STM32CubeMX.

These files can be used when periodical operations in the cycle are required. 

Allows using custom interrupt callback functions with the pointer. Besides, interface contains the processing function,
that can be used with custom function.

Example
----------------------------
```c
#include "stm32_tim_irq.h" // including the lib

// This example uses TIM1.

// callback routine
void my_tim_1_callback(void) {
    // Stop after timer update
    tim_irq_default_stop(&irq_tim_1);
}

void my_tim_evt_proc(void) {
    // Start after interrupt
    // do some stuff
    tim_irq_default_start(&irq_tim_1); // irq_tim_* structures are listed in the header file
}

int main() {
    /*
    ... bacis STM32 configs...
    */
    irq_tim_1.p_tim = &htim1; // it is important to write the address of the timer's structure
    irq_tim_1.p_irq_tim_func = my_tim_1_callback;
    irq_tim_1.p_irq_processing = my_tim_evt_proc;
    tim_irq_default_start(&irq_tim_1); // starting the timer
    while (1) {
        tim_irq_processing(&irq_tim_1); // default processing function
    }
    return 0;
}
```
