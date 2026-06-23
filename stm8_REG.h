#ifndef STM8S_REG_H
#define STM8S_REG_H

#define F_CPU 16000000UL

#define HIGH 1
#define LOW 0

/* ==== PORT A ==== */
#define PA_ODR   (*(volatile unsigned char*)0x5000)
#define PA_IDR   (*(volatile unsigned char*)0x5001)
#define PA_DDR   (*(volatile unsigned char*)0x5002)
#define PA_CR1   (*(volatile unsigned char*)0x5003)
#define PA_CR2   (*(volatile unsigned char*)0x5004)

/* ==== PORT B ==== */
#define PB_ODR   (*(volatile unsigned char*)0x5005)
#define PB_IDR   (*(volatile unsigned char*)0x5006)
#define PB_DDR   (*(volatile unsigned char*)0x5007)
#define PB_CR1   (*(volatile unsigned char*)0x5008)
#define PB_CR2   (*(volatile unsigned char*)0x5009)

/* ==== PORT C ==== */
#define PC_ODR   (*(volatile unsigned char*)0x500A)
#define PC_IDR   (*(volatile unsigned char*)0x500B)
#define PC_DDR   (*(volatile unsigned char*)0x500C)
#define PC_CR1   (*(volatile unsigned char*)0x500D)
#define PC_CR2   (*(volatile unsigned char*)0x500E)

/* ==== PORT D ==== */
#define PD_ODR   (*(volatile unsigned char*)0x500F)
#define PD_IDR   (*(volatile unsigned char*)0x5010)
#define PD_DDR   (*(volatile unsigned char*)0x5011)
#define PD_CR1   (*(volatile unsigned char*)0x5012)
#define PD_CR2   (*(volatile unsigned char*)0x5013)

/* ==== I2C ==== */
#define I2C_CR1    (*(volatile uint8_t*)0x5210)
#define I2C_CR2    (*(volatile uint8_t*)0x5211)
#define I2C_FREQR    (*(volatile uint8_t*)0x5212)
#define I2C_DR    (*(volatile uint8_t*)0x5216)
#define I2C_SR1    (*(volatile uint8_t*)0x5217)
#define I2C_SR2    (*(volatile uint8_t*)0x5218)
#define I2C_SR3    (*(volatile uint8_t*)0x5219)
#define I2C_CCRL    (*(volatile uint8_t*)0x521B)
#define I2C_CCRH    (*(volatile uint8_t*)0x521C)
#define I2C_TRISER    (*(volatile uint8_t*)0x521D)

#define I2C_CR1_PE (1 << 0)
#define I2C_CR2_START (1 << 0)
#define I2C_CR2_STOP (1 << 1)
#define I2C_CR2_ACK (1 << 2)
#define I2C_SR1_SB (1 << 0)
#define I2C_SR1_ADDR (1 << 1)
#define I2C_SR1_TXE (1 << 7)
#define I2C_SR1_RXNE (1 << 6)
#define I2C_SR1_BTF (1 << 2)
#define I2C_SR2_AF (1 << 2)

/* ==== UART ==== */
#define UART1_SR  (*(volatile unsigned char*)0x5230)
#define UART1_DR  (*(volatile unsigned char*)0x5231)
#define UART1_BRR1  (*(volatile unsigned char*)0x5232)
#define UART1_BRR2  (*(volatile unsigned char*)0x5233)
#define UART1_CR1  (*(volatile unsigned char*)0x5234)
#define UART1_CR2  (*(volatile unsigned char*)0x5235)
#define UART1_CR3  (*(volatile unsigned char*)0x5236)

#define UART1_SR_TXE (1 << 7)
#define UART1_SR_RXNE (1 << 5)
#define UART1_CR2_TEN (1 << 3)
#define UART1_CR2_REN (1 << 2)

/* ==== TIM2 ==== */
#define TIM2_CR1  (*(volatile unsigned char*)0x5300)
#define TIM2_IER  (*(volatile unsigned char*)0x5303)
#define TIM2_SR1  (*(volatile unsigned char*)0x5304)
#define TIM2_CCMR1  (*(volatile unsigned char*)0x5307)
#define TIM2_CCMR2  (*(volatile unsigned char*)0x5308)
#define TIM2_CCMR3  (*(volatile unsigned char*)0x5309)
#define TIM2_CCER1  (*(volatile unsigned char*)0x530A)
#define TIM2_CCER2  (*(volatile unsigned char*)0x530B)
#define TIM2_PSCR  (*(volatile unsigned char*)0x530E)
#define TIM2_ARRH  (*(volatile unsigned char*)0x530F)
#define TIM2_ARRL  (*(volatile unsigned char*)0x5310)
#define TIM2_CCR1H  (*(volatile unsigned char*)0x5311)
#define TIM2_CCR1L  (*(volatile unsigned char*)0x5312)
#define TIM2_CCR2H  (*(volatile unsigned char*)0x5313)
#define TIM2_CCR2L  (*(volatile unsigned char*)0x5314)
#define TIM2_CCR3H  (*(volatile unsigned char*)0x5315)
#define TIM2_CCR3L  (*(volatile unsigned char*)0x5316)

/* ==== TIM4 ==== */
#define TIM4_CR1  (*(volatile unsigned char*)0x5340)
#define TIM4_IER  (*(volatile unsigned char*)0x5343)
#define TIM4_SR   (*(volatile unsigned char*)0x5344)
#define TIM4_EGR  (*(volatile unsigned char*)0x5345)
#define TIM4_CNTR (*(volatile unsigned char*)0x5346)
#define TIM4_PSCR (*(volatile unsigned char*)0x5347)
#define TIM4_ARR  (*(volatile unsigned char*)0x5348)

/* ==== ADC ==== */
#define ADC_CSR  (*(volatile unsigned char*)0x5400)
#define ADC_CR1  (*(volatile unsigned char*)0x5401)
#define ADC_CR2  (*(volatile unsigned char*)0x5402)
#define ADC_DRH  (*(volatile unsigned char*)0x5404)
#define ADC_DRL  (*(volatile unsigned char*)0x5405)
#define ADC_TDRH  (*(volatile unsigned char*)0x5406)
#define ADC_TDRL  (*(volatile unsigned char*)0x5407)

/* ==== CLOCK ==== */
#define CLK_CKDIVR (*(volatile unsigned char*)0x50C6)
#define CLK_PCKENR1 (*(volatile unsigned char*)0x50C7)
#define CLK_PCKENR2 (*(volatile unsigned char*)0x50CA)

/* ==== BEEP ==== */

#define BEEP_CSR (*(volatile unsigned char*)0x50F3)

#define BEEP_CSR_BEEPEN (1 << 5)
#define BEEP_CSR_BEEPSEL 6
#define BEEP_CSR_BEEPDIV 0

/* ==== INTERRUPTS ==== */
#define enableInterrupts()  __asm__("rim")
#define disableInterrupts() __asm__("sim")

#endif
