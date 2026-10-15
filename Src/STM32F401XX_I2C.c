#include "STM32F401XX_I2C.h"

void I2C_Init(I2C_RegMap_t *I2CX)
{
	I2CX->CR2 |= 16U;
	I2CX->CCR |= 16000000U / (2 * 100000U);
	I2CX->TRISE |= 17U;
	I2CX->CR1 |= 0x1U;
	I2CX->CR1 |= 0x1U << 10;
}

void I2C_Transfer(I2C_RegMap_t *I2CX, uint8_t *data, uint32_t length, uint32_t slvAddr)
{
	uint32_t temp;

	I2CX->CR1 |= 0x1U << 8;
	while(!(I2CX->SR1 & 0x1U));
	I2CX->DR = slvAddr << 1;
	while(!((I2CX->SR1 >> 1) & 0x1U));
	temp = I2CX->SR2;
	(void)temp;
	while(!((I2CX->SR1 >> 7) & 0x1U));
	I2CX->DR = *data;
	data++;
	length--;

	while(length > 0)
	{
		while(!((I2CX->SR1 >> 7) & 0x1U));
		I2CX->DR = *data;
		data++;
		length--;
	}

	while(!((I2CX->SR1 >> 2) & 	0x1U));
	I2CX->SR1 |= 0x1U << 9;
}
