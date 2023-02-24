#include "stm32f10x.h"
#include "led.h"
#include "exti.h"
#include "Systick.h"

int main ( void )
{ 
	LED1();
	LED2();
	SysTick_Init();  
		while(1)
		{
			LED1_ON;
			LED2_OFF;
			Systick_Delay_us( 1000 );		//10000*10us
			LED2_ON;
			LED1_OFF;
			Systick_Delay_us( 1000 );	
		} 
	
	/*while(1)
	{
		LED1_ON;
		LED2_OFF;
		Delay_Ms( 1000 );
		LED2_ON;
		LED1_OFF;
		Delay_Ms( 1000 );
	}*/
}

			 