#define STM32H7xx

#include "hal.h"
#include "stm32h753xx.h"
#include <stdint.h>

static SPI_TypeDef* SPI_Get(SPI_t spi) {
    switch(spi) {
        case spi1: return SPI1;
        case spi2: return SPI2;
        case spi3: return SPI3;
        case spi4: return SPI4;
        case spi5: return SPI5;
        case spi6: return SPI6;
        default:   return NULL;
    }
}

void SPI_Init(GPIO_Init_t * sck,GPIO_Init_t * mosi,GPIO_Init_t * miso,GPIO_Init_t * cs){

    GPIO_Moder_Alternate(sck);
    GPIO_Set_AFR(mosi);
    GPIO_Moder_Output(mosi);
    GPIO_Set_AFR(miso);
    GPIO_Moder_Input(miso);
    GPIO_Moder_Output(cs);

}

void SPI_DMA(SPI_t spi){

SPI_TypeDef *bus = SPI_Get(spi);
spi->CFG1 |= ((1<<14 | 1<<15));

}

void SPI_Config(SPI_t spi){

    SPI_TypeDef *bus = SPI_Get(spi);
    spi->CFG2 |= ((1<<25) | (1<<24) | (1<<22));
}

void SPI_Prescaler(SPI_t spi, PSC_division_t division){

    SPI_TypeDef *bus = SPI_Get(spi);
    bus->CFG1 |= (division << 28);
       
}