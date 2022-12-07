#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"

#define LED_GPIO_Pin1		GPIO_Pin_0
#define LED_GPIO_Part		GPIOB
#define LED_GPIO_Clock	RCC_APB2Periph_GPIOB

void GPIO_Config( void );



#endif 

