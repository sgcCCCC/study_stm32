#ifndef __EXTI_H
#define __EXTI_H

#include "stm32f10x.h"

/*�����Ž��ж���*/
#define EXTI_1_KEYPIN_GPIOPORT		GPIOA     //���ڳ�ʼ��GPIOA
#define EXTI_1_KEYPIN_GPIOCLK			( RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO )    //����ʱ��A��ʱ�Ӻ�AFIO��ʱ�ӣ�����AFIOʱ����Ҫ����EXTI��λ����
#define EXTI_1_KEYPIN_GPIONUM			GPIO_Pin_0

/*exti������Ҫ������*/
#define EXTI_1_KEYPIN_EXTIPORT		GPIO_PortSourceGPIOA    //��Ҫ��EXTI���õ�������GPIOA����
#define EXTI_1_KEYPIN_EXTIPIN			GPIO_PinSource0         //��Ҫ��EXTI���õ�������0����
#define EXTI_1_KEYPIN_EXTILINE		EXTI_Line0              //��Ҫ��EXTI��ʹ�ã�����PTx0���ţ�����x�Ƕ��٣���AFIO����
#define EXTI_1_KEYPIN_IRQ					EXTI0_IRQn					    //�ж�Դͨ��0

#define EXTI_1_KEYPIN_IRQHandler	EXTI0_IRQHandler				//�жϷ�����

/*�����Ž��ж���*/
#define EXTI_2_KEYPIN_GPIOPORT    GPIOC
#define EXTI_2_KEYPIN_GPIOCLK     ( RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO )
#define EXTI_2_KEYPIN_GPIONUM     GPIO_Pin_13

/*exti������Ҫ������*/
#define EXTI_2_KEYPIN_EXTIPORT   	GPIO_PortSourceGPIOC
#define EXTI_2_KEYPIN_EXTIPIN    	GPIO_PinSource13
#define EXTI_2_KEYPIN_EXTILINE    EXTI_Line13
#define EXTI_2_KEYPIN_IRQ         EXTI15_10_IRQn

#define EXTI_2_KEYPIN_IRQHandler  EXTI15_10_IRQHandler

void EXTI_Config( void ); //����EXTI

void NVIC_Config( void );//����NVIC

void KEY_Config( void );//���ð��������룩

#endif