#ifndef __LED_H
#define __LED_H
#include "stm32f10x.h"

#define GPIO_LED_PIN1		GPIO_Pin_5
#define GPIO_LED1_PORT		GPIOB

#define GPIO_LED_PIN2		GPIO_Pin_0
#define GPIO_LED2_PORT		GPIOB

#define GPIO_LED_PIN3		GPIO_Pin_1
#define GPIO_LED3_PORT		GPIOB

void LED1();
void LED2();
void LED3();
void CloseLED();

/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //���Ϊ�ߵ�ƽ		
#define digitalLo(p,i)		 {p->BRR=i;}	 //����͵�ƽ
#define digitalToggle(p,i) {p->ODR ^=i;} //�����ת״̬


/* �������IO�ĺ� */
#define LED1_TOGGLE		 digitalToggle( GPIO_LED1_PORT , GPIO_LED_PIN1 )
#define LED1_OFF		   digitalHi( GPIO_LED1_PORT , GPIO_LED_PIN1 )
#define LED1_ON			   digitalLo( GPIO_LED1_PORT , GPIO_LED_PIN1 )

#define LED2_TOGGLE		 digitalToggle( GPIO_LED2_PORT , GPIO_LED_PIN2 )
#define LED2_OFF		   digitalHi( GPIO_LED2_PORT , GPIO_LED_PIN2 )
#define LED2_ON			   digitalLo( GPIO_LED2_PORT , GPIO_LED_PIN2 )

#define LED3_TOGGLE		 digitalToggle( GPIO_LED3_PORT , GPIO_LED_PIN3)
#define LED3_OFF		   digitalHi( GPIO_LED3_PORT , GPIO_LED_PIN3 )
#define LED3_ON			   digitalLo( GPIO_LED3_PORT , GPIO_LED_PIN3 )



#endif