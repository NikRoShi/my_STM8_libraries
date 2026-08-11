#ifndef STM8_7SEG595_DISPLAY_H
#define STM8_7SEG595_DISPLAY_H

#include <stdint.h>
#include "stm8_SPI.h"
#include "stm8_GPIO.h"

#define DISPLAY_BLANK 0xff

void init_display(uint8_t port, uint8_t pin);
void clear_display(void);
void setDigit(uint8_t position, uint8_t digit);
void refresh_display(void);

#endif