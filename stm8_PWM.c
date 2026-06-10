#include "stm8_PWM.h"

static uint16_t memory_period = 0;

void init_PWM(uint16_t period) {	// period = Fmaster / Fpwm (для удобства лучше использовать 1023)
	CLK_PCKENR1 |= (1 << 5);		//включить тактирование TIM2

	memory_period = period;			// запомним период чтобы считать проценты

	TIM2_ARRH = (uint8_t)((period >> 8));	//устанавливаем период
	TIM2_ARRL = (uint8_t)((period & 0xFF));
	
	TIM2_CCMR1 &= ~(0b111 << 4);		//сбрасываем значения настройки в 0 PD4
	TIM2_CCMR2 &= ~(0b111 << 4);		//PD3
	TIM2_CCMR3 &= ~(0b111 << 4);		//PA3
	
	TIM2_CCMR1 |= (0b110 << 4);		//настроить режим работы вывода PD4
	TIM2_CCMR2 |= (0b110 << 4);		//PD3
	TIM2_CCMR3 |= (0b110 << 4);		//PA3
	
	TIM2_CCMR1 |= (1 << 3);		//настроить PD4 как выход
	TIM2_CCMR2 |= (1 << 3);		//PD3
	TIM2_CCMR3 |= (1 << 3);		//PA3
	
	TIM2_CCMR1 &= ~0b11;		//настроить PD4 как выход
	TIM2_CCMR2 &= ~0b11;		//PD3
	TIM2_CCMR3 &= ~0b11;		//PA3
	
	TIM2_CR1 |= (1 << 7) | (1 << 0);
}

void startChannel_PWM(uint8_t channel) {	//функция разрешает вывод на соответствующий пин
	switch (channel) {
		case 1:		//PD4
			PD_DDR |= (1 << 4);
			PD_CR1 |= (1 << 4);
			TIM2_CCER1 |= (1 << 0);	
			break;
		case 2:		//PD3
			PD_DDR |= (1 << 3);
			PD_CR1 |= (1 << 3);
			TIM2_CCER1 |= (1 << 4);	
			break;
		case 3:		//PA3
			PA_DDR |= (1 << 3);
			PA_CR1 |= (1 << 3);
			TIM2_CCER2 |= (1 << 0);	
			break;
		
	}
}

void stopChannel_PWM(uint8_t channel) {		//функция запрещает вывод на соответствующий пин
	switch (channel) {
		case 1:		//PD4
			TIM2_CCER1 &= ~(1 << 0);
			break;
		case 2:		//PD3
			TIM2_CCER1 &= ~(1 << 4);
			break;
		case 3:		//PA3
			TIM2_CCER2 &= ~(1 << 0);
			break;
		
	}
}

void write_PWM(uint8_t channel, uint16_t value) {
	switch (channel) {
		case 1:
			TIM2_CCR1H = (uint8_t)(value >> 8);
			TIM2_CCR1L = (uint8_t)(value & 0xFF);
			break;
		case 2:
			TIM2_CCR2H = (uint8_t)(value >> 8);
			TIM2_CCR2L = (uint8_t)(value & 0xFF);
			break;
		case 3:
			TIM2_CCR3H = (uint8_t)(value >> 8);
			TIM2_CCR3L = (uint8_t)(value & 0xFF);
			break;
	
	}
}

void writePercent_PWM(uint8_t channel, uint8_t percent) {
	if (percent > 100) percent = 100;
	uint16_t value = (uint16_t)(((uint32_t)percent * memory_period) / 100);
	write_PWM(channel, value);
}