#include "exti.h"

/*����NVIC*/
void NVIC_Config( void )
{
	NVIC_InitTypeDef	NVIC_InitStructure;	//�����ṹ�����
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_1 );//�ж����ȼ�����1 **���������У����ȼ�����ֻ��Ҫ����һ��**
	
	/*��KEY1�����ж�����*/
	NVIC_InitStructure.NVIC_IRQChannel = KEY1_EXTI_IRQ;	//�ṹ��-�ж�Դ  EXTI0,1,2,3,4....._IRQn  (EXTI0)
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//�ṹ��-��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;	//�ṹ��-�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	//�ṹ��-ʹ���ж�
	
	NVIC_Init( &NVIC_InitStructure );	//��ʼ��
	
	/*��KEY2�����ж�����*/
	NVIC_InitStructure.NVIC_IRQChannel = KEY2_EXTI_IRQ;	//�ṹ��-�ж�Դ
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//�ṹ��-��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;	//�ṹ��-�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	//�ṹ��-ʹ���ж�
	
	NVIC_Init( &NVIC_InitStructure );	//��ʼ��	
}

/*����EXTI*/
void EXTI_Config( void )
{
	/*******KEY1_EXTI����*******/
	EXTI_InitTypeDef EXTI_InitStructure;	//�����ṹ�����
	NVIC_Config();		//�����ж�
	GPIO_EXTILineConfig( GPIO_PortSource_A , GPIO_PinSource_0 );		//�ж�ԴA0
	
	EXTI_InitStructure.EXTI_Line = KEY1_EXTI_Line;		//�ṹ��-��ѡ��
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//�ṹ��-�ж�or�¼�ģʽ�����ж�ģʽ 
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//�ṹ��-������ʽΪ�����ش���
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;		//ʹ���ж�
	EXTI_Init( &EXTI_InitStructure );		//��ʼ��
	
	
	
	/*******KEY2_EXTI����*******/
	NVIC_Config();		//�����ж�
	GPIO_EXTILineConfig( GPIO_PortSource_C , GPIO_PinSource_13 );		//�ж�ԴC13
	
	EXTI_InitStructure.EXTI_Line = KEY2_EXTI_Line;		//�ṹ��-��ѡ��
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;		//�ṹ��-�ж�or�¼�ģʽ�����ж�ģʽ 
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;		//�ṹ��-������ʽΪ���ش���
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;		//ʹ���ж�
	EXTI_Init( &EXTI_InitStructure );		//��ʼ��
	
}

/***********��������***********/
void KEY1_Config( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;		//�����ṹ�����
	
	RCC_APB2PeriphClockCmd( KEY1_GPIO_CLK , ENABLE );		//����ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_INT_PIN1;		//�ṹ��-�����źŵ�����
	GPIO_InitStructure.GPIO_Mode = FLOAT_IN;		//�ṹ��-����ķ�ʽ������������
	GPIO_InitStructure.GPIO_Speed = GPIO_IN_Speed_50;		//�ṹ��-�������ʡ���50MHZ
	
	GPIO_Init( KEY1_GPIO_PORT , &GPIO_InitStructure );		//��ʼ��
}

void KEY2_Config( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;		//�����ṹ�����
	
	RCC_APB2PeriphClockCmd( KEY2_GPIO_CLK , ENABLE );//����ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_INT_PIN13;		//�ṹ��-�����źŵ�����
	GPIO_InitStructure.GPIO_Mode = FLOAT_IN;		//�ṹ��-����ķ�ʽ������������
	GPIO_InitStructure.GPIO_Speed = GPIO_IN_Speed_50;		//�ṹ��-�������ʡ���50MHZ
	
	GPIO_Init( KEY2_GPIO_PORT , &GPIO_InitStructure );		//��ʼ��
}

