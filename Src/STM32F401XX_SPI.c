#include "STM32F401XX_SPI.h"

void SPI_Init(SPI_RegMap_t *SPIX, SPI_Conf_t *config)
{
	uint32_t temp = 0;

	temp |= config->ssm << 9;
	temp |= config->ssi << 8;
	temp |= config->mstr << 2;

	SPIX->CR1 = temp;
}

void SPI_Transfer(SPI_RegMap_t *SPIX, SPI_Conf_t *config)
{
	SPIX->CR1 |= 0x1U << 6;

	while((config->txLen > 0) && (config->rxLen > 0))
	{
		while(!((SPIX->SR >> 0x1U) & 0x1U));
		SPIX->DR = *(config->pTxData);
		while(!(SPIX->SR & 0x1U));
		*(config->pRxData) = SPIX->DR;
		config->txLen--;
		config->rxLen--;
		config->pTxData++;
		config->pRxData++;
	}

	while((SPIX->SR >> 0x7U) & 0x1U);
	SPIX->CR1 &= ~(0x1U << 6);
}
