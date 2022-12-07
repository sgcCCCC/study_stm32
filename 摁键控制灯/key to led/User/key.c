#include "key.h"
#include "stm32f10x.h"

void key1_Init()//������ʼ��
{
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOA , ENABLE );				//ʹ��ʱ��
	
	/*�˿ڳ�ʼ��*/
	GPIO_InitTypeDef GPIO_Init_Pin0;																//���� GPIO_InitTypeDef ���͵Ľṹ�����
	GPIO_Init_Pin0.GPIO_Pin = GPIO_Pin_0;														//���ö˿�����ΪP0
	GPIO_Init_Pin0.GPIO_Mode = GPIO_Mode_IPD;										//���ö˿��������Ϊ ��������
	GPIO_Init_Pin0.GPIO_Speed = GPIO_Speed_50MHz;										//���ô����ٶ�Ϊ50MHz
	
	GPIO_Init( GPIOA , &GPIO_Init_Pin0 );//ָ����ʼ��������	
}

void key2_Init()//������ʼ��
{
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOC , ENABLE );				//ʹ��ʱ��
	
	/*�˿ڳ�ʼ��*/
	GPIO_InitTypeDef GPIO_Init_Pin1;																//���� GPIO_InitTypeDef ���͵Ľṹ�����
	GPIO_Init_Pin1.GPIO_Pin = GPIO_Pin_13;														//���ö˿�����ΪP0
	GPIO_Init_Pin1.GPIO_Mode = GPIO_Mode_IPD;										//���ö˿��������Ϊ ��������
	GPIO_Init_Pin1.GPIO_Speed = GPIO_Speed_50MHz;										//���ô����ٶ�Ϊ50MHz
	
	GPIO_Init( GPIOC , &GPIO_Init_Pin1 );//ָ����ʼ��������	
}
