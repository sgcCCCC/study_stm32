#include "stm32f10x.h"
#include "led.h"
#include "key.h"

void Delay( int a )
{
	for( ; a > 0; a-- );
}

int main()
{
	LED0_Init();
	lED1_Init();
	key1_Init();
	key2_Init();
	while(1)
	{
		LED0_OFF();
		LED1_OFF();
		
		if( GPIO_ReadInputDataBit(GPIOA , GPIO_Pin_0) )
		{
	  	LED0_ON();
		}
		
		if( GPIO_ReadInputDataBit(GPIOC , GPIO_Pin_13) )
		{
	  	LED1_ON();
		}
		
	}	
}
