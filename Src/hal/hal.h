#define STM32H753xx

#include "stm32h753xx.h"
#include <stdint.h>

#define I2C_TIMING_100KHZ    0x00C0EAFF
#define I2C_TIMING_400KHZ    0x00602173


typedef struct {
    // Acceleration (in g)
    float accel_x;
    float accel_y;
    float accel_z;

    // Gyroscope (in degrees per second)
    float gyro_x;
    float gyro_y;
    float gyro_z;

    // Temperature (in degrees Celsius)
    float temp;
} MPU6050_data_t;

typedef enum{

    psc1 = 0x00, // Division by 2, 120MHz/2 = 60MHz
    psc2 = 0x01, // Division by 4   120MHz/4 = 30MHz
    psc3 = 0x02, // Division by 8   120MHz/8 = 15MHz
    psc4 = 0x03, // Division by 16  120MHz/16 = 7.5MHz
    psc5 = 0x04, // Division by 32  120MHz/32 = 3.75MHz
    psc6 = 0x05, //  Division by 64 120MHz/64 = 1.875MHz
    psc7 = 0x06, // Division by 128 120MHz/128 = 937.5kHz
    psc8 = 0x07, // Division by 256 120MHz/256 = 468.75kHz

}PSC_division_t;

typedef enum{

    spi1,
    spi2,
    spi3,
    spi4,
    spi5,
    spi6,

}SPI_t;

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

    QMC5883L = 0x68 , // Magnetometer
    ICM20948 = 0x69, // Magnetometer
    BMP280 = 0x0D , // Barometer
    HMC5883L = 0x1E,  // Barometer
    MPU6050 = 0x76 , // Accelerometer and Gyroscope
    MS5611 = 0x77 // Accelerometer and Gyroscope

}I2C_Adrr_t;

typedef enum {
    // AHB4 - GPIO
    RCC_GPIOA,      // Bit 0
    RCC_GPIOB,      // Bit 1
    RCC_GPIOC,      // Bit 2
    RCC_GPIOD,      // Bit 3
    RCC_GPIOE,      // Bit 4

    // AHB1 - DMA, ADC
    RCC_DMA1,       // Bit 0
    RCC_DMA2,      // Bit 1
    RCC_ADC12,      // Bit 5
    RCC_DMAMUX1,      // Bit 19

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
    RCC_SPI2,

} RCC_Peripheral_t;


typedef enum{

i2c1 = 0b00100001, // I2C1 RX DMA request 33
i2c2 = 0b00100011, // I2C2 RX DMA request 35
spi1 = 0b00100101, // SPI1 RX DMA request 37
spi2 = 0b00100111, // SPI2 RX DMA request 39
uart4 = 0b00111111, // UART4 RX DMA request 63
uart5 = 0b01000001, // UART5 RX DMA request 65
adc1 = 0b00001001, // ADC1 DMA request 9



}dmamux_request_t;

// SPI peripherals

typedef enum{

    spi1,
    spi2,
    spi3,
    spi4,
    spi5,
    spi6,

}SPI_t;

// DMA peripherals
typedef enum{

    dma1,
    dma2,

}DMA_t;

// DMAMUX1 and DMAMUX2 are used for DMA channel request mapping and configuration

typedef enum{

    dmamux1,
    dmamux2,

}DMAMUX_t;

// uart only synchrone no clock 

//streams for DMA

typedef enum{

    dma_circular,
    dma_normal,

}DMA_Mode_t;

typedef enum {

    spi1_rx_dma,
    spi1_tx_dma,
    spi2_rx_dma,
    spi2_tx_dma,
    uart4_rx_dma,
    uart4_tx_dma,
    uart5_rx_dma,
    uart5_tx_dma,
    uart7_rx_dma,
    uart7_tx_dma,
    uart8_rx_dma,
    uart8_tx_dma,
    usart1_rx_dma,
    usart1_tx_dma,
    usart2_rx_dma,
    usart2_tx_dma,
    usart3_rx_dma,
    usart3_tx_dma,
    usart6_rx_dma,
    usart6_tx_dma,
    i2c1_rx_dma,
    i2c1_tx_dma,
    i2c2_rx_dma,
    i2c2_tx_dma,
    i2c3_rx_dma,
    i2c3_tx_dma,
    i2c4_rx_dma,
    i2c4_tx_dma,
    i2s1_rx_dma,
    i2s1_tx_dma,
    i2s2_rx_dma,
    i2s2_tx_dma,
    i2s3_rx_dma,
    i2s3_tx_dma,

}DMA_Channel_t;

typedef enum {

    uart4,
    uart5,
    uart7,
    uart8,
 // usart synchrone with clock   
    usart1,
    usart2,
    usart3,
    usart6,
}UART_t;

// I2C peripherals

typedef enum{

	i2c1,
	i2c2,
	i2c3,
	i2c4,

}I2C_t;



typedef enum{
	BATTERY_CRITIC,
	BATTERY_LOW,
	BATTERY_MEDIUM,
	BATTERY_HIGHT,
}Battery_level_t;

// Drone states

