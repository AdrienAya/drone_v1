#define STM32H7xx

#include "hal.h"
#include "stm32h753xx.h"
#include <stdint.h>


static DMATypeDef * DMA_GET(DMA_t dma){

    switch(dma){
        case dma1: return DMA1;
        case dma2: return DMA2;
        default: return NULL;
    }
}


DMA_Mode_circular(DMA_Stream_TypeDef * stream){

    // Enable circular mode
    // DMA_Stream_TypeDef point to the correct stream (e.g., DMA1_Stream0, DMA1_Stream1, etc.) "stm32h753xx.h"
        stream->CR |= (1 << 8);

}
    
DMA_init(DMA_Stream_TypeDef * stream, uint32_t * adress, uint32_t * buffer, uint16_t size, uint8_t priority){

   
   stream->CR |= (0b10<<13); // memory size 32 bits
   stream->CR |= (1<<10); // Memory increment mode
   stream->CR |= (0b10<<11); // Peripheral size 32 bits
   stream->CR |= (priority<<25); // Priority level

   stream->PAR = (uint32_t)adress; // Peripheral address
   stream->M0AR = (uint32_t)buffer; // Memory address
   stream->NDTR = size; // Number of data items to transfer

}

