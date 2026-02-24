#define STM32H7xx

#include "hal.h"
#include "stm32h753xx.h"
#include <stdint.h>


void DMA_Mode_circular(DMA_Stream_TypeDef * stream){

    // Enable circular mode
    // DMA_Stream_TypeDef point to the correct stream (e.g., DMA1_Stream0, DMA1_Stream1, etc.) "stm32h753xx.h"
        stream->CR |= (1 << 8);

}
    
void DMA_Init(DMA_Stream_TypeDef * stream, uint32_t * adress, uint32_t * buffer, uint16_t size, uint8_t priority){

   stream->CR &= ~(0xFFFF<<0); // Clear the existing configuration and clear DIR bits for peripheral-to-memory transfer, set 0b01 for memory-to-peripheral transfer, or set 0b10 for memory-to-memory transfer
   stream->CR |= (0b10<<13); // memory size 32 bits
   stream->CR |= (1<<10); // Memory increment mode
   stream->CR |= (0b10<<11); // Peripheral size 32 bits
   stream->CR |= (priority<<25); // Priority level
   
   stream->PAR = (uint32_t)adress; // Peripheral address
   stream->M0AR = (uint32_t)buffer; // Memory address
   stream->NDTR = size; // Number of data items to transfer

}

void DMA_Start(DMA_Stream_TypeDef * stream, DMA_TypeDef * dma){

    // Enable the DMA stream
    if(stream == NULL) return; // Invalid stream
    if(stream->CR & (1 << 0))return;// DMA stream is already enabled
       
    
   

    if(stream == DMA1_Stream0 || stream == DMA2_Stream0){
        // Clear all interrupt flags for DMA1 Stream 1
        dma->LIFCR |= (0x3F<<0);
        stream->CR |= (1 << 0); // Enable the DMA stream
    }
    else if(stream == DMA1_Stream1 || stream == DMA2_Stream1){
        // Clear all interrupt flags for DMA1 Stream 2
        dma->LIFCR |= (0x3F<<6);
        stream->CR |= (1 << 0);
    }
    else if(stream == DMA1_Stream2 || stream == DMA2_Stream2){
        // Clear all interrupt flags for DMA1 Stream 3
        dma->LIFCR |= (0x3F<<16);
        stream->CR |= (1 << 0);
    }
    else if(stream == DMA1_Stream3 || stream == DMA2_Stream3){
        // Clear all interrupt flags for DMA1 Stream 4
        dma->LIFCR |= (0x3F<<22);
        stream->CR |= (1 << 0);
    }
    else if(stream == DMA2_Stream4 || stream == DMA1_Stream4){
        // Clear all interrupt flags for DMA2 Stream 0
        dma->HIFCR |= (0x3F<<0);
        stream->CR |= (1 << 0);
    }
    else if(stream == DMA2_Stream5 || stream == DMA1_Stream5){
        // Clear all interrupt flags for DMA2 Stream 1
        dma->HIFCR |= (0x3F<<6);
        stream->CR |= (1 << 0);
    }
    else if(stream == DMA2_Stream6 || stream == DMA1_Stream6){
        // Clear all interrupt flags for DMA2 Stream 2
        dma->HIFCR |= (0x3F<<16);
        stream->CR |= (1 << 0);
    }

    else if(stream == DMA2_Stream7 || stream == DMA1_Stream7){
        // Clear all interrupt flags for DMA2 Stream 3
        dma->HIFCR |= (0x3F<<22);
        stream->CR |= (1 << 0);
    }
    
}

void DMA_dmamux_config(DMAMUX_Channel_TypeDef * channel, dmamux_request_t request){

    channel->CCR &= ~(0xFF<<0); // Clear the existing request configuration
    // Configure DMAMUX channel for the specified request
    channel->CCR |= (request<<0); // Set the DMA request for the channel

}