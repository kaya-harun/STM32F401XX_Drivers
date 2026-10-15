/**
 * @file STM32F401XX_I2C.h
 * @brief I2C peripheral header for STM32F401XX
 * @author Harun Kaya
 * @date 15.10.2026
 */

#include "STM32F401XX.h"

#ifndef INC_STM32F401XX_I2C_H_
#define INC_STM32F401XX_I2C_H_

/**
 * @brief SPI configuration structure.
 */
typedef struct I2C_Conf_t I2C_Conf_t;
struct I2C_Conf_t
{
};

/**
 * @brief I2C initialization API.
 *
 * @param I2CX		Pointer to the I2C to be used
 */
void I2C_Init(I2C_RegMap_t *I2CX);

#endif /* INC_STM31F401XX_I2C_H_ */
