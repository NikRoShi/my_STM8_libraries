#ifndef STM8_7SEG595_DISPLAY_H
#define STM8_7SEG595_DISPLAY_H

#include <stdint.h>
#include "stm8_SPI.h"
#include "stm8_GPIO.h"

#define DISPLAY_BLANK 0xff

void clear_display(void);
void init_display(volatile uint8_t *port, uint8_t pin);
void setDigit(uint8_t position, uint8_t digit);
void refresh_display(void);
void printNumber(uint32_t number);

#endif
