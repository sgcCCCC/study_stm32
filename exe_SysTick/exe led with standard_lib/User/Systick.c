#include "Systick.h"
#include "core_cm3.h"
#include "misc.h"

 static __IO u32 TimingDelay; 
 
 void SysTick_Init( void ) //��Ҫ������ʼ��
 {
	 	/* SystemFrequency / 1000    1ms�ж�һ��
	 * SystemFrequency / 100000	 10us�ж�һ��
	 * SystemFrequency / 1000000 1us�ж�һ��
	 */
	 if( SysTick_Config( SystemCoreClock / 1000 ) )
	 {
			while( 1 );		
	 }
 }
/*******��ͨ���ж�ʵ�ֵĶ�ʱ��*******/
void Delay_Us( __IO u32 us )
{
	uint32_t i;
	SysTick_Config( SystemCoreClock / 1000000 );  //1us�ж�һ�Σ�Ҫ�޸��ж�Ƶ�ʣ��͸�0�ĸ���
	for( i=0 ; i < us ; i++ )
	{
		while( !( ( SysTick -> CTRL ) & ( 1 << 16 )) );		//CTRLλ�Ĵ����ڴӸߵ��ͼ�����0ʱ������һ�����ڶ�ȡ֮���0����ʱ��while���ѳ����ٴν���forѭ����
	}
	SysTick -> CTRL &= ~ SysTick_CTRL_ENABLE_Msk;		//�رռ�ʱʹ��
}	

void Delay_Ms( __IO u32 ms )
{
	uint32_t i;
	SysTick_Config( SystemCoreClock / 1000 );  //1us�ж�һ�Σ�Ҫ�޸��ж�Ƶ�ʣ��͸�0�ĸ���
	for( i=0 ; i < ms ; i++ )
	{
		while( !( ( SysTick -> CTRL ) & ( 1 << 16 )) ) ;		//CTRL�Ĵ�����16λ�ڴӸߵ��ͼ�����0ʱ������һ�����ڶ�ȡ֮���0����ʱ��while���ѳ����ٴν���forѭ����
	}
	SysTick -> CTRL &= ~ SysTick_CTRL_ENABLE_Msk;		//�رռ�ʱʹ��
}

/*******ͨ���ж�ʵ�ֵĶ�ʱ��*******/
void Systick_Delay_us( __IO u32 nTime )		//10msΪһ����λ
{
	TimingDelay = nTime;
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;		//ʹ�ܶ�ʱ��
	while( TimingDelay != 0 );
}
/*��ʱ���жϷ�����*/
void Systick_IQR_Handle( void )
{
	if( TimingDelay != 0 )
	{
		TimingDelay --;
	}
}





