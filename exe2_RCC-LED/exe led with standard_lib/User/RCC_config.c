#include "RCC_config.h"
#include "stm32f10x_rcc.h"

/*使用HSE作为系统时钟的来源*/

void HSE_SetSysClock( uint32_t pllmul )
{
		 __IO uint32_t StartCounter = 0 , HSEStartUpStatus = 0;
	
		RCC_DeInit(); //将RCC外设初始化成复位状态（此句必须出现）
		RCC_HSEConfig( RCC_HSE_ON ); //使能HSE
		HSEStartUpStatus = RCC_WaitForHSEStartUp();//等待HSE启动正常
		if( HSEStartUpStatus == SUCCESS )
		{
			/*此部分用于定义FLASH，若没用到，可以屏蔽*/ 
			// 使能FLASH 预存取缓冲区
			FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);

			// SYSCLK周期与闪存访问时间的比例设置，这里统一设置成2
			// 设置成2的时候，SYSCLK低于48M也可以工作，如果设置成0或者1的时候，
			// 如果配置的SYSCLK超出了范围的话，则会进入硬件错误，程序就死了
			// 0：0 < SYSCLK <= 24M
			// 1：24< SYSCLK <= 48M
			// 2：48< SYSCLK <= 72M
			FLASH_SetLatency(FLASH_Latency_2);
			
			/*此部分对分频预设因子进行定义*/
			RCC_HCLKConfig( RCC_SYSCLK_Div1 ); //AHB预分频因子为1		HCLK = SYSCLK
			RCC_PCLK2Config( RCC_HCLK_Div1 ); //APB2预分频因子为1    PCLK2 = HCLK
			RCC_PCLK1Config( RCC_HCLK_Div2 ); //APB1预分频因子为2		PCLK1 = HCLK/2
				
			
		}
}