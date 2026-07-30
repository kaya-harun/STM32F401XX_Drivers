#include"STM32F401XX_GPIO.h"

void GPIO_Init(GPIO_RegMap_t *GPIOX, GPIO_Conf_t *config)
{
	GPIOX->MODER &= ~(0x3U << (2 * config->pinNumber));
	GPIOX->MODER |= (config->mode << (2 * config->pinNumber));

	GPIOX->OTYPER &= ~(0x1U << config->pinNumber);
	GPIOX->OTYPER |= config->outType << config->pinNumber;

	GPIOX->OSPEEDR &= ~(0x3U << (2 * config->pinNumber));
	GPIOX->OSPEEDR |= (config->outSpeed << (2 * config->pinNumber));

	GPIOX->PUPDR &= ~(0x3U << (2 * config->pinNumber));
	GPIOX->PUPDR |= (config->puPd << (2 * config->pinNumber));

	uint8_t temp, temp1;
	temp = config->pinNumber / 8;
	temp1 = config->pinNumber % 8;
	GPIOX->AFR[temp] &= ~(0x15U << (4 * temp1));
	GPIOX->AFR[temp] |= (config->altFunc << (4 * temp1));
}

void GPIO_Write(GPIO_RegMap_t *GPIOX, GPIO_PIN_STATE value, GPIO_PIN_NUMBER pinNumber)
{
	if(value)
		GPIOX->ODR |= 0x1U << pinNumber;
	else
		GPIOX->ODR &= ~(0x1U << pinNumber);
}

GPIO_PIN_STATE GPIO_Read(GPIO_RegMap_t *GPIOX, GPIO_PIN_NUMBER pinNumber)
{
	uint8_t retVal;
	retVal = (GPIOX->IDR >> pinNumber) & 0x1U;

	return retVal;
}

void GPIO_Toggle(GPIO_RegMap_t *GPIOX, GPIO_PIN_NUMBER pinNumber)
{
	GPIOX->ODR ^= 0x1U << pinNumber;
}

void GPIO_IRQ_Init(GPIO_RegMap_t *GPIOX, GPIO_PIN_NUMBER pinNumber,
					GPIO_EDGE_TRIGGER edgeTrigger, GPIO_IRQ_NUMBER IRQNumber,
					GPIO_PRIORITY_NUMBER IRQPriority)
{
	switch(edgeTrigger)
	{
		case 0:
			EXTI->RTSR |= 0x1U << pinNumber;
			break;
		case 1:
			EXTI->FTSR |= 0x1U << pinNumber;
			break;
		case 2:
			EXTI->RTSR |= 0x1U << pinNumber;
			EXTI->FTSR |= 0x1U << pinNumber;
			break;
	}

	EXTI->IMR |= 0x1U << pinNumber;

	uint8_t portCode, temp, temp1;
	portCode = GPIO_GET_PORT_CODE(GPIOX);
	temp = pinNumber / 4;
	temp1 = pinNumber % 4;
	SYSCFG->EXTICR[temp] |= portCode << (4 * temp1);

	if(IRQNumber <= 31)
		NVIC->ISER[0] |= 0x1U << IRQNumber;
	else if(IRQNumber >= 32 && IRQNumber <= 63)
			NVIC->ISER[1] |= 0x1U << (IRQNumber % 32);
	else if(IRQNumber >= 64 && IRQNumber <= 95)
			NVIC->ISER[2] |= 0x1U << (IRQNumber % 64);

	temp = IRQNumber / 4;
	temp1 = IRQNumber % 4;
	NVIC->IPR[temp] |= IRQPriority << ((8 * temp1) + 4);
}

void GPIO_IRQ_Handle(GPIO_PIN_NUMBER pinNumber)
{
	EXTI->PR |= 0x1U << pinNumber;
}
