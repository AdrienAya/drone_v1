#define STM32H7xx

#include "hal.h"
#include "stm32h753xx.h"
#include <stdint.h>
#include "hal_tim.h"


void Init_pin(GPIO_Init_t * gpio, uint8_t afr){

   if(((gpio->GPIO->MODER >> (gpio->PIN * 2)) & 0b11) != 0b10){

    GPIO_Moder_Clean(gpio);
    GPIO_Moder_Alternate(gpio);
    GPIO_Set_AFR(gpio, afr);

   }



}
// only TIM1 and TIM8
void TIM_PWM_Init(TIM_TypeDef * tim, uint16_t psc, uint16_t arr){

    // PSC and ARR
    tim->PSC = psc - 1;
    tim->ARR = arr - 1;

    // Canal 1 et 2 — CCMR1
    tim->CCMR1 |= (0b110 << 4);   // Canal 1 PWM Mode 1
    tim->CCMR1 |= (1 << 3);        // Canal 1 preload
    tim->CCMR1 |= (0b110 << 12);  // Canal 2 PWM Mode 1
    tim->CCMR1 |= (1 << 11);       // Canal 2 preload

    // Canal 3 et 4 — CCMR2
    tim->CCMR2 |= (0b110 << 4);   // Canal 3 PWM Mode 1
    tim->CCMR2 |= (1 << 3);        // Canal 3 preload
    tim->CCMR2 |= (0b110 << 12);  // Canal 4 PWM Mode 1
    tim->CCMR2 |= (1 << 11);       // Canal 4 preload

    // Activer les 4 canaux — CCER
    tim->CCER |= (1 << 0);   // Canal 1
    tim->CCER |= (1 << 4);   // Canal 2
    tim->CCER |= (1 << 8);   // Canal 3
    tim->CCER |= (1 << 12);  // Canal 4

    // ARPE
    tim->CR1 |= (1 << 7);
}

void TIM_PWM_Duty(TIM_TypeDef * tim,TIM_Channel_t channel, uint16_t duty){

    if(duty > 2000){

        duty = 2000;
      }
   
    if(duty < 1000){

        duty = 1000;
    }

    switch(channel){
        case TIM_Channel_1:
        tim->CCR1 = duty;
        break;
        case TIM_Channel_2:
        tim->CCR2 = duty;
        break;
        case TIM_Channel_3:
        tim->CCR3 = duty;
        break;
        case TIM_Channel_4:
        tim->CCR4 = duty;
        break;
        default:
        break;
    }


}

void TIM_PWM_Start(TIM_TypeDef * tim){

    if(tim == TIM1 || tim == TIM8){ //BDTR register is availible only in TIM1 AND TIM8 

    tim->BDTR |= (1<<15); // Main output enable bit 15 registre BDTR, MOEN must be set to 1 for safety reason, only for advanced timers

    }

    tim->CR1 |= (1<<0); // Counteur enable bit 0 register CR1

}

void TIM_Start(TIM_TypeDef * tim){

    tim->CR1 |= (1<<0); // Counteur enable bit 0 register CR1

}

void TIM_Stop(TIM_TypeDef * tim){

    tim->CR1 &= ~(1<<0); // Counteur enable bit 0 register CR1

}

void TIM_PWM_Stop(TIM_TypeDef * tim){

     // 1000 corresponds to 0% duty cycle, which is the minimum value for the duty cycle in this configuration
        tim->CCR1 = 1000;   
        tim->CCR2 = 1000;   
        tim->CCR3 = 1000;   
        tim->CCR4 = 1000; 

    if(tim == TIM1 || tim == TIM8){ //BDTR register is availible only in TIM1 AND TIM8 

    tim->BDTR &= ~(1<<15); 

    }
 

    tim->CR1 &= ~(1<<0); // Counteur enable bit 0 register CR1

}

void TIM_Stop(TIM_TypeDef * tim){

    tim->CR1 &= ~(1<<0); // Counteur enable bit 0 register CR1
}