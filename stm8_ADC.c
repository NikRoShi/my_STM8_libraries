#include <stdint.h>
#include "stm8_ADC.h"

void init_ADC(uint8_t channel) {
	CLK_PCKENR2 |= (1 << 3);	//включить тактирование адс
	
	ADC_CSR &= ~0x0F;        // Очистить старый канал
	ADC_CSR |= (channel & 0x0F); // Записать номер канала

	if (channel < 8) 			//отключаем триггер шмидта на выбраном канале
        ADC_TDRL |= (1 << channel);
    else 
        ADC_TDRH |= (1 << (channel - 8));
	
	ADC_CR2 |= (1 << 3);		//выравнивание вправо
	
	ADC_CR1 &= ~(0b111 << 4);	//очищаем значение делителя
	ADC_CR1 |= (0b100 << 4);	//устанавливаем делитьеть на 8(2Мгц для ADC)
	
	ADC_CR1 |= (1 << 0);		//запускаем ADON(прогрев)
}

void start_ADC(void) {
	ADC_CR1 |= (1 << 0);		//вторая запись в адон запускает преобразование
}

uint8_t isReady_ADC(void) {
	if (ADC_CSR & (1 << 7)) {return 1;}	//1 если значение готово
	return 0;
}

uint16_t getValue_ADC (void) {
	uint16_t val = ADC_DRL;
	val |= (uint16_t)ADC_DRH << 8;
	
	ADC_CSR &= ~(1 << 7);
	
	return val;
}