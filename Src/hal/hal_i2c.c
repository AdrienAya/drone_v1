#define stm32h753xx

#include "stm32h753xx.h"
#include "hal.h"
#include <stdint.h>

static I2C_TypeDef* I2C_Get(I2C_t i2c) {
    switch(i2c) {
        case i2c1: return I2C1;
        case i2c2: return I2C2;
        case i2c3: return I2C3;
        case i2c4: return I2C4;
        default:   return NULL;
    }
}

void I2C_init(GPIO_Init_t* gpio){

	GPIO_Set_AFR(gpio);
	GPIO_Moder_Alternate(gpio);

}


void I2C_Timing(I2C_t i2c){

	I2C_TypeDef *bus = I2C_Get(i2c);
	bus->TIMINGR = I2C_TIMING_400KHZ;
}

void I2C_Start(I2C_t i2c){

I2C_TypeDef *bus = I2C_Get(i2c);
while(bus->ISR & I2C_ISR_BUSY);
bus->CR2 |= I2C_CR2_START;
while(!(bus->ISR & I2C_ISR_BUSY));

}

void I2C_Send_adrr(I2C_t i2c, I2C_Adrr_t adrr){

	I2C_TypeDef *bus = I2C_Get(i2c);
	bus->CR2 &= ~I2C_CR2_SADD;
	bus->CR2 |= (adrr << 1) & I2C_CR2_SADD;

}

void I2C_Stop(I2C_t i2c){

I2C_TypeDef *bus = I2C_Get(i2c);
while(bus->ISR & I2C_ISR_BUSY);
bus->CR2 |= I2C_CR2_STOP;
while(!(bus->ISR & I2C_ISR_BUSY));

}
void I2C_Read(I2C_t i2c, uint8_t *buf, uint8_t size){

	I2C_TypeDef *bus = I2C_Get(i2c);
	for(uint8_t i = 0; i < size ; i++){
		while(!(bus->ISR & I2C_ISR_RXNE));
		buf[i] = bus->RXDR;
	}
}

void I2C_Nack(I2C_t i2c){
    
	I2C_TypeDef *bus = I2C_Get(i2c);
	while(!(bus->ISR & I2C_ISR_RXNE));
	bus->CR2 |= I2C_CR2_NACK;
}
	
