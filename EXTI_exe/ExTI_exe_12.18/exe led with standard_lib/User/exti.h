#ifndef __EXTI_H
#define __EXTI_H

#include "stm32f10x.h"

/*对引脚进行定义*/
#define EXTI_1_KEYPIN_GPIOPORT		GPIOA     //用于初始化GPIOA
#define EXTI_1_KEYPIN_GPIOCLK			( RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO )    //启用时钟A的时钟和AFIO的时钟，其中AFIO时钟主要用于EXTI定位引脚
#define EXTI_1_KEYPIN_GPIONUM			GPIO_Pin_0

/*exti部分需要的配置*/
#define EXTI_1_KEYPIN_EXTIPORT		GPIO_PortSourceGPIOA    //主要在EXTI中用到，声明GPIOA部分
#define EXTI_1_KEYPIN_EXTIPIN			GPIO_PinSource0         //主要在EXTI中用到，声明0引脚
#define EXTI_1_KEYPIN_EXTILINE		EXTI_Line0              //主要在EXTI中使用，声明PTx0引脚，其中x是多少，靠AFIO定义
#define EXTI_1_KEYPIN_IRQ					EXTI0_IRQn					    //中断源通道0

#define EXTI_1_KEYPIN_IRQHandler	EXTI0_IRQHandler				//中断服务函数

/*对引脚进行定义*/
#define EXTI_2_KEYPIN_GPIOPORT    GPIOC
#define EXTI_2_KEYPIN_GPIOCLK     ( RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO )
#define EXTI_2_KEYPIN_GPIONUM     GPIO_Pin_13

/*exti部分需要的配置*/
#define EXTI_2_KEYPIN_EXTIPORT   	GPIO_PortSourceGPIOC
#define EXTI_2_KEYPIN_EXTIPIN    	GPIO_PinSource13
#define EXTI_2_KEYPIN_EXTILINE    EXTI_Line13
#define EXTI_2_KEYPIN_IRQ         EXTI15_10_IRQn

#define EXTI_2_KEYPIN_IRQHandler  EXTI15_10_IRQHandler

void EXTI_Config( void ); //配置EXTI

void NVIC_Config( void );//配置NVIC

void KEY_Config( void );//配置按键（输入）

#endif