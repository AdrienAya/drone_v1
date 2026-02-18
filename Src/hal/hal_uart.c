#define stm32h753xx

#include "stm32h753xx.h"
#include "hal.h"
#include <stdint.h>
#include "hal_uart.h"

static UART_TypeDef * UART_Get(UART_t uart){

    switch(uart){
        case uart4: return UART4;
        case uart5: return UART5;
        case uart7: return UART7;
        case uart8: return UART8;
        case usart1: return USART1;
        case usart2: return USART2;
        case usart3: return USART3;
        case usart6: return USART6;
        default:   return NULL;
    }
}

void UART_Init(GPIO_Init_t * gpio){

    GPIO_Set_AFR(gpio);
    GPIO_Moder_Alternate(gpio);
}

void UART_BaudRate(UART_t uart, uint32_t Baudrate, uint32_t ClockRate){

    UART_TypeDef *bus = UART_Get(uart);
    uint16_t BRR = ClockRate/Baudrate;
    bus->BRR = BRR;

} 

void UART_Enable(UART_t uart){

    UART_TypeDef *bus = UART_Get(uart);
    bus->CR1 = 0;
    bus->CR1 |= (1<<3) | (1<<2);  // TE + RE
    bus->CR1 |= (1<<0); // UE always in last

}

void UART_DMA_Enable(UART_t uart){

    UART_TypeDef *bus = UART_Get(uart);
    bus->CR3 |= (1<<6);

}

void UART_Read(UART_t uart, uint8_t *buf, uint8_t size){

    UART_TypeDef *bus = UART_Get(uart);
    for(uint8_t i =0 ; i < size ; i++ ){
        while(!(bus->ISR & UART_ISR_RXNE));
        buf[i] = bus->RDR;
    }
}

void UART_Write(UART_t uart, uint8_t *buf, uint8_t size){

    UART_TypeDef *bus = UART_Get(uart);
    for(uint8_t i = 0 ; i < size ; i++ ){
        while(!(bus->ISR & UART_ISR_TXE));
        bus->TDR = buf[i];
    }
}


