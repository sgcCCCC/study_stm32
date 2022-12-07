/*新建工程*/
#include "stm32f10x.h"
#include "dsp_led.h"

void delay(int i)
{
	for( ; i > 0 ; i -- );
}

int main ()
{
	GPIO_Config();
	while(1)
	{
		GPIO_SetBits( LED_GPIO_Part , LED_GPIO_Pin1 );
		delay(0xfffff);
		GPIO_ResetBits( LED_GPIO_Part , LED_GPIO_Pin1 );
		delay(0xfffff);
  }
}
