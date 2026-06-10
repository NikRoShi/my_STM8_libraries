#ifndef STM8_TIME_H
#define STM8_TIME_H

#include <stdint.h>
#include "stm8_REG.h"

void tick_TIME(void);
void init_TIME(void);
uint32_t get_milsec(void);
uint32_t get_micsec(void);
void delay(uint32_t ms);

/* прерывание для работы таймера
void TIM4_UPD_OVF_IRQHandler(void) __interrupt(23) {
    TIM4_SR &= ~(1 << 0);
    tick_TIME();
}
*/

#endif