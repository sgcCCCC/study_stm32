#include "stm32f10x.h"
#include "led.h"

void LED0_Init()
{
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOB , ENABLE );				//使能时钟
	
	/*端口初始化*/
	GPIO_InitTypeDef GPIO_Init_Pin0;																//声明 GPIO_InitTypeDef 类型的结构体变量
	GPIO_Init_Pin0.GPIO_Pin = GPIO_Pin_0;														//设置端口引脚为P0
	GPIO_Init_Pin0.GPIO_Mode = GPIO_Mode_Out_PP;										//设置端口输出类型为 推挽输出
	GPIO_Init_Pin0.GPIO_Speed = GPIO_Speed_50MHz;										//设置传输速度为50MHz
	
	GPIO_Init( GPIOB , &GPIO_Init_Pin0 );//指定初始化的引脚	
}  

void lED1_Init()
{
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOB , ENABLE );				//使能时钟
					 
	/*端口初始化*/
	GPIO_InitTypeDef GPIO_Init_Pin1;																//声明 GPIO_InitTypeDef 类型的结构体变量
	GPIO_Init_Pin1.GPIO_Pin = GPIO_Pin_1;														//设置端口引脚为P1
	GPIO_Init_Pin1.GPIO_Mode = GPIO_Mode_Out_PP;																		//设置端口输出类型为 推挽输出
	GPIO_Init_Pin1.GPIO_Speed = GPIO_Speed_50MHz;										//设置传输速度为50MHz
	
	GPIO_Init( GPIOB , &GPIO_Init_Pin1 );//指定初始化的引脚		
}

void LED0_ON()
{
	GPIO_ResetBits( GPIOB , GPIO_Pin_0 );
}

void LED0_OFF()
{
	GPIO_SetBits( GPIOB , GPIO_Pin_0 );
}

void LED1_ON()
{
	GPIO_ResetBits( GPIOB , GPIO_Pin_1 );
}

void LED1_OFF()
{
	GPIO_SetBits( GPIOB , GPIO_Pin_1 );
}