typedef enum{

	Debug,
	Takeoff,
	Flight,
	AudioMission,
	Alert,

}Drone_State_t;



typedef enum {
    GPIO_PUSHPULL  = 0x00, // Stantard output (0V ou 3.3V)
    GPIO_OPENDRAIN = 0x01  // Output open drain (0V ou Flottant)
} GPIO_OutputType_t;

typedef struct{
	GPIO_TypeDef *GPIO;
	uint8_t PIN;
	uint8_t volatile STATE_GPIO;
}GPIO_Init_t;

//GPIO HAL
void GPIO_Moder_Alternate(GPIO_Init_t * gpio); // Configure GPIO pin as alternate function
void GPIO_Moder_Clean(GPIO_Init_t * gpio); // Clear GPIO mode bits for a specific pin
uint8_t GPIO_Read(GPIO_Init_t * gpio);
void GPIO_Moder_Output(GPIO_Init_t * gpio); // Configure GPIO pin as output
void GPIO_Moder_Input(GPIO_Init_t * gpio); // Configure GPIO pin as input
void GPIO_High(GPIO_Init_t * gpio); // Set GPIO pin high
void GPIO_Low(GPIO_Init_t * gpio); // Set GPIO pin low
void GPIO_Set_Pull(GPIO_Init_t * gpio, GPIO_Pull_t pull_mode); // Configure GPIO pull-up/pull-down resistors
void GPIO_Set_OutputType (GPIO_Init_t * gpio, GPIO_OutputType_t output_mode); // Configure GPIO output type (push-pull or open-drain
void GPIO_Set_AFR(GPIO_Init_t * gpio); // Configure GPIO alternate function register for a specific pin
//RCC HAL
void RCC_Enable(RCC_Periphal_t peripheral); // Enable clock for a specific peripheral
void RCC_Disable(RCC_Periphal_t peripheral); // Disable clock for a specific peripheral
void RCC_State_update(Drone_State_t state); // Update RCC state based on drone state (Debug, Takeoff, Flight, etc.)
void RCC_SPI_Enable(SPI_t spi); //SPI HAL
//I2C HAL
void I2C_Timing(I2C_t i2c); // Configure I2C timing for 400kHz
void I2C_Init(GPIO_Init_t * gpio); // Initialize I2C peripheral with GPIO configuration
void I2C_Start(I2C_t i2c); // Generate I2C start condition
void I2C_Send_adrr(I2C_t i2c, I2C_Adrr_t adrr); // Send I2C slave address
void I2C_Stop(I2C_t i2c); // Generate I2C stop condition
void I2C_Write(I2C_t i2c, uint8_t *buf, uint8_t size); // Write data to I2C bus
void I2C_Read(I2C_t i2c, uint8_t *buf, uint8_t size); // Read data from I2C bus
void I2C_Nack(I2C_t i2c); // Send NACK after reading data from I2C bus
// UART HAL
void UART_Init(GPIO_Init_t * gpio); // Initialize UART peripheral with GPIO configuration
void UART_BaudRate(UART_t uart, uint32_t Baudrate, uint32_t ClockRate); // Configure UART baud rate
void UART_Enable(UART_t uart); // Enable UART peripheral
void UART_Read(UART_t uart, uint8_t *buf, uint8_t size); // Read data from UART
void UART_Write(UART_t uart, uint8_t *buf, uint8_t size); // Write data to UART
void UART_DMA_Enable(UART_t uart); // Enable UART DMA for transmission
//SPI HAL
void SPI_Init(GPIO_Init_t * sck,GPIO_Init_t * mosi,GPIO_Init_t * miso,GPIO_Init_t * cs); // Initialize SPI peripheral with GPIO configuration
void SPI_Enable(SPI_t spi); // Enable SPI peripheral
void SPI_DMA(SPI_t spi); // Enable SPI DMA for transmission
void SPI_Config(SPI_t spi); // Configure SPI settings (mode, data size, etc.)
void SPI_Prescaler(SPI_t spi, PSC_division_t division); // Configure SPI prescaler for baud rate control
void SPI_CS_High(GPIO_Init_t *cs); // Set SPI chip select pin high
void SPI_CS_Low(GPIO_Init_t *cs); // Set SPI chip select pin low
void SPI_Transfert(SPI_t spi, uint8_t *tx_buff, uint8_t *rx_buff, uint8_t size); // Perform SPI data transfer (full-duplex)
void SPI_Write(SPI_t spi, uint8_t *buf, uint8_t size); // Perform SPI write operation
//DMA HAL
void DMA_Init(DMA_Stream_TypeDef * stream, uint32_t * adress, uint32_t * buffer, uint16_t size, uint8_t priority); // Initialize DMA stream with configuration
void DMA_Start(DMA_Stream_TypeDef * stream, DMA_TypeDef * dma); // Start DMA transfer
void DMA_Circular_Mode(DMA_Stream_TypeDef * stream); // Enable circular mode for continuous data transfer
void DMA_dmamux_config(DMAMUX_Channel_TypeDef * channel, dmamux_request_t request);
