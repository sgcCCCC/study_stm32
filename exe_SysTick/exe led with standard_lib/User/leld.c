#include "led.h"

void LED1( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB , ENABLE );
	GPIO_InitStructure.GPIO_Pin = GPIO_LED_PIN1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIO_LED1_PORT , &GPIO_InitStructure );	
}

void LED2( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB , ENABLE );
	GPIO_InitStructure.GPIO_Pin = GPIO_LED_PIN2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIO_LED2_PORT , &GPIO_InitStructure );	
}

void LED3( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB , ENABLE );
	GPIO_InitStructure.GPIO_Pin = GPIO_LED_PIN3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIO_LED3_PORT , &GPIO_InitStructure );	
}


void CloseLED()
{
			/* �ر�����led��	*/
		GPIO_SetBits(GPIO_LED1_PORT, GPIO_LED_PIN1);
		
		/* �ر�����led��	*/
		GPIO_SetBits(GPIO_LED2_PORT, GPIO_LED_PIN2);	 
    
    /* �ر�����led��	*/
		GPIO_SetBits(GPIO_LED3_PORT, GPIO_LED_PIN3);
}
	

