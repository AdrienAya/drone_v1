#define stm32h753xx

#include "stm32h753xx.h"
#include "hal.h"
#include <stdint.h>


void RCC_Enable(RCC_Periphal_t peripheral){

	switch(peripheral){

    //   LED
	case RCC_GPIOA:
		     RCC->AHB4ENR |= (1<<0);
		     break;
	//	 Other
	case RCC_GPIOB:
			 RCC->AHB4ENR |= (1<<1);
			 break;
	//	 Other
	case RCC_GPIOC:
			 RCC->AHB4ENR |= (1<<2);
			 break;
	//   Other
	case RCC_GPIOD:
			 RCC->AHB4ENR |= (1<<3);
			 break;
    //   Other
	case RCC_GPIOE:
			 RCC->AHB4ENR |= (1<<4);
			 break;
    //   Other
	case RCC_DMA1:
		     RCC->AHB1ENR |= (1<<0);
		     break;
    //   Other
	case RCC_ADC12:
			 RCC->AHB1ENR |= (1<<5);
			 break;
    //   SD card
	case RCC_SDMMC1:
		     RCC->AHB3ENR |= (1<<16);
		     break;
    //   Buzzer
	case RCC_TIM3:
		     RCC->APB1ENR |= (1<<1);
			 break;
	//	 Debug
	case RCC_USART3:
			 RCC->APB1ENR |= (1<<18);
			 break;
	//	 Gps
	case RCC_UART4:
			 RCC->APB1ENR |= (1<<19);
			 break;
	//	 Capteur
	case RCC_I2C1:
			 RCC->APB1ENR |= (1<<21);
			 break;
	//   Engine
	case RCC_TIM1:
			 RCC->APB2ENR |= (1<<0);
			 break;
	//	SD card
	case RCC_SPI1:
			 RCC->APB2ENR |= (1<<12);
			 break;

	}
}

void RCC_Disable(RCC_Periphal_t peripheral){

	switch(peripheral){

	    //   LED
		case RCC_GPIOA:
			     RCC->AHB4ENR &= ~(1<<0);
			     break;
		//	 Other
		case RCC_GPIOB:
				 RCC->AHB4ENR &= ~(1<<1);
				 break;
		//	 Other
		case RCC_GPIOC:
				 RCC->AHB4ENR &= ~(1<<2);
				 break;
		//   Other
		case RCC_GPIOD:
				 RCC->AHB4ENR &= ~(1<<3);
				 break;
	    //   Other
		case RCC_GPIOE:
				 RCC->AHB4ENR &= ~(1<<4);
				 break;
	    //   Other
		case RCC_DMA1:
			     RCC->AHB1ENR &= ~(1<<0);
			     break;
	    //   Other
		case RCC_ADC12:
				 RCC->AHB1ENR &= ~(1<<5);
				 break;
	    //   SD card
		case RCC_SDMMC1:
			     RCC->AHB3ENR &= ~(1<<16);
			     break;
	    //   Buzzer
		case RCC_TIM3:
			     RCC->APB1ENR &= ~(1<<1);
				 break;
		//	 Debug
		case RCC_USART3:
				 RCC->APB1ENR &= ~(1<<18);
				 break;
		//	 Gps
		case RCC_UART4:
				 RCC->APB1ENR &= ~(1<<19);
				 break;
		//	 Capteur
		case RCC_I2C1:
				 RCC->APB1ENR &= ~(1<<21);
				 break;
		//   Engine
		case RCC_TIM1:
				 RCC->APB2ENR &= ~(1<<0);
				 break;
		//	SD card
		case RCC_SPI1:
				 RCC->APB2ENR &= ~(1<<12);
				 break;

		}

}

void RCC_State_update(Drone_State_t state){

	switch(state){
	case Debug:
		 RCC->APB1ENR &= ~((1<<21) | (1<<19) | (1<<1));
		 RCC->APB2ENR &= ~((1<<0) | (1<<12));
					 break;
	}

	case Takeoff:
		 RCC->APB2ENR &= ~((1<<0) | (1<<12));
		 RCC->AHB3ENR &= ~(1<<16);
		 RCC->APB1ENR &= ~(1<<19);
		 RCC->APB1ENR &= ~(1<<18);

		 RCC->APB2ENR |= (1<<0);
		 RCC->APB1ENR |= (1<<1);
		 RCC->APB1ENR |= (1<<21);

					 break;

	case Flight:
		 RCC->APB1ENR |= (1<<19);
		 RCC->APB2ENR |= (1<<0);
		 RCC->APB2ENR |= (1<<12);
		 RCC->AHB3ENR |= (1<<16);
		 RCC->APB1ENR |= (1<<21);

		 RCC->APB1ENR &= ~(1<<18);

}
