/**
 * @file STM32F401XX_I2C.h
 * @brief I2C peripheral header for STM32F401XX
 * @author Harun Kaya
 * @date 15.10.2026
 */

#ifndef INC_STM32F401XX_I2C_H_
#define INC_STM32F401XX_I2C_H_

#include "STM32F401XX.h"

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

/**
 * @brief I2C transfer API.
 *
 * @param I2CX		Pointer to the I2C to be used
 * @param *data		Pointer to the data to be transmitted
 * @param length	Size of the data to be transmitted
 * @param slvAddr	Address of the slave
 */
void I2C_Transfer(I2C_RegMap_t *I2CX, uint8_t *data, uint32_t length, uint32_t slvAddr);

#endif /* INC_STM31F401XX_I2C_H_ */
