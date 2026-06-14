#include "stm8_I2C.h"

void init_I2C(void) 
{
	uint16_t ccr;
	ccr = F_CPU / (2UL * F_I2C);
	
	PB_DDR |= (1 << 4) | (1 << 5);  // настраиваем PB4 и PB5 как выход
	PB_CR1 &= ~((1 << 4) | (1 << 5));	// настраиваем PB4 и PB5 открытый коллектор 
		
	I2C_CR1 &= ~I2C_CR1_PE;	// отключим модуль перед настройкой
	
	I2C_FREQR = F_CPU / 1000000UL;	// сообщим модулю частоту ядра
	
	I2C_CCRL = (uint8_t)ccr;	// настроим частоту
	I2C_CCRH = (uint8_t)(ccr >> 8);
	
	I2C_TRISER = (F_CPU / 1000000UL) + 1;	//время нарастания = Fcpu + 1
	
	I2C_CR1 |= I2C_CR1_PE;	// включим модуль перед настройкой
}

uint8_t I2C_Ping(uint8_t address)
{
	uint16_t timeout = 50000;
	
	I2C_CR2 |= I2C_CR2_START;	//даём старт на линии

	while (!(I2C_SR1 & I2C_SR1_SB))	//ждём флага что старт сформирован
	{
		if (--timeout == 0) 
		{
			I2C_CR2 |= I2C_CR2_STOP;
			return 0;
		}
	}
	
	timeout = 50000;
	
	I2C_DR = (address << 1);	//записываем в регистр данных адрес устройства к которому мы хотим обратиться + 0, что значит что мы хотим write

	while (!(I2C_SR1 & I2C_SR1_ADDR) && !(I2C_SR2 & I2C_SR2_AF))	//ждём либо флага подтверждения адреса либо ошибки подтверждения
	{
		if (--timeout == 0) 
		{
			I2C_CR2 |= I2C_CR2_STOP;
			return 0;
		}
	}
	if (I2C_SR1 & I2C_SR1_ADDR)	//если адрес ответил 
	{
		(void)I2C_SR1;	//сбрасываем как в RM
		(void)I2C_SR3;
		
		I2C_CR2 |= I2C_CR2_STOP;	//даём стоп на линии
		return 1;
	}
		I2C_SR2 &= ~I2C_SR2_AF;	//если ошибка подтверждения
		
		I2C_CR2 |= I2C_CR2_STOP;	//формируем стоп на линии
		return 0;
}
