#define STM32H7xx

#include "hal.h"
#include "stm32h753xx.h"
#include <stdint.h>




void GPIO_Moder_Clean(gpio_init_t * gpio){

	gpio->GPIO->MODER &= ~(0b11<<gpio->PIN * 2);

}

uint8_t GPIO_Read(gpio_init_t * gpio){

	return (gpio->GPIO->IDR >> gpio->PIN) & 0x01;
}

void GPIO_Moder_Output(gpio_init_t * gpio){

    GPIO_Moder_Clean(gpio);
}

void GPIO_Moder_Input(gpio_init_t * gpio){

	GPIO_Moder_Clean(gpio);
	gpio->GPIO->MODER &= ~(0b11<< gpio->PIN * 2);

}

void GPIO_Moder_Alternate(gpio_init_t * gpio){

	GPIO_Moder_Clean(gpio);
	gpio->GPIO->MODER |= (0b10<< gpio->PIN * 2);

}

void GPIO_High(gpio_init_t * gpio){

    gpio->GPIO->BSRR = (1 << gpio->PIN);


    gpio->STATE_GPIO = 1;
}


void GPIO_Low(gpio_init_t * gpio){

    gpio->GPIO->BSRR = (1 << (gpio->PIN + 16));

    gpio->STATE_GPIO = 0;
}

void GPIO_Set_Pull(gpio_init_t * gpio, GPIO_Pull_t pull_mode){

	gpio->GPIO->PUPDR &= ~(0b11 <<(gpio->PIN*2));

	gpio->GPIO->PUPDR |= (pull_mode << (gpio->PIN*2));

}

void GPIO_Set_OutputType (gpio_init_t * gpio, GPIO_OutputType_t output_mode){

	if(output_mode == GPIO_OPENDRAIN){
		gpio->GPIO->OTYPER |= (1<<gpio->PIN);
	}
	else{
		gpio->GPIO->OTYPER &= ~(1<<gpio->PIN);
	}
}

