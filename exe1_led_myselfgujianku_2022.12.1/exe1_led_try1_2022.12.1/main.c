#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

#define   LED_G_GPIO_PORT                   GPIOB
#define   LED_G_GPIO_CLK_ENABLE            (RCC->APB2ENR  |=  ( (1) << 3 ))
#define   LED_G_GPIO_PIN                    GPIO_Pin_0

void Delay(uint32_t count)
{
	for( ; count !=0; count-- );
}



int main (void)
{

	GPIO_InitTypeDef  GPIO_InitStructure;
	
	// 打开 GPIOB 端口的时钟
	LED_G_GPIO_CLK_ENABLE;
	
	GPIO_InitStructure.GPIO_Pin = LED_G_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStructure);	

  while(1)
  {
		GPIO_SetBits(LED_G_GPIO_PORT,LED_G_GPIO_PIN);
		Delay(0xFFFF);
		GPIO_ResetBits(LED_G_GPIO_PORT,LED_G_GPIO_PIN);
		Delay(0xFFFF);
	}


}


void SystemInit(void)
{
	// 函数体为空，目的是为了骗过编译器不报错
}