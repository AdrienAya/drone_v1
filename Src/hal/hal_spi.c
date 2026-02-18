#define STM32H7xx

#include "hal.h"
#include "stm32h753xx.h"
#include <stdint.h>
#include "hal_spi.h"

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

    GPIO_Set_AFR(sck);
    GPIO_Moder_Alternate(sck);
    GPIO_Set_AFR(mosi);
    GPIO_Moder_Output(mosi);
    GPIO_Set_AFR(miso);
    GPIO_Moder_Input(miso);
    GPIO_Moder_Output(cs);

}


void SPI_Enable(SPI_t spi){

    SPI_TypeDef *bus = SPI_Get(spi);
    bus->CR1 |= (1<<0);

}

void SPI_DMA(SPI_t spi){

SPI_TypeDef *bus = SPI_Get(spi);
bus->CFG1 |= ((1<<14 | 1<<15));

}

void SPI_Config(SPI_t spi){

    SPI_TypeDef *bus = SPI_Get(spi);
    bus->CFG2 |= ((1<<25) | (1<<24) | (1<<22));
}

void SPI_Prescaler(SPI_t spi, PSC_division_t division){

    SPI_TypeDef *bus = SPI_Get(spi);
    bus->CFG1 |= (division << 28);
       
}

void SPI_CS_High(GPIO_Init_t * cs){

    GPIO_High(cs);

}

void SPI_CS_Low(GPIO_Init_t * cs){

     GPIO_Low(cs);

}

void SPI_Transfert(SPI_t spi, uint8_t *tx_buff, uint8_t *rx_buff, uint8_t size){

    SPI_TypeDef *bus = SPI_Get(spi);
    for(uint8_t i = 0; i < size; i++) {

    while(!(bus->SR & SPI_SR_TXP));
    *(volatile uint8_t*)&bus->TXDR = tx_buff[i];

    while(!(bus->SR & SPI_SR_RXP));
    rx_buff[i] = *(volatile uint8_t*)&bus->RXDR;
}
    
}

void SPI_Write(SPI_t spi, uint8_t *buf, uint8_t size){
  
    SPI_TypeDef *bus = SPI_Get(spi);
    for(uint8_t i = 0 ; i < size; i++ ){
        while(!(bus->SR & SPI_SR_TXP));
        bus->TXDR = buf[i];
    }

}