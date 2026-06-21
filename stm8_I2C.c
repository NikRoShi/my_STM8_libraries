#include "stm8_I2C.h"

void init_I2C(void) 
{
	uint16_t ccr;
	ccr = F_CPU / (2UL * F_I2C);
		
	I2C_CR1 &= ~I2C_CR1_PE;	// отключим модуль перед настройкой
	
	I2C_FREQR = F_CPU / 1000000UL;	// сообщим модулю частоту ядра
	
	I2C_CCRL = (uint8_t)ccr;	// настроим частоту
	I2C_CCRH = (uint8_t)(ccr >> 8);
	
	I2C_TRISER = (F_CPU / 1000000UL) + 1;	//время нарастания = Fcpu + 1
	
	I2C_CR1 |= I2C_CR1_PE;	// включим модуль перед настройкой
}

void stop_I2C(void)
{
	I2C_CR2 |= I2C_CR2_STOP;	//формируем стоп на линии
}

uint8_t start_I2C(void)
{
	uint16_t timeout = 50000;
	
	I2C_CR2 |= I2C_CR2_START;	//даём старт на линии
	while (!(I2C_SR1 & I2C_SR1_SB))	//ждём флага что старт сформирован
	{
		if (--timeout == 0) 
		{
			stop_I2C();
			return 0;
		}
	}
	return 1;
}
void clearADDR_I2C(void)
{
	(void)I2C_SR1;
	(void)I2C_SR3;
}
uint8_t writeAddr_I2C(uint8_t address, uint8_t mode)
{
	uint16_t timeout = 50000;
	
	if (mode == WRITE) I2C_DR = (address << 1);
	if (mode == READ) I2C_DR = (address << 1) | 0x01;
	
	while (!(I2C_SR1 & I2C_SR1_ADDR) && !(I2C_SR2 & I2C_SR2_AF))
	{
		if (--timeout == 0) 
		{
			stop_I2C();
			return 0;
		}
	}
	if (I2C_SR1 & I2C_SR1_ADDR)	//если адрес ответил 
	{
		return 1;
	}
		I2C_SR2 &= ~I2C_SR2_AF;	//иначе, сбрасываем ошибку подтверждения
		stop_I2C();
		return 0;
}

uint8_t writeByte_I2C(uint8_t data)
{
	uint16_t timeout = 50000;
	
	I2C_DR = data;	//записываем байт в реистр данных
	
	while(!(I2C_SR1 & I2C_SR1_TXE))	//ждём флага о том, что регистр данных опустел
	{
		if (I2C_SR2 & I2C_SR2_AF)	//если пришёл NACK
		{
			I2C_SR2 &= ~I2C_SR2_AF;	//очищаем регистр ошибки
			stop_I2C();
			return 0;
		}
		if (--timeout == 0)	//проверка таймаута
		{
			stop_I2C();
			return 0;
		}
	}
	return 1;
}

uint8_t ping_I2C(uint8_t address)
{
	if (start_I2C() == 0) return 0;
	if (writeAddr_I2C(address, WRITE) == 0) return 0;
	clearADDR_I2C(); 
	stop_I2C();
	return 1;
}

uint8_t writeReg_I2C(uint8_t address, uint8_t reg, uint8_t data)
{
	if (start_I2C() == 0) return 0;
	if (writeAddr_I2C(address, WRITE) == 0) return 0;
	clearADDR_I2C();
	if (writeByte_I2C(reg) == 0) return 0;
	if (writeByte_I2C(data) == 0) return 0;
	stop_I2C();
	return 1;
}

uint8_t readByte_I2C(uint8_t address, uint8_t *data)
{
	uint16_t timeout = 50000;
	
	if (start_I2C() == 0) return 0;
	
	I2C_CR2 &= ~I2C_CR2_ACK;
	
	if (writeAddr_I2C(address, READ) == 0) return 0;
	
	clearADDR_I2C();
	
	while (!(I2C_SR1 & I2C_SR1_RXNE))
	{
		if (--timeout == 0) 
		{
			stop_I2C();
			return 0;
		}
	}
	*data = I2C_DR;
	I2C_CR2 |= I2C_CR2_ACK;
	stop_I2C();
	return 1;
}
uint8_t readReg_I2C(uint8_t address, uint8_t reg, uint8_t *data)
{
	uint16_t timeout = 50000;
	
	if (start_I2C() == 0) return 0;
	
	if (writeAddr_I2C(address, WRITE) == 0) return 0;
	
	clearADDR_I2C();
	
	if (writeByte_I2C(reg) == 0) return 0;
	
	if (start_I2C() == 0) return 0;
	
	if (writeAddr_I2C(address, READ) == 0) return 0;
		
	I2C_CR2 &= ~I2C_CR2_ACK;
	
	clearADDR_I2C();
	
	stop_I2C();
	
	while (!(I2C_SR1 & I2C_SR1_RXNE))
	{
		if (--timeout == 0)
		{
			stop_I2C();
			return 0;
		}
	}
	*data = I2C_DR;
	I2C_CR2 |= I2C_CR2_ACK;
	return 1;
}
