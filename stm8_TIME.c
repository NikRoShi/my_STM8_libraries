#include "stm8_TIME.h"

static volatile uint32_t _milsec = 0;

void tick_TIME(void) {
    _milsec++;
}

void init_TIME(void) {
    _milsec = 0;
	TIM4_CR1 = 0;
	TIM4_PSCR = 0x07;
	TIM4_ARR  = 124;
	TIM4_IER |= 0x01;
    TIM4_CR1 |= (1 << 0);
    TIM4_SR = 0;
}

uint32_t get_milsec(void) {
    uint32_t ms;

    disableInterrupts();
    ms = _milsec;
    enableInterrupts();

    return ms;
}

// Микросекунды (расчет: полные мс * 1000 + текущие тики в регистре * 8)
uint32_t get_micsec(void) {
    uint32_t ms;
    uint8_t ticks;
    
    disableInterrupts();
    ms = _milsec;
    ticks = TIM4_CNTR; // Текущее значение счетчика (0-124)
    enableInterrupts();
    
    return (ms * 1000) + (uint32_t)(ticks * 8);
}

// Блокирующая задержка на базе нашего таймера
void delay(uint32_t ms) {
    uint32_t start = get_milsec();
    while ((get_milsec() - start) < ms);
}
