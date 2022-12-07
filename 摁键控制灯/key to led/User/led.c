#include "stm32f10x.h"
#include "led.h"

void LED0_Init()
{
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOB , ENABLE );				//ʹ��ʱ��
	
	/*�˿ڳ�ʼ��*/
	GPIO_InitTypeDef GPIO_Init_Pin0;																//���� GPIO_InitTypeDef ���͵Ľṹ�����
	GPIO_Init_Pin0.GPIO_Pin = GPIO_Pin_0;														//���ö˿�����ΪP0
	GPIO_Init_Pin0.GPIO_Mode = GPIO_Mode_Out_PP;										//���ö˿��������Ϊ �������
	GPIO_Init_Pin0.GPIO_Speed = GPIO_Speed_50MHz;										//���ô����ٶ�Ϊ50MHz
	
	GPIO_Init( GPIOB , &GPIO_Init_Pin0 );//ָ����ʼ��������	
}  

void lED1_Init()
{
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOB , ENABLE );				//ʹ��ʱ��
					 
	/*�˿ڳ�ʼ��*/
	GPIO_InitTypeDef GPIO_Init_Pin1;																//���� GPIO_InitTypeDef ���͵Ľṹ�����
	GPIO_Init_Pin1.GPIO_Pin = GPIO_Pin_1;														//���ö˿�����ΪP1
	GPIO_Init_Pin1.GPIO_Mode = GPIO_Mode_Out_PP;																		//���ö˿��������Ϊ �������
	GPIO_Init_Pin1.GPIO_Speed = GPIO_Speed_50MHz;										//���ô����ٶ�Ϊ50MHz
	
	GPIO_Init( GPIOB , &GPIO_Init_Pin1 );//ָ����ʼ��������		
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