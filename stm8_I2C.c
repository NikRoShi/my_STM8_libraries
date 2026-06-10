#include "stm8_I2C.h"

void init_I2C(void) {
    I2C_CR1 &= ~(1 << 0); // PE = 0
    CLK_PCKENR1 |= (1 << 0);
    I2C_FREQR = 16;
    I2C_CCRL = 0x50;      // 100 кГц
    I2C_CCRH = 0x00;
    I2C_TRISER = 17;
    I2C_CR1 |= (1 << 0);  // PE = 1
}

uint8_t start_I2C(void) {
    uint16_t timeout = 2000;
    I2C_CR2 |= (1 << 0); // START
    while (!(I2C_SR1 & (1 << 0)) && --timeout);
    return (timeout > 0); // 1 - успех, 0 - провал
}

uint8_t sendAddress_I2C(uint8_t addr) {
    uint16_t timeout = 2000;
    I2C_DR = addr;
    while (!(I2C_SR1 & (1 << 1)) && --timeout);
    if (timeout == 0) return 0;
    (void)I2C_SR1; 
    (void)I2C_SR3; // Сброс ADDR
    return 1;
}

uint8_t write_I2C(uint8_t data) {
    uint16_t timeout = 2000;
    I2C_DR = data;
    while (!(I2C_SR1 & (1 << 7)) && --timeout); // Ждем TXE
    return (timeout > 0);
}

uint8_t readAck_I2C(void) {
    I2C_CR2 |= (1 << 4); // ACK On
    while (!(I2C_SR1 & (1 << 6))); // RXNE
    return I2C_DR;
}

uint8_t readNack_I2C(void) {
    I2C_CR2 &= ~(1 << 4); // ACK Off (NACK)
    I2C_CR2 |= (1 << 1);  // STOP
    while (!(I2C_SR1 & (1 << 6))); // RXNE
    return I2C_DR;
}

void stop_I2C(void) {
    I2C_CR2 |= (1 << 1); // STOP
}
