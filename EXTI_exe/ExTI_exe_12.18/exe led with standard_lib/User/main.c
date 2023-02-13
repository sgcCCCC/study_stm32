#include "stm32f10x.h"
#include "led.h"
#include "exti.h"

int main ( void )
{ 

	KEY1_Config();
	KEY2_Config();
	EXTI_Config();
	LED1();
	LED2();
	LED3();
	CloseLED();
	

	GPIO_ResetBits(GPIO_LED3_PORT, GPIO_LED_PIN3);
	
	

	
	while(1)
	{  

	}
}

			 