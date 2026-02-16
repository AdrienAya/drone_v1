#define STM32H753xx

#include "stm32h753xx.h"
#include <stdint.h>


typedef enum {
    HAL_OK = 0,
    HAL_ERROR = 1,
    HAL_BUSY = 2,
    HAL_TIMEOUT = 3
} HAL_StatusTypeDef;

typedef enum {
    GPIO_NOPULL   = 0x00, // no resistance
    GPIO_PULLUP   = 0x01, // Resistance to VDD (3.3V)
    GPIO_PULLDOWN = 0x02  // Resistance to GND (0V)
} GPIO_Pull_t;

typedef enum {
    // AHB4 - GPIO
    RCC_GPIOA,      // Bit 0
    RCC_GPIOB,      // Bit 1
    RCC_GPIOC,      // Bit 2
    RCC_GPIOD,      // Bit 3
    RCC_GPIOE,      // Bit 4

    // AHB1 - DMA, ADC
    RCC_DMA1,       // Bit 0
    RCC_ADC12,      // Bit 5

    // AHB3 - SDMMC
    RCC_SDMMC1,     // Bit 16

    // APB1 - I2C, UART, Timers
    RCC_TIM3,       // Bit 1 (buzzer PWM)
    RCC_USART3,     // Bit 18 (debug)
    RCC_UART4,      // Bit 19 (GPS)
    RCC_I2C1,       // Bit 21 (capteurs)

    // APB2 - SPI, Timers
    RCC_TIM1,       // Bit 0 (moteurs)
    RCC_SPI1,       // Bit 12 (SD card)

} RCC_Peripheral_t;

typedef enum{
	BATTERY_CRITIC,
	BATTERY_LOW,
	BATTERY_MEDIUM,
	BATTERY_HIGHT,
}Battery_level_t;

typedef enum{

	Debug,
	Takeoff,
	Flight,
	AudioMission,
	Alert,

}Drone_State_t;



typedef struct{

	RCC_TypeDef * rcc_name;
	uint8_t volatile STATE_RCC;

}RCC_t;

typedef enum {
    GPIO_PUSHPULL  = 0x00, // Stantard output (0V ou 3.3V)
    GPIO_OPENDRAIN = 0x01  // Output open drain (0V ou Flottant)
} GPIO_OutputType_t;

typedef struct{
	GPIO_TypeDef *GPIO;
	uint8_t PIN;
	uint8_t volatile STATE_GPIO;
}gpio_init_t;




