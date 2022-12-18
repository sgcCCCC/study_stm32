// bsp : board support package �弶֧�ְ� 
#include "dsp_led.h"

void GPIO_Config( void )
{
	RCC_APB2PeriphClockCmd( LED_GPIO_Clock , ENABLE );      //���ĸ�ʱ�� ���Ǹ����� ģʽ ���ʣ����ģʽ����Ҫ���ã� ��ʼ��
	
	GPIO_InitTypeDef GPIO_Initstruct;
	
	GPIO_Initstruct.GPIO_Pin = LED_GPIO_Pin1;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init( LED_GPIO_Part , &GPIO_Initstruct );
	
}

