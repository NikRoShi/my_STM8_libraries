#include "stm8_7SEG595_display.h"

static const uint8_t positionTable[] =
{
    0b00001000,
    0b00000100,
    0b00000010,
    0b00000001,
    0b10000000,
    0b01000000,
    0b00100000,
    0b00010000
};

static const uint8_t digitTable[] =
{
    0b11000000, //0
    0b11111001, //1
    0b10100100, //2
    0b10110000, //3
    0b10011001, //4
    0b10010010, //5
    0b10000010, //6
    0b11111000, //7
    0b10000000, //8
    0b10010000  //9
};

static volatile uint8_t *latchPort;
static uint8_t latchPin;
static uint8_t displayBuffer[8];
static uint8_t currentPosition = 0;
static uint8_t a = 0;

void clear_display(void) 
{
	for (uint8_t i = 0; i < 8; i++)
	{
		displayBuffer[i] = DISPLAY_BLANK;
	}
}

void init_display(volatile uint8_t *port, uint8_t pin)
{
	latchPort = port;
    latchPin = pin;
	currentPosition = 0;
	clear_display();

	init_SPI(SPI_MODE0, SPI_DIV16, SPI_MSB, SPI_MST);
	pinMode(latchPort, latchPin, OUTPUT);
	
	writePin(latchPort, latchPin, LOW);
}
void setDigit(uint8_t position, uint8_t digit)
{
	if (position > 7) return;
	if (digit > 9) return;
	
	displayBuffer[position] = digitTable[digit];
}
void refresh_display(void)
{
	write_SPI(displayBuffer[currentPosition]);
	write_SPI(positionTable[currentPosition]);
	
	writePin(latchPort, latchPin, HIGH);
	writePin(latchPort, latchPin, LOW);
	
	currentPosition++;
	if (currentPosition > 7) currentPosition = 0;
}
void printNumber(uint32_t number)
{
	while (number)
	{
		setDigit(a, number % 10);
		number /= 10;
		a++;
	}
	a = 0;
}
