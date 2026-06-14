#include "stm8_I2C.h"

void init_I2C(void) 
{
	PB_DDR |= (1 << 4) | (1 << 5);  // настраиваем PB4 и PB5 как открытый коллектор 
	PB_CR1 &= ~(1 << 4) | (1 << 5);
		
	I2C_CR1 &= ~I2C_CR1_PE;	// отключим модуль перед настройкой
	
	I2C_FREQR = F_CPU / 1000000UL;	// сообщим модулю частоту ядра
	
	uint16_t ccr;
	ccr = F_CPU / (2UL * F_I2C);
	I2C_CCRL = (uint8_t)ccr;	// настроим частоту
	I2C_CCRH = (uint8_t)(ccr >> 8);
	
	I2C_TRISER = (F_CPU / 1000000UL) + 1;	//время нарастания = Fcpu + 1
	
	I2C_CR1 |= I2C_CR1_PE;	// включим модуль перед настройкой
}
