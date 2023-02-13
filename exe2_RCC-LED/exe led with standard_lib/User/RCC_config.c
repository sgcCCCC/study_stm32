#include "RCC_config.h"
#include "stm32f10x_rcc.h"

/*ʹ��HSE��Ϊϵͳʱ�ӵ���Դ*/

void HSE_SetSysClock( uint32_t pllmul )
{
		 __IO uint32_t StartCounter = 0 , HSEStartUpStatus = 0;
	
		RCC_DeInit(); //��RCC�����ʼ���ɸ�λ״̬���˾������֣�
		RCC_HSEConfig( RCC_HSE_ON ); //ʹ��HSE
		HSEStartUpStatus = RCC_WaitForHSEStartUp();//�ȴ�HSE��������
		if( HSEStartUpStatus == SUCCESS )
		{
			/*�˲������ڶ���FLASH����û�õ�����������*/ 
			// ʹ��FLASH Ԥ��ȡ������
			FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);

			// SYSCLK�������������ʱ��ı������ã�����ͳһ���ó�2
			// ���ó�2��ʱ��SYSCLK����48MҲ���Թ�����������ó�0����1��ʱ��
			// ������õ�SYSCLK�����˷�Χ�Ļ���������Ӳ�����󣬳��������
			// 0��0 < SYSCLK <= 24M
			// 1��24< SYSCLK <= 48M
			// 2��48< SYSCLK <= 72M
			FLASH_SetLatency(FLASH_Latency_2);
			
			/*�˲��ֶԷ�ƵԤ�����ӽ��ж���*/
			RCC_HCLKConfig( RCC_SYSCLK_Div1 ); //AHBԤ��Ƶ����Ϊ1		HCLK = SYSCLK
			RCC_PCLK2Config( RCC_HCLK_Div1 ); //APB2Ԥ��Ƶ����Ϊ1    PCLK2 = HCLK
			RCC_PCLK1Config( RCC_HCLK_Div2 ); //APB1Ԥ��Ƶ����Ϊ2		PCLK1 = HCLK/2
				
			
		}
}