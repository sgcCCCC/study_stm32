#include "Systick.h"
#include "core_cm3.h"
#include "misc.h"

 static __IO u32 TimingDelay; 
 
 void SysTick_Init( void ) //主要用来初始化
 {
	 	/* SystemFrequency / 1000    1ms中断一次
	 * SystemFrequency / 100000	 10us中断一次
	 * SystemFrequency / 1000000 1us中断一次
	 */
	 if( SysTick_Config( SystemCoreClock / 1000 ) )
	 {
			while( 1 );		
	 }
 }
/*******不通过中断实现的定时器*******/
void Delay_Us( __IO u32 us )
{
	uint32_t i;
	SysTick_Config( SystemCoreClock / 1000000 );  //1us中断一次，要修改中断频率，就改0的个数
	for( i=0 ; i < us ; i++ )
	{
		while( !( ( SysTick -> CTRL ) & ( 1 << 16 )) );		//CTRL位寄存器在从高到低计数到0时，会置一，并在读取之后归0，此时从while里脱出，再次进到for循环中
	}
	SysTick -> CTRL &= ~ SysTick_CTRL_ENABLE_Msk;		//关闭计时使能
}	

void Delay_Ms( __IO u32 ms )
{
	uint32_t i;
	SysTick_Config( SystemCoreClock / 1000 );  //1us中断一次，要修改中断频率，就改0的个数
	for( i=0 ; i < ms ; i++ )
	{
		while( !( ( SysTick -> CTRL ) & ( 1 << 16 )) ) ;		//CTRL寄存器的16位在从高到低计数到0时，会置一，并在读取之后归0，此时从while里脱出，再次进到for循环中
	}
	SysTick -> CTRL &= ~ SysTick_CTRL_ENABLE_Msk;		//关闭计时使能
}

/*******通过中断实现的定时器*******/
void Systick_Delay_us( __IO u32 nTime )		//10ms为一个单位
{
	TimingDelay = nTime;
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;		//使能定时器
	while( TimingDelay != 0 );
}
/*定时器中断服务函数*/
void Systick_IQR_Handle( void )
{
	if( TimingDelay != 0 )
	{
		TimingDelay --;
	}
}





