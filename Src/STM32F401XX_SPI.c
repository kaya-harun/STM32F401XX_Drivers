#include "STM32F401XX_SPI.h"

static void SPI_Rx_Handle(SPI_RegMap_t *SPIX, SPI_Conf_t *config);

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

void SPI_Start_Transfer_It(SPI_RegMap_t *SPIX, SPI_Conf_t *config, SPI_IRQ_NUMBER IRQNumber)
{

	if(IRQNumber <= 31)
		NVIC->ISER[0] |= 0x1U << IRQNumber;
	else if(IRQNumber >= 32 && IRQNumber <= 63)
			NVIC->ISER[1] |= 0x1U << (IRQNumber % 32);
	else if(IRQNumber >= 64 && IRQNumber <= 95)
			NVIC->ISER[2] |= 0x1U << (IRQNumber % 64);

	SPIX->CR2 |= 0x1U << 6;

	SPIX->CR1 |= 0x1U << 6;

	SPIX->DR = *(config->pTxData);
	config->txLen--;
	config->pTxData++;
}

void SPI_IRQ_Handle(SPI_RegMap_t *SPIX, SPI_Conf_t *config)
{
	if(((SPIX->CR2 >> 6) & 0x1U) && (SPIX->SR & 0x1U))
	{
		SPI_Rx_Handle(SPIX, config);
	}
}

static void SPI_Rx_Handle(SPI_RegMap_t *SPIX, SPI_Conf_t *config)
{
	*(config->pRxData) = SPIX->DR;
	config->rxLen--;
	config->pRxData++;

	if(config->txLen > 0)
	{
		SPIX->DR = *(config->pTxData);
		config->txLen--;
		config->pTxData++;
	}

	if(config->rxLen <= 0)
	{
		SPIX->CR2 &= ~(0x1U << 6);
		SPIX->CR1 &= ~(0x1U << 6);
	}
}
