#ifndef __EXTI_H
#define __EXTI_H

#include "stm32f10x.h"

#define FLOAT_IN		GPIO_Mode_IN_FLOATING
#define GPIO_IN_Speed_50		GPIO_Speed_50MHz


#define KEY1_EXTI_IRQ		EXTI0_IRQn
#define KEY1_GPIO_PORT		GPIOA 
#define GPIO_PortSource_A		GPIO_PortSourceGPIOA
#define GPIO_PinSource_0		GPIO_PinSource0
#define KEY1_EXTI_Line		EXTI_Line0
#define GPIO_INT_PIN1		GPIO_Pin_0
#define KEY1_GPIO_CLK		(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)


#define KEY2_EXTI_IRQ		EXTI15_10_IRQn
#define KEY2_GPIO_PORT		GPIOC 
#define GPIO_PortSource_C		GPIO_PortSourceGPIOC
#define GPIO_PinSource_13		GPIO_PinSource13
#define KEY2_EXTI_Line		EXTI_Line13
#define GPIO_INT_PIN13		GPIO_Pin_13
#define KEY2_GPIO_CLK		(RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO)


#define KEY1_IRQHandler		EXTI0_IRQHandler     //中断服务函数 具体内容在
#define KEY2_IRQHandler		EXTI15_10_IRQHandler

void NVIC_Config( void );
void EXTI_Config( void );
void KEY1_Config( void );
void KEY2_Config( void );

#endif