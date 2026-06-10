#ifndef STM8_UART_H
#define STM8_UART_H

#include <stdint.h>
#include "stm8_REG.h"

#define TX_PIN 5
#define RX_PIN 6

void init_UART(uint32_t baudRate);
void sendByte_UART(uint8_t byte);
void sendString_UART(const char *str);
void sendLine_UART(void);
void sendInt_UART(uint16_t num);
uint8_t available_UART(void);
uint8_t read_UART(void);

#endif