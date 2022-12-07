#include "key.h"
#include "stm32f10x.h"

void key1_Init()//按键初始化
{
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOA , ENABLE );				//使能时钟
	
	/*端口初始化*/
	GPIO_InitTypeDef GPIO_Init_Pin0;																//声明 GPIO_InitTypeDef 类型的结构体变量
	GPIO_Init_Pin0.GPIO_Pin = GPIO_Pin_0;														//设置端口引脚为P0
	GPIO_Init_Pin0.GPIO_Mode = GPIO_Mode_IPD;										//设置端口输出类型为 下拉输入
	GPIO_Init_Pin0.GPIO_Speed = GPIO_Speed_50MHz;										//设置传输速度为50MHz
	
	GPIO_Init( GPIOA , &GPIO_Init_Pin0 );//指定初始化的引脚	
}

void key2_Init()//按键初始化
{
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOC , ENABLE );				//使能时钟
	
	/*端口初始化*/
	GPIO_InitTypeDef GPIO_Init_Pin1;																//声明 GPIO_InitTypeDef 类型的结构体变量
	GPIO_Init_Pin1.GPIO_Pin = GPIO_Pin_13;														//设置端口引脚为P0
	GPIO_Init_Pin1.GPIO_Mode = GPIO_Mode_IPD;										//设置端口输出类型为 下拉输入
	GPIO_Init_Pin1.GPIO_Speed = GPIO_Speed_50MHz;										//设置传输速度为50MHz
	
	GPIO_Init( GPIOC , &GPIO_Init_Pin1 );//指定初始化的引脚	
}
