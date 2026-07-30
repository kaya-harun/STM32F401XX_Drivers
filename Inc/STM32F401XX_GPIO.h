/**
 * @file STM32F401XX_GPIO.h
 * @brief GPIO peripheral header for STM32F401XX
 * @author Harun Kaya
 * @date 29.07.2026
 */

#ifndef INC_STM32F401XX_GPIO_H_
#define INC_STM32F401XX_GPIO_H_

#include"STM32F401XX.h"

/**
 * @defgroup GPIO_Type_Definitions GPIO type definitions
 * @{
 */
typedef uint8_t GPIO_PIN_NUMBER;
typedef uint8_t GPIO_MODE;
typedef uint8_t GPIO_OUT;
typedef uint8_t GPIO_SPEED;
typedef uint8_t GPIO_PUPD;
typedef uint8_t GPIO_AF;
typedef uint8_t GPIO_PIN_STATE;
typedef uint8_t GPIO_EDGE_TRIGGER;
typedef uint8_t GPIO_PRIORITY_NUMBER;
typedef uint8_t GPIO_IRQ_NUMBER;
/**
 * @}
 */

/**
 * @brief GPIO pin configuration structure.
 */
typedef struct GPIO_Conf_t GPIO_Conf_t;
struct GPIO_Conf_t
{
	GPIO_PIN_NUMBER pinNumber;	/**< GPIO pin number */
	GPIO_MODE mode;				/**< GPIO pin mode */
	GPIO_OUT outType; 			/**< GPIO pin output type */
	GPIO_SPEED outSpeed;		/**< GPIO pin output speed */
	GPIO_PUPD puPd;				/**< GPIO pin pull-up/pull-down */
	GPIO_AF altFunc;			/**< GPIO pin alternate function */
};

/**
 * @defgroup GPIO_Mode_Configurations GPIO pin mode configurations
 * @{
 */
#define GPIO_MODE_IN 	0x0U 	/**< GPIO pin input */
#define GPIO_MODE_OUT 	0x1U	/**< GPIO pin output */
#define GPIO_MODE_AF 	0x2U	/**< GPIO pin alternate function */
/**
 * @}
 */

/**
 * @defgroup GPIO_OutType_Configurations GPIO pin output type configurations
 * @{
 */
#define GPIO_OUT_PP 	0x0U	/**< GPIO pin push-pull */
#define GPIO_OUT_OD 	0x1U	/**< GPIO pin open-drain */
/**
 * @}
 */

/**
 * @defgroup GPIO_OutSpeed_Configurations GPIO pin output speed configurations
 * @{
 */
#define GPIO_SPEED_LOW 		0x0U	/**< GPIO pin low speed */
#define GPIO_SPEED_MEDIUM	0x1U	/**< GPIO pin medium speed */
#define GPIO_SPEED_HIGH		0x2U	/**< GPIO pin high speed */
#define GPIO_SPEED_VHIGH	0x3U	/**< GPIO pin very high speed */
/**
 * @}
 */

/**
 * @defgroup GPIO_PuPd_Configurations GPIO pin pull-up/pull-down configurations
 * @{
 */
#define GPIO_PUPD_NONE	0x0U	/**< GPIO pin no pull-up/pull-down */
#define GPIO_PUPD_PU	0x1U	/**< GPIO pin pull up */
#define GPIO_PUPD_PD	0x2U	/**< GPIO pin pull down */
/**
 * @}
 */

/**
 * @defgroup GPIO_Edge_Trigger_Configurations GPIO edge trigger configurations
 * @{
 */
#define GPIO_EDGE_TRIGGER_RT	0x0U	/**< GPIO rising trigger */
#define GPIO_EDGE_TRIGGER_FT	0x1U	/**< GPIO falling trigger */
#define GPIO_EDGE_TRIGGER_BOTH	0x2U	/**< GPIO rising and falling trigger */
/**
 * @}
 */

/**
 * @defgroup GPIO_IRQ_Numbers GPIO IRQ number macros
 * @{
 */
#define GPIO_EXTI0		0x6U
#define GPIO_EXTI1		0x7U
#define GPIO_EXTI2		0x8U
#define GPIO_EXTI3		0x9U
#define GPIO_EXTI4		0xAU
#define GPIO_EXTI9_5	0x17U
#define GPIO_EXTI15_10	0x28U
/**
 * @}
 */

#endif /* INC_STM32F401XX_GPIO_H_ */
