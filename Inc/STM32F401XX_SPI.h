/**
 * @file STM32F401XX_SPI.h
 * @brief SPI peripheral header for STM32F401XX
 * @author Harun Kaya
 * @date 12.08.2026
 */

#ifndef INC_STM32F401XX_SPI_H_
#define INC_STM32F401XX_SPI_H_

#include "STM32F401XX.h"

/**
 * @defgroup SPI_Type_Definitions SPI type definitions
 * @{
 */
typedef uint8_t SPI_MSTR;
typedef uint8_t SPI_SSM;
typedef uint8_t SPI_SSI;
/**
 * @}
 */

/**
 * @brief SPI configuration structure.
 */
typedef struct SPI_Conf_t SPI_Conf_t;
struct SPI_Conf_t
{
	SPI_MSTR mstr;
	SPI_SSM ssm;
	SPI_SSI ssi;
	uint8_t *pTxData;
	uint8_t *pRxData;
	uint32_t txLen;
	uint32_t rxLen;
	uint8_t txBusy;
	uint8_t rxBusy;
};

/**
 * @defgroup SPI_Mstr_Configurations SPI master/slave configurations
 * @{
 */
#define SPI_MSTR_SLV	0x0U	/**< Slave configuration */
#define SPI_MSTR_MSTR	0x1U	/**< Master configuration */
/**
 * @}
 */

/**
 * @defgroup SPI_Ssm_Configurations SPI SSM configurations
 * @{
 */
#define SPI_SSM_HRD		0x0U	/**< Slave hardware select */
#define SPI_SSM_SFT		0x1U	/**< Slave software select */
/**
 * @}
 */

/**
 * @defgroup SPI_Ssi_Configurations SPI SSI configurations
 * @{
 */
#define SPI_SSI_LOW		0x0U	/**< NSS low */
#define SPI_SSI_HIGH	0x1U	/**< NSS high */
/**
 * @}
 */

/**
 * @brief SPI initialization API.
 *
 * @param SPIX		Pointer to the SPI to be used
 * @param config	Pointer to the SPI configuration structure
 */
void SPI_Init(SPI_RegMap_t *SPIX, SPI_Conf_t *config);

/**
 * @brief SPI transfer API.
 *
 * @param SPIX		Pointer to the SPI to be used
 * @param config	Pointer to the SPI configuration structure
 */
void SPI_Transfer(SPI_RegMap_t *SPIX, SPI_Conf_t *config);


#endif /* INC_STM32F401XX_SPI_H_ */
