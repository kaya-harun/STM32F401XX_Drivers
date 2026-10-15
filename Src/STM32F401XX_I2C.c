#include "STM32F401XX_I2C.h"

void I2C_Init(I2C_RegMap_t *I2CX)
{
	I2CX->CR2 |= 16U;
	I2CX->CCR |= 16000000U / (2 * 100000U);
	I2CX->TRISE |= 17U;
	I2CX->CR1 |= 0x1U;
	I2CX->CR1 |= 0x1U << 10;
}
