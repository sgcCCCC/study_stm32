#include "exti.h"

/*配置NVIC*/
void NVIC_Config( void )
{
	NVIC_InitTypeDef	NVIC_InitStructure;	//声明结构体变量
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_1 );//中断优先级分组1 **整个工程中，优先级分组只需要出现一次**
	
	/*对KEY1进行中断设置*/
	NVIC_InitStructure.NVIC_IRQChannel = KEY1_EXTI_IRQ;	//结构体-中断源  EXTI0,1,2,3,4....._IRQn  (EXTI0)
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//结构体-抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;	//结构体-子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	//结构体-使能中断
	
	NVIC_Init( &NVIC_InitStructure );	//初始化
	
	/*对KEY2进行中断设置*/
	NVIC_InitStructure.NVIC_IRQChannel = KEY2_EXTI_IRQ;	//结构体-中断源
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//结构体-抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;	//结构体-子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	//结构体-使能中断
	
	NVIC_Init( &NVIC_InitStructure );	//初始化	
}

/*配置EXTI*/
void EXTI_Config( void )
{
	/*******KEY1_EXTI配置*******/
	EXTI_InitTypeDef EXTI_InitStructure;	//声明结构体变量
	NVIC_Config();		//配置中断
	GPIO_EXTILineConfig( GPIO_PortSource_A , GPIO_PinSource_0 );		//中断源A0
	
	EXTI_InitStructure.EXTI_Line = KEY1_EXTI_Line;		//结构体-线选择
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//结构体-中断or事件模式——中断模式 
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//结构体-触发方式为上升沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;		//使能中断
	EXTI_Init( &EXTI_InitStructure );		//初始化
	
	
	
	/*******KEY2_EXTI配置*******/
	NVIC_Config();		//配置中断
	GPIO_EXTILineConfig( GPIO_PortSource_C , GPIO_PinSource_13 );		//中断源C13
	
	EXTI_InitStructure.EXTI_Line = KEY2_EXTI_Line;		//结构体-线选择
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//结构体-中断or事件模式——中断模式 
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//结构体-触发方式为下沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;		//使能中断
	EXTI_Init( &EXTI_InitStructure );		//初始化
	
}

/***********配置摁键***********/
void KEY1_Config( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;		//声明结构体变量
	
	RCC_APB2PeriphClockCmd( KEY1_GPIO_CLK , ENABLE );		//开启时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_INT_PIN1;		//结构体-出入信号的引脚
	GPIO_InitStructure.GPIO_Mode = FLOAT_IN;		//结构体-输入的方式——浮空输入
	GPIO_InitStructure.GPIO_Speed = GPIO_IN_Speed_50;		//结构体-传输速率——50MHZ
	
	GPIO_Init( KEY1_GPIO_PORT , &GPIO_InitStructure );		//初始化
}

void KEY2_Config( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;		//声明结构体变量
	
	RCC_APB2PeriphClockCmd( KEY2_GPIO_CLK , ENABLE );//开启时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_INT_PIN13;		//结构体-出入信号的引脚
	GPIO_InitStructure.GPIO_Mode = FLOAT_IN;		//结构体-输入的方式——浮空输入
	GPIO_InitStructure.GPIO_Speed = GPIO_IN_Speed_50;		//结构体-传输速率——50MHZ
	
	GPIO_Init( KEY2_GPIO_PORT , &GPIO_InitStructure );		//初始化
}

